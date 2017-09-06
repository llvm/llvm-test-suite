#include "SimpleMOC_header.h"

// Prints program logo
void logo(int version)
{
	border_print();
	printf(
"              _____ _                 _      __  __  ____   _____ \n"
"             / ____(_)               | |    |  \\/  |/ __ \\ / ____|\n"
"            | (___  _ _ __ ___  _ __ | | ___| \\  / | |  | | |     \n"
"             \\___ \\| | '_ ` _ \\| '_ \\| |/ _ \\ |\\/| | |  | | |     \n"
"             ____) | | | | | | | |_) | |  __/ |  | | |__| | |____ \n"
"            |_____/|_|_| |_| |_| .__/|_|\\___|_|  |_|\\____/ \\_____|\n"
"                               | |                                \n"
"                               |_|                                \n"
	);
	border_print();
	printf("\n");
	center_print("Developed at", 79);
	center_print("The Massachusetts Institute of Technology", 79);
	center_print("and", 79);
	center_print("Argonne National Laboratory", 79);
	printf("\n");
	char v[100];
	sprintf(v, "Version: %d", version);
	center_print(v, 79);
	printf("\n");
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

// Prints a border
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

// Prints out the summary of User input
void print_input_summary(Input I)
{
	center_print("INPUT SUMMARY", 79);
	border_print();
	#ifdef MPI
	int nranks;
	MPI_Comm_size(MPI_COMM_WORLD, &nranks);
	printf("%-35s%d\n", "MPI Ranks:", nranks); 
	#endif
	#ifdef OPENMP
	printf("%-35s%d\n", "Number of Threads:", I.nthreads);
	#endif
	printf("%-35s%d\n", "x-axis assemblies:", I.x_assemblies);
	printf("%-35s%d\n", "y-axis assemblies:", I.y_assemblies);
	printf("%-35s%d\n", "coarse axial intervals:", I.cai);
	printf("%-35s%d\n", "fine axial intervals:", I.fai);
	printf("%-35s%d\n", "axial source expansion order:", I.axial_exp);
	printf("%-35s%.2lf\n", "radial ray separation:", I.radial_ray_sep);
	printf("%-35s%.2lf\n", "axial z-ray separation:", I.axial_z_sep);
	printf("%-35s%d\n", "azimuthal angles:", I.n_azimuthal);
	printf("%-35s%d\n", "polar angles:", I.n_polar_angles);
	printf("%-35s%d\n", "energy groups:", I.n_egroups);
	printf("%-35s%d\n", "assemblies per axial sub-domain:", 
			I.decomp_assemblies_ax);
	printf("%-35s%ld\n", "avg segments per track:", I.segments_per_track);
	printf("%-35s%.2lf\n", "assembly width:", I.assembly_width);
	printf("%-35s%.2lf\n", "reactor height:", I.height);
	printf("%-35s%ld\n", "2D Src regions per assembly:", 
			I.n_2D_source_regions_per_assembly);
	printf("%-35s%ld\n", "2D Tracks:", I.ntracks_2D);
	printf("%-35s", "3D Tracks:"); fancy_int(I.ntracks);
#ifdef PRINT_MEM_SIZES
	printf("%-35s%zu (MB)\n", "Estimated Memory Usage:",
			est_mem_usage(I) / 1024 / 1024);
#endif
	#ifdef PAPI
    if( I.papi_event_set == -1)
        printf("%-35s%s\n", "PAPI event to count:", I.event_name);
	#endif
	border_print();
}

// reads command line inputs and applies options
void read_CLI( int argc, char * argv[], Input * input )
{
	// defaults to max threads on the system	
	#ifdef OPENMP
	input->nthreads = omp_get_num_procs();
	#else
	input->nthreads = 1;
	#endif
	
	// Collect Raw Input
	for( int i = 1; i < argc; i++ )
	{
		char * arg = argv[i];

		// nthreads (-t)
		if( strcmp(arg, "-t") == 0 )
		{
			if( ++i < argc )
				input->nthreads = atoi(argv[i]);
			else
				print_CLI_error();
		}
		// input file (-i)
		else if( strcmp(arg, "-i") == 0 )
		{
			if( ++i < argc )
				read_input_file( input, argv[i]);
			else
				print_CLI_error();
		}
		// set input for small problem (-s)
		else if( strcmp(arg, "-s") == 0)
			set_small_input( input );

        #ifdef PAPI
        // Add single PAPI event
        else if( strcmp(arg, "-p") == 0 )
        {
            if( ++i < argc ){
                input->papi_event_set = -1;
                strcpy(input->event_name, argv[i]);
            }
            else
                print_CLI_error();
        }
        #endif
		// Load OpenMOC track data file
		else if( strcmp(arg,"-d") == 0)
		{
			if( ++i < argc )
			{
				input->track_file = argv[i];
				input->load_tracks = true;
			}
			else
				print_CLI_error();
		}
		else
			print_CLI_error();
	}

	// Validate Input

	// Validate nthreads
	if( input->nthreads < 1 )
		print_CLI_error();
}

// print error to screen, inform program options
void print_CLI_error(void)
{
	printf("Usage: ./SimpleMOC <options>\n");
	printf("Options include:\n");
	printf("  -t <threads>     Number of OpenMP threads to run\n");
	printf("  -i <filename>    Input file name\n");
    printf("  -p <PAPI event>  PAPI event name to count (1 only) \n");
    printf("  -s               Small problem flag \n");
	printf("  -d <filename>    OpenMOC tracking file\n");
	printf("See readme for full description of default run values\n");
	exit(1);
}

// read input file describing problem parameters
void read_input_file( Input * I, char * fname)
{
	#if TIMING_INFO | 0
		printf("Attempting to open FIle: %s\n", fname);
	#endif
    	FILE * fp = fopen(fname, "r");
	#if TIMING_INFO | 0
		printf("Opened FIle: %s\n", fname);
	#endif
	if( fp == NULL )
		printf("FIle Open FAILED\n");
    char c[255];

	char * stat;
	int err;

    err = fscanf(fp, "%d", &I->x_assemblies);
    stat = fgets(c, 255, fp);

    err = fscanf(fp, "%d", &I->y_assemblies);
    stat = fgets(c, 255, fp);
    
	err = fscanf(fp, "%d", &I->cai);
    stat = fgets(c, 255, fp);
	
	err = fscanf(fp, "%d", &I->fai);
    stat = fgets(c, 255, fp);
	
	err = fscanf(fp, "%d", &I->axial_exp);
    stat = fgets(c, 255, fp);
	
	err = fscanf(fp, "%f", &I->radial_ray_sep);
    stat = fgets(c, 255, fp);
	
	err = fscanf(fp, "%f", &I->axial_z_sep);
    stat = fgets(c, 255, fp);
	
	err = fscanf(fp, "%d", &I->n_azimuthal);
    stat = fgets(c, 255, fp);
	
	err = fscanf(fp, "%d", &I->n_polar_angles);
    stat = fgets(c, 255, fp);
	
	err = fscanf(fp, "%d", &I->n_egroups);
    stat = fgets(c, 255, fp);

	int decompose;	
	err = fscanf(fp, "%d", &decompose);
    stat = fgets(c, 255, fp);
	if(decompose == 0)
		I->decompose = false;
	else
		I->decompose = true;
	
	err = fscanf(fp, "%d", &I->decomp_assemblies_ax);
    stat = fgets(c, 255, fp);
	
	err = fscanf(fp, "%ld", &I->segments_per_track);
    stat = fgets(c, 255, fp);
	
	err = fscanf(fp, "%f", &I->assembly_width);
    stat = fgets(c, 255, fp);
	
	err = fscanf(fp, "%f", &I->height);
    stat = fgets(c, 255, fp);
	
	err = fscanf(fp, "%f", &I->precision);
    stat = fgets(c, 255, fp);

	err = fscanf(fp, "%ld", &I->n_2D_source_regions_per_assembly);
    stat = fgets(c, 255, fp);
	
	err = fscanf(fp, "%d", &I->papi_event_set);
    stat = fgets(c, 255, fp);

	fclose(fp);
}
