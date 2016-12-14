#include "XSbench_header.h"

#ifdef MPI
#include<mpi.h>
#endif

// Prints program logo
void logo(int version)
{
	border_print();
	printf(
	"                   __   __ ___________                 _                        \n"
	"                   \\ \\ / //  ___| ___ \\               | |                       \n"
	"                    \\ V / \\ `--.| |_/ / ___ _ __   ___| |__                     \n"
	"                    /   \\  `--. \\ ___ \\/ _ \\ '_ \\ / __| '_ \\                    \n"
	"                   / /^\\ \\/\\__/ / |_/ /  __/ | | | (__| | | |                   \n"
	"                   \\/   \\/\\____/\\____/ \\___|_| |_|\\___|_| |_|                   \n\n"
    );
	border_print();
	center_print("Developed at Argonne National Laboratory", 79);
	char v[100];
	sprintf(v, "Version: %d", version);
	center_print(v, 79);
	border_print();
}

// Prints Section titles in center of 80 char terminal
void center_print(const char *s, int width)
{
	int length = strlen(s);
	int i;
	for (i=0; i<=(width-length)/2; i++) {
		fputs(" ", stdout);
	}
	fputs(s, stdout);
	fputs("\n", stdout);
}

void print_results( Inputs in, int mype, double runtime, int nprocs,
	unsigned long long vhash )
{
	// Calculate Lookups per sec
	int lookups_per_sec = (int) ((double) in.lookups / runtime);
	
	// If running in MPI, reduce timing statistics and calculate average
	#ifdef MPI
	int total_lookups = 0;
	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Reduce(&lookups_per_sec, &total_lookups, 1, MPI_INT,
	           MPI_SUM, 0, MPI_COMM_WORLD);
	#endif
	
	// Print output
	if( mype == 0 )
	{
		border_print();
		center_print("RESULTS", 79);
		border_print();

		// Print the results
		printf("Threads:     %d\n", in.nthreads);
		#ifdef MPI
		printf("MPI ranks:   %d\n", nprocs);
		#endif
		#ifdef TIMING
		#ifdef MPI
		printf("Total Lookups/s:            ");
		fancy_int(total_lookups);
		printf("Avg Lookups/s per MPI rank: ");
		fancy_int(total_lookups / nprocs);
		#else
		printf("Runtime:     %.3lf seconds\n", runtime);
		printf("Lookups:     "); fancy_int(in.lookups);
		printf("Lookups/s:   ");
		fancy_int(lookups_per_sec);
		#endif
		#endif
		#ifdef VERIFICATION
		printf("Verification checksum: %llu\n", vhash);
		#endif
		border_print();

		// For bechmarking, output lookup/s data to file
		if( SAVE )
		{
			FILE * out = fopen( "results.txt", "a" );
			fprintf(out, "%d\t%d\n", in.nthreads, lookups_per_sec);
			fclose(out);
		}
	}
}

void print_inputs(Inputs in, int nprocs, int version )
{
	// Calculate Estimate of Memory Usage
	int mem_tot = estimate_mem_usage( in );
	logo(version);
	center_print("INPUT SUMMARY", 79);
	border_print();
	#ifdef VERIFICATION
	printf("Verification Mode:            on\n");
	#endif
	printf("Materials:                    %d\n", 12);
	printf("H-M Benchmark Size:           %s\n", in.HM);
	printf("Total Nuclides:               %ld\n", in.n_isotopes);
	printf("Gridpoints (per Nuclide):     ");
	fancy_int(in.n_gridpoints);
	printf("Unionized Energy Gridpoints:  ");
	fancy_int(in.n_isotopes*in.n_gridpoints);
	printf("XS Lookups:                   "); fancy_int(in.lookups);
	#ifdef MPI
	printf("MPI Ranks:                    %d\n", nprocs);
	printf("OMP Threads per MPI Rank:     %d\n", in.nthreads);
	printf("Mem Usage per MPI Rank (MB):  "); fancy_int(mem_tot);
	#else
	printf("Threads:                      %d\n", in.nthreads);
	printf("Est. Memory Usage (MB):       "); fancy_int(mem_tot);
	#endif
	border_print();
	center_print("INITIALIZATION", 79);
	border_print();
}

void border_print(void)
{
	printf(
	"==================================================================="
	"=============\n");
}

// Prints comma separated integers - for ease of reading
void fancy_int( long a )
{
    if( a < 1000 )
        printf("%ld\n",a);

    else if( a >= 1000 && a < 1000000 )
        printf("%ld,%03ld\n", a / 1000, a % 1000);

    else if( a >= 1000000 && a < 1000000000 )
        printf("%ld,%03ld,%03ld\n",a / 1000000,(a % 1000000) / 1000,a % 1000 );

    else if( a >= 1000000000 )
        printf("%ld,%03ld,%03ld,%03ld\n",
               a / 1000000000,
               (a % 1000000000) / 1000000,
               (a % 1000000) / 1000,
               a % 1000 );
    else
        printf("%ld\n",a);
}

void print_CLI_error(void)
{
	printf("Usage: ./XSBench <options>\n");
	printf("Options include:\n");
	printf("  -t <threads>     Number of OpenMP threads to run\n");
	printf("  -s <size>        Size of H-M Benchmark to run (small, large, XL, XXL)\n");
	printf("  -g <gridpoints>  Number of gridpoints per nuclide (overrides -s defaults)\n");
	printf("  -l <lookups>     Number of Cross-section (XS) lookups\n");
	printf("Default is equivalent to: -s large -l 15000000\n");
	printf("See readme for full description of default run values\n");
	exit(4);
}

Inputs read_CLI( int argc, char * argv[] )
{
	Inputs input;
	
	// defaults to max threads on the system	
	#ifdef OPENMP
	input.nthreads = omp_get_num_procs();
	#else
	input.nthreads = 1;
	#endif
	
	// defaults to 355 (corresponding to H-M Large benchmark)
	input.n_isotopes = 355;
	
	// defaults to 11303 (corresponding to H-M Large benchmark)
	input.n_gridpoints = 11303;
	
	// defaults to 15,000,000
	input.lookups = 15000000;
	
	// defaults to H-M Large benchmark
	input.HM = (char *) malloc( 6 * sizeof(char) );
	input.HM[0] = 'l' ; 
	input.HM[1] = 'a' ; 
	input.HM[2] = 'r' ; 
	input.HM[3] = 'g' ; 
	input.HM[4] = 'e' ; 
	input.HM[5] = '\0';
	
	// Check if user sets these
	int user_g = 0;
	
	// Collect Raw Input
	for( int i = 1; i < argc; i++ )
	{
		char * arg = argv[i];

		// nthreads (-t)
		if( strcmp(arg, "-t") == 0 )
		{
			if( ++i < argc )
				input.nthreads = atoi(argv[i]);
			else
				print_CLI_error();
		}
		// n_gridpoints (-g)
		else if( strcmp(arg, "-g") == 0 )
		{	
			if( ++i < argc )
			{
				user_g = 1;
				input.n_gridpoints = atol(argv[i]);
			}
			else
				print_CLI_error();
		}
		// lookups (-l)
		else if( strcmp(arg, "-l") == 0 )
		{
			if( ++i < argc )
				input.lookups = atoi(argv[i]);
			else
				print_CLI_error();
		}
		// HM (-s)
		else if( strcmp(arg, "-s") == 0 )
		{	
			if( ++i < argc )
				input.HM = argv[i];
			else
				print_CLI_error();
		}
		else
			print_CLI_error();
	}

	// Validate Input

	// Validate nthreads
	if( input.nthreads < 1 )
		print_CLI_error();
	
	// Validate n_isotopes
	if( input.n_isotopes < 1 )
		print_CLI_error();
	
	// Validate n_gridpoints
	if( input.n_gridpoints < 1 )
		print_CLI_error();

	// Validate lookups
	if( input.lookups < 1 )
		print_CLI_error();
	
	// Validate HM size
	if( strcasecmp(input.HM, "small") != 0 &&
		strcasecmp(input.HM, "large") != 0 &&
		strcasecmp(input.HM, "XL") != 0 &&
		strcasecmp(input.HM, "XXL") != 0 )
		print_CLI_error();
	
	// Set HM size specific parameters
	// (defaults to large)
	if( strcasecmp(input.HM, "small") == 0 )
		input.n_isotopes = 68;
	else if( strcasecmp(input.HM, "XL") == 0 && user_g == 0 )
		input.n_gridpoints = 238847; // sized to make 120 GB XS data
	else if( strcasecmp(input.HM, "XXL") == 0 && user_g == 0 )
		input.n_gridpoints = 238847 * 2.1; // 252 GB XS data

	// Return input struct
	return input;
}
