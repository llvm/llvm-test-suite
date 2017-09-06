#include"SimpleMOC_header.h"

// intitialize source structures and intitialize XS values to random numbers
Source * initialize_sources( Input I, size_t * nbytes )
{
	// Allocate space
	Source * sources = (Source *) malloc( I.n_source_regions_per_node 
			* sizeof(Source) );
	*nbytes += I.n_source_regions_per_node * sizeof(Source);

	// determine number of cross section and coarse axial regions
	long n_xs_regions = I.n_source_regions_per_node / 8;
	
	///////////////////////////////////////////////////////////////////////////
	
	// Allocate scattering matrix matrix ptrs
	float *** s_matrices = (float ***) malloc( n_xs_regions 
			* sizeof(float**) );
	*nbytes += n_xs_regions * sizeof(float **);

	// Allocate space for ALL scattering matrix ptrs
	float ** s_matrix_ptrs = (float **) malloc( n_xs_regions * I.n_egroups 
			* sizeof(float *));
	*nbytes += n_xs_regions * sizeof(float **);

	// Allocate space for ALL scattering data
#ifdef PRINT_MEM_SIZES
	if(I.mype==0) 
		printf("Scattering data requires %zu MB of data...\n", 
				n_xs_regions * I.n_egroups * I.n_egroups 
				* sizeof(float) / 1024 / 1024);
#endif
	float * s_matrix_data = (float *) malloc( n_xs_regions * I.n_egroups
		   	* I.n_egroups * sizeof(float));
	*nbytes += n_xs_regions * I.n_egroups * I.n_egroups * sizeof(float);

	// Stitch allocation ptrs together
	for( long i = 0; i < n_xs_regions; i++ )
		s_matrices[i] = &s_matrix_ptrs[i * I.n_egroups];

	for( long i = 0; i < n_xs_regions; i++ )
		for( long j = 0; j < I.n_egroups; j++ )
			s_matrices[i][j] = &s_matrix_data[i * I.n_egroups * I.n_egroups 
				+ j * I.n_egroups];

	// Iniitalize Scattering Matrix Values
	for( long i = 0; i < n_xs_regions; i++ )
		for( long j = 0; j < I.n_egroups; j++ )
			for( long k = 0; k < I.n_egroups; k++ )
				s_matrices[i][j][k] = urand();

	///////////////////////////////////////////////////////////////////////////
	
	/*
	 * Create data scrtucture for storing XS data (and chi) as follows:
	 * An array is created which stores in contigious memory as
	 * [ ... , nu*SigmaF, SigmaA, Chi, ...]
	 */
	
	if(I.mype==0) printf("Beginning XS Allocation...\n");

	// Allocate space for XS ptrs (by region)
	float *** XS = (float ***) malloc( n_xs_regions * sizeof(float **) );
	*nbytes += n_xs_regions * sizeof(float **);

	// Allocate space for each XS type of interest (total, nu*SigmaF, and chi)
	float ** XS_arrays = (float **) malloc (n_xs_regions * I.n_egroups
		   	* sizeof(float *) );
	*nbytes += n_xs_regions * I.n_egroups * sizeof(float *);

	// Allocate space for total XS data
	float * XS_data = (float *) malloc( n_xs_regions * I.n_egroups * 3 
			* sizeof(float) );
	*nbytes += n_xs_regions * I.n_egroups * 3 * sizeof(float);

	// stitch allocation ptrs together for XS data
	for( long i = 0; i < n_xs_regions; i++)
		XS[i] = &XS_arrays[i * I.n_egroups];

	for( long i = 0; i < n_xs_regions; i++)
		for(long j = 0; j < I.n_egroups; j++)
			XS[i][j] = &XS_data[i * I.n_egroups * 3 + j * 3];

	// Initialize XS data
	for( long i = 0; i < n_xs_regions; i++)
		for( int j = 0; j < I.n_egroups; j++)
			for( int k = 0; k < 3; k++)
				XS[i][j][k] = urand();

	///////////////////////////////////////////////////////////////////////////

	/* Here I allocate useful source parameters and fluxes for use in the
	 * attenuate_fluxes function in solver.c - the parameters are arranged
	 * contigiously for efficiency */

	if(I.mype==0) printf("Beginning Source and Flux Parameter Allocation...\n");

	// Allocate space for source parameters (quadratic axially)
	float *** fineSource = (float ***) malloc( I.n_source_regions_per_node
		   	* sizeof(float **) );
	*nbytes += I.n_source_regions_per_node * sizeof(float **);

	// Allocate space for array pointers to parameters
	float ** fineSourcePtrs = (float **) malloc ( I.n_source_regions_per_node
		   	* I.fai * sizeof(float *) );
	*nbytes += I.n_source_regions_per_node * I.fai * sizeof(float *);

	// Allocate space for flux parameters (quadratic axially)
	float *** fineFlux = (float ***) malloc( I.n_source_regions_per_node
		   	* sizeof(float **) );
	*nbytes += I.n_source_regions_per_node * sizeof(float **);

	// Allocate space for array pointers to parameters
	float ** fineFluxPtrs = (float **) malloc ( I.n_source_regions_per_node
		   	* I.fai * sizeof(float *) );
	*nbytes += I.n_source_regions_per_node * I.fai * sizeof(float *);

	// Allocate space for cross section pointers
	float ** sigT = (float **) malloc( I.n_source_regions_per_node
			* sizeof(float *) );

	// Allocate space for parameter data
	float * data = (float *) malloc( (2 * I.fai + 1) * 
			I.n_source_regions_per_node * I.n_egroups * sizeof(float) );

	*nbytes += I.n_source_regions_per_node * I.fai * I.n_egroups 
		* sizeof(float);

	///////////////////////////////////////////////////////////////////////////
	
	// stitch pointers together

	// stitch allocation ptrs together for source data
	for( long i = 0; i < I.n_source_regions_per_node; i++)
		fineSource[i] = &fineSourcePtrs[i * I.fai];

	for( long i = 0; i < I.n_source_regions_per_node; i++)
		for(long j = 0; j < I.fai; j++)
			fineSource[i][j] = &data[i * I.fai * I.n_egroups
			   	+ j * I.n_egroups];

	// stitch allocation ptrs together for flux data
	for( long i = 0; i < I.n_source_regions_per_node; i++)
		fineFlux[i] = &fineFluxPtrs[i * I.fai];

	for( long i = 0; i < I.n_source_regions_per_node; i++)
		for(int j = 0; j < I.fai; j++)
			fineFlux[i][j] = &data[I.n_egroups * I.fai * 
				(I.n_source_regions_per_node + i) + j * I.n_egroups];
	
	// stitch allocation ptrs together for total XS
	for( long i = 0; i < I.n_source_regions_per_node; i++)
		sigT[i] = &data[ 2 * I.n_source_regions_per_node * I.fai * I.n_egroups 
			+ i * I.n_egroups];

	///////////////////////////////////////////////////////////////////////////

	// Initialize source to random numbers
	for( long i = 0; i < I.n_source_regions_per_node; i++)
		for( int j = 0; j < I.fai; j++)
			for( int k = 0; k < I.n_egroups; k++)
				fineSource[i][j][k] = urand();
		
	// Initialize fine flux to zeros
	for( long i = 0; i < I.n_source_regions_per_node; i++)
		for( int j = 0; j < I.fai; j++)
			for( int k = 0; k < I.n_egroups; k++)
				fineFlux[i][j][k] = 0;
	

	// Initialize total XS to random numbers
	for( long i = 0; i < I.n_source_regions_per_node; i++)
		for( int k = 0; k < I.n_egroups; k++)
			sigT[i][k] = urand();

	///////////////////////////////////////////////////////////////////////////
	//
	
	#ifdef OPENMP
	omp_lock_t * locks = init_locks(I);
	long lock_idx = 0;
	#endif

	// Assign to source regions
	for( long i = 0; i < I.n_source_regions_per_node; i++ )
	{
		long idx;
		if( i == 0 )
			idx = 0;
		else
			idx = rand() % n_xs_regions;

		sources[i].scattering_matrix = s_matrices[idx];
		sources[i].XS = XS[idx];
		sources[i].fine_flux = fineFlux[i];
		sources[i].fine_source = fineSource[i]; 
		sources[i].sigT = sigT[i];

		// initialize FSR volume
		sources[i].vol = urand();

		#ifdef OPENMP
		sources[i].locks = &locks[lock_idx];
		lock_idx += I.fai;
		#endif
	}

	// free memory of temporary variables
	free( s_matrices );
	free( XS );
	free( fineFlux );
	free( fineSource);
	free( sigT);

	return sources;
}

void free_sources( Input I, Source * sources )
{
	// Free XS's
	free( sources[0].XS[0] );
	free( sources[0].XS );
	// Free Flux's
	free( sources[0].fine_flux[0] );
	free( sources[0].fine_flux );
	// Free scattering matrices
	free( sources[0].scattering_matrix[0] );
	free( sources[0].scattering_matrix );
	// Free source values
	free( sources[0].fine_source[0] );
	free( sources[0].fine_source );
}
