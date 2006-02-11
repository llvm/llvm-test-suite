
/*!
 *************************************************************************************
 *
 * \file simplified_fast_me.c
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

#include <stdlib.h>
#include <string.h>

#include "global.h"
#include "memalloc.h"
#include "simplified_fast_me.h"
#include "refbuf.h"

extern  unsigned int *byte_abs;
extern           int *mvbits;

static const short Diamond_X[4]      = {-1, 1, 0, 0};
static const short Diamond_Y[4]      = { 0, 0,-1, 1};
static const short Hexagon_X[6]      = {-2, 2,-1, 1,-1, 1};
static const short Hexagon_Y[6]      = { 0, 0,-2, 2, 2,-2};
static const short Big_Hexagon_X[16] = {-4, 4, 0, 0,-4, 4,-4, 4,-4, 4,-4, 4,-2, 2,-2, 2};
static const short Big_Hexagon_Y[16] = { 0, 0,-4, 4,-1, 1, 1,-1,-2, 2, 2,-2,-3, 3, 3,-3};

static pel_t *(*get_line) (pel_t**, int, int, int, int);

// Macro for motion estimation cost computation per match
#define SEARCH_ONE_PIXEL_HELPER                                                         \
if(absm(cand_x - center_x) <= search_range && absm(cand_y - center_y) <= search_range)  \
{                                                                                       \
  mcost = MV_COST (lambda_factor, mvshift, cand_x, cand_y, pred_x, pred_y);             \
  mcost = simplified_partial_SAD_calculate(ref_pic, orig_pic, get_ref_line, height,     \
             blocksize_y, blocksize_x, blocksize_x4, mcost, min_mcost, cand_x, cand_y); \
  if (mcost < min_mcost)                                                                \
  {                                                                                     \
    best_x    = cand_x;                                                                 \
    best_y    = cand_y;                                                                 \
    min_mcost = mcost;                                                                  \
  }                                                                                     \
}

/*!
 ************************************************************************
 * \brief
 *    Set thresholds for fast motion estimation
 *    Those thresholds may be adjusted to trade off rate-distortion
 *    performance and FME speed
 ************************************************************************
 */
void simplified_init_FME()
{
  SymmetricalCrossSearchThreshold1 =  800;
  SymmetricalCrossSearchThreshold2 = 7000;
  ConvergeThreshold                = 1000;
  SubPelThreshold1                 = 1000;
  SubPelThreshold3                 =  400;
}

/*!
 ************************************************************************
 * \brief
 *    Allocation of space for fast motion estimation
 ************************************************************************
 */
int simplified_get_mem_FME()
{
  int memory_size = 0;
  if (NULL==(simplified_flag_intra = calloc((img->width>>4)+1, sizeof(byte))))
    no_mem_exit("simplified_get_mem_FME: simplified_flag_intra");

  memory_size += get_mem3Dint(&simplified_fastme_l0_cost, 9, img->height/4, img->width/4);
  memory_size += get_mem3Dint(&simplified_fastme_l1_cost, 9, img->height/4, img->width/4);
  memory_size += get_mem2D(&simplified_SearchState, 7, 7);
  
  return memory_size;
}

/*!
 ************************************************************************
 * \brief
 *    Free space for fast motion estimation
 ************************************************************************
 */
void simplified_free_mem_FME()
{
  free_mem3Dint(simplified_fastme_l0_cost, 9);
  free_mem3Dint(simplified_fastme_l1_cost, 9);
  free_mem2D(simplified_SearchState);

  free (simplified_flag_intra);
}

/*!
 ************************************************************************
 * \brief
 *    Partial SAD calculation for fast motion estimation
 ************************************************************************
 */
int simplified_partial_SAD_calculate(pel_t*   ref_pic,
               pel_t**  orig_pic,
               pel_t* (*get_ref_line)(int, pel_t*, int, int, int, int),
               int      height,
               int      blocksize_y,
               int      blocksize_x,
               int      blocksize_x4,
               int      mcost,
               int      min_mcost,
               int      cand_x,
               int      cand_y)
{
  unsigned short    y, x4;
  pel_t *orig_line, *ref_line;

  for (y = 0; y < blocksize_y; y++)
  {
    ref_line  = get_ref_line (blocksize_x, ref_pic, cand_y+y, cand_x, height, img->width);
    orig_line = orig_pic[y];
    
    for (x4 = 0; x4 < blocksize_x4; x4++)
    {
      mcost += byte_abs[ *orig_line++ - *ref_line++ ];
      mcost += byte_abs[ *orig_line++ - *ref_line++ ];
      mcost += byte_abs[ *orig_line++ - *ref_line++ ];
      mcost += byte_abs[ *orig_line++ - *ref_line++ ];
    }
    if (mcost >= min_mcost)
      break;
  }
  return mcost;
}

/*!
 ************************************************************************
 * \brief
 *    Add up SAD for sub pixel for fast motion estimation
 ************************************************************************
 */
int simplified_add_up_SAD_quarter_pel(int   pic_pix_x,
                    int                     pic_pix_y,
                    int                     blocksize_x,
                    int                     blocksize_y,
                    int                     cand_mv_x,
                    int                     cand_mv_y,
                    StorablePicture        *ref_picture,
                    pel_t**                 orig_pic,
                    int                     Mvmcost,
                    int                     min_mcost,
                    int                     useABT,
                    int                     blocktype)
{
  int j, i, k;  
  int diff[16], *d; 
  int mcost = Mvmcost;
  int c_diff[MB_PIXELS];
  int y_offset, ypels =(128 - ((blocktype == 3)<<6));
  int ry0, ry4, ry8, ry12;
  int y0, y1, y2, y3;
  int x0, x1, x2, x3;
  int abort_search, rx0; 
  int img_width  = (ref_picture->size_x + (IMG_PAD_SIZE<<1) - 1)<<2;
  int img_height = (ref_picture->size_y + (IMG_PAD_SIZE<<1) - 1)<<2;

  //===== Use weighted Reference for ME ====
  pel_t **ref_pic;      
  pel_t *ref_line;
  pel_t *orig_line;
  int    apply_weights = ( (active_pps->weighted_pred_flag && 
               (img->type == P_SLICE || img->type == SP_SLICE)) ||
          (active_pps->weighted_bipred_idc && (img->type == B_SLICE)) );  
  
  if (apply_weights && input->UseWeightedReferenceME)
  {
    ref_pic = ref_picture->imgY_ups_w;
  }
  else
  {
    ref_pic = ref_picture->imgY_ups;
  }

  for (y0 = 0, abort_search = 0; y0 < blocksize_y && !abort_search; y0 += 4)
  {
    y_offset = (y0>7)*ypels;
    ry0  = (y0<<2) + cand_mv_y;
    ry4  = ry0 + 4;
    ry8  = ry4 + 4;
    ry12 = ry8 + 4;
    y1   = y0  + 1;
    y2   = y1  + 1;
    y3   = y2  + 1;

    for (x0 = 0; x0 < blocksize_x; x0 += 4)
    {
      rx0 = (x0<<2) + cand_mv_x;
      x1  = x0 + 1;
      x2  = x1 + 1;
      x3  = x2 + 1;
      d   = diff;

      orig_line = orig_pic [y0];    
      ref_line  = get_line (ref_pic, ry0, rx0, img_height, img_width);
      *d++      = orig_line[x0] - *(ref_line     );
      *d++      = orig_line[x1] - *(ref_line + 4 );
      *d++      = orig_line[x2] - *(ref_line + 8 );
      *d++      = orig_line[x3] - *(ref_line + 12);

      orig_line = orig_pic [y1];    
      ref_line  = get_line (ref_pic, ry4, rx0, img_height, img_width);
      *d++      = orig_line[x0] - *(ref_line     );
      *d++      = orig_line[x1] - *(ref_line + 4 );
      *d++      = orig_line[x2] - *(ref_line + 8 );
      *d++      = orig_line[x3] - *(ref_line + 12);

      orig_line = orig_pic [y2];
      ref_line  = get_line (ref_pic, ry8, rx0, img_height, img_width);
      *d++      = orig_line[x0] - *(ref_line     );
      *d++      = orig_line[x1] - *(ref_line += 4);
      *d++      = orig_line[x2] - *(ref_line += 4);
      *d++      = orig_line[x3] - *(ref_line += 4);

      orig_line = orig_pic [y3];    
      ref_line  = get_line (ref_pic, ry12, rx0, img_height, img_width);
      *d++      = orig_line[x0] - *(ref_line     );
      *d++      = orig_line[x1] - *(ref_line += 4);
      *d++      = orig_line[x2] - *(ref_line += 4);
      *d        = orig_line[x3] - *(ref_line += 4);

      if (!useABT)
      {
        if ((mcost += SATD (diff, input->hadamard)) >= min_mcost) {
          abort_search = 1;
          break;
        }
      }
      else
      { // copy diff to curr_diff for ABT SATD calculation
        i = (x0&0x7) +  (x0>7) * 64 + y_offset;
        for(k=0, j=y0; j<BLOCK_SIZE + y0; j++, k+=BLOCK_SIZE)
        {
          memcpy(&(c_diff[i + ((j&0x7)<<3)]), &diff[k], BLOCK_SIZE*sizeof(int));
        }
      }
    }
  }

  // Adaptive Block Transform
  if(useABT)
  {
    mcost += find_SATD (c_diff, blocktype);
  }

  return mcost;
}

/*!
 ************************************************************************
 * \brief
 *    Fast integer pixel block motion estimation
 ************************************************************************
 */
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
               int       lambda_factor) // <--  lagrangian parameter for determining motion cost
{
  short mvshift       = 2;
  int   blocksize_y   = input->blc_size[blocktype][1];
  int   blocksize_x   = input->blc_size[blocktype][0];
  int   blocksize_x4  = blocksize_x >> 2;
  int   pred_x        = (pic_pix_x << mvshift) + pred_mv_x;
  int   pred_y        = (pic_pix_y << mvshift) + pred_mv_y;
  int   center_x      = pic_pix_x + *mv_x;
  int   center_y      = pic_pix_y + *mv_y;
  int   best_x        = 0, best_y = 0;
  int   search_step, iYMinNow, iXMinNow;
  int   cand_x, cand_y, mcost;

  unsigned short        i, m; 
  pel_t                *ref_pic;
  pel_t *(*get_ref_line)(int, pel_t*, int, int, int, int);

  short list_offset   = ((img->MbaffFrameFlag)&&(img->mb_data[img->current_mb_nr].mb_field))?
                          img->current_mb_nr%2 ? 4 : 2 : 0;
  int   height        = ((img->MbaffFrameFlag)&&(img->mb_data[img->current_mb_nr].mb_field))?
                         (img->height+1)>>1 : img->height;
   
  //===== Use weighted Reference for ME ====
  int  apply_weights = ( (active_pps->weighted_pred_flag  && 
                         (img->type == P_SLICE || img->type == SP_SLICE)) ||
                         (active_pps->weighted_bipred_idc && (img->type == B_SLICE)) );  

  if (apply_weights && input->UseWeightedReferenceME)
  {
    ref_pic       = listX[list+list_offset][ref]->imgY_11_w;
  }
  else
  {
    ref_pic       = listX[list+list_offset][ref]->imgY_11;
  }

  //===== set function for getting reference picture lines =====
  if ((center_x > search_range) && (center_x < img->width-1-search_range-blocksize_x) &&
      (center_y > search_range) && (center_y < height-1-search_range-blocksize_y))
  {
    get_ref_line = FastLineX;
  }
  else
  {
    get_ref_line = UMVLineX;
  }
 
  // Check the center median predictor
  cand_x = center_x ;
  cand_y = center_y ;
  mcost  = MV_COST    (lambda_factor, mvshift, cand_x, cand_y, pred_x, pred_y);
  mcost  = simplified_partial_SAD_calculate (ref_pic, orig_pic, get_ref_line,
                       height, blocksize_y, blocksize_x,
                       blocksize_x4, mcost, min_mcost, cand_x, cand_y);

  if (mcost < min_mcost)
  {
    min_mcost = mcost;
    best_x    = cand_x;
    best_y    = cand_y;
  }

  iXMinNow = best_x;
  iYMinNow = best_y;
  if ((0 != pred_mv_x) || (0 != pred_mv_y))
  {
    cand_x = pic_pix_x;
    cand_y = pic_pix_y;
    SEARCH_ONE_PIXEL_HELPER
  } 

  // If the min_mcost is small enough, do a local search then terminate
  // Ihis is good for stationary or quasi-stationary areas
  if (min_mcost < (ConvergeThreshold>>block_type_shift_factor[blocktype]))
  {
    for (m = 0; m < 4; m++)
    {   
      cand_x = iXMinNow + Diamond_X[m];
      cand_y = iYMinNow + Diamond_Y[m];
      SEARCH_ONE_PIXEL_HELPER
    }
    *mv_x = best_x - pic_pix_x;
    *mv_y = best_y - pic_pix_y; 
    return min_mcost;
  }

  // Small local search
  for (m = 0; m < 4; m++)
  {   
    cand_x = iXMinNow + Diamond_X[m];
    cand_y = iYMinNow + Diamond_Y[m];
    SEARCH_ONE_PIXEL_HELPER
  }

  // First_step: Symmetrical-cross search
  // If distortion is large, use large shapes. Otherwise, compact shapes are faster
  if ( (blocktype == 1 && 
        min_mcost > (SymmetricalCrossSearchThreshold1>>block_type_shift_factor[blocktype])) ||
       (min_mcost > (SymmetricalCrossSearchThreshold2>>block_type_shift_factor[blocktype])) )
  {
    iXMinNow = best_x;
    iYMinNow = best_y;

    for(i = 1; i <= search_range/2; i++)
    {
      search_step = (i<<1) - 1;
      cand_x = iXMinNow + search_step;
      cand_y = iYMinNow;
      SEARCH_ONE_PIXEL_HELPER

      cand_x = iXMinNow - search_step;
      SEARCH_ONE_PIXEL_HELPER

      cand_x = iXMinNow;
      cand_y = iYMinNow + search_step;
      SEARCH_ONE_PIXEL_HELPER

      cand_y = iYMinNow - search_step;
      SEARCH_ONE_PIXEL_HELPER
    }

    // Hexagon Search
    iXMinNow = best_x;
    iYMinNow = best_y;
    for (m = 0; m < 6; m++)
    {
      cand_x = iXMinNow + Hexagon_X[m];
      cand_y = iYMinNow + Hexagon_Y[m];
      SEARCH_ONE_PIXEL_HELPER
    }
    // Multi Big Hexagon Search
    iXMinNow = best_x;
    iYMinNow = best_y;
    for(i = 1; i <= search_range/4; i++)
    {
      for (m = 0; m < 16; m++)
      {
        cand_x = iXMinNow + Big_Hexagon_X[m]*i;
        cand_y = iYMinNow + Big_Hexagon_Y[m]*i;
        SEARCH_ONE_PIXEL_HELPER
      }
    }
  }

  // Search up_layer predictor for non 16x16 blocks
  if (blocktype > 1)
  {
    cand_x = pic_pix_x + (simplified_pred_MV_uplayer_X/4);
    cand_y = pic_pix_y + (simplified_pred_MV_uplayer_Y/4);
    SEARCH_ONE_PIXEL_HELPER
  }

  if(center_x != pic_pix_x || center_y != pic_pix_y)
  {
    cand_x = pic_pix_x;
    cand_y = pic_pix_y;
    SEARCH_ONE_PIXEL_HELPER

    iXMinNow = best_x;
    iYMinNow = best_y;
    // Local diamond search
    for (m = 0; m < 4; m++)
    {   
      cand_x = iXMinNow + Diamond_X[m];
      cand_y = iYMinNow + Diamond_Y[m];
      SEARCH_ONE_PIXEL_HELPER
    }
  }

  // If the minimum cost is small enough, do a local search
  // and finish the search here
  if (min_mcost < (ConvergeThreshold>>block_type_shift_factor[blocktype]))
  {
    iXMinNow = best_x;
    iYMinNow = best_y;
    for (m = 0; m < 4; m++)
    {   
      cand_x = iXMinNow + Diamond_X[m];
      cand_y = iYMinNow + Diamond_Y[m];
      SEARCH_ONE_PIXEL_HELPER
    }
    *mv_x = best_x - pic_pix_x;
    *mv_y = best_y - pic_pix_y; 
    return min_mcost;
  }

  //second_step:  Extended Hexagon-based Search
  for(i = 0; i < search_range; i++)
  {
    iXMinNow = best_x;
    iYMinNow = best_y;
    for (m = 0; m < 6; m++)
    {
      cand_x = iXMinNow + Hexagon_X[m];
      cand_y = iYMinNow + Hexagon_Y[m];
      SEARCH_ONE_PIXEL_HELPER
    }
    // The minimum cost point happens in the center
    if (best_x == iXMinNow && best_y == iYMinNow)
    {
      break;
    }
  }

  //third_step: Small diamond search
  for(i = 0; i < search_range; i++)
  {
    iXMinNow = best_x;
    iYMinNow = best_y;
    for (m = 0; m < 4; m++)
    {
      cand_x = iXMinNow + Diamond_X[m];
      cand_y = iYMinNow + Diamond_Y[m];
      SEARCH_ONE_PIXEL_HELPER
    }

    // The minimum cost point happens in the center
    if (best_x == iXMinNow && best_y == iYMinNow)
    {
      break;
    }
  }

  *mv_x = best_x - pic_pix_x;
  *mv_y = best_y - pic_pix_y; 
  return min_mcost;
}

/*!
 ************************************************************************
 * \brief
 *    Fast sub pixel block motion estimation 
 ************************************************************************
 */
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
               short*    mv_x,          // <--> in: search center (x) / out: MV (x) - in pel units
               short*    mv_y,          // <--> in: search center (y) / out: MV (y) - in pel units
               int       search_pos2,   // <--  search positions for    half-pel search  (default: 9)
               int       search_pos4,   // <--  search positions for quarter-pel search  (default: 9)
               int       min_mcost,     // <--  minimum motion cost (cost for center or huge value)
               int       lambda_factor, // <--  lagrangian parameter for determining motion cost
               int       useABT)
{
  int   mcost;
  int   cand_mv_x, cand_mv_y;
  
  int   list_offset     = ((img->MbaffFrameFlag) &&
                           (img->mb_data[img->current_mb_nr].mb_field)) ?
                            img->current_mb_nr%2 ? 4 : 2 : 0;
  StorablePicture *ref_picture = listX[list+list_offset][ref];
  
  short mv_shift        = 0;
  short blocksize_x     = input->blc_size[blocktype][0];
  short blocksize_y     = input->blc_size[blocktype][1];
  int   pic4_pix_x      = ((pic_pix_x + IMG_PAD_SIZE)<<2);
  int   pic4_pix_y      = ((pic_pix_y + IMG_PAD_SIZE)<<2);
  short max_pos_x4      = ((ref_picture->size_x - blocksize_x + 2*IMG_PAD_SIZE)<<2);
  short max_pos_y4      = ((ref_picture->size_y - blocksize_y + 2*IMG_PAD_SIZE)<<2);
  
  int   iXMinNow, iYMinNow;
  short dynamic_search_range, i, m;
  int   currmv_x = 0, currmv_y = 0;
  int   pred_frac_mv_x,pred_frac_mv_y,abort_search;
  int   mv_cost;
  int   pred_frac_up_mv_x, pred_frac_up_mv_y;

  if ((pic4_pix_x + *mv_x > 1) && (pic4_pix_x + *mv_x < max_pos_x4 - 1) &&
      (pic4_pix_y + *mv_y > 1) && (pic4_pix_y + *mv_y < max_pos_y4 - 1))
  {
    get_line = FastLine4X;
  }
  else
  {
    get_line = UMVLine4X;    
  }
  
  dynamic_search_range = 3;
  pred_frac_mv_x = (pred_mv_x - *mv_x) % 4;
  pred_frac_mv_y = (pred_mv_y - *mv_y) % 4; 
  
  pred_frac_up_mv_x = (simplified_pred_MV_uplayer_X - *mv_x) % 4;
  pred_frac_up_mv_y = (simplified_pred_MV_uplayer_Y - *mv_y) % 4;

  memset(simplified_SearchState[0], 0, 
         (2*dynamic_search_range+1)*(2*dynamic_search_range+1));

  simplified_SearchState[dynamic_search_range][dynamic_search_range] = 1;
  if(input->hadamard)
  {
    cand_mv_x = *mv_x;    
    cand_mv_y = *mv_y;    
    mv_cost   = MV_COST (lambda_factor, mv_shift, cand_mv_x, cand_mv_y, pred_mv_x, pred_mv_y);
    mcost     = simplified_add_up_SAD_quarter_pel(pic_pix_x, pic_pix_y, blocksize_x, blocksize_y,
                                cand_mv_x + pic4_pix_x, cand_mv_y + pic4_pix_y,
                                ref_picture, orig_pic, mv_cost, min_mcost, useABT, blocktype);
    if (mcost < min_mcost)
    {
      min_mcost = mcost;
      currmv_x  = cand_mv_x;
      currmv_y  = cand_mv_y; 
    }
  }
  else
  {
    currmv_x = *mv_x;
    currmv_y = *mv_y; 
  }

  // If the min_mcost is small enough and other statistics are positive,
  // better to stop the search now
  if ( ((*mv_x) == 0) && ((*mv_y) == 0) && 
	    (pred_frac_mv_x == 0 && pred_frac_up_mv_x == 0) &&
        (pred_frac_mv_y == 0 && pred_frac_up_mv_y == 0) &&
        (min_mcost < (SubPelThreshold1>>block_type_shift_factor[blocktype])) )
  {
    *mv_x = currmv_x;
    *mv_y = currmv_y;
	return min_mcost;
  }

  if(pred_frac_mv_x || pred_frac_mv_y)
  {
    cand_mv_x = *mv_x + pred_frac_mv_x;    
    cand_mv_y = *mv_y + pred_frac_mv_y;    
    mv_cost   = MV_COST (lambda_factor, mv_shift, cand_mv_x, cand_mv_y, pred_mv_x, pred_mv_y);    
    mcost     = simplified_add_up_SAD_quarter_pel(pic_pix_x, pic_pix_y, blocksize_x, blocksize_y,
                            cand_mv_x + pic4_pix_x, cand_mv_y + pic4_pix_y,
                            ref_picture, orig_pic,mv_cost, min_mcost, useABT, blocktype);
    simplified_SearchState[cand_mv_y -*mv_y + dynamic_search_range][cand_mv_x - *mv_x + dynamic_search_range] = 1;
    if (mcost < min_mcost)
    {
      min_mcost = mcost;
      currmv_x  = cand_mv_x;
      currmv_y  = cand_mv_y; 
    }
  }

  // Multiple small diamond search
  for(i = 0; i < dynamic_search_range; i++)
  {
    abort_search = 1;

    iXMinNow = currmv_x;
    iYMinNow = currmv_y;
    for (m = 0; m < 4; m++)
    {
      cand_mv_x = iXMinNow + Diamond_X[m];    
      cand_mv_y = iYMinNow + Diamond_Y[m]; 

      if(absm(cand_mv_x - *mv_x) <= dynamic_search_range && absm(cand_mv_y - *mv_y) <= dynamic_search_range)
      {
        if(!simplified_SearchState[cand_mv_y - *mv_y + dynamic_search_range][cand_mv_x - *mv_x + dynamic_search_range])
        {
          mv_cost = MV_COST (lambda_factor, mv_shift, cand_mv_x, cand_mv_y, pred_mv_x, pred_mv_y);    
          mcost   = simplified_add_up_SAD_quarter_pel(pic_pix_x, pic_pix_y, blocksize_x, blocksize_y,
                                  cand_mv_x + pic4_pix_x, cand_mv_y + pic4_pix_y,
                                  ref_picture, orig_pic, mv_cost, min_mcost, useABT, blocktype);
          simplified_SearchState[cand_mv_y - *mv_y + dynamic_search_range][cand_mv_x - *mv_x + dynamic_search_range] = 1;

          if (mcost < min_mcost)
          {
            min_mcost    = mcost;
            currmv_x     = cand_mv_x;
            currmv_y     = cand_mv_y; 
            abort_search = 0; 
          }
          if (min_mcost < (SubPelThreshold3>>block_type_shift_factor[blocktype]))
          {
            *mv_x = currmv_x;
            *mv_y = currmv_y;
            return min_mcost;
          }
        }
      }
    }
    // If the minimum cost point is in the center, break out the loop
    if (abort_search)
    {
      break;
    }
  }
  
  *mv_x = currmv_x;
  *mv_y = currmv_y;
  return min_mcost;
}

/*!
 ************************************************************************
 * \brief
 *    Set neighbouring block mode (intra/inter)
 *    used for fast motion estimation
 ************************************************************************
 */
void simplified_decide_intrabk_SAD()
{
  if (img->type != I_SLICE)
  {
    if (img->pix_x == 0 && img->pix_y == 0)
    {
      simplified_flag_intra_SAD = 0;
    }
    else if (img->pix_x == 0)
    {
      simplified_flag_intra_SAD = simplified_flag_intra[(img->pix_x)>>4];
    }
    else if (img->pix_y == 0)
    {
      simplified_flag_intra_SAD = simplified_flag_intra[((img->pix_x)>>4)-1];
    }
    else
    {
      simplified_flag_intra_SAD = ((simplified_flag_intra[(img->pix_x)>>4])||
                                   (simplified_flag_intra[((img->pix_x)>>4)-1])||
                                   (simplified_flag_intra[((img->pix_x)>>4)+1])) ;
    }
  }
  return;
}

/*!
 ************************************************************************
 * \brief
 *    Set cost to zero if neighbouring block is intra
 *    used for fast motion estimation
 ************************************************************************
 */
void simplified_skip_intrabk_SAD(int best_mode, int ref_max)
{
  short i, j, k;

  if (img->number > 0)
  {
    simplified_flag_intra[(img->pix_x)>>4] = (best_mode == 9 || best_mode == 10) ? 1 : 0;
  }

  if (img->type != I_SLICE  && (best_mode == 9 || best_mode == 10))
  {
    for (i=0; i < 4; i++)
    {
      for (j=0; j < 4; j++)
      {
        for (k=0; k < 9;k++)
        {
          simplified_fastme_l0_cost[k][j][i] = 0;
          simplified_fastme_l1_cost[k][j][i] = 0;
        }
      }
    }
  }
  return;
}

/*!
 ************************************************************************
 * \brief
 *    Set up prediction MV and prediction up layer cost
 *    used for fast motion estimation
 ************************************************************************
 */
void simplified_setup_FME(short ref,
                          int list,
                          int block_y,
                          int block_x,
                          int blocktype,
                          short ******all_mv)
{
  if (blocktype > 6)
  {
    simplified_pred_MV_uplayer_X = all_mv[block_y][block_x][list][ref][5][0];
    simplified_pred_MV_uplayer_Y = all_mv[block_y][block_x][list][ref][5][1];
  }
  else if (blocktype > 4)
  {
    simplified_pred_MV_uplayer_X = all_mv[block_y][block_x][list][ref][4][0];
    simplified_pred_MV_uplayer_Y = all_mv[block_y][block_x][list][ref][4][1];
  }
  else if (blocktype == 4)
  {
    simplified_pred_MV_uplayer_X = all_mv[block_y][block_x][list][ref][2][0];
    simplified_pred_MV_uplayer_Y = all_mv[block_y][block_x][list][ref][2][1];
  }
  else if (blocktype > 1)
  {
    simplified_pred_MV_uplayer_X = all_mv[block_y][block_x][list][ref][1][0];
    simplified_pred_MV_uplayer_Y = all_mv[block_y][block_x][list][ref][1][1];
  }

  if (blocktype > 1)
  {
    if (blocktype > 6)
    {   
      simplified_pred_SAD_uplayer = (list==1) ? 
          (simplified_fastme_l1_cost[5][(img->pix_y>>2)+block_y][(img->pix_x>>2)+block_x])
          : (simplified_fastme_l0_cost[5][(img->pix_y>>2)+block_y][(img->pix_x>>2)+block_x]);
      simplified_pred_SAD_uplayer /= 2; 	     
    }
    else if (blocktype > 4)
    {
      simplified_pred_SAD_uplayer = (list==1) ?
          (simplified_fastme_l1_cost[4][(img->pix_y>>2)+block_y][(img->pix_x>>2)+block_x])
          : (simplified_fastme_l0_cost[4][(img->pix_y>>2)+block_y][(img->pix_x>>2)+block_x]);
      simplified_pred_SAD_uplayer /= 2; 
    }
    else if (blocktype == 4)
    {
      simplified_pred_SAD_uplayer = (list==1) ?
          (simplified_fastme_l1_cost[2][(img->pix_y>>2)+block_y][(img->pix_x>>2)+block_x])
          : (simplified_fastme_l0_cost[2][(img->pix_y>>2)+block_y][(img->pix_x>>2)+block_x]);
      simplified_pred_SAD_uplayer /= 2; 
    }
    else
    {
      simplified_pred_SAD_uplayer = (list==1) ?
          (simplified_fastme_l1_cost[1][(img->pix_y>>2)+block_y][(img->pix_x>>2)+block_x])
          : (simplified_fastme_l0_cost[1][(img->pix_y>>2)+block_y][(img->pix_x>>2)+block_x]);
      simplified_pred_SAD_uplayer /= 2;
    }

    simplified_pred_SAD_uplayer = simplified_flag_intra_SAD ? 0 : simplified_pred_SAD_uplayer;
  }
}

