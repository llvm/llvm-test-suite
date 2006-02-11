/*!
 ***************************************************************************
 * \file transform8x8.c
 *
 * \brief
 *    8x8 transform functions
 *
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details) 
 *    - Yuri Vatis                      <vatis@hhi.de>
 *    - Jan Muenster                    <muenster@hhi.de>
 *    - Lowell Winger                   <lwinger@lsil.com>
 * \date
 *    12. October 2003
 **************************************************************************
 */

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#include "global.h"

#include "image.h"
#include "mb_access.h"
#include "elements.h"
#include "cabac.h"
#include "vlc.h"

#include "transform8x8.h"

int   cofAC8x8_chroma[2][4][2][18];


#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))


const int quant_coef8[6][8][8] = 
{
  { 
    {13107, 12222,  16777,  12222,  13107,  12222,  16777,  12222},
    {12222, 11428,  15481,  11428,  12222,  11428,  15481,  11428},
    {16777, 15481,  20972,  15481,  16777,  15481,  20972,  15481},
    {12222, 11428,  15481,  11428,  12222,  11428,  15481,  11428},
    {13107, 12222,  16777,  12222,  13107,  12222,  16777,  12222},
    {12222, 11428,  15481,  11428,  12222,  11428,  15481,  11428},
    {16777, 15481,  20972,  15481,  16777,  15481,  20972,  15481},
    {12222, 11428,  15481,  11428,  12222,  11428,  15481,  11428}
  },
  {
    {11916, 11058,  14980,  11058,  11916,  11058,  14980,  11058},
    {11058, 10826,  14290,  10826,  11058,  10826,  14290,  10826},
    {14980, 14290,  19174,  14290,  14980,  14290,  19174,  14290},
    {11058, 10826,  14290,  10826,  11058,  10826,  14290,  10826},
    {11916, 11058,  14980,  11058,  11916,  11058,  14980,  11058},
    {11058, 10826,  14290,  10826,  11058,  10826,  14290,  10826},
    {14980, 14290,  19174,  14290,  14980,  14290,  19174,  14290},
    {11058, 10826,  14290,  10826,  11058,  10826,  14290,  10826}
  },
  {
    {10082, 9675,   12710,  9675,   10082,  9675, 12710,  9675},
    {9675,  8943,   11985,  8943,   9675,   8943, 11985,  8943},
    {12710, 11985,  15978,  11985,  12710,  11985,  15978,  11985},
    {9675,  8943,   11985,  8943,   9675,   8943, 11985,  8943},
    {10082, 9675,   12710,  9675,   10082,  9675, 12710,  9675},
    {9675,  8943,   11985,  8943,   9675, 8943, 11985,  8943},
    {12710, 11985,  15978,  11985,  12710,  11985,  15978,  11985},
    {9675,  8943,   11985,  8943,   9675, 8943, 11985,  8943}
  },
  {
    {9362,  8931, 11984,  8931, 9362, 8931, 11984,  8931},
    {8931,  8228, 11259,  8228, 8931, 8228, 11259,  8228},
    {11984, 11259,  14913,  11259,  11984,  11259,  14913,  11259},
    {8931,  8228, 11259,  8228, 8931, 8228, 11259,  8228},
    {9362,  8931, 11984,  8931, 9362, 8931, 11984,  8931},
    {8931,  8228, 11259,  8228, 8931, 8228, 11259,  8228},
    {11984, 11259,  14913,  11259,  11984,  11259,  14913,  11259},
    {8931,  8228, 11259,  8228, 8931, 8228, 11259,  8228}
  },
  {
    {8192,  7740, 10486,  7740, 8192, 7740, 10486,  7740},
    {7740,  7346, 9777, 7346, 7740, 7346, 9777, 7346},
    {10486, 9777, 13159,  9777, 10486,  9777, 13159,  9777},
    {7740,  7346, 9777, 7346, 7740, 7346, 9777, 7346},
    {8192,  7740, 10486,  7740, 8192, 7740, 10486,  7740},
    {7740,  7346, 9777, 7346, 7740, 7346, 9777, 7346},
    {10486, 9777, 13159,  9777, 10486,  9777, 13159,  9777},
    {7740,  7346, 9777, 7346, 7740, 7346, 9777, 7346}
  },
  {
    {7282,  6830, 9118, 6830, 7282, 6830, 9118, 6830},
    {6830,  6428, 8640, 6428, 6830, 6428, 8640, 6428},
    {9118,  8640, 11570,  8640, 9118, 8640, 11570,  8640},
    {6830,  6428, 8640, 6428, 6830, 6428, 8640, 6428},
    {7282,  6830, 9118, 6830, 7282, 6830, 9118, 6830},
    {6830,  6428, 8640, 6428, 6830, 6428, 8640, 6428},
    {9118,  8640, 11570,  8640, 9118, 8640, 11570,  8640},
    {6830,  6428, 8640, 6428, 6830, 6428, 8640, 6428}
  }
};


const int dequant_coef8[6][8][8] = 
{
  {
    {20,  19, 25, 19, 20, 19, 25, 19},
    {19,  18, 24, 18, 19, 18, 24, 18},
    {25,  24, 32, 24, 25, 24, 32, 24},
    {19,  18, 24, 18, 19, 18, 24, 18},
    {20,  19, 25, 19, 20, 19, 25, 19},
    {19,  18, 24, 18, 19, 18, 24, 18},
    {25,  24, 32, 24, 25, 24, 32, 24},
    {19,  18, 24, 18, 19, 18, 24, 18}
  },
  {
    {22,  21, 28, 21, 22, 21, 28, 21},
    {21,  19, 26, 19, 21, 19, 26, 19},
    {28,  26, 35, 26, 28, 26, 35, 26},
    {21,  19, 26, 19, 21, 19, 26, 19},
    {22,  21, 28, 21, 22, 21, 28, 21},
    {21,  19, 26, 19, 21, 19, 26, 19},
    {28,  26, 35, 26, 28, 26, 35, 26},
    {21,  19, 26, 19, 21, 19, 26, 19}
  },
  {
    {26,  24, 33, 24, 26, 24, 33, 24},
    {24,  23, 31, 23, 24, 23, 31, 23},
    {33,  31, 42, 31, 33, 31, 42, 31},
    {24,  23, 31, 23, 24, 23, 31, 23},
    {26,  24, 33, 24, 26, 24, 33, 24},
    {24,  23, 31, 23, 24, 23, 31, 23},
    {33,  31, 42, 31, 33, 31, 42, 31},
    {24,  23, 31, 23, 24, 23, 31, 23}
  },
  {
    {28,  26, 35, 26, 28, 26, 35, 26},
    {26,  25, 33, 25, 26, 25, 33, 25},
    {35,  33, 45, 33, 35, 33, 45, 33},
    {26,  25, 33, 25, 26, 25, 33, 25},
    {28,  26, 35, 26, 28, 26, 35, 26},
    {26,  25, 33, 25, 26, 25, 33, 25},
    {35,  33, 45, 33, 35, 33, 45, 33},
    {26,  25, 33, 25, 26, 25, 33, 25}
  },
  {
    {32,  30, 40, 30, 32, 30, 40, 30},
    {30,  28, 38, 28, 30, 28, 38, 28},
    {40,  38, 51, 38, 40, 38, 51, 38},
    {30,  28, 38, 28, 30, 28, 38, 28},
    {32,  30, 40, 30, 32, 30, 40, 30},
    {30,  28, 38, 28, 30, 28, 38, 28},
    {40,  38, 51, 38, 40, 38, 51, 38},
    {30,  28, 38, 28, 30, 28, 38, 28}
  },
  {
    {36,  34, 46, 34, 36, 34, 46, 34},
    {34,  32, 43, 32, 34, 32, 43, 32},
    {46,  43, 58, 43, 46, 43, 58, 43},
    {34,  32, 43, 32, 34, 32, 43, 32},
    {36,  34, 46, 34, 36, 34, 46, 34},
    {34,  32, 43, 32, 34, 32, 43, 32},
    {46,  43, 58, 43, 46, 43, 58, 43},
    {34,  32, 43, 32, 34, 32, 43, 32}
  }

};


//! single scan pattern
const byte SNGL_SCAN8x8[64][2] = {
  {0,0}, {1,0}, {0,1}, {0,2}, {1,1}, {2,0}, {3,0}, {2,1}, 
  {1,2}, {0,3}, {0,4}, {1,3}, {2,2}, {3,1}, {4,0}, {5,0},
  {4,1}, {3,2}, {2,3}, {1,4}, {0,5}, {0,6}, {1,5}, {2,4},
  {3,3}, {4,2}, {5,1}, {6,0}, {7,0}, {6,1}, {5,2}, {4,3},
  {3,4}, {2,5}, {1,6}, {0,7}, {1,7}, {2,6}, {3,5}, {4,4},
  {5,3}, {6,2}, {7,1}, {7,2}, {6,3}, {5,4}, {4,5}, {3,6},
  {2,7}, {3,7}, {4,6}, {5,5}, {6,4}, {7,3}, {7,4}, {6,5},
  {5,6}, {4,7}, {5,7}, {6,6}, {7,5}, {7,6}, {6,7}, {7,7}
};


//! field scan pattern
const byte FIELD_SCAN8x8[64][2] = {   // 8x8
  {0,0}, {0,1}, {0,2}, {1,0}, {1,1}, {0,3}, {0,4}, {1,2}, 
  {2,0}, {1,3}, {0,5}, {0,6}, {0,7}, {1,4}, {2,1}, {3,0}, 
  {2,2}, {1,5}, {1,6}, {1,7}, {2,3}, {3,1}, {4,0}, {3,2}, 
  {2,4}, {2,5}, {2,6}, {2,7}, {3,3}, {4,1}, {5,0}, {4,2}, 
  {3,4}, {3,5}, {3,6}, {3,7}, {4,3}, {5,1}, {6,0}, {5,2}, 
  {4,4}, {4,5}, {4,6}, {4,7}, {5,3}, {6,1}, {6,2}, {5,4}, 
  {5,5}, {5,6}, {5,7}, {6,3}, {7,0}, {7,1}, {6,4}, {6,5}, 
  {6,6}, {6,7}, {7,2}, {7,3}, {7,4}, {7,5}, {7,6}, {7,7}
};


//! array used to find expensive coefficients
const byte COEFF_COST8x8[2][64] =
{
  {3,3,3,3,2,2,2,2,2,2,2,2,1,1,1,1,
  1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
   9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
   9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
   9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9}
};

/*! 
 *************************************************************************************
 * \brief
 *    8x8 Intra mode decision for a macroblock
 *************************************************************************************
 */

int Mode_Decision_for_new_Intra8x8Macroblock (double lambda, int *min_cost)
{
  int  cbp=0, b8, cost8x8;

  *min_cost = (int)floor(6.0 * lambda + 0.4999);

  for (b8=0; b8<4; b8++)
  {
    if (Mode_Decision_for_new_8x8IntraBlocks (b8, lambda, &cost8x8))
    {
      cbp |= (1<<b8);
    }
    *min_cost += cost8x8;
  }

  return cbp;
}

/*! 
 *************************************************************************************
 * \brief
 *    8x8 Intra mode decision for a macroblock
 *************************************************************************************
 */

int Mode_Decision_for_new_8x8IntraBlocks (int b8, double lambda, int *min_cost)
{
  int     ipmode, best_ipmode = 0, i, j, k, x, y, cost, dummy;
  int     c_nz, nonzero = 0, diff[64];
  imgpel  rec8x8[8][8];
  double  rdcost = 0.0;
  int     block4x4_x, block4x4_y;
  int     block_x     = 8*(b8 & 0x01);
  int     block_y     = 8*(b8 >> 1);
  int     pic_pix_x   = img->pix_x+block_x;
  int     pic_pix_y   = img->pix_y+block_y;
  int     pic_opix_x   = img->opix_x+block_x;
  int     pic_opix_y   = img->opix_y+block_y;
  int     pic_block_x = pic_pix_x/4;
  int     pic_block_y = pic_pix_y/4;
  double  min_rdcost  = 1e30;
  imgpel    **imgY_orig  = imgY_org;
  extern  int ****cofAC8x8; 
  int fadjust8x8[2][16][16];
  int left_available, up_available, all_available;

  char   upMode;
  char   leftMode;
  int     mostProbableMode;  

  PixelPos left_block;
  PixelPos top_block;

  // Residue Color Transform
  int residue_R, residue_G, residue_B;
  int rate, temp, b4;
  int64 distortion;
  Macroblock     *currMB       = &img->mb_data[img->current_mb_nr];
  int c_ipmode = currMB->c_ipred_mode;
  int rec8x8_c[2][4][4][4];

  getLuma4x4Neighbour(img->current_mb_nr, block_x/4, block_y/4, -1,  0, &left_block);
  getLuma4x4Neighbour(img->current_mb_nr, block_x/4, block_y/4,  0, -1, &top_block);

  if (input->UseConstrainedIntraPred)
  {
    top_block.available  = top_block.available ? img->intra_block [top_block.mb_addr] : 0;
    left_block.available = left_block.available ? img->intra_block [left_block.mb_addr] : 0;
  }

  if(b8 >> 1)
    upMode    =  top_block.available ? img->ipredmode8x8[top_block.pos_y ][top_block.pos_x ] : -1; 
  else
    upMode    =  top_block.available ? img->ipredmode   [top_block.pos_y ][top_block.pos_x ] : -1;
  if(b8 & 0x01)
    leftMode  = left_block.available ? img->ipredmode8x8[left_block.pos_y][left_block.pos_x] : -1;
  else
    leftMode  = left_block.available ? img->ipredmode[left_block.pos_y][left_block.pos_x] : -1;

  mostProbableMode  = (upMode < 0 || leftMode < 0) ? DC_PRED : upMode < leftMode ? upMode : leftMode;

  *min_cost = INT_MAX;

  //===== INTRA PREDICTION FOR 8x8 BLOCK =====
  intrapred_luma8x8 (pic_pix_x, pic_pix_y, &left_available, &up_available, &all_available);

  //===== LOOP OVER ALL 8x8 INTRA PREDICTION MODES =====
  for (ipmode=0; ipmode<NO_INTRA_PMODE; ipmode++)
  {
    if( (ipmode==DC_PRED) ||
        ((ipmode==VERT_PRED||ipmode==VERT_LEFT_PRED||ipmode==DIAG_DOWN_LEFT_PRED) && up_available ) ||
        ((ipmode==HOR_PRED||ipmode==HOR_UP_PRED) && left_available ) ||
        (all_available) )
    {
      if (!input->rdopt)
      {
        for (k=j=0; j<8; j++)
          for (i=0; i<8; i++, k++)
          {
            diff[k] = imgY_orig[pic_opix_y+j][pic_opix_x+i] - img->mprr_3[ipmode][j][i];
          }
        cost  = (ipmode == mostProbableMode) ? 0 : (int)floor(4 * lambda );
        cost += SATD8X8 (diff, input->hadamard);
        if (cost < *min_cost)
        {
          best_ipmode = ipmode;
          *min_cost   = cost;
        }
      }
      else
      {
        // Residue Color Transform
        if(!img->residue_transform_flag)
        {
          // get prediction and prediction error
          for (j=0; j<8; j++)
          {
            memcpy(&img->mpr[block_y+j][block_x],img->mprr_3[ipmode][j], 8 * sizeof(imgpel));
            for (i=0; i<8; i++)
            {
              img->m7[j][i] = imgY_orig[pic_opix_y+j][pic_opix_x+i] - img->mprr_3[ipmode][j][i];
            }
          }
          //===== store the coding state =====
          //store_coding_state_cs_cm();
          // get and check rate-distortion cost
          
          if ((rdcost = RDCost_for_8x8IntraBlocks (&c_nz, b8, ipmode, lambda, min_rdcost, mostProbableMode)) < min_rdcost)
          {
            //--- set coefficients ---
            for(k=0; k<4; k++) // do 4x now
            {
              for (j=0; j<2; j++)
                memcpy(cofAC8x8[b8][k][j],img->cofAC[b8][k][j], 65 * sizeof(int));
            }
            
            //--- set reconstruction ---
            for (y=0; y<8; y++)
            {
              memcpy(rec8x8[y],&enc_picture->imgY[pic_pix_y+y][pic_pix_x], 8 * sizeof(imgpel));
            }

            if (img->AdaptiveRounding)
            {
              for (j=block_y; j<block_y + 8; j++)
                memcpy(&fadjust8x8[1][j][block_x],&img->fadjust8x8[1][j][block_x], 8 * sizeof(int));
            }
            
            //--- flag if dct-coefficients must be coded ---
            nonzero = c_nz;
            
            //--- set best mode update minimum cost ---
            min_rdcost  = rdcost;
            best_ipmode = ipmode;
          }
          reset_coding_state_cs_cm();  
        }
        else
        {

          for (j=0; j<8; j++)
          for (i=0; i<8; i++)
          {
            residue_B = imgUV_org[0][pic_opix_y+j][pic_opix_x+i] - img->mprr_c[0][c_ipmode][block_y+j][block_x+i];
            residue_G = imgY_org[pic_opix_y+j][pic_opix_x+i] - img->mprr_3[ipmode][j][i];
            residue_R = imgUV_org[1][pic_opix_y+j][pic_opix_x+i] - img->mprr_c[1][c_ipmode][block_y+j][block_x+i];

            /* Forward Residue Transform */
            resTrans_R[j][i] = residue_R-residue_B;
            temp = residue_B+(resTrans_R[j][i]>>1);
            resTrans_B[j][i] = residue_G-temp;
            resTrans_G[j][i] = temp+(resTrans_B[j][i]>>1);
          }

          for (j=0; j<8; j++)
          for (i=0; i<8; i++)
          {
            img->m7[j][i]  = resTrans_G[j][i];
          }

          //store_coding_state_cs_cm();
          rate = (int) RDCost_for_8x8IntraBlocks (&c_nz, b8, ipmode, lambda, min_rdcost, mostProbableMode);
          reset_coding_state_cs_cm();

          for (j=0; j<8; j++)
            for (i=0; i<8; i++)
            {
              rec_resG[j][i] = img->m7[j][i];            
            }


          for(b4=0;b4<4;b4++)
          {
            
            block4x4_x = 4*(b4 & 0x01);
            block4x4_y = 4*(b4 >> 1);
            
            for (j=0; j<4; j++)
              for (i=0; i<4; i++)
              {
                img->m7[j][i]  = resTrans_B[j+block4x4_y][i+block4x4_x];
              }
            rate += RDCost_for_4x4Blocks_Chroma (b8+4, b4, 0);
            for (j=0; j<4; j++)
              for (i=0; i<4; i++)
              {
                rec_resB[j+block4x4_y][i+block4x4_x] = img->m7[j][i];
                img->m7[j][i]  = resTrans_R[j+block4x4_y][i+block4x4_x];
              }
            rate += RDCost_for_4x4Blocks_Chroma (b8+8, b4, 1);
            for (j=0; j<4; j++)
              for (i=0; i<4; i++)
              {
                rec_resR[j+block4x4_y][i+block4x4_x] = img->m7[j][i];
              }
          }
          reset_coding_state_cs_cm();

          for (j=0; j<8; j++)
          {
            for (i=0; i<8; i++)
            {
              /* Inverse Residue Transform */
              temp      = rec_resG[j][i]-(rec_resB[j][i]>>1);
              residue_G = rec_resB[j][i]+temp;
              residue_B = temp - (rec_resR[j][i]>>1);
              residue_R = residue_B+rec_resR[j][i];
              enc_picture->imgUV[0][pic_pix_y+j][pic_pix_x+i] = min(img->max_imgpel_value_uv,max(0,residue_B+(int)img->mprr_c[0][c_ipmode][block_y+j][block_x+i]));
              enc_picture->imgY[pic_pix_y+j][pic_pix_x+i]     = min(img->max_imgpel_value,max(0,residue_G+(int)img->mprr_3[ipmode][j][i]));
              enc_picture->imgUV[1][pic_pix_y+j][pic_pix_x+i] = min(img->max_imgpel_value_uv,max(0,residue_R+(int)img->mprr_c[1][c_ipmode][block_y+j][block_x+i]));
            }
          }
          //===== get distortion (SSD) of 8x8 block =====
          distortion = 0;
          for (y=0; y<8; y++)
            for (x=pic_pix_x; x<pic_pix_x+8; x++)
            {
              distortion += img->quad[imgY_org    [pic_pix_y+y][x] - enc_picture->imgY    [pic_pix_y+y][x]];
              distortion += img->quad[imgUV_org[0][pic_pix_y+y][x] - enc_picture->imgUV[0][pic_pix_y+y][x]];
              distortion += img->quad[imgUV_org[1][pic_pix_y+y][x] - enc_picture->imgUV[1][pic_pix_y+y][x]];
            }
          rdcost = (double)distortion + lambda*(double)rate;

          if (rdcost < min_rdcost)
          {
            //--- set coefficients ---
            for (j=0; j<2; j++)
              for (i=0; i<65;i++)  
                for(k=0; k<4; k++) //do 4x now
                  cofAC8x8[b8][k][j][i]=img->cofAC[b8][k][j][i]; //k vs 0

            for(b4=0; b4<4; b4++)
            {
              block4x4_x = 4*(b4 & 0x01);
              block4x4_y = 4*(b4 >> 1);

              for (j=0; j<2; j++)
                for (i=0; i<18;i++)  cofAC8x8_chroma[0][b4][j][i]=img->cofAC[b8+4][b4][j][i];
              for (j=0; j<2; j++)
                for (i=0; i<18;i++)  cofAC8x8_chroma[1][b4][j][i]=img->cofAC[b8+8][b4][j][i];

              for (i=0; i<2; i++)
              { //uv
                dc_level[i][2*(b8 & 0x01)+(b4 & 0x01)][2*(b8 >> 1)+(b4 >> 1)] = dc_level_temp[i][2*(b8 & 0x01)+(b4 & 0x01)][2*(b8 >> 1)+(b4 >> 1)];
                cbp_chroma_block[i][2*(b8 & 0x01)+(b4 & 0x01)][2*(b8 >> 1)+(b4 >> 1)] = cbp_chroma_block_temp[i][2*(b8 & 0x01)+(b4 & 0x01)][2*(b8 >> 1)+(b4 >> 1)];
                //--- set reconstruction ---
                for (y=0; y<4; y++)
                  for (x=0; x<4; x++)  rec8x8_c[i][b4][y][x] = enc_picture->imgUV[i][pic_pix_y+y+block4x4_y][pic_pix_x+x+block4x4_x];
              }
            }

            //--- set reconstruction ---
            for (y=0; y<8; y++)
              for (x=0; x<8; x++)  
                rec8x8[y][x] = enc_picture->imgY[pic_pix_y+y][pic_pix_x+x];

            //--- flag if dct-coefficients must be coded ---
            nonzero = c_nz;

            //--- set best mode update minimum cost ---
            min_rdcost  = rdcost;
            best_ipmode = ipmode;
          }
         }
      }
    }
  }

  //===== set intra mode prediction =====
  img->ipredmode8x8[pic_block_y][pic_block_x] = best_ipmode;
  currMB->intra_pred_modes8x8[4*b8] = (mostProbableMode == best_ipmode) 
    ? -1 
    : (best_ipmode < mostProbableMode ? best_ipmode : best_ipmode-1);

  for(j = img->mb_y*4+(b8 >> 1)*2; j < img->mb_y*4+(b8 >> 1)*2 + 2; j++)   //loop 4x4s in the subblock for 8x8 prediction setting
   memset(&img->ipredmode8x8[j][img->mb_x*4+(b8 & 0x01)*2], best_ipmode, 2 * sizeof(char));


  if (!input->rdopt)
  {
    // Residue Color Transform
    if(!img->residue_transform_flag)
    {
      // get prediction and prediction error
      for (j=0; j<8; j++)
      {
        memcpy(&img->mpr[block_y+j][block_x],img->mprr_3[best_ipmode][j], 8 * sizeof(imgpel));
        for (i=0; i<8; i++)
        {
          img->m7[j][i] = imgY_orig[pic_opix_y+j][pic_opix_x+i] - img->mprr_3[best_ipmode][j][i];
        }
      } 
      nonzero = dct_luma8x8 (b8, &dummy, 1);
    }
    else 
    {
      for (j=0; j<8; j++)
      {
        for (i=0; i<8; i++)
        {
          img->mpr[block_y+j][block_x+i]  = img->mprr_3[best_ipmode][j][i];
          residue_B = imgUV_org[0][pic_opix_y+j][pic_opix_x+i] - img->mprr_c[0][c_ipmode][block_y+j][block_x+i];
          residue_G = imgY_org[pic_opix_y+j][pic_opix_x+i] - img->mprr_3[best_ipmode][j][i];
          residue_R = imgUV_org[1][pic_opix_y+j][pic_opix_x+i] - img->mprr_c[1][c_ipmode][block_y+j][block_x+i];
          
          /* Forward Residue Transform */
          resTrans_R[j][i] = residue_R-residue_B;
          temp = residue_B+(resTrans_R[j][i]>>1);
          resTrans_B[j][i] = residue_G-temp;
          resTrans_G[j][i] = temp+(resTrans_B[j][i]>>1);
        }
      } 
      for (j=0; j<8; j++)
      {
        for (i=0; i<8; i++)
          
          img->m7[j][i]  = resTrans_G[j][i];
      }
      
      nonzero = dct_luma8x8 (b8, &dummy, 1);
      
      for (j=0; j<8; j++)
      {
        for (i=0; i<8; i++)
          rec_resG[j][i] = img->m7[j][i];
      }
      
      for(b4=0;b4<4;b4++)
      {

        block4x4_x = 4*(b4 & 0x01);
        block4x4_y = 4*(b4 >> 1);
        
        for (j=0; j<4; j++)
        {
          for (i=0; i<4; i++)                
            img->m7[j][i]  = resTrans_B[j+block4x4_y][i+block4x4_x];
        }
        cbp_chroma_block[0][2*(b8 & 0x01)+(b4 & 0x01)][2*(b8 >> 1)+(b4 >> 1)] = dct_chroma4x4 (0, b8+4, b4);
        dc_level        [0][2*(b8 & 0x01)+(b4 & 0x01)][2*(b8 >> 1)+(b4 >> 1)] = dc_level_temp[0][2*(b8 & 0x01)+(b4 & 0x01)][2*(b8 >> 1)+(b4 >> 1)];
        for (j=0; j<4; j++)
        {
          for (i=0; i<4; i++)
          {
            rec_resB[j+block4x4_y][i+block4x4_x] = img->m7[j][i];
            img->m7[j][i]  = resTrans_R[j+block4x4_y][i+block4x4_x];
          }
        }
        cbp_chroma_block[1][2*(b8 & 0x01)+(b4 & 0x01)][2*(b8 >> 1)+(b4 >> 1)] = dct_chroma4x4 (1, b8+8, b4);
        dc_level        [1][2*(b8 & 0x01)+(b4 & 0x01)][2*(b8 >> 1)+(b4 >> 1)] = dc_level_temp[1][2*(b8 & 0x01)+(b4 & 0x01)][2*(b8 >> 1)+(b4 >> 1)];
        for (j=0; j<4; j++)
        {
          for (i=0; i<4; i++)
            rec_resR[j+block4x4_y][i+block4x4_x] = img->m7[j][i];
        }
      }
      
      for (j=0; j<8; j++)
      {
        for (i=0; i<8; i++)
        {
          /* Inverse Residue Transform */
          temp      = rec_resG[j][i]-(rec_resB[j][i]>>1);
          residue_G = rec_resB[j][i]+temp;
          residue_B = temp - (rec_resR[j][i]>>1);
          residue_R = residue_B+rec_resR[j][i];
          enc_picture->imgUV[0][pic_pix_y+j][pic_pix_x+i] = min(img->max_imgpel_value_uv,max(0,residue_B+(int)img->mprr_c[0][c_ipmode][block_y+j][block_x+i]));
          enc_picture->imgY[pic_pix_y+j][pic_pix_x+i]     = min(img->max_imgpel_value,max(0,residue_G+(int)img->mprr_3[best_ipmode][j][i]));
          enc_picture->imgUV[1][pic_pix_y+j][pic_pix_x+i] = min(img->max_imgpel_value_uv,max(0,residue_R+(int)img->mprr_c[1][c_ipmode][block_y+j][block_x+i]));
        }
      }
    }
  }
  else
  {
    //===== restore coefficients =====
    for(k=0; k<4; k++) // do 4x now    
    {
      for (j=0; j<2; j++)
        memcpy(img->cofAC[b8][k][j],cofAC8x8[b8][k][j], 65 * sizeof(int));
    }

    if (img->AdaptiveRounding)
    {
      for (j=0; j<8; j++)
        memcpy(&img->fadjust8x8[1][block_y+j][block_x], &fadjust8x8[1][block_y+j][block_x], 8 * sizeof(int));
    }
    
    // Residue Color Transform
    if(img->residue_transform_flag)
    for(b4=0; b4<4; b4++){
      for (j=0; j<2; j++)
      for (i=0; i<18;i++)  
        img->cofAC[b8+4][b4][j][i]=cofAC8x8_chroma[0][b4][j][i];
      for (j=0; j<2; j++)
      for (i=0; i<18;i++)  
        img->cofAC[b8+8][b4][j][i]=cofAC8x8_chroma[1][b4][j][i];
    }

    //===== restore reconstruction and prediction (needed if single coeffs are removed) =====
    for (y=0; y<8; y++) 
    {
      memcpy(&enc_picture->imgY[pic_pix_y+y][pic_pix_x], rec8x8[y], 8 * sizeof(imgpel));
      memcpy(&  img->mpr[block_y+y][block_x], img->mprr_3[best_ipmode][y], 8 * sizeof(imgpel));
    }

    // Residue Color Transform
      if(img->residue_transform_flag)
      {
        for(b4=0; b4<4; b4++)
        {
          block4x4_x = 4*(b4 & 0x01);
          block4x4_y = 4*(b4>>1);
          for (i=0; i<2; i++)
          { //uv
            //--- set reconstruction ---
            for (y=0; y<4; y++)
              memcpy(&enc_picture->imgUV[i][pic_pix_y + block4x4_y + y][pic_pix_x + block4x4_x], rec8x8_c[i][b4][y], 4 * sizeof(imgpel));
          }
        }
      }
  }

  return nonzero;
}



// Notation for comments regarding prediction and predictors.
// The pels of the 4x4 block are labelled a..p. The predictor pels above
// are labelled A..H, from the left I..P, and from above left X, as follows:
//
//  Z  A  B  C  D  E  F  G  H  I  J  K  L  M   N  O  P  
//  Q  a1 b1 c1 d1 e1 f1 g1 h1
//  R  a2 b2 c2 d2 e2 f2 g2 h2
//  S  a3 b3 c3 d3 e3 f3 g3 h3
//  T  a4 b4 c4 d4 e4 f4 g4 h4
//  U  a5 b5 c5 d5 e5 f5 g5 h5
//  V  a6 b6 c6 d6 e6 f6 g6 h6
//  W  a7 b7 c7 d7 e7 f7 g7 h7
//  X  a8 b8 c8 d8 e8 f8 g8 h8


// Predictor array index definitions
#define P_Z (PredPel[0])
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
#define P_M (PredPel[13])
#define P_N (PredPel[14])
#define P_O (PredPel[15])
#define P_P (PredPel[16])
#define P_Q (PredPel[17])
#define P_R (PredPel[18])
#define P_S (PredPel[19])
#define P_T (PredPel[20])
#define P_U (PredPel[21])
#define P_V (PredPel[22])
#define P_W (PredPel[23])
#define P_X (PredPel[24])

/*!
 ************************************************************************
 * \brief
 *    Make intra 8x8 prediction according to all 9 prediction modes.
 *    The routine uses left and upper neighbouring points from
 *    previous coded blocks to do this (if available). Notice that
 *    inaccessible neighbouring points are signalled with a negative
 *    value in the predmode array .
 *
 *  \par Input:
 *     Starting point of current 8x8 block image posision
 *
 *  \par Output:
 *      none
 ************************************************************************
 */
void intrapred_luma8x8(int img_x,int img_y, int *left_available, int *up_available, int *all_available)
{
  int i,j;
  int s0;
  int PredPel[25];  // array of predictor pels
  imgpel **imgY = enc_picture->imgY;  // For MB level frame/field coding tools -- set default to imgY

  int ioff = (img_x & 15);
  int joff = (img_y & 15);
  int mb_nr=img->current_mb_nr;

  PixelPos pix_a[8];
  PixelPos pix_b, pix_c, pix_d;

  int block_available_up;
  int block_available_left;
  int block_available_up_left;
  int block_available_up_right;

  for (i=0;i<8;i++)
  {
    getNeighbour(mb_nr, ioff -1 , joff +i , 1, &pix_a[i]);
  }

  getNeighbour(mb_nr, ioff    , joff -1 , 1, &pix_b);
  getNeighbour(mb_nr, ioff +8 , joff -1 , 1, &pix_c);
  getNeighbour(mb_nr, ioff -1 , joff -1 , 1, &pix_d);
  
  pix_c.available = pix_c.available &&!(ioff == 8 && joff == 8);

  if (input->UseConstrainedIntraPred)
  {
    for (i=0, block_available_left=1; i<8;i++)
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
  // form predictor pels
  if (block_available_up)
  {
    P_A = imgY[pix_b.pos_y][pix_b.pos_x+0];
    P_B = imgY[pix_b.pos_y][pix_b.pos_x+1];
    P_C = imgY[pix_b.pos_y][pix_b.pos_x+2];
    P_D = imgY[pix_b.pos_y][pix_b.pos_x+3];
    P_E = imgY[pix_b.pos_y][pix_b.pos_x+4];
    P_F = imgY[pix_b.pos_y][pix_b.pos_x+5];
    P_G = imgY[pix_b.pos_y][pix_b.pos_x+6];
    P_H = imgY[pix_b.pos_y][pix_b.pos_x+7];
  }
  else
  {
    P_A = P_B = P_C = P_D = P_E = P_F = P_G = P_H = img->dc_pred_value;
  }

  if (block_available_up_right)
  {
    P_I = imgY[pix_c.pos_y][pix_c.pos_x+0];
    P_J = imgY[pix_c.pos_y][pix_c.pos_x+1];
    P_K = imgY[pix_c.pos_y][pix_c.pos_x+2];
    P_L = imgY[pix_c.pos_y][pix_c.pos_x+3];
    P_M = imgY[pix_c.pos_y][pix_c.pos_x+4];
    P_N = imgY[pix_c.pos_y][pix_c.pos_x+5];
    P_O = imgY[pix_c.pos_y][pix_c.pos_x+6];
    P_P = imgY[pix_c.pos_y][pix_c.pos_x+7];

  }
  else
  {
    P_I = P_J = P_K = P_L = P_M = P_N = P_O = P_P = P_H;
  }

  if (block_available_left)
  {
    P_Q = imgY[pix_a[0].pos_y][pix_a[0].pos_x];
    P_R = imgY[pix_a[1].pos_y][pix_a[1].pos_x];
    P_S = imgY[pix_a[2].pos_y][pix_a[2].pos_x];
    P_T = imgY[pix_a[3].pos_y][pix_a[3].pos_x];
    P_U = imgY[pix_a[4].pos_y][pix_a[4].pos_x];
    P_V = imgY[pix_a[5].pos_y][pix_a[5].pos_x];
    P_W = imgY[pix_a[6].pos_y][pix_a[6].pos_x];
    P_X = imgY[pix_a[7].pos_y][pix_a[7].pos_x];
  }
  else
  {
    P_Q = P_R = P_S = P_T = P_U = P_V = P_W = P_X = img->dc_pred_value;
  }

  if (block_available_up_left)
  {
    P_Z = imgY[pix_d.pos_y][pix_d.pos_x];
  }
  else
  {
    P_Z = img->dc_pred_value;
  }

  for(i=0;i<9;i++)
    img->mprr_3[i][0][0]=-1;

  LowPassForIntra8x8Pred(&(P_Z), block_available_up_left, block_available_up, block_available_left);

  ///////////////////////////////
  // make DC prediction
  ///////////////////////////////
  s0 = 0;
  if (block_available_up && block_available_left)
  {   
    // no edge
    s0 = (P_A + P_B + P_C + P_D + P_E + P_F + P_G + P_H + P_Q + P_R + P_S + P_T + P_U + P_V + P_W + P_X + 8) >> 4;
  }
  else if (!block_available_up && block_available_left)
  {
    // upper edge
    s0 = (P_Q + P_R + P_S + P_T + P_U + P_V + P_W + P_X + 4) >> 3;             
  }
  else if (block_available_up && !block_available_left)
  {
    // left edge
    s0 = (P_A + P_B + P_C + P_D + P_E + P_F + P_G + P_H + 4) >> 3;             
  }
  else //if (!block_available_up && !block_available_left)
  {
    // top left corner, nothing to predict from
    s0 = img->dc_pred_value;                           
  }
  
  // store DC prediction
  for (j=0; j < 2*BLOCK_SIZE; j++)
  {
    for (i=0; i < 2*BLOCK_SIZE; i++)
    {
      img->mprr_3[DC_PRED][i][j] = s0;
    }
  }

  
  ///////////////////////////////
  // make horiz and vert prediction
  ///////////////////////////////

  for (i=0; i < 2*BLOCK_SIZE; i++)
  {
    img->mprr_3[VERT_PRED][0][i] = 
    img->mprr_3[VERT_PRED][1][i] = 
    img->mprr_3[VERT_PRED][2][i] = 
    img->mprr_3[VERT_PRED][3][i] = 
    img->mprr_3[VERT_PRED][4][i] = 
    img->mprr_3[VERT_PRED][5][i] = 
    img->mprr_3[VERT_PRED][6][i] = 
    img->mprr_3[VERT_PRED][7][i] = (&P_A)[i];
    img->mprr_3[HOR_PRED][i][0]  = 
    img->mprr_3[HOR_PRED][i][1]  = 
    img->mprr_3[HOR_PRED][i][2]  = 
    img->mprr_3[HOR_PRED][i][3]  = 
    img->mprr_3[HOR_PRED][i][4]  = 
    img->mprr_3[HOR_PRED][i][5]  = 
    img->mprr_3[HOR_PRED][i][6]  = 
    img->mprr_3[HOR_PRED][i][7]  = (&P_Q)[i];
  }

  if(!block_available_up)img->mprr_3[VERT_PRED][0][0]=-1;
  if(!block_available_left)img->mprr_3[HOR_PRED][0][0]=-1;

  ///////////////////////////////////
  // make diagonal down left prediction
  ///////////////////////////////////
  if (block_available_up) 
  {
    // Mode DIAG_DOWN_LEFT_PRED
    img->mprr_3[DIAG_DOWN_LEFT_PRED][0][0] = (P_A + P_C + 2*(P_B) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_LEFT_PRED][0][1] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][1][0] = (P_B + P_D + 2*(P_C) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_LEFT_PRED][0][2] =
    img->mprr_3[DIAG_DOWN_LEFT_PRED][1][1] =
    img->mprr_3[DIAG_DOWN_LEFT_PRED][2][0] = (P_C + P_E + 2*(P_D) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_LEFT_PRED][0][3] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][1][2] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][2][1] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][3][0] = (P_D + P_F + 2*(P_E) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_LEFT_PRED][0][4] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][1][3] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][2][2] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][3][1] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][4][0] = (P_E + P_G + 2*(P_F) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_LEFT_PRED][0][5] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][1][4] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][2][3] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][3][2] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][4][1] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][5][0] = (P_F + P_H + 2*(P_G) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_LEFT_PRED][0][6] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][1][5] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][2][4] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][3][3] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][4][2] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][5][1] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][6][0] = (P_G + P_I + 2*(P_H) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_LEFT_PRED][0][7] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][1][6] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][2][5] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][3][4] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][4][3] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][5][2] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][6][1] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][7][0] = (P_H + P_J + 2*(P_I) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_LEFT_PRED][1][7] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][2][6] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][3][5] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][4][4] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][5][3] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][6][2] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][7][1] = (P_I + P_K + 2*(P_J) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_LEFT_PRED][2][7] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][3][6] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][4][5] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][5][4] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][6][3] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][7][2] = (P_J + P_L + 2*(P_K) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_LEFT_PRED][3][7] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][4][6] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][5][5] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][6][4] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][7][3] = (P_K + P_M + 2*(P_L) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_LEFT_PRED][4][7] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][5][6] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][6][5] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][7][4] = (P_L + P_N + 2*(P_M) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_LEFT_PRED][5][7] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][6][6] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][7][5] = (P_M + P_O + 2*(P_N) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_LEFT_PRED][6][7] = 
    img->mprr_3[DIAG_DOWN_LEFT_PRED][7][6] = (P_N + P_P + 2*(P_O) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_LEFT_PRED][7][7] = (P_O + 3*(P_P) + 2) >> 2;

    ///////////////////////////////////
    // make vertical left prediction
    ///////////////////////////////////
    img->mprr_3[VERT_LEFT_PRED][0][0] = (P_A + P_B + 1) >> 1;
    img->mprr_3[VERT_LEFT_PRED][0][1] = 
    img->mprr_3[VERT_LEFT_PRED][2][0] = (P_B + P_C + 1) >> 1;
    img->mprr_3[VERT_LEFT_PRED][0][2] = 
    img->mprr_3[VERT_LEFT_PRED][2][1] = 
    img->mprr_3[VERT_LEFT_PRED][4][0] = (P_C + P_D + 1) >> 1;
    img->mprr_3[VERT_LEFT_PRED][0][3] = 
    img->mprr_3[VERT_LEFT_PRED][2][2] = 
    img->mprr_3[VERT_LEFT_PRED][4][1] = 
    img->mprr_3[VERT_LEFT_PRED][6][0] = (P_D + P_E + 1) >> 1;
    img->mprr_3[VERT_LEFT_PRED][0][4] = 
    img->mprr_3[VERT_LEFT_PRED][2][3] = 
    img->mprr_3[VERT_LEFT_PRED][4][2] = 
    img->mprr_3[VERT_LEFT_PRED][6][1] = (P_E + P_F + 1) >> 1;
    img->mprr_3[VERT_LEFT_PRED][0][5] = 
    img->mprr_3[VERT_LEFT_PRED][2][4] = 
    img->mprr_3[VERT_LEFT_PRED][4][3] = 
    img->mprr_3[VERT_LEFT_PRED][6][2] = (P_F + P_G + 1) >> 1;
    img->mprr_3[VERT_LEFT_PRED][0][6] = 
    img->mprr_3[VERT_LEFT_PRED][2][5] = 
    img->mprr_3[VERT_LEFT_PRED][4][4] = 
    img->mprr_3[VERT_LEFT_PRED][6][3] = (P_G + P_H + 1) >> 1;
    img->mprr_3[VERT_LEFT_PRED][0][7] = 
    img->mprr_3[VERT_LEFT_PRED][2][6] = 
    img->mprr_3[VERT_LEFT_PRED][4][5] = 
    img->mprr_3[VERT_LEFT_PRED][6][4] = (P_H + P_I + 1) >> 1;
    img->mprr_3[VERT_LEFT_PRED][2][7] = 
    img->mprr_3[VERT_LEFT_PRED][4][6] = 
    img->mprr_3[VERT_LEFT_PRED][6][5] = (P_I + P_J + 1) >> 1;
    img->mprr_3[VERT_LEFT_PRED][4][7] = 
    img->mprr_3[VERT_LEFT_PRED][6][6] = (P_J + P_K + 1) >> 1;
    img->mprr_3[VERT_LEFT_PRED][6][7] = (P_K + P_L + 1) >> 1;
    img->mprr_3[VERT_LEFT_PRED][1][0] = (P_A + P_C + 2*P_B + 2) >> 2;
    img->mprr_3[VERT_LEFT_PRED][1][1] = 
    img->mprr_3[VERT_LEFT_PRED][3][0] = (P_B + P_D + 2*P_C + 2) >> 2;
    img->mprr_3[VERT_LEFT_PRED][1][2] = 
    img->mprr_3[VERT_LEFT_PRED][3][1] = 
    img->mprr_3[VERT_LEFT_PRED][5][0] = (P_C + P_E + 2*P_D + 2) >> 2;
    img->mprr_3[VERT_LEFT_PRED][1][3] = 
    img->mprr_3[VERT_LEFT_PRED][3][2] = 
    img->mprr_3[VERT_LEFT_PRED][5][1] = 
    img->mprr_3[VERT_LEFT_PRED][7][0] = (P_D + P_F + 2*P_E + 2) >> 2;
    img->mprr_3[VERT_LEFT_PRED][1][4] = 
    img->mprr_3[VERT_LEFT_PRED][3][3] = 
    img->mprr_3[VERT_LEFT_PRED][5][2] = 
    img->mprr_3[VERT_LEFT_PRED][7][1] = (P_E + P_G + 2*P_F + 2) >> 2;
    img->mprr_3[VERT_LEFT_PRED][1][5] = 
    img->mprr_3[VERT_LEFT_PRED][3][4] = 
    img->mprr_3[VERT_LEFT_PRED][5][3] = 
    img->mprr_3[VERT_LEFT_PRED][7][2] = (P_F + P_H + 2*P_G + 2) >> 2;
    img->mprr_3[VERT_LEFT_PRED][1][6] = 
    img->mprr_3[VERT_LEFT_PRED][3][5] = 
    img->mprr_3[VERT_LEFT_PRED][5][4] = 
    img->mprr_3[VERT_LEFT_PRED][7][3] = (P_G + P_I + 2*P_H + 2) >> 2;
    img->mprr_3[VERT_LEFT_PRED][1][7] = 
    img->mprr_3[VERT_LEFT_PRED][3][6] = 
    img->mprr_3[VERT_LEFT_PRED][5][5] = 
    img->mprr_3[VERT_LEFT_PRED][7][4] = (P_H + P_J + 2*P_I + 2) >> 2;
    img->mprr_3[VERT_LEFT_PRED][3][7] = 
    img->mprr_3[VERT_LEFT_PRED][5][6] = 
    img->mprr_3[VERT_LEFT_PRED][7][5] = (P_I + P_K + 2*P_J + 2) >> 2;
    img->mprr_3[VERT_LEFT_PRED][5][7] = 
    img->mprr_3[VERT_LEFT_PRED][7][6] = (P_J + P_L + 2*P_K + 2) >> 2;
    img->mprr_3[VERT_LEFT_PRED][7][7] = (P_K + P_M + 2*P_L + 2) >> 2;
  }

  ///////////////////////////////////
  // make diagonal down right prediction
  ///////////////////////////////////
  if (block_available_up && block_available_left && block_available_up_left) 
  {
    // Mode DIAG_DOWN_RIGHT_PRED
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][7][0] = (P_X + P_V + 2*(P_W) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][6][0] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][7][1] = (P_W + P_U + 2*(P_V) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][5][0] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][6][1] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][7][2] = (P_V + P_T + 2*(P_U) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][4][0] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][5][1] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][6][2] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][7][3] = (P_U + P_S + 2*(P_T) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][3][0] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][4][1] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][5][2] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][6][3] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][7][4] = (P_T + P_R + 2*(P_S) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][2][0] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][3][1] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][4][2] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][5][3] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][6][4] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][7][5] = (P_S + P_Q + 2*(P_R) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][1][0] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][2][1] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][3][2] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][4][3] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][5][4] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][6][5] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][7][6] = (P_R + P_Z + 2*(P_Q) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][0][0] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][1][1] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][2][2] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][3][3] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][4][4] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][5][5] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][6][6] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][7][7] = (P_Q + P_A + 2*(P_Z) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][0][1] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][1][2] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][2][3] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][3][4] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][4][5] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][5][6] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][6][7] = (P_Z + P_B + 2*(P_A) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][0][2] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][1][3] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][2][4] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][3][5] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][4][6] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][5][7] = (P_A + P_C + 2*(P_B) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][0][3] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][1][4] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][2][5] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][3][6] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][4][7] = (P_B + P_D + 2*(P_C) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][0][4] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][1][5] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][2][6] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][3][7] = (P_C + P_E + 2*(P_D) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][0][5] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][1][6] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][2][7] = (P_D + P_F + 2*(P_E) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][0][6] = 
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][1][7] = (P_E + P_G + 2*(P_F) + 2) >> 2;
    img->mprr_3[DIAG_DOWN_RIGHT_PRED][0][7] = (P_F + P_H + 2*(P_G) + 2) >> 2;

  ///////////////////////////////////
  // make vertical right prediction
  ///////////////////////////////////
    img->mprr_3[VERT_RIGHT_PRED][0][0] = 
    img->mprr_3[VERT_RIGHT_PRED][2][1] = 
    img->mprr_3[VERT_RIGHT_PRED][4][2] = 
    img->mprr_3[VERT_RIGHT_PRED][6][3] = (P_Z + P_A + 1) >> 1;
    img->mprr_3[VERT_RIGHT_PRED][0][1] = 
    img->mprr_3[VERT_RIGHT_PRED][2][2] = 
    img->mprr_3[VERT_RIGHT_PRED][4][3] = 
    img->mprr_3[VERT_RIGHT_PRED][6][4] = (P_A + P_B + 1) >> 1;
    img->mprr_3[VERT_RIGHT_PRED][0][2] = 
    img->mprr_3[VERT_RIGHT_PRED][2][3] = 
    img->mprr_3[VERT_RIGHT_PRED][4][4] = 
    img->mprr_3[VERT_RIGHT_PRED][6][5] = (P_B + P_C + 1) >> 1;
    img->mprr_3[VERT_RIGHT_PRED][0][3] = 
    img->mprr_3[VERT_RIGHT_PRED][2][4] = 
    img->mprr_3[VERT_RIGHT_PRED][4][5] = 
    img->mprr_3[VERT_RIGHT_PRED][6][6] = (P_C + P_D + 1) >> 1;
    img->mprr_3[VERT_RIGHT_PRED][0][4] = 
    img->mprr_3[VERT_RIGHT_PRED][2][5] = 
    img->mprr_3[VERT_RIGHT_PRED][4][6] = 
    img->mprr_3[VERT_RIGHT_PRED][6][7] = (P_D + P_E + 1) >> 1;
    img->mprr_3[VERT_RIGHT_PRED][0][5] = 
    img->mprr_3[VERT_RIGHT_PRED][2][6] = 
    img->mprr_3[VERT_RIGHT_PRED][4][7] = (P_E + P_F + 1) >> 1;
    img->mprr_3[VERT_RIGHT_PRED][0][6] = 
    img->mprr_3[VERT_RIGHT_PRED][2][7] = (P_F + P_G + 1) >> 1;
    img->mprr_3[VERT_RIGHT_PRED][0][7] = (P_G + P_H + 1) >> 1;
    img->mprr_3[VERT_RIGHT_PRED][1][0] = 
    img->mprr_3[VERT_RIGHT_PRED][3][1] = 
    img->mprr_3[VERT_RIGHT_PRED][5][2] = 
    img->mprr_3[VERT_RIGHT_PRED][7][3] = (P_Q + P_A + 2*P_Z + 2) >> 2;
    img->mprr_3[VERT_RIGHT_PRED][1][1] = 
    img->mprr_3[VERT_RIGHT_PRED][3][2] = 
    img->mprr_3[VERT_RIGHT_PRED][5][3] = 
    img->mprr_3[VERT_RIGHT_PRED][7][4] = (P_Z + P_B + 2*P_A + 2) >> 2;
    img->mprr_3[VERT_RIGHT_PRED][1][2] = 
    img->mprr_3[VERT_RIGHT_PRED][3][3] = 
    img->mprr_3[VERT_RIGHT_PRED][5][4] = 
    img->mprr_3[VERT_RIGHT_PRED][7][5] = (P_A + P_C + 2*P_B + 2) >> 2;
    img->mprr_3[VERT_RIGHT_PRED][1][3] = 
    img->mprr_3[VERT_RIGHT_PRED][3][4] = 
    img->mprr_3[VERT_RIGHT_PRED][5][5] = 
    img->mprr_3[VERT_RIGHT_PRED][7][6] = (P_B + P_D + 2*P_C + 2) >> 2;
    img->mprr_3[VERT_RIGHT_PRED][1][4] = 
    img->mprr_3[VERT_RIGHT_PRED][3][5] = 
    img->mprr_3[VERT_RIGHT_PRED][5][6] = 
    img->mprr_3[VERT_RIGHT_PRED][7][7] = (P_C + P_E + 2*P_D + 2) >> 2;
    img->mprr_3[VERT_RIGHT_PRED][1][5] = 
    img->mprr_3[VERT_RIGHT_PRED][3][6] = 
    img->mprr_3[VERT_RIGHT_PRED][5][7] = (P_D + P_F + 2*P_E + 2) >> 2;
    img->mprr_3[VERT_RIGHT_PRED][1][6] = 
    img->mprr_3[VERT_RIGHT_PRED][3][7] = (P_E + P_G + 2*P_F + 2) >> 2;
    img->mprr_3[VERT_RIGHT_PRED][1][7] = (P_F + P_H + 2*P_G + 2) >> 2;
    img->mprr_3[VERT_RIGHT_PRED][2][0] =
    img->mprr_3[VERT_RIGHT_PRED][4][1] =
    img->mprr_3[VERT_RIGHT_PRED][6][2] = (P_R + P_Z + 2*P_Q + 2) >> 2;
    img->mprr_3[VERT_RIGHT_PRED][3][0] =
    img->mprr_3[VERT_RIGHT_PRED][5][1] =
    img->mprr_3[VERT_RIGHT_PRED][7][2] = (P_S + P_Q + 2*P_R + 2) >> 2;
    img->mprr_3[VERT_RIGHT_PRED][4][0] =
    img->mprr_3[VERT_RIGHT_PRED][6][1] = (P_T + P_R + 2*P_S + 2) >> 2;
    img->mprr_3[VERT_RIGHT_PRED][5][0] =
    img->mprr_3[VERT_RIGHT_PRED][7][1] = (P_U + P_S + 2*P_T + 2) >> 2;
    img->mprr_3[VERT_RIGHT_PRED][6][0] = (P_V + P_T + 2*P_U + 2) >> 2;
    img->mprr_3[VERT_RIGHT_PRED][7][0] = (P_W + P_U + 2*P_V + 2) >> 2;

  ///////////////////////////////////
  // make horizontal down prediction
  ///////////////////////////////////
    
    img->mprr_3[HOR_DOWN_PRED][0][0] = 
    img->mprr_3[HOR_DOWN_PRED][1][2] = 
    img->mprr_3[HOR_DOWN_PRED][2][4] = 
    img->mprr_3[HOR_DOWN_PRED][3][6] = (P_Q + P_Z + 1) >> 1;
    img->mprr_3[HOR_DOWN_PRED][1][0] = 
    img->mprr_3[HOR_DOWN_PRED][2][2] = 
    img->mprr_3[HOR_DOWN_PRED][3][4] = 
    img->mprr_3[HOR_DOWN_PRED][4][6] = (P_R + P_Q + 1) >> 1;
    img->mprr_3[HOR_DOWN_PRED][2][0] = 
    img->mprr_3[HOR_DOWN_PRED][3][2] = 
    img->mprr_3[HOR_DOWN_PRED][4][4] = 
    img->mprr_3[HOR_DOWN_PRED][5][6] = (P_S + P_R + 1) >> 1;
    img->mprr_3[HOR_DOWN_PRED][3][0] = 
    img->mprr_3[HOR_DOWN_PRED][4][2] = 
    img->mprr_3[HOR_DOWN_PRED][5][4] = 
    img->mprr_3[HOR_DOWN_PRED][6][6] = (P_T + P_S + 1) >> 1;
    img->mprr_3[HOR_DOWN_PRED][4][0] = 
    img->mprr_3[HOR_DOWN_PRED][5][2] = 
    img->mprr_3[HOR_DOWN_PRED][6][4] = 
    img->mprr_3[HOR_DOWN_PRED][7][6] = (P_U + P_T + 1) >> 1;
    img->mprr_3[HOR_DOWN_PRED][5][0] = 
    img->mprr_3[HOR_DOWN_PRED][6][2] = 
    img->mprr_3[HOR_DOWN_PRED][7][4] = (P_V + P_U + 1) >> 1;
    img->mprr_3[HOR_DOWN_PRED][6][0] = 
    img->mprr_3[HOR_DOWN_PRED][7][2] = (P_W + P_V + 1) >> 1;
    img->mprr_3[HOR_DOWN_PRED][7][0] = (P_X + P_W + 1) >> 1;
    img->mprr_3[HOR_DOWN_PRED][0][1] =
    img->mprr_3[HOR_DOWN_PRED][1][3] =
    img->mprr_3[HOR_DOWN_PRED][2][5] =
    img->mprr_3[HOR_DOWN_PRED][3][7] = (P_Q + P_A + 2*P_Z + 2) >> 2;
    img->mprr_3[HOR_DOWN_PRED][1][1] =
    img->mprr_3[HOR_DOWN_PRED][2][3] =
    img->mprr_3[HOR_DOWN_PRED][3][5] =
    img->mprr_3[HOR_DOWN_PRED][4][7] = (P_Z + P_R + 2*P_Q + 2) >> 2;
    img->mprr_3[HOR_DOWN_PRED][2][1] =
    img->mprr_3[HOR_DOWN_PRED][3][3] =
    img->mprr_3[HOR_DOWN_PRED][4][5] =
    img->mprr_3[HOR_DOWN_PRED][5][7] = (P_Q + P_S + 2*P_R + 2) >> 2;
    img->mprr_3[HOR_DOWN_PRED][3][1] =
    img->mprr_3[HOR_DOWN_PRED][4][3] =
    img->mprr_3[HOR_DOWN_PRED][5][5] =
    img->mprr_3[HOR_DOWN_PRED][6][7] = (P_R + P_T + 2*P_S + 2) >> 2;
    img->mprr_3[HOR_DOWN_PRED][4][1] =
    img->mprr_3[HOR_DOWN_PRED][5][3] =
    img->mprr_3[HOR_DOWN_PRED][6][5] =
    img->mprr_3[HOR_DOWN_PRED][7][7] = (P_S + P_U + 2*P_T + 2) >> 2;
    img->mprr_3[HOR_DOWN_PRED][5][1] =
    img->mprr_3[HOR_DOWN_PRED][6][3] =
    img->mprr_3[HOR_DOWN_PRED][7][5] = (P_T + P_V + 2*P_U + 2) >> 2;
    img->mprr_3[HOR_DOWN_PRED][6][1] =
    img->mprr_3[HOR_DOWN_PRED][7][3] = (P_U + P_W + 2*P_V + 2) >> 2;
    img->mprr_3[HOR_DOWN_PRED][7][1] = (P_V + P_X + 2*P_W + 2) >> 2;
    img->mprr_3[HOR_DOWN_PRED][0][2] = 
    img->mprr_3[HOR_DOWN_PRED][1][4] = 
    img->mprr_3[HOR_DOWN_PRED][2][6] = (P_Z + P_B + 2*P_A + 2) >> 2;
    img->mprr_3[HOR_DOWN_PRED][0][3] = 
    img->mprr_3[HOR_DOWN_PRED][1][5] = 
    img->mprr_3[HOR_DOWN_PRED][2][7] = (P_A + P_C + 2*P_B + 2) >> 2;
    img->mprr_3[HOR_DOWN_PRED][0][4] = 
    img->mprr_3[HOR_DOWN_PRED][1][6] = (P_B + P_D + 2*P_C + 2) >> 2;
    img->mprr_3[HOR_DOWN_PRED][0][5] = 
    img->mprr_3[HOR_DOWN_PRED][1][7] = (P_C + P_E + 2*P_D + 2) >> 2;
    img->mprr_3[HOR_DOWN_PRED][0][6] = (P_D + P_F + 2*P_E + 2) >> 2;
    img->mprr_3[HOR_DOWN_PRED][0][7] = (P_E + P_G + 2*P_F + 2) >> 2;
  }

  ///////////////////////////////////
  // make horizontal up prediction
  ///////////////////////////////////
  if (block_available_left)
  {
    img->mprr_3[HOR_UP_PRED][0][0] = (P_Q + P_R + 1) >> 1;
    img->mprr_3[HOR_UP_PRED][1][0] =
    img->mprr_3[HOR_UP_PRED][0][2] = (P_R + P_S + 1) >> 1;
    img->mprr_3[HOR_UP_PRED][2][0] =
    img->mprr_3[HOR_UP_PRED][1][2] =
    img->mprr_3[HOR_UP_PRED][0][4] = (P_S + P_T + 1) >> 1;
    img->mprr_3[HOR_UP_PRED][3][0] =
    img->mprr_3[HOR_UP_PRED][2][2] =
    img->mprr_3[HOR_UP_PRED][1][4] =
    img->mprr_3[HOR_UP_PRED][0][6] = (P_T + P_U + 1) >> 1;
    img->mprr_3[HOR_UP_PRED][4][0] =
    img->mprr_3[HOR_UP_PRED][3][2] =
    img->mprr_3[HOR_UP_PRED][2][4] =
    img->mprr_3[HOR_UP_PRED][1][6] = (P_U + P_V + 1) >> 1;
    img->mprr_3[HOR_UP_PRED][5][0] =
    img->mprr_3[HOR_UP_PRED][4][2] =
    img->mprr_3[HOR_UP_PRED][3][4] =
    img->mprr_3[HOR_UP_PRED][2][6] = (P_V + P_W + 1) >> 1;
    img->mprr_3[HOR_UP_PRED][6][0] =
    img->mprr_3[HOR_UP_PRED][5][2] =
    img->mprr_3[HOR_UP_PRED][4][4] =
    img->mprr_3[HOR_UP_PRED][3][6] = (P_W + P_X + 1) >> 1;
    img->mprr_3[HOR_UP_PRED][4][6] =
    img->mprr_3[HOR_UP_PRED][4][7] =
    img->mprr_3[HOR_UP_PRED][5][4] =
    img->mprr_3[HOR_UP_PRED][5][5] =
    img->mprr_3[HOR_UP_PRED][5][6] =
    img->mprr_3[HOR_UP_PRED][5][7] =
    img->mprr_3[HOR_UP_PRED][6][2] =
    img->mprr_3[HOR_UP_PRED][6][3] =
    img->mprr_3[HOR_UP_PRED][6][4] =
    img->mprr_3[HOR_UP_PRED][6][5] =
    img->mprr_3[HOR_UP_PRED][6][6] =
    img->mprr_3[HOR_UP_PRED][6][7] =
    img->mprr_3[HOR_UP_PRED][7][0] =
    img->mprr_3[HOR_UP_PRED][7][1] =
    img->mprr_3[HOR_UP_PRED][7][2] =
    img->mprr_3[HOR_UP_PRED][7][3] =
    img->mprr_3[HOR_UP_PRED][7][4] =
    img->mprr_3[HOR_UP_PRED][7][5] =
    img->mprr_3[HOR_UP_PRED][7][6] =
    img->mprr_3[HOR_UP_PRED][7][7] = P_X;
    img->mprr_3[HOR_UP_PRED][6][1] =
    img->mprr_3[HOR_UP_PRED][5][3] =
    img->mprr_3[HOR_UP_PRED][4][5] =
    img->mprr_3[HOR_UP_PRED][3][7] = (P_W + 3*P_X + 2) >> 2;
    img->mprr_3[HOR_UP_PRED][5][1] =
    img->mprr_3[HOR_UP_PRED][4][3] =
    img->mprr_3[HOR_UP_PRED][3][5] =
    img->mprr_3[HOR_UP_PRED][2][7] = (P_X + P_V + 2*P_W + 2) >> 2;
    img->mprr_3[HOR_UP_PRED][4][1] =
    img->mprr_3[HOR_UP_PRED][3][3] =
    img->mprr_3[HOR_UP_PRED][2][5] =
    img->mprr_3[HOR_UP_PRED][1][7] = (P_W + P_U + 2*P_V + 2) >> 2;
    img->mprr_3[HOR_UP_PRED][3][1] =
    img->mprr_3[HOR_UP_PRED][2][3] =
    img->mprr_3[HOR_UP_PRED][1][5] =
    img->mprr_3[HOR_UP_PRED][0][7] = (P_V + P_T + 2*P_U + 2) >> 2;
    img->mprr_3[HOR_UP_PRED][2][1] =
    img->mprr_3[HOR_UP_PRED][1][3] =
    img->mprr_3[HOR_UP_PRED][0][5] = (P_U + P_S + 2*P_T + 2) >> 2;
    img->mprr_3[HOR_UP_PRED][1][1] =
    img->mprr_3[HOR_UP_PRED][0][3] = (P_T + P_R + 2*P_S + 2) >> 2;
    img->mprr_3[HOR_UP_PRED][0][1] = (P_S + P_Q + 2*P_R + 2) >> 2;
  }
}

/*! 
 *************************************************************************************
 * \brief
 *    Prefiltering for Intra8x8 prediction
 *************************************************************************************
 */
void LowPassForIntra8x8Pred(int *PredPel, int block_up_left, int block_up, int block_left)
{
  int i;
  int LoopArray[25];
 

  for(i = 0; i < 25; i++)
     LoopArray[i] = PredPel[i] ;

 	if(block_up)
	{
		if(block_up_left) 
		{
			LoopArray[1] = ((&P_Z)[0] + ((&P_Z)[1]<<1) + (&P_Z)[2] + 2)>>2;
		}
		else
			LoopArray[1] = ((&P_Z)[1] + ((&P_Z)[1]<<1) + (&P_Z)[2] + 2)>>2; 


		for(i = 2; i <16; i++)
		{
			LoopArray[i] = ((&P_Z)[i-1] + ((&P_Z)[i]<<1) + (&P_Z)[i+1] + 2)>>2;
		}
		LoopArray[16] = (P_P + (P_P<<1) + P_O + 2)>>2;
	}

	if(block_up_left) 
	{
		
		if(block_up && block_left)
		{
				LoopArray[0] = (P_Q + (P_Z<<1) + P_A +2)>>2;
		}
		else
		{
			if(block_up)
				LoopArray[0] = (P_Z + (P_Z<<1) + P_A +2)>>2;
			else
				if(block_left)
					LoopArray[0] = (P_Z + (P_Z<<1) + P_Q +2)>>2;
		}

	}

	if(block_left)
	{
		if(block_up_left)
			LoopArray[17] = (P_Z + (P_Q<<1) + P_R + 2)>>2; 
		else
			LoopArray[17] = (P_Q + (P_Q<<1) + P_R + 2)>>2;

		for(i = 18; i <24; i++)
		{
			LoopArray[i] = ((&P_Z)[i-1] + ((&P_Z)[i]<<1) + (&P_Z)[i+1] + 2)>>2;
		}
		LoopArray[24] = (P_W + (P_X<<1) + P_X + 2)>>2;
	}

  for(i = 0; i < 25; i++)
    PredPel[i] = LoopArray[i];
}





/*! 
 *************************************************************************************
 * \brief
 *    R-D Cost for an 8x8 Intra block
 *************************************************************************************
 */

double RDCost_for_8x8IntraBlocks(int *nonzero, int b8, int ipmode, double lambda, double min_rdcost, int mostProbableMode)
{
  double  rdcost = 0.0;
  int     dummy, x, y, rate;
  int64   distortion  = 0;
  int     block_x     = 8*(b8 & 0x01);
  int     block_y     = 8*(b8 >> 1);
  int     pic_pix_x   = img->pix_x+block_x;
  int     pic_pix_y   = img->pix_y+block_y;
  int     pic_opix_y  = img->opix_y+block_y;
  imgpel    **imgY_orig  = imgY_org;
  imgpel    **imgY       = enc_picture->imgY;

  Slice          *currSlice    =  img->currentSlice;
  Macroblock     *currMB       = &img->mb_data[img->current_mb_nr];
  SyntaxElement  *currSE       = &img->MB_SyntaxElements[currMB->currSEnr];
  const int      *partMap      = assignSE2partition[input->partition_mode];
  DataPartition  *dataPart;

  //===== perform DCT, Q, IQ, IDCT, Reconstruction =====
  dummy = 0;

  *nonzero = dct_luma8x8 (b8, &dummy, 1);

  //===== get distortion (SSD) of 8x8 block =====
  for (y=0; y<8; y++)
    for (x=pic_pix_x; x<pic_pix_x+8; x++)  
      distortion += img->quad [imgY_orig[pic_opix_y+y][x] - imgY[pic_pix_y+y][x]];

  //===== RATE for INTRA PREDICTION MODE  (SYMBOL MODE MUST BE SET TO UVLC) =====
  currSE->value1 = (mostProbableMode == ipmode) ? -1 : ipmode < mostProbableMode ? ipmode : ipmode-1;

  //--- set position and type ---
  currSE->context = b8;
  currSE->type    = SE_INTRAPREDMODE;

  //--- set function pointer ----
  if (input->symbol_mode != UVLC)    
    currSE->writing = writeIntraPredMode_CABAC;

  //--- choose data partition ---
  if (img->type!=B_SLICE)
    dataPart = &(currSlice->partArr[partMap[SE_INTRAPREDMODE]]);
  else
    dataPart = &(currSlice->partArr[partMap[SE_BFRAME]]);

  //--- encode and update rate ---
  if (input->symbol_mode == UVLC)
    writeSyntaxElement_Intra4x4PredictionMode(currSE, dataPart);
  else
    dataPart->writeSyntaxElement (currSE, dataPart);

  rate = currSE->len;
  currSE++;
  currMB->currSEnr++;

  //===== RATE for LUMINANCE COEFFICIENTS =====

  if (input->symbol_mode == UVLC)
  {
    int b4;
    for(b4=0; b4<4; b4++)
      rate  += writeCoeff4x4_CAVLC (LUMA, b8, b4, 0);
  }
  else
  {
    rate  += writeLumaCoeff8x8_CABAC (b8, 1);
  }


  rdcost = (double)distortion + lambda*(double)rate;

  if(img->residue_transform_flag)
    return (double)rate;
  else
    return rdcost;
}


/*!
 ************************************************************************
 * \brief
 *    The routine performs transform,quantization,inverse transform, adds the diff.
 *    to the prediction and writes the result to the decoded luma frame. Includes the
 *    RD constrained quantization also.
 *
 * \par Input:
 *    b8: Block position inside a macro block (0,1,2,3).
 *
 * \par Output:
 *    nonzero: 0 if no levels are nonzero.  1 if there are nonzero levels.  
 *    coeff_cost: Counter for nonzero coefficients, used to discard expensive levels.
 ************************************************************************
 */

#define MC(coeff) ((coeff)&3)

int dct_luma8x8(int b8,int *coeff_cost, int intra)
{
  int sign(int a,int b);

  int i,j,ilev,coeff_ctr;
  int level,scan_pos,run;
  int nonzero;
  int qp_per,qp_rem,q_bits;
  int dq_lshift = 0, dq_rshift = 0, dq_round = 0;

  int block_x = 8*(b8 & 0x01);
  int block_y = 8*(b8 >> 1);
  int*  ACLevel = img->cofAC[b8][0][0];
  int*  ACRun   = img->cofAC[b8][0][1];
  int m6[8][8];
  int a[8], b[8];
  int scan_poss[4],runs[4];
  int pix_x, pix_y, ipix_y;
  int **levelscale,**leveloffset;
  int **invlevelscale;
  int MCcoeff;
  Macroblock *currMB = &img->mb_data[img->current_mb_nr];
  short is_field_mode = (img->field_picture || ( img->MbaffFrameFlag && currMB->mb_field));

  Boolean lossless_qpprime = ((img->qp + img->bitdepth_luma_qp_scale)==0 && img->lossless_qpprime_flag==1);
  
  qp_per    = (img->qp + img->bitdepth_luma_qp_scale - MIN_QP)/6;
  qp_rem    = (img->qp + img->bitdepth_luma_qp_scale - MIN_QP)%6;
  q_bits    = Q_BITS_8+qp_per;
  levelscale    = LevelScale8x8Luma[intra][qp_rem];
  leveloffset   = LevelOffset8x8Luma[intra][qp_per];
  invlevelscale = InvLevelScale8x8Luma[intra][qp_rem];

  if (qp_per < 6)
  {
    dq_rshift = 6 - qp_per;
    dq_round  = 1<<(5-qp_per);
  }
  else
    dq_lshift = qp_per - 6;
    

  // horizontal transform
  if (!lossless_qpprime) 
  {
    for( i=0; i<8; i++)
    {
      a[0] = img->m7[i][0] + img->m7[i][7];
      a[1] = img->m7[i][1] + img->m7[i][6];
      a[2] = img->m7[i][2] + img->m7[i][5];
      a[3] = img->m7[i][3] + img->m7[i][4];
      
      b[0] = a[0] + a[3];
      b[1] = a[1] + a[2];
      b[2] = a[0] - a[3];
      b[3] = a[1] - a[2];
      
      a[4] = img->m7[i][0] - img->m7[i][7];
      a[5] = img->m7[i][1] - img->m7[i][6];
      a[6] = img->m7[i][2] - img->m7[i][5];
      a[7] = img->m7[i][3] - img->m7[i][4];
      
      b[4]= a[5] + a[6] + ((a[4]>>1) + a[4]);
      b[5]= a[4] - a[7] - ((a[6]>>1) + a[6]);
      b[6]= a[4] + a[7] - ((a[5]>>1) + a[5]);
      b[7]= a[5] - a[6] + ((a[7]>>1) + a[7]);
      
      m6[0][i] = b[0] + b[1];
      m6[2][i] = b[2] + (b[3]>>1);
      m6[4][i] = b[0] - b[1];
      m6[6][i] = (b[2]>>1) - b[3];
      m6[1][i] =   b[4] + (b[7]>>2);
      m6[3][i] =   b[5] + (b[6]>>2);
      m6[5][i] =   b[6] - (b[5]>>2);
      m6[7][i] = - b[7] + (b[4]>>2);
      
    }
    // vertical transform
    for( i=0; i<8; i++)
    {
      a[0] = m6[i][0] + m6[i][7];
      a[1] = m6[i][1] + m6[i][6];
      a[2] = m6[i][2] + m6[i][5];
      a[3] = m6[i][3] + m6[i][4];
      
      b[0] = a[0] + a[3];
      b[1] = a[1] + a[2];
      b[2] = a[0] - a[3];
      b[3] = a[1] - a[2];
      
      a[4] = m6[i][0] - m6[i][7];
      a[5] = m6[i][1] - m6[i][6];
      a[6] = m6[i][2] - m6[i][5];
      a[7] = m6[i][3] - m6[i][4];
      
      b[4]= a[5] + a[6] + ((a[4]>>1) + a[4]);
      b[5]= a[4] - a[7] - ((a[6]>>1) + a[6]);
      b[6]= a[4] + a[7] - ((a[5]>>1) + a[5]);
      b[7]= a[5] - a[6] + ((a[7]>>1) + a[7]);
      
      img->m7[0][i] = b[0] + b[1];
      img->m7[2][i] = b[2] + (b[3]>>1);
      img->m7[4][i] = b[0] - b[1];
      img->m7[6][i] = (b[2]>>1) - b[3];
      img->m7[1][i] =   b[4] + (b[7]>>2);
      img->m7[3][i] =   b[5] + (b[6]>>2);
      img->m7[5][i] =   b[6] - (b[5]>>2);
      img->m7[7][i] = - b[7] + (b[4]>>2);
    }
  }

  // Quant  
  nonzero=FALSE;
  
  run=-1;
  scan_pos=0;
  
  runs[0]=runs[1]=runs[2]=runs[3]=-1;
  scan_poss[0]=scan_poss[1]=scan_poss[2]=scan_poss[3]=0;
  
  for (coeff_ctr=0;coeff_ctr < 64;coeff_ctr++)
  {
    
    if (is_field_mode) 
    {  // Alternate scan for field coding
      i=FIELD_SCAN8x8[coeff_ctr][0];
      j=FIELD_SCAN8x8[coeff_ctr][1];
    }
    else 
    {
      i=SNGL_SCAN8x8[coeff_ctr][0];
      j=SNGL_SCAN8x8[coeff_ctr][1];
    }
    MCcoeff = MC(coeff_ctr);
    run++;
    ilev=0;
    
    runs[MCcoeff]++;
    
    if(lossless_qpprime)
      level = absm (img->m7[j][i]);
    else 
      level = (absm (img->m7[j][i]) * levelscale[i][j] + leveloffset[i][j]) >> q_bits;
  
    if (img->AdaptiveRounding)
    {
      if (lossless_qpprime || level == 0 )
      {
        img->fadjust8x8[intra][block_y+j][block_x+i] = 0;
      }
      else 
      {
        img->fadjust8x8[intra][block_y + j][block_x + i] = 
          (AdaptRndWeight * (absm (img->m7[j][i]) * levelscale[i][j] - (level << q_bits)) + (1<< (q_bits))) >> (q_bits + 1);       
      }
    }

    if (level != 0)
    {
      nonzero=TRUE;
      
      if (currMB->luma_transform_size_8x8_flag && input->symbol_mode == UVLC)
      {
        *coeff_cost += (level > 1) ? MAX_VALUE : COEFF_COST8x8[input->disthres][runs[MCcoeff]];

        img->cofAC[b8][MCcoeff][0][scan_poss[MCcoeff]] = sign(level,img->m7[j][i]);
        img->cofAC[b8][MCcoeff][1][scan_poss[MCcoeff]] = runs[MCcoeff];
        ++scan_poss[MCcoeff];
        runs[MCcoeff]=-1;
      }
      else
      {
        *coeff_cost += (level > 1) ? MAX_VALUE : COEFF_COST8x8[input->disthres][run];
        ACLevel[scan_pos] = sign(level,img->m7[j][i]);
        ACRun  [scan_pos] = run;
        ++scan_pos;
        run=-1;                     // reset zero level counter
      }      
      level = sign(level, img->m7[j][i]);
      if(lossless_qpprime)
      {
        ilev = level;
      }
      else 
      {
        if (qp_per>=6)
          ilev = level*invlevelscale[i][j]<<dq_lshift; // dequantization
        else
          ilev = (level*invlevelscale[i][j] + dq_round)>>dq_rshift; // dequantization
      }
    }
    if(!lossless_qpprime)
      img->m7[j][i] = ilev;
  }
  if (!currMB->luma_transform_size_8x8_flag || input->symbol_mode != UVLC)
    ACLevel[scan_pos] = 0;
  else
  {
    for(i=0; i<4; i++)
      img->cofAC[b8][i][0][scan_poss[i]] = 0;
  }
 
  
  //    Inverse Transform
  // horizontal inverse transform
  if (!lossless_qpprime)
  {
    for( i=0; i<8; i++)
    {
      a[0] = img->m7[i][0] + img->m7[i][4];
      a[4] = img->m7[i][0] - img->m7[i][4];
      a[2] = (img->m7[i][2]>>1) - img->m7[i][6];
      a[6] = img->m7[i][2] + (img->m7[i][6]>>1);
      
      b[0] = a[0] + a[6];
      b[2] = a[4] + a[2];
      b[4] = a[4] - a[2];
      b[6] = a[0] - a[6];
      
      a[1] = -img->m7[i][3] + img->m7[i][5] - img->m7[i][7] - (img->m7[i][7]>>1);
      a[3] =  img->m7[i][1] + img->m7[i][7] - img->m7[i][3] - (img->m7[i][3]>>1);
      a[5] = -img->m7[i][1] + img->m7[i][7] + img->m7[i][5] + (img->m7[i][5]>>1);
      a[7] =  img->m7[i][3] + img->m7[i][5] + img->m7[i][1] + (img->m7[i][1]>>1);
      
      b[1] = a[1] + (a[7]>>2);
      b[7] = -(a[1]>>2) + a[7];
      b[3] = a[3] + (a[5]>>2);
      b[5] = (a[3]>>2) - a[5];
      
      m6[0][i] = b[0] + b[7];
      m6[1][i] = b[2] + b[5];
      m6[2][i] = b[4] + b[3];
      m6[3][i] = b[6] + b[1];
      m6[4][i] = b[6] - b[1];
      m6[5][i] = b[4] - b[3];
      m6[6][i] = b[2] - b[5];
      m6[7][i] = b[0] - b[7];
    }
    
    // vertical inverse transform
    for( i=0; i<8; i++)
    {
      a[0] =  m6[i][0] + m6[i][4];
      a[4] =  m6[i][0] - m6[i][4];
      a[2] = (m6[i][2]>>1) - m6[i][6];
      a[6] =  m6[i][2] + (m6[i][6]>>1);
      
      b[0] = a[0] + a[6];
      b[2] = a[4] + a[2];
      b[4] = a[4] - a[2];
      b[6] = a[0] - a[6];
      
      a[1] = -m6[i][3] + m6[i][5] - m6[i][7] - (m6[i][7]>>1);
      a[3] =  m6[i][1] + m6[i][7] - m6[i][3] - (m6[i][3]>>1);
      a[5] = -m6[i][1] + m6[i][7] + m6[i][5] + (m6[i][5]>>1);
      a[7] =  m6[i][3] + m6[i][5] + m6[i][1] + (m6[i][1]>>1);
      
      b[1] =   a[1] + (a[7]>>2);
      b[7] = -(a[1]>>2) + a[7];
      b[3] =   a[3] + (a[5]>>2);
      b[5] =  (a[3]>>2) - a[5];
      
      img->m7[0][i] = b[0] + b[7];
      img->m7[1][i] = b[2] + b[5];
      img->m7[2][i] = b[4] + b[3];
      img->m7[3][i] = b[6] + b[1];
      img->m7[4][i] = b[6] - b[1];
      img->m7[5][i] = b[4] - b[3];
      img->m7[6][i] = b[2] - b[5];
      img->m7[7][i] = b[0] - b[7];
    }
  }
  
  if (!img->residue_transform_flag)
  {
    for( j=0; j<2*BLOCK_SIZE; j++)
    {
      pix_y = block_y+j;    
      ipix_y = img->pix_y + pix_y;
      for( i=0; i<2*BLOCK_SIZE; i++)
      {
        pix_x = block_x+i;
        if(lossless_qpprime)
          img->m7[j][i] = img->m7[j][i]+img->mpr[pix_y][block_x+i];
        else
          img->m7[j][i] = clip1a((img->m7[j][i]+((long)img->mpr[pix_y][pix_x] << DQ_BITS_8)+DQ_ROUND_8)>>DQ_BITS_8);
        enc_picture->imgY[ipix_y][img->pix_x + pix_x]=img->m7[j][i];
      }
    }
  }
  else if(!lossless_qpprime)
  {
    for( j=0; j<2*BLOCK_SIZE; j++)
      for( i=0; i<2*BLOCK_SIZE; i++)
        img->m7[j][i] =(img->m7[j][i]+DQ_ROUND_8)>>DQ_BITS_8;
  }
  
  //  Decoded block moved to frame memory
  
  return nonzero;
}

