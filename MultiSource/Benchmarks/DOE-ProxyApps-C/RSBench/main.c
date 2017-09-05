#include "rsbench.h"

int main(int argc, char * argv[])
{
	// =====================================================================
	// Initialization & Command Line Read-In
	// =====================================================================

	int version = 9;
	#ifdef OPENMP
	int max_procs = omp_get_num_procs();
	#else
	int max_procs = 1;
	#endif
	double start = 0.0, stop = 0.0;
	
	srand(time(NULL));
	
	// Process CLI Fields
	Input input = read_CLI( argc, argv );

	#ifdef OPENMP
	// Set number of OpenMP Threads
	omp_set_num_threads(input.nthreads); 
	#endif
	// =====================================================================
	// Print-out of Input Summary
	// =====================================================================
	logo(version);
	center_print("INPUT SUMMARY", 79);
	border_print();
	print_input_summary(input);

	// =====================================================================
	// Prepare Pole Paremeter Grids
	// =====================================================================
	border_print();
	center_print("INITIALIZATION", 79);
	border_print();

	#if defined(TIMING) && defined(OPENMP)	
	start = omp_get_wtime();
	#endif
	
	// Allocate & fill energy grids
	printf("Generating resonance distributions...\n");
	int * n_poles = generate_n_poles( input );

	// Allocate & fill Window grids
	printf("Generating window distributions...\n");
	int * n_windows = generate_n_windows( input );

	// Get material data
	printf("Loading Hoogenboom-Martin material data...\n");
	Materials materials = get_materials( input ); 

	// Prepare full resonance grid
	printf("Generating resonance parameter grid...\n");
	Pole ** poles = generate_poles( input, n_poles );

	// Prepare full Window grid
	printf("Generating window parameter grid...\n");
	Window ** windows = generate_window_params( input, n_windows, n_poles);

	// Prepare 0K Resonances
	printf("Generating 0K l_value data...\n");
	double ** pseudo_K0RS = generate_pseudo_K0RS( input );

	CalcDataPtrs data;
	data.n_poles = n_poles;
	data.n_windows = n_windows;
	data.materials = materials;
	data.poles = poles;
	data.windows = windows;
	data.pseudo_K0RS = pseudo_K0RS;
	#if defined(TIMING) && defined(OPENMP)
	stop = omp_get_wtime();
	#endif
	printf("Initialization Complete. (%.2lf seconds)\n", stop-start);
	
	// =====================================================================
	// Cross Section (XS) Parallel Lookup Simulation Begins
	// =====================================================================
	border_print();
	center_print("SIMULATION", 79);
	border_print();
	
	printf("Beginning Simulation.\n");
	#ifndef STATUS
	printf("Calculating XS's...\n");
	#endif
	
	#ifdef PAPI
	/* initialize papi with one thread here  */
	if ( PAPI_library_init(PAPI_VER_CURRENT) != PAPI_VER_CURRENT){
		fprintf(stderr, "PAPI library init error!\n");
		exit(1);
	}
	#endif	

	#if defined(TIMING) && defined(OPENMP)
	start = omp_get_wtime();
	#endif

	long g_abrarov = 0; 
	long g_alls = 0;
	#pragma omp parallel default(none) \
	shared(input, data) \
	reduction(+:g_abrarov, g_alls)
	{
		unsigned long seed = time(NULL)+1;
		double macro_xs[4];
		double * xs = (double *) calloc(4, sizeof(double));
		int thread = 0;
		#ifdef OPENMP
		thread = omp_get_thread_num();
		#endif
		seed += thread;
		int mat;
		double E;
		long abrarov = 0; 
		long alls = 0;

		#ifdef PAPI
		int eventset = PAPI_NULL; 
		int num_papi_events;
		#pragma omp critical
		{
			counter_init(&eventset, &num_papi_events);
		}
		#endif
		complex double * sigTfactors =
			(complex double *) malloc( input.numL * sizeof(complex double) );

		#pragma omp for schedule(dynamic)
		for( int i = 0; i < input.lookups; i++ )
		{
			#ifdef STATUS
			if( thread == 0 && i % 1000 == 0 )
				printf("\rCalculating XS's... (%.0lf%% completed)",
						(i / ( (double)input.lookups /
							   (double) input.nthreads )) /
						(double) input.nthreads * 100.0);
			#endif
			mat = pick_mat( &seed );
			E = rn( &seed );
			calculate_macro_xs( macro_xs, mat, E, input, data, sigTfactors, &abrarov, &alls ); 
			// Results are copied onto heap to avoid some compiler
			// flags (-flto) from optimizing out function call
			memcpy(xs, macro_xs, 4*sizeof(double));
		}

		free(sigTfactors);

		// Accumulate global counters
		g_abrarov = abrarov; 
		g_alls = alls;

		#ifdef PAPI
		if( thread == 0 )
		{
			printf("\n");
			border_print();
			center_print("PAPI COUNTER RESULTS", 79);
			border_print();
			printf("Count          \tSmybol      \tDescription\n");
		}
		{
			#pragma omp barrier
		}
		counter_stop(&eventset, num_papi_events);
		#endif
	}

	#if defined(TIMING) && defined(OPENMP)
	stop = omp_get_wtime();
	#endif

	#ifndef PAPI
	printf("\nSimulation Complete.\n");
	#endif
	// =====================================================================
	// Print / Save Results and Exit
	// =====================================================================
	#ifdef RESULTS
	border_print();
	center_print("RESULTS", 79);
	border_print();

	printf("Threads:       %d\n", input.nthreads);
	if( input.doppler)
		printf("Slow Faddeeva: %.2lf%%\n", (double) g_abrarov/g_alls * 100.f);
	printf("Runtime:       %.3lf seconds\n", stop-start);
	printf("Lookups:       "); fancy_int(input.lookups);
	printf("Lookups/s:     "); fancy_int((double) input.lookups / (stop-start));

	border_print();
	#endif
	return 0;
}
