#include"SimpleMOC_header.h"

// Calculate Derived Inputs
void calculate_derived_inputs( Input * I )
{
	
	#ifdef MPI
	int mype;
	MPI_Comm_rank(MPI_COMM_WORLD, &mype);
	I->mype = mype;
	#endif

	/* Divide number of azimuthal angles by 2 to accound for forward/backward
	 *  tracking */
	I->n_azimuthal /= 2;

	// calculate number of 2D tracks, enforcing divisible by 2
	I->ntracks_2D = I->n_azimuthal * 
			(I->assembly_width * sqrt(2) / I->radial_ray_sep);

	I->ntracks_2D = 2 * ( I->ntracks_2D / 2 );

	I->z_stacked = (int) ( I->height / (I->axial_z_sep * I->decomp_assemblies_ax));
	I->ntracks = I->ntracks_2D * I->n_polar_angles * I->z_stacked;  
	I->domain_height = I->height / I->decomp_assemblies_ax;

	I->n_source_regions_per_node = I->n_2D_source_regions_per_assembly *
		I->cai / I->decomp_assemblies_ax;

}

// Gets I from user and sets defaults
Input set_default_input( void )
{
	Input I;

	I.x_assemblies = 17;      	/* Number of assemblies in the x-axis 
								   of the reactor */
	I.y_assemblies = 17;        /* Number of assemblies in the y-axis 
								   of the reactor */
	I.cai = 27;                	// Number of coarse axial intervals
	I.fai = 5;                  /* Number of fine axial intervals per coarse 
								   axial interval */
	I.axial_exp = 2;            // Axial source expansion order
	I.radial_ray_sep = 0.05;    // Radial ray separation
	I.axial_z_sep = 0.25;       // Axial stacked z-ray separation
	I.n_azimuthal = 64;         // Number of azimuthal angles (should be 32)
	I.n_polar_angles = 10;      // Number of polar angles
	I.n_egroups = 104;        	// Number of energy groups
	I.decompose = true;      	/* Turn decomposition on/off (true = on, 
								   flase = off) */
	I.decomp_assemblies_ax =20; /* Number of subdomains per assembly
								   (axially) */
	I.segments_per_track = 120;  // Average number of segments per track (123)
	I.assembly_width = 21.42;   // Width of an assembly - 1.26 x 17 cm
	I.height = 400.0;           // Height of the reactor - 400 cm
	I.precision = 0.01;			// precision for source convergence
	I.mype = 0;                 // MPI Rank

	// source regions per assembly (estimate)
	I.n_2D_source_regions_per_assembly = 5000; 

	#ifdef PAPI
	I.papi_event_set = 4;
	#endif
	
	#ifdef OPENMP
	I.nthreads = omp_get_max_threads();
	#endif

	I.load_tracks = false; 

	return I;
}

// Changes defaults to small problem size
void set_small_input( Input * I )
{
	I->x_assemblies = 15;      		/* Number of assemblies in the x-axis 
								   		of the reactor */
	I->y_assemblies = 15;        	/* Number of assemblies in the y-axis 
								    	of the reactor */
	I->cai = 5;                	 	// Number of coarse axial intervals
	I->fai = 3;                  	/* Number of fine axial intervals per 
									   coarse axial interval */
	I->axial_exp = 2;            	// Axial source expansion order
	I->radial_ray_sep = 0.5;     	// Radial ray separation
	I->axial_z_sep = 0.2;        	// Axial stacked z-ray separation
	I->n_azimuthal = 5;         	// Number of azimuthal angles
	I->n_polar_angles = 5;      	// Number of polar angles
	I->n_egroups = 104;        		// Number of energy groups
	I->decompose = false;      	 	/* Turn decomposition on/off (true = on, 
								   		flase = off) */
	I->decomp_assemblies_ax = 1; 	/* Number of sub-domains per assembly
								   		(axially) */
	I->segments_per_track = 120;  	// Average number of segments per track
	I->assembly_width = 1.26*17; 	// Width of an assembly - 1.26 x 17 cm
	I->height = 400.0;           	// Height of the reactor - 400 cm
	I->precision = 0.01;			// precision for source convergence

	// source regions per assembly (estimate)
	I->n_2D_source_regions_per_assembly = 3000; 
}

// Initializes all track data
Params build_tracks( Input* input )
{
	Input I = *input;
	size_t nbytes = 0;
	Params params;

	if(I.mype == 0)
	{
		center_print("INITIALIZATION", 79);
		border_print();
		printf("Initializing 2D tracks...\n");
	}

	if(I.load_tracks)
	{
		params.tracks_2D = load_OpenMOC_tracks(
				I.track_file,false, input, &nbytes);
		I = *input;
	}
	else
    	params.tracks_2D = generate_2D_tracks(I, &nbytes); 

	if(I.mype == 0)
	{
#ifdef PRINT_MEM_SIZES
		printf("Memory allocated thus far (MB): %zu\n", nbytes / 1024 / 1014 );
#endif
		printf("Initializing 3D tracks...\n");
	}

	params.tracks = generate_tracks(I, params.tracks_2D, &nbytes);
	params.polar_angles = generate_polar_angles( I ); 

	if(I.mype == 0)
	{
#ifdef PRINT_MEM_SIZES
		printf("Memory allocated thus far (MB): %zu\n", nbytes / 1024 / 1014 );
#endif
		printf("Initializing flat source regions...\n");
	}

	params.sources = initialize_sources(I, &nbytes); 

	if(I.mype == 0)
	{
#ifdef PRINT_MEM_SIZES
		printf("Memory allocated thus far (MB): %zu\n", nbytes / 1024 / 1014 );
#endif
		border_print();
	}

	// initialize to zero leakage
	float * leakage = calloc( 1, sizeof(float) );
	params.leakage = leakage;

	// build exponential table for interpolation
	params.expTable = buildExponentialTable( I.precision, 10.0 ); 

	return params;
}

// Initializes 3D Cartesian Communication Grid + Shift Ranks
CommGrid init_mpi_grid( Input I )
{
	CommGrid grid;

	#ifdef MPI
	MPI_Comm cart_comm_3d;
	int ndims = 3;
	int dims[3] = {2,2,1};
	int period[3] = {0,0,0};
   	int reorder = 1;

	MPI_Cart_create(MPI_COMM_WORLD, ndims, dims, period, reorder, 
			&cart_comm_3d);

	// X Shifts
	int x_pos_src;
	int x_pos_dest;
	int x_neg_src;
	int x_neg_dest;
	MPI_Cart_shift( cart_comm_3d, 0,  1, &x_pos_src, &x_pos_dest );
	MPI_Cart_shift( cart_comm_3d, 0, -1, &x_neg_src, &x_neg_dest );

	// Y Shifts
	int y_pos_src;
	int y_pos_dest;
	int y_neg_src;
	int y_neg_dest;
	MPI_Cart_shift( cart_comm_3d, 1,  1, &y_pos_src, &y_pos_dest );
	MPI_Cart_shift( cart_comm_3d, 1, -1, &y_neg_src, &y_neg_dest );

	// Z Shifts
	int z_pos_src;
	int z_pos_dest;
	int z_neg_src;
	int z_neg_dest;
	MPI_Cart_shift( cart_comm_3d, 2,  1, &z_pos_src, &z_pos_dest );
	MPI_Cart_shift( cart_comm_3d, 2, -1, &z_neg_src, &z_neg_dest );

	grid.cart_comm_3d = cart_comm_3d;
	grid.x_pos_src    = x_pos_src;
	grid.x_pos_dest   = x_pos_dest;
	grid.x_neg_src    = x_neg_src;
	grid.x_neg_dest   = x_neg_dest;
	grid.y_pos_src    = y_pos_src;
	grid.y_pos_dest   = y_pos_dest;
	grid.y_neg_src    = y_neg_src;
	grid.y_neg_dest   = y_neg_dest;
	grid.z_pos_src    = z_pos_src;
	grid.z_pos_dest   = z_pos_dest;
	grid.z_neg_src    = z_neg_src;
	grid.z_neg_dest   = z_neg_dest;


	// Init flux buffer MPI type
	MPI_Datatype flux_array;
	MPI_Type_contiguous(I.n_egroups, MPI_FLOAT, &flux_array);
	MPI_Type_commit(&flux_array);

	grid.Flux_Array = flux_array;

	#endif

	return grid;
}

#ifdef OPENMP
// Intialized OpenMP Source Region Locks
omp_lock_t * init_locks( Input I )
{
	// Allocate locks array
	long n_locks = I.n_source_regions_per_node * I.fai; 
	omp_lock_t * locks = (omp_lock_t *) malloc( n_locks* sizeof(omp_lock_t));
	
	// Initialize locks array
	for( long i = 0; i < n_locks; i++ )
		omp_init_lock(&locks[i]);

	return locks;
}	
#endif


