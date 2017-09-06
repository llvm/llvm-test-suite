#include"SimpleMOC_header.h"

/* Efficient version of attenuate fluxes which determines the change in angular
 * flux along a particular track across a fine axial region and tallies the 
 * contribution to the scalar flux in the fine axial region. This function
 * assumes a quadratic source, which is calculated on the fly using neighboring
 * source values. 
 * 
 * This version decomposes the work into many for loops for efficient SIMD 
 * instructions and to reduce register pressure. For a more descriptive 
 * (but less effiient) version of the code in terms of the underlying physics, 
 * see alt_attenuate_fluxes which solves the problem in a more naive, 
 * straightforward manner. */
void attenuate_fluxes( Track * track, bool forward, Source * QSR, Input * I_in,
		Params * params_in, float ds, float mu, float az_weight, 
		AttenuateVars * A ) 
{
	Input I = *I_in;
	Params params = *params_in;

	// unload attenuate vars
	float * restrict q0 = A->q0;
	float *  restrict q1 = A->q1;
	float *  restrict q2 = A->q2;
	float *  restrict sigT = A->sigT;
	float *  restrict tau = A->tau;
	float *  restrict sigT2 = A->sigT2;
	float *  restrict expVal = A->expVal;
	float *  restrict reuse = A->reuse;
	float *  restrict flux_integral = A->flux_integral;
	float *  restrict tally = A->tally;
	float *  restrict t1 = A->t1;
	float *  restrict t2 = A->t2;
	float *  restrict t3 = A->t3;
	float *  restrict t4 = A->t4;

	// compute fine axial interval spacing
	float dz = I.height / (I.fai * I.decomp_assemblies_ax * I.cai);

	// compute z height in cell
	float zin = track->z_height - dz * 
		( (int)( track->z_height / dz ) + 0.5f );

	// compute fine axial region ID
	int fine_id = (int) ( track->z_height / dz ) % I.fai;

	// compute weight (azimuthal * polar)
	// NOTE: real app would also have volume weight component
	float weight = track->p_weight * az_weight;
	float mu2 = mu * mu;

	// load fine source region flux vector
	float * FSR_flux = QSR -> fine_flux[fine_id];

	if( fine_id == 0 )
	{
		// adjust z height to account for edge
		zin -= dz;

		// cycle over energy groups
		#ifdef INTEL
		#pragma simd
		#elif defined IBM
		#pragma simd_level(10)
		#endif
		for( int g = 0; g < I.n_egroups; g++)
		{
			// load neighboring sources
			float y1 = QSR->fine_source[fine_id][g];
			float y2 = QSR->fine_source[fine_id+1][g];
			float y3 = QSR->fine_source[fine_id+2][g];

			// do quadratic "fitting"
			float c0 = y2;
			float c1 = (y1 - y3) / (2.f*dz);
			float c2 = (y1 - 2.f*y2 + y3) / (2.f*dz*dz);
			
			// calculate q0, q1, q2
			q0[g] = c0 + c1*zin + c2*zin*zin;
			q1[g] = c1 + 2.f*c2*zin;
			q2[g] = c2;
		}
	}
	else if ( fine_id == I.fai - 1 )
	{
		// adjust z height to account for edge
		zin += dz;
		
		// cycle over energy groups
		#ifdef INTEL
		#pragma simd
		#elif defined IBM
		#pragma simd_level(10)
		#endif
		for( int g = 0; g < I.n_egroups; g++)
		{
			// load neighboring sources
			float y1 = QSR->fine_source[fine_id-2][g];
			float y2 = QSR->fine_source[fine_id-1][g];
			float y3 = QSR->fine_source[fine_id][g];

			// do quadratic "fitting"
			float c0 = y2;
			float c1 = (y1 - y3) / (2.f*dz);
			float c2 = (y1 - 2.f*y2 + y3) / (2.f*dz*dz);

			// calculate q0, q1, q2
			q0[g] = c0 + c1*zin + c2*zin*zin;
			q1[g] = c1 + 2.f*c2*zin;
			q2[g] = c2;
		}
	}
	else
	{
		// cycle over energy groups
		#ifdef INTEL
		#pragma simd
		#elif defined IBM
		#pragma simd_level(10)
		#endif
		for( int g = 0; g < I.n_egroups; g++)
		{
			// load neighboring sources
			float y1 = QSR->fine_source[fine_id-1][g];
			float y2 = QSR->fine_source[fine_id][g];
			float y3 = QSR->fine_source[fine_id+1][g];

			// do quadratic "fitting"
			float c0 = y2;
			float c1 = (y1 - y3) / (2.f*dz);
			float c2 = (y1 - 2.f*y2 + y3) / (2.f*dz*dz);

			// calculate q0, q1, q2
			q0[g] = c0 + c1*zin + c2*zin*zin;
			q1[g] = c1 + 2.f*c2*zin;
			q2[g] = c2;
		}
	}

	// cycle over energy groups
	#ifdef INTEL
	#pragma simd
	#elif defined IBM
	#pragma simd_level(10)
	#endif
	for( int g = 0; g < I.n_egroups; g++)
	{
		// load total cross section
		sigT[g] = QSR->sigT[g];

		// calculate common values for efficiency
		tau[g] = sigT[g] * ds;
		sigT2[g] = sigT[g] * sigT[g];
	}

	// cycle over energy groups
	#ifdef INTEL
	#pragma simd
	#elif defined IBM
	#pragma simd_level(10)
	#endif
	for( int g = 0; g < I.n_egroups; g++)
		expVal[g] = interpolateTable( params.expTable, tau[g] );  

	// Flux Integral

	// Re-used Term
	#ifdef INTEL
	#pragma simd
	#elif defined IBM
	#pragma simd_level(10)
	#endif
	for( int g = 0; g < I.n_egroups; g++)
	{
		reuse[g] = tau[g] * (tau[g] - 2.f) + 2.f * expVal[g] 
			/ (sigT[g] * sigT2[g]); 
	}


	float * psi;
	if(forward)
		psi = track->f_psi;
	else
		psi = track->b_psi;

	//#pragma vector nontemporal
	#ifdef INTEL
	#pragma simd
	#elif defined IBM
	#pragma simd_level(10)
	#endif
	for( int g = 0; g < I.n_egroups; g++)
	{
		// add contribution to new source flux
		flux_integral[g] = (q0[g] * tau[g] + (sigT[g] * psi[g] - q0[g])
			* expVal[g]) / sigT2[g] + q1[g] * mu * reuse[g] + q2[g] * mu2 
			* (tau[g] * (tau[g] * (tau[g] - 3.f) + 6.f) - 6.f * expVal[g]) 
			/ (3.f * sigT2[g] * sigT2[g]);
	}

	#ifdef INTEL
	#pragma simd
	#elif defined IBM
	#pragma simd_level(10)
	#endif
	for( int g = 0; g < I.n_egroups; g++)
	{
		// Prepare tally
		tally[g] = weight * flux_integral[g];
	}

	#ifdef OPENMP
	omp_set_lock(QSR->locks + fine_id);
	#endif

	#ifdef INTEL
	#pragma simd
	#elif defined IBM
	#pragma simd_level(10)
	#endif
	for( int g = 0; g < I.n_egroups; g++)
	{
		FSR_flux[g] += tally[g];
	}

	#ifdef OPENMP
	omp_unset_lock(QSR->locks + fine_id);
	#endif

	// Term 1
	#ifdef INTEL
	#pragma simd
	#elif defined IBM
	#pragma simd_level(10)
	#endif
	for( int g = 0; g < I.n_egroups; g++)
	{
		t1[g] = q0[g] * expVal[g] / sigT[g];  
	}
	// Term 2
	#ifdef INTEL
	#pragma simd
	#elif defined IBM
	#pragma simd_level(10)
	#endif
	for( int g = 0; g < I.n_egroups; g++)
	{
		t2[g] = q1[g] * mu * (tau[g] - expVal[g]) / sigT2[g]; 
	}
	// Term 3
	#ifdef INTEL
	#pragma simd
	#elif defined IBM
	#pragma simd_level(10)
	#endif
	for( int g = 0; g < I.n_egroups; g++)
	{
		t3[g] =	q2[g] * mu2 * reuse[g];
	}
	// Term 4
	#ifdef INTEL
	#pragma simd
	#elif defined IBM
	#pragma simd_level(10)
	#endif
	for( int g = 0; g < I.n_egroups; g++)
	{
		t4[g] = psi[g] * (1.f - expVal[g]);
	}
	// Total psi
	#ifdef INTEL
	#pragma simd
	#elif defined IBM
	#pragma simd_level(10)
	#endif
	for( int g = 0; g < I.n_egroups; g++)
	{
		psi[g] = t1[g] + t2[g] + t3[g] + t4[g];
	}
}	

// single direction transport sweep
void transport_sweep( Params * params, Input * I )
{
	if(I->mype==0) printf("Starting transport sweep ...\n");

	// calculate the height of a node's domain and of each FSR
	double node_delta_z = I->height / I->decomp_assemblies_ax;
	double fine_delta_z = node_delta_z / (I->cai * I->fai);

	/* loop over tracks (implicitly azimuthal angles, tracks in azimuthal 
	 * angles, polar angles, and z stacked rays) */

	//print_Input_struct( I );
	long segments_processed = 0;

	#pragma omp parallel default(none) \
	shared( I, params, node_delta_z, fine_delta_z ) \
	reduction(+ : segments_processed )
	{
		#ifdef OPENMP
		int thread = omp_get_thread_num();
		int nthreads = omp_get_num_threads();
		unsigned int seed = time(NULL) * (thread+1);
		#endif
		//print_Input_struct( I );

		#ifdef PAPI
		int eventset = PAPI_NULL;
		int num_papi_events;
		#pragma omp critical
		{
			counter_init(&eventset, &num_papi_events, I);
		}
		#endif

		AttenuateVars A;
		float * ptr = (float * ) malloc( I->n_egroups * 14 * sizeof(float));
		A.q0 = ptr;
		ptr += I->n_egroups;
		A.q1 = ptr;
		ptr += I->n_egroups;
		A.q2 = ptr;
		ptr += I->n_egroups;
		A.sigT = ptr;
		ptr += I->n_egroups;
		A.tau = ptr;
		ptr += I->n_egroups;
		A.sigT2 = ptr;
		ptr += I->n_egroups;
		A.expVal = ptr;
		ptr += I->n_egroups;
		A.reuse = ptr;
		ptr += I->n_egroups;
		A.flux_integral = ptr;
		ptr += I->n_egroups;
		A.tally = ptr;
		ptr += I->n_egroups;
		A.t1 = ptr;
		ptr += I->n_egroups;
		A.t2 = ptr;
		ptr += I->n_egroups;
		A.t3 = ptr;
		ptr += I->n_egroups;
		A.t4 = ptr;

		#pragma omp for schedule( dynamic ) 
		for (long i = 0; i < I->ntracks_2D; i++)
		{
			#if TIMING_INFO | 0
				// print progress
				#ifdef OPENMP
				if(I->mype==0 && thread == 0)
				{
					printf("\rAttenuating Tracks... (%.0lf%% completed)",
							(i / ( (double)I->ntracks_2D / (double) nthreads ))
							/ (double) nthreads * 100.0);
				}
				#else
				if( i % 50 == 0)
					if(I->mype==0)
						printf("%s%ld%s%ld\n","2D Tracks Completed = ", i," / ", 
								I->ntracks_2D );
				#endif
			#endif


			// treat positive-z traveling rays first
			bool pos_z_dir = true;
			for( int j = 0; j < I->n_polar_angles; j++)
			{
				if( j == I->n_polar_angles / 2 )
					pos_z_dir = false;
				float p_angle = params->polar_angles[j];
				float mu = cos(p_angle);

				// start with all z stacked rays
				int begin_stacked = 0;
				int end_stacked = I->z_stacked;

				for( int n = 0; n < params->tracks_2D[i].n_segments; n++)
				{
					// calculate distance traveled in cell if segment completed
					float s_full = params->tracks_2D[i].segments[n].length 
						/ sin(p_angle);

					// allocate varaible for distance traveled in an FSR
					float ds = 0;

					// loop over remaining z-stacked rays
					for( int k = begin_stacked; k < end_stacked; k++)
					{
						// initialize s to full length
						float s = s_full;

						// select current track
						Track * track = &params->tracks[i][j][k];

						// set flag for completeion of segment
						bool seg_complete = false;

						// calculate interval
						int curr_interval;
						if( pos_z_dir)
							curr_interval = get_pos_interval(track->z_height, 
									fine_delta_z);
						else
							curr_interval = get_neg_interval(track->z_height, 
									fine_delta_z);

						while( !seg_complete )
						{
							// flag to reset z position
							bool reset = false;


							/* calculate new height based on s 
							 * (distance traveled in FSR) */
							float z = track->z_height + s * cos(p_angle);

							// check if still in same FSR (fine axial interval)
							int new_interval;
							if( pos_z_dir )
								new_interval = get_pos_interval(z, 
										fine_delta_z);
							else
								new_interval = get_neg_interval(z,
										fine_delta_z);

							if( new_interval == curr_interval )
							{
								seg_complete = true;
								ds = s;
							}

							// otherwise, we need to recalculate distances
							else
							{
								// correct z
								if( pos_z_dir )
								{
									curr_interval++;
									z = fine_delta_z * (float) curr_interval;
								}
								else{
									curr_interval--;
									z = fine_delta_z * (float) curr_interval;
								}

								// calculate distance travelled in FSR (ds)
								ds = (z - track->z_height) / cos(p_angle);

								// update track length remaining
								s -= ds;

								/* check remaining track length to protect
								 * against potential roundoff errors */
								if( s <= 0 )
									seg_complete = true;

								// check if out of bounds or track complete
								if( z <= 0 || z >= node_delta_z )
								{
									// mark segment as completed
									seg_complete = true;

									// remember to no longer treat this track
									if ( pos_z_dir )
										end_stacked--;
									else
										begin_stacked++;

									// reset z height
									reset = true;
								}
							}

							// pick a random FSR (cache miss expected)
							#ifdef OPENMP
							long QSR_id = rand_r(&seed) % 
								I->n_source_regions_per_node;
							#else
							long QSR_id = rand() % 
								I->n_source_regions_per_node;
							#endif

							/* update sources and fluxes from attenuation 
							 * over FSR */
							if( I->axial_exp == 2 )
							{
								attenuate_fluxes( track, true, 
										&params->sources[QSR_id], 
										I, params, ds, mu, 
										params->tracks_2D[i].az_weight, &A );

								segments_processed++;
							}

							else if( I->axial_exp == 0 )
							{
								attenuate_FSR_fluxes( track, true,
										&params->sources[QSR_id],
										I, params, ds, mu,
										params->tracks_2D[i].az_weight, &A );

								segments_processed++;
							}
							else
							{
								printf("Error: invalid axial expansion order");
								printf("\n Please input 0 or 2\n");
								exit(1);
							}

							// update with new z height or reset if finished
							if( n == params->tracks_2D[i].n_segments - 1  
									|| reset)
							{
								if( pos_z_dir)
									track->z_height = I->axial_z_sep * k;
								else
									track->z_height = I->axial_z_sep * (k+1);
							}
							else
								track->z_height = z;

						}
					}
				}
			}
		}
		#ifdef OPENMP
		if(thread == 0 && I->mype==0) printf("\n");
		#endif

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
		counter_stop(&eventset, num_papi_events, I);
		#endif
	}
	I->segments_processed = segments_processed;

	return;
}


// run one full transport sweep, return k
void two_way_transport_sweep( Params * params, Input * I )
{
	if(I->mype==0) printf("Starting transport sweep ...\n");

	// calculate the height of a node's domain and of each FSR
	double node_delta_z = I->height / I->decomp_assemblies_ax;
	int num_intervals = (I->cai * I->fai);
	double fine_delta_z = node_delta_z / num_intervals;

	/* loop over tracks (implicitly azimuthal angles, tracks in azimuthal 
	 * angles, polar angles, and z stacked rays) */
		long segments_processed = 0;

	#pragma omp parallel default(none) \
	shared( I, params, node_delta_z, fine_delta_z, num_intervals ) \
	reduction(+ : segments_processed )
	{
		#ifdef OPENMP
		int thread = omp_get_thread_num();
		int nthreads = omp_get_num_threads();
		unsigned int seed = time(NULL) * (thread+1);
		#endif
		//print_Input_struct( I );

		#ifdef PAPI
		int eventset = PAPI_NULL;
		int num_papi_events;
		#pragma omp critical
		{
			counter_init(&eventset, &num_papi_events, I);
		}
		#endif


		AttenuateVars A;
		float * ptr = (float * ) malloc( I->n_egroups * 14 * sizeof(float));
		A.q0 = ptr;
		ptr += I->n_egroups;
		A.q1 = ptr;
		ptr += I->n_egroups;
		A.q2 = ptr;
		ptr += I->n_egroups;
		A.sigT = ptr;
		ptr += I->n_egroups;
		A.tau = ptr;
		ptr += I->n_egroups;
		A.sigT2 = ptr;
		ptr += I->n_egroups;
		A.expVal = ptr;
		ptr += I->n_egroups;
		A.reuse = ptr;
		ptr += I->n_egroups;
		A.flux_integral = ptr;
		ptr += I->n_egroups;
		A.tally = ptr;
		ptr += I->n_egroups;
		A.t1 = ptr;
		ptr += I->n_egroups;
		A.t2 = ptr;
		ptr += I->n_egroups;
		A.t3 = ptr;
		ptr += I->n_egroups;
		A.t4 = ptr;

		#pragma omp for schedule( dynamic ) 
		for (long i = 0; i < I->ntracks_2D; i++)
		{
			// print progress
			#ifdef OPENMP
			if(I->mype==0 && thread == 0)
			{
				printf("\rAttenuating Tracks... (%.0lf%% completed)",
						(i / ( (double)I->ntracks_2D / (double) nthreads ))
						/ (double) nthreads * 100.0);
			}
			#else
			if( i % 50 == 0)
				if(I->mype==0)
					printf("%s%ld%s%ld\n","2D Tracks Completed = ", i," / ", 
							I->ntracks_2D );
			#endif

			// allocate arrays for segment storage FIXME
			double ** seg_dist = malloc( I->z_stacked * sizeof(double *) );
			Source *** seg_src = malloc( I->z_stacked * sizeof(Source**) );
			int * seg_idx = malloc( I->z_stacked * sizeof(int) );
			int * seg_size = malloc( I->z_stacked * sizeof(int) );

			// fill matrix with arrays FIXME
			for( int k = 0; k < I->z_stacked; k++)
			{
				seg_size[k] = 2 * I->segments_per_track;
				seg_dist[k] = malloc( seg_size[k] * sizeof(double) );
				seg_src[k] = malloc( seg_size[k] * sizeof(Source *) );
				seg_idx[k] = 0;
			}

			// treat positive-z traveling rays first
			bool pos_z_dir = true;
			for( int j = 0; j < I->n_polar_angles; j++)
			{
				if( j == I->n_polar_angles / 2 )
					pos_z_dir = false;
				float p_angle = params->polar_angles[j];
				float mu = cos(p_angle);

				// start with all z stacked rays
				int begin_stacked = 0;
				int end_stacked = I->z_stacked;

				// reset semgnet indexes
				for( int k = 0; k < I->z_stacked; k++)
					seg_idx[k] = 0;

				for( int n = 0; n < params->tracks_2D[i].n_segments; n++)
				{
					// calculate distance traveled in cell if segment completed
					float s_full = params->tracks_2D[i].segments[n].length 
						/ sin(p_angle);

					// allocate varaible for distance traveled in an FSR
					float ds = 0;

					// loop over remaining z-stacked rays
					int tracks_completed = 0;
					for( int k = begin_stacked; k < end_stacked; k++)
					{
						// select current track
						Track * track = &params->tracks[i][j][k];

						// determine current axial interval
						int interval = (int) track->z_height / fine_delta_z;

						// calculate distance to domain boundary
						float bound_dist;
						if( pos_z_dir)
							bound_dist = (node_delta_z - track->z_height) / mu;
						else
							bound_dist = -track->z_height / mu;

						// determine track length
						float s;
						if(	s_full < bound_dist )
							s = s_full;
						else
						{
							// note completion of track
							s = bound_dist;
							tracks_completed++;
						}

						// set flag for completeion of segment
						bool seg_complete = false;

						while( !seg_complete )
						{
							// initialize tracking variables
							long QSR_id = interval + num_intervals * n;
							float ds;
							float z;

							// calculate z height of next fine axial interval
							float fai_z_height;
							if( pos_z_dir )
								fai_z_height = (interval + 1) * fine_delta_z ;
							else
								fai_z_height = interval * fine_delta_z;

							// calculate z distance to next fine axial interval
							float z_dist_to_fai = 
								fai_z_height - track->z_height;

							/* calculate total distance (s) to fine axial 
							 * interval */
							float s_dist_to_fai = z_dist_to_fai / mu;

							// determine if a fine axial interval is crossed
							if( s_dist_to_fai < s )
							{
								if( pos_z_dir )
									interval++;
								else
									interval--;
								ds = s_dist_to_fai;
								z = track->z_height + z_dist_to_fai;
							}
							else
							{
								ds = s;
								z = track->z_height + s * mu;
							}	

							/* shorten remaining segment length and check if
							 * completed (accounting for potential roundoff) */
							s -= ds;
							if( s <= 0 || interval < 0 
									|| interval >= num_intervals)
								seg_complete = true;

							// pick a random FSR (cache miss expected)
							#ifdef OPENMP
							QSR_id = rand_r(&seed) % 
								I->n_source_regions_per_node;
							#else
							QSR_id = rand() % I->n_source_regions_per_node;
							#endif

							/* update sources and fluxes from attenuation 
							 * over FSR */
							if( I->axial_exp == 2 )
							{
								attenuate_fluxes( track, true,
										&params->sources[QSR_id], 
										I, params, ds, mu, 
										params->tracks_2D[i].az_weight, &A );
								segments_processed++;
							}

							else if( I->axial_exp == 0 )
								attenuate_FSR_fluxes( track, true,
										&params->sources[QSR_id],
										I, params, ds, mu,
										params->tracks_2D[i].az_weight, &A );
							else
							{
								printf("Error: invalid axial expansion order");
								printf("\n Please input 0 or 2\n");
								exit(1);
							}

							// update track height
							track->z_height = z;
							
							// save segment length and source FIXME
							seg_dist[k][seg_idx[k]] = ds;
							seg_src[k][seg_idx[k]] = &params->sources[QSR_id];
							seg_idx[k]++;

							// check if array needs to grow FIXME
							if( seg_idx[k] >= seg_size[k] )
							{
								seg_size[k] *= 2;
								seg_dist[k] = (double *) realloc( seg_dist[k],
										seg_size[k] * sizeof(double) );
								seg_src[k] = (Source **) realloc( seg_src[k],
										seg_size[k] * sizeof(Source *) );
							}
						}
					}
					if(pos_z_dir)
						end_stacked -= tracks_completed;
					else
						begin_stacked += tracks_completed;
				}

				// loop over all z stacked rays again
				for( int k = 0; k < I->z_stacked; k++ )
				{
					for( int n = seg_idx[k]-1; n >= 0; n--)
					{
						// load distance
						float ds = seg_dist[k][n];

						// select current track
						Track * track = &params->tracks[i][j][k];

						// update sources and fluxes from attenuation over FSR
						if( I->axial_exp == 2 )
						{
							attenuate_fluxes( track, false,
									seg_src[k][n], 
									I, params, ds, -mu, 
									params->tracks_2D[i].az_weight, &A );
								segments_processed++;
						}

						else if( I->axial_exp == 0 )
							attenuate_FSR_fluxes( track, false,
									seg_src[k][n],
									I, params, ds, -mu,
									params->tracks_2D[i].az_weight, &A );

						// update z height
						track->z_height -= ds * mu;
					}
				}


				/* Update all tracks with correct starting z location again
				 * NOTE: this is only here to acocunt for roundoff error */
				for( int k = 0; k < I->z_stacked; k++)
				{
					Track * track = &params->tracks[i][j][k];
					if( pos_z_dir)
						track->z_height = I->axial_z_sep * k;
					else
						track->z_height = I->axial_z_sep * (k+1);
				}
			}

			// free memory
			for( int k = 0; k < I->z_stacked; k++)
			{
				free(seg_dist[k]);
				free(seg_src[k]);
			}
			free(seg_dist);
			free(seg_src);
			free(seg_idx);
			free(seg_size);

		}
		#ifdef OPENMP
		if(thread == 0 && I->mype==0) printf("\n");
		#endif

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
		counter_stop(&eventset, num_papi_events, I);
		#endif
	}
	//printf("Number of segments processed: %ld\n", segments_processed);
	I->segments_processed = segments_processed;

	return;
}

/* returns integer number for axial interval for tracks traveling in the
 *  positive direction */
int get_pos_interval( float z, float dz)
{
	int interval = (int) (z/dz);
	return interval;
}

/* returns integer number for axial interval for tracks traveling in the 
 * negative direction */
int get_neg_interval( float z, float dz)
{
	// NOTE: a bit of trickery using floors to obtain ceils 
	int interval = INT_MAX - (int) ( (double) INT_MAX 
			- (double) ( z / dz ) );
	return interval;
}

int calc_next_fai( float z, float dz, bool pos_dir)
{
	int interval = z/dz;
	float lower_z = dz * (float) interval;
	if(pos_dir)
		return interval + 1;
	else
		return interval;
}

/* Determines the change in angular flux along a particular track across a fine
 * axial region and tallies the contribution to the scalar flux in the fine 
 * axial region. This function assumes a quadratic source, which is calculated 
 * on the fly using neighboring source values.
 *
 * This legacy function is unused since it is less efficient than the current 
 * attenuate_fluxes function. However, it provides a more straightforward 
 * description of the underlying physical problem. */
void alt_attenuate_fluxes( Track * track, bool forward, Source * QSR, Input * I,
		Params * params, float ds, float mu, float az_weight ) 
{
	// compute fine axial interval spacing
	float dz = I->height / (I->fai * I->decomp_assemblies_ax * I->cai);

	// compute z height in cell
	float zin = track->z_height - dz * ( (int)( track->z_height / dz ) + 0.5 );

	// compute fine axial region ID
	int fine_id = (int) ( track->z_height / dz ) % I->fai;

	// compute weight (azimuthal * polar)
	// NOTE: real app would also have volume weight component
	float weight = track->p_weight * az_weight;
	float mu2 = mu * mu;

	// load fine source region flux vector
	float * FSR_flux = QSR -> fine_flux[fine_id];

	// cycle over energy groups
	for( int g = 0; g < I->n_egroups; g++)
	{
		// load total cross section
		float sigT = QSR->sigT[g];

		// define source parameters
		float q0, q1, q2;

		// calculate source components
		if( fine_id == 0 )
		{
			// load neighboring sources
			float y2 = QSR->fine_source[fine_id][g];
			float y3 = QSR->fine_source[fine_id+1][g];

			// do linear "fitting"
			float c0 = y2;
			float c1 = (y3 - y2) / dz;

			// calculate q0, q1, q2
			q0 = c0 + c1*zin;
			q1 = c1;
			q2 = 0;
		}
		else if( fine_id == I->fai - 1 )
		{
			// load neighboring sources
			float y1 = QSR->fine_source[fine_id-1][g];
			float y2 = QSR->fine_source[fine_id][g];

			// do linear "fitting"
			float c0 = y2;
			float c1 = (y2 - y1) / dz;

			// calculate q0, q1, q2
			q0 = c0 + c1*zin;
			q1 = c1;
			q2 = 0;
		}		
		else
		{
			// load neighboring sources
			float y1 = QSR->fine_source[fine_id-1][g];
			float y2 = QSR->fine_source[fine_id][g];
			float y3 = QSR->fine_source[fine_id+1][g];

			// do quadratic "fitting"
			float c0 = y2;
			float c1 = (y1 - y3) / (2*dz);
			float c2 = (y1 - 2*y2 + y3) / (2*dz*dz);

			// calculate q0, q1, q2
			q0 = c0 + c1*zin + c2*zin*zin;
			q1 = c1 + 2*c2*zin;
			q2 = c2;
		}

		// calculate common values for efficiency
		float tau = sigT * ds;
		float sigT2 = sigT * sigT;

		// compute exponential ( 1 - exp(-x) ) using table lookup
		float expVal = interpolateTable( params->expTable, tau );  

		// load correct angular flux vector
		float * psi;
		if(forward)
			psi = track->f_psi;
		else
			psi = track->b_psi;

		// add contribution to new source flux
		float flux_integral = (q0 * tau + (sigT * psi[g] - q0) * expVal)
			/ sigT2
			+ q1 * mu * (tau * (tau - 2) + 2 * expVal)
			/ (sigT * sigT2)
			+ q2 * mu2 * (tau * (tau * (tau - 3) + 6) - 6 * expVal)
			/ (3 * sigT2 * sigT2);

		#pragma omp atomic
		FSR_flux[g] += weight * flux_integral;

		// update angular flux
		psi[g] = psi[g] * (1.0 - expVal) + q0 * expVal / sigT
			+ q1 * mu * (tau - expVal) / sigT2 + q2 * mu2 *
			(tau * (tau - 2) + 2 * expVal) / (sigT2 * sigT);
	}
}

/* Determines the change in angular flux along a particular track across a fine
 * axial region and tallies the contribution to the scalar flux in the fine 
 * axial region. This function assumes a constant  source. */ 
void attenuate_FSR_fluxes( Track * track, bool forward, Source * FSR, Input * I,
		Params * params_in, float ds, float mu, float az_weight, 
		AttenuateVars *A)
{
	// upack attenuate vars struct
	float *  restrict tally = A->tally;
	float *  restrict expVal = A->expVal;
	float *  restrict sigT = A->sigT;
	float *  restrict tau = A->tau;

	Params params = * params_in;

	// compute fine axial interval spacing
	float dz = I->height / (I->fai * I->decomp_assemblies_ax * I->cai);

	// compute z height in cell
	float zin = track->z_height - dz * 
		( (int)( track->z_height / dz ) + 0.5f );

	// compute fine axial region ID
	int fine_id = (int) ( track->z_height / dz ) % I->fai;

	// compute weight (azimuthal * polar)
	// NOTE: real app would also have volume weight component
	float weight = track->p_weight * az_weight * mu;

	// load fine source region flux vector
	float * FSR_flux = FSR -> fine_flux[fine_id];

	// cycle over energy groups
	#ifdef INTEL
	#pragma simd
	#elif defined IBM
	#pragma simd_level(10)
	#endif
	for( int g = 0; g < I->n_egroups; g++)
	{
		// load total cross section
		sigT[g] = FSR->sigT[g];
		tau[g] = sigT[g] * ds;
	}

	// compute exponential ( 1 - exp(-x) ) using table lookup
	#ifdef INTEL
	#pragma simd
	#elif defined IBM
	#pragma simd_level(10)
	#endif
	for(int g = 0; g < I->n_egroups; g++)
	{
		expVal[g] = interpolateTable( params.expTable, tau[g] );
	}

	float * psi;
	if(forward)
		psi = track->f_psi;
	else
		psi = track->b_psi;

	#ifdef INTEL
	#pragma simd
	#elif defined IBM
	#pragma simd_level(10)
	#endif
	for( int g = 0; g < I->n_egroups; g++)
	{
		// compute angular flux attenuation
		float q = FSR->fine_source[fine_id][g] / sigT[g];
		float delta_psi = (psi[g] - q) * expVal[g];

		// add contribution to new source flux
		tally[g] = weight * delta_psi;

		// update angular flux
		psi[g] -= delta_psi;
	}



	#ifdef OPENMP
	omp_set_lock(&FSR->locks[fine_id]);
	#endif

	#ifdef INTEL
	#pragma simd
	#elif defined IBM
	#pragma simd_level(10)
	#endif
	for( int g = 0; g < I->n_egroups; g++)
	{
		FSR_flux[g] += tally[g];
	}

	#ifdef OPENMP
	omp_unset_lock(&FSR->locks[fine_id]);
	#endif


}

/* Renormalizes scalar and angular flux for next transport sweep iteration.
 * Calculation requires multiple pair-wise sums and a reduction accross all 
 * nodes. */
void renormalize_flux( Params params, Input I, CommGrid grid )
{
	if( I.mype == 0 ) printf("Renormalizing Flux...\n");
	float node_fission_rate = 0;
	#ifdef OPENMP
	#pragma omp parallel default(none) shared(params, I, grid) \
	reduction(+ : node_fission_rate)
	{
	#endif
		// tally total fission rate (pair-wise sum)
		float * fission_rates = malloc( I.n_source_regions_per_node 
				* sizeof(float) );

		float * fine_fission_rates = malloc( I.fai * sizeof(float) );
		float * g_fission_rates = malloc( I.n_egroups * sizeof(float) );

		// accumulate total fission rate on node domain
		#pragma omp for schedule(dynamic)
		for( int i = 0; i < I.n_source_regions_per_node; i++)
		{
			Source src = params.sources[i];
			for( int j = 0; j < I.fai; j++)
			{
				for( int g = 0; g < I.n_egroups; g++)
					g_fission_rates[g] = src.fine_flux[j][g] * src.vol 
						* src.XS[g][0];
				fine_fission_rates[j] = pairwise_sum( g_fission_rates, 
						I.n_egroups );
			}
			fission_rates[i] = pairwise_sum( fine_fission_rates, I.fai );
		}
		node_fission_rate = pairwise_sum(fission_rates, 
				I.n_source_regions_per_node);
		
		// free allocated memory
		free(fission_rates);
		free(fine_fission_rates);
		free(g_fission_rates);
	
	#ifdef OPENMP
	}
	#endif

	#ifdef MPI	
	// accumulate total fission rate by MPI Allreduce
	float total_fission_rate = 0;
	MPI_Barrier(grid.cart_comm_3d);
	MPI_Allreduce( &node_fission_rate, // Send Buffer
			&total_fission_rate,    // Receive Buffer
			1,                    	// Element Count
			MPI_FLOAT,           	// Element Type
			MPI_SUM,              	// Reduciton Operation Type
			grid.cart_comm_3d );  	// MPI Communicator
	MPI_Barrier(grid.cart_comm_3d);
	#else
	float total_fission_rate = node_fission_rate;
	#endif


	// normalize fluxes by fission reaction rate
	float norm_factor = 1.0 / total_fission_rate;

	#pragma omp parallel for default(none) \
	shared(I, params) private(norm_factor) schedule(dynamic)
	for( int i = 0; i < I.n_source_regions_per_node; i++)
	{
		Source * src = &params.sources[i];
		float adjust = norm_factor * 4 * M_PI * I.fai / src->vol;
		for( int k = 0; k < I.fai; k++)
			for( int g = 0; g < I.n_egroups; g++)
				src->fine_flux[k][g] *= adjust;
	}

	// normalize boundary fluxes by same factor
	#pragma omp parallel for default(none) \
	shared(I, params) private(norm_factor) schedule(dynamic)
	for( long i = 0; i < I.ntracks_2D; i++)
		for( int j = 0; j < I.n_polar_angles; j++)
			for( int k = 0; k < I.z_stacked; k++)
				for( int g = 0; g < I.n_egroups; g++)
				{
					params.tracks[i][j][k].f_psi[g] *= norm_factor;
					params.tracks[i][j][k].b_psi[g] *= norm_factor;
				}

	if( I.mype == 0 ) printf("Renormalizing Flux Complete.\n");
	return;
}

/* Updates sources for next iteration by computing scattering and fission
 * components. Calculation includes multiple pair-wise sums and reductions
 * accross all nodes */
float update_sources( Params params, Input I, float keff )
{
	// source residual
	float residual;

	// calculate inverse multiplication facotr for efficiency
	float inverse_k = 1.0 / keff;

	// allocate residual arrays
	float * group_res = (float *) malloc(I.n_egroups * sizeof(float));
	float * fine_res = (float *) malloc(I.fai * sizeof(float));
	float * residuals = (float *) malloc(I.n_source_regions_per_node 
			* sizeof(float));

	// allocate arrays for summation
	float * fission_rates = malloc(I.n_egroups * sizeof(float));
	float * scatter_rates = malloc(I.n_egroups * sizeof(float));

	// cycle through all coarse axial intervals to update source
	for( long i = 0; i < I.n_source_regions_per_node; i++)
	{
		Source src = params.sources[i];

		// cycle thorugh all fine axial regions to calculate new source
		for( int j = 0; j < I.fai; j++)
		{
			// calculate total fission source and scattering source
			float fission_source;
			float scatter_source;

			// compute total fission source
			for( int g = 0; g < I.n_egroups; g++ )
				fission_rates[g] = src.fine_flux[j][g] * src.XS[g][0];
			fission_source = pairwise_sum( fission_rates, (long) I.n_egroups);

			// normalize fission source by multiplication factor
			fission_source *= inverse_k;

			// compute scattering and new total source for each group
			for( int g = 0; g < I.n_egroups; g++ )
			{
				for( int g2 = 0; g2 < I.n_egroups; g2++ )
				{
					// compute scatter source originating from g2 -> g
					scatter_rates[g2] = src.scattering_matrix[g][g2] * 
						src.fine_flux[j][g2];
				}
				scatter_source = pairwise_sum(scatter_rates, 
						(long) I.n_egroups);

				// compuate new total source
				float chi = src.XS[g][2];

				// calculate new fine source
				float newSrc = (fission_source * chi + scatter_source) 
					/ (4.0 * M_PI);

				// calculate residual
				float oldSrc = src.fine_source[j][g];
				group_res[g] = (newSrc - oldSrc) * (newSrc - oldSrc)
					/ (oldSrc * oldSrc);

				/* calculate new source in fine axial interval assuming 
				 * isotropic source components */
				src.fine_source[j][g] = newSrc;
			}
			fine_res[j] = pairwise_sum(group_res, (long) I.n_egroups);
		}
		residuals[i] = pairwise_sum(fine_res, (long) I.fai);
	}

	// calculate source residual
	residual = pairwise_sum(residuals, I.n_source_regions_per_node);

	// free memory
	free(fission_rates);
	free(scatter_rates);
	free(group_res);
	free(fine_res);
	free(residuals);


	// NOTE: See code around line 600 of CPUSolver.cpp in ClosedMOC/ OpenMOC

	return residual;
}

/* Computes globall k-effective using multiple pair-wise summations and finally
 * a reduction accross all nodes */
float compute_keff(Params params, Input I, CommGrid grid)
{
	// allocate temporary memory
	float * sigma = malloc( I.n_egroups * sizeof(float) );
	float * group_rates = malloc( I.n_egroups * sizeof(float) );
	float * fine_rates = malloc( I.fai * sizeof(float) );
	float * QSR_rates = malloc( I.n_source_regions_per_node * sizeof(float) );

	///////////////////////////////////////////////////////////////////////////

	// compute total absorption rate, looping over source regions
	for( long i = 0; i < I.n_source_regions_per_node; i++)
	{
		// load absorption XS data
		Source src = params.sources[i];
		for( int g = 0; g < I.n_egroups; g++)	
			sigma[g] = src.XS[g][1];

		for( int j = 0; j < I.fai; j++ )
		{
			// calculate absorption rates
			float * fine_flux = src.fine_flux[j];
			for( int g = 0; g < I.n_egroups; g++)
				group_rates[g] = sigma[g] * fine_flux[g];

			// sum absorption over all energy groups
			fine_rates[j] = pairwise_sum( group_rates, (long) I.n_egroups );
		}
		// sum absorption over all fine axial intervals
		QSR_rates[i] = pairwise_sum( fine_rates, (long) I.fai );
	}
	// sum absorption over all source regions in a node
	float node_abs = pairwise_sum( QSR_rates, I.n_source_regions_per_node);

	///////////////////////////////////////////////////////////////////////////

	// compute total absorption rate, looping over source regions
	for( long i = 0; i < I.n_source_regions_per_node; i++)
	{
		// load nuSigmaF XS data
		Source src = params.sources[i];
		for( int g = 0; g < I.n_egroups; g++)	
			sigma[g] = src.XS[g][0];

		for( int j = 0; j < I.fai; j++ )
		{
			// calculate absorption rates
			float * fine_flux = src.fine_flux[j];
			for( int g = 0; g < I.n_egroups; g++)
				group_rates[g] = sigma[g] * fine_flux[g];

			// sum fission over all energy groups
			fine_rates[j] = pairwise_sum( group_rates, (long) I.n_egroups );
		}
		// sum fission over all fine axial intervals
		QSR_rates[i] = pairwise_sum( fine_rates, (long) I.fai );
	}
	// sum fission over all source regions in a node
	float node_fission = pairwise_sum( QSR_rates, I.n_source_regions_per_node);

	///////////////////////////////////////////////////////////////////////////

	// MPi Reduction
	float tot_abs = 0;
	float tot_fission = 0;
	float leakage = 0;

	#ifdef MPI 

	// Total Absorption Reduction
	MPI_Reduce( &node_abs,    		// Send Buffer
			&tot_abs,      			// Receive Buffer
			1,                  	// Element Count
			MPI_FLOAT,          	// Element Type
			MPI_SUM,            	// Reduciton Operation Type
			0,                  	// Master Rank
			grid.cart_comm_3d );	// MPI Communicator

	// Total Fission Reduction
	MPI_Reduce( &node_fission,     	// Send Buffer
			&tot_fission,  			// Receive Buffer
			1,                    	// Element Count
			MPI_FLOAT,           	// Element Type
			MPI_SUM,              	// Reduciton Operation Type
			0,                    	// Master Rank
			grid.cart_comm_3d );  	// MPI Communicator

	// Total Leakage Reduction
	MPI_Reduce( params.leakage,  	// Send Buffer
			&leakage,      			// Receive Buffer
			1,                    	// Element Count
			MPI_FLOAT,           	// Element Type
			MPI_SUM,              	// Reduciton Operation Type
			0,                    	// Master Rank
			grid.cart_comm_3d );  	// MPI Communicator

	MPI_Barrier(grid.cart_comm_3d);

	// calculate keff
	float keff = tot_fission/ (tot_abs + leakage);
	#else
	float keff = node_fission / (node_abs + *params.leakage);
	#endif

	///////////////////////////////////////////////////////////////////////////

	// free memory
	free(sigma);
	free(group_rates);
	free(fine_rates);
	free(QSR_rates);

	return keff;
}

/* Interpolates a formed exponential table to compute ( 1- exp(-x) )
 *  at the desired x value */
float interpolateTable( Table table, float x)
{
	// check to ensure value is in domain
	if( x > table.maxVal )
		return 1.0f;
	else
	{
		int interval = (int) ( x / table.dx + 0.5f * table.dx );
		/*
		   if( interval >= table.N || interval < 0)
		   {
		   printf( "Interval = %d\n", interval);
		   printf( "N = %d\n", table.N);
		   printf( "x = %f\n", x);
		   printf( "dx = %f\n", table.dx);
		   exit(1);
		   }
		   */
		float slope = table.values[ 2 * interval ];
		float intercept = table.values[ 2 * interval + 1 ];
		float val = slope * x + intercept;
		return val;
	}
}

