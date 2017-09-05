#include "rsbench.h"

// Prints program logo
void logo(int version)
{
	border_print();
	printf(
"                    _____   _____ ____                  _     \n"
"                   |  __ \\ / ____|  _ \\                | |    \n"
"                   | |__) | (___ | |_) | ___ _ __   ___| |__  \n"
"                   |  _  / \\___ \\|  _ < / _ \\ '_ \\ / __| '_ \\ \n"
"                   | | \\ \\ ____) | |_) |  __/ | | | (__| | | |\n"
"                   |_|  \\_\\_____/|____/ \\___|_| |_|\\___|_| |_|\n"
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

void border_print(void)
{
	printf(
	"==================================================================="
	"=============\n");
}

// Prints comma separated integers - for ease of reading
void fancy_int( int a )
{
    if( a < 1000 )
        printf("%d\n",a);

    else if( a >= 1000 && a < 1000000 )
        printf("%d,%03d\n", a / 1000, a % 1000);

    else if( a >= 1000000 && a < 1000000000 )
        printf("%d,%03d,%03d\n", a / 1000000, (a % 1000000) / 1000, a % 1000 );

    else if( a >= 1000000000 )
        printf("%d,%03d,%03d,%03d\n",
               a / 1000000000,
               (a % 1000000000) / 1000000,
               (a % 1000000) / 1000,
               a % 1000 );
    else
        printf("%d\n",a);
}

Input read_CLI( int argc, char * argv[] )
{
	Input input;
	
	// defaults to max threads on the system
	#ifdef OPENMP
	input.nthreads = omp_get_num_procs();
	#else
	input.nthreads = 1;
	#endif
	// defaults to 355 (corresponding to H-M Large benchmark)
	input.n_nuclides = 355;
	// defaults to 10,000,000
	input.lookups = 10000000;
	// defaults to H-M Large benchmark
	input.HM = LARGE;
	// defaults to 3000 resonancs (avg) per nuclide
	input.avg_n_poles = 1000;
	// defaults to 100
	input.avg_n_windows = 100;
	// defaults to 4;
	input.numL = 4;
	// defaults to no temperature dependence (Doppler broadening)
	input.doppler = 1;
	
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
		// lookups (-l)
		else if( strcmp(arg, "-l") == 0 )
		{
			if( ++i < argc )
				input.lookups = atoi(argv[i]);
			else
				print_CLI_error();
		}
		// nuclides (-n)
		else if( strcmp(arg, "-n") == 0 )
		{
			if( ++i < argc )
				input.n_nuclides = atoi(argv[i]);
			else
				print_CLI_error();
		}
		// HM (-s)
		else if( strcmp(arg, "-s") == 0 )
		{	
			if( ++i < argc )
			{
				if( strcmp(argv[i], "small") == 0 )
					input.HM = SMALL;
				else if ( strcmp(argv[i], "large") == 0 )
					input.HM = LARGE;
				else
					print_CLI_error();
			}
			else
				print_CLI_error();
		}
		// Doppler Broadening (Temperature Dependence)
		else if( strcmp(arg, "-d") == 0 )
		{	
			input.doppler = 0;
		}
		// Avg number of windows per nuclide (-w)
		else if( strcmp(arg, "-w") == 0 )
		{
			if( ++i < argc )
				input.avg_n_windows = atoi(argv[i]);
			else
				print_CLI_error();
		}
		// Avg number of poles per nuclide (-p)
		else if( strcmp(arg, "-p") == 0 )
		{
			if( ++i < argc )
				input.avg_n_poles = atoi(argv[i]);
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
	if( input.n_nuclides < 1 )
		print_CLI_error();
	
	// Validate lookups
	if( input.lookups < 1 )
		print_CLI_error();
	
	// Validate lookups
	if( input.avg_n_poles < 1 )
		print_CLI_error();
	
	// Validate lookups
	if( input.avg_n_windows < 1 )
		print_CLI_error();
	
	// Set HM size specific parameters
	// (defaults to large)
	if( input.HM == SMALL )
		input.n_nuclides = 68;

	// Return input struct
	return input;
}

void print_CLI_error(void)
{
	printf("Usage: ./multibench <options>\n");
	printf("Options include:\n");
	printf("  -t <threads>     Number of OpenMP threads to run\n");
	printf("  -s <size>        Size of H-M Benchmark to run (small, large)\n");
	printf("  -l <lookups>     Number of Cross-section (XS) lookups\n");
	printf("  -p <poles>       Average Number of Poles per Nuclide\n");
	printf("  -w <poles>       Average Number of Windows per Nuclide\n");
	printf("  -d               Disables Temperature Dependence (Doppler Broadening)\n");
	printf("Default is equivalent to: -s large -l 10000000 -p 1000 -w 100\n");
	printf("See readme for full description of default run values\n");
	exit(4);
}

void print_input_summary(Input input)
{
	// Calculate Estimate of Memory Usage
	size_t mem = get_mem_estimate(input);

	printf("Materials:                   12\n");
	printf("H-M Benchmark Size:          ");
	if( input.HM == 0 )
		printf("Small\n");
	else
		printf("Large\n");
	if( input.doppler == 1 )
		printf("Temperature Dependence:      ON\n");
	else
		printf("Temperature Dependence:      OFF\n");
	printf("Total Nuclides:              %d\n", input.n_nuclides);
	printf("Avg Poles per Nuclide:       "); fancy_int(input.avg_n_poles);
	printf("Avg Windows per Nuclide:     "); fancy_int(input.avg_n_windows);
	printf("XS Lookups:                  "); fancy_int(input.lookups);
	printf("Threads:                     %d\n", input.nthreads);
	printf("Est. Memory Usage (MB):      %.1lf\n", mem / 1024.0 / 1024.0);
	#ifdef PAPI
	printf("PAPI Performance Counters:   ON\n");
	#endif
}
