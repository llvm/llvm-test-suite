
/*!
 *************************************************************************************
 *
 * \file fast_me.h
 *
 * \brief
 *   Fast integer pixel and sub pixel motion estimation
 *   Improved and simplified from the original UMHexagonS algorithms
 *   See JVT-P021 for details
 *
 * \author 
 *    Main contributors: (see contributors.h for copyright, address and affiliation details)
 *    - Zhibo Chen                      <chenzhibo@tsinghua.org.cn>
 *    - JianFeng Xu                     <fenax@video.mdc.tsinghua.edu.cn>  
 *    - Wenfang Fu                      <fwf@video.mdc.tsinghua.edu.cn>
 *
 *    - Xiaoquan Yi                     <xyi@engr.scu.edu>
 *    - Jun Zhang                       <jzhang2@engr.scu.edu>
 *
 * \date
 *    16. June 2005
 *************************************************************************************
 */

#ifndef _SIMPLIFIED_FAST_ME_H_
#define _SIMPLIFIED_FAST_ME_H_

#include "mbuffer.h"

static const short block_type_shift_factor[8] = {0, 0, 1, 1, 2, 3, 3, 1}; // last one relaxed to 1 instead 4

unsigned short  SymmetricalCrossSearchThreshold1;
unsigned short  SymmetricalCrossSearchThreshold2;
unsigned short  ConvergeThreshold;
unsigned short  SubPelThreshold1;
unsigned short  SubPelThreshold3;

byte  **simplified_SearchState;          //state for fractional pel search
int  ***simplified_fastme_l0_cost;       //store SAD information needed for forward median and uplayer prediction
int  ***simplified_fastme_l1_cost;       //store SAD information needed for backward median and uplayer prediction
byte   *simplified_flag_intra;
int     simplified_flag_intra_SAD;

int     simplified_pred_SAD_uplayer;     // Up layer SAD prediction
short   simplified_pred_MV_uplayer_X;    // Up layer MV predictor X-component
short   simplified_pred_MV_uplayer_Y;    // Up layer MV predictor Y-component

void    simplified_init_FME();
int     simplified_get_mem_FME();
void    simplified_free_mem_FME();
void    simplified_decide_intrabk_SAD();
void    simplified_skip_intrabk_SAD(int, int);
void    simplified_setup_FME(short, int, int, int, int, short ******);

int                                     //  ==> minimum motion cost after search
simplified_FastIntegerPelBlockMotionSearch (
               pel_t   **orig_pic,      // <--  not used
               short     ref,           // <--  reference frame (0... or -1 (backward))
               int       list,          // <--  reference picture list
               int       pic_pix_x,     // <--  absolute x-coordinate of regarded AxB block
               int       pic_pix_y,     // <--  absolute y-coordinate of regarded AxB block
               int       blocktype,     // <--  block type (1-16x16 ... 7-4x4)
               short     pred_mv_x,     // <--  motion vector predictor (x) in sub-pel units
               short     pred_mv_y,     // <--  motion vector predictor (y) in sub-pel units
               short*    mv_x,          //  --> motion vector (x) - in pel units
               short*    mv_y,          //  --> motion vector (y) - in pel units
               int       search_range,  // <--  1-d search range in pel units                         
               int       min_mcost,     // <--  minimum motion cost (cost for center or huge value)
               int       lambda_factor);// <--  lagrangian parameter for determining motion cost

int                                     //  ==> minimum motion cost after search
simplified_FastSubPelBlockMotionSearch (
               pel_t** orig_pic,        // <--  original pixel values for the AxB block
               short     ref,           // <--  reference frame (0... or -1 (backward))
               int       list,          // <--  reference picture list
               int       pic_pix_x,     // <--  absolute x-coordinate of regarded AxB block
               int       pic_pix_y,     // <--  absolute y-coordinate of regarded AxB block
               int       blocktype,     // <--  block type (1-16x16 ... 7-4x4)
               short     pred_mv_x,     // <--  motion vector predictor (x) in sub-pel units
               short     pred_mv_y,     // <--  motion vector predictor (y) in sub-pel units
               short*    mv_x,          // <--> in: search center (x) / out: motion vector (x) - in pel units
               short*    mv_y,          // <--> in: search center (y) / out: motion vector (y) - in pel units
               int       search_pos2,   // <--  search positions for    half-pel search  (default: 9)
               int       search_pos4,   // <--  search positions for quarter-pel search  (default: 9)
               int       min_mcost,     // <--  minimum motion cost (cost for center or huge value)
               int       lambda_factor, // <--  lagrangian parameter for determining motion cost
               int       useABT);

#endif
