
/*!
 ***************************************************************************
 * \file mode_decision.c
 *
 * \brief
 *    Main macroblock mode decision functions and helpers
 *
 **************************************************************************
 */

#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <memory.h>

#include "global.h"
#include "rdopt_coding_state.h"
#include "mb_access.h"
#include "intrarefresh.h"
#include "image.h"
#include "transform8x8.h"
#include "fast_me.h"
#include "simplified_fast_me.h"
#include "ratectl.h"            
#include "mode_decision.h"

//==== MODULE PARAMETERS ====
imgpel temp_imgY[16][16]; // to temp store the Y data for 8x8 transform
imgpel temp_imgU[16][16];
imgpel temp_imgV[16][16];

const int  b8_mode_table[6]  = {0, 4, 5, 6, 7};         // DO NOT CHANGE ORDER !!!
const int  mb_mode_table[9]  = {0, 1, 2, 3, P8x8, I16MB, I4MB, I8MB, IPCM}; // DO NOT CHANGE ORDER !!!
// Residue Color Transform
const int  mb_mode_table_RCT[11]  = {0, 1, 2, 3, P8x8, I16MB, I16MB, I16MB, I16MB, I4MB, I8MB};

/*!
*************************************************************************************
* \brief
*    Update Rate Control Difference
*************************************************************************************
*/
void rc_store_diff(int cpix_x, int cpix_y, imgpel prediction[16][16])
{
  int i,j;
  int pix_x, pix_y;
  
  for (i=0; i<MB_BLOCK_SIZE; i++)
  {
    pix_x = cpix_x + i;
    for(j=0; j<MB_BLOCK_SIZE; j++)
    {
      pix_y = cpix_y + j;
      diffy[j][i] = imgY_org[pix_y][pix_x] - prediction[j][i];
    }
  } 
}

/*!
*************************************************************************************
* \brief
*    Update Rate Control Parameters
*************************************************************************************
*/
void update_rc(Macroblock *currMB, short best_mode)
{
  if(img->type==P_SLICE)
  {
    img->MADofMB[img->current_mb_nr] = calc_MAD();
    
    if(input->basicunit<img->Frame_Total_Number_MB)
    {
      img->TotalMADBasicUnit +=img->MADofMB[img->current_mb_nr];
      
      // delta_qp is present only for non-skipped macroblocks
      if ((currMB->cbp!=0 || best_mode==I16MB))
        currMB->prev_cbp = 1;
      else
      {
        currMB->delta_qp = 0;
        currMB->qp = currMB->prev_qp;
        img->qp = currMB->qp;
        currMB->prev_cbp = 0;
      }
      // When MBAFF is used, delta_qp is only present for 
      // the first non-skipped macroblock of each macroblock pair
      if (input->MbInterlace)
      {
        if(!currMB->mb_field)
        {
          DELTA_QP = currMB->delta_qp;
          QP       = currMB->qp;
        }
        else
        {
          DELTA_QP2 = currMB->delta_qp;
          QP2       = currMB->qp;
        }
      }       
    }
  }
}

/*!
*************************************************************************************
* \brief
*    Fast intra decision
*************************************************************************************
*/
void fast_mode_intra_decision(short *intra_skip, double min_rate)
{
  int i;
  int mb_available_up, mb_available_left, mb_available_up_left;
  long SBE;
  double AR = 0, ABE = 0;
  PixelPos up;       //!< pixel position p(0,-1)
  PixelPos left[2];  //!< pixel positions p(-1, -1..0)   
  
  for (i=0;i<2;i++)
  {
    getNeighbour(img->current_mb_nr, -1 ,  i-1 , 0, &left[i]);
  }
  getNeighbour(img->current_mb_nr, 0     ,  -1 , 0, &up);
  
  mb_available_up       = up.available;
  mb_available_up_left  = left[0].available;
  mb_available_left     = left[1].available;
  
  AR=(1.0/384)*min_rate;
  
  SBE = 0;
  
  if( (img->mb_y != (int)img->FrameHeightInMbs-1) && (img->mb_x != (int)img->PicWidthInMbs-1) && mb_available_left && mb_available_up)
  {
    for(i = 0; i < MB_BLOCK_SIZE; i++)
    {
      SBE += abs(imgY_org[img->opix_y][img->opix_x+i] - enc_picture->imgY[img->pix_y-1][img->pix_x+i]);
      SBE += abs(imgY_org[img->opix_y+i][img->opix_x] - enc_picture->imgY[img->pix_y+i][img->pix_x-1]);
    }
    for(i = 0; i < 8; i++)
    {
      SBE += abs(imgUV_org[0][img->opix_c_y][img->opix_c_x+i] - enc_picture->imgUV[0][img->pix_c_y-1][img->pix_c_x+i]);
      SBE += abs(imgUV_org[0][img->opix_c_y+i][img->opix_c_x] - enc_picture->imgUV[0][img->pix_c_y+i][img->pix_c_x-1]);
      SBE += abs(imgUV_org[1][img->opix_c_y][img->opix_c_x+i] - enc_picture->imgUV[1][img->pix_c_y-1][img->pix_c_x+i]);
      SBE += abs(imgUV_org[1][img->opix_c_y+i][img->opix_c_x] - enc_picture->imgUV[1][img->pix_c_y+i][img->pix_c_x-1]);
    }            
    ABE = 1.0/64 * SBE;
  }
  else  // Image boundary
  {
    ABE = 0; 
  }
  
  if(AR <= ABE)
  {
    *intra_skip = 1;
  }
}

/*!
*************************************************************************************
* \brief
*    Initialize Encoding parameters for Macroblock
*************************************************************************************
*/
void init_enc_mb_params(Macroblock* currMB, RD_PARAMS *enc_mb, int intra, int bslice)
{
  int mode;
  int l,k;
  
  //Setup list offset
  enc_mb->list_offset[LIST_0] = LIST_0 + currMB->list_offset;
  enc_mb->list_offset[LIST_1] = LIST_1 + currMB->list_offset;
  
  enc_mb->curr_mb_field = ((img->MbaffFrameFlag)&&(currMB->mb_field));  
  enc_mb->best_ref[LIST_0] = 0;
  enc_mb->best_ref[LIST_1] = -1;
  
  // Set valid modes
  enc_mb->valid[I8MB]  = input->Transform8x8Mode;
  enc_mb->valid[I4MB]  = (input->Transform8x8Mode==2) ? 0:1;
  enc_mb->valid[I16MB] = 1;
  enc_mb->valid[IPCM]  = (input->symbol_mode != CABAC && input->EnableIPCM);
  
  enc_mb->valid[0]     = (!intra );
  enc_mb->valid[1]     = (!intra && input->InterSearch16x16);
  enc_mb->valid[2]     = (!intra && input->InterSearch16x8);
  enc_mb->valid[3]     = (!intra && input->InterSearch8x16);
  enc_mb->valid[4]     = (!intra && input->InterSearch8x8);
  enc_mb->valid[5]     = (!intra && input->InterSearch8x4 && !(input->Transform8x8Mode==2));
  enc_mb->valid[6]     = (!intra && input->InterSearch4x8 && !(input->Transform8x8Mode==2));
  enc_mb->valid[7]     = (!intra && input->InterSearch4x4 && !(input->Transform8x8Mode==2));
  enc_mb->valid[P8x8]  = (enc_mb->valid[4] || enc_mb->valid[5] || enc_mb->valid[6] || enc_mb->valid[7]);
  enc_mb->valid[12]    = (img->type == SI_SLICE);

  
  //===== SET LAGRANGE PARAMETERS =====
  // Note that these are now computed at the slice level to reduce
  // computations and cleanup code.
  if (bslice && img->nal_reference_idc)
  {
    enc_mb->lambda_md = img->lambda_md[5][img->qp];
    enc_mb->lambda_me = img->lambda_me[5][img->qp];
    enc_mb->lambda_mf = img->lambda_mf[5][img->qp];
  }
  else
  {
    enc_mb->lambda_md = img->lambda_md[img->type][img->qp];
    enc_mb->lambda_me = img->lambda_me[img->type][img->qp];
    enc_mb->lambda_mf = img->lambda_mf[img->type][img->qp];
  }
  
  // Initialize bipredME decisions
  for (mode=0; mode<MAXMODE; mode++)
  {
    img->bi_pred_me[mode]=0;
  }
  
  if (!img->MbaffFrameFlag)
  {
    for (l = LIST_0; l < BI_PRED; l++)
    {
      for(k = 0; k < listXsize[l]; k++)
      {
        listX[l][k]->chroma_vector_adjustment= 0;
        if(img->structure == TOP_FIELD && img->structure != listX[l][k]->structure)
          listX[l][k]->chroma_vector_adjustment = -2;
        if(img->structure == BOTTOM_FIELD && img->structure != listX[l][k]->structure)
          listX[l][k]->chroma_vector_adjustment = 2;
      }
    }
  }
  else
  {
    if (enc_mb->curr_mb_field)
    {
      for (l = enc_mb->list_offset[LIST_0]; l <= enc_mb->list_offset[LIST_1]; l++)
      {
        for(k = 0; k < listXsize[l]; k++)
        {
          listX[l][k]->chroma_vector_adjustment= 0;
          if(img->current_mb_nr % 2 == 0 && listX[l][k]->structure == BOTTOM_FIELD)
            listX[l][k]->chroma_vector_adjustment = -2;
          if(img->current_mb_nr % 2 == 1 && listX[l][k]->structure == TOP_FIELD)
            listX[l][k]->chroma_vector_adjustment = 2;
        }
      }
    }
    else
    {
      for (l = enc_mb->list_offset[LIST_0]; l <= enc_mb->list_offset[LIST_1]; l++)
      {
        for(k = 0; k < listXsize[l]; k++)
          listX[l][k]->chroma_vector_adjustment= 0;
      }
    }    
  } 
}

/*!
*************************************************************************************
* \brief
*    computation of prediction list (including biprediction) cost
*************************************************************************************
*/
void list_prediction_cost(int list, int block, int mode, RD_PARAMS enc_mb, int bmcost[5], char best_ref[2])
{
  short ref;
  int mcost;
  int cur_list = list < BI_PRED ? enc_mb.list_offset[list] : enc_mb.list_offset[LIST_0];
  
  //--- get cost and reference frame for forward prediction ---
  
  if (list < BI_PRED)
  {
    for (ref=0; ref < listXsize[cur_list]; ref++)
    {
      if (!img->checkref || list || ref==0 || CheckReliabilityOfRef (block, list, ref, mode))
      {
        mcost  = (input->rdopt 
          ? REF_COST (enc_mb.lambda_mf, ref, cur_list) 
          : (int) (2 * enc_mb.lambda_me * min(ref, 1)));     
        
        mcost += motion_cost[mode][list][ref][block];
        if (mcost < bmcost[list])
        {
          bmcost[list]   = mcost;
          best_ref[list] = (char)ref;
        }
      }
    }
  }
  else if (list == BI_PRED)
  {
    bmcost[list]  = (input->rdopt 
      ? (REF_COST  (enc_mb.lambda_mf, (short)best_ref[LIST_0], cur_list)
      +  REF_COST  (enc_mb.lambda_mf, (short)best_ref[LIST_1], cur_list + LIST_1)) 
      : (int) (2 * (enc_mb.lambda_me * (min((short)best_ref[LIST_0], 1) + min((short)best_ref[LIST_1], 1)))));    
    bmcost[list] += BIDPartitionCost (mode, block, (short)best_ref[LIST_0], (short)best_ref[LIST_1], enc_mb.lambda_mf);    
  }
  else
  {
    bmcost[list]  = (input->rdopt 
      ? (REF_COST (enc_mb.lambda_mf, 0, cur_list) 
      +  REF_COST (enc_mb.lambda_mf, 0, cur_list + LIST_1)) 
      : (int) (4 * enc_mb.lambda_me));
    bmcost[list] += BPredPartitionCost(mode, block, 0, 0, enc_mb.lambda_mf, !(list&1));                
  }
}  

int compute_ref_cost(RD_PARAMS enc_mb, int ref, int list)
{  
  return WEIGHTED_COST(enc_mb.lambda_mf,((listXsize[enc_mb.list_offset[list]] <= 1)? 0:refbits[ref]));
}

/*!
*************************************************************************************
* \brief
*    Determination of prediction list based on simple distortion computation
*************************************************************************************
*/
void determine_prediction_list(int mode, int bmcost[5], char best_ref[2], short *best_pdir, int *cost, short *bi_pred_me)
{  
  if ((!input->BiPredMotionEstimation) || (mode != 1))
  {               
    //--- get prediction direction ----
    if  (bmcost[LIST_0] <= bmcost[LIST_1] 
      && bmcost[LIST_0] <= bmcost[BI_PRED])
    {
      *best_pdir = 0;
//      if(*cost!=INT_MAX)
        *cost += bmcost[LIST_0];
      //best_ref[LIST_1] = 0;
    }
    else if (bmcost[LIST_1] <= bmcost[LIST_0] 
      &&     bmcost[LIST_1] <= bmcost[BI_PRED])
    {
      *best_pdir = 1;
//      if(*cost!=INT_MAX)
        *cost += bmcost[LIST_1];
      //best_ref[LIST_0] = 0;
    }
    else
    {
      *best_pdir = 2;
//      if((bmcost[BI_PRED]==INT_MAX) | (*cost==INT_MAX))
//        *cost=INT_MAX;
//      else
        *cost += bmcost[BI_PRED];
      //best_ref[LIST_1] = 0;
    }
  }
  else
  {                            
    img->bi_pred_me[mode]=0;
    *bi_pred_me = 0;
    //--- get prediction direction ----
    if  (bmcost[LIST_0] <= bmcost[LIST_1] 
      && bmcost[LIST_0] <= bmcost[BI_PRED] 
      && bmcost[LIST_0] <= bmcost[BI_PRED_L0] 
      && bmcost[LIST_0] <= bmcost[BI_PRED_L1])
    {
      *best_pdir = 0;
      *cost += bmcost[LIST_0];
      //best_ref[LIST_1] = 0;
    }
    else if (bmcost[LIST_1] <= bmcost[LIST_0] 
      &&     bmcost[LIST_1] <= bmcost[BI_PRED] 
      &&     bmcost[LIST_1] <= bmcost[BI_PRED_L0] 
      &&     bmcost[LIST_1] <= bmcost[BI_PRED_L1])
    {
      *best_pdir = 1;
      *cost += bmcost[LIST_1];
      //best_ref[LIST_0] = 0;
    }
    else if (bmcost[BI_PRED] <= bmcost[LIST_0] 
      &&     bmcost[BI_PRED] <= bmcost[LIST_1] 
      &&     bmcost[BI_PRED] <= bmcost[BI_PRED_L0] 
      &&     bmcost[BI_PRED] <= bmcost[BI_PRED_L1])
    {
      *best_pdir = 2;
      *cost += bmcost[BI_PRED];
      //best_ref[LIST_1] = 0;  
    }
    else if (bmcost[BI_PRED_L0] <= bmcost[LIST_0] 
      &&     bmcost[BI_PRED_L0] <= bmcost[LIST_1] 
      &&     bmcost[BI_PRED_L0] <= bmcost[BI_PRED]
      &&     bmcost[BI_PRED_L0] <= bmcost[BI_PRED_L1])
    {
      *best_pdir = 2;
      *cost += bmcost[BI_PRED_L0];                  
      *bi_pred_me = 1;
      img->bi_pred_me[mode]=1;
      best_ref[LIST_1] = 0;
      best_ref[LIST_0] = 0;
    }
    else
    {
      *best_pdir = 2;
      *cost += bmcost[BI_PRED_L1];                                  
      *bi_pred_me = 2;
      best_ref[LIST_1] = 0;
      best_ref[LIST_0] = 0;
      img->bi_pred_me[mode]=2;
    }               
  }
}

/*!
*************************************************************************************
* \brief
*    RD decision process
*************************************************************************************
*/
void compute_mode_RD_cost(int mode, 
                          Macroblock *currMB, 
                          RD_PARAMS enc_mb, 
                          double *min_rdcost, 
                          double *min_rate, 
                          int i16mode, 
                          short bslice, 
                          short *inter_skip)
{
  //--- transform size ---           
  currMB->luma_transform_size_8x8_flag = input->Transform8x8Mode==2
    ?  (mode >= 1 && mode <= 3)
    || (mode == 0 && bslice && active_sps->direct_8x8_inference_flag)
    || ((mode == P8x8) && (enc_mb.valid[4]))
    :  0;
  
  SetModesAndRefframeForBlocks (mode);
  
  // Encode with coefficients
  img->NoResidueDirect = 0;  
  if (currMB->c_ipred_mode == DC_PRED_8 || (IS_INTRA(currMB) ))
  {
    while(1)
    {
      if (RDCost_for_macroblocks (enc_mb.lambda_md, mode, min_rdcost, min_rate, i16mode))
      {
        //Rate control
        if (input->RCEnable)
        {
          if(mode == P8x8)
            rc_store_diff(img->opix_x,img->opix_y,
            currMB->luma_transform_size_8x8_flag == 1 ? tr8x8.mpr8x8 : tr4x4.mpr8x8);
          else
            rc_store_diff(img->opix_x, img->opix_y, pred);
        }      
        store_macroblock_parameters (mode);
        
        if(input->rdopt==2 && mode == 0 && input->EarlySkipEnable)
        {
          // check transform quantized coeff.
          if(currMB->cbp == 0)
            *inter_skip = 1;
        }
        
      }
      
      // Go through transform modes. 
      // Note that if currMB->cbp is 0 one could choose to skip 8x8 mode
      // although this could be due to deadzoning decisions.
      //if (input->Transform8x8Mode==1 && currMB->cbp!=0) 
      if (input->Transform8x8Mode==1)
      {
        //=========== try mb_types 1,2,3 with 8x8 transform ===========
        if ((mode >= 1 && mode <= 3) && currMB->luma_transform_size_8x8_flag == 0)
        {
          //try with 8x8 transform size
          currMB->luma_transform_size_8x8_flag = 1;
          continue;
        }
        //=========== try DIRECT-MODE with 8x8 transform ===========
        else if (mode == 0 && bslice && active_sps->direct_8x8_inference_flag && currMB->luma_transform_size_8x8_flag == 0)
        {
          //try with 8x8 transform size
          currMB->luma_transform_size_8x8_flag = 1;
          continue;
        }
        //=========== try mb_type P8x8 for mode 4 with 4x4/8x8 transform ===========
        else if ((mode == P8x8) && (enc_mb.valid[4]) && (currMB->luma_transform_size_8x8_flag == 0))
        {
          currMB->luma_transform_size_8x8_flag = 1; //check 8x8 partition for transform size 8x8
          continue;
        }
        else
        {
          currMB->luma_transform_size_8x8_flag = 0;
          break;
        }
      }
      else
        break;
    }
  }
  
  // Encode with no coefficients. Currently only for direct. This could be extended to all other modes as in example.
  //if (mode < P8x8 && (*inter_skip == 0) && enc_mb.valid[mode] && currMB->cbp && (currMB->cbp&15) != 15 && !input->nobskip)
  if ( bslice && mode == 0 && (*inter_skip == 0) && enc_mb.valid[mode] 
    && currMB->cbp && (currMB->cbp&15) != 15 && !input->nobskip) 
  {
    img->NoResidueDirect = 1;
    if (RDCost_for_macroblocks (enc_mb.lambda_md, mode, min_rdcost, min_rate, i16mode)) 
    {
      //Rate control
      if (input->RCEnable)
        rc_store_diff(img->opix_x,img->opix_y,pred);
      
      store_macroblock_parameters (mode);
    }
  }
};


/*!
*************************************************************************************
* \brief
*    Mode Decision for an 8x8 sub-macroblock
*************************************************************************************
*/
void submacroblock_mode_decision(RD_PARAMS enc_mb, 
                                 RD_8x8DATA *dataTr, 
                                 Macroblock *currMB,
                                 int ***cofACtr, 
                                 int *have_direct, 
                                 short bslice, 
                                 int block, 
                                 int *cost_direct,                                  
                                 int *cost,
                                 int *cost8x8_direct,
                                 int transform8x8)  
{
  int j0, i0, j1, i1;
  int i,j, k;
  int min_cost8x8, index;
  double min_rdcost, rdcost = 0.0;
  short best_pdir = 0;
  char best_ref[2] = {0, -1};
  int mode;
  int64 curr_cbp_blk;
  int direct4x4_tmp, direct8x8_tmp;
  int bmcost[5] = {INT_MAX};
  int cnt_nonz = 0;
  short pdir;
  int dummy;
  short bi_pred_me;
  int best_cnt_nonz = 0;
  int maxindex =  (transform8x8) ? 2 : 5;
  int pix_x, pix_y;
  int block_x, block_y;
  
  int fadjust[16][16], fadjustCr[2][16][16];    
  int (*fadjustTransform)[16][16] = transform8x8? img->fadjust8x8 : img->fadjust4x4;
  int (*fadjustTransformCr)[2][16][16] = transform8x8? img->fadjust8x8Cr : img->fadjust4x4Cr;
  int lumaAdjustIndex = transform8x8? 2 : 3;
  int chromaAdjustIndex = transform8x8? 0 : 2;
  
  //--- set coordinates ---
  j0 = ((block/2)<<3);    j1 = (j0>>2);
  i0 = ((block%2)<<3);    i1 = (i0>>2);
  
#ifdef BEST_NZ_COEFF
  for(j = 0; j <= 1; j++)
  {
    for(i = 0; i <= 1; i++)
      best_nz_coeff[i][j] = img->nz_coeff[img->current_mb_nr][i1 + i][j1 + j] = 0;
  }
#endif
  
  if (transform8x8)
    currMB->luma_transform_size_8x8_flag = 1; //switch to transform size 8x8
  
  //--- store coding state before coding ---
  store_coding_state (cs_cm);

  //=====  LOOP OVER POSSIBLE CODING MODES FOR 8x8 SUB-PARTITION  =====
  for (min_cost8x8=INT_MAX, min_rdcost=1e30, index=(bslice?0:1); index<maxindex; index++)
  {
    mode = b8_mode_table[index]; 
    *cost = 0;
    if (enc_mb.valid[mode] && (transform8x8 == 0 || mode != 0 || (mode == 0 && active_sps->direct_8x8_inference_flag)))
    {
      curr_cbp_blk = 0;
      
      if (mode==0)
      {
        //--- Direct Mode ---                                      
        if (!input->rdopt )
        {
          direct4x4_tmp=0; direct8x8_tmp=0;
          direct4x4_tmp = Get_Direct_Cost8x8 ( block, &direct8x8_tmp);
          
          if ((direct4x4_tmp==INT_MAX)||(*cost_direct==INT_MAX))
          {
            *cost_direct = INT_MAX;
            if (transform8x8) 
              *cost8x8_direct = INT_MAX;
          }
          else
          {
            *cost_direct += direct4x4_tmp;
            if (transform8x8) 
              *cost8x8_direct += direct8x8_tmp;
          }                     
          *have_direct ++;
          
          if (transform8x8)
          {
            switch(input->Transform8x8Mode)
            {
            case 1: // Mixture of 8x8 & 4x4 transform
              if((direct8x8_tmp < direct4x4_tmp) || !(enc_mb.valid[5] && enc_mb.valid[6] && enc_mb.valid[7]))
                *cost = direct8x8_tmp;
              else
                *cost = direct4x4_tmp;
              break;
            case 2: // 8x8 Transform only
              *cost = direct8x8_tmp;
              break;
            default: // 4x4 Transform only
              *cost = direct4x4_tmp;
              break;
            }            
            if (input->Transform8x8Mode==2) 
              *cost = INT_MAX;                                       
          }
          else
          {
            *cost = direct4x4_tmp;
          }
        }

        block_x = img->block_x+(block&1)*2;
        block_y = img->block_y+(block&2);
        best_ref[LIST_0] = direct_ref_idx[LIST_0][block_y][block_x];
        best_ref[LIST_1] = direct_ref_idx[LIST_1][block_y][block_x];
        best_pdir   = direct_pdir[block_y][block_x];
      } // if (mode==0)
      else
      {        
        //======= motion estimation for all reference frames ========
        //-----------------------------------------------------------
        PartitionMotionSearch (mode, block, enc_mb.lambda_mf);
        
        //--- get cost and reference frame for LIST 0 prediction ---
        bmcost[LIST_0] = INT_MAX;
        list_prediction_cost(LIST_0, block, mode, enc_mb, bmcost, best_ref);
        
        //store LIST 0 reference index for every block
        block_x = img->block_x+(block&1)*2;
        block_y = img->block_y+(block&2);
        for (j = block_y; j< block_y + 2; j++)
        {
          for (i = block_x; i < block_x + 2; i++)
          {
            enc_picture->ref_idx   [LIST_0][j][i] = best_ref[LIST_0];
            enc_picture->ref_pic_id[LIST_0][j][i] = 
              enc_picture->ref_pic_num[enc_mb.list_offset[LIST_0]][(short)best_ref[LIST_0]];
          }
        } 
        
        if (bslice)
        {
          //--- get cost and reference frame for LIST 1 prediction ---
          bmcost[LIST_1] = INT_MAX;
          list_prediction_cost(LIST_1, block, mode, enc_mb, bmcost, best_ref);
          
          // Compute bipredictive cost between best list 0 and best list 1 references
          list_prediction_cost(BI_PRED, block, mode, enc_mb, bmcost, best_ref);
          
          //--- get prediction direction ----          
          determine_prediction_list(mode, bmcost, best_ref, &best_pdir, cost, &bi_pred_me);
          
          //store backward reference index for every block
          for (j = block_y; j< block_y + 2; j++)
          {
            for (i = block_x; i < block_x + 2; i++)
            {
              enc_picture->ref_idx[LIST_0][j][i] = best_ref[LIST_0];
              enc_picture->ref_idx[LIST_1][j][i] = best_ref[LIST_1];
            }
          }
        } // if (bslice)
        else
        {
          best_pdir = 0;
          *cost     = bmcost[LIST_0];
        }
      } // if (mode!=0)
      
      if (input->rdopt)
      {
        //--- get and check rate-distortion cost ---
        rdcost = RDCost_for_8x8blocks (&cnt_nonz, &curr_cbp_blk, enc_mb.lambda_md,
          block, mode, best_pdir, best_ref[LIST_0], best_ref[LIST_1]);
      }
      else
      {
        if (*cost!=INT_MAX)
          *cost += (REF_COST (enc_mb.lambda_mf, B8Mode2Value (mode, best_pdir),
          enc_mb.list_offset[(best_pdir<1?LIST_0:LIST_1)]) - 1);
      }
      
      //--- set variables if best mode has changed ---
      if ( ( input->rdopt && rdcost < min_rdcost) 
        || (!input->rdopt && *cost < min_cost8x8))
      {
        min_cost8x8                 = *cost;
        min_rdcost                  = rdcost;
        dataTr->part8x8mode [block] = mode;
        dataTr->part8x8pdir [block] = best_pdir;
        dataTr->part8x8fwref[block] = best_ref[LIST_0];
        dataTr->part8x8bwref[block] = best_ref[LIST_1];
        
#ifdef BEST_NZ_COEFF
        for(j = 0; j <= 1; j++)
        {
          for(i = 0; i <= 1; i++)
            best_nz_coeff[i][j]= cnt_nonz 
            ? img->nz_coeff[img->current_mb_nr][i1 + i][j1 + j] : 0;
        }
#endif
        
        //--- store number of nonzero coefficients ---
        best_cnt_nonz  = cnt_nonz;
        
        if (input->rdopt)
        {
          //--- store block cbp ---
          cbp_blk8x8    &= (~(0x33 << (((block>>1)<<3)+((block%2)<<1)))); // delete bits for block
          cbp_blk8x8    |= curr_cbp_blk;
          
          //--- store coefficients ---
          for (k=0; k< 4; k++)
          {
            for (j=0; j< 2; j++)
              for (i=0; i<65; i++)  
                cofACtr[k][j][i] = img->cofAC[block][k][j][i]; // 18->65 for ABT
          }   
          //--- store reconstruction and prediction --- 
          if(!img->residue_transform_flag)
          {
            for (j=j0; j<j0+8; j++)    
            {
              pix_y = img->pix_y + j;
              for (i=i0; i<i0+8; i++)
              {
                pix_x = img->pix_x + i;
                dataTr->rec_mbY8x8[j][i] = enc_picture->imgY[pix_y][pix_x];
                dataTr->mpr8x8[j][i] = img->mpr[j][i];
              }     
            }
          }
          else
          {
            for (j=j0; j<j0+8; j++)                
              for (i=i0; i<i0+8; i++)
              {
                dataTr->rec_resG_8x8  [j][i] = rec_resG  [j][i];
                dataTr->resTrans_R_8x8[j][i] = resTrans_R[j][i];
                dataTr->resTrans_B_8x8[j][i] = resTrans_B[j][i];
                dataTr->mprRGB_8x8 [0][j][i] = mprRGB [0][j][i];
                dataTr->mprRGB_8x8 [1][j][i] = mprRGB [1][j][i];
                dataTr->mprRGB_8x8 [2][j][i] = mprRGB [2][j][i];                  
              }     
          }
        }                  
        if (img->AdaptiveRounding)
        {
          for (j=j0; j<j0+8; j++)
            for (i=i0; i<i0+8; i++)                    
            {
              fadjust     [j][i] = fadjustTransform  [0]   [j][i];
              fadjustCr[0][j][i] = fadjustTransformCr[0][0][j][i];
              fadjustCr[1][j][i] = fadjustTransformCr[0][1][j][i];
            }
        }
        //--- store best 8x8 coding state ---
        if (block < 3)
        store_coding_state (cs_b8);
      } // if (rdcost <= min_rdcost)
      
      //--- re-set coding state as it was before coding with current mode was performed ---

      reset_coding_state (cs_cm);
    } // if ((enc_mb.valid[mode] && (transform8x8 == 0 || mode != 0 || (mode == 0 && active_sps->direct_8x8_inference_flag)))
  } // for (min_rdcost=1e30, index=(bslice?0:1); index<6; index++)  
  
#ifdef BEST_NZ_COEFF
  for(j = 0; j <= 1; j++)
  {
    for(i = 0; i <= 1; i++)
      img->nz_coeff[img->current_mb_nr][i1 + i][j1 + j] = best_nz_coeff[i][j];
  }
#endif              
  
  if (!transform8x8)
    dataTr->cost8x8 += min_cost8x8;
  
  if (!input->rdopt)
  {
    if (transform8x8)
    {
      dataTr->cost8x8 += min_cost8x8;              
      mode = dataTr->part8x8mode[block];
      pdir = dataTr->part8x8pdir[block];
    }
    else
    {
      mode = dataTr->part8x8mode[block];
      pdir = dataTr->part8x8pdir[block];    
    }
    curr_cbp_blk  = 0;
    best_cnt_nonz = LumaResidualCoding8x8 (&dummy, &curr_cbp_blk, block, pdir,
      (pdir==0||pdir==2?mode:0), (pdir==1||pdir==2?mode:0), dataTr->part8x8fwref[block], dataTr->part8x8bwref[block]);    
    
    cbp_blk8x8   &= (~(0x33 << (((block>>1)<<3)+((block%2)<<1)))); // delete bits for block
    cbp_blk8x8   |= curr_cbp_blk;
    
    //--- store coefficients ---
    for (k=0; k< 4; k++)
    {
        for (j=0; j< 2; j++)
          memcpy(cofACtr[k][j],img->cofAC[block][k][j],65 * sizeof(int));
    } 
    
    //--- store reconstruction and prediction ---
    if(!img->residue_transform_flag) // Residue Color Transform
    {
      for (j=j0; j<j0+2* BLOCK_SIZE; j++)
        {       
        memcpy(&dataTr->rec_mbY8x8[j][i0], &enc_picture->imgY[img->pix_y + j][img->pix_x + i0], 2* BLOCK_SIZE * sizeof (imgpel));
        memcpy(&dataTr->mpr8x8[j][i0], &img->mpr[j][i0], 2* BLOCK_SIZE * sizeof (imgpel));
      }
    }
    else 
    {   
      for (j=j0; j<j0+8; j++)
        for (i=i0; i<i0+8; i++)
        { 
          dataTr->rec_resG_8x8  [j][i] = rec_resG  [j][i];
          dataTr->resTrans_R_8x8[j][i] = resTrans_R[j][i];
          dataTr->resTrans_B_8x8[j][i] = resTrans_B[j][i];          
          dataTr->mprRGB_8x8 [0][j][i] = mprRGB [0][j][i];
          dataTr->mprRGB_8x8 [1][j][i] = mprRGB [1][j][i];
          dataTr->mprRGB_8x8 [2][j][i] = mprRGB [2][j][i];
        }
    }              
  }
  
  //----- set cbp and count of nonzero coefficients ---
  if (best_cnt_nonz)
  {
    cbp8x8       |= (1 << block);
    cnt_nonz_8x8 += best_cnt_nonz;
  }
  
  if (!transform8x8)
  {
    if (block<3)
    {
      //===== re-set reconstructed block =====
      j0   = 8*(block/2);
      i0   = 8*(block%2);
      for (j=j0; j<j0 + 2 * BLOCK_SIZE; j++)
        {
        memcpy(&enc_picture->imgY[img->pix_y + j][img->pix_x], dataTr->rec_mbY8x8[j], 2 * BLOCK_SIZE * sizeof(imgpel));
      }
    } // if (block<3)    
  }  
  else
  {  
    //======= save motion data for 8x8 partition for transform size 8x8 ========
    StoreNewMotionVectorsBlock8x8(0, block, dataTr->part8x8mode[block], dataTr->part8x8fwref[block], dataTr->part8x8bwref[block], dataTr->part8x8pdir[block], bslice);
  }  
  //===== set motion vectors and reference frames (prediction) =====
  SetRefAndMotionVectors (block, dataTr->part8x8mode[block], dataTr->part8x8pdir[block], dataTr->part8x8fwref[block], dataTr->part8x8bwref[block]);
  
  //===== set the coding state after current block =====
  //if (transform8x8 == 0 || block < 3)
  if (block < 3)
    reset_coding_state (cs_b8);
  
  if (img->AdaptiveRounding)
  {
    for (j=j0; j<j0+2 * BLOCK_SIZE; j++)
      {
        memcpy(&fadjustTransform  [lumaAdjustIndex  ]   [j][i0], &fadjust     [j][i0], 2 * BLOCK_SIZE * sizeof(int));
        memcpy(&fadjustTransformCr[chromaAdjustIndex][0][j][i0], &fadjustCr[0][j][i0], 2 * BLOCK_SIZE * sizeof(int));
        memcpy(&fadjustTransformCr[chromaAdjustIndex][1][j][i0], &fadjustCr[1][j][i0], 2 * BLOCK_SIZE * sizeof(int));
      }
  }
}

/*!
*************************************************************************************
* \brief
*    Mode Decision for a macroblock
*************************************************************************************
*/
void encode_one_macroblock ()
{  
  int max_index;
  
  int         rerun, block, index, mode, i, j, k, ctr16x16, dummy;
  short       best_pdir;
  RD_PARAMS   enc_mb;
  double      min_rdcost, max_rdcost=1e30;
  char        best_ref[2] = {0, -1};
  int         bmcost[5] = {INT_MAX};
  int         cost=0;
  int         min_cost = INT_MAX, cost_direct=0, have_direct=0, i16mode;
  int         intra1 = 0;
  int         temp_cpb = 0;
  int         best_transform_flag = 0;
  int         cost8x8_direct = 0;  
  short       islice      = (img->type==I_SLICE);
  short       bslice      = (img->type==B_SLICE);
  short       pslice      = (img->type==P_SLICE) || (img->type==SP_SLICE);
  short       intra       = (islice || (pslice && img->mb_y==img->mb_y_upd && img->mb_y_upd!=img->mb_y_intra));
  
  short       runs        = (input->RestrictRef==1 && input->rdopt==3 && (pslice  || (bslice && img->nal_reference_idc>0)) ? 2 : 1);
  
  int         pix_x, pix_y;
  Macroblock* currMB      = &img->mb_data[img->current_mb_nr];
  Macroblock* prevMB      = img->current_mb_nr ? &img->mb_data[img->current_mb_nr-1]:NULL ;
  
  char   **ipredmodes = img->ipredmode;
  short   *allmvs = img->all_mv[0][0][0][0][0];
  short   max_chroma_pred_mode;
  int     ****i4p;  //for non-RD-opt. mode
  
#ifdef BEST_NZ_COEFF
  int best_nz_coeff[2][2];
#endif  
  
  int tmp_8x8_flag, tmp_no_mbpart;  
  // Residue Color Transform
  int residue_R, residue_G, residue_B, temp;
  int cr_cbp = 0;  
  // Fast Mode Decision
  short inter_skip = 0, intra_skip = 0;
  int cost16 = 0, mode16 = 0;
  double min_rate = 0, RDCost16 = DBL_MAX;
  
  
  if(input->FMEnable == 1)
  {
    decide_intrabk_SAD();
  }
  else if (input->FMEnable ==2)
  {
    simplified_decide_intrabk_SAD();
  }
  
  intra |= RandomIntra (img->current_mb_nr);    // Forced Pseudo-Random Intra
  
  //===== Setup Macroblock encoding parameters =====
  init_enc_mb_params(currMB, &enc_mb, intra, bslice);
  
  // Perform multiple encodings if rdopt with losses is enabled
  for (rerun=0; rerun<runs; rerun++)
  {
    if (runs==2)
      input->rdopt= (rerun==0) ? 1 : 3;
    
    // reset chroma intra predictor to default
    currMB->c_ipred_mode = DC_PRED_8;

    //=====   S T O R E   C O D I N G   S T A T E   =====
    //---------------------------------------------------
    store_coding_state (cs_cm);
    
    if (!intra)
    {
      //===== set direct motion vectors =====
      best_mode = 1;
      if (bslice)
      {
        Get_Direct_Motion_Vectors ();
        if (input->rdopt == 2 && enc_mb.valid[0])
        {
          best_mode = 0;
          currMB->c_ipred_mode=DC_PRED_8;
          min_rdcost = max_rdcost;
          compute_mode_RD_cost(0, currMB, enc_mb, &min_rdcost, &min_rate, i16mode, bslice, &inter_skip);
        }
      }
      
      //===== MOTION ESTIMATION FOR 16x16, 16x8, 8x16 BLOCKS =====      
      for (min_cost=INT_MAX, mode=1; mode<4; mode++)
      {
        bi_pred_me = 0;
        img->bi_pred_me[mode]=0;
        if (enc_mb.valid[mode] && !inter_skip)
        {
          for (cost=0, block=0; block<(mode==1?1:2); block++)
          {
            PartitionMotionSearch (mode, block, enc_mb.lambda_mf);
            //--- set 4x4 block indizes (for getting MV) ---
            j = (block==1 && mode==2 ? 2 : 0);
            i = (block==1 && mode==3 ? 2 : 0);
            
            //--- get cost and reference frame for List 0 prediction ---
            bmcost[LIST_0] = INT_MAX;
            list_prediction_cost(LIST_0, block, mode, enc_mb, bmcost, best_ref);
            
            if (bslice)
            {
              //--- get cost and reference frame for List 1 prediction ---
              bmcost[LIST_1] = INT_MAX;
              list_prediction_cost(LIST_1, block, mode, enc_mb, bmcost, best_ref);
              
              // Compute bipredictive cost between best list 0 and best list 1 references
              list_prediction_cost(BI_PRED, block, mode, enc_mb, bmcost, best_ref);
              
              // Finally, if mode 16x16, compute cost for bipredictive ME vectore
              if (input->BiPredMotionEstimation && mode == 1)
              {                
                list_prediction_cost(BI_PRED_L0, block, mode, enc_mb, bmcost, 0);
                list_prediction_cost(BI_PRED_L1, block, mode, enc_mb, bmcost, 0);
              }
              else
              {
                bmcost[BI_PRED_L0] = INT_MAX;
                bmcost[BI_PRED_L1] = INT_MAX;
              }
              
              // Determine prediction list based on mode cost
              determine_prediction_list(mode, bmcost, best_ref, &best_pdir, &cost, &bi_pred_me);
            }
            else // if (bslice)
            {
              best_pdir  = 0;
              cost      += bmcost[LIST_0];
            }
            
            assign_enc_picture_params(mode, best_pdir, block, enc_mb.list_offset[LIST_0], best_ref[LIST_0], best_ref[LIST_1], bslice);
            
            //----- set reference frame and direction parameters -----
            if (mode==3)
            {
              best8x8fwref [3][block  ] = best8x8fwref [3][  block+2] = best_ref[LIST_0];
              best8x8pdir  [3][block  ] = best8x8pdir  [3][  block+2] = best_pdir;
              best8x8bwref [3][block  ] = best8x8bwref [3][  block+2] = best_ref[LIST_1];
            }
            else if (mode==2)
            {
              best8x8fwref [2][2*block] = best8x8fwref [2][2*block+1] = best_ref[LIST_0];
              best8x8pdir  [2][2*block] = best8x8pdir  [2][2*block+1] = best_pdir;
              best8x8bwref [2][2*block] = best8x8bwref [2][2*block+1] = best_ref[LIST_1];
            }
            else
            {
              best8x8fwref [1][0] = best8x8fwref [1][1] = best8x8fwref [1][2] = best8x8fwref [1][3] = best_ref[LIST_0];
              best8x8pdir  [1][0] = best8x8pdir  [1][1] = best8x8pdir  [1][2] = best8x8pdir  [1][3] = best_pdir;
              best8x8bwref [1][0] = best8x8bwref [1][1] = best8x8bwref [1][2] = best8x8bwref [1][3] = best_ref[LIST_1];
            }
            
            //--- set reference frames and motion vectors ---
            if (mode>1 && block==0)
              SetRefAndMotionVectors (block, mode, best_pdir, best_ref[LIST_0], best_ref[LIST_1]);            
          } // for (block=0; block<(mode==1?1:2); block++)
          
          if(!input->rdopt)
          {
            currMB->luma_transform_size_8x8_flag = 0;
            if (input->Transform8x8Mode) //for inter rd-off, set 8x8 to do 8x8 transform
            {
              SetModesAndRefframeForBlocks(mode);
              currMB->luma_transform_size_8x8_flag = TransformDecision(-1, &cost);
            }
          }          
          
          if(input->rdopt == 2 && mode == 1)
          {
            if(pslice)
              min_rdcost = max_rdcost;
            
            //=====   S T O R E   C O D I N G   S T A T E   =====
            //---------------------------------------------------
            //store_coding_state (cs_cm);

            for (ctr16x16=0, k=0; k<1; k++)
            {
              i16mode = 0; 
              
              //--- for INTER16x16 check all prediction directions ---
              if (bslice)
              {
                best8x8pdir[1][0] = best8x8pdir[1][1] = best8x8pdir[1][2] = best8x8pdir[1][3] = ctr16x16;
                if (ctr16x16 < 2) k--;
                ctr16x16++;
              }
              
              currMB->c_ipred_mode=DC_PRED_8;
              compute_mode_RD_cost(mode, currMB, enc_mb, &min_rdcost, &min_rate, i16mode, bslice, &inter_skip);
            } // for (ctr16x16=0, k=0; k<1; k++)
            
            if(pslice)
            {
              // Get SKIP motion vector and compare SKIP_MV with best motion vector of 16x16
              FindSkipModeMotionVector ();
              if(input->EarlySkipEnable)
              {
                //===== check for SKIP mode =====
                if ( currMB->cbp==0 && enc_picture->ref_idx[LIST_0][img->block_y][img->block_x]==0 &&
                  enc_picture->mv[LIST_0][img->block_y][img->block_x][0]==allmvs[0] &&
                  enc_picture->mv[LIST_0][img->block_y][img->block_x][1]==allmvs[1]               )
                {
                  inter_skip = 1;
                  best_mode = 0;
                }
              } // if(input->EarlySkipEnable)
            }
            
            // store variables.
            RDCost16 = min_rdcost;
            mode16 = best_mode;
            cost16 = cost;
          } // if(input->rdopt == 2 && mode == 1)
          
          if ((!inter_skip) && (cost < min_cost))
          {
            best_mode = mode;
            min_cost  = cost;
            best_transform_flag = currMB->luma_transform_size_8x8_flag;
          }
        } // if (enc_mb.valid[mode])
      } // for (mode=1; mode<4; mode++)
      
      if ((!inter_skip) && enc_mb.valid[P8x8])
      {
        tr8x8.cost8x8 = INT_MAX;
        tr4x4.cost8x8 = INT_MAX;
        //===== store coding state of macroblock =====
        store_coding_state (cs_mb);
        
        currMB->all_blk_8x8 = -1;
        
        if (input->Transform8x8Mode)
        {  
          tr8x8.cost8x8 = 0;
          //===========================================================
          // Check 8x8 partition with transform size 8x8 
          //===========================================================
          //=====  LOOP OVER 8x8 SUB-PARTITIONS  (Motion Estimation & Mode Decision) =====
          for (cost_direct=cbp8x8=cbp_blk8x8=cnt_nonz_8x8=0, block=0; block<4; block++)
            submacroblock_mode_decision(enc_mb, &tr8x8, currMB, cofAC_8x8ts[block],
            &have_direct, bslice, block, &cost_direct, &cost, &cost8x8_direct, 1);
          
          // following params could be added in RD_8x8DATA structure
          cbp8_8x8ts      = cbp8x8;
          cbp_blk8_8x8ts  = cbp_blk8x8;
          cnt_nonz8_8x8ts = cnt_nonz_8x8;
          currMB->luma_transform_size_8x8_flag = 0; //switch to 4x4 transform size

          //--- re-set coding state (as it was before 8x8 block coding) ---
          //reset_coding_state (cs_mb);        
        }// if (input->Transform8x8Mode)
        

        if (input->Transform8x8Mode != 2)  
        {
          tr4x4.cost8x8 = 0;
          //=================================================================
          // Check 8x8, 8x4, 4x8 and 4x4 partitions with transform size 4x4
          //=================================================================
          //=====  LOOP OVER 8x8 SUB-PARTITIONS  (Motion Estimation & Mode Decision) =====
          for (cost_direct=cbp8x8=cbp_blk8x8=cnt_nonz_8x8=0, block=0; block<4; block++)
          {
            submacroblock_mode_decision(enc_mb, &tr4x4, currMB, cofAC8x8[block],
              &have_direct, bslice, block, &cost_direct, &cost, &cost8x8_direct, 0);
            
            best8x8mode       [block] = tr4x4.part8x8mode [block];
            best8x8pdir [P8x8][block] = tr4x4.part8x8pdir [block];
            best8x8fwref[P8x8][block] = tr4x4.part8x8fwref[block];
            best8x8bwref[P8x8][block] = tr4x4.part8x8bwref[block];
          }          
          //--- re-set coding state (as it was before 8x8 block coding) ---
          // reset_coding_state (cs_mb);  
        }// if (input->Transform8x8Mode != 2)
        
        //--- re-set coding state (as it was before 8x8 block coding) ---
        reset_coding_state (cs_mb);
        
        
        // This is not enabled yet since mpr has reverse order.
        if (input->RCEnable)
          rc_store_diff(img->opix_x,img->opix_y,img->mpr);
        
        //check cost for P8x8 for non-rdopt mode
        if (!input->rdopt && (tr4x4.cost8x8 < min_cost || tr8x8.cost8x8 < min_cost))
        {
          best_mode = P8x8;
          if (input->Transform8x8Mode)
          {
            if (tr8x8.cost8x8 < tr4x4.cost8x8)
            {
              min_cost = tr8x8.cost8x8;
              currMB->luma_transform_size_8x8_flag=1;
            }
            else if(tr4x4.cost8x8 < tr8x8.cost8x8)
            {
              min_cost = tr4x4.cost8x8;
              currMB->luma_transform_size_8x8_flag=0;
            }
            else
            {
              min_cost = tr8x8.cost8x8;
              currMB->luma_transform_size_8x8_flag=1;
              if (GetBestTransformP8x8() == 0)
              {
                min_cost = tr4x4.cost8x8;
                currMB->luma_transform_size_8x8_flag=0;
              }
            }
          }
          else
          {
            min_cost = tr4x4.cost8x8;
            currMB->luma_transform_size_8x8_flag=0;
          }
        }// if (!input->rdopt && (tr4x4.cost8x8 < min_cost || tr8x8.cost8x8 < min_cost))
      }
      else // if (enc_mb.valid[P8x8])
      {
        tr4x4.cost8x8 = INT_MAX;
      }
      
      // Find a motion vector for the Skip mode
      if(input->rdopt != 2 && pslice)
        FindSkipModeMotionVector ();
    }   
    else // if (!intra)
    {
      min_cost = INT_MAX;
    }
    
    //========= C H O O S E   B E S T   M A C R O B L O C K   M O D E =========
    //-------------------------------------------------------------------------
   if (input->rdopt)
   {
    if (!inter_skip)
    {
        int mb_available_up;
        int mb_available_left;
        int mb_available_up_left;
        
        if(input->rdopt == 2 && img->type!=I_SLICE)
        {
          min_rdcost = RDCost16;
          best_mode  = mode16;
        }
        else
          min_rdcost = max_rdcost;
        
        // if Fast High mode, compute  inter modes separate process for inter/intra
        max_index = (img->residue_transform_flag) ? 11 : ((input->rdopt == 2 && !intra && input->SelectiveIntraEnable ) ? 5 : 9);
        
        if (input->BiPredMotionEstimation)
          img->bi_pred_me[1] =0;  
        
        if (img->yuv_format != YUV400 && max_index != 5)
        {
          // precompute all new chroma intra prediction modes
          IntraChromaPrediction(&mb_available_up, &mb_available_left, &mb_available_up_left);
          max_chroma_pred_mode = PLANE_8;
        }
        else
          max_chroma_pred_mode = DC_PRED_8;
        
        for (currMB->c_ipred_mode=DC_PRED_8; currMB->c_ipred_mode<=max_chroma_pred_mode; currMB->c_ipred_mode++)
        {
          // bypass if c_ipred_mode is not allowed
          if ( (img->yuv_format != YUV400) &&
            (  ((!intra || !input->IntraDisableInterOnly) && input->ChromaIntraDisable == 1 && currMB->c_ipred_mode!=DC_PRED_8) 
            || (currMB->c_ipred_mode == VERT_PRED_8 && !mb_available_up) 
            || (currMB->c_ipred_mode == HOR_PRED_8  && !mb_available_left) 
            || (currMB->c_ipred_mode == PLANE_8     && (!mb_available_left || !mb_available_up || !mb_available_up_left))))
            continue;        
          
          //===== GET BEST MACROBLOCK MODE =====
          for (ctr16x16=0, index=0; index < max_index; index++)
          {
            mode = mb_mode_table[index];
            
            if (img->yuv_format != YUV400)
            {           
              if (input->rdopt == 2)
              {
                i16mode = 0;              
                // RDcost of mode 1 in P-slice and mode 0, 1 in B-slice are already available
                if(((bslice && mode == 0) || (!islice && mode == 1)))
                  continue;
              }
              else
              {
                // Residue Color Transform
                if(img->residue_transform_flag)
                {
                  mode = mb_mode_table_RCT[index];
                  if( mode == I16MB) 
                    i16mode = index -5;
                  // bypass if i16mode is not allowed
                  if (mode == I16MB &&
                    (  (i16mode==VERT_PRED_16 && !mb_available_up) 
                    || (i16mode==HOR_PRED_16  && !mb_available_left) 
                    || (i16mode==PLANE_16    && (!mb_available_left || !mb_available_up || !mb_available_up_left))))
                    continue;
                }
                else
                {
                  mode = mb_mode_table[index];
                  i16mode = 0; 
                }
              }
            }
            //--- for INTER16x16 check all prediction directions ---
            if (mode==1 && bslice)
            {
              best8x8pdir[1][0] = best8x8pdir[1][1] = best8x8pdir[1][2] = best8x8pdir[1][3] = ctr16x16;
              
              if ( (bslice) && (input->BiPredMotionEstimation) 
                && (ctr16x16 == 2 && img->bi_pred_me[mode] < 2 && mode == 1))
                ctr16x16--;
              if (ctr16x16 < 2) 
                index--;
              ctr16x16++;
            }
            
            // Skip intra modes in inter slices if best inter mode is 
            // a MB partition and cbp is 0.
            if (input->SkipIntraInInterSlices && !intra && mode >= I16MB 
              && best_mode <=3 && currMB->cbp == 0)
              continue;
            
            if (enc_mb.valid[mode])
              compute_mode_RD_cost(mode, currMB, enc_mb, &min_rdcost, &min_rate, i16mode, bslice, &inter_skip);
            
            if ((input->BiPredMotionEstimation) && (bslice) && ctr16x16 == 2 
              && img->bi_pred_me[mode] < 2 && mode == 1 && best8x8pdir[1][0] == 2) 
              img->bi_pred_me[mode] = img->bi_pred_me[mode] + 1;
          }// for (ctr16x16=0, index=0; index<max_index; index++)
        }// for (currMB->c_ipred_mode=DC_PRED_8; currMB->c_ipred_mode<=max_chroma_pred_mode; currMB->c_ipred_mode++)
        
        // Selective Intra Coding
        if(img->type!=I_SLICE && input->rdopt == 2 && input->SelectiveIntraEnable && input->ProfileIDC<FREXT_HP)
        {
          fast_mode_intra_decision(&intra_skip, min_rate);
          
          if(!intra_skip)
          {
            // precompute all new chroma intra prediction modes
            if (img->yuv_format != YUV400)
            {
              // precompute all new chroma intra prediction modes
              IntraChromaPrediction(&mb_available_up, &mb_available_left, &mb_available_up_left);
              max_chroma_pred_mode = PLANE_8;
            }
            else
              max_chroma_pred_mode = DC_PRED_8;
            
            max_index = 9;
            
            for (currMB->c_ipred_mode=DC_PRED_8; currMB->c_ipred_mode<=max_chroma_pred_mode; currMB->c_ipred_mode++)
            {
              
              // bypass if c_ipred_mode is not allowed
              if ( (img->yuv_format != YUV400) &&
                (  ((!intra || !input->IntraDisableInterOnly) && input->ChromaIntraDisable == 1 && currMB->c_ipred_mode!=DC_PRED_8) 
                || (currMB->c_ipred_mode == VERT_PRED_8 && !mb_available_up) 
                || (currMB->c_ipred_mode == HOR_PRED_8  && !mb_available_left) 
                || (currMB->c_ipred_mode == PLANE_8     && (!mb_available_left || !mb_available_up || !mb_available_up_left))))
                continue;           
              
              //===== GET BEST MACROBLOCK MODE =====
              for (index = 5; index < max_index; index++)
              {
                mode = mb_mode_table[index];
                
                if (input->SkipIntraInInterSlices && !intra && mode >= I16MB 
                  && best_mode <=3 && currMB->cbp == 0)
                  continue;
                
                if (img->yuv_format != YUV400)
                {           
                  if (input->rdopt == 2)
                  {
                    i16mode = 0;              
                    // RDcost of mode 1 in P-slice and mode 0, 1 in B-slice are already available
                    if(((bslice && mode == 0) || (!islice && mode == 1)))
                      continue;
                  }
                  else
                  {
                    // Residue Color Transform
                    if(img->residue_transform_flag)
                    {
                      mode = mb_mode_table_RCT[index];
                      if( mode == I16MB) 
                        i16mode = index -5;
                      // bypass if i16mode is not allowed
                      if (mode == I16MB &&
                        (  (i16mode==VERT_PRED_16 && !mb_available_up) 
                        || (i16mode==HOR_PRED_16  && !mb_available_left) 
                        || (i16mode==PLANE_16    && (!mb_available_left || !mb_available_up || !mb_available_up_left))))
                        continue;
                    }
                    else
                    {
                      mode = mb_mode_table[index];
                      i16mode = 0; 
                    }
                  }
                }
                
                if (enc_mb.valid[mode])
                  compute_mode_RD_cost(mode, currMB, enc_mb, &min_rdcost, &min_rate, i16mode, bslice, &inter_skip);                            
              } // for (index = 5; index < max_index; index++)
            }
          }
        }          
      }
   }
   else //rdopt off
   {
     tmp_8x8_flag = currMB->luma_transform_size_8x8_flag;	//save 8x8_flag
     tmp_no_mbpart = currMB->NoMbPartLessThan8x8Flag;		  //save no-part-less
     
     if (img->yuv_format != YUV400)
       // precompute all chroma intra prediction modes
       IntraChromaPrediction(NULL, NULL, NULL);
     
     if (enc_mb.valid[0] && bslice) // check DIRECT MODE
     {
       if(have_direct)
       {
         switch(input->Transform8x8Mode)
         {
         case 1: // Mixture of 8x8 & 4x4 transform
           cost = ((cost8x8_direct < cost_direct) || !(enc_mb.valid[5] && enc_mb.valid[6] && enc_mb.valid[7])) 
             ? cost8x8_direct : cost_direct;
           break;
         case 2: // 8x8 Transform only
           cost = cost8x8_direct;
           break;
         default: // 4x4 Transform only
           cost = cost_direct;
           break;
         }
       }
       else
       { //!have_direct
         cost = Get_Direct_CostMB (enc_mb.lambda_mf);
       }
       if (cost!=INT_MAX)
       {
         cost -= (int)floor(16*enc_mb.lambda_me+0.4999);
       }
       
       if (cost <= min_cost)
       {
         if(active_sps->direct_8x8_inference_flag && input->Transform8x8Mode)
         {
           if(input->Transform8x8Mode==2)
             currMB->luma_transform_size_8x8_flag=1;
           else
           {
             if(cost8x8_direct < cost_direct)
               currMB->luma_transform_size_8x8_flag=1;
             else
               currMB->luma_transform_size_8x8_flag=0;
           }
         }
         else
           currMB->luma_transform_size_8x8_flag=0;
         
         //Rate control
         if (input->RCEnable)
           rc_store_diff(img->opix_x,img->opix_y,img->mpr);
         
         min_cost  = cost;
         best_mode = 0;
       }
       else
       {
         currMB->luma_transform_size_8x8_flag = tmp_8x8_flag; // restore if not best
         currMB->NoMbPartLessThan8x8Flag = tmp_no_mbpart; // restore if not best
       }        
     }
     
     if (enc_mb.valid[I8MB]) // check INTRA8x8
     {
       currMB->luma_transform_size_8x8_flag = 1; // at this point cost will ALWAYS be less than min_cost 
       
       currMB->mb_type = I8MB;
       temp_cpb = Mode_Decision_for_new_Intra8x8Macroblock (enc_mb.lambda_md, &cost);
       
       if (cost <= min_cost)
       {
         // Residue Color Transform
         if(img->residue_transform_flag)
         {            
           for(i=0; i<2; i++) 
           {
             for(j=0; j<4; j++) 
               for(k=0; k<4; k++)
                 if(cbp_chroma_block[i][j][k]) cr_cbp = 2;
           }            
           cr_cbp = dct_chroma_DC(0, cr_cbp);
           cr_cbp = dct_chroma_DC(1, cr_cbp);
           
           temp_cpb += (cr_cbp<<4);
           for(j=0; j<MB_BLOCK_SIZE; j++) 
           {
             pix_y = img->pix_y + j;
             for(i=0; i<MB_BLOCK_SIZE; i++) 
             {
               pix_x = img->pix_x + i;
               temp_imgU[j][i] = enc_picture->imgUV[0][pix_y][pix_x];
               temp_imgV[j][i] = enc_picture->imgUV[1][pix_y][pix_x];
             }
           }
         }          
         currMB->cbp = temp_cpb;
         
         //coeffs
         if (input->Transform8x8Mode != 2)
         {
           i4p=cofAC; cofAC=img->cofAC; img->cofAC=i4p;
         }
         
         for(j=0; j<MB_BLOCK_SIZE; j++) 
         {
           pix_y = img->pix_y + j;
           for(i=0; i<MB_BLOCK_SIZE; i++) 
           {
             pix_x = img->pix_x + i;
             temp_imgY[j][i] = enc_picture->imgY[pix_y][pix_x];
           }
         }
         
         //Rate control
         if (input->RCEnable)
           rc_store_diff(img->opix_x,img->opix_y,img->mpr);
         
         min_cost  = cost;
         best_mode = I8MB;
         tmp_8x8_flag = currMB->luma_transform_size_8x8_flag;
       } 
       else
         currMB->luma_transform_size_8x8_flag = tmp_8x8_flag; // restore if not best
     }
     
     if (enc_mb.valid[I4MB]) // check INTRA4x4
     {
       currMB->luma_transform_size_8x8_flag = 0;
       currMB->mb_type = I4MB;
       temp_cpb = Mode_Decision_for_Intra4x4Macroblock (enc_mb.lambda_md, &cost);
       
       if (cost <= min_cost)
       {
         // Residue Color Transform
         if(img->residue_transform_flag)
         {
           for(i=0; i<2; i++) 
           { 
             for(j=0; j<4; j++) 
               for(k=0; k<4; k++) 
                 if(cbp_chroma_block[i][j][k]) 
                   cr_cbp = 2;
           }
           cr_cbp = dct_chroma_DC(0, cr_cbp);
           cr_cbp = dct_chroma_DC(1, cr_cbp);
           
           temp_cpb += (cr_cbp<<4);
         }
         currMB->cbp = temp_cpb;
         
         //Rate control
         if (input->RCEnable)
           rc_store_diff(img->opix_x,img->opix_y,img->mpr);
         
         min_cost  = cost;
         best_mode = I4MB;
         tmp_8x8_flag = currMB->luma_transform_size_8x8_flag;
       } 
       else
       {
         currMB->luma_transform_size_8x8_flag = tmp_8x8_flag; // restore if not best
         //coeffs
         i4p=cofAC; cofAC=img->cofAC; img->cofAC=i4p;
       }
     }
     if (enc_mb.valid[I16MB]) // check INTRA16x16
     {
       currMB->luma_transform_size_8x8_flag = 0;
       intrapred_luma_16x16 ();
       cost = find_sad_16x16 (&i16mode);
       
       if (cost < min_cost)
       {
         //Rate control
         // should this access opix or pix?
         if (input->RCEnable)
           rc_store_diff(img->opix_x,img->opix_y,img->mprr_2[i16mode]);
         
         // Residue Color Transform
         if(img->residue_transform_flag)
         {
           for (j = 0; j < MB_BLOCK_SIZE; j++) 
           {
             pix_y = img->pix_y + j;
             for (i = 0; i < MB_BLOCK_SIZE; i++) 
             {
               pix_x = img->pix_x + i;
               residue_G = imgY_org    [pix_y][pix_x] - img->mprr_2   [i16mode]             [j][i];
               residue_B = imgUV_org[0][pix_y][pix_x] - img->mprr_c[0][currMB->c_ipred_mode][j][i];
               residue_R = imgUV_org[1][pix_y][pix_x] - img->mprr_c[1][currMB->c_ipred_mode][j][i];                
               /* Forward Residue Transform */
               resTrans_R[j][i] = residue_R - residue_B;
               temp             = residue_B + (resTrans_R[j][i] >> 1);
               resTrans_B[j][i] = residue_G-temp;
               resTrans_G[j][i] = temp+(resTrans_B[j][i] >> 1);                
               img->m7[j][i]    = resTrans_G[j][i];
             }
           }
         }
         
         best_mode   = I16MB;
         currMB->cbp = dct_luma_16x16 (i16mode);
         
         // Residue Color Transform
         if(img->residue_transform_flag)
         {
           for (j = 0; j < MB_BLOCK_SIZE; j++) 
           {
             for (i=0; i < MB_BLOCK_SIZE; i++) 
             {
               rec_resG[j][i] = img->m7[j][i];
               img->m7[j][i]  = resTrans_B[j][i];
             }
           }
           cr_cbp = dct_chroma(0, 0);
           
           for (j=0; j < MB_BLOCK_SIZE; j++) 
           {
             for (i=0; i < MB_BLOCK_SIZE; i++) 
             {
               rec_resB[j][i] = img->m7[j][i];
               img->m7[j][i]  = resTrans_R[j][i];
             }
           } 
           cr_cbp = dct_chroma(1, cr_cbp);
           
           for (j=0; j < MB_BLOCK_SIZE; j++) 
           {
             for (i=0; i < MB_BLOCK_SIZE; i++) 
               rec_resR[j][i] = img->m7[j][i];
           } 
           currMB->cbp += (cr_cbp<<4);
           
           /* Inverse Residue Transform */
           for (j=0; j < MB_BLOCK_SIZE; j++) 
           {
             pix_y = img->pix_y + j;
             for (i=0; i < MB_BLOCK_SIZE; i++) 
             {
               pix_x = img->pix_x + i;
               temp      = rec_resG[j][i] - (rec_resB[j][i] >> 1);
               residue_G = rec_resB[j][i]+temp;
               residue_B = temp - (rec_resR[j][i]>>1);
               residue_R = residue_B+rec_resR[j][i];                
               enc_picture->imgY    [pix_y][pix_x] = 
                 min(img->max_imgpel_value   ,max(0, residue_G + (int) img->mprr_2[i16mode][j][i]));
               enc_picture->imgUV[0][pix_y][pix_x] = 
                 min(img->max_imgpel_value_uv,max(0, residue_B + (int) img->mprr_c[0][currMB->c_ipred_mode][j][i]));
               enc_picture->imgUV[1][pix_y][pix_x] = 
                 min(img->max_imgpel_value_uv,max(0, residue_R + (int) img->mprr_c[1][currMB->c_ipred_mode][j][i]));
             }
           }
         }
       }
       else
       {
         currMB->luma_transform_size_8x8_flag = tmp_8x8_flag; // restore
         currMB->NoMbPartLessThan8x8Flag = tmp_no_mbpart;     // restore
       }
     }
     }    
     if (rerun==0)
       intra1 = IS_INTRA(currMB);
  } // for (rerun=0; rerun<runs; rerun++) 
  
  //=====  S E T   F I N A L   M A C R O B L O C K   P A R A M E T E R S ======
  //---------------------------------------------------------------------------  
  if (input->rdopt)
  {   
    if ((cbp!=0 || best_mode==I16MB ))
      currMB->prev_cbp = 1;    
    else if (cbp==0 && !input->RCEnable)
    {
      currMB->delta_qp = 0;
      currMB->qp = currMB->prev_qp;
      img->qp = currMB->qp;
      currMB->prev_cbp = 0;
    }    
    set_stored_macroblock_parameters ();
  }
  else
  {
    //===== set parameters for chosen mode =====
    SetModesAndRefframeForBlocks (best_mode);
    
    if (best_mode==P8x8)
    {
      if (currMB->luma_transform_size_8x8_flag && (cbp8_8x8ts == 0) && input->Transform8x8Mode != 2)
        currMB->luma_transform_size_8x8_flag = 0;
      
      SetCoeffAndReconstruction8x8 (currMB);
      
      memset(currMB->intra_pred_modes, DC_PRED, MB_BLOCK_PARTITIONS * sizeof(char));
      for (k=0, j = img->block_y; j < img->block_y + BLOCK_MULTIPLE; j++)
        memset(&ipredmodes[j][img->block_x], DC_PRED, BLOCK_MULTIPLE * sizeof(char));
    }
    else
    {
      //===== set parameters for chosen mode =====
      if (best_mode == I8MB)
      {
        memcpy(currMB->intra_pred_modes,currMB->intra_pred_modes8x8, MB_BLOCK_PARTITIONS * sizeof(char));
        for(j = img->block_y; j < img->block_y + BLOCK_MULTIPLE; j++)
          memcpy(&img->ipredmode[j][img->block_x],&img->ipredmode8x8[j][img->block_x], BLOCK_MULTIPLE * sizeof(char));

        //--- restore reconstruction for 8x8 transform ---
        for(j=0; j<MB_BLOCK_SIZE; j++) 
        {
          memcpy(&enc_picture->imgY[img->pix_y + j][img->pix_x],temp_imgY[j], MB_BLOCK_SIZE * sizeof(imgpel));
        }
        
        // Residue Color Transform
        if(img->residue_transform_flag)
        {          
          for(j=0; j<MB_BLOCK_SIZE; j++) 
          {
            pix_y = img->pix_c_y + j;
            for(i=0; i<MB_BLOCK_SIZE; i++) 
            {
              pix_x = img->pix_c_x + i;
              enc_picture->imgUV[0][pix_y][pix_x] = temp_imgU[j][i] ;
              enc_picture->imgUV[1][pix_y][pix_x] = temp_imgV[j][i] ;
            }
          }                
        }
      }
      
      if ((best_mode!=I4MB)&&(best_mode != I8MB))
      {
        memset(currMB->intra_pred_modes,DC_PRED, MB_BLOCK_PARTITIONS * sizeof(char));
        for(j = img->block_y; j < img->block_y + BLOCK_MULTIPLE; j++)
          memset(&ipredmodes[j][img->block_x],DC_PRED, BLOCK_MULTIPLE * sizeof(char));

        if (best_mode!=I16MB)
        {
          if((best_mode>=1) && (best_mode<=3))
            currMB->luma_transform_size_8x8_flag = best_transform_flag;
          LumaResidualCoding ();
          
          if((currMB->cbp==0)&&(best_mode==0))
            currMB->luma_transform_size_8x8_flag = 0;
          
          //Rate control
          if (input->RCEnable)
            rc_store_diff(img->opix_x,img->opix_y,img->mpr);
        }
      }
    }
    //check luma cbp for transform size flag
    if (((currMB->cbp&15) == 0) && !(IS_OLDINTRA(currMB) || currMB->mb_type == I8MB))
      currMB->luma_transform_size_8x8_flag = 0;
    
    // precompute all chroma intra prediction modes
    if (img->yuv_format != YUV400)
      IntraChromaPrediction(NULL, NULL, NULL);

    img->i16offset = 0;
    dummy = 0;
    
    // Residue Color Transform
    if ((!(img->residue_transform_flag && (best_mode==I4MB || best_mode==I16MB || best_mode==I8MB))) && img->yuv_format!=YUV400)
      ChromaResidualCoding (&dummy);
    if (best_mode==I16MB) {
      img->i16offset = I16Offset  (currMB->cbp, i16mode);
    }
    SetMotionVectorsMB (currMB, bslice);
    
    //===== check for SKIP mode =====
    if ((pslice) && best_mode==1 && currMB->cbp==0 &&
      enc_picture->ref_idx[LIST_0][img->block_y][img->block_x]    == 0 &&
      enc_picture->mv     [LIST_0][img->block_y][img->block_x][0] == allmvs[0] &&
      enc_picture->mv     [LIST_0][img->block_y][img->block_x][1] == allmvs[1])
    {
      currMB->mb_type = currMB->b8mode[0] = currMB->b8mode[1] = currMB->b8mode[2] = currMB->b8mode[3] = 0;
      currMB->luma_transform_size_8x8_flag = 0;
    }
    
    if(img->MbaffFrameFlag)
      set_mbaff_parameters();
  }
  
  // Rate control
  if(input->RCEnable)
    update_rc(currMB, best_mode);
  
  rdopt->min_rdcost = input->rdopt ? min_rdcost : min_cost;
  
  if ( (img->MbaffFrameFlag)
    && (img->current_mb_nr%2)
    && (currMB->mb_type ? 0:((bslice) ? !currMB->cbp:1))  // bottom is skip
    && (prevMB->mb_type ? 0:((bslice) ? !prevMB->cbp:1))
    && !(field_flag_inference() == enc_mb.curr_mb_field)) // top is skip
  {    
    rdopt->min_rdcost = 1e30;  // don't allow coding of a MB pair as skip if wrong inference
  }
  
  //===== Decide if this MB will restrict the reference frames =====
  if (input->RestrictRef)
    update_refresh_map(intra, intra1, currMB);  
  
  if(input->FMEnable == 1)
  {
    skip_intrabk_SAD(best_mode, listXsize[enc_mb.list_offset[LIST_0]]);
  }
  else if(input->FMEnable == 2)
  {
    simplified_skip_intrabk_SAD(best_mode, listXsize[enc_mb.list_offset[LIST_0]]);
  }
}

