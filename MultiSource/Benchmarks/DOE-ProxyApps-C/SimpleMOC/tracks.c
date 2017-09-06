#include"SimpleMOC_header.h"

// Allocates and initializes an array of 2D tracks
Track2D * generate_2D_tracks( Input I, size_t * nbytes )
{
	// Allocate space for 2D tracks
	Track2D * tracks = (Track2D *) malloc( I.ntracks_2D * sizeof(Track2D));
	*nbytes += I.ntracks_2D * sizeof(Track2D);

	// Fill weights with randomized data
	for( int i = 0; i < I.ntracks_2D; i++ )
		tracks[i].az_weight = urand();

	// Allocate and randomize segments
	generate_2D_segments( I, tracks, nbytes );

	return tracks;
}

// Allocates and initializes all segments
void generate_2D_segments( 
		Input I, 
		Track2D * tracks, 
		size_t * nbytes )
{
	/* Randomize Number of segments per track, and accumulate total 2D 
	 * segments in assembly */
	long total_segments = 0;
	for( long i = 0; i < I.ntracks_2D; i++ )
	{
		tracks[i].n_segments = segments_per_2D_track_distribution( I );
		total_segments += tracks[i].n_segments;
	}
	
	// Allocate contiguous space for segments
	Segment * contiguous_segments = (Segment *) malloc( total_segments 
			* sizeof(Segment));
	
	*nbytes += total_segments * sizeof(Segment);

	// Set segments arrays to correct locations within contiguous allocation
	long idx = 0;
	for( long i = 0; i < I.ntracks_2D; i++ )
	{
		tracks[i].segments = &contiguous_segments[idx];
		idx += tracks[i].n_segments;
	}

	// Initialize segments to randomized values
	for( long i = 0; i < I.ntracks_2D; i++ )
	{
		for( long j = 0; j < tracks[i].n_segments; j++ )
		{
			tracks[i].segments[j].length  = urand() * I.assembly_width
				/ tracks[i].n_segments;
			// source ID to be calculated on the fly
		}
	}
}

// generate segments per 2D track based on a normal distribution
long segments_per_2D_track_distribution( Input I )
{
	return nrand(I.segments_per_track, sqrt(I.segments_per_track));
}

// free memory associated with 2D tracks
void free_2D_tracks( Track2D * tracks )
{
	free(tracks[0].segments);
	free(tracks);
}

// allocate memory for tracks (primarily angular fluxes)
Track *** generate_tracks(Input I, Track2D * tracks_2D, size_t * nbytes)
{
	// Allocate space for tracks (3D)
	Track *** tracks = (Track ***) malloc( I.ntracks_2D * sizeof(Track **));
	*nbytes += I.ntracks_2D * sizeof(Track **);

	// Allocate pointers for tracks associated with a 2D track
	Track ** tracks_in_track2D = (Track **) malloc( I.ntracks_2D *
		   	I.n_polar_angles * sizeof(Track *));
	*nbytes += I.ntracks_2D * I.n_polar_angles * sizeof(Track *);

	// Allocate complete array of track data
	Track * track_data = (Track *) malloc( I.ntracks * sizeof(Track) );
	*nbytes += I.ntracks * sizeof(Track);
#ifdef PRINT_MEM_SIZES
	if(I.mype==0) printf("3D track data requires %zu MB of data...\n", 
			I.ntracks * sizeof(Track) / 1024 / 1024 );
#endif

	// stitch pointers together
	for( long i = 0; i < I.ntracks_2D; i++ )
		tracks[i] = &tracks_in_track2D[ i * I.n_polar_angles ];

	for( long i = 0; i < I.ntracks_2D; i++ )
	{
		for( int j = 0; j < I.n_polar_angles; j++ )
		{
			tracks[i][j] = &track_data[ 
				(i * I.n_polar_angles + j) * I.z_stacked ];
		}
	}

	// Allocate space for Flux Arrays
	size_t flux_bytes_needed = 2 * I.ntracks * I.n_egroups * sizeof(float);
	
#ifdef PRINT_MEM_SIZES
	if(I.mype==0) printf("Flux Arrays Require %zu MB of data...\n", 
			flux_bytes_needed / 1024 / 1024);
#endif

	float * flux_space = (float *) malloc( flux_bytes_needed );
	*nbytes += flux_bytes_needed;
	size_t flux_idx = 0;

	long offset = I.ntracks * I.n_egroups;

	for( long i = 0; i < I.ntracks_2D; i++ )
	{
		for( int j = 0; j < I.n_polar_angles; j++ )
		{
			for( int k = 0; k < I.z_stacked; k++ )
			{
				/* bottom z heights should only have upward directed polar
				 * angles and  similarly top should only have downward directed
				 * polar angles */
				if( j < I.n_polar_angles/2 )
					tracks[i][j][k].z_height = I.axial_z_sep * k;
				else
					tracks[i][j][k].z_height = I.axial_z_sep * ( k + 1 );
				
				// set polar weight, NOTE: this is the same for same polar angle
				tracks[i][j][k].p_weight = urand();

				// assign angular flux array memory
				tracks[i][j][k].f_psi = &flux_space[flux_idx];
				flux_idx += I.n_egroups;
				tracks[i][j][k].b_psi = &flux_space[flux_idx];
				flux_idx += I.n_egroups;

				// set incoming flux to 0 (guess 0 for inner assemblies)
				for( int g = 0; g < I.n_egroups; g++)
				{
					tracks[i][j][k].f_psi[g] = 0;
					tracks[i][j][k].b_psi[g] = 0;
				}
			}
		}
	}
	return tracks;
}

// free memory associated with tracks
void free_tracks( Track *** tracks )
{
	free(tracks);
}

// assign polar angles
float * generate_polar_angles( Input I )
{
	float * polar_angles = (float *) malloc( I.n_polar_angles * 
			sizeof(float) );

	for( int i = 0; i < I.n_polar_angles; i++)
		polar_angles[i] = M_PI * (i + 0.5) / I.n_polar_angles;
	
	return polar_angles;
}

Track2D * load_OpenMOC_tracks(char* fname, bool CMFD_obj, Input* I, size_t* nbytes)
{
	int ret;
	FILE* in;
	in = fopen(fname, "r");
	printf("Reading track data from:\n%s\n",fname);
	int string_length;

	/* Import Geometry metadata from the Track file */
	ret = fread(&string_length, sizeof(int), 1, in);
	char geometry_to_string[string_length];
	ret = fread(geometry_to_string, sizeof(char)*string_length, 1, in);
	printf("Importing ray tracing data from file...\n");
	
	/* Import ray tracing metadata from the Track file */
	double spacing;
	ret = fread(&I->n_azimuthal, sizeof(int), 1, in);
	ret = fread(&spacing, sizeof(double), 1, in);
	I->radial_ray_sep = (float) spacing;

	/* Initialize data structures for Tracks */
	int num_tracks[I->n_azimuthal];
	int num_x[I->n_azimuthal];
	int num_y[I->n_azimuthal];
	double azim_weights[I->n_azimuthal];
	
	ret = fread(num_tracks, sizeof(int), I->n_azimuthal, in);
	ret = fread(num_x, sizeof(int), I->n_azimuthal, in);
	ret = fread(num_y, sizeof(int), I->n_azimuthal, in);
	ret = fread(azim_weights, sizeof(double), I->n_azimuthal, in);
	
	/* Import azimuthal angle quadrature weights from Track file */
	double x0, y0, x1, y1;
	double phi;
	int azim_angle_index;
	int num_segments;
	double length;
	int material_id;
	int region_id;
	int mesh_surface_fwd;
	int mesh_surface_bwd;
	long num_2D_tracks;

	/* Calculate the total number of 2D Tracks */
	I->ntracks_2D = 0;
	for (int i=0; i < I->n_azimuthal; i++)
		I->ntracks_2D += (long) num_tracks[i];	
	
	/* Allocate memory for 2D tracks */
	Track2D * tracks = (Track2D *) malloc( I->ntracks_2D * sizeof(Track2D));
	*nbytes += I->ntracks_2D * sizeof(Track2D);

	// Allocate memory for the number of segments per Track array
	long tot_num_segments = 0;

	fpos_t checkpoint;
	fgetpos(in, &checkpoint);

	// Loop over tracks to determine total number of segments
	for (int i=0; i < I->n_azimuthal; i++)
	{
		for (int j=0; j < num_tracks[i]; j++)
		{
			// Skip to segment number information
			fseek( in, 5*sizeof(double) + sizeof(int), SEEK_CUR);
			
			// Load number of segments
			ret = fread(&num_segments, sizeof(int), 1, in);
			tot_num_segments += (long) num_segments;

			// Loop over all segments in this Track
			for (int s=0; s < num_segments; s++)
			{
				// Skip ahead again 
				fseek( in, 2*sizeof(int) + sizeof(double), SEEK_CUR);
				if (CMFD_obj)
					fseek( in, 2*sizeof(int), SEEK_CUR);
			}
		}
	}

	// Allocate contiguous space for segments 
	Segment * contiguous_segments = (Segment *) malloc( tot_num_segments 
			* sizeof(Segment));
	*nbytes += tot_num_segments * sizeof(Segment);

	// Reset file handle 
	fsetpos(in, &checkpoint);
	
	/* Initialize 2D track unique identifer (uid) end semgnet index (idx)*/
	int uid = 0;
	int idx = 0;
	
	/* Loop over Tracks */
	for (int i=0; i < I->n_azimuthal; i++)
	{
		//TODO: recored actual azimuthal angles
		for (int j=0; j < num_tracks[i]; j++)
		{
			/* Import data for this Track from Track file */
			ret = fread(&x0, sizeof(double), 1, in);
			ret = fread(&y0, sizeof(double), 1, in);
			ret = fread(&x1, sizeof(double), 1, in);
			ret = fread(&y1, sizeof(double), 1, in);
			ret = fread(&phi, sizeof(double), 1, in);
			ret = fread(&azim_angle_index, sizeof(int), 1, in);
			
			/* Load number of segments */
			ret = fread(&num_segments, sizeof(int), 1, in);
			tracks[uid].n_segments = (long) num_segments;

			/* Allocate memory for segments */
			tracks[uid].segments = &contiguous_segments[idx];
			idx += tracks[uid].n_segments;

			// TODO: set real azimuthal weight
			tracks[uid].az_weight = urand();
		
			/* Loop over all segments in this Track */
			for (int s=0; s < num_segments; s++)
			{
				/* Import data for this segment from Track file */
				ret = fread(&length, sizeof(double), 1, in);
				ret = fread(&material_id, sizeof(int), 1, in);
				ret = fread(&region_id, sizeof(int), 1, in);
			
				/* record track length */
				tracks[uid].segments[s].length = (float) length;

				/* record region_id (not used at the moment) */
				tracks[uid].segments[s].source_id = (long) region_id;

				/* Import CMFD-related data if needed */
				if (CMFD_obj)
				{
					ret = fread(&mesh_surface_fwd, sizeof(int), 1, in);
					ret = fread(&mesh_surface_bwd, sizeof(int), 1, in);
				}
			}
			uid++;
		}
	}
	// recalculate average number of segments per track
	I->segments_per_track = tot_num_segments / I->ntracks_2D;	

	printf("Number of 2D tracks = %ld\n", I->ntracks_2D);
	I->ntracks = I->ntracks_2D * I->n_polar_angles * I->z_stacked; 
	printf("Number of 3D tracks = %ld\n", I->ntracks);
	printf("Number of segments = %ld\n", tot_num_segments);

	/* Close the Track file */
	fclose(in);
	return tracks;
}
