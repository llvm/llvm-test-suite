#ifndef __HOTSPOT_H_
#define __HOTSPOT_H_

#define STR_SIZE 256

/* maximum power density possible (say 300W for a 10mm x 10mm chip)	*/
#define MAX_PD (3.0e6)
/* required precision in degrees	*/
#define PRECISION 0.001
#define SPEC_HEAT_SI 1.75e6
#define K_SI 100
/* capacitance fitting factor	*/
#define FACTOR_CHIP 0.5

// Run Options
#define grid_rows 512
#define grid_cols 512
#define num_iterations 200 // sim_time in original hotspot

// seed for random number generator
#define SEED 7

#endif /* __HOTSPOT_H_ */