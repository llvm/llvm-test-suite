#include"SimpleMOC_header.h"

#ifdef MPI
// Transfer information between nodes (angular fluxes)
void fast_transfer_boundary_fluxes( Params params, Input I, CommGrid grid)
{
	MPI_Barrier(grid.cart_comm_3d);
	if(I.mype==0) printf("Beginning Inter-Node Border Flux Transfer...\n");

	int tracks_per_msg = 10000;

	float h = I.domain_height;
	float x = I.assembly_width;

	// calculate number of tracks to each surface
	long ntracks_per_axial_direction  = I.ntracks * x / (2*x + 4*h);
	long ntracks_per_radial_direction = I.ntracks * h / (2*x + 4*h);

	// correct so that all tracks are used and are symmetric
	long remaining_tracks = I.ntracks - 2 * ntracks_per_axial_direction
	   - 4 * ntracks_per_radial_direction;

	long add_radial = remaining_tracks * ( 4*h / (2*x + 4*h) );
	add_radial = 4 * (add_radial / 4);
	ntracks_per_radial_direction += add_radial / 4;
	
	long add_axial = remaining_tracks - add_radial;
	ntracks_per_axial_direction += add_axial / 2;

	// Calculate all requests needed
	long max_requests = ntracks_per_radial_direction / tracks_per_msg;
	max_requests *= 4;
	max_requests += 2 * (ntracks_per_axial_direction / tracks_per_msg );

	// One for send, one for receive
	max_requests *= 2;

	long send_idx = 0;
	MPI_Status stat;

	// Computer Message Size
	size_t bytes = I.n_egroups * sizeof(float) * tracks_per_msg;
#ifdef PRINT_MEM_SIZES
	if(I.mype==0) printf("MPI Message Size: %.2lf (MB)\n",
			bytes / 1024. / 1024. );
#endif
	

	// Use knowledge of underlying flux structure for efficiency
	float * flux_array = params.tracks[0][0][0].f_psi;

	// TODO: Send reverse direction as well!!!

	// make an array of radial sending destinations
	int send_dest[6] = 
	{
		grid.x_pos_dest,
		grid.x_neg_dest,
		grid.y_pos_dest,
		grid.y_neg_dest,
		grid.z_pos_dest,
		grid.z_neg_dest
	};
	// make an array of radial receiving sources
	int rec_sources[6] = 
	{
		grid.x_pos_src,
		grid.x_neg_src,
		grid.y_pos_src,
		grid.y_neg_src,
		grid.z_pos_src,
		grid.z_neg_src
	};
	
	// make an array of number of messages
	// NOTE: There is some rounding here, should be corrected in real app
	long num_messages[6] =
	{
		ntracks_per_radial_direction / tracks_per_msg,
		ntracks_per_radial_direction / tracks_per_msg,
		ntracks_per_radial_direction / tracks_per_msg,
		ntracks_per_radial_direction / tracks_per_msg,
		ntracks_per_axial_direction / tracks_per_msg,
		ntracks_per_axial_direction / tracks_per_msg
	};


	// send_idx is now the beginning of the non-border region memory
	// i.e., we need to actually MPI Send/Recv the rest of the data

	// calculate the maximum number of messages sent in any direction
	long max_msgs_per_dir = 0;
	for( int i = 0; i < 6; i++ )
		if( num_messages[i] > max_msgs_per_dir )
		   max_msgs_per_dir = num_messages[i];

	// Flux Memory is assumed to be laid out as follows:
	// (Border Flux) --- (Send_MSG_Dir_0) (Recv_MSG_Dir_0) (Send_MSG_Dir_1) (Recv_MSG_Dir_1)....

	// New Comms
	float ** buffer = (float **) malloc(6 * sizeof(float*));
	float * _buffer = (float *) malloc( 6 * tracks_per_msg * I.n_egroups * sizeof(float));
	for( int i = 0; i < 6; i++ )
		buffer[i] = &_buffer[i * tracks_per_msg * I.n_egroups];

	long idx = 0;
	for( long i = 0; i < max_msgs_per_dir; i++ )
	{
		MPI_Request request[12];
		int active[6] = {0};
		int mpi_send[6] = {0};
		int mpi_recv[6] = {0};
		long bookmark = idx;
		for( int j = 0; j < 6; j++ )
		{
			if( i >= num_messages[j] )
				continue;
			
			// check if border assembly
			else if( send_dest[j] == -1 )
			{
				* params.leakage += pairwise_sum( &flux_array[idx],
						I.n_egroups * tracks_per_msg );
				idx += (long) I.n_egroups * tracks_per_msg;
			}
			else
			{
				MPI_Isend(
					&flux_array[idx], 	// Send Buffer
					tracks_per_msg,     // Number of Elements
					grid.Flux_Array,  	/* Type of element 
											(all energy group array) */
					send_dest[j],	  	// Destination MPI rank
					j,                	// Message ID
					grid.cart_comm_3d,	// MPI Communicator
					&request[j] );   	/* MPI Request (to monitor 
											when call finishes) */
				idx += (long) I.n_egroups * tracks_per_msg;
				mpi_send[j] = 1;
			}
		}
		for( int j = 0; j < 6; j++ )
		{
			if( i >= num_messages[j] )
				continue;
			
			// Check if Border Case
			else if( rec_sources[j] == -1)
				for( long k =0; k < I.n_egroups * tracks_per_msg; k++)
					buffer[j][k] = 0;
			else
			{
				MPI_Irecv(
						buffer[j],   		// Recv Buffer
						tracks_per_msg,   	// Number of Elements
						grid.Flux_Array,  	/* Type of element 
												(all energy group array) */
						rec_sources[j],		// MPI rank to Receive From
						j,              	// Message ID
						grid.cart_comm_3d,	// MPI Communicator
						&request[6+j] ); 		/* MPI Request (to monitor 
												when call finishes) */
				mpi_recv[j] = 1;
			}
			active[j] = 1;
		}

		// Block for Comm Round to complete & copy received data out of buffer
		for( int j = 0; j < 6; j++ )
		{
			if( mpi_send[j] == 1 )
			{
				MPI_Wait( &request[j], &stat );
			}
			if( mpi_recv[j] == 1 )
			{
				MPI_Wait( &request[6+j], &stat );
			}
			if( active[j] == 1 )
			{
				memcpy(&flux_array[bookmark], buffer[j],
						I.n_egroups * tracks_per_msg * sizeof(float));
				bookmark += (long) I.n_egroups*tracks_per_msg;
			}
		}


	}

	free(&buffer[0][0]);
	free(buffer);


	MPI_Barrier( grid.cart_comm_3d );
	MPI_Barrier( MPI_COMM_WORLD);

	if(I.mype==0) printf("Finished Inter-Node Border Flux Transfer.\n");
}
#endif
