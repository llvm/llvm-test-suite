
/*!
*************************************************************************************
* \file epzs.c
*
* \brief
*    Motion Estimation using EPZS
*
* \author
*    Main contributors (see contributors.h for copyright, address and affiliation details)
*      - Alexis Michael Tourapis <alexismt@ieee.org>
*
*************************************************************************************
*/

#include "contributors.h"

#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "global.h"
#include "image.h"
#include "memalloc.h"
#include "mb_access.h"

#include "epzs.h"

#define EPZSREF 1

extern int *mvbits;
extern unsigned int *byte_abs;

// Define Global Parameters
static const short blk_parent[8] = {1, 1, 1, 1, 2, 4, 4, 5}; //!< {skip, 16x16, 16x8, 8x16, 8x8, 8x4, 4x8, 4x4}
static const short blk_child[8]  = {1, 2, 4, 4, 5, 7, 7, 7}; //!< {skip, 16x16, 16x8, 8x16, 8x8, 8x4, 4x8, 4x4}
static const int   minthres_base[8] = {0,  64,  32,  32,  16,  8,  8,  4};
static const int   medthres_base[8] = {0, 256, 128, 128,  64, 32, 32, 16};
static const int   maxthres_base[8] = {0, 768, 384, 384, 192, 96, 96, 48};
static short img_width;
static short img_height;  
static short weight1, weight2, offsetBi;

//! Define EPZS Refinement patterns
static int pattern_data[4][12][4] = 
{  
  { // Small Diamond pattern
    {  0,  1,  3, 3 }, {  1,  0,  0, 3 }, {  0, -1,  1, 3 }, { -1,  0, 2, 3 }
  },    
  { // Square pattern
    {  0,  1,  7, 3 }, {  1,  1,  7, 5 }, {  1,  0,  1, 3 }, {  1, -1, 1, 5 },
    {  0, -1,  3, 3 }, { -1, -1,  3, 5 }, { -1,  0,  5, 3 }, { -1,  1, 5, 5 }
  },    
  { // Enhanced Diamond pattern
    { -1,  1, 10, 5 }, {  0,  2, 10, 8 }, {  0,  1, 10, 7 }, {  1,  1, 1, 5 },
    {  2,  0, 1,  8 }, {  1,  0,  1, 7 }, {  1, -1,  4, 5 }, {  0, -2, 4, 8 },
    {  0, -1, 4,  7 }, { -1, -1, 7,  5 }, { -2,  0,  7, 8 }, { -1,  0, 7, 7 }
  },  
  { // Large Diamond pattern
    {  0,  2, 6,  5 }, {  1,  1, 0,  3 }, {  2,  0, 0,  5 }, {  1, -1, 2, 3 },
    {  0, -2, 2,  5 }, { -1, -1, 4,  3 }, { -2,  0, 4,  5 }, { -1,  1, 6, 3 }
  }
};

// Other definitions
const  char c_EPZSPattern[4][20] = { "Diamond", "Square", "Extended Diamond", "Large Diamond"};
const  char c_EPZSDualPattern[5][20] = { "Disabled","Diamond", "Square", "Extended Diamond", "Large Diamond"};
const  char c_EPZSFixed[3][20] = { "Disabled","All P", "All P + B"};
const  char c_EPZSOther[2][20] = { "Disabled","Enabled"};

int medthres[8];
int maxthres[8];
int minthres[8];
int mv_scale[6][MAX_REFERENCE_PICTURES][MAX_REFERENCE_PICTURES];

static byte **EPZSMap;  //!< Memory Map definition 
int ***EPZSDistortion;  //!< Array for storing SAD Values
#if EPZSREF
short ******EPZSMotion;  //!< Array for storing Motion Vectors
#else
short *****EPZSMotion;  //!< Array for storing Motion Vectors
#endif

//
EPZSStructure *searchPattern,*searchPatternD, *predictor;
EPZSStructure *window_predictor, *window_predictor_extended;
EPZSStructure *sdiamond,*square,*ediamond,*ldiamond;
EPZSColocParams *EPZSCo_located;

int (*computeBiPredSad)(pel_t **, int, int, int, int, int, int, int, int, int);

static pel_t *(*get_ref_line1)(int, pel_t *, int, int, int, int);
static pel_t *(*get_ref_line2)(int, pel_t *, int, int, int, int);
static pel_t *(*get_ref_line) (int, pel_t *, int, int, int, int);  
static pel_t *ref_pic;
static pel_t *ref_pic1;
static pel_t *ref_pic2;
/*!
************************************************************************
* \brief
*    Allocate co-located memory 
*
* \param size_x
*    horizontal luma size
* \param size_y
*    vertical luma size
* \param mb_adaptive_frame_field_flag
*    flag that indicates macroblock adaptive frame/field coding
*
* \return
*    the allocated EPZSColocParams structure
************************************************************************
*/
EPZSColocParams* allocEPZScolocated(int size_x, int size_y, int mb_adaptive_frame_field_flag)
{
  EPZSColocParams *s;
  
  s = calloc(1, sizeof(EPZSColocParams)); 
  if (NULL == s)
    no_mem_exit("alloc_EPZScolocated: s");
  
  s->size_x = size_x;
  s->size_y = size_y;
  get_mem4Dshort (&(s->mv), 2, size_y / BLOCK_SIZE, size_x / BLOCK_SIZE, 2);
  
  if (mb_adaptive_frame_field_flag)
  {
    get_mem4Dshort (&(s->top_mv),   2, size_y / BLOCK_SIZE/2, size_x / BLOCK_SIZE, 2);
    get_mem4Dshort (&(s->bottom_mv),2, size_y / BLOCK_SIZE/2, size_x / BLOCK_SIZE, 2);
  }
  
  s->mb_adaptive_frame_field_flag  = mb_adaptive_frame_field_flag;
  
  return s;
}

/*!
************************************************************************
* \brief
*    Free co-located memory.
*
* \param p
*    structure to be freed
*
************************************************************************
*/
void freeEPZScolocated(EPZSColocParams* p)
{
  if (p)
  {
    free_mem4Dshort (p->mv, 2, p->size_y / BLOCK_SIZE);
    
    if (p->mb_adaptive_frame_field_flag)
    {
      free_mem4Dshort (p->top_mv, 2, p->size_y / BLOCK_SIZE / 2);
      free_mem4Dshort (p->bottom_mv, 2, p->size_y / BLOCK_SIZE / 2);                 
    }
    
    free(p);
    
    p=NULL;
  }
}

/*!
************************************************************************
* \brief
*    Allocate EPZS pattern memory
*
* \param searchpoints 
*    number of searchpoints to allocate
*
* \return
*    the allocated EPZSStructure structure
************************************************************************
*/
EPZSStructure* allocEPZSpattern(int searchpoints)
{
  EPZSStructure *s;
  
  s = calloc(1, sizeof(EPZSStructure)); 
  if (NULL == s)
    no_mem_exit("alloc_EPZSpattern: s");
  
  s->searchPoints = searchpoints;
  s->point = (SPoint*) calloc(searchpoints, sizeof(SPoint)); 
  
  return s;
}

/*!
************************************************************************
* \brief
*    Free EPZS pattern memory.
*
* \param p
*    structure to be freed
*
************************************************************************
*/
void freeEPZSpattern(EPZSStructure* p)
{
  if (p)
  {
    free ( (SPoint*) p->point);
    free(p);
    p=NULL;
  }
}

void assignEPZSpattern(EPZSStructure *pattern,int type)
{
  int i;
  
  for (i = 0; i < pattern->searchPoints; i++)
  {
    pattern->point[i].x           = pattern_data[type][i][0];
    pattern->point[i].y           = pattern_data[type][i][1];
    pattern->point[i].start_nmbr  = pattern_data[type][i][2];
    pattern->point[i].next_points = pattern_data[type][i][3];
  }
}

/*!
************************************************************************
* \brief
*    calculate RoundLog2(uiVal)
************************************************************************
*/
static int RoundLog2 (int iValue)
{
  int iRet = 0;
  int iValue_square = iValue * iValue;
  
  while ((1 << (iRet + 1)) <= iValue_square)
    iRet++;
  
  iRet = (iRet + 1) >> 1;
  
  return iRet;
}


/*!
************************************************************************
* \brief
*    EPZS Search Window Predictor Initialization
************************************************************************
*/
void EPZSWindowPredictorInit (short search_range, EPZSStructure * predictor, short mode)
{
  int pos;
  short searchpos, fieldsearchpos;
  short prednum = 0;
  short i;
  if (mode == 0)
  {
    for (pos = RoundLog2 (search_range) - 2; pos > -1; pos--)
    {
      searchpos = (search_range >> pos);
      
      for (i=1; i>=-1; i-=2)
      {
        predictor->point[prednum  ].x =  i * searchpos;
        predictor->point[prednum++].y =  0;
        predictor->point[prednum  ].x =  i * searchpos;
        predictor->point[prednum++].y =  i * searchpos;
        predictor->point[prednum  ].x =  0;
        predictor->point[prednum++].y =  i * searchpos;
        predictor->point[prednum  ].x = -i * searchpos;
        predictor->point[prednum++].y =  i * searchpos;
      }
    }
  }
  else // if (mode == 0)
  {
    for (pos = RoundLog2 (search_range) - 2; pos > -1; pos--)
    {
      searchpos = (search_range >> pos);      
      fieldsearchpos = (3 * searchpos + 1) >> 1;
      
      for (i=1; i>=-1; i-=2)
      {
        predictor->point[prednum  ].x =  i * searchpos;
        predictor->point[prednum++].y =  0;
        predictor->point[prednum  ].x =  i * searchpos;
        predictor->point[prednum++].y =  i * searchpos;
        predictor->point[prednum  ].x =  0;
        predictor->point[prednum++].y =  i * searchpos;
        predictor->point[prednum  ].x = -i * searchpos;
        predictor->point[prednum++].y =  i * searchpos;
      }
      
      for (i=1; i>=-1; i-=2)
      {
        predictor->point[prednum  ].x =  i * fieldsearchpos;
        predictor->point[prednum++].y = -i * searchpos;
        predictor->point[prednum  ].x =  i * fieldsearchpos;
        predictor->point[prednum++].y =  0;
        predictor->point[prednum  ].x =  i * fieldsearchpos;
        predictor->point[prednum++].y =  i * searchpos;
        predictor->point[prednum  ].x =  i * searchpos;
        predictor->point[prednum++].y =  i * fieldsearchpos;
        predictor->point[prednum  ].x =  0;
        predictor->point[prednum++].y =  i * fieldsearchpos;
        predictor->point[prednum  ].x = -i * searchpos;
        predictor->point[prednum++].y =  i * fieldsearchpos;
      }
    }
  }
  predictor->searchPoints = prednum;  
}

/*!
************************************************************************
* \brief
*    EPZS Global Initialization
************************************************************************
*/
int
EPZSInit ()
{
  int pel_error_me = 1 << (img->bitdepth_luma - 8);
  int i, memory_size = 0;
  int searcharray = input->BiPredMotionEstimation? 2 * max (input->search_range, input->BiPredMESearchRange) + 1 : 2 * input->search_range + 1;
  int searchlevels = RoundLog2 (input->search_range) - 1;  
  
  //! In this implementation we keep threshold limits fixed.
  //! However one could adapt these limits based on lagrangian 
  //! optimization considerations (i.e. qp), while also allow 
  //! adaptation of the limits themselves based on content or complexity. 
  for (i=0;i<8;i++)
  {
    medthres[i] = input->EPZSMedThresScale * medthres_base[i] * pel_error_me;
    maxthres[i] = input->EPZSMaxThresScale * maxthres_base[i] * pel_error_me;
    minthres[i] = input->EPZSMinThresScale * minthres_base[i] * pel_error_me;
  }
  
  //! Definition of pottential EPZS patterns.
  //! It is possible to also define other patterns, or even use
  //! resizing patterns (such as the PMVFAST scheme. These patterns
  //! are only shown here as reference, while the same also holds
  //! for this implementation (i.e. new conditions could be added
  //! on adapting predictors, or thresholds etc. Note that search
  //! could also be performed on subpel positions directly while 
  //! pattern needs not be restricted on integer positions only.
  
  //! Allocate memory and assign search patterns
  sdiamond = allocEPZSpattern(4);
  assignEPZSpattern(sdiamond, SDIAMOND);
  square = allocEPZSpattern(8);
  assignEPZSpattern(square, SQUARE);
  ediamond = allocEPZSpattern(12);
  assignEPZSpattern(ediamond, EDIAMOND);
  ldiamond = allocEPZSpattern(8);  
  assignEPZSpattern(ldiamond, LDIAMOND);
  
  //! Allocate and assign window based predictors. 
  //! Other window types could also be used, while method could be 
  //! made a bit more adaptive (i.e. patterns could be assigned 
  //! based on neighborhood
  window_predictor = allocEPZSpattern(searchlevels * 8);
  window_predictor_extended = allocEPZSpattern(searchlevels * 20);  
  EPZSWindowPredictorInit ((short) input->search_range, window_predictor, 0);
  EPZSWindowPredictorInit ((short) input->search_range, window_predictor_extended, 1);
  //! Also assing search predictor memory
  // maxwindow + spatial + blocktype + temporal + memspatial
  predictor = allocEPZSpattern(searchlevels * 20 + 5 + 5 + 9 * (input->EPZSTemporal) + 3 * (input->EPZSSpatialMem));
  
  //! Finally assign memory for all other elements 
  //! (distortion, EPZSMap, and temporal predictors)
  
  memory_size += get_mem3Dint (&EPZSDistortion, 6, 7, img->width/BLOCK_SIZE);
  memory_size += get_mem2D (&EPZSMap, searcharray, searcharray );
  if (input->EPZSSpatialMem)
  {
#if EPZSREF
    memory_size += get_mem6Dshort (&EPZSMotion, 6, img->max_num_references, 7, 4, img->width/BLOCK_SIZE, 2);
#else
    memory_size += get_mem5Dshort (&EPZSMotion, 6, 7, 4, img->width/BLOCK_SIZE, 2);
#endif
  }
  
  if (input->EPZSTemporal)
    EPZSCo_located = allocEPZScolocated (img->width, img->height, 
    active_sps->mb_adaptive_frame_field_flag);
  
  switch (input->EPZSPattern)
  {
  case 3:
    searchPattern = ldiamond;
    break;
  case 2:
    searchPattern = ediamond;
    break;
  case 1:
    searchPattern = square;
    break;
  case 0:
  default:
    searchPattern = sdiamond;
    break;
  }
  
  switch (input->EPZSDual)
  {
  case 4:
    searchPatternD = ldiamond;
    break;
  case 3:
    searchPatternD = ediamond;
    break;
  case 2:
    searchPatternD = square;
    break;
  case 1:
  default:
    searchPatternD = sdiamond;
    break;
  }
  
  return memory_size;
}

/*!
************************************************************************
* \brief
*    Delete EPZS Alocated memory
************************************************************************
*/
void EPZSDelete ()
{
  if (input->EPZSTemporal)
    freeEPZScolocated (EPZSCo_located);
  
  free_mem2D (EPZSMap);
  free_mem3Dint (EPZSDistortion, 6);
  freeEPZSpattern(window_predictor_extended);
  freeEPZSpattern(window_predictor);
  freeEPZSpattern(predictor);
  freeEPZSpattern(ldiamond);
  freeEPZSpattern(ediamond);
  freeEPZSpattern(sdiamond);
  freeEPZSpattern(square);
  if (input->EPZSSpatialMem)
  {
#if EPZSREF
    free_mem6Dshort (EPZSMotion, 6, img->max_num_references, 7, 4);
#else
    free_mem5Dshort (EPZSMotion, 6, 7, 4); 
#endif
  }
  
}

//! For ME purposes restricting the co-located partition is not necessary.
/*!
************************************************************************
* \brief
*    EPZS Slice Level Initialization 
************************************************************************
*/
void
EPZSSliceInit (EPZSColocParams * p, 
               StorablePicture ** listX[6])
{
  StorablePicture *fs, *fs_top, *fs_bottom;
  StorablePicture *fs1, *fs_top1, *fs_bottom1, *fsx;
  int i, j, k, jj, jdiv, loffset;
  int prescale, iTRb, iTRp;
  int list = img->type == B_SLICE ? LIST_1 : LIST_0;
  int tempmv_scale[2];
  int epzs_scale[2][6][MAX_LIST_SIZE];
  int iref; 
  
  // Lets compute scaling factoes between all references in lists.
  // Needed to scale spatial predictors.
  for (j = LIST_0; j < 2 + (img->MbaffFrameFlag * 4); j ++)
  {
    for (k = 0; k < listXsize[j]; k++)   
    {
      for (i = 0; i < listXsize[j]; i++)
      {
        if (j/2 == 0) 
        {
          iTRb = Clip3 (-128, 127, enc_picture->poc - listX[j][i]->poc);
          iTRp = Clip3 (-128, 127, enc_picture->poc - listX[j][k]->poc);
        }
        else if (j/2 == 1)
        {
          iTRb = Clip3 (-128, 127, enc_picture->top_poc - listX[j][i]->poc);
          iTRp = Clip3 (-128, 127, enc_picture->top_poc - listX[j][k]->poc);
        }
        else 
        {
          iTRb = Clip3 (-128, 127, enc_picture->bottom_poc - listX[j][i]->poc);
          iTRp = Clip3 (-128, 127, enc_picture->bottom_poc - listX[j][k]->poc);
        }
        
        if (iTRp != 0)
        {
          prescale = (16384 + abs (iTRp / 2)) / iTRp;
          mv_scale[j][i][k] = Clip3 (-2048, 2047, (iTRb * prescale + 32) >> 6);
        }
        else
          mv_scale[j][i][k] = 256;
      }
    }
  }      
  
  if (input->EPZSTemporal)
  {
    fs_top = fs_bottom = fs = listX[list][0];
    if (listXsize[0]> 1)
      fs_top1 = fs_bottom1 = fs1 = listX[list][1];
    else
      fs_top1 = fs_bottom1 = fs1 = listX[list][0];
    
    for (j = 0; j < 6; j++)
    {
      for (i = 0; i < 6; i++)
      {
        epzs_scale[0][j][i] = 256;
        epzs_scale[1][j][i] = 256;
      }
    }
    
    for (j = 0; j < 2 + (img->MbaffFrameFlag * 4); j += 2)
    {
      for (i = 0; i < listXsize[j]; i++)
      {      
        if (j == 0)
          iTRb = Clip3 (-128, 127, enc_picture->poc - listX[LIST_0 + j][i]->poc);
        else if (j == 2)
          iTRb = Clip3 (-128, 127, enc_picture->top_poc - listX[LIST_0 + j][i]->poc);
        else
          iTRb = Clip3 (-128, 127, enc_picture->bottom_poc - listX[LIST_0 + j][i]->poc);
        iTRp = Clip3 (-128, 127, listX[list + j][0]->poc - listX[LIST_0 + j][i]->poc);      
        if (iTRp != 0)
        {
          prescale = (16384 + abs (iTRp / 2)) / iTRp;
          prescale = Clip3 (-2048, 2047, (iTRb * prescale + 32) >> 6);        
          //prescale = (iTRb * prescale + 32) >> 6;
        }
        else			// This could not happen but lets use it in case that reference is removed.
          prescale = 256;      
        epzs_scale[0][j][i] = (mv_scale[j][0][i] * prescale + 128) >> 8;
        epzs_scale[0][j + 1][i] = prescale - 256;      
        if (listXsize[j]>1)
        {
          iTRp = Clip3 (-128, 127, listX[list + j][1]->poc - listX[LIST_0 + j][i]->poc);      
          if (iTRp != 0)
          {
            prescale = (16384 + abs (iTRp / 2)) / iTRp;
            prescale = Clip3 (-2048, 2047, (iTRb * prescale + 32) >> 6);        
            //prescale = (iTRb * prescale + 32) >> 6;
          }
          else			// This could not happen but lets use it for case that reference is removed.
            prescale = 256;      
          epzs_scale[1][j][i] = (mv_scale[j][1][i] * prescale + 128) >> 8;
          epzs_scale[1][j + 1][i] = prescale - 256;      
        }
        else
        {
          epzs_scale[1][j][i] = epzs_scale[0][j][i];
          epzs_scale[1][j + 1][i] = epzs_scale[0][j + 1][i];
        }
      }
    }  
    if (img->MbaffFrameFlag)
    {
      fs_top = listX[list + 2][0];
      fs_bottom = listX[list + 4][0];
      if (listXsize[0]> 1)
      {
        fs_top1 = listX[list + 2][1];
        fs_bottom = listX[list + 4][1];
      }
    }
    else
    {
      if (img->structure != FRAME)
      {
        if ((img->structure != fs->structure) && (fs->coded_frame))
        {
          if (img->structure == TOP_FIELD)
          {
            fs_top = fs_bottom = fs = listX[list][0]->top_field;
            fs_top1 = fs_bottom1 = fs1 = listX[list][0]->bottom_field;
          }
          else
          {
            fs_top = fs_bottom = fs = listX[list][0]->bottom_field;
            fs_top1 = fs_bottom1 = fs1 = listX[list][0]->top_field;
          }
        }
      }
    }
    
    //if (!active_sps->frame_mbs_only_flag || active_sps->direct_8x8_inference_flag)
    if (!active_sps->frame_mbs_only_flag)
    {
      for (j = 0; j < fs->size_y >> 2; j++)
      {
        jj = j / 2;
        jdiv = j / 2 + 4 * (j / 8);
        for (i = 0; i < fs->size_x >> 2; i++)
        {
          if (img->MbaffFrameFlag && fs->field_frame[j][i])
          {
            //! Assign frame buffers for field MBs   
            //! Check whether we should use top or bottom field mvs.
            //! Depending on the assigned poc values.                
            if (abs (enc_picture->poc - fs_bottom->poc) > abs (enc_picture->poc - fs_top->poc))
            {
              tempmv_scale[LIST_0] = 256;
              tempmv_scale[LIST_1] = 0;
              
              if (fs->ref_id [LIST_0][jdiv][i] < 0 && listXsize[LIST_0] > 1)
              {
                fsx = fs_top1;
                loffset = 1;
              }
              else 
              {
                fsx = fs_top;
                loffset = 0;
              }             
              
              if (fs->ref_id [LIST_0][jdiv][i] != -1)
              {
                for (iref=0;iref<min(img->num_ref_idx_l0_active,listXsize[LIST_0]);iref++)
                {
                  if (enc_picture->ref_pic_num[LIST_0][iref]==fs->ref_id [LIST_0][jdiv][i])
                  {
                    tempmv_scale[LIST_0] = epzs_scale[loffset][LIST_0][iref];
                    tempmv_scale[LIST_1] = epzs_scale[loffset][LIST_1][iref];
                    break;
                  }
                }
                p->mv[LIST_0][j][i][0] = (tempmv_scale[LIST_0] * fsx->mv[LIST_0][jj][i][0] + 32) >> 6;
                p->mv[LIST_0][j][i][1] = (tempmv_scale[LIST_0] * fsx->mv[LIST_0][jj][i][1] + 32) >> 6;
                p->mv[LIST_1][j][i][0] = (tempmv_scale[LIST_1] * fsx->mv[LIST_0][jj][i][0] + 32) >> 6;
                p->mv[LIST_1][j][i][1] = (tempmv_scale[LIST_1] * fsx->mv[LIST_0][jj][i][1] + 32) >> 6;
              }
              else
              {
                p->mv[LIST_0][j][i][0] = 0;
                p->mv[LIST_0][j][i][1] = 0;
                p->mv[LIST_1][j][i][0] = 0;
                p->mv[LIST_1][j][i][1] = 0;        
              }          
              
            }
            else
            {
              tempmv_scale[LIST_0] = 256;
              tempmv_scale[LIST_1] = 0;
              
              if (fs->ref_id [LIST_0][jdiv + 4][i] < 0 && listXsize[LIST_0] > 1)
              {
                fsx = fs_bottom1;
                loffset = 1;
              }
              else 
              {
                fsx = fs_bottom;
                loffset = 0;
              }             
              
              if (fs->ref_id [LIST_0][jdiv + 4][i] != -1)
              {
                for (iref=0;iref<min(img->num_ref_idx_l0_active,listXsize[LIST_0]);iref++)
                {
                  if (enc_picture->ref_pic_num[LIST_0][iref]==fs->ref_id [LIST_0][jdiv + 4][i])
                  {
                    tempmv_scale[LIST_0] = epzs_scale[loffset][LIST_0][iref];
                    tempmv_scale[LIST_1] = epzs_scale[loffset][LIST_1][iref];
                    break;
                  }
                }
                p->mv[LIST_0][j][i][0] = (tempmv_scale[LIST_0] * fsx->mv[LIST_0][jj][i][0] + 32) >> 6;
                p->mv[LIST_0][j][i][1] = (tempmv_scale[LIST_0] * fsx->mv[LIST_0][jj][i][1] + 32) >> 6;
                p->mv[LIST_1][j][i][0] = (tempmv_scale[LIST_1] * fsx->mv[LIST_0][jj][i][0] + 32) >> 6;
                p->mv[LIST_1][j][i][1] = (tempmv_scale[LIST_1] * fsx->mv[LIST_0][jj][i][1] + 32) >> 6;        
              }
              else
              {
                p->mv[LIST_0][j][i][0] = 0;
                p->mv[LIST_0][j][i][1] = 0;
                p->mv[LIST_1][j][i][0] = 0;
                p->mv[LIST_1][j][i][1] = 0;        
              }           
            }
          }
          else
          {          
            tempmv_scale[LIST_0] = 256;
            tempmv_scale[LIST_1] = 0;
            if (fs->ref_id [LIST_0][j][i] < 0 && listXsize[LIST_0] > 1)
            {
              fsx = fs1;
              loffset = 1;
            }
            else 
            {
              fsx = fs;
              loffset = 0;
            }             
            
            if (fsx->ref_id [LIST_0][j][i] != -1)
            {
              for (iref=0;iref<min(img->num_ref_idx_l0_active,listXsize[LIST_0]);iref++)
              {
                if (enc_picture->ref_pic_num[LIST_0][iref]==fsx->ref_id [LIST_0][j][i])
                {
                  tempmv_scale[LIST_0] = epzs_scale[loffset][LIST_0][iref];
                  tempmv_scale[LIST_1] = epzs_scale[loffset][LIST_1][iref];
                  break;
                }
              }
              p->mv[LIST_0][j][i][0] = (tempmv_scale[LIST_0] * fsx->mv[LIST_0][j][i][0] + 32) >> 6;
              p->mv[LIST_0][j][i][1] = (tempmv_scale[LIST_0] * fsx->mv[LIST_0][j][i][1] + 32) >> 6;
              p->mv[LIST_1][j][i][0] = (tempmv_scale[LIST_1] * fsx->mv[LIST_0][j][i][0] + 32) >> 6;
              p->mv[LIST_1][j][i][1] = (tempmv_scale[LIST_1] * fsx->mv[LIST_0][j][i][1] + 32) >> 6;        
            }
            else
            {
              p->mv[LIST_0][j][i][0] = 0;
              p->mv[LIST_0][j][i][1] = 0;
              p->mv[LIST_1][j][i][0] = 0;
              p->mv[LIST_1][j][i][1] = 0;        
            }          
          }
        }
      }
    }
    
    //! Generate field MVs from Frame MVs  
    if (img->structure || img->MbaffFrameFlag)
    {
      for (j = 0; j < fs->size_y / 8; j++)
      {
        for (i = 0; i < fs->size_x / 4; i++)
        {
          if (!img->MbaffFrameFlag)
          {
            tempmv_scale[LIST_0] = 256;
            tempmv_scale[LIST_1] = 0;
            
            if (fs->ref_id [LIST_0][j][i] < 0 && listXsize[LIST_0] > 1)
            {
              fsx = fs1;
              loffset = 1;
            }
            else 
            {
              fsx = fs;
              loffset = 0;
            }             
            
            if (fsx->ref_id [LIST_0][j][i] != -1)
            {
              for (iref=0;iref<min(img->num_ref_idx_l0_active,listXsize[LIST_0]);iref++)
              {
                if (enc_picture->ref_pic_num[LIST_0][iref]==fsx->ref_id [LIST_0][j][i])
                {
                  tempmv_scale[LIST_0] = epzs_scale[loffset][LIST_0][iref];
                  tempmv_scale[LIST_1] = epzs_scale[loffset][LIST_1][iref];
                  break;
                }
              }
              p->mv[LIST_0][j][i][0] = (tempmv_scale[LIST_0] * fsx->mv[LIST_0][j][i][0] + 32) >> 6;
              p->mv[LIST_0][j][i][1] = (tempmv_scale[LIST_0] * fsx->mv[LIST_0][j][i][1] + 32) >> 6;
              p->mv[LIST_1][j][i][0] = (tempmv_scale[LIST_1] * fsx->mv[LIST_0][j][i][0] + 32) >> 6;
              p->mv[LIST_1][j][i][1] = (tempmv_scale[LIST_1] * fsx->mv[LIST_0][j][i][1] + 32) >> 6;                  
              
            }
            else
            {
              p->mv[LIST_0][j][i][0] = 0;
              p->mv[LIST_0][j][i][1] = 0;
              p->mv[LIST_1][j][i][0] = 0;
              p->mv[LIST_1][j][i][1] = 0;                  
            }          
          }
          else
          {
            tempmv_scale[LIST_0] = 256;
            tempmv_scale[LIST_1] = 0;
            
            if (fs_bottom->ref_id [LIST_0][j][i] < 0 && listXsize[LIST_0] > 1)
            {
              fsx = fs_bottom1;
              loffset = 1;
            }
            else 
            {
              fsx = fs_bottom;
              loffset = 0;
            }             
            
            if (fsx->ref_id [LIST_0][j][i] != -1)
            {
              for (iref=0;iref<min(2*img->num_ref_idx_l0_active,listXsize[LIST_0 + 4]);iref++)
              {
                if (enc_picture->ref_pic_num[LIST_0 + 4][iref]==fsx->ref_id [LIST_0][j][i])
                {
                  tempmv_scale[LIST_0] = epzs_scale[loffset][LIST_0 + 4][iref];
                  tempmv_scale[LIST_1] = epzs_scale[loffset][LIST_1 + 4][iref];
                  break;
                }
              }
              p->bottom_mv[LIST_0][j][i][0] = (tempmv_scale[LIST_0] * fsx->mv[LIST_0][j][i][0] + 32) >> 6;
              p->bottom_mv[LIST_0][j][i][1] = (tempmv_scale[LIST_0] * fsx->mv[LIST_0][j][i][1] + 32) >> 6;
              p->bottom_mv[LIST_1][j][i][0] = (tempmv_scale[LIST_1] * fsx->mv[LIST_0][j][i][0] + 32) >> 6;
              p->bottom_mv[LIST_1][j][i][1] = (tempmv_scale[LIST_1] * fsx->mv[LIST_0][j][i][1] + 32) >> 6;                              
            }
            else
            {
              p->bottom_mv[LIST_0][j][i][0] = 0;
              p->bottom_mv[LIST_0][j][i][1] = 0;
              p->bottom_mv[LIST_1][j][i][0] = 0;
              p->bottom_mv[LIST_1][j][i][1] = 0;                  
            }
            
            if (!fs->field_frame[2 * j][i])
            {
              p->bottom_mv[LIST_0][j][i][1] = (p->bottom_mv[LIST_0][j][i][1] + 1) >> 1;
              p->bottom_mv[LIST_1][j][i][1] = (p->bottom_mv[LIST_1][j][i][1] + 1) >> 1;
            }
            
            tempmv_scale[LIST_0] = 256;
            tempmv_scale[LIST_1] = 0;
            
            if (fs_top->ref_id [LIST_0][j][i] < 0 && listXsize[LIST_0] > 1)
            {
              fsx = fs_top1;
              loffset = 1;
            }
            else 
            {
              fsx = fs_top;
              loffset = 0;
            }             
            
            if (fsx->ref_id [LIST_0][j][i] != -1)
            {
              for (iref=0;iref<min(2*img->num_ref_idx_l0_active,listXsize[LIST_0 + 2]);iref++)
              {
                if (enc_picture->ref_pic_num[LIST_0 + 2][iref]==fsx->ref_id [LIST_0][j][i])
                {
                  tempmv_scale[LIST_0] = epzs_scale[loffset][LIST_0 + 2][iref];
                  tempmv_scale[LIST_1] = epzs_scale[loffset][LIST_1 + 2][iref];
                  break;
                }
              }
              p->top_mv[LIST_0][j][i][0] = (tempmv_scale[LIST_0] * fsx->mv[LIST_0][j][i][0] + 32) >> 6;
              p->top_mv[LIST_0][j][i][1] = (tempmv_scale[LIST_0] * fsx->mv[LIST_0][j][i][1] + 32) >> 6;
              p->top_mv[LIST_1][j][i][0] = (tempmv_scale[LIST_1] * fsx->mv[LIST_0][j][i][0] + 32) >> 6;
              p->top_mv[LIST_1][j][i][1] = (tempmv_scale[LIST_1] * fsx->mv[LIST_0][j][i][1] + 32) >> 6;                  
            }
            else
            {
              p->top_mv[LIST_0][j][i][0] = 0;
              p->top_mv[LIST_0][j][i][1] = 0;
              p->top_mv[LIST_1][j][i][0] = 0;
              p->top_mv[LIST_1][j][i][1] = 0;                  
            }
            
            if (!fs->field_frame[2 * j][i])
            {
              p->top_mv[LIST_0][j][i][1] = (p->top_mv[LIST_0][j][i][1] + 1) >> 1;
              p->top_mv[LIST_1][j][i][1] = (p->top_mv[LIST_1][j][i][1] + 1) >> 1;
            }
          }
        }
      }
    }
    
    //if (!active_sps->frame_mbs_only_flag || active_sps->direct_8x8_inference_flag)
    if (!active_sps->frame_mbs_only_flag )
    {
      //! Use inference flag to remap mvs/references
      //! Frame with field co-located    
      if (!img->structure)
      {
        for (j = 0; j < fs->size_y >> 2; j++)
        {
          jj = j>>1;
          jdiv = (j>>1) + ((j>>3) << 2);
          for (i = 0; i < fs->size_x >> 2; i++)
          {        
            if (fs->field_frame[j][i])
            {
              tempmv_scale[LIST_0] = 256;
              tempmv_scale[LIST_1] = 0;
              
              if (fs->ref_id [LIST_0][jdiv][i] < 0 && listXsize[LIST_0] > 1)
              {
                fsx = fs1;
                loffset = 1;
              }
              else 
              {
                fsx = fs;
                loffset = 0;
              }             
              if (fsx->ref_id [LIST_0][jdiv][i] != -1)
              {
                for (iref=0;iref<min(img->num_ref_idx_l0_active,listXsize[LIST_0]);iref++)
                {
                  if (enc_picture->ref_pic_num[LIST_0][iref]==fsx->ref_id [LIST_0][jdiv][i])
                  {
                    tempmv_scale[LIST_0] = epzs_scale[loffset][LIST_0][iref];
                    tempmv_scale[LIST_1] = epzs_scale[loffset][LIST_1][iref];
                    break;
                  }
                }
                
                if (abs (enc_picture->poc - fsx->bottom_field->poc) > abs (enc_picture->poc - fsx->top_field->poc))
                {              
                  p->mv[LIST_0][j][i][0] = (tempmv_scale[LIST_0] * fsx->top_field->mv[LIST_0][jj][i][0] + 32) >> 6;
                  p->mv[LIST_0][j][i][1] = (tempmv_scale[LIST_0] * fsx->top_field->mv[LIST_0][jj][i][1] + 32) >> 6;
                  p->mv[LIST_1][j][i][0] = (tempmv_scale[LIST_1] * fsx->top_field->mv[LIST_0][jj][i][0] + 32) >> 6;
                  p->mv[LIST_1][j][i][1] = (tempmv_scale[LIST_1] * fsx->top_field->mv[LIST_0][jj][i][1] + 32) >> 6;        
                }
                else
                {
                  p->mv[LIST_0][j][i][0] = (tempmv_scale[LIST_0] * fsx->bottom_field->mv[LIST_0][jj][i][0] + 32) >> 6;
                  p->mv[LIST_0][j][i][1] = (tempmv_scale[LIST_0] * fsx->bottom_field->mv[LIST_0][jj][i][1] + 32) >> 6;
                  p->mv[LIST_1][j][i][0] = (tempmv_scale[LIST_1] * fsx->bottom_field->mv[LIST_0][jj][i][0] + 32) >> 6;
                  p->mv[LIST_1][j][i][1] = (tempmv_scale[LIST_1] * fsx->bottom_field->mv[LIST_0][jj][i][1] + 32) >> 6;        
                }
              }
              else
              {              
                p->mv[LIST_0][j][i][0] = 0;
                p->mv[LIST_0][j][i][1] = 0;
                p->mv[LIST_1][j][i][0] = 0;
                p->mv[LIST_1][j][i][1] = 0;
              }
            }
          }
        }
      }
    }
    
    if (active_sps->frame_mbs_only_flag)
    {
      for (j = 0; j < fs->size_y >> 2; j++)
      {
        for (i = 0; i < fs->size_x >> 2; i++)
        {
          tempmv_scale[LIST_0] = 256;
          tempmv_scale[LIST_1] = 0;
          if (fs->ref_id [LIST_0][j][i] < 0 && listXsize[LIST_0] > 1)
          {
            fsx = fs1;
            loffset = 1;
          }
          else 
          {
            fsx = fs;
            loffset = 0;
          }             
          if (fsx->ref_id [LIST_0][j][i] != -1)
          {
            for (iref=0;iref<min(img->num_ref_idx_l0_active,listXsize[LIST_0]);iref++)
            {
              if (enc_picture->ref_pic_num[LIST_0][iref]==fsx->ref_id [LIST_0][j][i])
              {
                tempmv_scale[LIST_0] = epzs_scale[loffset][LIST_0][iref];
                tempmv_scale[LIST_1] = epzs_scale[loffset][LIST_1][iref];
                break;
              }
            }
            p->mv[LIST_0][j][i][0] = (tempmv_scale[LIST_0] * fsx->mv[LIST_0][j][i][0] + 32) >> 6;
            p->mv[LIST_0][j][i][1] = (tempmv_scale[LIST_0] * fsx->mv[LIST_0][j][i][1] + 32) >> 6;
            p->mv[LIST_1][j][i][0] = (tempmv_scale[LIST_1] * fsx->mv[LIST_0][j][i][0] + 32) >> 6;
            p->mv[LIST_1][j][i][1] = (tempmv_scale[LIST_1] * fsx->mv[LIST_0][j][i][1] + 32) >> 6;                
          }
          else
          {
            p->mv[LIST_0][j][i][0] = 0;
            p->mv[LIST_0][j][i][1] = 0;
            p->mv[LIST_1][j][i][0] = 0;
            p->mv[LIST_1][j][i][1] = 0;
          }
        }
      }
    }
    
    if (!active_sps->frame_mbs_only_flag)
    {
      for (j = 0; j < fs->size_y >> 2; j++)
      {
        for (i = 0; i < fs->size_x >> 2; i++)
        {
          if ((!img->MbaffFrameFlag && !img->structure && fs->field_frame[j][i]) || (img->MbaffFrameFlag && fs->field_frame[j][i]))
          {
            p->mv[LIST_0][j][i][1] *= 2;        
            p->mv[LIST_1][j][i][1] *= 2;
          }
          else if (img->structure && !fs->field_frame[j][i])
          {
            p->mv[LIST_0][j][i][1] = (p->mv[LIST_0][j][i][1] + 1) >> 1;
            p->mv[LIST_1][j][i][1] = (p->mv[LIST_1][j][i][1] + 1) >> 1;
          }
        }
      }
    }
  }
}

/*!
***********************************************************************
* \brief
*    Spatial Predictors
*    AMT/HYC
***********************************************************************
*/
static short EPZSSpatialPredictors (PixelPos block_a, 
                                    PixelPos block_b,
                                    PixelPos block_c, 
                                    PixelPos block_d,
                                    int list, 
                                    int list_offset, 
                                    short ref,
                                    char **refPic, 
                                    short ***tmp_mv,
                                    EPZSStructure * predictor)
{
  int refA, refB, refC, refD;
  int *mot_scale = mv_scale[list + list_offset][ref];
  
  // zero predictor
  predictor->point[0].x = 0;
  predictor->point[0].y = 0;
  
  // Non MB-AFF mode
  if (!img->MbaffFrameFlag)
  {
    refA = block_a.available ? (int) refPic[block_a.pos_y][block_a.pos_x] : -1;
    refB = block_b.available ? (int) refPic[block_b.pos_y][block_b.pos_x] : -1;
    refC = block_c.available ? (int) refPic[block_c.pos_y][block_c.pos_x] : -1;
    refD = block_d.available ? (int) refPic[block_d.pos_y][block_d.pos_x] : -1;
    
    // Left Predictor
    predictor->point[1].x = (block_a.available) 
      ? (mot_scale[refA] * tmp_mv[block_a.pos_y][block_a.pos_x][0] + 512) >> 10 :  3;
    predictor->point[1].y = (block_a.available) 
      ? (mot_scale[refA] * tmp_mv[block_a.pos_y][block_a.pos_x][1] + 512) >> 10 :  0;
    
    // Up predictor
    predictor->point[2].x = (block_b.available) 
      ? (mot_scale[refB] * tmp_mv[block_b.pos_y][block_b.pos_x][0] + 512) >> 10 :  0;
    predictor->point[2].y = (block_b.available) 
      ? (mot_scale[refB] * tmp_mv[block_b.pos_y][block_b.pos_x][1] + 512) >> 10 :  3;
    
    // Up-Right predictor
    predictor->point[3].x = (block_c.available) 
      ? (mot_scale[refC] * tmp_mv[block_c.pos_y][block_c.pos_x][0] + 512) >> 10 : -3;
    predictor->point[3].y = (block_c.available) 
      ? (mot_scale[refC] * tmp_mv[block_c.pos_y][block_c.pos_x][1] + 512) >> 10 :  0;
    
    //Up-Left predictor
    predictor->point[4].x = (block_d.available) 
      ? (mot_scale[refD] * tmp_mv[block_d.pos_y][block_d.pos_x][0] + 512) >> 10 :  0;
    predictor->point[4].y = (block_d.available) 
      ? (mot_scale[refD] * tmp_mv[block_d.pos_y][block_d.pos_x][1] + 512) >> 10 : -3;    
  }
  else  // MB-AFF mode
  {    
    // Field Macroblock
    if (list_offset)
    {
      refA = block_a.available 
        ? img->mb_data[block_a.mb_addr].mb_field 
        ? (int) refPic[block_a.pos_y][block_a.pos_x] 
        : (int) refPic[block_a.pos_y][block_a.pos_x] * 2 : -1;
      refB =block_b.available 
        ? img->mb_data[block_b.mb_addr].mb_field 
        ? (int) refPic[block_b.pos_y][block_b.pos_x]
        : (int) refPic[block_b.pos_y][block_b.pos_x] * 2 : -1;
      refC = block_c.available 
        ? img->mb_data[block_c.mb_addr].mb_field 
        ? (int) refPic[block_c.pos_y][block_c.pos_x] 
        : (int) refPic[block_c.pos_y][block_c.pos_x] * 2 : -1;
      refD = block_d.available 
        ? img->mb_data[block_d.mb_addr].mb_field 
        ? (int) refPic[block_d.pos_y][block_d.pos_x] 
        : (int) refPic[block_d.pos_y][block_d.pos_x] * 2 : -1;
      
      // Left Predictor
      predictor->point[1].x = (block_a.available) 
        ? (mot_scale[refA] * tmp_mv[block_a.pos_y][block_a.pos_x][0] + 512 ) >> 10 :  3;
      predictor->point[1].y = (block_a.available) 
        ? img->mb_data[block_a.mb_addr].mb_field 
        ? (mot_scale[refA] * tmp_mv[block_a.pos_y][block_a.pos_x][1] + 512 ) >> 10 
        : (mot_scale[refA] * tmp_mv[block_a.pos_y][block_a.pos_x][1] + 1024) >> 11 :  0;
      
      // Up predictor
      predictor->point[2].x = (block_b.available) 
        ? (mot_scale[refB] * tmp_mv[block_b.pos_y][block_b.pos_x][0] + 512 ) >> 10 :  0;
      predictor->point[2].y = (block_b.available) 
        ? img->mb_data[block_b.mb_addr].mb_field 
        ? (mot_scale[refB] * tmp_mv[block_b.pos_y][block_b.pos_x][1] + 512 ) >> 10 
        : (mot_scale[refB] * tmp_mv[block_b.pos_y][block_b.pos_x][1] + 1024) >> 11 :  3;
      
      // Up-Right predictor
      predictor->point[3].x = (block_c.available) 
        ? (mot_scale[refC] * tmp_mv[block_c.pos_y][block_c.pos_x][0] + 512 ) >> 10 : -3;
      predictor->point[3].y = (block_c.available) 
        ? img->mb_data[block_c.mb_addr].mb_field 
        ? (mot_scale[refC] * tmp_mv[block_c.pos_y][block_c.pos_x][1] + 512 ) >> 10 
        : (mot_scale[refC] * tmp_mv[block_c.pos_y][block_c.pos_x][1] + 1024) >> 11 :  0;
      
      //Up-Left predictor
      predictor->point[4].x = (block_d.available) 
        ? (mot_scale[refD] * tmp_mv[block_d.pos_y][block_d.pos_x][0] + 512 ) >> 10 :  0;
      predictor->point[4].y = (block_d.available) 
        ? img->mb_data[block_d.mb_addr].mb_field 
        ? (mot_scale[refD] * tmp_mv[block_d.pos_y][block_d.pos_x][1] + 512 ) >> 10 
        : (mot_scale[refD] * tmp_mv[block_d.pos_y][block_d.pos_x][1] + 1024) >> 11 : -3;
    }
    else // Frame macroblock
    {
      refA = block_a.available 
        ? img->mb_data[block_a.mb_addr].mb_field 
        ? (int) refPic[block_a.pos_y][block_a.pos_x] >> 1
        : (int) refPic[block_a.pos_y][block_a.pos_x] : -1;
      refB = block_b.available 
        ? img->mb_data[block_b.mb_addr].mb_field 
        ? (int) refPic[block_b.pos_y][block_b.pos_x] >> 1 
        : (int) refPic[block_b.pos_y][block_b.pos_x] : -1;
      refC = block_c.available 
        ? img->mb_data[block_c.mb_addr].mb_field 
        ? (int) refPic[block_c.pos_y][block_c.pos_x] >> 1 
        : (int) refPic[block_c.pos_y][block_c.pos_x] : -1;
      refD = block_d.available 
        ? img->mb_data[block_d.mb_addr].mb_field 
        ? (int) refPic[block_d.pos_y][block_d.pos_x] >> 1 
        : (int) refPic[block_d.pos_y][block_d.pos_x] : -1;
      
      // Left Predictor
      predictor->point[1].x = (block_a.available) 
        ? (mot_scale[refA] * tmp_mv[block_a.pos_y][block_a.pos_x][0] + 512) >> 10 :  3;
      predictor->point[1].y = (block_a.available) 
        ? img->mb_data[block_a.mb_addr].mb_field 
        ? (mot_scale[refA] * tmp_mv[block_a.pos_y][block_a.pos_x][1] + 256) >> 9  
        : (mot_scale[refA] * tmp_mv[block_a.pos_y][block_a.pos_x][1] + 512) >> 10 :  0;
      
      // Up predictor
      predictor->point[2].x = (block_b.available) 
        ? (mot_scale[refB] * tmp_mv[block_b.pos_y][block_b.pos_x][0] + 512) >> 10 :  0;
      predictor->point[2].y = (block_b.available) 
        ? img->mb_data[block_b.mb_addr].mb_field 
        ? (mot_scale[refB] * tmp_mv[block_b.pos_y][block_b.pos_x][1] + 256) >> 9  
        : (mot_scale[refB] * tmp_mv[block_b.pos_y][block_b.pos_x][1] + 512) >> 10 :  3;
      
      // Up-Right predictor
      predictor->point[3].x = (block_c.available) 
        ? (mot_scale[refC] * tmp_mv[block_c.pos_y][block_c.pos_x][0] + 512) >> 10 : -3;
      predictor->point[3].y = (block_c.available) 
        ? img->mb_data[block_c.mb_addr].mb_field 
        ? (mot_scale[refC] * tmp_mv[block_c.pos_y][block_c.pos_x][1] + 256) >> 9  
        : (mot_scale[refC] * tmp_mv[block_c.pos_y][block_c.pos_x][1] + 512) >> 10 :  3;
      
      //Up-Left predictor
      predictor->point[4].x = (block_d.available) 
        ? (mot_scale[refD] * tmp_mv[block_d.pos_y][block_d.pos_x][0] + 512) >> 10 :  0;
      predictor->point[4].y = (block_d.available) 
        ? img->mb_data[block_d.mb_addr].mb_field 
        ? (mot_scale[refD] * tmp_mv[block_d.pos_y][block_d.pos_x][1] + 256) >>  9 
        : (mot_scale[refD] * tmp_mv[block_d.pos_y][block_d.pos_x][1] + 512) >> 10 : -3;
    }
  }
  
  return ((refA == -1) + (refB == -1) + (refC == -1 && refD == -1));
}

/*!
***********************************************************************
* \brief
*    Spatial Predictors
*    AMT/HYC
***********************************************************************
*/

static void EPZSSpatialMemPredictors (int list, 
                                      short ref,
                                      int blocktype,
                                      int pic_x, 
                                      int bs_x, 
                                      int bs_y, 
                                      int by,
                                      int *prednum,
                                      int img_width,
                                      EPZSStructure * predictor)
{
#if EPZSREF
  short ***mv = EPZSMotion[list][ref][blocktype];  
  
  // Left Predictor
  predictor->point[*prednum].x = (pic_x > 0) ? mv[by][pic_x - bs_x][0] :  0;
  predictor->point[*prednum].y = (pic_x > 0) ? mv[by][pic_x - bs_x][1] :  0;
  *prednum += ((predictor->point[*prednum].x != 0) || (predictor->point[*prednum].y != 0));
  
  // Up predictor
  predictor->point[*prednum].x = (by > 0) ? mv[by - bs_y][pic_x][0] : mv[4 - bs_y][pic_x][0] ;
  predictor->point[*prednum].y = (by > 0) ? mv[by - bs_y][pic_x][1] : mv[4 - bs_y][pic_x][1];
  *prednum += ((predictor->point[*prednum].x != 0) || (predictor->point[*prednum].y != 0));
  
  // Up-Right predictor
  predictor->point[*prednum].x = (pic_x + bs_x < img_width) ? (by > 0) 
    ? mv[by - bs_y][pic_x + bs_x][0] : mv[4 - bs_y][pic_x + bs_x][0] : 0;
  predictor->point[*prednum].y = (pic_x + bs_x < img_width) ? (by > 0) 
    ? mv[by - bs_y][pic_x + bs_x][1] : mv[4 - bs_y][pic_x + bs_x][1] : 0;
  *prednum += ((predictor->point[*prednum].x != 0) || (predictor->point[*prednum].y != 0));
  
#else
  int mot_scale = mv_scale[list][ref][0];
  short **mv = EPZSMotion[list][blocktype];  
  
  // Left Predictor
  predictor->point[*prednum].x = (pic_x > 0) 
    ? (mot_scale * mv[by][pic_x - bs_x][0] + 128) >> 8 
    : 0;
  predictor->point[*prednum].y = (pic_x > 0) 
    ? (mot_scale * mv[by][pic_x - bs_x][1] + 128) >> 8 
    : 0;
  *prednum += ((predictor->point[*prednum].x != 0) || (predictor->point[*prednum].y != 0));
  
  // Up predictor
  predictor->point[*prednum].x = (by > 0) 
    ? (mot_scale * mv[by - bs_y][pic_x][0] + 128) >> 8
    : (mot_scale * mv[4  - bs_y][pic_x][0] + 128) >> 8;
  predictor->point[*prednum].y = (by > 0) 
    ? (mot_scale * mv[by - bs_y][pic_x][1] + 128) >> 8
    : (mot_scale * mv[4  - bs_y][pic_x][0] + 128) >> 8;
  *prednum += ((predictor->point[*prednum].x != 0) || (predictor->point[*prednum].y != 0));
  
  // Up-Right predictor
  predictor->point[*prednum].x = (pic_x + bs_x < img_width) 
    ? (by > 0) 
    ? (mot_scale * mv[by - bs_y][pic_x + bs_x][0] + 128) >> 8
    : (mot_scale * mv[4  - bs_y][pic_x + bs_x][0] + 128) >> 8
    : 0;
  predictor->point[*prednum].y = (pic_x + bs_x < img_width) 
    ? (by > 0) 
    ? (mot_scale * mv[by - bs_y][pic_x + bs_x][1] + 128) >> 8
    : (mot_scale * mv[4  - bs_y][pic_x + bs_x][1] + 128) >> 8
    : 0;
  *prednum += ((predictor->point[*prednum].x != 0) || (predictor->point[*prednum].y != 0));
#endif
}

/*!
***********************************************************************
* \brief
*    Temporal Predictors
*    AMT/HYC
***********************************************************************
*/
static void
EPZSTemporalPredictors (int list,         // <--  current list
                        int list_offset,  // <--  list offset for MBAFF
                        short ref,        // <--  current reference frame
                        int o_block_x,	// <--  absolute x-coordinate of regarded AxB block
                        int o_block_y,	// <--  absolute y-coordinate of regarded AxB block
                        EPZSStructure * predictor, 
                        int *prednum,
                        int block_available_left, 
                        int block_available_up,
                        int block_available_right, 
                        int block_available_below,
                        int blockshape_x, 
                        int blockshape_y,
                        int stopCriterion, 
                        int min_mcost)
{  
  int mvScale = mv_scale[list + list_offset][ref][0];
  short ***col_mv = (list_offset == 0) ? EPZSCo_located->mv[list]
    : (list_offset == 2) ? EPZSCo_located->top_mv[list] : EPZSCo_located->bottom_mv[list];
  
  predictor->point[*prednum].x = (mvScale * col_mv[o_block_y][o_block_x][0] + 2048) >> 12;
  predictor->point[*prednum].y = (mvScale * col_mv[o_block_y][o_block_x][1] + 2048) >> 12;
  *prednum += ((predictor->point[*prednum].x != 0) || (predictor->point[*prednum].y != 0));
  
  if (min_mcost > stopCriterion && ref < 2)
  {
    if (block_available_left)
    {    
      predictor->point[*prednum].x = (mvScale * col_mv[o_block_y][o_block_x - 1][0] + 2048) >> 12;
      predictor->point[*prednum].y = (mvScale * col_mv[o_block_y][o_block_x - 1][1] + 2048) >> 12;
      *prednum += ((predictor->point[*prednum].x != 0) || (predictor->point[*prednum].y != 0));
      
      //Up_Left
      if (block_available_up)
      {
        predictor->point[*prednum].x = (mvScale * col_mv[o_block_y - 1][o_block_x - 1][0] + 2048) >> 12;
        predictor->point[*prednum].y = (mvScale * col_mv[o_block_y - 1][o_block_x - 1][1] + 2048) >> 12;
        *prednum += ((predictor->point[*prednum].x != 0) || (predictor->point[*prednum].y != 0));;
      }
      //Down_Left
      if (block_available_below)
      {
        predictor->point[*prednum].x = (mvScale * col_mv[o_block_y + blockshape_y][o_block_x - 1][0] + 2048) >> 12;
        predictor->point[*prednum].y = (mvScale * col_mv[o_block_y + blockshape_y][o_block_x - 1][1] + 2048) >> 12;
        *prednum += ((predictor->point[*prednum].x != 0) || (predictor->point[*prednum].y != 0));
      }
    }
    // Up
    if (block_available_up)
    {
      predictor->point[*prednum].x = (mvScale * col_mv[o_block_y - 1][o_block_x][0] + 2048) >> 12;
      predictor->point[*prednum].y = (mvScale * col_mv[o_block_y - 1][o_block_x][1] + 2048) >> 12;
      *prednum += ((predictor->point[*prednum].x != 0) || (predictor->point[*prednum].y != 0));
    }
    
    // Up - Right
    if (block_available_right)
    {
      predictor->point[*prednum].x = (mvScale * col_mv[o_block_y][o_block_x + blockshape_x][0] + 2048) >> 12;
      predictor->point[*prednum].y = (mvScale * col_mv[o_block_y][o_block_x + blockshape_x][1] + 2048) >> 12;
      *prednum += ((predictor->point[*prednum].x != 0) || (predictor->point[*prednum].y != 0));
      
      if (block_available_up)
      {
        predictor->point[*prednum].x = (mvScale * col_mv[o_block_y - 1][o_block_x + blockshape_x][0] + 2048) >> 12;
        predictor->point[*prednum].y = (mvScale * col_mv[o_block_y - 1][o_block_x + blockshape_x][1] + 2048) >> 12;
        *prednum += ((predictor->point[*prednum].x != 0) || (predictor->point[*prednum].y != 0));
      }
      if (block_available_below)
      {
        predictor->point[*prednum].x = (mvScale * col_mv[o_block_y + blockshape_y][o_block_x + blockshape_x][0] + 2048) >> 12;
        predictor->point[*prednum].y = (mvScale * col_mv[o_block_y + blockshape_y][o_block_x + blockshape_x][1] + 2048) >> 12;
        *prednum += ((predictor->point[*prednum].x != 0) || (predictor->point[*prednum].y != 0));
      }
    }
    
    if (block_available_below)
    {
      predictor->point[*prednum].x = (mvScale * col_mv[o_block_y + blockshape_y][o_block_x][0] + 2048) >> 12;
      predictor->point[*prednum].y = (mvScale * col_mv[o_block_y + blockshape_y][o_block_x][1] + 2048) >> 12;
      *prednum += ((predictor->point[*prednum].x != 0) || (predictor->point[*prednum].y != 0));
    }
  }
}

/*!
************************************************************************
* \brief
*    EPZS Block Type Predictors 
************************************************************************
*/
static void EPZSBlockTypePredictors (int block_x, int block_y, int blocktype, int ref, int list,
                                     EPZSStructure * predictor, int *prednum)
{
  short ***all_mv = img->all_mv[block_y][block_x][list];
  
  
  if ((ref > 0) && (blocktype < 5 || img->structure != FRAME))
  {
    predictor->point[*prednum].x = (mv_scale[list][ref][ref-1] * all_mv[ref-1][blocktype][0] + 512) >> 10;
    predictor->point[*prednum].y = (mv_scale[list][ref][ref-1] * all_mv[ref-1][blocktype][1] + 512) >> 10;
    *prednum += ((predictor->point[*prednum].x != 0) || (predictor->point[*prednum].y != 0));    
    
    predictor->point[*prednum].x = (mv_scale[list][ref][0] * all_mv[0][blocktype][0] + 512) >> 10;
    predictor->point[*prednum].y = (mv_scale[list][ref][0] * all_mv[0][blocktype][1] + 512) >> 10;
    *prednum += ((predictor->point[*prednum].x != 0) || (predictor->point[*prednum].y != 0));        
  }
  
  predictor->point[*prednum].x = (all_mv[ref][blk_parent[blocktype]][0] + 2) >> 2;
  predictor->point[*prednum].y = (all_mv[ref][blk_parent[blocktype]][1] + 2) >> 2;
  *prednum += ((predictor->point[*prednum].x != 0) || (predictor->point[*prednum].y != 0));    
  
  if (blocktype != 1)
  {
    predictor->point[*prednum].x = (all_mv[ref][1][0] + 2) >> 2;
    predictor->point[*prednum].y = (all_mv[ref][1][1] + 2) >> 2;
    *prednum += ((predictor->point[*prednum].x != 0) || (predictor->point[*prednum].y != 0));        
  }  
  
  if (blocktype != 4)
  {
    predictor->point[*prednum].x = (all_mv[ref][4][0] + 2) >> 2;
    predictor->point[*prednum].y = (all_mv[ref][4][1] + 2) >> 2;
    *prednum += ((predictor->point[*prednum].x != 0) || (predictor->point[*prednum].y != 0));    
  }
}

/*!
************************************************************************
* \brief
*    EPZS Window Based Predictors 
************************************************************************
*/
static void EPZSWindowPredictors (int mv_x, int mv_y, EPZSStructure *predictor, int *prednum, int extended)
{
  int pos;
  EPZSStructure *windowPred = (extended) ? window_predictor_extended : window_predictor;
  
  for (pos = 0; pos < windowPred->searchPoints; pos++)
  {
    predictor->point[(*prednum)  ].x = mv_x + windowPred->point[pos].x;
    predictor->point[(*prednum)++].y = mv_y + windowPred->point[pos].y;
  }
}

/*!
************************************************************************
* \brief
*    SAD computation 
************************************************************************
*/
static int computeSad(pel_t** cur_pic,
               int blocksize_y,
               int blocksize_x, 
               int blockshape_x,
               int mcost,
               int min_mcost,
               int cand_x,
               int cand_y)
{
  int y,x4;
  
  pel_t *cur_line, *ref_line;
  for (y=0; y<blocksize_y; y++)
  {
    ref_line  = get_ref_line (blocksize_x, ref_pic, cand_y + y, cand_x, img_height, img_width);
    cur_line = cur_pic [y];
    
    for (x4 = 0; x4 < blockshape_x; x4++)
    {
      mcost += byte_abs[ *cur_line++ - *ref_line++ ];
      mcost += byte_abs[ *cur_line++ - *ref_line++ ];
      mcost += byte_abs[ *cur_line++ - *ref_line++ ];
      mcost += byte_abs[ *cur_line++ - *ref_line++ ];
      //mcost += abs( *cur_line++ - *ref_line++ );
      //mcost += abs( *cur_line++ - *ref_line++ );
      //mcost += abs( *cur_line++ - *ref_line++ );
      //mcost += abs( *cur_line++ - *ref_line++ );
    }    
    if (mcost >= min_mcost) break;
  }
  return mcost;
}

/*!
************************************************************************
* \brief
*    BiPred SAD computation (no weights)
************************************************************************
*/
static int computeBiPredSad1(pel_t** cur_pic,
                             int blocksize_y,
                             int blocksize_x, 
                             int blockshape_x,
                             int mcost,
                             int min_mcost,
                             int cand_x1, int cand_y1, 
                             int cand_x2, int cand_y2)
{
  pel_t *cur_line, *ref1_line, *ref2_line;
  int bi_diff; 
  int y,x4;  
  
  for (y = 0; y < blocksize_y; y++)
  {
    ref2_line = get_ref_line2 (blocksize_x, ref_pic2, cand_y2 + y, cand_x2, img_height, img_width);
    ref1_line = get_ref_line1 (blocksize_x, ref_pic1, cand_y1 + y, cand_x1, img_height, img_width);
    cur_line = cur_pic [y];
    
    for (x4 = 0; x4 < blockshape_x; x4++)
    {         
      bi_diff = (*cur_line++) - ((*ref1_line++ + *ref2_line++)>>1);
      mcost += byte_abs[bi_diff];
      bi_diff = (*cur_line++) - ((*ref1_line++ + *ref2_line++)>>1);
      mcost += byte_abs[bi_diff];
      bi_diff = (*cur_line++) - ((*ref1_line++ + *ref2_line++)>>1);
      mcost += byte_abs[bi_diff];
      bi_diff = (*cur_line++) - ((*ref1_line++ + *ref2_line++)>>1);
      mcost += byte_abs[bi_diff];
    }        
    
    if (mcost >= min_mcost) break;
  }
  return mcost;
}


/*!
************************************************************************
* \brief
*    BiPred SAD computation (with weights)
************************************************************************
*/
static int computeBiPredSad2(pel_t** cur_pic,
                             int blocksize_y,
                             int blocksize_x, 
                             int blockshape_x,
                             int mcost,
                             int min_mcost,
                             int cand_x1, int cand_y1, 
                             int cand_x2, int cand_y2)
{
  pel_t *cur_line, *ref1_line, *ref2_line;
  int bi_diff; 
  int denom = luma_log_weight_denom + 1;
  int lround = 2 * wp_luma_round;
  int y,x4;  
  int weightedpel, pixel1, pixel2;
  for (y=0; y<blocksize_y; y++)
  {
    ref2_line  = get_ref_line2 (blocksize_x, ref_pic2, cand_y2 + y, cand_x2, img_height, img_width);
    ref1_line  = get_ref_line1 (blocksize_x, ref_pic1, cand_y1 + y, cand_x1, img_height, img_width);
    cur_line = cur_pic [y];
    
    for (x4 = 0; x4 < blockshape_x; x4++)
    { 
      pixel1 = weight1 * (*ref1_line++);
      pixel2 = weight2 * (*ref2_line++);
      weightedpel =  Clip3 (0, img->max_imgpel_value ,((pixel1 + pixel2 + lround) >> denom) + offsetBi);
      bi_diff = (*cur_line++)  - weightedpel;
      mcost += byte_abs[bi_diff];
      
      pixel1 = weight1 * (*ref1_line++);
      pixel2 = weight2 * (*ref2_line++);
      weightedpel =  Clip3 (0, img->max_imgpel_value ,((pixel1 + pixel2 + lround) >> denom) + offsetBi);
      bi_diff = (*cur_line++)  - weightedpel;
      mcost += byte_abs[bi_diff];
      
      pixel1 = weight1 * (*ref1_line++);
      pixel2 = weight2 * (*ref2_line++);
      weightedpel =  Clip3 (0, img->max_imgpel_value ,((pixel1 + pixel2 + lround) >> denom) + offsetBi);                     
      bi_diff = (*cur_line++)  - weightedpel;
      mcost += byte_abs[bi_diff];
      
      pixel1 = weight1 * (*ref1_line++);
      pixel2 = weight2 * (*ref2_line++);
      weightedpel =  Clip3 (0, img->max_imgpel_value ,((pixel1 + pixel2 + lround) >> denom) + offsetBi);
      bi_diff = (*cur_line++)  - weightedpel;
      mcost += byte_abs[bi_diff];
      if (mcost >= min_mcost) break;
    }    
    
    if (mcost >= min_mcost) break;
  }
  return mcost;
}

/*!
***********************************************************************
* \brief
*    FAST Motion Estimation using EPZS
*    AMT/HYC
***********************************************************************
*/
int				                                    //  ==> minimum motion cost after search
EPZSPelBlockMotionSearch (pel_t ** cur_pic,	  // <--  original pixel values for the AxB block
                          short ref,	        // <--  reference picture 
                          int list,           // <--  reference list
                          int list_offset,    // <--  offset for Mbaff
                          char ***refPic,    // <--  reference array
                          short ****tmp_mv,   // <--  mv array
                          int pic_pix_x,	    // <--  absolute x-coordinate of regarded AxB block
                          int pic_pix_y,	    // <--  absolute y-coordinate of regarded AxB block
                          int blocktype,    	// <--  block type (1-16x16 ... 7-4x4)
                          short pred_mv_x,	  // <--  motion vector predictor (x) in sub-pel units
                          short pred_mv_y,	  // <--  motion vector predictor (y) in sub-pel units
                          short *mv_x,	      // <--> in: search center (x) / out: motion vector (x) - in pel units
                          short *mv_y,	      // <--> in: search center (y) / out: motion vector (y) - in pel units
                          int search_range,	  // <--  1-d search range in pel units
                          int min_mcost,	    // <--  minimum motion cost (cost for center or huge value)
                          int lambda_factor)	    // <--  lagrangian parameter for determining motion cost
{
  StorablePicture *ref_picture = listX[list+list_offset][ref];
  short blocksize_y = input->blc_size[blocktype][1];	// vertical block size
  short blocksize_x = input->blc_size[blocktype][0];	// horizontal block size
  short blockshape_x = (blocksize_x >> 2);	// horizontal block size in 4-pel units
  short blockshape_y = (blocksize_y >> 2);	// vertical block size in 4-pel units
  
  short mb_x = pic_pix_x - img->opix_x; 
  short mb_y = pic_pix_y - img->opix_y;
  short pic_pix_x2 = pic_pix_x >> 2;
  short pic_pix_y2 = pic_pix_y >> 2;
  short block_x = (mb_x >> 2);
  short block_y = (mb_y >> 2);  
   
  int   pred_x = (pic_pix_x << 2) + pred_mv_x;	// predicted position x (in sub-pel units)
  int   pred_y = (pic_pix_y << 2) + pred_mv_y;	// predicted position y (in sub-pel units)
  int   center_x = pic_pix_x + *mv_x;	// center position x (in pel units)
  int   center_y = pic_pix_y + *mv_y;	// center position y (in pel units)
  int   cand_x = center_x;
  int   cand_y = center_y;
  int   tempmv_x  = *mv_x, tempmv_y  = *mv_y;
  int   tempmv_x2 = 0, tempmv_y2 = 0;
  int   stopCriterion = medthres[blocktype];
  int   mapCenter_x = search_range - *mv_x;
  int   mapCenter_y = search_range - *mv_y;
  int   second_mcost = INT_MAX;
  short apply_weights = (active_pps->weighted_pred_flag > 0 || active_pps->weighted_bipred_idc == 1);
  int   *prevSad = EPZSDistortion[list + list_offset][blocktype - 1];
  short *motion=NULL;
  
  short invalid_refs = 0;
  byte  checkMedian = FALSE;  
  EPZSStructure *searchPatternF = searchPattern;
  ref_pic = (apply_weights && input->UseWeightedReferenceME) ? ref_picture->imgY_11_w : ref_picture->imgY_11;
  
  if (input->EPZSSpatialMem)
  {
#if EPZSREF  
    motion = EPZSMotion[list + list_offset][ref][blocktype - 1][block_y][pic_pix_x2];  
#else
    motion = EPZSMotion[list + list_offset][blocktype - 1][block_y][pic_pix_x2];  
#endif
  }
  img_width  = ref_picture->size_x;
  img_height = ref_picture->size_y;  
  
  
  //===== set function for getting reference picture lines =====
  get_ref_line = CHECK_RANGE ? FastLineX : UMVLineX;
  
  // Clear EPZSMap
  memset(EPZSMap[0],FALSE,(2*search_range+1)*(2*search_range+1));
  // Check median candidate;  
  EPZSMap[search_range][search_range] = TRUE;
  
  //--- initialize motion cost (cost for motion vector) and check ---
  min_mcost = MV_COST (lambda_factor, 2, cand_x, cand_y, pred_x, pred_y);  
  
  //--- add residual cost to motion cost ---
  min_mcost = computeSad(cur_pic, blocksize_y,blocksize_x,
    blockshape_x,min_mcost, INT_MAX, cand_x,cand_y);
  // Additional threshold for ref>0  
  if ((ref>0 && img->structure == FRAME)  
    && (prevSad[pic_pix_x2] < medthres[blocktype]) 
    && (prevSad[pic_pix_x2] < min_mcost))
  {
    return min_mcost;  
  } 
  
  if ((center_x > search_range) && (center_x < img_width  - search_range - blocksize_x) &&
    (center_y > search_range) && (center_y < img_height - search_range - blocksize_y)   )
    get_ref_line = FastLineX;
  else
    get_ref_line = UMVLineX;
  
  //! If medthres satisfied, then terminate, otherwise generate Predictors  
  //! Condition could be strengthened by consideration distortion of adjacent partitions.
  if (min_mcost > stopCriterion)
  {    
    int mb_available_right   = (img->mb_x < (img_width  >> 4) - 1);
    int mb_available_below   = (img->mb_y < (img_height >> 4) - 1);
    
    int sadA, sadB, sadC;    
    int block_available_right;
    int block_available_below;
    int prednum = 5;
    int patternStop = 0, pointNumber = 0, checkPts;
    int totalCheckPts = 0, motionDirection = 0;
    int conditionEPZS;
    int mvx, mvy;
    int pos, mcost;  
    PixelPos block_a, block_b, block_c, block_d;
    
    getLuma4x4Neighbour (img->current_mb_nr, block_x, block_y, -1, 0, &block_a);
    getLuma4x4Neighbour (img->current_mb_nr, block_x, block_y, 0, -1, &block_b);
    getLuma4x4Neighbour (img->current_mb_nr, block_x, block_y, blocksize_x, -1, &block_c);
    getLuma4x4Neighbour (img->current_mb_nr, block_x, block_y, -1, -1, &block_d);
    
    if (mb_y > 0)
    {
      if (mb_x < 8)		// first column of 8x8 blocks
      {
        if (mb_y == 8)
        {
          block_available_right = (blocksize_x != MB_BLOCK_SIZE) || mb_available_right;
          if (blocksize_x == MB_BLOCK_SIZE) 
            block_c.available = 0;
        }
        else
        {
          block_available_right = (mb_x + blocksize_x != 8) || mb_available_right;
          if (mb_x + blocksize_x == 8) 
            block_c.available = 0;
        }
      }
      else
      {
        block_available_right = (mb_x + blocksize_x != MB_BLOCK_SIZE) || mb_available_right;
        if (mb_x + blocksize_x == MB_BLOCK_SIZE) 
          block_c.available = 0;
      }
    }
    else
    {
      block_available_right = (mb_x + blocksize_x != MB_BLOCK_SIZE) || mb_available_right;
    }    
    block_available_below = (mb_y + blocksize_y != MB_BLOCK_SIZE) || (mb_available_below);    
    
    sadA = block_a.available ? prevSad[pic_pix_x2 - blockshape_x] : INT_MAX;
    sadB = block_b.available ? prevSad[pic_pix_x2] : INT_MAX;
    sadC = block_c.available ? prevSad[pic_pix_x2 + blockshape_x] : INT_MAX;
    
    stopCriterion = min(sadA,min(sadB,sadC));
    stopCriterion = max(stopCriterion,minthres[blocktype]);
    stopCriterion = min(stopCriterion,maxthres[blocktype]);
    
    stopCriterion = (9 * max (medthres[blocktype], stopCriterion) + 2 * medthres[blocktype]) >> 3;
    
    //! Add Spatial Predictors in predictor list.
    //! Scheme adds zero, left, top-left, top, top-right. Note that top-left adds very little
    //! in terms of performance and could be removed with little penalty if any.
    invalid_refs = EPZSSpatialPredictors (block_a, block_b, block_c, block_d, 
      list, list_offset, ref, refPic[list], tmp_mv[list], predictor);
    if (input->EPZSSpatialMem)
      EPZSSpatialMemPredictors (list + list_offset, ref, blocktype - 1, pic_pix_x2, 
      blockshape_x, blockshape_y, block_y, &prednum, img_width>>2, predictor);
    
    // Temporal predictors  
    if (input->EPZSTemporal)
      EPZSTemporalPredictors (list, list_offset, ref, pic_pix_x2, pic_pix_y2, predictor, &prednum, 
      block_a.available, block_b.available, block_available_right, 
      block_available_below, blockshape_x, blockshape_y, stopCriterion, min_mcost);
    
    //! Window Size Based Predictors
    //! Basically replaces a Hierarchical ME concept and helps escaping local minima, or
    //! determining large motion variations.
    //! Following predictors can be adjusted further (i.e. removed, conditioned etc) 
    //! based on distortion, correlation of adjacent MVs, complexity etc. These predictors
    //! and their conditioning could also be moved after all other predictors have been
    //! tested. Adaptation could also be based on type of material and coding mode (i.e. 
    //! field/frame coding,MBAFF etc considering the higher dependency with opposite parity field
    //conditionEPZS = ((min_mcost > stopCriterion) 
    // && (input->EPZSFixed > 1 || (input->EPZSFixed && img->type == P_SLICE)));
    //conditionEPZS = ((ref == 0) && (blocktype < 5) && (min_mcost > stopCriterion) 
    //&& (input->EPZSFixed > 1 || (input->EPZSFixed && img->type == P_SLICE)));
    conditionEPZS = ((min_mcost > stopCriterion) && ((ref < 2 && blocktype < 5) 
      || ((img->structure!=FRAME || list_offset) && ref < 3)) 
      && (input->EPZSFixed > 1 || (input->EPZSFixed && img->type == P_SLICE))); 
    
    if (conditionEPZS)
      EPZSWindowPredictors ((int) *mv_x, (int) *mv_y, predictor, &prednum, 
      (blocktype < 5) && (invalid_refs > 2) && (ref < 1 + (img->structure!=FRAME || list_offset)));
    
    //! Blocktype/Reference dependent predictors. 
    //! Since already mvs for other blocktypes/references have been computed, we can reuse
    //! them in order to easier determine the optimal point. Use of predictors could depend
    //! on cost,
    //conditionEPZS = (ref == 0 || (ref > 0 && min_mcost > stopCriterion) || img->structure != FRAME || list_offset);
    conditionEPZS = (ref == 0 || (ref > 0 && min_mcost > stopCriterion));
    
    if (conditionEPZS)
      EPZSBlockTypePredictors (block_x, block_y, blocktype, ref, list, predictor, &prednum);
    
    //! Check all predictors          
    for (pos = 0; pos < prednum; pos++)
    {
      mvx = predictor->point[pos].x;
      mvy = predictor->point[pos].y;
      //if ((abs (mvx - *mv_x) > search_range || abs (mvy - *mv_y) > search_range) && (mvx || mvy))
      if (abs (mvx - *mv_x) > search_range || abs (mvy - *mv_y) > search_range)
        continue;
      
      if ((abs (mvx - *mv_x) <= search_range) && (abs (mvy - *mv_y) <= search_range))
      {
        if (EPZSMap[mapCenter_y + mvy][mapCenter_x + mvx] == TRUE)
          continue;
        else
          EPZSMap[mapCenter_y + mvy][mapCenter_x + mvx] = TRUE;
      }
      
      cand_x = pic_pix_x + mvx;
      cand_y = pic_pix_y + mvy;
      
      //--- set motion cost (cost for motion vector) and check ---
      mcost = MV_COST (lambda_factor, 2, cand_x, cand_y, pred_x, pred_y);
      
      if (mcost >= second_mcost) continue;            
      get_ref_line = CHECK_RANGE ? FastLineX : UMVLineX;      
      
      mcost = computeSad(cur_pic, blocksize_y,blocksize_x, 
        blockshape_x, mcost, second_mcost, cand_x, cand_y);
      
      //--- check if motion cost is less than minimum cost ---
      if (mcost < min_mcost)
      {
        tempmv_x2 = tempmv_x;
        tempmv_y2 = tempmv_y;
        second_mcost = min_mcost;
        tempmv_x = mvx;
        tempmv_y = mvy;
        min_mcost = mcost;
        checkMedian = TRUE;
      }
      //else if (mcost < second_mcost && (tempmv_x != mvx || tempmv_y != mvy))
      else if (mcost < second_mcost)
      {
        tempmv_x2 = mvx;
        tempmv_y2 = mvy;
        second_mcost = mcost;
        checkMedian = TRUE;
      }
    }
    
    //! Refine using EPZS pattern if needed
    //! Note that we are using a conservative threshold method. Threshold 
    //! could be tested after checking only a certain number of predictors
    //! instead of the full set. Code could be easily modified for this task.
    if (min_mcost > stopCriterion)
    {
      //! Adapt pattern based on different conditions.
      if (input->EPZSPattern != 0)
      {
        if ((min_mcost < stopCriterion + ((3 * medthres[blocktype]) >> 1)))
        {
          if ((tempmv_x == 0 && tempmv_y == 0) 
            || (abs (tempmv_x - *mv_x) < 2 && abs (tempmv_y - *mv_y) < 2))
            searchPatternF = sdiamond;
          else
            searchPatternF = square;
        }
        else if (blocktype > 5 || (ref > 0 && blocktype != 1))
          searchPatternF = square;
        else
          searchPatternF = searchPattern;
      }
      
      totalCheckPts = searchPatternF->searchPoints;
      
      //! center on best predictor      
      center_x = tempmv_x;
      center_y = tempmv_y;
      while(1)
      {
        do
        {
          checkPts = totalCheckPts;
          do
          {
            mvx = center_x + searchPatternF->point[pointNumber].x;
            mvy = center_y + searchPatternF->point[pointNumber].y;
            cand_x = pic_pix_x + mvx;
            cand_y = pic_pix_y + mvy;
            
            if ((abs (mvx - *mv_x) <= search_range) 
              && (abs (mvy - *mv_y) <= search_range))
            {
              if (EPZSMap[mapCenter_y + mvy][mapCenter_x + mvx] != TRUE)
                EPZSMap[mapCenter_y + mvy][mapCenter_x + mvx] = TRUE;
              else
              {
                pointNumber += 1;
                if (pointNumber >= searchPatternF->searchPoints)
                  pointNumber -= searchPatternF->searchPoints;
                checkPts -= 1;
                continue;
              }
              mcost = MV_COST (lambda_factor, 2, cand_x, cand_y, pred_x, pred_y);
              
              if (mcost < min_mcost)
              {              
                get_ref_line = CHECK_RANGE ? FastLineX : UMVLineX;      
                mcost = computeSad(cur_pic, blocksize_y,blocksize_x,
                  blockshape_x, mcost, min_mcost, cand_x, cand_y);
                if (mcost < min_mcost)
                {
                  min_mcost = mcost;
                  tempmv_x = mvx;
                  tempmv_y = mvy;
                  motionDirection = pointNumber;
                }
              }
            }
            pointNumber += 1;
            if (pointNumber >= searchPatternF->searchPoints)
              pointNumber -= searchPatternF->searchPoints;
            checkPts -= 1;
          }
          while (checkPts > 0);
          
          if ((tempmv_x == center_x) && (tempmv_y == center_y))
          {
            totalCheckPts = searchPatternF->searchPoints;
            patternStop = 1;
            motionDirection = 0;
            pointNumber = 0;
          }
          else
          {
            totalCheckPts = searchPatternF->point[motionDirection].next_points;
            pointNumber = searchPatternF->point[motionDirection].start_nmbr;
            center_x = tempmv_x;
            center_y = tempmv_y;
          }
        }
        while (patternStop != 1);
        
        if ((ref>0) && (img->structure == FRAME) 
          && (( 4 * prevSad[pic_pix_x2] < min_mcost) ||
          ((3 * prevSad[pic_pix_x2] < min_mcost) && (prevSad[pic_pix_x2] <= stopCriterion))))              
        {
          *mv_x = tempmv_x;
          *mv_y = tempmv_y;  
          return min_mcost;  
        } 
        
        //! Check Second best predictor with EPZS pattern     
        conditionEPZS = (checkMedian == TRUE) 
          && ((img->type == P_SLICE) || (blocktype < 5)) 
          && (min_mcost > stopCriterion) && (input->EPZSDual > 0);
        
        if (!conditionEPZS) break;
        
        pointNumber = 0;
        patternStop = 0;
        motionDirection = 0;        
        
        if ((tempmv_x == 0 && tempmv_y == 0) 
          || (tempmv_x == *mv_x && tempmv_y == *mv_y))
        {
          if (abs (tempmv_x - *mv_x) < 2 && abs (tempmv_y - *mv_y) < 2)
            searchPatternF = sdiamond;
          else
            searchPatternF = square;
        }
        else
          searchPatternF = searchPatternD;        
        totalCheckPts = searchPatternF->searchPoints;
        
        //! Second best. Note that following code is identical as for best predictor.
        center_x = tempmv_x2;
        center_y = tempmv_y2;
        checkMedian = FALSE;        
      }
    }
  }
  
  if ((ref==0) || (prevSad[pic_pix_x2] > min_mcost))
    prevSad[pic_pix_x2] = min_mcost;
#if EPZSREF  
  if (input->EPZSSpatialMem)  
#else
    if (input->EPZSSpatialMem && ref == 0)  
#endif
    {
      motion[0]  = tempmv_x;
      motion[1]  = tempmv_y;
    }
    
    *mv_x = tempmv_x;
    *mv_y = tempmv_y;
    return min_mcost;
}


/*!
***********************************************************************
* \brief
*    FAST Motion Estimation using EPZS
*    AMT/HYC
***********************************************************************
*/
int				                                        //  ==> minimum motion cost after search
EPZSBiPredBlockMotionSearch (pel_t ** cur_pic,	  // <--  original pixel values for the AxB block
                             short  ref,	        // <--  reference picture 
                             int    list,         // <--  reference list
                             int    list_offset,  // <--  offset for Mbaff
                             char  ***refPic,    // <--  reference array
                             short  ****tmp_mv,   // <--  mv array
                             int    pic_pix_x,	  // <--  absolute x-coordinate of regarded AxB block
                             int    pic_pix_y,	  // <--  absolute y-coordinate of regarded AxB block
                             int    blocktype,    //<--  block type (1-16x16 ... 7-4x4)
                             short  pred_mv_x1,   // <--  motion vector predictor (x) in sub-pel units
                             short  pred_mv_y1,   // <--  motion vector predictor (y) in sub-pel units
                             short  pred_mv_x2,   // <--  motion vector predictor (x) in sub-pel units
                             short  pred_mv_y2,   // <--  motion vector predictor (y) in sub-pel units
                             short  *mv_x,	      // <--> in: search center (x) / out: motion vector (x) - in pel units
                             short  *mv_y,	      // <--> in: search center (y) / out: motion vector (y) - in pel units
                             short  *s_mv_x,      // <--> in: search center (x) / out: motion vector (x) - in pel units
                             short  *s_mv_y,      // <--> in: search center (y) / out: motion vector (y) - in pel units
                             int    search_range,	// <--  1-d search range in pel units
                             int    min_mcost,	  // <--  minimum motion cost (cost for center or huge value)
                             int    lambda_factor)	      // <--  lagrangian parameter for determining motion cost
{
  short blocksize_y = input->blc_size[blocktype][1];	// vertical block size
  short blocksize_x = input->blc_size[blocktype][0];	// horizontal block size
  short blockshape_x = (blocksize_x >> 2);	// horizontal block size in 4-pel units
  short mb_x = pic_pix_x - img->opix_x;
  short mb_y = pic_pix_y - img->opix_y;
  short block_x = (mb_x >> 2);
  short block_y = (mb_y >> 2);  
  int   pred_x1 = (pic_pix_x << 2) + pred_mv_x1; // predicted position x (in sub-pel units)
  int   pred_y1 = (pic_pix_y << 2) + pred_mv_y1; // predicted position y (in sub-pel units)
  int   pred_x2 = (pic_pix_x << 2) + pred_mv_x2; // predicted position x (in sub-pel units)
  int   pred_y2 = (pic_pix_y << 2) + pred_mv_y2; // predicted position y (in sub-pel units)
  int   center2_x = pic_pix_x + *mv_x;          // center position x (in pel units)
  int   center2_y = pic_pix_y + *mv_y;          // center position y (in pel units)
  int   center1_x = pic_pix_x + *s_mv_x;   // mvx of second pred (in pel units)
  int   center1_y = pic_pix_y + *s_mv_y;   // mvy of second pred (in pel units)
  int   tempmv_x  = *mv_x, tempmv_y  = *mv_y;
  int   tempmv_x2 = 0, tempmv_y2 = 0;
  int stopCriterion = medthres[blocktype];  
  int mapCenter_x = search_range - *mv_x;
  int mapCenter_y = search_range - *mv_y;
  int second_mcost = INT_MAX;
  short apply_weights = (active_pps->weighted_bipred_idc != 0);
  short offset1 = apply_weights ? list == 0
    ? wp_offset[list_offset         ][ref]     [0]
    : wp_offset[list_offset + LIST_1][0  ]     [0] 
    : 0;
  short offset2 = apply_weights ? list == 0
    ? wp_offset[list_offset + LIST_1][ref]     [0]
    : wp_offset[list_offset         ][0  ]     [0] 
    : 0;  
  short invalid_refs = 0;
  byte checkMedian = FALSE;  
  EPZSStructure *searchPatternF = searchPattern;
  ref_pic1 = listX[ list      + list_offset][ref]->imgY_11;
  ref_pic2 = listX[(list ^ 1) + list_offset][ 0 ]->imgY_11;  
  
  img_width  = listX[ list    + list_offset][ref]->size_x;
  img_height = listX[ list    + list_offset][ref]->size_y;
  
  weight1 = apply_weights ? list == 0 
    ? wbp_weight[list_offset         ][ref][0  ][0]
    : wbp_weight[list_offset + LIST_1][0  ][ref][0]
    : 1<<luma_log_weight_denom;
  weight2 = apply_weights ? list == 0
    ? wbp_weight[list_offset + LIST_1][ref][0  ][0]
    : wbp_weight[list_offset         ][0  ][ref][0]
    : 1<<luma_log_weight_denom;
  offsetBi=(offset1 + offset2 + 1)>>1;
  
  computeBiPredSad = apply_weights? computeBiPredSad2 : computeBiPredSad1;
  
  //===== set function for getting reference picture lines from reference 1=====  
  if ( (center2_x > search_range) && (center2_x < img_width  - search_range-blocksize_x) 
    && (center2_y > search_range) && (center2_y < img_height - search_range-blocksize_y))
  {
    get_ref_line2 = FastLineX;
  }
  else
  {
    get_ref_line2 = UMVLineX;
  }
  
  //===== set function for getting reference picture lines from reference 2=====
  if ( (center1_x > search_range) && (center1_x < img_width  - search_range-blocksize_x) 
    && (center1_y > search_range) && (center1_y < img_height - search_range-blocksize_y))
  {
    get_ref_line1 = FastLineX;
  }
  else
  {
    get_ref_line1 = UMVLineX;
  }  
  // Clear EPZSMap
  memset(EPZSMap[0],FALSE,(2*search_range+1)*(2*search_range+1));
  // Check median candidate;  
  EPZSMap[search_range][search_range] = TRUE;
  
  //--- initialize motion cost (cost for motion vector) and check ---
  min_mcost  = MV_COST (lambda_factor, 2, center1_x, center1_y, pred_x1, pred_y1);
  min_mcost += MV_COST (lambda_factor, 2, center2_x, center2_y, pred_x2, pred_y2);
  
  //--- add residual cost to motion cost ---
  min_mcost = computeBiPredSad(cur_pic, blocksize_y, blocksize_x, blockshape_x, 
    min_mcost, INT_MAX, center1_x, center1_y, center2_x, center2_y);
  
  //! If medthres satisfied, then terminate, otherwise generate Predictors  
  if (min_mcost > stopCriterion)
  {       
    int prednum = 5;
    int patternStop = 0, pointNumber = 0, checkPts;
    int totalCheckPts = 0, motionDirection = 0;
    int   conditionEPZS;
    int   mvx, mvy, cand_x, cand_y;
    int   pos, mcost;  
    PixelPos block_a, block_b, block_c, block_d;
    
    getLuma4x4Neighbour (img->current_mb_nr, block_x, block_y, -1, 0, &block_a);
    getLuma4x4Neighbour (img->current_mb_nr, block_x, block_y, 0, -1, &block_b);
    getLuma4x4Neighbour (img->current_mb_nr, block_x, block_y, blocksize_x, -1, &block_c);
    getLuma4x4Neighbour (img->current_mb_nr, block_x, block_y, -1, -1, &block_d);
    
    if (mb_y > 0)
    {
      if (mb_x < 8)  // first column of 8x8 blocks
      {
        if (mb_y==8)
        {
          if (blocksize_x == MB_BLOCK_SIZE) 
            block_c.available  = 0;
        }
        else if (mb_x+blocksize_x == 8) 
          block_c.available = 0;
      }
      else if (mb_x+blocksize_x == MB_BLOCK_SIZE) 
        block_c.available = 0;
    }
    
    stopCriterion = (11 * medthres[blocktype]) >> 3;
    
    //! Add Spatial Predictors in predictor list.
    //! Scheme adds zero, left, top-left, top, top-right. Note that top-left adds very little
    //! in terms of performance and could be removed with little penalty if any.
    invalid_refs = EPZSSpatialPredictors (block_a, block_b, block_c, block_d, 
      list, list_offset, ref, refPic[list], tmp_mv[list], predictor);
    
    //! Check all predictors          
    for (pos = 0; pos < prednum; pos++)
    {
      mvx = predictor->point[pos].x;
      mvy = predictor->point[pos].y;
      if ((abs (mvx - *mv_x) > search_range || abs (mvy - *mv_y) > search_range) && (mvx || mvy))
        continue;
      
      if ((abs (mvx - *mv_x) <= search_range) && (abs (mvy - *mv_y) <= search_range))
      {
        if (EPZSMap[mapCenter_y + mvy][mapCenter_x + mvx] == TRUE)
          continue;
        else
          EPZSMap[mapCenter_y + mvy][mapCenter_x + mvx] = TRUE;
      }
      
      cand_x = pic_pix_x + mvx;
      cand_y = pic_pix_y + mvy;
      
      //--- set motion cost (cost for motion vector) and check ---
      mcost  = MV_COST (lambda_factor, 2, center1_x, center1_y, pred_x1, pred_y1);
      mcost += MV_COST (lambda_factor, 2, cand_x   ,    cand_y, pred_x2, pred_y2);
      
      if (mcost >= second_mcost) continue;
      
      mcost = computeBiPredSad(cur_pic, blocksize_y, blocksize_x, blockshape_x, 
        mcost, second_mcost, center1_x, center1_y, cand_x, cand_y);
      
      //--- check if motion cost is less than minimum cost ---
      if (mcost < min_mcost)
      {
        tempmv_x2 = tempmv_x;
        tempmv_y2 = tempmv_y;
        second_mcost = min_mcost;
        tempmv_x = mvx;
        tempmv_y = mvy;
        min_mcost = mcost;
        checkMedian = TRUE;
      }      
      //else if (mcost < second_mcost && (tempmv_x != mvx || tempmv_y != mvy))
      else if (mcost < second_mcost)
      {
        tempmv_x2 = mvx;
        tempmv_y2 = mvy;
        second_mcost = mcost;
        checkMedian = TRUE;
      }
    }
    
    //! Refine using EPZS pattern if needed.
    //! Note that we are using a simplistic threshold computation.
    if (min_mcost > stopCriterion)
    {
      //! Adapt pattern based on different conditions.
      if (input->EPZSPattern != 0)
      {
        if ((min_mcost < stopCriterion + ((3 * medthres[blocktype]) >> 1)))
        {
          if ((tempmv_x == 0 && tempmv_y == 0)
            || (abs (tempmv_x - *mv_x) < 2 && abs (tempmv_y - *mv_y) < 2))
            searchPatternF = sdiamond;
          else
            searchPatternF = square;
        }
        else if (blocktype > 5 || (ref > 0 && blocktype != 1))
          searchPatternF = square;
        else
          searchPatternF = searchPattern;
      }
      
      totalCheckPts = searchPatternF->searchPoints;
      
      //! center on best predictor      
      center2_x = tempmv_x;
      center2_y = tempmv_y;
      while (1)
      {
        do
        {
          checkPts = totalCheckPts;
          do
          {
            mvx = center2_x + searchPatternF->point[pointNumber].x;
            mvy = center2_y + searchPatternF->point[pointNumber].y;
            cand_x = pic_pix_x + mvx;
            cand_y = pic_pix_y + mvy;
            
            if ((abs (mvx - *mv_x) <= search_range) 
              && (abs (mvy - *mv_y) <= search_range))
            {
              if (EPZSMap[mapCenter_y + mvy][mapCenter_x + mvx] != TRUE)
                EPZSMap[mapCenter_y + mvy][mapCenter_x + mvx] = TRUE;
              else
              {
                pointNumber += 1;
                if (pointNumber >= searchPatternF->searchPoints)
                  pointNumber -= searchPatternF->searchPoints;
                checkPts -= 1;
                continue;
              }
              
              mcost  = MV_COST (lambda_factor, 2, center1_x, center1_y, pred_x1, pred_y1);
              mcost += MV_COST (lambda_factor, 2, cand_x   ,    cand_y, pred_x2, pred_y2);     
              
              if (mcost < min_mcost)
              {         
                mcost = computeBiPredSad(cur_pic, blocksize_y, blocksize_x, blockshape_x, 
                  mcost, min_mcost, center1_x, center1_y, cand_x, cand_y);
                
                if (mcost < min_mcost)
                {
                  min_mcost = mcost;
                  tempmv_x = mvx;
                  tempmv_y = mvy;
                  motionDirection = pointNumber;
                }
              }
            }
            pointNumber += 1;
            if (pointNumber >= searchPatternF->searchPoints)
              pointNumber -= searchPatternF->searchPoints;
            checkPts -= 1;
          }
          while (checkPts > 0);
          
          if ((tempmv_x == center2_x) && (tempmv_y == center2_y))
          {
            totalCheckPts = searchPatternF->searchPoints;
            patternStop = 1;
            motionDirection = 0;
            pointNumber = 0;
          }
          else
          {
            totalCheckPts = searchPatternF->point[motionDirection].next_points;
            pointNumber = searchPatternF->point[motionDirection].start_nmbr;
            center2_x = tempmv_x;
            center2_y = tempmv_y;
          }
        }
        while (patternStop != 1);
        
        //! Check Second best predictor with EPZS pattern     
        
        conditionEPZS = (checkMedian == TRUE) && (blocktype < 5) && (min_mcost > stopCriterion) && (input->EPZSDual > 0);
        
        if (!conditionEPZS) break;
        
        pointNumber = 0;
        patternStop = 0;
        motionDirection = 0;        
        
        if ((tempmv_x == 0 && tempmv_y == 0) 
          || (tempmv_x == *mv_x && tempmv_y == *mv_y))
        {
          if (abs (tempmv_x - *mv_x) < 2 && abs (tempmv_y - *mv_y) < 2)
            searchPatternF = sdiamond;
          else
            searchPatternF = square;
        }
        else
          searchPatternF = searchPatternD;
        totalCheckPts = searchPatternF->searchPoints;
        
        //! Second best. Note that following code is identical as for best predictor.
        center2_x = tempmv_x2;
        center2_y = tempmv_y2;
        
        checkMedian = FALSE;
      }
    }
  }
  *mv_x = tempmv_x;
  *mv_y = tempmv_y;  
  return min_mcost;
}

/*!
***********************************************************************
* \brief
*    Report function for EPZS Fast ME
*    AMT/HYC
***********************************************************************
*/
void
EPZSOutputStats (FILE * stat, short stats_file)
{  
  if (stats_file == 1)
  {
    fprintf (stat, " EPZS Pattern                 : %s\n",c_EPZSPattern[input->EPZSPattern]);
    fprintf (stat, " EPZS Dual Pattern            : %s\n",c_EPZSDualPattern[input->EPZSDual]);
    fprintf (stat, " EPZS Fixed Predictors        : %s\n",c_EPZSFixed[input->EPZSFixed]);
    fprintf (stat, " EPZS Temporal Predictors     : %s\n",c_EPZSOther[input->EPZSTemporal]);
    fprintf (stat, " EPZS Spatial Predictors      : %s\n",c_EPZSOther[input->EPZSSpatialMem]);
    fprintf (stat, " EPZS Thresholds (16x16)      : (%d %d %d)\n",medthres[1], minthres[1], maxthres[1]);
  }
  else
  {
    fprintf (stat, " EPZS Pattern                      : %s\n",c_EPZSPattern[input->EPZSPattern]);
    fprintf (stat, " EPZS Dual Pattern                 : %s\n",c_EPZSDualPattern[input->EPZSDual]);
    fprintf (stat, " EPZS Fixed Predictors             : %s\n",c_EPZSFixed[input->EPZSFixed]);
    fprintf (stat, " EPZS Temporal Predictors          : %s\n",c_EPZSOther[input->EPZSTemporal]);
    fprintf (stat, " EPZS Spatial Predictors           : %s\n",c_EPZSOther[input->EPZSSpatialMem]);    
    fprintf (stat, " EPZS Thresholds (16x16)           : (%d %d %d)\n",medthres[1], minthres[1], maxthres[1]);
  }
}
