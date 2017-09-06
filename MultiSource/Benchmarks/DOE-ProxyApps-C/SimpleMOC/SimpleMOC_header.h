#ifndef __SimpleMOC_header
#define __SimpleMOC_header

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>
#include<limits.h>
#include<assert.h>
#include<pthread.h>
#include<unistd.h>

#ifdef MPI
#include<mpi.h>
#endif

#ifdef OPENMP
#include<omp.h>
#endif

#ifdef PAPI
#include<papi.h>
#endif

#define TIMIING_INFO 0

#include "glibc_compat_rand.h"
#ifndef NO_GLIBC_COMPAT_RAND
#define rand glibc_compat_rand
#define srand glibc_compat_srand
#endif

// User inputs
typedef struct{
	int x_assemblies;          	/* Number of assemblies in the x-axis of the 
								   reactor */
	int y_assemblies;           /* Number of assemblies in the y-axis of the 
								   reactor */
	int cai;                    // Number of course axial intervals
	int fai;                    /* Number of fine axial intervals per coarse 
								   axial interval */
	int axial_exp;             	// Axial source expansion order
	float radial_ray_sep;     	// Radial ray separation
	float axial_z_sep;        	// Axial stacked z-ray separation
	int n_azimuthal;           	// Number of azimuthal angles
	int n_polar_angles;        	// Number of polar angles
	int n_egroups;             	// Number of energy groups
	bool decompose;            	// Turn decomposition on/off
	int decomp_assemblies_ax;  	// Number of sub-domains per assembly (axially)
	long segments_per_track;   	// Average number of segments per track
	float assembly_width;     	// Width of an assembly - 1.26 x 17 cm
	float height;             	// Height of the reactor - 400 cm
	float domain_height;      	// Z Height of a domain
	float precision;		   	// precision for source convergence
	long mype;                 	// MPI Rank
	long ntracks_2D;           	// Number of 2D tracks (derived)
	int z_stacked;             	// Number of z rays (derived)
	long ntracks;              	/* Total number of 3D tracks per assembly
								   (derived) */
	int nthreads;              	// Number of OpenMP Threads
	int papi_event_set;         // PAPI event set
	// 0 - FLOPS   1 - Bandwidth   2 - CPU Stall reason
	
	// Source regions per assembly (3M estimate)
	long n_2D_source_regions_per_assembly;

	// Source regions per node (derived)	
	long n_source_regions_per_node; 

    #ifdef PAPI
    // String for command line PAPI event
    char event_name[PAPI_MAX_STR_LEN]; 
    // Array to accumulate PAPI counts across all threads
    long long *vals_accum;
    #endif

	bool load_tracks;		// Turn on/off loading 2D tracks from file
	char* track_file;		// Name/address of tracking file to load

	long segments_processed;    // Total number of segments processed per node

} Input;

// Localized geometrical region ID
typedef struct{
	long assembly;             // Assembly ID
	long pin;                  // Pin Cell ID
	long zone;                 // Zone (inside pin cell) ID
} RegionID;

// Segment Structure
typedef struct{
	float length;
	long source_id;
} Segment;

// Track2D Structure
typedef struct{
	float az_weight;          	// Azimuthal Quadrature Weight (rand)
	long n_segments;           	// Number of Segments (gaussian)
	Segment * segments;        	// Array of Segments
	int n_3D_segments;			// Number of intersections in 3D tracks
} Track2D;

// Track Structure
typedef struct{
	float p_weight;				// Polar Quadrature Weight     (rand)
	float z_height;           	// Z-height
	long rank_in;              	// MPI rank to receive from
	long rank_out;             	// MPI rank to send to
	float * f_psi;			   	// Forward angular flux along track
	float * b_psi;				// Backward angular flux along track
} Track;

// Source Region Structure
typedef struct{
	float ** fine_flux;
	float ** fine_source;
	float vol;
	float * sigT;
	float ** XS;
	float ** scattering_matrix;
	#ifdef OPENMP
	omp_lock_t * locks;
	#endif
} Source;

// Table structure for computing exponential
typedef struct{
	float * values;
	float dx;
	float maxVal;
	int N;
} Table;

// Params Structure for easier data pointer passing
typedef struct{
	Track2D * tracks_2D;
	Track *** tracks;
	Source * sources;
   	float * polar_angles;
	float * leakage;
	Table expTable;
} Params;

// MPI 3D Grid info
typedef struct{
	#ifdef MPI
	MPI_Comm cart_comm_3d;
	MPI_Datatype Flux_Array;
	#endif
	int x_pos_src;
	int x_pos_dest;
	int x_neg_src;
	int x_neg_dest;
	int y_pos_src;
	int y_pos_dest;
	int y_neg_src;
	int y_neg_dest;
	int z_pos_src;
	int z_pos_dest;
	int z_neg_src;
	int z_neg_dest;
} CommGrid;

// Attenuation Arrays
typedef struct{
	float * q0;
	float * q1;
	float * q2;
	float * sigT;
	float * tau;
	float * sigT2;
	float * expVal;
	float * reuse;
	float * flux_integral;
	float * tally;
	float * t1;
	float * t2;
	float * t3;
	float * t4;
} AttenuateVars;


// init.c
Input set_default_input( void );
void set_small_input( Input * I );
Params build_tracks( Input* I );
CommGrid init_mpi_grid( Input I );
void calculate_derived_inputs( Input * I );
#ifdef OPENMP
omp_lock_t * init_locks( Input I );
#endif

// io.c
void logo(int version);
void center_print(const char *s, int width);
void border_print(void);
void fancy_int( int a );
void print_input_summary(Input input);
void read_CLI( int argc, char * argv[], Input * input );
void print_CLI_error(void);
void read_input_file( Input * I, char * fname);

// tracks.c
Track2D * generate_2D_tracks( Input input, size_t * nbytes );
void generate_2D_segments( Input input, Track2D * tracks,
	   	size_t * nbytes );
void free_2D_tracks( Track2D * tracks );
Track *** generate_tracks(Input input, Track2D * tracks_2D, size_t * nbytes);
void free_tracks( Track *** tracks );
long segments_per_2D_track_distribution( Input I );
float * generate_polar_angles( Input I );
Track2D * load_OpenMOC_tracks(char* fname, bool CMFD_obj, Input* I, size_t* nbytes);

// utils.c
float urand(void);
float nrand(float mean, float sigma);
float pairwise_sum(float * vector, long size);
Table buildExponentialTable( float precision, float maxVal );
float interpolateTable( Table table, float x);
double get_time(void);
size_t est_mem_usage( Input I );
double time_per_intersection( Input I, double time );

// source.c
Source * initialize_sources( Input I, size_t * nbytes );
void free_sources( Input I, Source * sources );

// solver.c
void transport_sweep( Params * params, Input * I );
int get_pos_interval( float z, float dz);
int get_neg_interval( float z, float dz);
int get_alt_neg_interval( float z, float dz);
void attenuate_fluxes( Track * track, bool forward, Source * QSR, Input * I, 
		Params * params, float ds, float mu, float az_weight, AttenuateVars * A ); 
void attenuate_FSR_fluxes( Track * track, bool forward, Source * FSR, Input * I,
		Params * params, float ds, float mu, float az_weight, AttenuateVars * A );
void alt_attenuate_fluxes( Track * track, bool forward, Source * FSR, Input * I,
		Params * params, float ds, float mu, float az_weight );
void renormalize_flux( Params params, Input I, CommGrid grid );
float update_sources( Params params, Input I, float keff );
float compute_keff( Params params, Input I, CommGrid grid);

// test.c
void gen_norm_pts(float mean, float sigma, int n_pts);
void print_Input_struct( Input I );

// papi.c
void papi_serial_init(void);
void counter_init( int *eventset, int *num_papi_events, Input * I );
void counter_stop( int * eventset, int num_papi_events, Input * I );

// comms.c
#ifdef MPI
void fast_transfer_boundary_fluxes( Params params, Input I, CommGrid grid);
void transfer_boundary_fluxes( Params params, Input I, CommGrid grid);
#endif

#endif
