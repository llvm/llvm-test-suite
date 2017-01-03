#include "XSbench_header.h"

#ifdef MPI
#include<mpi.h>
#endif

int main( int argc, char* argv[] )
{
	// =====================================================================
	// Initialization & Command Line Read-In
	// =====================================================================
	int version = 13;
	int mype = 0;
	#ifdef OPENMP
	int max_procs = omp_get_num_procs();
	#else
	int max_procs = 1;
	#endif
	int i, thread = 0, mat;
	unsigned long seed;
	double omp_start = 0.0, omp_end = 0.0, p_energy;
	unsigned long long vhash = 0;
	int nprocs;

	#ifdef MPI
	MPI_Status stat;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &mype);
	#endif
	
	// rand() is only used in the serial initialization stages.
	// A custom RNG is used in parallel portions.
	#ifdef VERIFICATION
	srand(26);
	#else
	srand(time(NULL));
	#endif

	// Process CLI Fields -- store in "Inputs" structure
	Inputs in = read_CLI( argc, argv );

	#ifdef OPENMP	
	// Set number of OpenMP Threads
	omp_set_num_threads(in.nthreads); 
	#endif

	// Print-out of Input Summary
	if( mype == 0 )
		print_inputs( in, nprocs, version );

	// =====================================================================
	// Prepare Nuclide Energy Grids, Unionized Energy Grid, & Material Data
	// =====================================================================

	// Allocate & fill energy grids
	#ifndef BINARY_READ
	if( mype == 0) printf("Generating Nuclide Energy Grids...\n");
	#endif
	
	NuclideGridPoint ** nuclide_grids = gpmatrix(in.n_isotopes,in.n_gridpoints);
	
	#ifdef VERIFICATION
	generate_grids_v( nuclide_grids, in.n_isotopes, in.n_gridpoints );	
	#else
	generate_grids( nuclide_grids, in.n_isotopes, in.n_gridpoints );	
	#endif
	
	// Sort grids by energy
	#ifndef BINARY_READ
	if( mype == 0) printf("Sorting Nuclide Energy Grids...\n");
	sort_nuclide_grids( nuclide_grids, in.n_isotopes, in.n_gridpoints );
	#endif

	// Prepare Unionized Energy Grid Framework
	#ifndef BINARY_READ
	GridPoint * energy_grid = generate_energy_grid( in.n_isotopes,
	                          in.n_gridpoints, nuclide_grids ); 	
	#else
	GridPoint * energy_grid = (GridPoint *)malloc( in.n_isotopes *
	                           in.n_gridpoints * sizeof( GridPoint ) );
	int * index_data = (int *) malloc( in.n_isotopes * in.n_gridpoints
	                   * in.n_isotopes * sizeof(int));
	for( i = 0; i < in.n_isotopes*in.n_gridpoints; i++ )
		energy_grid[i].xs_ptrs = &index_data[i*in.n_isotopes];
	#endif

	// Double Indexing. Filling in energy_grid with pointers to the
	// nuclide_energy_grids.
	#ifndef BINARY_READ
	set_grid_ptrs( energy_grid, nuclide_grids, in.n_isotopes, in.n_gridpoints );
	#endif

	#ifdef BINARY_READ
	if( mype == 0 ) printf("Reading data from \"XS_data.dat\" file...\n");
	binary_read(in.n_isotopes, in.n_gridpoints, nuclide_grids, energy_grid);
	#endif
	
	// Get material data
	if( mype == 0 )
		printf("Loading Mats...\n");
	int *num_nucs  = load_num_nucs(in.n_isotopes);
	int **mats     = load_mats(num_nucs, in.n_isotopes);

	#ifdef VERIFICATION
	double **concs = load_concs_v(num_nucs);
	#else
	double **concs = load_concs(num_nucs);
	#endif

	#ifdef BINARY_DUMP
	if( mype == 0 ) printf("Dumping data to binary file...\n");
	binary_dump(in.n_isotopes, in.n_gridpoints, nuclide_grids, energy_grid);
	if( mype == 0 ) printf("Binary file \"XS_data.dat\" written! Exiting...\n");
	return 0;
	#endif

	// =====================================================================
	// Cross Section (XS) Parallel Lookup Simulation Begins
	// =====================================================================

	// Outer benchmark loop can loop through all possible # of threads
	#if defined(BENCHMARK) && defined(OPENMP)
	for( int bench_n = 1; bench_n <=omp_get_num_procs(); bench_n++ )
	{
		in.nthreads = bench_n;
		omp_set_num_threads(in.nthreads);
 	#endif

	if( mype == 0 )
	{
		printf("\n");
		border_print();
		center_print("SIMULATION", 79);
		border_print();
	}

	#if defined(TIMING) && defined(OPENMP)
	omp_start = omp_get_wtime();
	#endif
  
	//initialize papi with one thread (master) here
	#ifdef PAPI
	if ( PAPI_library_init(PAPI_VER_CURRENT) != PAPI_VER_CURRENT){
		fprintf(stderr, "PAPI library init error!\n");
		exit(1);
	}
	#endif	

	// OpenMP compiler directives - declaring variables as shared or private
	#ifdef OPENMP
	#pragma omp parallel default(none) \
	private(i, thread, p_energy, mat, seed) \
	shared( max_procs, in, energy_grid, nuclide_grids, \
	        mats, concs, num_nucs, mype, vhash) 
	#endif
	{	
		// Initialize parallel PAPI counters
		#ifdef PAPI
		int eventset = PAPI_NULL; 
		int num_papi_events;
		#ifdef OPENMP
		#pragma omp critical
		#endif
		{
			counter_init(&eventset, &num_papi_events);
		}
		#endif

		double macro_xs_vector[5];
		double * xs = (double *) calloc(5, sizeof(double));

		// Initialize RNG seeds for threads
		#ifdef OPENMP
		thread = omp_get_thread_num();
		#endif
		seed   = (thread+1)*19+17;

		// XS Lookup Loop
		#ifdef OPENMP
		#pragma omp for schedule(dynamic)
		#endif
		for( i = 0; i < in.lookups; i++ )
		{
			// Status text
			if( INFO && mype == 0 && thread == 0 && i % 1000 == 0 )
				printf("\rCalculating XS's... (%.0lf%% completed)",
						(i / ( (double)in.lookups / (double) in.nthreads ))
						/ (double) in.nthreads * 100.0);

			// Randomly pick an energy and material for the particle
			#ifdef VERIFICATION
			#ifdef OPENMP
			#pragma omp critical
			#endif
			{
				p_energy = rn_v();
				mat      = pick_mat(&seed); 
			}
			#else
			p_energy = rn(&seed);
			mat      = pick_mat(&seed); 
			#endif
			
			// debugging
			//printf("E = %lf mat = %d\n", p_energy, mat);
				
			// This returns the macro_xs_vector, but we're not going
			// to do anything with it in this program, so return value
			// is written over.
			calculate_macro_xs( p_energy, mat, in.n_isotopes,
			                    in.n_gridpoints, num_nucs, concs,
			                    energy_grid, nuclide_grids, mats,
                                macro_xs_vector );
			
			// Copy results from above function call onto heap
			// so that compiler cannot optimize function out
			// (only occurs if -flto flag is used)
			memcpy(xs, macro_xs_vector, 5*sizeof(double));

			// Verification hash calculation
			// This method provides a consistent hash accross
			// architectures and compilers.
			#ifdef VERIFICATION
			char line[256];
			sprintf(line, "%.5lf %d %.5lf %.5lf %.5lf %.5lf %.5lf",
			       p_energy, mat,
				   macro_xs_vector[0],
				   macro_xs_vector[1],
				   macro_xs_vector[2],
				   macro_xs_vector[3],
				   macro_xs_vector[4]);
			unsigned long long vhash_local = hash(line, 10000);
			#ifdef OPENMP
			#pragma omp atomic
			#endif
			vhash += vhash_local;
			#endif
		}

		// Prints out thread local PAPI counters
		#ifdef PAPI
		if( mype == 0 && thread == 0 )
		{
			printf("\n");
			border_print();
			center_print("PAPI COUNTER RESULTS", 79);
			border_print();
			printf("Count          \tSmybol      \tDescription\n");
		}
		{
		#ifdef OPENMP
		#pragma omp barrier
		#endif
		}
		counter_stop(&eventset, num_papi_events);
		#endif

	}

	#ifndef PAPI
	if( mype == 0)	
	{	
		printf("\n" );
		printf("Simulation complete.\n" );
	}
	#endif

	#if defined(TIMING) && defined(OPENMP)
	omp_end = omp_get_wtime();
	#endif
	
	// Print / Save Results and Exit
	print_results( in, mype, omp_end-omp_start, nprocs, vhash );

	#ifdef BENCHMARK
	}
	#endif

	#ifdef MPI
	MPI_Finalize();
	#endif

	return 0;
}
