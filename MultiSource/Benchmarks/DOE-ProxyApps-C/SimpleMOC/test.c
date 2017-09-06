#include"SimpleMOC_header.h"

// prints input parameters to screen
void print_Input_struct( Input I )
{
	printf("INPUT STRUCT\n");
	printf("%d\n", I.x_assemblies);    		/* Number of assemblies in the 
												x-axis of the reactor */
	printf("%d\n", I.y_assemblies);       	/* Number of assemblies in the 
												y-axis of the reactor */
	printf("%d\n", I.cai);                 	// Number of course axial intervals
	printf("%d\n", I.fai);                 	/* Number of fine axial intervals 
											   per coarse axial interval */
	printf("%d\n", I.axial_exp);          	// Axial source expansion order
	printf("%lf\n", I.radial_ray_sep);    	// Radial ray separation
	printf("%lf\n", I.axial_z_sep);       	// Axial stacked z-ray separation
	printf("%d\n", I.n_azimuthal);         	// Number of azimuthal angles
	printf("%d\n", I.n_polar_angles);      	// Number of polar angles
	printf("%d\n", I.n_egroups);           	// Number of energy groups
	printf("%d\n", I.decomp_assemblies_ax);	/* Number of assemblies per 
												sub-domain (axially) */
	printf("%ld\n", I.segments_per_track); 	/* Average number of segments per 
												track */
	printf("%lf\n", I.assembly_width);    	// Width of an assembly
	printf("%lf\n", I.height);            	// Height of the reactor
	printf("%lf\n", I.domain_height);     	// Z Height of a domain
	printf("%lf\n", I.precision);		  	// precision for source convergence
	printf("%ld\n", I.mype);               	// MPI Rank
	printf("%ld\n", I.ntracks_2D);        	// Number of 2D tracks (derived)
	printf("%d\n", I.z_stacked);          	// Number of z rays (derived)
	printf("%ld\n", I.ntracks);           	/* Total number of 3D tracks per 
											   assembly (derived) */
	printf("%d\n", I.nthreads);           	// Number of OpenMP Threads
	printf("%d\n", I.papi_event_set);     	/* PAPI event set:
												0 - FLOPS   
												1 - Bandwidth   
												2 - CPU Stall reason
											*/
	
	// Source regions per assembly
	printf("%ld\n", I.n_2D_source_regions_per_assembly);

	// Source regions per node (derived)	
	printf("%ld\n", I.n_source_regions_per_node); 
	printf("END INPUT STRUCT\n");
	
}

// generates normally distributed random numbers
void gen_norm_pts(float mean, float sigma, int n_pts)
{
	// generate output file
	FILE * out;
	out = fopen("gen_points.txt","w");
	fprintf(out, "Random numbers generated for a normal distribution\n");
	fprintf(out, "Mean = %f\n", mean);
	fprintf(out, "Standard deviation = %f\n", sigma);
	fprintf(out, "Generated points:\n");

	// generate gaussian random points
	for(int i = 0; i < n_pts; i++)
	{
		float random = nrand(mean,sigma);	
		fprintf(out, "%f\n", random);
	}

	// close stream
	fclose(out);

	return;
}
