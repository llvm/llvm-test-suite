
/*!
 *************************************************************************************
 * \file block.c
 *
 * \brief
 *    Process one block
 *
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *    - Inge Lille-Langoy               <inge.lille-langoy@telenor.com>
 *    - Rickard Sjoberg                 <rickard.sjoberg@era.ericsson.se>
 *    - Stephan Wenger                  <stewe@cs.tu-berlin.de>
 *    - Jani Lainema                    <jani.lainema@nokia.com>
 *    - Detlev Marpe                    <marpe@hhi.de>
 *    - Thomas Wedi                     <wedi@tnt.uni-hannover.de>
 *    - Ragip Kurceren                  <ragip.kurceren@nokia.com>
 *    - Greg Conklin                    <gregc@real.com>
 *************************************************************************************
 */

#include "contributors.h"


#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <math.h>

#include "global.h"

#include "image.h"
#include "mb_access.h"
#include "block.h"
#include "vlc.h"


const int quant_coef[6][4][4] = {
  {{13107, 8066,13107, 8066},{ 8066, 5243, 8066, 5243},{13107, 8066,13107, 8066},{ 8066, 5243, 8066, 5243}},
  {{11916, 7490,11916, 7490},{ 7490, 4660, 7490, 4660},{11916, 7490,11916, 7490},{ 7490, 4660, 7490, 4660}},
  {{10082, 6554,10082, 6554},{ 6554, 4194, 6554, 4194},{10082, 6554,10082, 6554},{ 6554, 4194, 6554, 4194}},
  {{ 9362, 5825, 9362, 5825},{ 5825, 3647, 5825, 3647},{ 9362, 5825, 9362, 5825},{ 5825, 3647, 5825, 3647}},
  {{ 8192, 5243, 8192, 5243},{ 5243, 3355, 5243, 3355},{ 8192, 5243, 8192, 5243},{ 5243, 3355, 5243, 3355}},
  {{ 7282, 4559, 7282, 4559},{ 4559, 2893, 4559, 2893},{ 7282, 4559, 7282, 4559},{ 4559, 2893, 4559, 2893}}
};

const int dequant_coef[6][4][4] = {
  {{10, 13, 10, 13},{ 13, 16, 13, 16},{10, 13, 10, 13},{ 13, 16, 13, 16}},
  {{11, 14, 11, 14},{ 14, 18, 14, 18},{11, 14, 11, 14},{ 14, 18, 14, 18}},
  {{13, 16, 13, 16},{ 16, 20, 16, 20},{13, 16, 13, 16},{ 16, 20, 16, 20}},
  {{14, 18, 14, 18},{ 18, 23, 18, 23},{14, 18, 14, 18},{ 18, 23, 18, 23}},
  {{16, 20, 16, 20},{ 20, 25, 20, 25},{16, 20, 16, 20},{ 20, 25, 20, 25}},
  {{18, 23, 18, 23},{ 23, 29, 23, 29},{18, 23, 18, 23},{ 23, 29, 23, 29}}
};
static const int A[4][4] = {
  { 16, 20, 16, 20},
  { 20, 25, 20, 25},
  { 16, 20, 16, 20},
  { 20, 25, 20, 25}
};


// Notation for comments regarding prediction and predictors.
// The pels of the 4x4 block are labelled a..p. The predictor pels above
// are labelled A..H, from the left I..P, and from above left X, as follows:
//
//  X A B C D E F G H
//  I a b c d
//  J e f g h
//  K i j k l
//  L m n o p
//

// Predictor array index definitions
#define P_X (PredPel[0])
#define P_A (PredPel[1])
#define P_B (PredPel[2])
#define P_C (PredPel[3])
#define P_D (PredPel[4])
#define P_E (PredPel[5])
#define P_F (PredPel[6])
#define P_G (PredPel[7])
#define P_H (PredPel[8])
#define P_I (PredPel[9])
#define P_J (PredPel[10])
#define P_K (PredPel[11])
#define P_L (PredPel[12])

/*!
 ************************************************************************
 * \brief
 *    Make intra 4x4 prediction according to all 9 prediction modes.
 *    The routine uses left and upper neighbouring points from
 *    previous coded blocks to do this (if available). Notice that
 *    inaccessible neighbouring points are signalled with a negative
 *    value in the predmode array .
 *
 *  \par Input:
 *     Starting point of current 4x4 block image posision
 *
 *  \par Output:
 *      none
 ************************************************************************
 */
void intrapred_luma(int img_x,int img_y, int *left_available, int *up_available, int *all_available)
{
  int i,j;
  int s0;
  int PredPel[13];  // array of predictor pels
  imgpel **imgY = enc_picture->imgY;  // For MB level frame/field coding tools -- set default to imgY

  int ioff = (img_x & 15);
  int joff = (img_y & 15);
  int mb_nr=img->current_mb_nr;

  PixelPos pix_a[4];
  PixelPos pix_b, pix_c, pix_d;

  int block_available_up;
  int block_available_left;
  int block_available_up_left;
  int block_available_up_right;

  for (i=0;i<4;i++)
  {
    getNeighbour(mb_nr, ioff -1 , joff +i , 1, &pix_a[i]);
  }
    
  getNeighbour(mb_nr, ioff    , joff -1 , 1, &pix_b);
  getNeighbour(mb_nr, ioff +4 , joff -1 , 1, &pix_c);
  getNeighbour(mb_nr, ioff -1 , joff -1 , 1, &pix_d);

  pix_c.available = pix_c.available && !(((ioff==4)||(ioff==12)) && ((joff==4)||(joff==12)));

  if (input->UseConstrainedIntraPred)
  {
    for (i=0, block_available_left=1; i<4;i++)
      block_available_left  &= pix_a[i].available ? img->intra_block[pix_a[i].mb_addr]: 0;
    block_available_up       = pix_b.available ? img->intra_block [pix_b.mb_addr] : 0;
    block_available_up_right = pix_c.available ? img->intra_block [pix_c.mb_addr] : 0;
    block_available_up_left  = pix_d.available ? img->intra_block [pix_d.mb_addr] : 0;
  }
  else
  {
    block_available_left     = pix_a[0].available;
    block_available_up       = pix_b.available;
    block_available_up_right = pix_c.available;
    block_available_up_left  = pix_d.available;
  }
  
  *left_available = block_available_left;
  *up_available   = block_available_up;
  *all_available  = block_available_up && block_available_left && block_available_up_left;

  i = (img_x & 15);
  j = (img_y & 15);

  // form predictor pels
  if (block_available_up)
  {
    P_A = imgY[pix_b.pos_y][pix_b.pos_x+0];
    P_B = imgY[pix_b.pos_y][pix_b.pos_x+1];
    P_C = imgY[pix_b.pos_y][pix_b.pos_x+2];
    P_D = imgY[pix_b.pos_y][pix_b.pos_x+3];

  }
  else
  {
    P_A = P_B = P_C = P_D = img->dc_pred_value;
  }

  if (block_available_up_right)
  {
    P_E = imgY[pix_c.pos_y][pix_c.pos_x+0];
    P_F = imgY[pix_c.pos_y][pix_c.pos_x+1];
    P_G = imgY[pix_c.pos_y][pix_c.pos_x+2];
    P_H = imgY[pix_c.pos_y][pix_c.pos_x+3];
  }
  else
  {
    P_E = P_F = P_G = P_H = P_D;
  }

  if (block_available_left)
  {
    P_I = imgY[pix_a[0].pos_y][pix_a[0].pos_x];
    P_J = imgY[pix_a[1].pos_y][pix_a[1].pos_x];
    P_K = imgY[pix_a[2].pos_y][pix_a[2].pos_x];
    P_L = imgY[pix_a[3].pos_y][pix_a[3].pos_x];
  }
  else
  {
    P_I = P_J = P_K = P_L = img->dc_pred_value;
  }

  if (block_available_up_left)
  {
    P_X = imgY[pix_d.pos_y][pix_d.pos_x];
  }
  else
  {
    P_X = img->dc_pred_value;
  }

  for(i=0;i<9;i++)
    img->mprr[i][0][0]=-1;

  ///////////////////////////////
  // make DC prediction
  ///////////////////////////////
  s0 = 0;
  if (block_available_up && block_available_left)
  {   
    // no edge
    s0 = (P_A + P_B + P_C + P_D + P_I + P_J + P_K + P_L + 4) >> (BLOCK_SHIFT + 1);
  }
  else if (!block_available_up && block_available_left)
  {
    // upper edge
    s0 = (P_I + P_J + P_K + P_L + 2) >> BLOCK_SHIFT;;             
  }
  else if (block_available_up && !block_available_left)
  {
    // left edge
    s0 = (P_A + P_B + P_C + P_D + 2) >> BLOCK_SHIFT;             
  }
  else //if (!block_available_up && !block_available_left)
  {
    // top left corner, nothing to predict from
    s0 = img->dc_pred_value;                           
  }

  // store DC prediction
  for (j=0; j < BLOCK_SIZE; j++)
  {
    for (i=0; i < BLOCK_SIZE; i++)
      img->mprr[DC_PRED][j][i] = s0;
  }

  ///////////////////////////////
  // make horiz and vert prediction
  ///////////////////////////////

  for (i=0; i < BLOCK_SIZE; i++)
  {
    img->mprr[VERT_PRED][0][i] = 
    img->mprr[VERT_PRED][1][i] = 
    img->mprr[VERT_PRED][2][i] = 
    img->mprr[VERT_PRED][3][i] = (&P_A)[i];
    img->mprr[HOR_PRED][i][0]  = 
    img->mprr[HOR_PRED][i][1]  = 
    img->mprr[HOR_PRED][i][2]  = 
    img->mprr[HOR_PRED][i][3]  = (&P_I)[i];
  }

  if(!block_available_up)
    img->mprr[VERT_PRED][0][0]=-1;
  if(!block_available_left)
    img->mprr[HOR_PRED][0][0]=-1;

  if (block_available_up) 
  {
    // Mode DIAG_DOWN_LEFT_PRED
    img->mprr[DIAG_DOWN_LEFT_PRED][0][0] = (P_A + P_C + 2*(P_B) + 2) >> 2;
    img->mprr[DIAG_DOWN_LEFT_PRED][0][1] = 
    img->mprr[DIAG_DOWN_LEFT_PRED][1][0] = (P_B + P_D + 2*(P_C) + 2) >> 2;
    img->mprr[DIAG_DOWN_LEFT_PRED][0][2] =
    img->mprr[DIAG_DOWN_LEFT_PRED][1][1] =
    img->mprr[DIAG_DOWN_LEFT_PRED][2][0] = (P_C + P_E + 2*(P_D) + 2) >> 2;
    img->mprr[DIAG_DOWN_LEFT_PRED][0][3] = 
    img->mprr[DIAG_DOWN_LEFT_PRED][1][2] = 
    img->mprr[DIAG_DOWN_LEFT_PRED][2][1] = 
    img->mprr[DIAG_DOWN_LEFT_PRED][3][0] = (P_D + P_F + 2*(P_E) + 2) >> 2;
    img->mprr[DIAG_DOWN_LEFT_PRED][1][3] = 
    img->mprr[DIAG_DOWN_LEFT_PRED][2][2] = 
    img->mprr[DIAG_DOWN_LEFT_PRED][3][1] = (P_E + P_G + 2*(P_F) + 2) >> 2;
    img->mprr[DIAG_DOWN_LEFT_PRED][2][3] = 
    img->mprr[DIAG_DOWN_LEFT_PRED][3][2] = (P_F + P_H + 2*(P_G) + 2) >> 2;
    img->mprr[DIAG_DOWN_LEFT_PRED][3][3] = (P_G + 3*(P_H) + 2) >> 2;

    // Mode VERT_LEFT_PRED
    img->mprr[VERT_LEFT_PRED][0][0] = (P_A + P_B + 1) >> 1;
    img->mprr[VERT_LEFT_PRED][0][1] = 
    img->mprr[VERT_LEFT_PRED][2][0] = (P_B + P_C + 1) >> 1;
    img->mprr[VERT_LEFT_PRED][0][2] = 
    img->mprr[VERT_LEFT_PRED][2][1] = (P_C + P_D + 1) >> 1;
    img->mprr[VERT_LEFT_PRED][0][3] = 
    img->mprr[VERT_LEFT_PRED][2][2] = (P_D + P_E + 1) >> 1;
    img->mprr[VERT_LEFT_PRED][2][3] = (P_E + P_F + 1) >> 1;
    img->mprr[VERT_LEFT_PRED][1][0] = (P_A + 2*P_B + P_C + 2) >> 2;
    img->mprr[VERT_LEFT_PRED][1][1] = 
    img->mprr[VERT_LEFT_PRED][3][0] = (P_B + 2*P_C + P_D + 2) >> 2;
    img->mprr[VERT_LEFT_PRED][1][2] = 
    img->mprr[VERT_LEFT_PRED][3][1] = (P_C + 2*P_D + P_E + 2) >> 2;
    img->mprr[VERT_LEFT_PRED][1][3] = 
    img->mprr[VERT_LEFT_PRED][3][2] = (P_D + 2*P_E + P_F + 2) >> 2;
    img->mprr[VERT_LEFT_PRED][3][3] = (P_E + 2*P_F + P_G + 2) >> 2;

  }

  /*  Prediction according to 'diagonal' modes */
  if (block_available_left) 
  {
    // Mode HOR_UP_PRED
    img->mprr[HOR_UP_PRED][0][0] = (P_I + P_J + 1) >> 1;
    img->mprr[HOR_UP_PRED][0][1] = (P_I + 2*P_J + P_K + 2) >> 2;
    img->mprr[HOR_UP_PRED][0][2] = 
    img->mprr[HOR_UP_PRED][1][0] = (P_J + P_K + 1) >> 1;
    img->mprr[HOR_UP_PRED][0][3] = 
    img->mprr[HOR_UP_PRED][1][1] = (P_J + 2*P_K + P_L + 2) >> 2;
    img->mprr[HOR_UP_PRED][1][2] = 
    img->mprr[HOR_UP_PRED][2][0] = (P_K + P_L + 1) >> 1;
    img->mprr[HOR_UP_PRED][1][3] = 
    img->mprr[HOR_UP_PRED][2][1] = (P_K + 2*P_L + P_L + 2) >> 2;
    img->mprr[HOR_UP_PRED][3][0] = 
    img->mprr[HOR_UP_PRED][2][2] = 
    img->mprr[HOR_UP_PRED][2][3] = 
    img->mprr[HOR_UP_PRED][3][1] = 
    img->mprr[HOR_UP_PRED][3][2] = 
    img->mprr[HOR_UP_PRED][3][3] = P_L;
  }

  /*  Prediction according to 'diagonal' modes */
  if (block_available_up && block_available_left && block_available_up_left) 
  {
    // Mode DIAG_DOWN_RIGHT_PRED
    img->mprr[DIAG_DOWN_RIGHT_PRED][3][0] = (P_L + 2*P_K + P_J + 2) >> 2; 
    img->mprr[DIAG_DOWN_RIGHT_PRED][2][0] =
    img->mprr[DIAG_DOWN_RIGHT_PRED][3][1] = (P_K + 2*P_J + P_I + 2) >> 2; 
    img->mprr[DIAG_DOWN_RIGHT_PRED][1][0] =
    img->mprr[DIAG_DOWN_RIGHT_PRED][2][1] = 
    img->mprr[DIAG_DOWN_RIGHT_PRED][3][2] = (P_J + 2*P_I + P_X + 2) >> 2; 
    img->mprr[DIAG_DOWN_RIGHT_PRED][0][0] =
    img->mprr[DIAG_DOWN_RIGHT_PRED][1][1] =
    img->mprr[DIAG_DOWN_RIGHT_PRED][2][2] =
    img->mprr[DIAG_DOWN_RIGHT_PRED][3][3] = (P_I + 2*P_X + P_A + 2) >> 2; 
    img->mprr[DIAG_DOWN_RIGHT_PRED][0][1] =
    img->mprr[DIAG_DOWN_RIGHT_PRED][1][2] =
    img->mprr[DIAG_DOWN_RIGHT_PRED][2][3] = (P_X + 2*P_A + P_B + 2) >> 2;
    img->mprr[DIAG_DOWN_RIGHT_PRED][0][2] =
    img->mprr[DIAG_DOWN_RIGHT_PRED][1][3] = (P_A + 2*P_B + P_C + 2) >> 2;
    img->mprr[DIAG_DOWN_RIGHT_PRED][0][3] = (P_B + 2*P_C + P_D + 2) >> 2;

     // Mode VERT_RIGHT_PRED
    img->mprr[VERT_RIGHT_PRED][0][0] = 
    img->mprr[VERT_RIGHT_PRED][2][1] = (P_X + P_A + 1) >> 1;
    img->mprr[VERT_RIGHT_PRED][0][1] = 
    img->mprr[VERT_RIGHT_PRED][2][2] = (P_A + P_B + 1) >> 1;
    img->mprr[VERT_RIGHT_PRED][0][2] = 
    img->mprr[VERT_RIGHT_PRED][2][3] = (P_B + P_C + 1) >> 1;
    img->mprr[VERT_RIGHT_PRED][0][3] = (P_C + P_D + 1) >> 1;
    img->mprr[VERT_RIGHT_PRED][1][0] = 
    img->mprr[VERT_RIGHT_PRED][3][1] = (P_I + 2*P_X + P_A + 2) >> 2;
    img->mprr[VERT_RIGHT_PRED][1][1] = 
    img->mprr[VERT_RIGHT_PRED][3][2] = (P_X + 2*P_A + P_B + 2) >> 2;
    img->mprr[VERT_RIGHT_PRED][1][2] = 
    img->mprr[VERT_RIGHT_PRED][3][3] = (P_A + 2*P_B + P_C + 2) >> 2;
    img->mprr[VERT_RIGHT_PRED][1][3] = (P_B + 2*P_C + P_D + 2) >> 2;
    img->mprr[VERT_RIGHT_PRED][2][0] = (P_X + 2*P_I + P_J + 2) >> 2;
    img->mprr[VERT_RIGHT_PRED][3][0] = (P_I + 2*P_J + P_K + 2) >> 2;

    // Mode HOR_DOWN_PRED
    img->mprr[HOR_DOWN_PRED][0][0] = 
    img->mprr[HOR_DOWN_PRED][1][2] = (P_X + P_I + 1) >> 1;
    img->mprr[HOR_DOWN_PRED][0][1] = 
    img->mprr[HOR_DOWN_PRED][1][3] = (P_I + 2*P_X + P_A + 2) >> 2;
    img->mprr[HOR_DOWN_PRED][0][2] = (P_X + 2*P_A + P_B + 2) >> 2;
    img->mprr[HOR_DOWN_PRED][0][3] = (P_A + 2*P_B + P_C + 2) >> 2;
    img->mprr[HOR_DOWN_PRED][1][0] = 
    img->mprr[HOR_DOWN_PRED][2][2] = (P_I + P_J + 1) >> 1;
    img->mprr[HOR_DOWN_PRED][1][1] = 
    img->mprr[HOR_DOWN_PRED][2][3] = (P_X + 2*P_I + P_J + 2) >> 2;
    img->mprr[HOR_DOWN_PRED][2][0] = 
    img->mprr[HOR_DOWN_PRED][3][2] = (P_J + P_K + 1) >> 1;
    img->mprr[HOR_DOWN_PRED][2][1] = 
    img->mprr[HOR_DOWN_PRED][3][3] = (P_I + 2*P_J + P_K + 2) >> 2;
    img->mprr[HOR_DOWN_PRED][3][0] = (P_K + P_L + 1) >> 1;
    img->mprr[HOR_DOWN_PRED][3][1] = (P_J + 2*P_K + P_L + 2) >> 2;
  }
}

/*!
 ************************************************************************
 * \brief
 *    16x16 based luma prediction
 *
 * \par Input:
 *    Image parameters
 *
 * \par Output:
 *    none
 ************************************************************************
 */
void intrapred_luma_16x16()
{
  int s0=0,s1,s2;
  imgpel s[2][16];
  int i,j;

  int ih,iv;
  int ib,ic,iaa;

  imgpel   **imgY_pred = enc_picture->imgY;  // For Mb level field/frame coding tools -- default to frame pred
  int          mb_nr = img->current_mb_nr;

  PixelPos up;          //!< pixel position p(0,-1)
  PixelPos left[17];    //!< pixel positions p(-1, -1..15)

  int up_avail, left_avail, left_up_avail;

  for (i=0;i<17;i++)
  {
    getNeighbour(mb_nr, -1,  i-1, 1, &left[i]);
  }
  
  getNeighbour(mb_nr,    0,   -1, 1, &up);

  if (!(input->UseConstrainedIntraPred))
  {
    up_avail      = up.available;
    left_avail    = left[1].available;
    left_up_avail = left[0].available;
  }
  else
  {
    up_avail      = up.available ? img->intra_block[up.mb_addr] : 0;
    for (i=1, left_avail=1; i<17;i++)
      left_avail  &= left[i].available ? img->intra_block[left[i].mb_addr]: 0;
    left_up_avail = left[0].available ? img->intra_block[left[0].mb_addr]: 0;
  }

  s1=s2=0;
  // make DC prediction
  if (up_avail)
  {
    for (i=0; i < MB_BLOCK_SIZE; i++)
      s1 += imgY_pred[up.pos_y][up.pos_x+i];    // sum hor pix
  }

  if (left_avail)
  {
    for (i=0; i < MB_BLOCK_SIZE; i++)      
      s2 += imgY_pred[left[i+1].pos_y][left[i+1].pos_x];    // sum vert pix
  }

  if (up_avail && left_avail)
    s0=(s1+s2+16)/(2*MB_BLOCK_SIZE);             // no edge
  
  if (!up_avail && left_avail)
    s0=(s2+8)/MB_BLOCK_SIZE;                     // upper edge
  
  if (up_avail && !left_avail)
    s0=(s1+8)/MB_BLOCK_SIZE;                     // left edge
  
  if (!up_avail && !left_avail)
    s0=img->dc_pred_value;                       // top left corner, nothing to predict from

  // vertical prediction
  if (up_avail)
    memcpy(s[0], &imgY_pred[up.pos_y][up.pos_x], MB_BLOCK_SIZE * sizeof(imgpel));
  
  // horizontal prediction
  if (left_avail)
  {
    for (i=0; i < MB_BLOCK_SIZE; i++)
      s[1][i]=imgY_pred[left[i+1].pos_y][left[i+1].pos_x];
  }

  for (j=0; j < MB_BLOCK_SIZE; j++)
  {
    memcpy(img->mprr_2[VERT_PRED_16][j], s[0], MB_BLOCK_SIZE * sizeof(imgpel)); // store vertical prediction
    for (i=0; i < MB_BLOCK_SIZE; i++)
    {
      img->mprr_2[HOR_PRED_16 ][j][i]=s[1][j]; // store horizontal prediction
      img->mprr_2[DC_PRED_16  ][j][i]=s0;      // store DC prediction
    }
  }
  if (!up_avail || !left_avail || !left_up_avail) // edge
    return;

  // 16 bit integer plan pred

  ih=0;
  iv=0;
  for (i=1;i<9;i++)
  {
    if (i<8)
      ih += i*(imgY_pred[up.pos_y][up.pos_x+7+i] - imgY_pred[up.pos_y][up.pos_x+7-i]);
    else
      ih += i*(imgY_pred[up.pos_y][up.pos_x+7+i] - imgY_pred[left[0].pos_y][left[0].pos_x]);
    
    iv += i*(imgY_pred[left[8+i].pos_y][left[8+i].pos_x] - imgY_pred[left[8-i].pos_y][left[8-i].pos_x]);
  }
  ib=(5*ih+32)>>6;
  ic=(5*iv+32)>>6;
  
  iaa=16*(imgY_pred[up.pos_y][up.pos_x+15]+imgY_pred[left[16].pos_y][left[16].pos_x]);

  for (j=0;j< MB_BLOCK_SIZE;j++)
  {
    for (i=0;i< MB_BLOCK_SIZE;i++)
    {
      img->mprr_2[PLANE_16][j][i]=max(0,min((int)img->max_imgpel_value,(iaa+(i-7)*ib +(j-7)*ic + 16)/32));// store plane prediction
    }
  }
}


/*!
 ************************************************************************
 * \brief
 *    For new intra pred routines
 *
 * \par Input:
 *    Image par, 16x16 based intra mode
 *
 * \par Output:
 *    none
 ************************************************************************
 */
int dct_luma_16x16(int new_intra_mode)
{
  //int qp_const;
  int i,j;
  int ii,jj;
  int jdiv, jmod;
  int M1[16][16];
  int M4[4][4];
  int M5[4],M6[4];
  int M0[4][4][4][4];
  int run,scan_pos,coeff_ctr,level;
  int qp_per,qp_rem,q_bits;
  int ac_coef = 0;

  Macroblock *currMB = &img->mb_data[img->current_mb_nr];
  short is_field_mode = (img->field_picture || ( img->MbaffFrameFlag && currMB->mb_field));

  int   b8, b4;
  int*  DCLevel = img->cofDC[0][0];
  int*  DCRun   = img->cofDC[0][1];
  int*  ACLevel;
  int*  ACRun;
  int **levelscale,**leveloffset;
  int **invlevelscale;
  Boolean lossless_qpprime = ((currMB->qp + img->bitdepth_luma_qp_scale)==0 && img->lossless_qpprime_flag==1);

  qp_per    = (currMB->qp + img->bitdepth_luma_qp_scale - MIN_QP)/6;
  qp_rem    = (currMB->qp + img->bitdepth_luma_qp_scale - MIN_QP)%6;
  q_bits    = Q_BITS+qp_per;
  levelscale    = LevelScale4x4Luma[1][qp_rem];
  leveloffset   = LevelOffset4x4Luma[1][qp_per];
  invlevelscale = InvLevelScale4x4Luma[1][qp_rem];


  for (j=0;j<16;j++)
  {
    jdiv = j >> 2;
    jmod = j & 0x03;
    jj = img->opix_y+j;
    for (i=0;i<16;i++)
    {
      // Residue Color Transform
      if(!img->residue_transform_flag)
        M1[j][i]=imgY_org[jj][img->opix_x+i]-img->mprr_2[new_intra_mode][j][i];
      else
        M1[j][i]=img->m7[j][i];

      M0[jdiv][i >> 2][jmod][i & 0x03]=M1[j][i];
    }
  }

  for (jj=0;jj<4 && !lossless_qpprime;jj++)
  {
    for (ii=0;ii<4;ii++)
    {
      for (j=0;j<4;j++)
      {
        M5[0] = M0[jj][ii][j][0] + M0[jj][ii][j][3];
        M5[1] = M0[jj][ii][j][1] + M0[jj][ii][j][2];
        M5[2] = M0[jj][ii][j][1] - M0[jj][ii][j][2];
        M5[3] = M0[jj][ii][j][0] - M0[jj][ii][j][3];

        M4[j][0] = M5[0]   + M5[1];
        M4[j][2] = M5[0]   - M5[1];
        M4[j][1] = M5[3]*2 + M5[2];
        M4[j][3] = M5[3]   - M5[2]*2;
      }
      // vertical
      for (i=0;i<4;i++)
      {
        M5[0] = M4[0][i] + M4[3][i];
        M5[1] = M4[1][i] + M4[2][i];
        M5[2] = M4[1][i] - M4[2][i];
        M5[3] = M4[0][i] - M4[3][i];
        
        M0[jj][ii][0][i] = M5[0]   + M5[1];
        M0[jj][ii][2][i] = M5[0]   - M5[1];
        M0[jj][ii][1][i] = M5[3]*2 + M5[2];
        M0[jj][ii][3][i] = M5[3]   - M5[2]*2;
      }
    }
  }

  // pick out DC coeff

  for (j=0;j<4;j++)
  {
    for (i=0;i<4;i++)
      M4[j][i]= M0[j][i][0][0];
  }

  if (!lossless_qpprime)
  {
    for (j=0;j<4;j++)
    {
      M5[0] = M4[j][0]+M4[j][3];
      M5[1] = M4[j][1]+M4[j][2];
      M5[2] = M4[j][1]-M4[j][2];
      M5[3] = M4[j][0]-M4[j][3];
      
      M4[j][0] = M5[0]+M5[1];
      M4[j][2] = M5[0]-M5[1];
      M4[j][1] = M5[3]+M5[2];
      M4[j][3] = M5[3]-M5[2];
    }
    
    // vertical
    
    for (i=0;i<4;i++)
    {    
      M5[0] = M4[0][i]+M4[3][i];
      M5[1] = M4[1][i]+M4[2][i];
      M5[2] = M4[1][i]-M4[2][i];
      M5[3] = M4[0][i]-M4[3][i];
      
      M4[0][i]=(M5[0]+M5[1])>>1;
      M4[2][i]=(M5[0]-M5[1])>>1;
      M4[1][i]=(M5[3]+M5[2])>>1;
      M4[3][i]=(M5[3]-M5[2])>>1;
    }
  }
  // quant

  run=-1;
  scan_pos=0;

  for (coeff_ctr=0;coeff_ctr<16;coeff_ctr++)
  {
    if (is_field_mode) 
    {  // Alternate scan for field coding
        i=FIELD_SCAN[coeff_ctr][0];
        j=FIELD_SCAN[coeff_ctr][1];
    }
    else 
    {
        i=SNGL_SCAN[coeff_ctr][0];
        j=SNGL_SCAN[coeff_ctr][1];
    }

    run++;

    if(lossless_qpprime)
      level= absm(M4[j][i]);
    else
      level= (absm(M4[j][i]) * levelscale[0][0] + (leveloffset[0][0]<<1)) >> (q_bits+1);

    if (input->symbol_mode == UVLC && img->qp < 10) 
    {
      if (level > CAVLC_LEVEL_LIMIT) 
        level = CAVLC_LEVEL_LIMIT;
    }

    if (level != 0)
    {
      DCLevel[scan_pos] = sign(level,M4[j][i]);
      DCRun  [scan_pos] = run;
      ++scan_pos;
      run=-1;
    }
    if(!lossless_qpprime)
      M4[j][i]=sign(level,M4[j][i]);
  }
  DCLevel[scan_pos]=0;

  // invers DC transform
  for (j=0;j<4 && !lossless_qpprime;j++)
  {
    M6[0]=M4[j][0]+M4[j][2];
    M6[1]=M4[j][0]-M4[j][2];
    M6[2]=M4[j][1]-M4[j][3];
    M6[3]=M4[j][1]+M4[j][3];

    M4[j][0] = M6[0]+M6[3];
    M4[j][1] = M6[1]+M6[2];
    M4[j][2] = M6[1]-M6[2];
    M4[j][3] = M6[0]-M6[3];
  }

  for (i=0;i<4 && !lossless_qpprime;i++)
  {
    
    M6[0]=M4[0][i]+M4[2][i];
    M6[1]=M4[0][i]-M4[2][i];
    M6[2]=M4[1][i]-M4[3][i];
    M6[3]=M4[1][i]+M4[3][i];
    
    if(qp_per<6)
    {
      M0[0][i][0][0] = ((M6[0]+M6[3])*invlevelscale[0][0]+(1<<(5-qp_per)))>>(6-qp_per);
      M0[1][i][0][0] = ((M6[1]+M6[2])*invlevelscale[0][0]+(1<<(5-qp_per)))>>(6-qp_per);
      M0[2][i][0][0] = ((M6[1]-M6[2])*invlevelscale[0][0]+(1<<(5-qp_per)))>>(6-qp_per);
      M0[3][i][0][0] = ((M6[0]-M6[3])*invlevelscale[0][0]+(1<<(5-qp_per)))>>(6-qp_per);
    }
    else
    {
      M0[0][i][0][0] = ((M6[0]+M6[3])*invlevelscale[0][0])<<(qp_per-6);
      M0[1][i][0][0] = ((M6[1]+M6[2])*invlevelscale[0][0])<<(qp_per-6);
      M0[2][i][0][0] = ((M6[1]-M6[2])*invlevelscale[0][0])<<(qp_per-6);
      M0[3][i][0][0] = ((M6[0]-M6[3])*invlevelscale[0][0])<<(qp_per-6);
    }   
  }

  // AC inverse trans/quant for MB
  for (jj=0;jj<4;jj++)
  {
    for (ii=0;ii<4;ii++)
    {
      for (j=0;j<4;j++)
      {
        memcpy(M4[j],M0[jj][ii][j], BLOCK_SIZE * sizeof(int));
      }

      run      = -1;
      scan_pos =  0;
      b8       = 2*(jj >> 1) + (ii >> 1);
      b4       = 2*(jj & 0x01) + (ii & 0x01);
      ACLevel  = img->cofAC [b8][b4][0];
      ACRun    = img->cofAC [b8][b4][1];

      for (coeff_ctr=1;coeff_ctr<16;coeff_ctr++) // set in AC coeff
      {

        if (is_field_mode) 
        {  // Alternate scan for field coding
          i=FIELD_SCAN[coeff_ctr][0];
          j=FIELD_SCAN[coeff_ctr][1];
        }
        else 
        {
          i=SNGL_SCAN[coeff_ctr][0];
          j=SNGL_SCAN[coeff_ctr][1];
        }
        run++;

        if(lossless_qpprime)
          level= absm( M4[j][i]);
        else          
          level= ( absm( M4[j][i]) * levelscale[i][j] + leveloffset[i][j]) >> q_bits;

        if (img->AdaptiveRounding)
        {
          if (lossless_qpprime || level == 0 )
          {
            img->fadjust4x4[2][jj*BLOCK_SIZE+j][ii*BLOCK_SIZE+i] = 0;
          }
          else
          {
            img->fadjust4x4[2][jj*BLOCK_SIZE+j][ii*BLOCK_SIZE+i] = 
              (AdaptRndWeight * (absm(M4[j][i]) * levelscale[i][j] - (level << q_bits)) + (1<< (q_bits))) >> (q_bits + 1);
          }            
        }

        if (level != 0)
        {
          ac_coef = 15;
          ACLevel[scan_pos] = sign(level,M4[j][i]);
          ACRun  [scan_pos] = run;
          ++scan_pos;
          run=-1;
        }
        
        if(!lossless_qpprime)
        {
          level=sign(level, M4[j][i]);
          if(qp_per<4)
            M4[j][i]=(level*invlevelscale[i][j]+(1<<(3-qp_per)))>>(4-qp_per);
          else
            M4[j][i]=(level*invlevelscale[i][j])<<(qp_per-4);
        }
      }
      ACLevel[scan_pos] = 0;


      // IDCT horizontal
      for (j=0;j<4 && !lossless_qpprime;j++)
      {
        M6[0] = M4[j][0]     +  M4[j][2];
        M6[1] = M4[j][0]     -  M4[j][2];
        M6[2] =(M4[j][1]>>1) -  M4[j][3];
        M6[3] = M4[j][1]     + (M4[j][3]>>1);
        
        M4[j][0] = M6[0] + M6[3];
        M4[j][1] = M6[1] + M6[2];
        M4[j][2] = M6[1] - M6[2];
        M4[j][3] = M6[0] - M6[3];
      }

      // vert
      for (i=0;i<4 && !lossless_qpprime;i++)
      {
        M6[0]= M4[0][i]     +  M4[2][i];
        M6[1]= M4[0][i]     -  M4[2][i];
        M6[2]=(M4[1][i]>>1) -  M4[3][i];
        M6[3]= M4[1][i]     + (M4[3][i]>>1);
        
        M0[jj][ii][0][i] = M6[0] + M6[3];
        M0[jj][ii][1][i] = M6[1] + M6[2];
        M0[jj][ii][2][i] = M6[1] - M6[2];
        M0[jj][ii][3][i] = M6[0] - M6[3];
      }
    }
  }

  // Residue Color Transform
  if(!img->residue_transform_flag)
  {
    for (jj=0;jj<BLOCK_MULTIPLE; jj++)
      for (ii=0;ii<BLOCK_MULTIPLE; ii++)
        for (j=0;j<BLOCK_SIZE;j++)
        {
          memcpy(&M1[jj*BLOCK_SIZE + j][ii*BLOCK_SIZE], M0[jj][ii][j], BLOCK_SIZE * sizeof(int));
        }
  }
  else
  {
    if(lossless_qpprime)
    {
      for (j=0;j<MB_BLOCK_SIZE;j++)    
      {
        jdiv = j >> 2;
        jmod = j & 0x03;
        for (i=0;i<MB_BLOCK_SIZE;i++)
          img->m7[j][i]=M0[jdiv][i >> 2][jmod][i & 0x03];
      }
    }
    else
    {
      for (j=0;j<MB_BLOCK_SIZE;j++)    
      {
        jdiv = j >> 2;
        jmod = j & 0x03;
        for (i=0;i<MB_BLOCK_SIZE;i++)
          img->m7[j][i]=((M0[jdiv][i >> 2][jmod][i & 0x03]+DQ_ROUND)>>DQ_BITS);
      }
    }
  }

  if(!img->residue_transform_flag)
  {
    if(lossless_qpprime)
    {
      for (j=0;j<16;j++)
      {
        jj = img->pix_y+j;
        for (i=0;i<16;i++)
            enc_picture->imgY[jj][img->pix_x+i]=(imgpel)(M1[j][i]+img->mprr_2[new_intra_mode][j][i]);
      }
    }
    else
    {
      for (j=0;j<16;j++)
      {
        jj = img->pix_y+j;
        for (i=0;i<16;i++)
          enc_picture->imgY[jj][img->pix_x+i]=(imgpel)clip1a((M1[j][i]+((long)img->mprr_2[new_intra_mode][j][i]<<DQ_BITS)+DQ_ROUND)>>DQ_BITS);
      }
    }
  }
  return ac_coef;
}


/*!
************************************************************************
* \brief
*    The routine performs transform,quantization,inverse transform, adds the diff.
*    to the prediction and writes the result to the decoded luma frame. Includes the
*    RD constrained quantization also.
*
* \par Input:
*    block_x,block_y: Block position inside a macro block (0,4,8,12).
*
* \par Output_
*    nonzero: 0 if no levels are nonzero.  1 if there are nonzero levels.             \n
*    coeff_cost: Counter for nonzero coefficients, used to discard expensive levels.
************************************************************************
*/
int dct_luma(int block_x,int block_y,int *coeff_cost, int intra)
{
  int sign(int a,int b);

  int i,j,ilev, m4[4][4], m5[4],m6[4],coeff_ctr;
  int ii;
  //int qp_const;
  int level,scan_pos,run;
  int nonzero;
  int qp_per,qp_rem,q_bits;

  int   pos_x   = block_x >> BLOCK_SHIFT;
  int   pos_y   = block_y >> BLOCK_SHIFT;
  int   b8      = 2*(pos_y >> 1) + (pos_x >> 1);
  int   b4      = 2*(pos_y & 0x01) + (pos_x & 0x01);
  int*  ACLevel = img->cofAC[b8][b4][0];
  int*  ACRun   = img->cofAC[b8][b4][1];
  short pix_y;

  Macroblock *currMB = &img->mb_data[img->current_mb_nr];
  short is_field_mode = (img->field_picture || ( img->MbaffFrameFlag && currMB->mb_field));

  Boolean lossless_qpprime = ((currMB->qp + img->bitdepth_luma_qp_scale)==0 && img->lossless_qpprime_flag==1);
  int **levelscale,**leveloffset;
  int **invlevelscale;

  qp_per    = (currMB->qp + img->bitdepth_luma_qp_scale - MIN_QP)/6; 
  qp_rem    = (currMB->qp + img->bitdepth_luma_qp_scale - MIN_QP)%6; 
  q_bits    = Q_BITS+qp_per;

  levelscale    = LevelScale4x4Luma[intra][qp_rem];
  leveloffset   = LevelOffset4x4Luma[intra][qp_per];
  invlevelscale = InvLevelScale4x4Luma[intra][qp_rem];

  //  Horizontal transform
  if (!lossless_qpprime)
  {
    for (j=0; j < BLOCK_SIZE; j++)
    {
      m5[0] = img->m7[j][0]+img->m7[j][3];
      m5[1] = img->m7[j][1]+img->m7[j][2];
      m5[2] = img->m7[j][1]-img->m7[j][2];
      m5[3] = img->m7[j][0]-img->m7[j][3];
      
      m4[j][0] = m5[0]   + m5[1];
      m4[j][2] = m5[0]   - m5[1];
      m4[j][1] = m5[3]*2 + m5[2];
      m4[j][3] = m5[3]   - m5[2]*2;
    }
    
    //  Vertical transform
    for (i=0; i < BLOCK_SIZE; i++)
    {    
      m5[0] = m4[0][i] + m4[3][i];
      m5[1] = m4[1][i] + m4[2][i];
      m5[2] = m4[1][i] - m4[2][i];
      m5[3] = m4[0][i] - m4[3][i];
      
      m4[0][i] = m5[0]   + m5[1];
      m4[2][i] = m5[0]   - m5[1];
      m4[1][i] = m5[3]*2 + m5[2];
      m4[3][i] = m5[3]   - m5[2]*2;
    }
  }
  // Quant

  nonzero=FALSE;

  run=-1;
  scan_pos=0;
  
  for (coeff_ctr=0;coeff_ctr < 16;coeff_ctr++)
  {

    if (is_field_mode) 
    {  
      // Alternate scan for field coding
      i=FIELD_SCAN[coeff_ctr][0];
      j=FIELD_SCAN[coeff_ctr][1];
    }
    else 
    {
      i=SNGL_SCAN[coeff_ctr][0];
      j=SNGL_SCAN[coeff_ctr][1];
    }
    
    run++;
    ilev=0;
    
    if(lossless_qpprime)
      level = absm (img->m7[j][i]);
    else
      level = (absm (m4[j][i]) * levelscale[i][j] + leveloffset[i][j]) >> q_bits;

    if (img->AdaptiveRounding)
    {
      if (lossless_qpprime || level == 0 )
      {
        img->fadjust4x4[intra][block_y+j][block_x+i] = 0;
      }
      else 
      {
        img->fadjust4x4[intra][block_y+j][block_x+i] = 
          (AdaptRndWeight * (absm(m4[j][i]) * levelscale[i][j] - (level << q_bits)) + (1<< (q_bits))) >> (q_bits + 1);         
      }
    }

    if (level != 0)
    {
      nonzero=TRUE;

      *coeff_cost += (level > 1 || lossless_qpprime) ? MAX_VALUE : COEFF_COST[input->disthres][run];

      if(lossless_qpprime)
        ACLevel[scan_pos] = sign(level,img->m7[j][i]);
      else
        ACLevel[scan_pos] = sign(level,m4[j][i]);

      ACRun  [scan_pos] = run;
      ++scan_pos;
      run=-1;                     // reset zero level counter

      level=sign(level, m4[j][i]);

      if(lossless_qpprime)
      {
        ilev=level;
      }
      else if(qp_per<4)
      {
        ilev=(level*invlevelscale[i][j]+(1<<(3-qp_per)))>>(4-qp_per);
      }
      else
      {
        ilev=(level*invlevelscale[i][j])<<(qp_per-4);
      }
    }
    if(!lossless_qpprime)
      m4[j][i]=ilev;
  }

  ACLevel[scan_pos] = 0;  
  
  //     IDCT.
  //     horizontal

  if (!lossless_qpprime)
  {
    for (j=0; j < BLOCK_SIZE; j++)
    {
      m6[0]=(m4[j][0]     +  m4[j][2]);
      m6[1]=(m4[j][0]     -  m4[j][2]);
      m6[2]=(m4[j][1]>>1) -  m4[j][3];
      m6[3]= m4[j][1]     + (m4[j][3]>>1);
      
      m4[j][0] = m6[0] + m6[3];
      m4[j][1] = m6[1] + m6[2];
      m4[j][2] = m6[1] - m6[2];
      m4[j][3] = m6[0] - m6[3];
    }
    
    //  vertical
    for (i=0; i < BLOCK_SIZE; i++)
    {
      
      m6[0]=(m4[0][i]     +  m4[2][i]);
      m6[1]=(m4[0][i]     -  m4[2][i]);
      m6[2]=(m4[1][i]>>1) -  m4[3][i];
      m6[3]= m4[1][i]     + (m4[3][i]>>1);
      
      ii = i + block_x;
      
      if (!img->residue_transform_flag)
      {
        img->m7[0][i] = min(img->max_imgpel_value,max(0,(m6[0]+m6[3]+((long)img->mpr[0 + block_y][ii] << DQ_BITS)+DQ_ROUND)>>DQ_BITS));
        img->m7[1][i] = min(img->max_imgpel_value,max(0,(m6[1]+m6[2]+((long)img->mpr[1 + block_y][ii] << DQ_BITS)+DQ_ROUND)>>DQ_BITS));
        img->m7[2][i] = min(img->max_imgpel_value,max(0,(m6[1]-m6[2]+((long)img->mpr[2 + block_y][ii] << DQ_BITS)+DQ_ROUND)>>DQ_BITS));
        img->m7[3][i] = min(img->max_imgpel_value,max(0,(m6[0]-m6[3]+((long)img->mpr[3 + block_y][ii] << DQ_BITS)+DQ_ROUND)>>DQ_BITS));
      } 
      else 
      {
        if(lossless_qpprime)
        {
          img->m7[0][i] = m6[0]+m6[3];
          img->m7[1][i] = m6[1]+m6[2];
          img->m7[2][i] = m6[1]-m6[2];
          img->m7[3][i] = m6[0]-m6[3];
        }
        else
        {
          img->m7[0][i] =(m6[0]+m6[3]+DQ_ROUND)>>DQ_BITS;
          img->m7[1][i] =(m6[1]+m6[2]+DQ_ROUND)>>DQ_BITS;
          img->m7[2][i] =(m6[1]-m6[2]+DQ_ROUND)>>DQ_BITS;
          img->m7[3][i] =(m6[0]-m6[3]+DQ_ROUND)>>DQ_BITS;
        }
      }
    }
  }
  //  Decoded block moved to frame memory
  if (!img->residue_transform_flag)
  {
    if(lossless_qpprime)
    {
      for (j=0; j < BLOCK_SIZE; j++)
      {
        pix_y = img->pix_y+block_y+j;
        for (i=0; i < BLOCK_SIZE; i++)
        {
         enc_picture->imgY[pix_y][img->pix_x+block_x+i]=img->m7[j][i]+img->mpr[j+block_y][i+block_x];
        }
      }
    }
    else
    {
      for (j=0; j < BLOCK_SIZE; j++)
      {
        pix_y = img->pix_y+block_y+j;
        for (i=0; i < BLOCK_SIZE; i++)
        {
          enc_picture->imgY[pix_y][img->pix_x+block_x+i]=img->m7[j][i];
        }
      }
    }
    
  }
  return nonzero;
}


/*!
 ************************************************************************
 * \brief
 *    Transform,quantization,inverse transform for chroma.
 *    The main reason why this is done in a separate routine is the
 *    additional 2x2 transform of DC-coeffs. This routine is called
 *    ones for each of the chroma components.
 *
 * \par Input:
 *    uv    : Make difference between the U and V chroma component  \n
 *    cr_cbp: chroma coded block pattern
 *
 * \par Output:
 *    cr_cbp: Updated chroma coded block pattern.
 ************************************************************************
 */
int dct_chroma(int uv,int cr_cbp)
{
  int i,j,i1,j2,ilev,n2,n1,j1,mb_y,coeff_ctr,level ,scan_pos,run;
  int m1[BLOCK_SIZE],m5[BLOCK_SIZE],m6[BLOCK_SIZE];
  int coeff_cost;
  int cr_cbp_tmp;
  int DCcoded=0 ;
  Macroblock *currMB = &img->mb_data[img->current_mb_nr];
 
  int qp_per,qp_rem,q_bits;
  int qp_c;

  int   b4;
  int*  DCLevel = img->cofDC[uv+1][0];
  int*  DCRun   = img->cofDC[uv+1][1];
  int*  ACLevel;
  int*  ACRun;
  int   intra = IS_INTRA (currMB);
  int   uv_scale = uv*(img->num_blk8x8_uv >> 1);

  //FRExt
  int64 cbpblk_pattern[4]={0, 0xf0000, 0xff0000, 0xffff0000};
  int yuv = img->yuv_format;
  int b8;
  int m3[4][4];
  int m4[4][4];
  int qp_per_dc = 0;
  int qp_rem_dc = 0;
  int q_bits_422 = 0;	
  int ***levelscale, ***leveloffset;
  int ***invlevelscale;
  short pix_c_x, pix_c_y;
  short is_field_mode = (img->field_picture || ( img->MbaffFrameFlag && currMB->mb_field));

  Boolean lossless_qpprime = ((currMB->qp + img->bitdepth_luma_qp_scale)==0 && img->lossless_qpprime_flag==1);

  qp_c      = currMB->qp + img->chroma_qp_offset[uv];
  qp_c      = Clip3(-img->bitdepth_chroma_qp_scale,51,qp_c);
  qp_c      = (qp_c < 0)? qp_c : QP_SCALE_CR[qp_c - MIN_QP];

  qp_per    = (qp_c + img->bitdepth_chroma_qp_scale)/6;              
  qp_rem    = (qp_c + img->bitdepth_chroma_qp_scale)%6;              
  q_bits    = Q_BITS+qp_per;

  levelscale = LevelScale4x4Chroma[uv][intra];
  leveloffset = LevelOffset4x4Chroma[uv][intra];
  invlevelscale = InvLevelScale4x4Chroma[uv][intra];

  if (img->yuv_format == YUV422)
  {
    //for YUV422 only
    qp_per_dc = (qp_c + 3 + img->bitdepth_chroma_qp_scale)/6;
    qp_rem_dc = (qp_c + 3 + img->bitdepth_chroma_qp_scale)%6;
    
    q_bits_422 = Q_BITS+qp_per_dc;  
  }

  
  //============= dct transform ===============	
  for (n2=0; n2 < img->mb_cr_size_y; n2 += BLOCK_SIZE)
  {
    for (n1=0; n1 < img->mb_cr_size_x; n1 += BLOCK_SIZE)
    {

      //  Horizontal transform.
      for (j=0; j < BLOCK_SIZE && !lossless_qpprime; j++)
      {
        mb_y=n2+j;
        
        m5[0]=img->m7[mb_y][n1  ]+img->m7[mb_y][n1+3];
        m5[1]=img->m7[mb_y][n1+1]+img->m7[mb_y][n1+2];
        m5[2]=img->m7[mb_y][n1+1]-img->m7[mb_y][n1+2];
        m5[3]=img->m7[mb_y][n1  ]-img->m7[mb_y][n1+3];
        
        img->m7[mb_y][n1  ] = (m5[0]   + m5[1]);
        img->m7[mb_y][n1+2] = (m5[0]   - m5[1]);
        img->m7[mb_y][n1+1] =  m5[3]*2 + m5[2];
        img->m7[mb_y][n1+3] =  m5[3]   - m5[2]*2;
      }

      //  Vertical transform.

      for (i=0; i < BLOCK_SIZE && !lossless_qpprime; i++)
      {
        j1=n1+i;
        m5[0] = img->m7[n2  ][j1] + img->m7[n2+3][j1];
        m5[1] = img->m7[n2+1][j1] + img->m7[n2+2][j1];
        m5[2] = img->m7[n2+1][j1] - img->m7[n2+2][j1];
        m5[3] = img->m7[n2  ][j1] - img->m7[n2+3][j1];

        img->m7[n2+0][j1] = (m5[0]   + m5[1]);
        img->m7[n2+2][j1] = (m5[0]   - m5[1]);
        img->m7[n2+1][j1] =  m5[3]*2 + m5[2];
        img->m7[n2+3][j1] =  m5[3]   - m5[2]*2;
      }
    }
  }
  
  if (yuv == YUV420)
  {
    //================== CHROMA DC YUV420 ===================
    //     2X2 transform of DC coeffs.
    if(lossless_qpprime)
    {
      m1[0]=img->m7[0][0];
      m1[1]=img->m7[0][4];
      m1[2]=img->m7[4][0];
      m1[3]=img->m7[4][4];
    }
    else 
    {
      m1[0]=(img->m7[0][0] + img->m7[0][4] + img->m7[4][0] + img->m7[4][4]);
      m1[1]=(img->m7[0][0] - img->m7[0][4] + img->m7[4][0] - img->m7[4][4]);
      m1[2]=(img->m7[0][0] + img->m7[0][4] - img->m7[4][0] - img->m7[4][4]);
      m1[3]=(img->m7[0][0] - img->m7[0][4] - img->m7[4][0] + img->m7[4][4]);
    }
    
    //     Quant of chroma 2X2 coeffs.
    run=-1;
    scan_pos=0;
    
    for (coeff_ctr=0; coeff_ctr < 4; coeff_ctr++)
    {
      run++;
      ilev=0;
      
      if(lossless_qpprime)
        level =absm(m1[coeff_ctr]);
      else 
        level =(absm(m1[coeff_ctr]) * levelscale[qp_rem][0][0] + (leveloffset[qp_per][0][0]<<1)) >> (q_bits+1);
      
      if (input->symbol_mode == UVLC && img->qp < 4) 
      {
        if (level > CAVLC_LEVEL_LIMIT) 
          level = CAVLC_LEVEL_LIMIT;
      }
      
      if (level  != 0)
      {
        currMB->cbp_blk |= 0xf0000 << (uv << 2) ;    // if one of the 2x2-DC levels is != 0 set the
        cr_cbp=max(1,cr_cbp);                     // coded-bit all 4 4x4 blocks (bit 16-19 or 20-23)
        DCcoded = 1 ;
        DCLevel[scan_pos] = sign(level ,m1[coeff_ctr]);
        DCRun  [scan_pos] = run;
        scan_pos++;
        run=-1;
        
        ilev=sign(level, m1[coeff_ctr]);
      }
      if(!lossless_qpprime)
        m1[coeff_ctr]=ilev;
    }
    DCLevel[scan_pos] = 0;
    
    //  Inverse transform of 2x2 DC levels
    if(!lossless_qpprime)
    {
      m5[0]=(m1[0] + m1[1] + m1[2] + m1[3]);
      m5[1]=(m1[0] - m1[1] + m1[2] - m1[3]);
      m5[2]=(m1[0] + m1[1] - m1[2] - m1[3]);
      m5[3]=(m1[0] - m1[1] - m1[2] + m1[3]);
      if(qp_per<5)
      {
        for(i=0; i<4; i++)
          m1[i]=(m5[i] * invlevelscale[qp_rem][0][0])>>(5-qp_per);
      }
      else
      {
        for(i=0; i<4; i++)
          m1[i]=(m5[i] * invlevelscale[qp_rem][0][0])<<(qp_per-5);
      }

      img->m7[0][0] = m1[0];
      img->m7[0][4] = m1[1];
      img->m7[4][0] = m1[2];
      img->m7[4][4] = m1[3];
    }
  }
  else if(yuv == YUV422)
  {
    //================== CHROMA DC YUV422 ===================
    //transform DC coeff
    //horizontal
    
    //pick out DC coeff
    for (j=0; j < img->mb_cr_size_y; j+=BLOCK_SIZE)
    {
      for (i=0; i < img->mb_cr_size_x; i+=BLOCK_SIZE)
        m3[i>>2][j>>2]= img->m7[j][i];
    } 
    //horizontal
    if(!lossless_qpprime)
    {
      m4[0][0] = m3[0][0] + m3[1][0];
      m4[0][1] = m3[0][1] + m3[1][1];
      m4[0][2] = m3[0][2] + m3[1][2];
      m4[0][3] = m3[0][3] + m3[1][3];
      
      m4[1][0] = m3[0][0] - m3[1][0];
      m4[1][1] = m3[0][1] - m3[1][1];
      m4[1][2] = m3[0][2] - m3[1][2];
      m4[1][3] = m3[0][3] - m3[1][3];
      
      // vertical
      for (i=0;i<2;i++)
      {
        m5[0] = m4[i][0] + m4[i][3];
        m5[1] = m4[i][1] + m4[i][2];
        m5[2] = m4[i][1] - m4[i][2];
        m5[3] = m4[i][0] - m4[i][3];
        
        m4[i][0] = (m5[0] + m5[1]);
        m4[i][2] = (m5[0] - m5[1]);
        m4[i][1] = (m5[3] + m5[2]);
        m4[i][3] = (m5[3] - m5[2]);
      }
    }
    
    run=-1;
    scan_pos=0;
    
    //quant of chroma DC-coeffs
    for (coeff_ctr=0;coeff_ctr<8;coeff_ctr++)
    {
      i=SCAN_YUV422[coeff_ctr][0];
      j=SCAN_YUV422[coeff_ctr][1];
      
      run++;

      if(lossless_qpprime)
      {
        level = absm(m3[i][j]);
        m4[i][j]=m3[i][j];
      }
      else 
        level =(absm(m4[i][j]) * levelscale[qp_rem_dc][0][0] + (leveloffset[qp_per_dc][0][0]*2)) >> (q_bits_422+1);

      if (level != 0)
      {
        //YUV422
        currMB->cbp_blk |= 0xff0000 << (uv << 3) ;   // if one of the DC levels is != 0 set the
        cr_cbp=max(1,cr_cbp);												   // coded-bit all 4 4x4 blocks (bit 16-31 or 32-47) //YUV444
        DCcoded = 1 ;
        
        DCLevel[scan_pos] = sign(level,m4[i][j]);
        DCRun  [scan_pos] = run;
        ++scan_pos;
        run=-1;
      }
      if(!lossless_qpprime)
        m3[i][j]=sign(level,m4[i][j]);
    }
    DCLevel[scan_pos]=0;

    //inverse DC transform
    //horizontal
    if(!lossless_qpprime)
    {
      m4[0][0] = m3[0][0] + m3[1][0];
      m4[0][1] = m3[0][1] + m3[1][1];
      m4[0][2] = m3[0][2] + m3[1][2];
      m4[0][3] = m3[0][3] + m3[1][3];
      
      m4[1][0] = m3[0][0] - m3[1][0];
      m4[1][1] = m3[0][1] - m3[1][1];
      m4[1][2] = m3[0][2] - m3[1][2];
      m4[1][3] = m3[0][3] - m3[1][3];      
      
      // vertical
      for (i=0;i<2;i++)
      {       
        m6[0]=m4[i][0]+m4[i][2];
        m6[1]=m4[i][0]-m4[i][2];
        m6[2]=m4[i][1]-m4[i][3];
        m6[3]=m4[i][1]+m4[i][3];
        
        if(qp_per_dc<4)
        {          
          img->m7[0 ][i*4]=((((m6[0]+m6[3])*invlevelscale[qp_rem_dc][0][0]+(1<<(3-qp_per_dc)))>>(4-qp_per_dc))+2)>>2;
          img->m7[4 ][i*4]=((((m6[1]+m6[2])*invlevelscale[qp_rem_dc][0][0]+(1<<(3-qp_per_dc)))>>(4-qp_per_dc))+2)>>2;
          img->m7[8 ][i*4]=((((m6[1]-m6[2])*invlevelscale[qp_rem_dc][0][0]+(1<<(3-qp_per_dc)))>>(4-qp_per_dc))+2)>>2;
          img->m7[12][i*4]=((((m6[0]-m6[3])*invlevelscale[qp_rem_dc][0][0]+(1<<(3-qp_per_dc)))>>(4-qp_per_dc))+2)>>2;
        }
        else
        {
          img->m7[0 ][i*4]=((((m6[0]+m6[3])*invlevelscale[qp_rem_dc][0][0])<<(qp_per_dc-4))+2)>>2;
          img->m7[4 ][i*4]=((((m6[1]+m6[2])*invlevelscale[qp_rem_dc][0][0])<<(qp_per_dc-4))+2)>>2;
          img->m7[8 ][i*4]=((((m6[1]-m6[2])*invlevelscale[qp_rem_dc][0][0])<<(qp_per_dc-4))+2)>>2;
          img->m7[12][i*4]=((((m6[0]-m6[3])*invlevelscale[qp_rem_dc][0][0])<<(qp_per_dc-4))+2)>>2;
        }
      }//for (i=0;i<2;i++)    
    }
  }
  else if(yuv == YUV444)
  {
    //================== CHROMA DC YUV444 ===================
    //transform DC coeff
    //pick out DC coeff
    for (j=0; j < img->mb_cr_size_y; j+=BLOCK_SIZE)
    {
      for (i=0; i < img->mb_cr_size_x; i+=BLOCK_SIZE)
        m4[i>>2][j>>2]= img->m7[j][i];
    }
    
    //horizontal
    for (j=0;j<4 && !lossless_qpprime;j++)
    {
      m5[0] = m4[0][j] + m4[3][j];
      m5[1] = m4[1][j] + m4[2][j];
      m5[2] = m4[1][j] - m4[2][j];
      m5[3] = m4[0][j] - m4[3][j];
      
      m4[0][j]=m5[0]+m5[1];
      m4[2][j]=m5[0]-m5[1];
      m4[1][j]=m5[3]+m5[2];
      m4[3][j]=m5[3]-m5[2];
    }
    // vertical
    for (i=0;i<4 && !lossless_qpprime;i++)
    {
      m5[0] = m4[i][0] + m4[i][3];
      m5[1] = m4[i][1] + m4[i][2];
      m5[2] = m4[i][1] - m4[i][2];
      m5[3] = m4[i][0] - m4[i][3];

      m4[i][0]=(m5[0]+m5[1])>>1;
      m4[i][2]=(m5[0]-m5[1])>>1;
      m4[i][1]=(m5[3]+m5[2])>>1;
      m4[i][3]=(m5[3]-m5[2])>>1;
    }

    run=-1;
    scan_pos=0;
    
    //quant of chroma DC-coeffs
    for (coeff_ctr=0;coeff_ctr<16;coeff_ctr++)
    {
      i=SNGL_SCAN[coeff_ctr][0];
      j=SNGL_SCAN[coeff_ctr][1];
      
      run++;
      
      if(lossless_qpprime)
        level = absm(m4[i][j]);
      else 
        level =(absm(m4[i][j]) * levelscale[qp_rem][0][0] + (leveloffset[qp_per][0][0]*2)) >> (q_bits+1);
      
      if (level != 0)
      {
        //YUV444
        currMB->cbp_blk |= ((int64)0xffff0000) << (uv << 4) ;   // if one of the DC levels is != 0 set the
        cr_cbp=max(1,cr_cbp);												   // coded-bit all 4 4x4 blocks (bit 16-31 or 32-47) //YUV444
        DCcoded = 1 ;
        
        DCLevel[scan_pos] = sign(level,m4[i][j]);
        DCRun  [scan_pos] = run;
        ++scan_pos;
        run=-1;
      }
      if(!lossless_qpprime)
        m4[i][j]=sign(level,m4[i][j]);
    }
    DCLevel[scan_pos]=0;

    // inverse DC transform
    //horizontal
    for (j=0;j<4 && !lossless_qpprime;j++)
    {     
      m6[0] = m4[0][j] + m4[2][j];
      m6[1] = m4[0][j] - m4[2][j];
      m6[2] = m4[1][j] - m4[3][j];
      m6[3] = m4[1][j] + m4[3][j];
      
      m4[0][j] = m6[0] + m6[3];
      m4[1][j] = m6[1] + m6[2];
      m4[2][j] = m6[1] - m6[2];
      m4[3][j] = m6[0] - m6[3];
    }
    
    //vertical
    for (i=0;i<4 && !lossless_qpprime;i++)
    {
      m6[0]=m4[i][0]+m4[i][2];
      m6[1]=m4[i][0]-m4[i][2];
      m6[2]=m4[i][1]-m4[i][3];
      m6[3]=m4[i][1]+m4[i][3];

      if(qp_per<4)
      {
        img->m7[0 ][i*4] = ((((m6[0] + m6[3])*invlevelscale[qp_rem][0][0]+(1<<(3-qp_per)))>>(4-qp_per))+2)>>2;
        img->m7[4 ][i*4] = ((((m6[1] + m6[2])*invlevelscale[qp_rem][0][0]+(1<<(3-qp_per)))>>(4-qp_per))+2)>>2;
        img->m7[8 ][i*4] = ((((m6[1] - m6[2])*invlevelscale[qp_rem][0][0]+(1<<(3-qp_per)))>>(4-qp_per))+2)>>2;
        img->m7[12][i*4] = ((((m6[0] - m6[3])*invlevelscale[qp_rem][0][0]+(1<<(3-qp_per)))>>(4-qp_per))+2)>>2;
      }
      else
      {
        img->m7[0 ][i*4] = ((((m6[0]+m6[3])*invlevelscale[qp_rem][0][0])<<(qp_per-4))+2)>>2;
        img->m7[4 ][i*4] = ((((m6[1]+m6[2])*invlevelscale[qp_rem][0][0])<<(qp_per-4))+2)>>2;
        img->m7[8 ][i*4] = ((((m6[1]-m6[2])*invlevelscale[qp_rem][0][0])<<(qp_per-4))+2)>>2;
        img->m7[12][i*4] = ((((m6[0]-m6[3])*invlevelscale[qp_rem][0][0])<<(qp_per-4))+2)>>2;
      }
    }
  }

  //     Quant of chroma AC-coeffs.
  coeff_cost=0;
  cr_cbp_tmp=0;

  for (b8=0; b8 < (img->num_blk8x8_uv >> 1); b8++)
  {
    for (b4=0; b4 < 4; b4++)
    {
      n1 = hor_offset[yuv][b8][b4];
      n2 = ver_offset[yuv][b8][b4];
      ACLevel = img->cofAC[4+b8+uv_scale][b4][0];
      ACRun   = img->cofAC[4+b8+uv_scale][b4][1];
      run=-1;
      scan_pos=0;

      for (coeff_ctr=1; coeff_ctr < 16; coeff_ctr++)// start change rd_quant
      {

        if (is_field_mode) 
        {  // Alternate scan for field coding
          i=FIELD_SCAN[coeff_ctr][0];
          j=FIELD_SCAN[coeff_ctr][1];
        }
        else 
        {
          i=SNGL_SCAN[coeff_ctr][0];
          j=SNGL_SCAN[coeff_ctr][1];
        }
        ++run;
        ilev=0;

        if(lossless_qpprime)
          level = absm(img->m7[n2+j][n1+i]);
        else 
          level=(absm(img->m7[n2+j][n1+i])*levelscale[qp_rem][i][j]+leveloffset[qp_per][i][j])>>q_bits;

        if (img->AdaptiveRounding)
        {
          if (lossless_qpprime || level == 0 )
          {
            img->fadjust4x4Cr[intra][uv][n2+j][n1+i] = 0;
          }
          else
          {
            img->fadjust4x4Cr[intra][uv][n2+j][n1+i] = 
              (AdaptRndWeight * (absm(img->m7[n2+j][n1+i]) * levelscale[qp_rem][i][j] - (level << q_bits)) + (1<< (q_bits))) >> (q_bits + 1); 
          }          
        }

        if (level  != 0)
        {
          currMB->cbp_blk |= ((int64)1) << cbp_blk_chroma[b8 + uv_scale][b4];
          if (level > 1 || lossless_qpprime)
            coeff_cost += MAX_VALUE;                // set high cost, shall not be discarded
          else
            coeff_cost += COEFF_COST[input->disthres][run];

          cr_cbp_tmp=2;
          ACLevel[scan_pos] = sign(level,img->m7[n2+j][n1+i]);
          ACRun  [scan_pos] = run;
          ++scan_pos;
          run=-1;

          level=sign(level, img->m7[n2+j][n1+i]);
          if(lossless_qpprime)
          {
            ilev = level;
          }
          else if(qp_per<4)
          {
            ilev=(level*invlevelscale[qp_rem][i][j]+(1<<(3-qp_per)))>>(4-qp_per);
          }
          else
          {
            ilev=(level*invlevelscale[qp_rem][i][j])<<(qp_per-4);
          }
        }
        if(!lossless_qpprime)
          img->m7[n2+j][n1+i]=ilev;
      }
      ACLevel[scan_pos] = 0;
    }
  }

  // * reset chroma coeffs
  if(coeff_cost < _CHROMA_COEFF_COST_ && !lossless_qpprime)
  {
    cr_cbp_tmp = 0 ;
    
    for (b8=0; b8 < (img->num_blk8x8_uv >> 1); b8++)
    {
      for (b4=0; b4 < 4; b4++)
      {
        n1 = hor_offset[yuv][b8][b4];
        n2 = ver_offset[yuv][b8][b4];
        ACLevel = img->cofAC[4+b8+uv_scale][b4][0];
        ACRun   = img->cofAC[4+b8+uv_scale][b4][1];
        if( DCcoded == 0) 
          currMB->cbp_blk &= ~((int64)cbpblk_pattern[yuv] << (uv << (1+yuv)));  // if no chroma DC's: then reset coded-bits of this chroma subblock
        
        ACLevel[0] = 0;
        for (coeff_ctr=1; coeff_ctr < 16; coeff_ctr++)// ac coeff
        {

          if (is_field_mode) 
          {  // Alternate scan for field coding
            i=FIELD_SCAN[coeff_ctr][0];
            j=FIELD_SCAN[coeff_ctr][1];
          }
          else 
          {
            i=SNGL_SCAN[coeff_ctr][0];
            j=SNGL_SCAN[coeff_ctr][1];
          }
          img->m7[n2+j][n1+i]=0;
          ACLevel[coeff_ctr] = 0;
        }
      }
    }
  }

  if(cr_cbp_tmp==2)   
    cr_cbp = 2;
  
  //     IDCT.
  //     Horizontal.
  for (n2=0; n2 < img->mb_cr_size_y && !lossless_qpprime; n2 += BLOCK_SIZE)
  {
    for (n1=0; n1 < img->mb_cr_size_x; n1 += BLOCK_SIZE)
    {
      for (j=0; j < BLOCK_SIZE; j++)
      {
        j2 = n2 + j;
        for (i=0; i < BLOCK_SIZE; i++)
        {
          m5[i]=img->m7[j2][n1+i];
        }

        m6[0] = (m5[0]     +  m5[2]);
        m6[1] = (m5[0]     -  m5[2]);
        m6[2] = (m5[1]>>1) -  m5[3];
        m6[3] =  m5[1]     + (m5[3]>>1);

        img->m7[j2][n1  ] = m6[0] + m6[3];
        img->m7[j2][n1+1] = m6[1] + m6[2];
        img->m7[j2][n1+2] = m6[1] - m6[2];
        img->m7[j2][n1+3] = m6[0] - m6[3];
      }

      //     Vertical.
      for (i=0; i < BLOCK_SIZE && !lossless_qpprime; i++)
      {
        i1 = n1 + i;
        for (j=0; j < BLOCK_SIZE; j++)
        {
          m5[j]=img->m7[n2+j][i1];
        }
        m6[0]=(m5[0]+m5[2]);
        m6[1]=(m5[0]-m5[2]);
        m6[2]=(m5[1]>>1)-m5[3];
        m6[3]=m5[1]+(m5[3]>>1);

          // Residue Color Transform
        if (!img->residue_transform_flag)
        {
          img->m7[n2  ][i1] = min(img->max_imgpel_value_uv,max(0,(m6[0]+m6[3]+((long)img->mpr[n2  ][i1] << DQ_BITS)+DQ_ROUND)>>DQ_BITS));
          img->m7[n2+1][i1] = min(img->max_imgpel_value_uv,max(0,(m6[1]+m6[2]+((long)img->mpr[n2+1][i1] << DQ_BITS)+DQ_ROUND)>>DQ_BITS));
          img->m7[n2+2][i1] = min(img->max_imgpel_value_uv,max(0,(m6[1]-m6[2]+((long)img->mpr[n2+2][i1] << DQ_BITS)+DQ_ROUND)>>DQ_BITS));
          img->m7[n2+3][i1] = min(img->max_imgpel_value_uv,max(0,(m6[0]-m6[3]+((long)img->mpr[n2+3][i1] << DQ_BITS)+DQ_ROUND)>>DQ_BITS));
        } 
        else 
        {
          if(lossless_qpprime)
          {
            img->m7[n2  ][i1] = m6[0]+m6[3];
            img->m7[n2+1][i1] = m6[1]+m6[2];
            img->m7[n2+2][i1] = m6[1]-m6[2];
            img->m7[n2+3][i1] = m6[0]-m6[3];
          }
          else
          {
            img->m7[n2  ][i1] = (m6[0]+m6[3]+DQ_ROUND)>>DQ_BITS;
            img->m7[n2+1][i1] = (m6[1]+m6[2]+DQ_ROUND)>>DQ_BITS;
            img->m7[n2+2][i1] = (m6[1]-m6[2]+DQ_ROUND)>>DQ_BITS;
            img->m7[n2+3][i1] = (m6[0]-m6[3]+DQ_ROUND)>>DQ_BITS;
          }
        }
      }
    }
  }

  //  Decoded block moved to memory
  if (!img->residue_transform_flag)
  {
    for (j=0; j < img->mb_cr_size_y; j++)
    {
      pix_c_y = img->pix_c_y+j;
      for (i=0; i < img->mb_cr_size_x; i++)
      {
        pix_c_x = img->pix_c_x+i;
        if(lossless_qpprime)
          enc_picture->imgUV[uv][pix_c_y][pix_c_x]= img->m7[j][i]+img->mpr[j][i];
        else
          enc_picture->imgUV[uv][pix_c_y][pix_c_x]= img->m7[j][i];
      }
    }
  }
  return cr_cbp;
}


// Residue Color Transform
int dct_chroma4x4(int uv, int b8, int b4)
{
  int sign(int a,int b);

  int i,j,i1,j1,ilev,m5[4],m6[4],coeff_ctr;
  int level,scan_pos,run;
  int nonzeroAC;
  Macroblock *currMB = &img->mb_data[img->current_mb_nr];
  int   intra = IS_INTRA (currMB);

  int qp_per,qp_rem,q_bits;
  int qp_c;

  int*  ACLevel = img->cofAC[b8][b4][0];
  int*  ACRun   = img->cofAC[b8][b4][1];

  int **levelscale, **leveloffset;
  int **invlevelscale;

  Boolean lossless_qpprime = ((img->qp + img->bitdepth_luma_qp_scale)==0 && img->lossless_qpprime_flag==1);

  qp_c      = currMB->qp + img->chroma_qp_offset[uv];
  qp_c      = (qp_c < 0)? qp_c : QP_SCALE_CR[qp_c - MIN_QP];

  qp_per    = (qp_c + img->bitdepth_chroma_qp_scale)/6;              
  qp_rem    = (qp_c + img->bitdepth_chroma_qp_scale)%6;              
  q_bits    = Q_BITS+qp_per;

  levelscale = LevelScale4x4Chroma[uv][intra][qp_rem];
  leveloffset = LevelOffset4x4Chroma[uv][intra][qp_per];
  invlevelscale = InvLevelScale4x4Chroma[uv][intra][qp_rem];

  //  Horizontal transform
  if(!lossless_qpprime)
  for (j=0; j < BLOCK_SIZE; j++)
  {
    for (i=0; i < 2; i++)
    {
      i1=3-i;
      m5[i]=img->m7[j][i]+img->m7[j][i1];
      m5[i1]=img->m7[j][i]-img->m7[j][i1];
    }
    img->m7[j][0]=(m5[0]+m5[1]);
    img->m7[j][2]=(m5[0]-m5[1]);
    img->m7[j][1]=m5[3]*2+m5[2];
    img->m7[j][3]=m5[3]-m5[2]*2;
  }

  //  Vertical transform
  if(!lossless_qpprime)
  for (i=0; i < BLOCK_SIZE; i++)
  {
    for (j=0; j < 2; j++)
    {
      j1=3-j;
      m5[j]=img->m7[j][i]+img->m7[j1][i];
      m5[j1]=img->m7[j][i]-img->m7[j1][i];
    }
    img->m7[0][i]=(m5[0]+m5[1]);
    img->m7[2][i]=(m5[0]-m5[1]);
    img->m7[1][i]=m5[3]*2+m5[2];
    img->m7[3][i]=m5[3]-m5[2]*2;
  }

  // Quant

  nonzeroAC=FALSE;

  run=-1;
  scan_pos=0;

  if(lossless_qpprime)
    level = absm(img->m7[0][0]);
  else 
    level =(absm(img->m7[0][0]) * levelscale[0][0] + leveloffset[0][0]) >> q_bits;

  b8 -= 4*(uv+1);
  dc_level_temp[uv][2*(b8 & 0x01)+(b4 & 0x01)][2*(b8 >> 1)+(b4 >> 1)] = sign(level, img->m7[0][0]);

  /* Inverse Quantization */
  if(lossless_qpprime)
  {
    img->m7[0][0] = sign( level, img->m7[0][0]);
  }
  else
  {
    if(qp_per<4)
    {
      img->m7[0][0] = sign( ((level*invlevelscale[0][0]+(1<<(3-qp_per)))>>(4-qp_per)), img->m7[0][0]);
    }
    else
    {
      img->m7[0][0] = sign( ((level*invlevelscale[0][0])<<(qp_per-4)), img->m7[0][0]);
    }
  }

  for (coeff_ctr=1;coeff_ctr < 16;coeff_ctr++)
  {
    i=SNGL_SCAN[coeff_ctr][0];
    j=SNGL_SCAN[coeff_ctr][1];

    run++;
    ilev=0;

    if(lossless_qpprime)
      level = absm (img->m7[j][i]);
    else 
      level = (absm(img->m7[j][i])*levelscale[i][j]+leveloffset[i][j])>>q_bits;
    
    if (level != 0)
    {
      if(i||j) nonzeroAC=TRUE;
      
      ACLevel[scan_pos] = sign(level,img->m7[j][i]);
      ACRun  [scan_pos] = run;
      ++scan_pos;
      run=-1;                     // reset zero level counter
      
      level=sign(level, img->m7[j][i]);
      if(lossless_qpprime)
      {
        ilev=level;
      }
      else if(qp_per<4)
      {
        ilev=(level*invlevelscale[i][j]+(1<<(3-qp_per)))>>(4-qp_per);
      }
      else
      {
        ilev=(level*invlevelscale[i][j])<<(qp_per-4);
      }
    }
    if(!lossless_qpprime)
      img->m7[j][i]=ilev;
  }
  ACLevel[scan_pos] = 0;

  
  //     IDCT.
  //     horizontal
  if(!lossless_qpprime)
  for (j=0; j < BLOCK_SIZE; j++)
  {
    for (i=0; i < BLOCK_SIZE; i++)
    {
      m5[i]=img->m7[j][i];
    }
    m6[0]=(m5[0]+m5[2]);
    m6[1]=(m5[0]-m5[2]);
    m6[2]=(m5[1]>>1)-m5[3];
    m6[3]=m5[1]+(m5[3]>>1);

    for (i=0; i < 2; i++)
    {
      i1=3-i;
      img->m7[j][i]=m6[i]+m6[i1];
      img->m7[j][i1]=m6[i]-m6[i1];
    }
  }

  //  vertical
  if(!lossless_qpprime)
  for (i=0; i < BLOCK_SIZE; i++)
  {
    for (j=0; j < BLOCK_SIZE; j++)
    {
      m5[j]=img->m7[j][i];
    }
    m6[0]=(m5[0]+m5[2]);
    m6[1]=(m5[0]-m5[2]);
    m6[2]=(m5[1]>>1)-m5[3];
    m6[3]=m5[1]+(m5[3]>>1);

    for (j=0; j < 2; j++)
    {
      j1=3-j;
      img->m7[j][i] =(m6[j]+m6[j1]+DQ_ROUND)>>DQ_BITS;
      img->m7[j1][i]=(m6[j]-m6[j1]+DQ_ROUND)>>DQ_BITS;
    }
  }

  return nonzeroAC;
}

// Residue Color Transform
int dct_chroma_DC(int uv, int cr_cbp)
{
  int run, scan_pos, coeff_ctr, level, i, j;
  int*  DCLevel = img->cofDC[uv+1][0];
  int*  DCRun   = img->cofDC[uv+1][1];

  run=-1;
  scan_pos=0;

  for (coeff_ctr=0; coeff_ctr < 16; coeff_ctr++)
  {
    i=SNGL_SCAN[coeff_ctr][0];
    j=SNGL_SCAN[coeff_ctr][1];

    run++;

    level = absm(dc_level[uv][i][j]);

    if (level  != 0)
    {
      cr_cbp=max(1,cr_cbp);
      DCLevel[scan_pos] = sign(level ,dc_level[uv][i][j]);
      DCRun  [scan_pos] = run;
      scan_pos++;
      run=-1;
    }
  }
  DCLevel[scan_pos] = 0;

  return cr_cbp;
}


/*!
 ************************************************************************
 * \brief
 *    The routine performs transform,quantization,inverse transform, adds the diff.
 *    to the prediction and writes the result to the decoded luma frame. Includes the
 *    RD constrained quantization also.
 *
 * \par Input:
 *    block_x,block_y: Block position inside a macro block (0,4,8,12).
 *
 * \par Output:
 *    nonzero: 0 if no levels are nonzero.  1 if there are nonzero levels.              \n
 *    coeff_cost: Counter for nonzero coefficients, used to discard expensive levels.
 *
 *
 ************************************************************************
 */
int dct_luma_sp(int block_x,int block_y,int *coeff_cost)
{
  int sign(int a,int b);

  int i,j,i1,j1,ilev,m5[4],m6[4],coeff_ctr;
  int qp_const,level,scan_pos,run;
  int nonzero;

  int predicted_block[BLOCK_SIZE][BLOCK_SIZE],c_err,qp_const2;
  int qp_per,qp_rem,q_bits;
  int qp_per_sp,qp_rem_sp,q_bits_sp;

  int   pos_x   = block_x >> BLOCK_SHIFT;
  int   pos_y   = block_y >> BLOCK_SHIFT;
  int   b8      = 2*(pos_y >> 1) + (pos_x >> 1);
  int   b4      = 2*(pos_y & 0x01) + (pos_x & 0x01);
  int*  ACLevel = img->cofAC[b8][b4][0];
  int*  ACRun   = img->cofAC[b8][b4][1];
  Macroblock *currMB = &img->mb_data[img->current_mb_nr];
  short is_field_mode = (img->field_picture || ( img->MbaffFrameFlag && currMB->mb_field));

  // For encoding optimization
  int c_err1, c_err2, level1, level2;
  double D_dis1, D_dis2;
  int len, info;
  double lambda_mode   = 0.85 * pow (2, (currMB->qp - SHIFT_QP)/3.0) * 4; 

  qp_per    = (currMB->qp-MIN_QP)/6;
  qp_rem    = (currMB->qp-MIN_QP)%6;
  q_bits    = Q_BITS+qp_per;
  qp_per_sp    = (currMB->qpsp-MIN_QP)/6;
  qp_rem_sp    = (currMB->qpsp-MIN_QP)%6;
  q_bits_sp    = Q_BITS+qp_per_sp;

  qp_const=(1<<q_bits)/6;    // inter
  qp_const2=(1<<q_bits_sp)/2;  //sp_pred

  //  Horizontal transform
  for (j=0; j< BLOCK_SIZE; j++)
    for (i=0; i< BLOCK_SIZE; i++)
    {
      img->m7[j][i]+=img->mpr[j+block_y][i+block_x];
      predicted_block[i][j]=img->mpr[j+block_y][i+block_x];
    }

  for (j=0; j < BLOCK_SIZE; j++)
  {
    for (i=0; i < 2; i++)
    {
      i1=3-i;
      m5[i]=img->m7[j][i]+img->m7[j][i1];
      m5[i1]=img->m7[j][i]-img->m7[j][i1];
    }
    img->m7[j][0]=(m5[0]+m5[1]);
    img->m7[j][2]=(m5[0]-m5[1]);
    img->m7[j][1]=m5[3]*2+m5[2];
    img->m7[j][3]=m5[3]-m5[2]*2;
  }

  //  Vertical transform

  for (i=0; i < BLOCK_SIZE; i++)
  {
    for (j=0; j < 2; j++)
    {
      j1=3-j;
      m5[j]=img->m7[j][i]+img->m7[j1][i];
      m5[j1]=img->m7[j][i]-img->m7[j1][i];
    }
    img->m7[0][i]=(m5[0]+m5[1]);
    img->m7[2][i]=(m5[0]-m5[1]);
    img->m7[1][i]=m5[3]*2+m5[2];
    img->m7[3][i]=m5[3]-m5[2]*2;
  }

  for (j=0; j < BLOCK_SIZE; j++)
  {
    for (i=0; i < 2; i++)
    {
      i1=3-i;
      m5[i]=predicted_block[i][j]+predicted_block[i1][j];
      m5[i1]=predicted_block[i][j]-predicted_block[i1][j];
    }
    predicted_block[0][j]=(m5[0]+m5[1]);
    predicted_block[2][j]=(m5[0]-m5[1]);
    predicted_block[1][j]=m5[3]*2+m5[2];
    predicted_block[3][j]=m5[3]-m5[2]*2;
  }

  //  Vertical transform

  for (i=0; i < BLOCK_SIZE; i++)
  {
    for (j=0; j < 2; j++)
    {
      j1=3-j;
      m5[j]=predicted_block[i][j]+predicted_block[i][j1];
      m5[j1]=predicted_block[i][j]-predicted_block[i][j1];
    }
    predicted_block[i][0]=(m5[0]+m5[1]);
    predicted_block[i][2]=(m5[0]-m5[1]);
    predicted_block[i][1]=m5[3]*2+m5[2];
    predicted_block[i][3]=m5[3]-m5[2]*2;
  }

  // Quant
  nonzero=FALSE;

  run=-1;
  scan_pos=0;
  
  for (coeff_ctr=0;coeff_ctr < 16;coeff_ctr++)     // 8 times if double scan, 16 normal scan
  {

    if (is_field_mode) 
    {  // Alternate scan for field coding
        i=FIELD_SCAN[coeff_ctr][0];
        j=FIELD_SCAN[coeff_ctr][1];
    }
    else 
    {
        i=SNGL_SCAN[coeff_ctr][0];
        j=SNGL_SCAN[coeff_ctr][1];
    }
    
    run++;
    ilev=0;
    
    // decide prediction
    
    // case 1
    level1 = (absm (predicted_block[i][j]) * quant_coef[qp_rem_sp][i][j] + qp_const2) >> q_bits_sp; 
    level1 = (level1 << q_bits_sp) / quant_coef[qp_rem_sp][i][j];                 
    c_err1 = img->m7[j][i]-sign(level1, predicted_block[i][j]);                   
    level1 = (absm (c_err1) * quant_coef[qp_rem][i][j] + qp_const) >> q_bits;
    
    // case 2
    c_err2=img->m7[j][i]-predicted_block[i][j];
    level2 = (absm (c_err2) * quant_coef[qp_rem][i][j] + qp_const) >> q_bits;
    
    // select prediction
    if ((level1 != level2) && (level1 != 0) && (level2 != 0))
    {
      D_dis1 = img->m7[j][i] - ((sign(level1,c_err1)*dequant_coef[qp_rem][i][j]*A[i][j]<< qp_per) >>6) - predicted_block[i][j]; 
      levrun_linfo_inter(level1, run, &len, &info);
      D_dis1 = D_dis1*D_dis1 + lambda_mode * len;
      
      D_dis2 = img->m7[j][i] - ((sign(level2,c_err2)*dequant_coef[qp_rem][i][j]*A[i][j]<< qp_per) >>6) - predicted_block[i][j]; 
      levrun_linfo_inter(level2, run, &len, &info);
      D_dis2 = D_dis2 * D_dis2 + lambda_mode * len;
      
      if (D_dis1 == D_dis2)
        level = (absm(level1) < absm(level2)) ? level1 : level2;
      else
      {
        if (D_dis1 < D_dis2)
          level = level1;
        else
          level = level2;
      }
      c_err = (level == level1) ? c_err1 : c_err2;
    }
    else if (level1 == level2)
    {
      level = level1;
      c_err = c_err1;
    }
    else
    {
      level = (level1 == 0) ? level1 : level2;
      c_err = (level1 == 0) ? c_err1 : c_err2;
    }
    
    if (level != 0)
    {
      nonzero=TRUE;
      if (level > 1)
        *coeff_cost += MAX_VALUE;                // set high cost, shall not be discarded
      else
        *coeff_cost += COEFF_COST[input->disthres][run];
      ACLevel[scan_pos] = sign(level,c_err);
      ACRun  [scan_pos] = run;
      ++scan_pos;
      run=-1;                     // reset zero level counter
      ilev=((sign(level,c_err)*dequant_coef[qp_rem][i][j]*A[i][j]<< qp_per) >>6);
    }
    ilev+=predicted_block[i][j] ; 
    img->m7[j][i] = sign((absm(ilev) * quant_coef[qp_rem_sp][i][j] + qp_const2)>> q_bits_sp, ilev) * dequant_coef[qp_rem_sp][i][j] << qp_per_sp;
  }
  ACLevel[scan_pos] = 0;
  
    
  //     IDCT.
  //     horizontal

  for (j=0; j < BLOCK_SIZE; j++)
  {
    for (i=0; i < BLOCK_SIZE; i++)
    {
      m5[i]=img->m7[j][i];
    }
    m6[0]=(m5[0]+m5[2]);
    m6[1]=(m5[0]-m5[2]);
    m6[2]=(m5[1]>>1)-m5[3];
    m6[3]=m5[1]+(m5[3]>>1);

    for (i=0; i < 2; i++)
    {
      i1=3-i;
      img->m7[j][i]=m6[i]+m6[i1];
      img->m7[j][i1]=m6[i]-m6[i1];
    }
  }

  //  vertical

  for (i=0; i < BLOCK_SIZE; i++)
  {
    for (j=0; j < BLOCK_SIZE; j++)
    {
      m5[j]=img->m7[j][i];
    }
    m6[0]=(m5[0]+m5[2]);
    m6[1]=(m5[0]-m5[2]);
    m6[2]=(m5[1]>>1)-m5[3];
    m6[3]=m5[1]+(m5[3]>>1);

    for (j=0; j < 2; j++)
    {
      j1=3-j;
      img->m7[j][i] =min(img->max_imgpel_value,max(0,(m6[j]+m6[j1]+DQ_ROUND)>>DQ_BITS));
      img->m7[j1][i]=min(img->max_imgpel_value,max(0,(m6[j]-m6[j1]+DQ_ROUND)>>DQ_BITS));
    }
  }

  //  Decoded block moved to frame memory

  for (j=0; j < BLOCK_SIZE; j++)
  for (i=0; i < BLOCK_SIZE; i++)
    enc_picture->imgY[img->pix_y+block_y+j][img->pix_x+block_x+i]=img->m7[j][i];

  return nonzero;
}

/*!
 ************************************************************************
 * \brief
 *    Transform,quantization,inverse transform for chroma.
 *    The main reason why this is done in a separate routine is the
 *    additional 2x2 transform of DC-coeffs. This routine is called
 *    ones for each of the chroma components.
 *
 * \par Input:
 *    uv    : Make difference between the U and V chroma component               \n
 *    cr_cbp: chroma coded block pattern
 *
 * \par Output:
 *    cr_cbp: Updated chroma coded block pattern.
 ************************************************************************
 */
int dct_chroma_sp(int uv,int cr_cbp)
{
  int i,j,i1,j2,ilev,n2,n1,j1,mb_y,coeff_ctr,qp_const,c_err,level ,scan_pos,run;
  int m1[BLOCK_SIZE],m5[BLOCK_SIZE],m6[BLOCK_SIZE];
  int coeff_cost;
  int cr_cbp_tmp;
  int predicted_chroma_block[MB_BLOCK_SIZE>>1][MB_BLOCK_SIZE>>1],qp_const2,mp1[BLOCK_SIZE];
  Macroblock *currMB = &img->mb_data[img->current_mb_nr];
  short is_field_mode = (img->field_picture || ( img->MbaffFrameFlag && currMB->mb_field));

  int qp_per,qp_rem,q_bits;
  int qp_per_sp,qp_rem_sp,q_bits_sp;

  int   b4;
  int*  DCLevel = img->cofDC[uv+1][0];
  int*  DCRun   = img->cofDC[uv+1][1];
  int*  ACLevel;
  int*  ACRun;

  int c_err1, c_err2, level1, level2;
  int len, info;
  double D_dis1, D_dis2;
  double lambda_mode   = 0.85 * pow (2, (currMB->qp -SHIFT_QP)/3.0) * 4; 


  int qpChroma=Clip3(0, 51, currMB->qp + active_pps->chroma_qp_index_offset);
  int qpChromaSP=Clip3(0, 51, currMB->qpsp + active_pps->chroma_qp_index_offset);

  qp_per    = ((qpChroma<0?qpChroma:QP_SCALE_CR[qpChroma])-MIN_QP)/6;
  qp_rem    = ((qpChroma<0?qpChroma:QP_SCALE_CR[qpChroma])-MIN_QP)%6;
  q_bits    = Q_BITS+qp_per;
  qp_const=(1<<q_bits)/6;    // inter
  qp_per_sp    = ((qpChromaSP<0?currMB->qpsp:QP_SCALE_CR[qpChromaSP])-MIN_QP)/6;
  qp_rem_sp    = ((qpChromaSP<0?currMB->qpsp:QP_SCALE_CR[qpChromaSP])-MIN_QP)%6;
  q_bits_sp    = Q_BITS+qp_per_sp;
  qp_const2=(1<<q_bits_sp)/2;  //sp_pred


  for (j=0; j < MB_BLOCK_SIZE>>1; j++)
    for (i=0; i < MB_BLOCK_SIZE>>1; i++)
    {
      img->m7[j][i]+=img->mpr[j][i];
      predicted_chroma_block[i][j]=img->mpr[j][i];
    }

  for (n2=0; n2 <= BLOCK_SIZE; n2 += BLOCK_SIZE)
  {
    for (n1=0; n1 <= BLOCK_SIZE; n1 += BLOCK_SIZE)
    {

      //  Horizontal transform.
      for (j=0; j < BLOCK_SIZE; j++)
      {
        mb_y=n2+j;
        for (i=0; i < 2; i++)
        {
          i1=3-i;
          m5[i]=img->m7[mb_y][i+n1]+img->m7[mb_y][i1+n1];
          m5[i1]=img->m7[mb_y][i+n1]-img->m7[mb_y][i1+n1];
        }
        img->m7[mb_y][n1]  =(m5[0]+m5[1]);
        img->m7[mb_y][n1+2]=(m5[0]-m5[1]);
        img->m7[mb_y][n1+1]=m5[3]*2+m5[2];
        img->m7[mb_y][n1+3]=m5[3]-m5[2]*2;
      }

      //  Vertical transform.

      for (i=0; i < BLOCK_SIZE; i++)
      {
        j1=n1+i;
        for (j=0; j < 2; j++)
        {
          j2=3-j;
          m5[j]=img->m7[n2+j][j1]+img->m7[n2+j2][j1];
          m5[j2]=img->m7[n2+j][j1]-img->m7[n2+j2][j1];
        }
        img->m7[n2+0][j1]=(m5[0]+m5[1]);
        img->m7[n2+2][j1]=(m5[0]-m5[1]);
        img->m7[n2+1][j1]=m5[3]*2+m5[2];
        img->m7[n2+3][j1]=m5[3]-m5[2]*2;
      }
    }
  }
  for (n2=0; n2 <= BLOCK_SIZE; n2 += BLOCK_SIZE)
  {
    for (n1=0; n1 <= BLOCK_SIZE; n1 += BLOCK_SIZE)
    {

      //  Horizontal transform.
      for (j=0; j < BLOCK_SIZE; j++)
      {
        mb_y=n2+j;
        for (i=0; i < 2; i++)
        {
          i1=3-i;
          m5[i]=predicted_chroma_block[i+n1][mb_y]+predicted_chroma_block[i1+n1][mb_y];
          m5[i1]=predicted_chroma_block[i+n1][mb_y]-predicted_chroma_block[i1+n1][mb_y];
        }
        predicted_chroma_block[n1][mb_y]  =(m5[0]+m5[1]);
        predicted_chroma_block[n1+2][mb_y]=(m5[0]-m5[1]);
        predicted_chroma_block[n1+1][mb_y]=m5[3]*2+m5[2];
        predicted_chroma_block[n1+3][mb_y]=m5[3]-m5[2]*2;
      }

      //  Vertical transform.

      for (i=0; i < BLOCK_SIZE; i++)
      {
        j1=n1+i;
        for (j=0; j < 2; j++)
        {
          j2=3-j;
          m5[j]=predicted_chroma_block[j1][n2+j]+predicted_chroma_block[j1][n2+j2];
          m5[j2]=predicted_chroma_block[j1][n2+j]-predicted_chroma_block[j1][n2+j2];
        }
        predicted_chroma_block[j1][n2+0]=(m5[0]+m5[1]);
        predicted_chroma_block[j1][n2+2]=(m5[0]-m5[1]);
        predicted_chroma_block[j1][n2+1]=m5[3]*2+m5[2];
        predicted_chroma_block[j1][n2+3]=m5[3]-m5[2]*2;
      }
    }
  }

  //     2X2 transform of DC coeffs.
  m1[0]=(img->m7[0][0]+img->m7[0][4]+img->m7[4][0]+img->m7[4][4]);
  m1[1]=(img->m7[0][0]-img->m7[0][4]+img->m7[4][0]-img->m7[4][4]);
  m1[2]=(img->m7[0][0]+img->m7[0][4]-img->m7[4][0]-img->m7[4][4]);
  m1[3]=(img->m7[0][0]-img->m7[0][4]-img->m7[4][0]+img->m7[4][4]);

  //     2X2 transform of DC coeffs.
  mp1[0]=(predicted_chroma_block[0][0]+predicted_chroma_block[4][0]+predicted_chroma_block[0][4]+predicted_chroma_block[4][4]);
  mp1[1]=(predicted_chroma_block[0][0]-predicted_chroma_block[4][0]+predicted_chroma_block[0][4]-predicted_chroma_block[4][4]);
  mp1[2]=(predicted_chroma_block[0][0]+predicted_chroma_block[4][0]-predicted_chroma_block[0][4]-predicted_chroma_block[4][4]);
  mp1[3]=(predicted_chroma_block[0][0]-predicted_chroma_block[4][0]-predicted_chroma_block[0][4]+predicted_chroma_block[4][4]);

  run=-1;
  scan_pos=0;

  for (coeff_ctr=0; coeff_ctr < 4; coeff_ctr++)
  {
    run++;
    ilev=0;

  // case 1
    c_err1 = (absm (mp1[coeff_ctr]) * quant_coef[qp_rem_sp][0][0] + 2 * qp_const2) >> (q_bits_sp + 1);
    c_err1 = (c_err1 << (q_bits_sp + 1)) / quant_coef[qp_rem_sp][0][0];
    c_err1 = m1[coeff_ctr] - sign(c_err1, mp1[coeff_ctr]);
    level1 = (absm(c_err1) * quant_coef[qp_rem][0][0] + 2 * qp_const) >> (q_bits+1);

  // case 2
    c_err2 = m1[coeff_ctr] - mp1[coeff_ctr];
    level2 = (absm(c_err2) * quant_coef[qp_rem][0][0] + 2 * qp_const) >> (q_bits+1);

    if (level1 != level2 && level1 != 0 && level2 != 0)
    {
      D_dis1 = m1[coeff_ctr] - ((sign(level1,c_err1)*dequant_coef[qp_rem][0][0]*A[0][0]<< qp_per) >>5)- mp1[coeff_ctr];
      levrun_linfo_c2x2(level1, run, &len, &info);
      D_dis1 = D_dis1 * D_dis1 + lambda_mode * len;
      
      D_dis2 = m1[coeff_ctr] - ((sign(level2,c_err2)*dequant_coef[qp_rem][0][0]*A[0][0]<< qp_per) >>5)- mp1[coeff_ctr];
      levrun_linfo_c2x2(level2, run, &len, &info);
      D_dis2 = D_dis2 * D_dis2 + lambda_mode * len;
      
      if (D_dis1 == D_dis2)
        level = (absm(level1) < absm(level2)) ? level1 : level2;
      else
      {
        if (D_dis1 < D_dis2)
          level = level1;
        else
          level = level2;
      }
      c_err = (level == level1) ? c_err1 : c_err2;
    }
    else if (level1 == level2)
    {
      level = level1;
      c_err = c_err1;
    }
    else
    {
      level = (level1 == 0) ? level1 : level2;
      c_err = (level1 == 0) ? c_err1 : c_err2;
    }
    
    if (input->symbol_mode == UVLC && img->qp < 4) 
    {
      if (level > CAVLC_LEVEL_LIMIT) 
      {
        level = CAVLC_LEVEL_LIMIT;
      }
    }

    if (level  != 0)
    {
      currMB->cbp_blk |= 0xf0000 << (uv << 2) ;  // if one of the 2x2-DC levels is != 0 the coded-bit
      cr_cbp=max(1,cr_cbp);
      DCLevel[scan_pos] = sign(level ,c_err);
      DCRun  [scan_pos] = run;
      scan_pos++;
      run=-1;
      ilev=((sign(level,c_err)*dequant_coef[qp_rem][0][0]*A[0][0]<< qp_per) >>5);
    }
    ilev+= mp1[coeff_ctr];
    m1[coeff_ctr]=sign((absm(ilev)  * quant_coef[qp_rem_sp][0][0] + 2 * qp_const2) >> (q_bits_sp+1), ilev) * dequant_coef[qp_rem_sp][0][0] << qp_per_sp;
  }
  DCLevel[scan_pos] = 0;

  //  Invers transform of 2x2 DC levels

  img->m7[0][0]=(m1[0]+m1[1]+m1[2]+m1[3])/2;
  img->m7[0][4]=(m1[0]-m1[1]+m1[2]-m1[3])/2;
  img->m7[4][0]=(m1[0]+m1[1]-m1[2]-m1[3])/2;
  img->m7[4][4]=(m1[0]-m1[1]-m1[2]+m1[3])/2;

  //     Quant of chroma AC-coeffs.
  coeff_cost=0;
  cr_cbp_tmp=0;

  for (n2=0; n2 <= BLOCK_SIZE; n2 += BLOCK_SIZE)
  {
    for (n1=0; n1 <= BLOCK_SIZE; n1 += BLOCK_SIZE)
    {
      b4      = 2*(n2 >> 2) + (n1 >> 2);
      ACLevel = img->cofAC[uv+4][b4][0];
      ACRun   = img->cofAC[uv+4][b4][1];

      run      = -1;
      scan_pos =  0;

      for (coeff_ctr=1; coeff_ctr < 16; coeff_ctr++)// start change rd_quant
      {

        if (is_field_mode) 
        {  // Alternate scan for field coding
          i=FIELD_SCAN[coeff_ctr][0];
          j=FIELD_SCAN[coeff_ctr][1];
        }
        else 
        {
          i=SNGL_SCAN[coeff_ctr][0];
          j=SNGL_SCAN[coeff_ctr][1];
        }
        ++run;
        ilev=0;

    // quantization on prediction
    c_err1 = (absm(predicted_chroma_block[n1+i][n2+j]) * quant_coef[qp_rem_sp][i][j] + qp_const2) >> q_bits_sp;
    c_err1 = (c_err1 << q_bits_sp) / quant_coef[qp_rem_sp][i][j];
    c_err1 = img->m7[n2+j][n1+i] - sign(c_err1, predicted_chroma_block[n1+i][n2+j]);
    level1 = (absm(c_err1) * quant_coef[qp_rem][i][j] + qp_const) >> q_bits;

    // no quantization on prediction
    c_err2 = img->m7[n2+j][n1+i] - predicted_chroma_block[n1+i][n2+j];
    level2 = (absm(c_err2) * quant_coef[qp_rem][i][j] + qp_const) >> q_bits;

    if (level1 != level2 && level1 != 0 && level2 != 0)
    {
      D_dis1 = img->m7[n2+j][n1+i] - ((sign(level1,c_err1)*dequant_coef[qp_rem][i][j]*A[i][j]<< qp_per) >>6) - predicted_chroma_block[n1+i][n2+j]; 

      levrun_linfo_inter(level1, run, &len, &info);
      D_dis1 = D_dis1 * D_dis1 + lambda_mode * len;

      D_dis2 = img->m7[n2+j][n1+i] - ((sign(level2,c_err2)*dequant_coef[qp_rem][i][j]*A[i][j]<< qp_per) >>6) - predicted_chroma_block[n1+i][n2+j]; 
      levrun_linfo_inter(level2, run, &len, &info);
      D_dis2 = D_dis2 * D_dis2 + lambda_mode * len;
      
      if (D_dis1 == D_dis2)
        level = (absm(level1) < absm(level2)) ? level1 : level2;
      else
      {
        if (D_dis1 < D_dis2)
          level = level1;
        else
          level = level2;
      }
      c_err = (level == level1) ? c_err1 : c_err2;
    }
    else if (level1 == level2)
    {
      level = level1;
      c_err = c_err1;
    }
    else
    {
      level = (level1 == 0) ? level1 : level2;
      c_err = (level1 == 0) ? c_err1 : c_err2;
    }

        if (level  != 0)
        {
          currMB->cbp_blk |=  1 << (16 + (uv << 2) + ((n2 >> 1) + (n1 >> 2))) ;
          if (level > 1)
            coeff_cost += MAX_VALUE;                // set high cost, shall not be discarded
          else
            coeff_cost += COEFF_COST[input->disthres][run];

          cr_cbp_tmp=2;
          ACLevel[scan_pos] = sign(level,c_err);
          ACRun  [scan_pos] = run;
          ++scan_pos;
          run=-1;
          ilev=((sign(level,c_err)*dequant_coef[qp_rem][i][j]*A[i][j]<< qp_per) >>6);
        }
        ilev+=predicted_chroma_block[n1+i][n2+j];
        img->m7[n2+j][n1+i] = sign((absm(ilev) * quant_coef[qp_rem_sp][i][j] + qp_const2) >> q_bits_sp,ilev) * dequant_coef[qp_rem_sp][i][j] << qp_per_sp;
      }
      ACLevel[scan_pos] = 0;
    }
  }

  // * reset chroma coeffs

  if(cr_cbp_tmp==2)
      cr_cbp=2;
  //     IDCT.

      //     Horizontal.
  for (n2=0; n2 <= BLOCK_SIZE; n2 += BLOCK_SIZE)
  {
    for (n1=0; n1 <= BLOCK_SIZE; n1 += BLOCK_SIZE)
    {
      for (j=0; j < BLOCK_SIZE; j++)
      {
        for (i=0; i < BLOCK_SIZE; i++)
        {
          m5[i]=img->m7[n2+j][n1+i];
        }
        m6[0]=(m5[0]+m5[2]);
        m6[1]=(m5[0]-m5[2]);
        m6[2]=(m5[1]>>1)-m5[3];
        m6[3]=m5[1]+(m5[3]>>1);

        for (i=0; i < 2; i++)
        {
          i1=3-i;
          img->m7[n2+j][n1+i]=m6[i]+m6[i1];
          img->m7[n2+j][n1+i1]=m6[i]-m6[i1];
        }
      }

      //     Vertical.
      for (i=0; i < BLOCK_SIZE; i++)
      {
        for (j=0; j < BLOCK_SIZE; j++)
        {
          m5[j]=img->m7[n2+j][n1+i];
        }
        m6[0]=(m5[0]+m5[2]);
        m6[1]=(m5[0]-m5[2]);
        m6[2]=(m5[1]>>1)-m5[3];
        m6[3]=m5[1]+(m5[3]>>1);

        for (j=0; j < 2; j++)
        {
          j2=3-j;
          img->m7[n2+j][n1+i] =min(img->max_imgpel_value_uv,max(0,(m6[j]+m6[j2]+DQ_ROUND)>>DQ_BITS));
          img->m7[n2+j2][n1+i]=min(img->max_imgpel_value_uv,max(0,(m6[j]-m6[j2]+DQ_ROUND)>>DQ_BITS));
        }
      }
    }
  }

  //  Decoded block moved to memory
  for (j=0; j < BLOCK_SIZE*2; j++)
    for (i=0; i < BLOCK_SIZE*2; i++)
    {
      enc_picture->imgUV[uv][img->pix_c_y+j][img->pix_c_x+i]= img->m7[j][i];
    }

  return cr_cbp;
}

/*!
 ************************************************************************
 * \brief
 *    The routine performs transform,quantization,inverse transform, adds the diff.
 *    to the prediction and writes the result to the decoded luma frame. Includes the
 *    RD constrained quantization also.
 *
 * \par Input:
 *    block_x,block_y: Block position inside a macro block (0,4,8,12).
 *
 * \par Output:
 *    nonzero: 0 if no levels are nonzero.  1 if there are nonzero levels.            \n
 *    coeff_cost: Counter for nonzero coefficients, used to discard expencive levels.
 ************************************************************************
 */
void copyblock_sp(int block_x,int block_y)
{
  int sign(int a,int b);

  int i,j,i1,j1,m5[4],m6[4];

  Macroblock *currMB = &img->mb_data[img->current_mb_nr];

  int predicted_block[BLOCK_SIZE][BLOCK_SIZE];
  int qp_per = (currMB->qpsp-MIN_QP)/6;
  int qp_rem = (currMB->qpsp-MIN_QP)%6;
  int q_bits    = Q_BITS+qp_per;
  int qp_const2=(1<<q_bits)/2;  //sp_pred

  //  Horizontal transform
  for (j=0; j< BLOCK_SIZE; j++)
    for (i=0; i< BLOCK_SIZE; i++)
    {
      predicted_block[i][j]=img->mpr[j+block_y][i+block_x];
    }

  for (j=0; j < BLOCK_SIZE; j++)
  {
    for (i=0; i < 2; i++)
    {
      i1=3-i;
      m5[i]=predicted_block[i][j]+predicted_block[i1][j];
      m5[i1]=predicted_block[i][j]-predicted_block[i1][j];
    }
    predicted_block[0][j]=(m5[0]+m5[1]);
    predicted_block[2][j]=(m5[0]-m5[1]);
    predicted_block[1][j]=m5[3]*2+m5[2];
    predicted_block[3][j]=m5[3]-m5[2]*2;
  }

  //  Vertival transform

  for (i=0; i < BLOCK_SIZE; i++)
  {
    for (j=0; j < 2; j++)
    {
      j1=3-j;
      m5[j]=predicted_block[i][j]+predicted_block[i][j1];
      m5[j1]=predicted_block[i][j]-predicted_block[i][j1];
    }
    predicted_block[i][0]=(m5[0]+m5[1]);
    predicted_block[i][2]=(m5[0]-m5[1]);
    predicted_block[i][1]=m5[3]*2+m5[2];
    predicted_block[i][3]=m5[3]-m5[2]*2;
  }

  // Quant
  for (j=0;j < BLOCK_SIZE; j++)
    for (i=0; i < BLOCK_SIZE; i++)
       img->m7[j][i]=sign((absm(predicted_block[i][j])* quant_coef[qp_rem][i][j]+qp_const2)>> q_bits,predicted_block[i][j])*dequant_coef[qp_rem][i][j]<<qp_per;

  //     IDCT.
  //     horizontal

  for (j=0;j<BLOCK_SIZE;j++)
  {
    for (i=0;i<BLOCK_SIZE;i++)
    {
      m5[i]=img->m7[j][i];
    }
    m6[0]=(m5[0]+m5[2]);
    m6[1]=(m5[0]-m5[2]);
    m6[2]=(m5[1]>>1)-m5[3];
    m6[3]=m5[1]+(m5[3]>>1);

    for (i=0;i<2;i++)
    {
      i1=3-i;
      img->m7[j][i]=m6[i]+m6[i1];
      img->m7[j][i1]=m6[i]-m6[i1];
    }
  }
  // vertical
  for (i=0;i<BLOCK_SIZE;i++)
  {
    for (j=0;j<BLOCK_SIZE;j++)
      m5[j]=img->m7[j][i];

    m6[0]=(m5[0]+m5[2]);
    m6[1]=(m5[0]-m5[2]);
    m6[2]=(m5[1]>>1)-m5[3];
    m6[3]=m5[1]+(m5[3]>>1);

    for (j=0;j<2;j++)
    {
      j1=3-j;
      img->m7[j][i] =min(img->max_imgpel_value,max(0,(m6[j]+m6[j1]+DQ_ROUND)>>DQ_BITS));
      img->m7[j1][i]=min(img->max_imgpel_value,max(0,(m6[j]-m6[j1]+DQ_ROUND)>>DQ_BITS));
    }
  }

  //  Decoded block moved to frame memory

  for (j=0; j < BLOCK_SIZE; j++)
    for (i=0; i < BLOCK_SIZE; i++)
      enc_picture->imgY[img->pix_y+block_y+j][img->pix_x+block_x+i]=img->m7[j][i];
}



int writeIPCMBytes(Bitstream *currStream)
{
  int i,j, jj;
  int len = 0, uv;
  int             mb_nr     = img->current_mb_nr;
  Macroblock*     currMB    = &img->mb_data[mb_nr];
  SyntaxElement  *currSE    = &img->MB_SyntaxElements[currMB->currSEnr];
  
  
  for (j=0;j<16;j++)
  {
    jj = img->pix_y+j;
    for (i=0;i<16;i++)
    {
      currSE->len = img->bitdepth_luma;  
      len += currSE->len;
      currSE->bitpattern = enc_picture->imgY[jj][img->pix_x+i];
      writeSyntaxElement2Buf_Fixed(currSE, currStream);
    }
  }
  
  for (uv = 0; uv < 2; uv ++)
  {
    for (j=0;j<img->mb_cr_size_y;j++)
    {
      jj = img->pix_c_y+j;
      for (i=0;i<img->mb_cr_size_x;i++)
      {
        currSE->len = img->bitdepth_chroma;
        len += currSE->len;
        currSE->bitpattern = enc_picture->imgUV[uv][jj][img->pix_c_x+i];
        writeSyntaxElement2Buf_Fixed(currSE, currStream);
      }
    }
  }  
  return len;
}

int writePCMByteAlign(Bitstream *currStream)
{
  int len = 0;
  if (currStream->bits_to_go < 8)
  { // trailing bits to process
    len = 8 - currStream->bits_to_go;
    currStream->byte_buf = (currStream->byte_buf <<currStream->bits_to_go) | (0xff >> (8 - currStream->bits_to_go));
    stats->bit_use_stuffingBits[img->type]+=currStream->bits_to_go;
    currStream->streamBuffer[currStream->byte_pos++]=currStream->byte_buf;
    currStream->bits_to_go = 8;
  }
  return len;
}

