#include"SimpleMOC_header.h"

// generates a random number between 0 and 1
float urand(void)
{
	return (float)rand() / (float)RAND_MAX;
}

/* generates a random number from a normal distribution of a 
 * given mean and standard deviation (Box-Muller) */
float nrand(float mean, float sigma)
{
	// generate two random numbers
	float rand1 = urand();
	float rand2 = urand();

	/* use first for "exponential part" and second for
	 *  "azimuthal part" to create a standard normal random number */
	float x = sqrt( -2 * log(rand1) ) * cos( 2 * M_PI * rand2);

	// NOTE: We can generate a second random number if neeeded
	// y = sqrt(-2*log(rand1)) * sin( 2 * M_PI * rand2);
	
	// shift random number to appropriate normal distribution and return
	return x * sigma + mean;
}

// pairwise summation for long arrays
float pairwise_sum( float * vector, long size ){
	float sum = 0;

	// Base case: perform summation if size <= 16
	if( size <= 16)
		for( int i = 0; i < size; i++ )
			sum += vector[i];

	else
	{
		// otherwise, split
		sum = pairwise_sum( &vector[0], size/2 ) +
			pairwise_sum( &vector[size/2], size - size/2 );
	}
	
	return sum;
}

// Builds a table of exponential values for linear interpolation
Table buildExponentialTable( float precision, float maxVal )
{
	// define table
	Table table;

	// compute number of arry values
	int N = (int) ( maxVal * sqrt(1.0 / ( 8.0 * precision * 0.01 ) ) ); 

	// compute spacing
	float dx = maxVal / (float) N;

	// allocate an array to store information
	float * tableVals = malloc( (2 * N ) * sizeof(float) );

	// store linear segment information (slope and y-intercept)
	for( int n = 0; n < N; n++ )
	{
		// compute slope and y-intercept for ( 1 - exp(-x) )
		float exponential = exp( - n * dx );
		tableVals[ 2*n ] = - exponential;
		tableVals[ 2*n + 1 ] = 1 + ( n * dx - 1 ) * exponential;
	}

	// assign data to table
	table.dx = dx;
	table.values = tableVals;
	table.maxVal = maxVal - table.dx;
	table.N = N;

	return table;
}

// Timer function. Depends on if compiled with MPI, openmp, or vanilla
double get_time(void)
{
	#ifdef MPI
	return MPI_Wtime();
	#endif

	#ifdef OPENMP
	return omp_get_wtime();
	#endif

	time_t time;
	time = clock();

	return (double) time / (double) CLOCKS_PER_SEC;
}

// Memory Usage Estimator
size_t est_mem_usage( Input I )
{
	size_t nbytes = 0;
	
	int z_stacked = (int) ( I.height / (I.axial_z_sep * 
				I.decomp_assemblies_ax) );
	
	long n_xs_regions = I.n_source_regions_per_node / 8;

	nbytes += I.ntracks_2D * sizeof(Track2D);
	nbytes += I.segments_per_track * I.ntracks_2D * sizeof(Segment);
	nbytes += I.ntracks_2D * sizeof(Track **);
	nbytes += I.ntracks_2D * I.n_polar_angles * sizeof(Track *);
	nbytes += I.ntracks * sizeof(Track);
	nbytes += I.ntracks_2D * I.n_polar_angles * z_stacked 
		* I.n_egroups * sizeof(float) * 2;
	nbytes += I.n_source_regions_per_node * sizeof(Source);
	nbytes += n_xs_regions * sizeof(float **);
	nbytes += n_xs_regions * sizeof(float **);
	nbytes += n_xs_regions * I.n_egroups * I.n_egroups * sizeof(float);
	nbytes += n_xs_regions * sizeof(float **);
	nbytes += n_xs_regions * I.n_egroups * sizeof(float *);
	nbytes += n_xs_regions * I.n_egroups * 3 * sizeof(float);
	nbytes += I.n_source_regions_per_node * sizeof(float **);
	nbytes += I.n_source_regions_per_node * I.fai * sizeof(float *);
	nbytes += I.n_source_regions_per_node * sizeof(float **);
	nbytes += I.n_source_regions_per_node * I.fai * sizeof(float *);
	nbytes += I.n_source_regions_per_node * I.fai * I.n_egroups
		* sizeof(float);
	
	// 2way tracking memory
	nbytes += I.nthreads * I.z_stacked * sizeof(double *);
	nbytes += I.nthreads * I.z_stacked * sizeof(Source**);
	nbytes += I.nthreads * I.z_stacked * sizeof(int);
	nbytes += I.nthreads * I.z_stacked * sizeof(int);			
	nbytes += I.nthreads * I.z_stacked * 2 * I.segments_per_track 
		* sizeof(double);
	nbytes += I.nthreads * I.z_stacked * 2 * I.segments_per_track 
		* sizeof(Source *);		

	// MPI Buffers
	#ifdef MPI
	nbytes += 6 * I.n_egroups * 10000 * sizeof(float);
	#endif
	
	return nbytes;
}

// Calculates Time per Intersection
double time_per_intersection( Input I, double time )
{
	/* This was the old estimate - new way uses actual tracking data
	double tpi = time / (double) I.ntracks /
		(double) I.segments_per_track / (double) I.n_egroups / 1e-9 / 2; 
		*/
	double tpi = time / (double) I.segments_processed * 1.0e9 / (double) I.n_egroups;
	return tpi;
}
