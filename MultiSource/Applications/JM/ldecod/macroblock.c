
/*!
 ***********************************************************************
 * \file macroblock.c
 *
 * \brief
 *     Decode a Macroblock
 *
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *    - Inge Lille-Langøy               <inge.lille-langoy@telenor.com>
 *    - Rickard Sjoberg                 <rickard.sjoberg@era.ericsson.se>
 *    - Jani Lainema                    <jani.lainema@nokia.com>
 *    - Sebastian Purreiter             <sebastian.purreiter@mch.siemens.de>
 *    - Thomas Wedi                     <wedi@tnt.uni-hannover.de>
 *    - Detlev Marpe                    <marpe@hhi.de>
 *    - Gabi Blaettermann               <blaetter@hhi.de>
 *    - Ye-Kui Wang                     <wyk@ieee.org>
 *    - Lowell Winger                   <lwinger@lsil.com>
 ***********************************************************************
*/

#include "contributors.h"

#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "global.h"
#include "mbuffer.h"
#include "elements.h"
#include "errorconcealment.h"
#include "macroblock.h"
#include "fmo.h"
#include "cabac.h"
#include "vlc.h"
#include "image.h"
#include "mb_access.h"
#include "biaridecod.h"

#include "transform8x8.h"

#if TRACE
#define TRACE_STRING(s) strncpy(currSE.tracestring, s, TRACESTRING_SIZE)
#else
#define TRACE_STRING(s) // do nothing
#endif

extern int last_dquant;
extern ColocatedParams *Co_located;


static void SetMotionVectorPredictor (struct img_par  *img,
                                      short           *pmv_x,
                                      short           *pmv_y,
                                      char            ref_frame,
                                      byte            list,
                                      char            ***refPic,
                                      short           ****tmp_mv,
                                      int             block_x,
                                      int             block_y,
                                      int             blockshape_x,
                                      int             blockshape_y);


/*!
 ************************************************************************
 * \brief
 *    initializes the current macroblock
 ************************************************************************
 */
void start_macroblock(struct img_par *img,struct inp_par *inp, int CurrentMBInScanOrder)
{
  int i,j,k,l;
  Macroblock *currMB;   // intialization code deleted, see below, StW

  assert (img->current_mb_nr < img->PicSizeInMbs);

  currMB = &img->mb_data[img->current_mb_nr];

  /* Update coordinates of the current macroblock */
  if (img->MbaffFrameFlag)
  {
    img->mb_x = (img->current_mb_nr)%((2*img->width)/MB_BLOCK_SIZE);
    img->mb_y = 2*((img->current_mb_nr)/((2*img->width)/MB_BLOCK_SIZE));

    if (img->mb_x % 2)
    {
      img->mb_y++;
    }

    img->mb_x /= 2;
  }
  else
  {
    img->mb_x = (img->current_mb_nr)%(img->width/MB_BLOCK_SIZE);
    img->mb_y = (img->current_mb_nr)/(img->width/MB_BLOCK_SIZE);
  }
  
  /* Define vertical positions */
  img->block_y = img->mb_y * BLOCK_SIZE;      /* luma block position */
  img->pix_y   = img->mb_y * MB_BLOCK_SIZE;   /* luma macroblock position */
  img->pix_c_y = img->mb_y * img->mb_cr_size_y; /* chroma macroblock position */
  
  /* Define horizontal positions */
  img->block_x = img->mb_x * BLOCK_SIZE;      /* luma block position */
  img->pix_x   = img->mb_x * MB_BLOCK_SIZE;   /* luma pixel position */
  
  img->pix_c_x = img->mb_x * img->mb_cr_size_x; /* chroma pixel position */

  // Save the slice number of this macroblock. When the macroblock below
  // is coded it will use this to decide if prediction for above is possible
  currMB->slice_nr = img->current_slice_nr;
  
  if (img->current_slice_nr >= MAX_NUM_SLICES)
  {
    error ("maximum number of supported slices exceeded, please recompile with increased value for MAX_NUM_SLICES", 200);
  }

  dec_picture->slice_id[img->mb_y][img->mb_x] = img->current_slice_nr;
  if (img->current_slice_nr > dec_picture->max_slice_id)
  {
    dec_picture->max_slice_id=img->current_slice_nr;
  }
  
  CheckAvailabilityOfNeighbors(img);

  // Reset syntax element entries in MB struct
  currMB->qp          = img->qp ;
  currMB->mb_type     = 0;
  currMB->delta_quant = 0;
  currMB->cbp         = 0;
  currMB->cbp_blk     = 0;
  currMB->c_ipred_mode= DC_PRED_8; //GB

  for (l=0; l < 2; l++)
    for (j=0; j < BLOCK_MULTIPLE; j++)
      for (i=0; i < BLOCK_MULTIPLE; i++)
        for (k=0; k < 2; k++)
          currMB->mvd[l][j][i][k] = 0;

  currMB->cbp_bits   = 0;

  // initialize img->m7 for ABT
  for (j=0; j<MB_BLOCK_SIZE; j++)
    for (i=0; i<MB_BLOCK_SIZE; i++)
      img->m7[i][j] = 0;

  // store filtering parameters for this MB 
  currMB->LFDisableIdc = img->currentSlice->LFDisableIdc;
  currMB->LFAlphaC0Offset = img->currentSlice->LFAlphaC0Offset;
  currMB->LFBetaOffset = img->currentSlice->LFBetaOffset;

}

/*!
 ************************************************************************
 * \brief
 *    set coordinates of the next macroblock
 *    check end_of_slice condition 
 ************************************************************************
 */
int exit_macroblock(struct img_par *img,struct inp_par *inp,int eos_bit)
{
 //! The if() statement below resembles the original code, which tested 
  //! img->current_mb_nr == img->PicSizeInMbs.  Both is, of course, nonsense
  //! In an error prone environment, one can only be sure to have a new
  //! picture by checking the tr of the next slice header!

// printf ("exit_macroblock: FmoGetLastMBOfPicture %d, img->current_mb_nr %d\n", FmoGetLastMBOfPicture(), img->current_mb_nr);
  img->num_dec_mb++;
  
  if (img->num_dec_mb == img->PicSizeInMbs)
//  if (img->current_mb_nr == FmoGetLastMBOfPicture(currSlice->structure))
  {
//thb
/*
    if (currSlice->next_header != EOS)
      currSlice->next_header = SOP;
*/
//the
    assert (nal_startcode_follows (img, inp, eos_bit) == TRUE);
    return TRUE;
  }
  // ask for last mb in the slice  UVLC
  else
  {
// printf ("exit_macroblock: Slice %d old MB %d, now using MB %d\n", img->current_slice_nr, img->current_mb_nr, FmoGetNextMBNr (img->current_mb_nr));

    img->current_mb_nr = FmoGetNextMBNr (img->current_mb_nr);

    if (img->current_mb_nr == -1)     // End of Slice group, MUST be end of slice
    {
      assert (nal_startcode_follows (img, inp, eos_bit) == TRUE);
      return TRUE;
    }

    if(nal_startcode_follows(img, inp, eos_bit) == FALSE) 
      return FALSE;

    if(img->type == I_SLICE  || img->type == SI_SLICE || active_pps->entropy_coding_mode_flag == CABAC)
      return TRUE;
    if(img->cod_counter<=0)
      return TRUE;
    return FALSE;
  }
}

/*!
 ************************************************************************
 * \brief
 *    Interpret the mb mode for P-Frames
 ************************************************************************
 */
void interpret_mb_mode_P(struct img_par *img)
{
  int i;
  const int ICBPTAB[6] = {0,16,32,15,31,47};
  Macroblock *currMB = &img->mb_data[img->current_mb_nr];
  int         mbmode = currMB->mb_type;

#define ZERO_P8x8     (mbmode==5)
#define MODE_IS_P8x8  (mbmode==4 || mbmode==5)
#define MODE_IS_I4x4  (mbmode==6)
#define I16OFFSET     (mbmode-7)
#define MODE_IS_IPCM  (mbmode==31)

  if(mbmode <4)
  {
    currMB->mb_type = mbmode;
    for (i=0;i<4;i++)
    {
      currMB->b8mode[i]   = mbmode;
      currMB->b8pdir[i]   = 0;
    }
  }
  else if(MODE_IS_P8x8)
  {
    currMB->mb_type = P8x8;
    img->allrefzero = ZERO_P8x8;
  }
  else if(MODE_IS_I4x4)
  {
    currMB->mb_type = I4MB;
    for (i=0;i<4;i++)
    {
      currMB->b8mode[i] = IBLOCK;
      currMB->b8pdir[i] = -1;
    }
  }
  else if(MODE_IS_IPCM)
  {
    currMB->mb_type=IPCM;
    
    for (i=0;i<4;i++) 
    {
      currMB->b8mode[i]=0; currMB->b8pdir[i]=-1; 
    }
    currMB->cbp= -1;
    currMB->i16mode = 0;
  }
  else
  {
    currMB->mb_type = I16MB;
    for (i=0;i<4;i++) {currMB->b8mode[i]=0; currMB->b8pdir[i]=-1; }
    currMB->cbp= ICBPTAB[(I16OFFSET)>>2];
    currMB->i16mode = (I16OFFSET) & 0x03;
  }
}

/*!
 ************************************************************************
 * \brief
 *    Interpret the mb mode for I-Frames
 ************************************************************************
 */
void interpret_mb_mode_I(struct img_par *img)
{
  int i;
  const int ICBPTAB[6] = {0,16,32,15,31,47};
  Macroblock *currMB   = &img->mb_data[img->current_mb_nr];
  int         mbmode   = currMB->mb_type;

  if (mbmode==0)
  {
    currMB->mb_type = I4MB;
    for (i=0;i<4;i++) {currMB->b8mode[i]=IBLOCK; currMB->b8pdir[i]=-1; }
  }
  else if(mbmode==25)
  {
    currMB->mb_type=IPCM;

    for (i=0;i<4;i++) {currMB->b8mode[i]=0; currMB->b8pdir[i]=-1; }
    currMB->cbp= -1;
    currMB->i16mode = 0;

  }
  else
  {
    currMB->mb_type = I16MB;
    for (i=0;i<4;i++) {currMB->b8mode[i]=0; currMB->b8pdir[i]=-1; }
    currMB->cbp= ICBPTAB[(mbmode-1)>>2];
    currMB->i16mode = (mbmode-1) & 0x03;
  }
}

/*!
 ************************************************************************
 * \brief
 *    Interpret the mb mode for B-Frames
 ************************************************************************
 */
void interpret_mb_mode_B(struct img_par *img)
{
  static const int offset2pdir16x16[12]   = {0, 0, 1, 2, 0,0,0,0,0,0,0,0};
  static const int offset2pdir16x8[22][2] = {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{1,1},{0,0},{0,1},{0,0},{1,0},
                                             {0,0},{0,2},{0,0},{1,2},{0,0},{2,0},{0,0},{2,1},{0,0},{2,2},{0,0}};
  static const int offset2pdir8x16[22][2] = {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{1,1},{0,0},{0,1},{0,0},
                                             {1,0},{0,0},{0,2},{0,0},{1,2},{0,0},{2,0},{0,0},{2,1},{0,0},{2,2}};

  const int ICBPTAB[6] = {0,16,32,15,31,47};
  Macroblock *currMB = &img->mb_data[img->current_mb_nr];

  int i, mbmode;
  int mbtype  = currMB->mb_type;
  int *b8mode = currMB->b8mode;
  int *b8pdir = currMB->b8pdir;

  //--- set mbtype, b8type, and b8pdir ---
  if (mbtype==0)       // direct
  {
      mbmode=0;       for(i=0;i<4;i++) {b8mode[i]=0;          b8pdir[i]=2; }
  }
  else if (mbtype==23) // intra4x4
  {
    mbmode=I4MB;    for(i=0;i<4;i++) {b8mode[i]=IBLOCK;     b8pdir[i]=-1; }
  }
  else if ((mbtype>23) && (mbtype<48) ) // intra16x16
  {
    mbmode=I16MB;   for(i=0;i<4;i++) {b8mode[i]=0;          b8pdir[i]=-1; }
    currMB->cbp     = ICBPTAB[(mbtype-24)>>2];
    currMB->i16mode = (mbtype-24) & 0x03;
  }
  else if (mbtype==22) // 8x8(+split)
  {
    mbmode=P8x8;       // b8mode and pdir is transmitted in additional codewords
  }
  else if (mbtype<4)   // 16x16
  {
    mbmode=1;       for(i=0;i<4;i++) {b8mode[i]=1;          b8pdir[i]=offset2pdir16x16[mbtype]; }
  }
  else if(mbtype==48)
  {
    mbmode=IPCM;
    for (i=0;i<4;i++) {currMB->b8mode[i]=0; currMB->b8pdir[i]=-1; }
    currMB->cbp= -1;
    currMB->i16mode = 0;
  }

  else if (mbtype%2==0) // 16x8
  {
    mbmode=2;       for(i=0;i<4;i++) {b8mode[i]=2;          b8pdir[i]=offset2pdir16x8 [mbtype][i/2]; }
  }
  else
  {
    mbmode=3;       for(i=0;i<4;i++) {b8mode[i]=3;          b8pdir[i]=offset2pdir8x16 [mbtype][i%2]; }
  }
  currMB->mb_type = mbmode;
}
/*!
 ************************************************************************
 * \brief
 *    Interpret the mb mode for SI-Frames
 ************************************************************************
 */
void interpret_mb_mode_SI(struct img_par *img)
{
  int i;
  const int ICBPTAB[6] = {0,16,32,15,31,47};
  Macroblock *currMB   = &img->mb_data[img->current_mb_nr];
  int         mbmode   = currMB->mb_type;

  if (mbmode==0)
  {
    currMB->mb_type = SI4MB;
    for (i=0;i<4;i++) {currMB->b8mode[i]=IBLOCK; currMB->b8pdir[i]=-1; }
    img->siblock[img->mb_x][img->mb_y]=1;
  }
  else if (mbmode==1)
  {
    currMB->mb_type = I4MB;
    for (i=0;i<4;i++) {currMB->b8mode[i]=IBLOCK; currMB->b8pdir[i]=-1; }
  }
  else if(mbmode==26)
  {
    currMB->mb_type=IPCM;

    for (i=0;i<4;i++) {currMB->b8mode[i]=0; currMB->b8pdir[i]=-1; }
    currMB->cbp= -1;
    currMB->i16mode = 0;

  }

  else
  {
    currMB->mb_type = I16MB;
    for (i=0;i<4;i++) {currMB->b8mode[i]=0; currMB->b8pdir[i]=-1; }
    currMB->cbp= ICBPTAB[(mbmode-1)>>2];
    currMB->i16mode = (mbmode-2) & 0x03;
  }
}
/*!
 ************************************************************************
 * \brief
 *    init macroblock I and P frames
 ************************************************************************
 */
void init_macroblock(struct img_par *img)
{
  int i,j;

  for (i=0;i<BLOCK_SIZE;i++)
  {                           // reset vectors and pred. modes
    for(j=0;j<BLOCK_SIZE;j++)
    {
      dec_picture->mv[LIST_0][img->block_y+j][img->block_x+i][0]=0;
      dec_picture->mv[LIST_0][img->block_y+j][img->block_x+i][1]=0;
      dec_picture->mv[LIST_1][img->block_y+j][img->block_x+i][0]=0;
      dec_picture->mv[LIST_1][img->block_y+j][img->block_x+i][1]=0;

      img->ipredmode[img->block_x+i][img->block_y+j] = DC_PRED;
    }
  }

  for (j=0; j<BLOCK_SIZE; j++)
    for (i=0; i<BLOCK_SIZE; i++)
    {
      dec_picture->ref_idx[LIST_0][img->block_y+j][img->block_x+i] = -1;
      dec_picture->ref_idx[LIST_1][img->block_y+j][img->block_x+i] = -1;
      dec_picture->ref_pic_id[LIST_0][img->block_y+j][img->block_x+i] = INT64_MIN;
      dec_picture->ref_pic_id[LIST_1][img->block_y+j][img->block_x+i] = INT64_MIN;
    }
}


/*!
 ************************************************************************
 * \brief
 *    Sets mode for 8x8 block
 ************************************************************************
 */
void SetB8Mode (struct img_par* img, Macroblock* currMB, int value, int i)
{
  static const int p_v2b8 [ 5] = {4, 5, 6, 7, IBLOCK};
  static const int p_v2pd [ 5] = {0, 0, 0, 0, -1};
  static const int b_v2b8 [14] = {0, 4, 4, 4, 5, 6, 5, 6, 5, 6, 7, 7, 7, IBLOCK};
  static const int b_v2pd [14] = {2, 0, 1, 2, 0, 0, 1, 1, 2, 2, 0, 1, 2, -1};

  if (img->type==B_SLICE)
  {
    currMB->b8mode[i]   = b_v2b8[value];
    currMB->b8pdir[i]   = b_v2pd[value];

  }
  else
  {
    currMB->b8mode[i]   = p_v2b8[value];
    currMB->b8pdir[i]   = p_v2pd[value];
  }

}


void reset_coeffs()
{
  int i, j, iii, jjj;

  // reset luma coeffs
  for (i=0;i<BLOCK_SIZE;i++)
  { 
    for (j=0;j<BLOCK_SIZE;j++)
      for(iii=0;iii<BLOCK_SIZE;iii++)
        for(jjj=0;jjj<BLOCK_SIZE;jjj++)
          img->cof[i][j][iii][jjj]=0;
  }

  // reset chroma coeffs
  for (j=4;j<(4+img->num_blk8x8_uv);j++)
  { 
    for (i=0;i<4;i++)
      for (iii=0;iii<4;iii++)
        for (jjj=0;jjj<4;jjj++)
          img->cof[i][j][iii][jjj]=0;
  }
  
  // CAVLC
  for (i=0; i < 4; i++)
    for (j=0; j < (4 + img->num_blk8x8_uv); j++)
      img->nz_coeff[img->current_mb_nr][i][j]=0;  

}

void field_flag_inference()
{
  Macroblock *currMB = &img->mb_data[img->current_mb_nr];

  if (currMB->mbAvailA)
  {
    currMB->mb_field = img->mb_data[currMB->mbAddrA].mb_field;
  }
  else
  {
    // check top macroblock pair
    if (currMB->mbAvailB)
    {
      currMB->mb_field = img->mb_data[currMB->mbAddrB].mb_field;
    }
    else
      currMB->mb_field = 0;
  }
  
}

/*!
 ************************************************************************
 * \brief
 *    Get the syntax elements from the NAL
 ************************************************************************
 */
int read_one_macroblock(struct img_par *img,struct inp_par *inp)
{
  int i;

  SyntaxElement currSE;
  Macroblock *currMB = &img->mb_data[img->current_mb_nr];

  Slice *currSlice = img->currentSlice;
  DataPartition *dP;
  int *partMap = assignSE2partition[currSlice->dp_mode];
  Macroblock *topMB = NULL;
  int  prevMbSkipped = 0;
  int  img_block_y;
  int  check_bottom, read_bottom, read_top;
  
  if (img->MbaffFrameFlag)
  {
    if (img->current_mb_nr%2)
    {
      topMB= &img->mb_data[img->current_mb_nr-1];
      if(!(img->type == B_SLICE))
        prevMbSkipped = (topMB->mb_type == 0);
      else 
        prevMbSkipped = topMB->skip_flag;
    }
    else 
      prevMbSkipped = 0;
  }
  
  if (img->current_mb_nr%2 == 0)
    currMB->mb_field = 0;
  else
    currMB->mb_field = img->mb_data[img->current_mb_nr-1].mb_field;


  currMB->qp = img->qp ;

  currSE.type = SE_MBTYPE;

  //  read MB mode *****************************************************************
  dP = &(currSlice->partArr[partMap[currSE.type]]);
  
  if (active_pps->entropy_coding_mode_flag == UVLC || dP->bitstream->ei_flag)   currSE.mapping = linfo_ue;

  if(img->type == I_SLICE || img->type == SI_SLICE)
  {
    // read MB aff
    if (img->MbaffFrameFlag && img->current_mb_nr%2==0)
    {
      TRACE_STRING("mb_field_decoding_flag");
      if (active_pps->entropy_coding_mode_flag == UVLC || dP->bitstream->ei_flag)
      {
        currSE.len = 1;
        readSyntaxElement_FLC(&currSE, dP->bitstream);
      }
      else
      {
        currSE.reading = readFieldModeInfo_CABAC;
        dP->readSyntaxElement(&currSE,img,inp,dP);
      }
      currMB->mb_field = currSE.value1;
    }
    if(active_pps->entropy_coding_mode_flag  == CABAC)
      CheckAvailabilityOfNeighborsCABAC();

    //  read MB type
    TRACE_STRING("mb_type");
    currSE.reading = readMB_typeInfo_CABAC;
    dP->readSyntaxElement(&currSE,img,inp,dP);

    currMB->mb_type = currSE.value1;
    if(!dP->bitstream->ei_flag)
      currMB->ei_flag = 0;
  }
  // non I/SI-slice CABAC
  else if (active_pps->entropy_coding_mode_flag == CABAC)
  {
    // read MB skip_flag
    if (img->MbaffFrameFlag && (img->current_mb_nr%2 == 0||prevMbSkipped))
      field_flag_inference();
    
    CheckAvailabilityOfNeighborsCABAC();
    TRACE_STRING("mb_skip_flag");
    currSE.reading = readMB_skip_flagInfo_CABAC;
    dP->readSyntaxElement(&currSE,img,inp,dP);

    currMB->mb_type   = currSE.value1;
    currMB->skip_flag = !(currSE.value1);

    if (img->type==B_SLICE)
      currMB->cbp = currSE.value2;

    if(!dP->bitstream->ei_flag)
      currMB->ei_flag = 0;
    
    if ((img->type==B_SLICE) && currSE.value1==0 && currSE.value2==0)
      img->cod_counter=0;
      
    // read MB AFF
    if (img->MbaffFrameFlag) 
    {
      check_bottom=read_bottom=read_top=0;
      if (img->current_mb_nr%2==0)
      {
        check_bottom =  currMB->skip_flag;
        read_top = !check_bottom;
      }
      else
      {
        read_bottom = (topMB->skip_flag && (!currMB->skip_flag));
       }
      
      if (read_bottom || read_top)
      {
        TRACE_STRING("mb_field_decoding_flag");
        currSE.reading = readFieldModeInfo_CABAC;
        dP->readSyntaxElement(&currSE,img,inp,dP);
        currMB->mb_field = currSE.value1;
      }
      if (check_bottom)
        check_next_mb_and_get_field_mode_CABAC(&currSE,img,inp,dP);
      
    }

    CheckAvailabilityOfNeighborsCABAC();
      
    // read MB type
    if (currMB->mb_type != 0 )
    {
      currSE.reading = readMB_typeInfo_CABAC;
      TRACE_STRING("mb_type");
      dP->readSyntaxElement(&currSE,img,inp,dP);
      currMB->mb_type = currSE.value1;
      if(!dP->bitstream->ei_flag)
        currMB->ei_flag = 0;
    }
  }
  // VLC Non-Intra
  else
  {
    if(img->cod_counter == -1)
    {
      TRACE_STRING("mb_skip_run");
      dP->readSyntaxElement(&currSE,img,inp,dP);
      img->cod_counter = currSE.value1;
    }
    if (img->cod_counter==0)
    {
      // read MB aff
      if ((img->MbaffFrameFlag) && ((img->current_mb_nr%2==0) || ((img->current_mb_nr%2) && prevMbSkipped)))
      {
        TRACE_STRING("mb_field_decoding_flag");
        currSE.len = 1;
        readSyntaxElement_FLC(&currSE, dP->bitstream);
        currMB->mb_field = currSE.value1;
      }
      
      // read MB type
      TRACE_STRING("mb_type");
      dP->readSyntaxElement(&currSE,img,inp,dP);
      if(img->type == P_SLICE || img->type == SP_SLICE)
        currSE.value1++;
      currMB->mb_type = currSE.value1;
      if(!dP->bitstream->ei_flag)
        currMB->ei_flag = 0;
      img->cod_counter--;
      currMB->skip_flag = 0;
    } 
    else
    {
      img->cod_counter--;
      currMB->mb_type = 0;
      currMB->ei_flag = 0;
      currMB->skip_flag = 1;

      // read field flag of bottom block
      if(img->MbaffFrameFlag)
      {
        if(img->cod_counter == 0 && (img->current_mb_nr%2 == 0))
        {
          TRACE_STRING("mb_field_decoding_flag (of coded bottom mb)");
          currSE.len = 1;
          readSyntaxElement_FLC(&currSE, dP->bitstream);
          dP->bitstream->frame_bitoffset--;
          currMB->mb_field = currSE.value1;
        }
        else if(img->cod_counter > 0 && (img->current_mb_nr%2 == 0))
        {
          // check left macroblock pair first
          if (mb_is_available(img->current_mb_nr-2, img->current_mb_nr)&&((img->current_mb_nr%(img->PicWidthInMbs*2))!=0))
          {
            currMB->mb_field = img->mb_data[img->current_mb_nr-2].mb_field;
          }
          else
          {
            // check top macroblock pair
            if (mb_is_available(img->current_mb_nr-2*img->PicWidthInMbs, img->current_mb_nr))
            {
              currMB->mb_field = img->mb_data[img->current_mb_nr-2*img->PicWidthInMbs].mb_field;
            }
            else
              currMB->mb_field = 0;
          }
        }
      }
    }
  }

  dec_picture->mb_field[img->current_mb_nr] = currMB->mb_field;

  img->siblock[img->mb_x][img->mb_y]=0;

  if ((img->type==P_SLICE ))    // inter frame
    interpret_mb_mode_P(img);
  else if (img->type==I_SLICE)                                  // intra frame
    interpret_mb_mode_I(img);
  else if ((img->type==B_SLICE))       // B frame
    interpret_mb_mode_B(img);
  else if ((img->type==SP_SLICE))     // SP frame
    interpret_mb_mode_P(img);
  else if (img->type==SI_SLICE)     // SI frame
    interpret_mb_mode_SI(img);

  if(img->MbaffFrameFlag)
  {
    if(currMB->mb_field)
    {
      img->num_ref_idx_l0_active <<=1;
      img->num_ref_idx_l1_active <<=1;
    }
  }

  //init NoMbPartLessThan8x8Flag
  currMB->NoMbPartLessThan8x8Flag = (IS_DIRECT(currMB) && !(active_sps->direct_8x8_inference_flag))? 0: 1;

  //====== READ 8x8 SUB-PARTITION MODES (modes of 8x8 blocks) and Intra VBST block modes ======
  if (IS_P8x8 (currMB))
  {
    currSE.type    = SE_MBTYPE;
    dP = &(currSlice->partArr[partMap[SE_MBTYPE]]);

    for (i=0; i<4; i++)
    {
      if (active_pps->entropy_coding_mode_flag ==UVLC || dP->bitstream->ei_flag) currSE.mapping = linfo_ue;
      else                                                  currSE.reading = readB8_typeInfo_CABAC;

      TRACE_STRING("sub_mb_type");
      dP->readSyntaxElement (&currSE, img, inp, dP);
      SetB8Mode (img, currMB, currSE.value1, i);

      //set NoMbPartLessThan8x8Flag for P8x8 mode
      currMB->NoMbPartLessThan8x8Flag &= (currMB->b8mode[i]==0 && active_sps->direct_8x8_inference_flag) || 
                                         (currMB->b8mode[i]==4);
    }
    //--- init macroblock data ---
    init_macroblock       (img);
    readMotionInfoFromNAL (img, inp);
  }


  //============= Transform Size Flag for INTRA MBs =============
  //-------------------------------------------------------------
  //transform size flag for INTRA_4x4 and INTRA_8x8 modes
  if (currMB->mb_type == I4MB && img->Transform8x8Mode)
  {
    currSE.type   =  SE_HEADER;
    dP = &(currSlice->partArr[partMap[SE_HEADER]]);
    currSE.reading = readMB_transform_size_flag_CABAC;
    TRACE_STRING("transform size 8x8 flag");

    // read UVLC transform_size_8x8_flag
    if (active_pps->entropy_coding_mode_flag == UVLC || dP->bitstream->ei_flag)
    {
      currSE.len = 1;
      readSyntaxElement_FLC(&currSE, dP->bitstream);
    } 
    else 
    {
      dP->readSyntaxElement(&currSE,img,inp,dP);
    } 

    currMB->luma_transform_size_8x8_flag = currSE.value1;
    
    if (currMB->luma_transform_size_8x8_flag)
    {
      currMB->mb_type = I8MB;
      for (i=0;i<4;i++) {currMB->b8mode[i]=I8MB; currMB->b8pdir[i]=-1; }
    }
  }
  else
  {
    currMB->luma_transform_size_8x8_flag = 0;
  }

  if(active_pps->constrained_intra_pred_flag && (img->type==P_SLICE|| img->type==B_SLICE))        // inter frame
  {
    if( !IS_INTRA(currMB) )
    {
      img->intra_block[img->current_mb_nr] = 0;
    }
  }

  //! TO for Error Concelament
  //! If we have an INTRA Macroblock and we lost the partition
  //! which contains the intra coefficients Copy MB would be better 
  //! than just a grey block.
  //! Seems to be a bit at the wrong place to do this right here, but for this case 
  //! up to now there is no other way.
  dP = &(currSlice->partArr[partMap[SE_CBP_INTRA]]);
  if(IS_INTRA (currMB) && dP->bitstream->ei_flag && img->number)
  {
    currMB->mb_type = 0;
    currMB->ei_flag = 1;
    for (i=0;i<4;i++) {currMB->b8mode[i]=currMB->b8pdir[i]=0; }
  }
  dP = &(currSlice->partArr[partMap[currSE.type]]);
  //! End TO


  //--- init macroblock data ---
  if (!IS_P8x8 (currMB))
    init_macroblock       (img);

  if (IS_DIRECT (currMB) && img->cod_counter >= 0)
  {
    currMB->cbp = 0;
    reset_coeffs();

    if (active_pps->entropy_coding_mode_flag ==CABAC)
      img->cod_counter=-1;

    return DECODE_MB;
  }

  if (IS_COPY (currMB)) //keep last macroblock
  {
    int i, j, k;
    short pmv[2];
    int zeroMotionAbove;
    int zeroMotionLeft;
    PixelPos mb_a, mb_b;
    int      a_mv_y = 0;
    int      a_ref_idx = 0;
    int      b_mv_y = 0;
    int      b_ref_idx = 0;
    int      list_offset = ((img->MbaffFrameFlag)&&(currMB->mb_field))? img->current_mb_nr%2 ? 4 : 2 : 0;

    getLuma4x4Neighbour(img->current_mb_nr,0,0,-1, 0,&mb_a);
    getLuma4x4Neighbour(img->current_mb_nr,0,0, 0,-1,&mb_b);

    if (mb_a.available)
    {
      a_mv_y    = dec_picture->mv[LIST_0][mb_a.pos_y][mb_a.pos_x][1];
      a_ref_idx = dec_picture->ref_idx[LIST_0][mb_a.pos_y][mb_a.pos_x];

      if (currMB->mb_field && !img->mb_data[mb_a.mb_addr].mb_field)
      {
        a_mv_y    /=2;
        a_ref_idx *=2;
      }
      if (!currMB->mb_field && img->mb_data[mb_a.mb_addr].mb_field)
      {
        a_mv_y    *=2;
        a_ref_idx >>=1;
      }
    }

    if (mb_b.available)
    {
      b_mv_y    = dec_picture->mv[LIST_0][mb_b.pos_y][mb_b.pos_x][1];
      b_ref_idx = dec_picture->ref_idx[LIST_0][mb_b.pos_y][mb_b.pos_x];

      if (currMB->mb_field && !img->mb_data[mb_b.mb_addr].mb_field)
      {
        b_mv_y    /=2;
        b_ref_idx *=2;
      }
      if (!currMB->mb_field && img->mb_data[mb_b.mb_addr].mb_field)
      {
        b_mv_y    *=2;
        b_ref_idx >>=1;
      }
    }
    
    zeroMotionLeft  = !mb_a.available ? 1 : a_ref_idx==0 && dec_picture->mv[LIST_0][mb_a.pos_y][mb_a.pos_x][0]==0 && a_mv_y==0 ? 1 : 0;
    zeroMotionAbove = !mb_b.available ? 1 : b_ref_idx==0 && dec_picture->mv[LIST_0][mb_b.pos_y][mb_b.pos_x][0]==0 && b_mv_y==0 ? 1 : 0;

    currMB->cbp = 0;
    reset_coeffs();

    img_block_y   = img->block_y;
  
    if (zeroMotionAbove || zeroMotionLeft)
    {
      for(i=0;i<BLOCK_SIZE;i++)
        for(j=0;j<BLOCK_SIZE;j++)
          for (k=0;k<2;k++)
            dec_picture->mv[LIST_0][img->block_y+j][img->block_x+i][k] = 0;
    }
    else
    {
      SetMotionVectorPredictor (img, pmv, pmv+1, 0, LIST_0, dec_picture->ref_idx, dec_picture->mv, 0, 0, 16, 16);
      
      for(i=0;i<BLOCK_SIZE;i++)
        for(j=0;j<BLOCK_SIZE;j++)
          for (k=0;k<2;k++)
          {
            dec_picture->mv[LIST_0][img_block_y+j][img->block_x+i][k] = pmv[k];
          }
    }

    for(i=0;i<BLOCK_SIZE;i++)
      for(j=0;j<BLOCK_SIZE;j++)
      {
        dec_picture->ref_idx[LIST_0][img_block_y+j][img->block_x+i] = 0;
        dec_picture->ref_pic_id[LIST_0][img_block_y+j][img->block_x+i] = 
          dec_picture->ref_pic_num[img->current_slice_nr][LIST_0 + list_offset][(short)dec_picture->ref_idx[LIST_0][img_block_y+j][img->block_x+i]];
      }

    return DECODE_MB;
  }
  if(currMB->mb_type!=IPCM)
  {
    
    // intra prediction modes for a macroblock 4x4 **********************************************
    read_ipred_modes(img,inp);
    
    // read inter frame vector data *********************************************************
    if (IS_INTERMV (currMB) && (!IS_P8x8(currMB)))
    {
      readMotionInfoFromNAL (img, inp);
    }
    // read CBP and Coeffs  ***************************************************************
    readCBPandCoeffsFromNAL (img,inp);
  }
  else
  {
    //read pcm_alignment_zero_bit and pcm_byte[i] 
    
    // here dP is assigned with the same dP as SE_MBTYPE, because IPCM syntax is in the 
    // same category as MBTYPE
    dP = &(currSlice->partArr[partMap[SE_MBTYPE]]);
    readIPCMcoeffsFromNAL(img,inp,dP);
  }
  return DECODE_MB;
}



/*!
 ************************************************************************
 * \brief
 *    Initialize decoding engine after decoding an IPCM macroblock
 *    (for IPCM CABAC  28/11/2003)
 *
 * \author
 *    Dong Wang <Dong.Wang@bristol.ac.uk>  
 ************************************************************************
 */
void init_decoding_engine_IPCM(struct img_par *img)
{
  Slice *currSlice = img->currentSlice;
  Bitstream *currStream;
  int ByteStartPosition;
  int PartitionNumber;
  int i;
  
  if(currSlice->dp_mode==PAR_DP_1)
    PartitionNumber=1;
  else if(currSlice->dp_mode==PAR_DP_3)
    PartitionNumber=3;
  else
  {
    printf("Partition Mode is not supported\n");
    exit(1);
  }
  
  for(i=0;i<PartitionNumber;i++)
  {
    currStream = currSlice->partArr[i].bitstream;
    ByteStartPosition = currStream->read_len;
    
    
    arideco_start_decoding (&currSlice->partArr[i].de_cabac, currStream->streamBuffer, ByteStartPosition, &currStream->read_len, img->type);
  }
}




/*!
 ************************************************************************
 * \brief
 *    Read IPCM pcm_alignment_zero_bit and pcm_byte[i] from stream to img->cof
 *    (for IPCM CABAC and IPCM CAVLC)
 *
 * \author
 *    Dong Wang <Dong.Wang@bristol.ac.uk>
 ************************************************************************
 */

void readIPCMcoeffsFromNAL(struct img_par *img, struct inp_par *inp, struct datapartition *dP)
{
  SyntaxElement currSE;
  int i,j;
  
  //For CABAC, we don't need to read bits to let stream byte aligned
  //  because we have variable for integer bytes position
  if(active_pps->entropy_coding_mode_flag  == CABAC)
  {
    //read luma and chroma IPCM coefficients
    currSE.len=8;
    
    for(i=0;i<MB_BLOCK_SIZE;i++)
    {
      for(j=0;j<MB_BLOCK_SIZE;j++)
      {
        readIPCMBytes_CABAC(&currSE, dP->bitstream);
        img->cof[i/4][j/4][i%4][j%4]=currSE.value1;
      }
    } 
    if (dec_picture->chroma_format_idc != YUV400)
    {
      TRACE_STRING("pcm_byte chroma");
      for(i=0;i<img->mb_cr_size_y;i++)
      {
        for(j=0;j<img->mb_cr_size_x;j++)
        {
          readIPCMBytes_CABAC(&currSE, dP->bitstream);
          img->cof[i/4][j/4+4][i%4][j%4]=currSE.value1;
        }
      } 
      for(i=0;i<img->mb_cr_size_y;i++)
      {
        for(j=0;j<img->mb_cr_size_x;j++)
        {
          readIPCMBytes_CABAC(&currSE, dP->bitstream);
          img->cof[i/4+2][j/4+4][i%4][j%4]=currSE.value1;
        }
      } 
    }
    //If the decoded MB is IPCM MB, decoding engine is initialized
    
    // here the decoding engine is directly initialized without checking End of Slice
    // The reason is that, whether current MB is the last MB in slice or not, there is
    // at least one 'end of slice' syntax after this MB. So when fetching bytes in this 
    // initialisation process, we can guarantee there is bits available in bitstream. 
    
    init_decoding_engine_IPCM(img);
  }
  else
  { 
    //read bits to let stream byte aligned
    
    if((dP->bitstream->frame_bitoffset)%8!=0)
    {
      TRACE_STRING("pcm_alignment_zero_bit");
      currSE.len=8-(dP->bitstream->frame_bitoffset)%8;
      readSyntaxElement_FLC(&currSE, dP->bitstream);
    }
    
    //read luma and chroma IPCM coefficients
    currSE.len=img->bitdepth_luma;
    TRACE_STRING("pcm_byte luma");
    
    for(i=0;i<MB_BLOCK_SIZE;i++)
    {
      for(j=0;j<MB_BLOCK_SIZE;j++)
      {
        readSyntaxElement_FLC(&currSE, dP->bitstream);
        img->cof[i/4][j/4][i%4][j%4]=currSE.value1;
      }
    } 
    currSE.len=img->bitdepth_chroma;
    if (dec_picture->chroma_format_idc != YUV400)
    {
      TRACE_STRING("pcm_byte chroma");
      for(i=0;i<img->mb_cr_size_y;i++)
      {
        for(j=0;j<img->mb_cr_size_x;j++)
        {
          readSyntaxElement_FLC(&currSE, dP->bitstream);
          img->cof[i/4][j/4+4][i%4][j%4]=currSE.value1;
        }
      } 
      for(i=0;i<img->mb_cr_size_y;i++)
      {
        for(j=0;j<img->mb_cr_size_x;j++)
        {
          readSyntaxElement_FLC(&currSE, dP->bitstream);
          img->cof[i/4+2][j/4+4][i%4][j%4]=currSE.value1;
        }
      }
    }
  }
}



void read_ipred_modes(struct img_par *img,struct inp_par *inp)
{
  int b8,i,j,bi,bj,bx,by,dec;
  SyntaxElement currSE;
  Slice *currSlice;
  DataPartition *dP;
  int *partMap;
  Macroblock *currMB;
  int ts, ls;
  int mostProbableIntraPredMode;
  int upIntraPredMode;
  int leftIntraPredMode;
  int IntraChromaPredModeFlag;
  int bs_x, bs_y;
  int ii,jj;
  
  PixelPos left_block;
  PixelPos top_block;
  
  currMB = &img->mb_data[img->current_mb_nr];

  IntraChromaPredModeFlag = IS_INTRA(currMB);

  currSlice = img->currentSlice;
  partMap = assignSE2partition[currSlice->dp_mode];

  currSE.type = SE_INTRAPREDMODE;

  TRACE_STRING("intra4x4_pred_mode");
  dP = &(currSlice->partArr[partMap[currSE.type]]);

  if (!(active_pps->entropy_coding_mode_flag == UVLC || dP->bitstream->ei_flag)) 
    currSE.reading = readIntraPredMode_CABAC;

  for(b8=0;b8<4;b8++)  //loop 8x8 blocks
  {
    if((currMB->b8mode[b8]==IBLOCK )||(currMB->b8mode[b8]==I8MB))
    {
      bs_x = bs_y = (currMB->b8mode[b8] == I8MB)?8:4;
      
      IntraChromaPredModeFlag = 1;

      ii=(bs_x>>2);
      jj=(bs_y>>2);
      
      for(j=0;j<2;j+=jj)  //loop subblocks
        for(i=0;i<2;i+=ii)
        {
          //get from stream
          if (active_pps->entropy_coding_mode_flag == UVLC || dP->bitstream->ei_flag)
            readSyntaxElement_Intra4x4PredictionMode(&currSE,img,inp,dP);
          else 
          {
            currSE.context=(b8<<2)+(j<<1)+i;
            dP->readSyntaxElement(&currSE,img,inp,dP);
          }

          bx = ((b8&1)<<1) + i;
          by = (b8&2)      + j;

          getLuma4x4Neighbour(img->current_mb_nr, bx, by, -1,  0, &left_block);
          getLuma4x4Neighbour(img->current_mb_nr, bx, by,  0, -1, &top_block);
          
          //get from array and decode
          bi = img->block_x + bx;
          bj = img->block_y + by;

          if (active_pps->constrained_intra_pred_flag)
          {
            left_block.available = left_block.available ? img->intra_block[left_block.mb_addr] : 0;
            top_block.available  = top_block.available  ? img->intra_block[top_block.mb_addr]  : 0;
          }

          // !! KS: not sure if the follwing is still correct...
          ts=ls=0;   // Check to see if the neighboring block is SI
          if (IS_OLDINTRA(currMB) && img->type == SI_SLICE)           // need support for MBINTLC1
          {
            if (left_block.available)
              if (img->siblock [left_block.pos_x][left_block.pos_y])
                ls=1;

            if (top_block.available)
              if (img->siblock [top_block.pos_x][top_block.pos_y])
                ts=1;
          }

          upIntraPredMode            = (top_block.available  &&(ts == 0)) ? img->ipredmode[top_block.pos_x ][top_block.pos_y ] : -1;
          leftIntraPredMode          = (left_block.available &&(ls == 0)) ? img->ipredmode[left_block.pos_x][left_block.pos_y] : -1;

          mostProbableIntraPredMode  = (upIntraPredMode < 0 || leftIntraPredMode < 0) ? DC_PRED : upIntraPredMode < leftIntraPredMode ? upIntraPredMode : leftIntraPredMode;

          dec = (currSE.value1 == -1) ? mostProbableIntraPredMode : currSE.value1 + (currSE.value1 >= mostProbableIntraPredMode);

          //set
          for(jj=0;jj<(bs_y>>2);jj++)   //loop 4x4s in the subblock for 8x8 prediction setting
            for(ii=0;ii<(bs_x>>2);ii++)
              img->ipredmode[bi+ii][bj+jj]=dec;
        }
    }
  }

  if (IntraChromaPredModeFlag && dec_picture->chroma_format_idc != YUV400)
  {
    currSE.type = SE_INTRAPREDMODE;
    TRACE_STRING("intra_chroma_pred_mode");
    dP = &(currSlice->partArr[partMap[currSE.type]]);

    if (active_pps->entropy_coding_mode_flag == UVLC || dP->bitstream->ei_flag) currSE.mapping = linfo_ue;
    else                                                    currSE.reading = readCIPredMode_CABAC;

    dP->readSyntaxElement(&currSE,img,inp,dP);
    currMB->c_ipred_mode = currSE.value1;

    if (currMB->c_ipred_mode < DC_PRED_8 || currMB->c_ipred_mode > PLANE_8)
    {
      error("illegal chroma intra pred mode!\n", 600);
    }
  }
}

/*!
 ************************************************************************
 * \brief
 *    Set motion vector predictor
 ************************************************************************
 */
static void SetMotionVectorPredictor (struct img_par  *img,
                                      short           *pmv_x,
                                      short           *pmv_y,
                                      char            ref_frame,
                                      byte            list,
                                      char            ***refPic,
                                      short           ****tmp_mv,
                                      int             block_x,
                                      int             block_y,
                                      int             blockshape_x,
                                      int             blockshape_y)
{
  int mb_x                 = BLOCK_SIZE*block_x;
  int mb_y                 = BLOCK_SIZE*block_y;
  int mb_nr                = img->current_mb_nr;

  int mv_a, mv_b, mv_c, pred_vec=0;
  int mvPredType, rFrameL, rFrameU, rFrameUR;
  int hv;


  PixelPos block_a, block_b, block_c, block_d;

  getLuma4x4Neighbour(mb_nr, block_x, block_y,           -1,  0, &block_a);
  getLuma4x4Neighbour(mb_nr, block_x, block_y,            0, -1, &block_b);
  getLuma4x4Neighbour(mb_nr, block_x, block_y, blockshape_x, -1, &block_c);
  getLuma4x4Neighbour(mb_nr, block_x, block_y,           -1, -1, &block_d);

  if (mb_y > 0)
  {
    if (mb_x < 8)  // first column of 8x8 blocks
    {
      if (mb_y==8)
      {
        if (blockshape_x == 16)      block_c.available  = 0;
      }
      else
      {
        if (mb_x+blockshape_x == 8)  block_c.available  = 0;
      }
    }
    else
    {
      if (mb_x+blockshape_x == 16)   block_c.available  = 0;
    }
  }

  if (!block_c.available)
  {
    block_c=block_d;
  }

  mvPredType = MVPRED_MEDIAN;

  if (!img->MbaffFrameFlag)
  {
    rFrameL    = block_a.available    ? refPic[list][block_a.pos_y][block_a.pos_x] : -1;
    rFrameU    = block_b.available    ? refPic[list][block_b.pos_y][block_b.pos_x] : -1;
    rFrameUR   = block_c.available    ? refPic[list][block_c.pos_y][block_c.pos_x] : -1;
  }
  else
  {
    if (img->mb_data[img->current_mb_nr].mb_field)
    {
      rFrameL    = block_a.available    ? 
        img->mb_data[block_a.mb_addr].mb_field ? 
        refPic[list][block_a.pos_y][block_a.pos_x]:
        refPic[list][block_a.pos_y][block_a.pos_x] * 2: 
        -1;
      rFrameU    = block_b.available    ? 
        img->mb_data[block_b.mb_addr].mb_field ? 
        refPic[list][block_b.pos_y][block_b.pos_x]:
        refPic[list][block_b.pos_y][block_b.pos_x] * 2: 
        -1;
      rFrameUR    = block_c.available    ? 
        img->mb_data[block_c.mb_addr].mb_field ? 
        refPic[list][block_c.pos_y][block_c.pos_x]:
        refPic[list][block_c.pos_y][block_c.pos_x] * 2: 
        -1;
    }
    else
    {
      rFrameL    = block_a.available    ? 
        img->mb_data[block_a.mb_addr].mb_field ? 
        refPic[list][block_a.pos_y][block_a.pos_x] >>1:
        refPic[list][block_a.pos_y][block_a.pos_x] : 
        -1;
      rFrameU    = block_b.available    ? 
        img->mb_data[block_b.mb_addr].mb_field ? 
        refPic[list][block_b.pos_y][block_b.pos_x] >>1:
        refPic[list][block_b.pos_y][block_b.pos_x] : 
        -1;
      rFrameUR    = block_c.available    ? 
        img->mb_data[block_c.mb_addr].mb_field ? 
        refPic[list][block_c.pos_y][block_c.pos_x] >>1:
        refPic[list][block_c.pos_y][block_c.pos_x] : 
        -1;
    }
  }


  /* Prediction if only one of the neighbors uses the reference frame
   * we are checking
   */
  if(rFrameL == ref_frame && rFrameU != ref_frame && rFrameUR != ref_frame)       mvPredType = MVPRED_L;
  else if(rFrameL != ref_frame && rFrameU == ref_frame && rFrameUR != ref_frame)  mvPredType = MVPRED_U;
  else if(rFrameL != ref_frame && rFrameU != ref_frame && rFrameUR == ref_frame)  mvPredType = MVPRED_UR;
  // Directional predictions 
  if(blockshape_x == 8 && blockshape_y == 16)
  {
    if(mb_x == 0)
    {
      if(rFrameL == ref_frame)
        mvPredType = MVPRED_L;
    }
    else
    {
      if( rFrameUR == ref_frame)
        mvPredType = MVPRED_UR;
    }
  }
  else if(blockshape_x == 16 && blockshape_y == 8)
  {
    if(mb_y == 0)
    {
      if(rFrameU == ref_frame)
        mvPredType = MVPRED_U;
    }
    else
    {
      if(rFrameL == ref_frame)
        mvPredType = MVPRED_L;
    }
  }

  for (hv=0; hv < 2; hv++)
  {
    if (!img->MbaffFrameFlag || hv==0)
    {
      mv_a = block_a.available  ? tmp_mv[list][block_a.pos_y][block_a.pos_x][hv] : 0;
      mv_b = block_b.available  ? tmp_mv[list][block_b.pos_y][block_b.pos_x][hv] : 0;
      mv_c = block_c.available  ? tmp_mv[list][block_c.pos_y][block_c.pos_x][hv] : 0;
    }
    else
    {
      if (img->mb_data[img->current_mb_nr].mb_field)
      {
        mv_a = block_a.available  ? img->mb_data[block_a.mb_addr].mb_field?
          tmp_mv[list][block_a.pos_y][block_a.pos_x][hv]:
          tmp_mv[list][block_a.pos_y][block_a.pos_x][hv] / 2: 
          0;
        mv_b = block_b.available  ? img->mb_data[block_b.mb_addr].mb_field?
          tmp_mv[list][block_b.pos_y][block_b.pos_x][hv]:
          tmp_mv[list][block_b.pos_y][block_b.pos_x][hv] / 2: 
          0;
        mv_c = block_c.available  ? img->mb_data[block_c.mb_addr].mb_field?
          tmp_mv[list][block_c.pos_y][block_c.pos_x][hv]:
          tmp_mv[list][block_c.pos_y][block_c.pos_x][hv] / 2: 
          0;
      }
      else
      {
        mv_a = block_a.available  ? img->mb_data[block_a.mb_addr].mb_field?
          tmp_mv[list][block_a.pos_y][block_a.pos_x][hv] * 2:
          tmp_mv[list][block_a.pos_y][block_a.pos_x][hv]: 
          0;
        mv_b = block_b.available  ? img->mb_data[block_b.mb_addr].mb_field?
          tmp_mv[list][block_b.pos_y][block_b.pos_x][hv] * 2:
          tmp_mv[list][block_b.pos_y][block_b.pos_x][hv]: 
          0;
        mv_c = block_c.available  ? img->mb_data[block_c.mb_addr].mb_field?
          tmp_mv[list][block_c.pos_y][block_c.pos_x][hv] * 2:
          tmp_mv[list][block_c.pos_y][block_c.pos_x][hv]: 
          0;
      }
    }

    switch (mvPredType)
    {
    case MVPRED_MEDIAN:
      if(!(block_b.available || block_c.available))
        pred_vec = mv_a;
      else
        pred_vec = mv_a+mv_b+mv_c-min(mv_a,min(mv_b,mv_c))-max(mv_a,max(mv_b,mv_c));
      break;
    case MVPRED_L:
      pred_vec = mv_a;
      break;
    case MVPRED_U:
      pred_vec = mv_b;
      break;
    case MVPRED_UR:
      pred_vec = mv_c;
      break;
    default:
      break;
    }

    if (hv==0)  *pmv_x = pred_vec;
    else        *pmv_y = pred_vec;

  }
}


/*!
 ************************************************************************
 * \brief
 *    Set context for reference frames
 ************************************************************************
 */
int
BType2CtxRef (int btype)
{
  if (btype<4)  return 0;
  else          return 1;
}

/*!
 ************************************************************************
 * \brief
 *    Read motion info
 ************************************************************************
 */
void readMotionInfoFromNAL (struct img_par *img, struct inp_par *inp)
{
  int i,j,k;
  int step_h,step_v;
  int curr_mvd;
  Macroblock *currMB  = &img->mb_data[img->current_mb_nr];
  SyntaxElement currSE;
  Slice *currSlice    = img->currentSlice;
  DataPartition *dP;
  int *partMap        = assignSE2partition[currSlice->dp_mode];
  int bframe          = (img->type==B_SLICE);
  int partmode        = (IS_P8x8(currMB)?4:currMB->mb_type);
  int step_h0         = BLOCK_STEP [partmode][0];
  int step_v0         = BLOCK_STEP [partmode][1];

  int mv_mode, i0, j0;
  char refframe;
  short pmv[2];
  int j4, i4, ii,jj;
  int vec;

  int mv_scale = 0;

  int flag_mode;

  int list_offset = ((img->MbaffFrameFlag)&&(currMB->mb_field))? img->current_mb_nr%2 ? 4 : 2 : 0;

  byte  **    moving_block;
  short ****  co_located_mv;
  char  ***   co_located_ref_idx;
  int64 ***   co_located_ref_id;

  if ((img->MbaffFrameFlag)&&(currMB->mb_field))
  {
    if(img->current_mb_nr%2)
    {
      moving_block = Co_located->bottom_moving_block;
      co_located_mv = Co_located->bottom_mv;
      co_located_ref_idx = Co_located->bottom_ref_idx;
      co_located_ref_id = Co_located->bottom_ref_pic_id;
    }
    else
    {
      moving_block = Co_located->top_moving_block;
      co_located_mv = Co_located->top_mv;
      co_located_ref_idx = Co_located->top_ref_idx;
      co_located_ref_id = Co_located->top_ref_pic_id;
    }
  }
  else
  {
    moving_block = Co_located->moving_block;
    co_located_mv = Co_located->mv;
    co_located_ref_idx = Co_located->ref_idx;
    co_located_ref_id = Co_located->ref_pic_id;
  }

  if (bframe && IS_P8x8 (currMB))
  {
    if (img->direct_spatial_mv_pred_flag)
    {
      int imgblock_y= ((img->MbaffFrameFlag)&&(currMB->mb_field))? (img->current_mb_nr%2) ? (img->block_y-4)/2:img->block_y/2: img->block_y;
      int fw_rFrameL, fw_rFrameU, fw_rFrameUL, fw_rFrameUR;
      int bw_rFrameL, bw_rFrameU, bw_rFrameUL, bw_rFrameUR;
      
      PixelPos mb_left, mb_up, mb_upleft, mb_upright;
      
      char  fw_rFrame,bw_rFrame;
      short pmvfw[2]={0,0},
            pmvbw[2]={0,0};
      
      
      getLuma4x4Neighbour(img->current_mb_nr, 0, 0, -1,  0, &mb_left);
      getLuma4x4Neighbour(img->current_mb_nr, 0, 0,  0, -1, &mb_up);
      getLuma4x4Neighbour(img->current_mb_nr, 0, 0, 16, -1, &mb_upright);
      getLuma4x4Neighbour(img->current_mb_nr, 0, 0, -1, -1, &mb_upleft);

      if (!img->MbaffFrameFlag)
      {
        fw_rFrameL = mb_left.available ? dec_picture->ref_idx[LIST_0][mb_left.pos_y][mb_left.pos_x] : -1;
        fw_rFrameU = mb_up.available ? dec_picture->ref_idx[LIST_0][mb_up.pos_y][mb_up.pos_x] : -1;
        fw_rFrameUL = mb_upleft.available ? dec_picture->ref_idx[LIST_0][mb_upleft.pos_y][mb_upleft.pos_x] : -1;
        fw_rFrameUR = mb_upright.available ? dec_picture->ref_idx[LIST_0][mb_upright.pos_y][mb_upright.pos_x] : fw_rFrameUL;      
        
        bw_rFrameL = mb_left.available ? dec_picture->ref_idx[LIST_1][mb_left.pos_y][mb_left.pos_x] : -1;
        bw_rFrameU = mb_up.available ? dec_picture->ref_idx[LIST_1][mb_up.pos_y][mb_up.pos_x] : -1;
        bw_rFrameUL = mb_upleft.available ? dec_picture->ref_idx[LIST_1][mb_upleft.pos_y][mb_upleft.pos_x] : -1;
        bw_rFrameUR = mb_upright.available ? dec_picture->ref_idx[LIST_1][mb_upright.pos_y][mb_upright.pos_x] : bw_rFrameUL;      
      }
      else
      {
        if (img->mb_data[img->current_mb_nr].mb_field)
        {
          fw_rFrameL = mb_left.available ? 
            img->mb_data[mb_left.mb_addr].mb_field  || dec_picture->ref_idx[LIST_0][mb_left.pos_y][mb_left.pos_x] < 0? 
            dec_picture->ref_idx[LIST_0][mb_left.pos_y][mb_left.pos_x] : 
          dec_picture->ref_idx[LIST_0][mb_left.pos_y][mb_left.pos_x] * 2: -1;
          fw_rFrameU = mb_up.available ? 
            img->mb_data[mb_up.mb_addr].mb_field || dec_picture->ref_idx[LIST_0][mb_up.pos_y][mb_up.pos_x] < 0? 
            dec_picture->ref_idx[LIST_0][mb_up.pos_y][mb_up.pos_x] : 
          dec_picture->ref_idx[LIST_0][mb_up.pos_y][mb_up.pos_x] * 2: -1;

          fw_rFrameUL = mb_upleft.available ? 
            img->mb_data[mb_upleft.mb_addr].mb_field || dec_picture->ref_idx[LIST_0][mb_upleft.pos_y][mb_upleft.pos_x] < 0?
            dec_picture->ref_idx[LIST_0][mb_upleft.pos_y][mb_upleft.pos_x] : 
          dec_picture->ref_idx[LIST_0][mb_upleft.pos_y][mb_upleft.pos_x] *2: -1;      

          fw_rFrameUR = mb_upright.available ? 
            img->mb_data[mb_upright.mb_addr].mb_field || dec_picture->ref_idx[LIST_0][mb_upright.pos_y][mb_upright.pos_x] < 0 ?
            dec_picture->ref_idx[LIST_0][mb_upright.pos_y][mb_upright.pos_x] : 
          dec_picture->ref_idx[LIST_0][mb_upright.pos_y][mb_upright.pos_x] * 2: fw_rFrameUL;      
          
          bw_rFrameL = mb_left.available ? 
            img->mb_data[mb_left.mb_addr].mb_field || dec_picture->ref_idx[LIST_1][mb_left.pos_y][mb_left.pos_x]  < 0 ?
            dec_picture->ref_idx[LIST_1][mb_left.pos_y][mb_left.pos_x] : 
          dec_picture->ref_idx[LIST_1][mb_left.pos_y][mb_left.pos_x] * 2: -1;

          bw_rFrameU = mb_up.available ? 
            img->mb_data[mb_up.mb_addr].mb_field || dec_picture->ref_idx[LIST_1][mb_up.pos_y][mb_up.pos_x]  < 0 ?
            dec_picture->ref_idx[LIST_1][mb_up.pos_y][mb_up.pos_x] : 
          dec_picture->ref_idx[LIST_1][mb_up.pos_y][mb_up.pos_x] * 2: -1;

          bw_rFrameUL = mb_upleft.available ? 
            img->mb_data[mb_upleft.mb_addr].mb_field || dec_picture->ref_idx[LIST_1][mb_upleft.pos_y][mb_upleft.pos_x]  < 0 ?
            dec_picture->ref_idx[LIST_1][mb_upleft.pos_y][mb_upleft.pos_x] : 
          dec_picture->ref_idx[LIST_1][mb_upleft.pos_y][mb_upleft.pos_x] *2: -1;      

          bw_rFrameUR = mb_upright.available ? 
            img->mb_data[mb_upright.mb_addr].mb_field || dec_picture->ref_idx[LIST_1][mb_upright.pos_y][mb_upright.pos_x]  < 0 ?
            dec_picture->ref_idx[LIST_1][mb_upright.pos_y][mb_upright.pos_x] : 
          dec_picture->ref_idx[LIST_1][mb_upright.pos_y][mb_upright.pos_x] * 2: bw_rFrameUL;      
          
        }
        else
        {
          fw_rFrameL = mb_left.available ? 
            img->mb_data[mb_left.mb_addr].mb_field || dec_picture->ref_idx[LIST_0][mb_left.pos_y][mb_left.pos_x]  < 0 ?
            dec_picture->ref_idx[LIST_0][mb_left.pos_y][mb_left.pos_x] >> 1 : 
          dec_picture->ref_idx[LIST_0][mb_left.pos_y][mb_left.pos_x]: -1;

          fw_rFrameU = mb_up.available ? 
            img->mb_data[mb_up.mb_addr].mb_field || dec_picture->ref_idx[LIST_0][mb_up.pos_y][mb_up.pos_x]  < 0 ?
            dec_picture->ref_idx[LIST_0][mb_up.pos_y][mb_up.pos_x] >> 1 :  
          dec_picture->ref_idx[LIST_0][mb_up.pos_y][mb_up.pos_x] : -1;

          fw_rFrameUL = mb_upleft.available ? 
            img->mb_data[mb_upleft.mb_addr].mb_field || dec_picture->ref_idx[LIST_0][mb_upleft.pos_y][mb_upleft.pos_x] < 0 ?
            dec_picture->ref_idx[LIST_0][mb_upleft.pos_y][mb_upleft.pos_x]>> 1 : 
          dec_picture->ref_idx[LIST_0][mb_upleft.pos_y][mb_upleft.pos_x] : -1;      

          fw_rFrameUR = mb_upright.available ? 
            img->mb_data[mb_upright.mb_addr].mb_field || dec_picture->ref_idx[LIST_0][mb_upright.pos_y][mb_upright.pos_x]  < 0 ?
            dec_picture->ref_idx[LIST_0][mb_upright.pos_y][mb_upright.pos_x] >> 1 :  
          dec_picture->ref_idx[LIST_0][mb_upright.pos_y][mb_upright.pos_x] : fw_rFrameUL;      
          
          bw_rFrameL = mb_left.available ? 
            img->mb_data[mb_left.mb_addr].mb_field || dec_picture->ref_idx[LIST_1][mb_left.pos_y][mb_left.pos_x] < 0 ?
            dec_picture->ref_idx[LIST_1][mb_left.pos_y][mb_left.pos_x] >> 1 :  
          dec_picture->ref_idx[LIST_1][mb_left.pos_y][mb_left.pos_x] : -1;
          bw_rFrameU = mb_up.available ? 
            img->mb_data[mb_up.mb_addr].mb_field || dec_picture->ref_idx[LIST_1][mb_up.pos_y][mb_up.pos_x] < 0 ?
            dec_picture->ref_idx[LIST_1][mb_up.pos_y][mb_up.pos_x] >> 1 : 
          dec_picture->ref_idx[LIST_1][mb_up.pos_y][mb_up.pos_x] : -1;

          bw_rFrameUL = mb_upleft.available ? 
            img->mb_data[mb_upleft.mb_addr].mb_field || dec_picture->ref_idx[LIST_1][mb_upleft.pos_y][mb_upleft.pos_x]  < 0 ?
            dec_picture->ref_idx[LIST_1][mb_upleft.pos_y][mb_upleft.pos_x] >> 1 : 
          dec_picture->ref_idx[LIST_1][mb_upleft.pos_y][mb_upleft.pos_x] : -1;      

          bw_rFrameUR = mb_upright.available ? 
            img->mb_data[mb_upright.mb_addr].mb_field || dec_picture->ref_idx[LIST_1][mb_upright.pos_y][mb_upright.pos_x] < 0 ?
            dec_picture->ref_idx[LIST_1][mb_upright.pos_y][mb_upright.pos_x] >> 1: 
          dec_picture->ref_idx[LIST_1][mb_upright.pos_y][mb_upright.pos_x] : bw_rFrameUL;      
        }
      }
      
    fw_rFrame = (fw_rFrameL >= 0 && fw_rFrameU >= 0) ? min(fw_rFrameL,fw_rFrameU): max(fw_rFrameL,fw_rFrameU);
    fw_rFrame = (fw_rFrame >= 0 && fw_rFrameUR >= 0) ? min(fw_rFrame,fw_rFrameUR): max(fw_rFrame,fw_rFrameUR);
      
    bw_rFrame = (bw_rFrameL >= 0 && bw_rFrameU >= 0) ? min(bw_rFrameL,bw_rFrameU): max(bw_rFrameL,bw_rFrameU);
    bw_rFrame = (bw_rFrame >= 0 && bw_rFrameUR >= 0) ? min(bw_rFrame,bw_rFrameUR): max(bw_rFrame,bw_rFrameUR);
      
      
    if (fw_rFrame >=0)
        SetMotionVectorPredictor (img, pmvfw, pmvfw+1, fw_rFrame, LIST_0, dec_picture->ref_idx, dec_picture->mv, 0, 0, 16, 16);
      
    if (bw_rFrame >=0)
        SetMotionVectorPredictor (img, pmvbw, pmvbw+1, bw_rFrame, LIST_1, dec_picture->ref_idx, dec_picture->mv, 0, 0, 16, 16);
      
      
      for (i=0;i<4;i++)
      {
        if (currMB->b8mode[i] == 0)
          for(j=2*(i/2);j<2*(i/2)+2;j++)
            for(k=2*(i%2);k<2*(i%2)+2;k++)
            {
              int j6 = imgblock_y+j;
              j4 = img->block_y+j;
              i4 = img->block_x+k;
                  
              
              if (fw_rFrame >= 0)
                {
                
                if  (!fw_rFrame  && ((!moving_block[j6][i4]) && (!listX[1+list_offset][0]->is_long_term)))
                  {                    
                  dec_picture->mv  [LIST_0][j4][i4][0] = 0;
                  dec_picture->mv  [LIST_0][j4][i4][1] = 0;
                  dec_picture->ref_idx[LIST_0][j4][i4] = 0;                    
                  }
                  else
                  {
                  
                  dec_picture->mv  [LIST_0][j4][i4][0] = pmvfw[0];
                  dec_picture->mv  [LIST_0][j4][i4][1] = pmvfw[1];
                  dec_picture->ref_idx[LIST_0][j4][i4] = fw_rFrame;
                  }
                }
                else
                {
                dec_picture->mv  [LIST_0][j4][i4][0] = 0;
                dec_picture->mv  [LIST_0][j4][i4][1] = 0;
                dec_picture->ref_idx[LIST_0][j4][i4] = -1;
                }
              if (bw_rFrame >= 0)
                {
                if  (bw_rFrame==0 && ((!moving_block[j6][i4])&& (!listX[1+list_offset][0]->is_long_term)))
                  {
                  dec_picture->mv  [LIST_1][j4][i4][0] = 0;
                  dec_picture->mv  [LIST_1][j4][i4][1] = 0;
                  dec_picture->ref_idx[LIST_1][j4][i4] = 0;
                  }
                  else
                  {
                  dec_picture->mv  [LIST_1][j4][i4][0] = pmvbw[0];
                  dec_picture->mv  [LIST_1][j4][i4][1] = pmvbw[1];
                  dec_picture->ref_idx[LIST_1][j4][i4] = bw_rFrame;
                  }
                }
                else
                {
                dec_picture->mv  [LIST_1][j4][i4][0] = 0;
                dec_picture->mv  [LIST_1][j4][i4][1] = 0;
                dec_picture->ref_idx[LIST_1][j4][i4] = -1;                               
                }

              if (fw_rFrame <0 && bw_rFrame <0)
                {
                dec_picture->ref_idx[LIST_0][j4][i4] = 0;
                dec_picture->ref_idx[LIST_1][j4][i4] = 0;                  
              }
            }
        }
    }
    else
    {
      for (i=0;i<4;i++)
      {
        if (currMB->b8mode[i] == 0)
        {
          for(j=2*(i/2);j<2*(i/2)+2;j++)
          {
            for(k=2*(i%2);k<2*(i%2)+2;k++)
            {
              
              int list_offset = ((img->MbaffFrameFlag)&&(currMB->mb_field))? img->current_mb_nr%2 ? 4 : 2 : 0;
              int imgblock_y= ((img->MbaffFrameFlag)&&(currMB->mb_field))? (img->current_mb_nr%2) ? (img->block_y-4)/2 : img->block_y/2 : img->block_y;
              int refList = co_located_ref_idx[LIST_0 ][imgblock_y+j][img->block_x+k]== -1 ? LIST_1 : LIST_0;
              int ref_idx = co_located_ref_idx[refList][imgblock_y + j][img->block_x + k];
              int mapped_idx=-1, iref;                             
 
              if (ref_idx == -1)
              {
                dec_picture->ref_idx [LIST_0][img->block_y + j][img->block_x + k] = 0;
                dec_picture->ref_idx [LIST_1][img->block_y + j][img->block_x + k] = 0;                
              }
              else
              {
                for (iref=0;iref<min(img->num_ref_idx_l0_active,listXsize[LIST_0 + list_offset]);iref++)
                {
#if 1
                int curr_mb_field = ((img->MbaffFrameFlag)&&(currMB->mb_field));

                  if(img->structure==0 && curr_mb_field==0)
                  {
                    // If the current MB is a frame MB and the colocated is from a field picture, 
                    // then the co_located_ref_id may have been generated from the wrong value of 
                    // frame_poc if it references it's complementary field, so test both POC values
                    if(listX[0][iref]->top_poc*2 == co_located_ref_id[refList][imgblock_y + j][img->block_x + k] 
                      || listX[0][iref]->bottom_poc*2 == co_located_ref_id[refList][imgblock_y + j][img->block_x + k])
                    {
                      mapped_idx=iref;
                      break;
                    }
                    else //! invalid index. Default to zero even though this case should not happen
                      mapped_idx=INVALIDINDEX;
                    continue;
                  }    
#endif                                        
                  if (dec_picture->ref_pic_num[img->current_slice_nr][LIST_0 + list_offset][iref]==co_located_ref_id[refList][imgblock_y + j][img->block_x + k])
                  {
                    mapped_idx=iref;
                    break;
                  }
                  else //! invalid index. Default to zero even though this case should not happen
                    mapped_idx=INVALIDINDEX;
                }
                if (INVALIDINDEX == mapped_idx)
                {
                  error("temporal direct error\ncolocated block has ref that is unavailable",-1111);
                }
                dec_picture->ref_idx [LIST_0][img->block_y + j][img->block_x + k] = mapped_idx;
                dec_picture->ref_idx [LIST_1][img->block_y + j][img->block_x + k] = 0;                
              }
            }
          }
        }
      }
    }
  } 

  //  If multiple ref. frames, read reference frame for the MB *********************************
  if(img->num_ref_idx_l0_active>1) 
  {
    flag_mode = ( img->num_ref_idx_l0_active == 2 ? 1 : 0);

    currSE.type = SE_REFFRAME;
    dP = &(currSlice->partArr[partMap[SE_REFFRAME]]);

    if (active_pps->entropy_coding_mode_flag == UVLC || dP->bitstream->ei_flag)   currSE.mapping = linfo_ue;
    else                                                      currSE.reading = readRefFrame_CABAC;
    
    for (j0=0; j0<4; j0+=step_v0)
    {
      for (i0=0; i0<4; i0+=step_h0)
      {
        k=2*(j0/2)+(i0/2);
        if ((currMB->b8pdir[k]==0 || currMB->b8pdir[k]==2) && currMB->b8mode[k]!=0)
        {
          TRACE_STRING("ref_idx_l0");

          img->subblock_x = i0;
          img->subblock_y = j0;
          
          if (!IS_P8x8 (currMB) || bframe || (!bframe && !img->allrefzero))
          {
            currSE.context = BType2CtxRef (currMB->b8mode[k]);
            if( (active_pps->entropy_coding_mode_flag == UVLC || dP->bitstream->ei_flag) && flag_mode )
            {
              currSE.len = 1;
              readSyntaxElement_FLC(&currSE, dP->bitstream);
              currSE.value1 = 1 - currSE.value1;
            }
            else
            {
              currSE.value2 = LIST_0;
              dP->readSyntaxElement (&currSE,img,inp,dP);
            }
            refframe = currSE.value1;
            
          }
          else
          {
            refframe = 0;
          }
          
          /*
          if (bframe && refframe>img->buf_cycle)    // img->buf_cycle should be correct for field MBs now
          {
            set_ec_flag(SE_REFFRAME);
            refframe = 1;
          }
          */
          
          for (j=j0; j<j0+step_v0;j++)
            for (i=i0; i<i0+step_h0;i++)
            {
              dec_picture->ref_idx[LIST_0][img->block_y + j][img->block_x + i] = refframe;
            }
          
        }
      }
    }
  }
  else
  {
    for (j0=0; j0<4; j0+=step_v0)
    {
      for (i0=0; i0<4; i0+=step_h0)
      {
        k=2*(j0/2)+(i0/2);
        if ((currMB->b8pdir[k]==0 || currMB->b8pdir[k]==2) && currMB->b8mode[k]!=0)
        {
          for (j=j0; j<j0+step_v0;j++)
            for (i=i0; i<i0+step_h0;i++)
            {
              dec_picture->ref_idx[LIST_0][img->block_y + j][img->block_x + i] = 0;
            }
        }
      }
    }
  }
  
  //  If backward multiple ref. frames, read backward reference frame for the MB *********************************
  if(img->num_ref_idx_l1_active>1)
  {
    flag_mode = ( img->num_ref_idx_l1_active == 2 ? 1 : 0);

    currSE.type = SE_REFFRAME;
    dP = &(currSlice->partArr[partMap[SE_REFFRAME]]);
    if (active_pps->entropy_coding_mode_flag == UVLC || dP->bitstream->ei_flag)   currSE.mapping = linfo_ue;
    else                                                      currSE.reading = readRefFrame_CABAC;
    
    for (j0=0; j0<4; j0+=step_v0)
    {
      for (i0=0; i0<4; i0+=step_h0)
      {
        k=2*(j0/2)+(i0/2);
        if ((currMB->b8pdir[k]==1 || currMB->b8pdir[k]==2) && currMB->b8mode[k]!=0)
        {
          TRACE_STRING("ref_idx_l1");

          img->subblock_x = i0;
          img->subblock_y = j0;
          
          currSE.context = BType2CtxRef (currMB->b8mode[k]);
          if( (active_pps->entropy_coding_mode_flag == UVLC || dP->bitstream->ei_flag) && flag_mode )
          {
            currSE.len = 1;
            readSyntaxElement_FLC(&currSE, dP->bitstream);
            currSE.value1 = 1-currSE.value1;
          }
          else
          {
            currSE.value2 = LIST_1;
            dP->readSyntaxElement (&currSE,img,inp,dP);
          }
          refframe = currSE.value1;

          for (j=j0; j<j0+step_v0;j++)
          {
            for (i=i0; i<i0+step_h0;i++)
            {
              dec_picture->ref_idx[LIST_1][img->block_y + j][img->block_x + i] = refframe;
            }
          }
        }
      }
    }
  }
  else
  {
    for (j0=0; j0<4; j0+=step_v0)
    {
      for (i0=0; i0<4; i0+=step_h0)
      {
        k=2*(j0/2)+(i0/2);
        if ((currMB->b8pdir[k]==1 || currMB->b8pdir[k]==2) && currMB->b8mode[k]!=0)
        {
          for (j=j0; j<j0+step_v0;j++)
            for (i=i0; i<i0+step_h0;i++)
            {
              dec_picture->ref_idx[LIST_1][img->block_y + j][img->block_x + i] = 0;
            }
        }
      }
    }
  }

  //=====  READ FORWARD MOTION VECTORS =====
  currSE.type = SE_MVD;
  dP = &(currSlice->partArr[partMap[SE_MVD]]);

  if (active_pps->entropy_coding_mode_flag == UVLC || dP->bitstream->ei_flag) currSE.mapping = linfo_se;
  else                                                  currSE.reading = readMVD_CABAC;

  for (j0=0; j0<4; j0+=step_v0)
    for (i0=0; i0<4; i0+=step_h0)
    {
      k=2*(j0/2)+(i0/2);

      if ((currMB->b8pdir[k]==0 || currMB->b8pdir[k]==2) && (currMB->b8mode[k] !=0))//has forward vector
      {
        mv_mode  = currMB->b8mode[k];
        step_h   = BLOCK_STEP [mv_mode][0];
        step_v   = BLOCK_STEP [mv_mode][1];
        
        refframe = dec_picture->ref_idx[LIST_0][img->block_y+j0][img->block_x+i0];
        
        for (j=j0; j<j0+step_v0; j+=step_v)
        {
          for (i=i0; i<i0+step_h0; i+=step_h)
          {
            j4 = img->block_y+j;
            i4 = img->block_x+i;
            
            // first make mv-prediction
            SetMotionVectorPredictor (img, pmv, pmv+1, refframe, LIST_0, dec_picture->ref_idx, dec_picture->mv, i, j, 4*step_h, 4*step_v);

            for (k=0; k < 2; k++) 
            {
              TRACE_STRING("mvd_l0");

              img->subblock_x = i; // position used for context determination
              img->subblock_y = j; // position used for context determination
              currSE.value2 = k<<1; // identifies the component; only used for context determination
              dP->readSyntaxElement(&currSE,img,inp,dP);
              curr_mvd = currSE.value1; 
              
              vec=curr_mvd+pmv[k];           /* find motion vector */
              
              for(ii=0;ii<step_h;ii++)
              {
                for(jj=0;jj<step_v;jj++)
                {
                  dec_picture->mv  [LIST_0][j4+jj][i4+ii][k] = vec;
                  currMB->mvd      [LIST_0][j+jj] [i+ii] [k] = curr_mvd;
                }
              }
            }
          }
        }
      }
      else if (currMB->b8mode[k=2*(j0/2)+(i0/2)]==0)      
      {  
        if (!img->direct_spatial_mv_pred_flag)
        {
          int list_offset = ((img->MbaffFrameFlag)&&(currMB->mb_field))? img->current_mb_nr%2 ? 4 : 2 : 0;
          int imgblock_y= ((img->MbaffFrameFlag)&&(currMB->mb_field))? (img->current_mb_nr%2) ? (img->block_y-4)/2:img->block_y/2 : img->block_y;

          int refList = (co_located_ref_idx[LIST_0][imgblock_y+j0][img->block_x+i0]== -1 ? LIST_1 : LIST_0);
          int ref_idx =  co_located_ref_idx[refList][imgblock_y+j0][img->block_x+i0];          
          
          if (ref_idx==-1)
          {
            for (j=j0; j<j0+step_v0; j++)
              for (i=i0; i<i0+step_h0; i++)
              {            
                dec_picture->ref_idx [LIST_1][img->block_y+j][img->block_x+i]=0;
                dec_picture->ref_idx [LIST_0][img->block_y+j][img->block_x+i]=0; 
                j4 = img->block_y+j;
                i4 = img->block_x+i;            
                for (ii=0; ii < 2; ii++) 
                {                                    
                  dec_picture->mv [LIST_0][j4][i4][ii]=0;
                  dec_picture->mv [LIST_1][j4][i4][ii]=0;                  
                }
              }
          }
          else 
          {        
            int mapped_idx=-1, iref;                             
            int j6;
                        
            for (iref=0;iref<min(img->num_ref_idx_l0_active,listXsize[LIST_0 + list_offset]);iref++)
            {
              
#if 1
                int curr_mb_field = ((img->MbaffFrameFlag)&&(currMB->mb_field));

                  if(img->structure==0 && curr_mb_field==0)
                  {
                    // If the current MB is a frame MB and the colocated is from a field picture, 
                    // then the co_located_ref_id may have been generated from the wrong value of 
                    // frame_poc if it references it's complementary field, so test both POC values
                    if(listX[0][iref]->top_poc*2 == co_located_ref_id[refList][imgblock_y + j0][img->block_x + i0] 
                       || listX[0][iref]->bottom_poc*2 == co_located_ref_id[refList][imgblock_y + j0][img->block_x + i0])
                    {
                      mapped_idx=iref;
                      break;
                    }
                    else //! invalid index. Default to zero even though this case should not happen
                      mapped_idx=INVALIDINDEX;
                    continue;
                  }    
#endif                                        
              if (dec_picture->ref_pic_num[img->current_slice_nr][LIST_0 + list_offset][iref]==co_located_ref_id[refList][imgblock_y+j0][img->block_x+i0])
              {
                mapped_idx=iref;
                break;
              }
              else //! invalid index. Default to zero even though this case should not happen
                mapped_idx=INVALIDINDEX;
            }
            
            if (INVALIDINDEX == mapped_idx)
            {
              error("temporal direct error\ncolocated block has ref that is unavailable",-1111);
            }
            
            
            for (j=j0; j<j0+step_v0; j++)
              for (i=i0; i<i0+step_h0; i++)
              {
                {
                  mv_scale = img->mvscale[LIST_0 + list_offset][mapped_idx];

                  dec_picture->ref_idx [LIST_0][img->block_y+j][img->block_x+i] = mapped_idx;
                  dec_picture->ref_idx [LIST_1][img->block_y+j][img->block_x+i] = 0;
                  
                  j4 = img->block_y+j;
                  j6 = imgblock_y+j;
                  i4 = img->block_x+i;

                  for (ii=0; ii < 2; ii++) 
                  {              
                    //if (iTRp==0)
                    if (mv_scale == 9999 || listX[LIST_0+list_offset][mapped_idx]->is_long_term)
//                    if (mv_scale==9999 || Co_located->is_long_term)
                    {                      
                      dec_picture->mv  [LIST_0][j4][i4][ii]=co_located_mv[refList][j6][i4][ii];
                      dec_picture->mv  [LIST_1][j4][i4][ii]=0;
                    }
                    else
                    {
                      dec_picture->mv  [LIST_0][j4][i4][ii]=(mv_scale * co_located_mv[refList][j6][i4][ii] + 128 ) >> 8;
                      dec_picture->mv  [LIST_1][j4][i4][ii]=dec_picture->mv[LIST_0][j4][i4][ii] - co_located_mv[refList][j6][i4][ii];
                    }
                  }
                } 
              }
          }  
      } 
    }
  }
  
  //=====  READ BACKWARD MOTION VECTORS =====
  currSE.type = SE_MVD;
  dP          = &(currSlice->partArr[partMap[SE_MVD]]);

  if (active_pps->entropy_coding_mode_flag == UVLC || dP->bitstream->ei_flag) currSE.mapping = linfo_se;
  else                                                    currSE.reading = readMVD_CABAC;

  for (j0=0; j0<4; j0+=step_v0)
  {
    for (i0=0; i0<4; i0+=step_h0)
    {
      k=2*(j0/2)+(i0/2);
      if ((currMB->b8pdir[k]==1 || currMB->b8pdir[k]==2) && (currMB->b8mode[k]!=0))//has backward vector
      {
        mv_mode  = currMB->b8mode[k];
        step_h   = BLOCK_STEP [mv_mode][0];
        step_v   = BLOCK_STEP [mv_mode][1];
        
        refframe = dec_picture->ref_idx[LIST_1][img->block_y+j0][img->block_x+i0];

        for (j=j0; j<j0+step_v0; j+=step_v)
        {
          for (i=i0; i<i0+step_h0; i+=step_h)
          {
            j4 = img->block_y+j;
            i4 = img->block_x+i;
            
            // first make mv-prediction
            SetMotionVectorPredictor (img, pmv, pmv+1, refframe, LIST_1, dec_picture->ref_idx, dec_picture->mv, i, j, 4*step_h, 4*step_v);
            
            for (k=0; k < 2; k++) 
            {
              TRACE_STRING("mvd_l1");
              
              img->subblock_x = i; // position used for context determination
              img->subblock_y = j; // position used for context determination
              currSE.value2   = (k<<1) +1; // identifies the component; only used for context determination
              dP->readSyntaxElement(&currSE,img,inp,dP);
              curr_mvd = currSE.value1; 
              
              vec=curr_mvd+pmv[k];           /* find motion vector */

              for(ii=0;ii<step_h;ii++)
              {
                for(jj=0;jj<step_v;jj++)
                {
                  dec_picture->mv  [LIST_1][j4+jj][i4+ii][k] = vec;
                  currMB->mvd      [LIST_1][j+jj] [i+ii] [k] = curr_mvd;
                }
              }
            }
          }
        }
      }
    }
  }
  // record reference picture Ids for deblocking decisions
 
  for(i4=img->block_x;i4<(img->block_x+4);i4++)
  for(j4=img->block_y;j4<(img->block_y+4);j4++)
  {
    if(dec_picture->ref_idx[LIST_0][j4][i4]>=0)
       dec_picture->ref_pic_id[LIST_0][j4][i4] = dec_picture->ref_pic_num[img->current_slice_nr][LIST_0 + list_offset][(short)dec_picture->ref_idx[LIST_0][j4][i4]];
    else
       dec_picture->ref_pic_id[LIST_0][j4][i4] = INT64_MIN;
    if(dec_picture->ref_idx[LIST_1][j4][i4]>=0)
       dec_picture->ref_pic_id[LIST_1][j4][i4] = dec_picture->ref_pic_num[img->current_slice_nr][LIST_1 + list_offset][(short)dec_picture->ref_idx[LIST_1][j4][i4]];  
    else
       dec_picture->ref_pic_id[LIST_1][j4][i4] = INT64_MIN;  
  }
}



/*!
 ************************************************************************
 * \brief
 *    Get the Prediction from the Neighboring Blocks for Number of Nonzero Coefficients 
 *    
 *    Luma Blocks
 ************************************************************************
 */
int predict_nnz(struct img_par *img, int i,int j)
{
  PixelPos pix;

  int pred_nnz = 0;
  int cnt      = 0;
  int mb_nr    = img->current_mb_nr;

  // left block
  getLuma4x4Neighbour(mb_nr, i, j, -1, 0, &pix);

  if (pix.available && active_pps->constrained_intra_pred_flag && (img->currentSlice->dp_mode==PAR_DP_3))
  {
    pix.available &= img->intra_block[pix.mb_addr];
  }

  if (pix.available)
  {
    pred_nnz = img->nz_coeff [pix.mb_addr ][pix.x][pix.y];
    cnt++;
  }

  // top block
  getLuma4x4Neighbour(mb_nr, i, j, 0, -1, &pix);

  if (pix.available && active_pps->constrained_intra_pred_flag && (img->currentSlice->dp_mode==PAR_DP_3))
  {
    pix.available &= img->intra_block[pix.mb_addr];
  }

  if (pix.available)
  {
    pred_nnz += img->nz_coeff [pix.mb_addr ][pix.x][pix.y];
    cnt++;
  }

  if (cnt==2)
  {
    pred_nnz++;
    pred_nnz/=cnt; 
  }

  return pred_nnz;
}


/*!
 ************************************************************************
 * \brief
 *    Get the Prediction from the Neighboring Blocks for Number of Nonzero Coefficients 
 *    
 *    Chroma Blocks   
 ************************************************************************
 */
int predict_nnz_chroma(struct img_par *img, int i,int j)
{
  PixelPos pix;

  int pred_nnz = 0;
  int cnt      =0;
  int mb_nr    = img->current_mb_nr;
  int j_off_tab [12] = {0,0,0,0,4,4,4,4,8,8,8,8};
  int j_off = j_off_tab[j];
  
  if (dec_picture->chroma_format_idc != YUV444)
  {
    //YUV420 and YUV422
    // left block
    getChroma4x4Neighbour(mb_nr, i%2, j-4, -1, 0, &pix);

    if (pix.available && active_pps->constrained_intra_pred_flag && (img->currentSlice->dp_mode==PAR_DP_3))
    {
      pix.available &= img->intra_block[pix.mb_addr];
    }

    if (pix.available)
    {
      pred_nnz = img->nz_coeff [pix.mb_addr ][2 * (i/2) + pix.x][4 + pix.y];
      cnt++;
    }
    
    // top block
    getChroma4x4Neighbour(mb_nr, i%2, j-4, 0, -1, &pix);

    if (pix.available && active_pps->constrained_intra_pred_flag && (img->currentSlice->dp_mode==PAR_DP_3))
    {
      pix.available &= img->intra_block[pix.mb_addr];
    }

    if (pix.available)
    {
      pred_nnz += img->nz_coeff [pix.mb_addr ][2 * (i/2) + pix.x][4 + pix.y];
      cnt++;
    }
  }
  else
  {
    //YUV444
    // left block
    getChroma4x4Neighbour(mb_nr, i, j-j_off, -1, 0, &pix);

    if (pix.available && active_pps->constrained_intra_pred_flag && (img->currentSlice->dp_mode==PAR_DP_3))
    {
      pix.available &= img->intra_block[pix.mb_addr];
    }

    if (pix.available)
    {
      pred_nnz = img->nz_coeff [pix.mb_addr ][pix.x][j_off + pix.y];
      cnt++;
    }
    
    // top block
    getChroma4x4Neighbour(mb_nr, i, j-j_off, 0, -1, &pix);

    if (pix.available && active_pps->constrained_intra_pred_flag && (img->currentSlice->dp_mode==PAR_DP_3))
    {
      pix.available &= img->intra_block[pix.mb_addr];
    }

    if (pix.available)
    {
      pred_nnz += img->nz_coeff [pix.mb_addr ][pix.x][j_off + pix.y];
      cnt++;
    }    
  }
  
  if (cnt==2)
  {
    pred_nnz++;
    pred_nnz/=cnt; 
  }

  return pred_nnz;
}


/*!
 ************************************************************************
 * \brief
 *    Reads coeff of an 4x4 block (CAVLC)
 *
 * \author
 *    Karl Lillevold <karll@real.com>
 *    contributions by James Au <james@ubvideo.com>
 ************************************************************************
 */


void readCoeff4x4_CAVLC (struct img_par *img,struct inp_par *inp,
                        int block_type, 
                        int i, int j, int levarr[16], int runarr[16],
                        int *number_coefficients)
{
  int mb_nr = img->current_mb_nr;
  Macroblock *currMB = &img->mb_data[mb_nr];
  SyntaxElement currSE;
  Slice *currSlice = img->currentSlice;
  DataPartition *dP;
  int *partMap = assignSE2partition[currSlice->dp_mode];


  int k, code, vlcnum;
  int numcoeff, numtrailingones, numcoeff_vlc;
  int level_two_or_higher;
  int numones, totzeros, level, cdc=0, cac=0;
  int zerosleft, ntr, dptype = 0;
  int max_coeff_num = 0, nnz;
  char type[15];
  int incVlc[] = {0,3,6,12,24,48,32768};    // maximum vlc = 6

  numcoeff = 0;

  switch (block_type)
  {
  case LUMA:
    max_coeff_num = 16;
    sprintf(type, "%s", "Luma");
    if (IS_INTRA (currMB))
    {
      dptype = SE_LUM_AC_INTRA;
    }
    else
    {
      dptype = SE_LUM_AC_INTER;
    }
    break;
  case LUMA_INTRA16x16DC:
    max_coeff_num = 16;
    sprintf(type, "%s", "Lum16DC");
    dptype = SE_LUM_DC_INTRA;
    break;
  case LUMA_INTRA16x16AC:
    max_coeff_num = 15;
    sprintf(type, "%s", "Lum16AC");
    dptype = SE_LUM_AC_INTRA;
    break;

  case CHROMA_DC:
    max_coeff_num = img->num_cdc_coeff;
    cdc = 1;

    sprintf(type, "%s", "ChrDC");
    if (IS_INTRA (currMB))
    {
      dptype = SE_CHR_DC_INTRA;
    }
    else
    {
      dptype = SE_CHR_DC_INTER;
    }
    break;
  case CHROMA_AC:
    max_coeff_num = 15;
    cac = 1;
    sprintf(type, "%s", "ChrAC");
    if (IS_INTRA (currMB))
    {
      dptype = SE_CHR_AC_INTRA;
    }
    else
    {
      dptype = SE_CHR_AC_INTER;
    }
    break;
  default:
    error ("readCoeff4x4_CAVLC: invalid block type", 600);
    break;
  }

  currSE.type = dptype;
  dP = &(currSlice->partArr[partMap[dptype]]);

  img->nz_coeff[img->current_mb_nr][i][j] = 0;


  if (!cdc)
  {
    // luma or chroma AC
    if (!cac)
    {
      nnz = predict_nnz(img, i, j);
    }
    else
    {
      nnz = predict_nnz_chroma(img, i, j);
    }

    if (nnz < 2)
    {
      numcoeff_vlc = 0;
    }
    else if (nnz < 4)
    {
      numcoeff_vlc = 1;
    }
    else if (nnz < 8)
    {
      numcoeff_vlc = 2;
    }
    else //
    {
      numcoeff_vlc = 3;
    }

    currSE.value1 = numcoeff_vlc;

    readSyntaxElement_NumCoeffTrailingOnes(&currSE, dP, type);

    numcoeff =  currSE.value1;
    numtrailingones =  currSE.value2;

    img->nz_coeff[img->current_mb_nr][i][j] = numcoeff;
  }
  else
  {
    // chroma DC
    readSyntaxElement_NumCoeffTrailingOnesChromaDC(&currSE, dP);

    numcoeff =  currSE.value1;
    numtrailingones =  currSE.value2;
  }


  for (k = 0; k < max_coeff_num; k++)
  {
    levarr[k] = 0;
    runarr[k] = 0;
  }

  numones = numtrailingones;
  *number_coefficients = numcoeff;

  if (numcoeff)
  {
    if (numtrailingones)
    {

      currSE.len = numtrailingones;

#if TRACE
      snprintf(currSE.tracestring, 
        TRACESTRING_SIZE, "%s trailing ones sign (%d,%d)", type, i, j);
#endif

      readSyntaxElement_FLC (&currSE, dP->bitstream);

      code = currSE.inf;
      ntr = numtrailingones;
      for (k = numcoeff-1; k > numcoeff-1-numtrailingones; k--)
      {
        ntr --;
        if ((code>>ntr)&1)
          levarr[k] = -1;
        else
          levarr[k] = 1;
      }
    }

    // decode levels
    level_two_or_higher = 1;
    if (numcoeff > 3 && numtrailingones == 3)
      level_two_or_higher = 0;

      if (numcoeff > 10 && numtrailingones < 3)
          vlcnum = 1;
      else
          vlcnum = 0;

    for (k = numcoeff - 1 - numtrailingones; k >= 0; k--)
    {

#if TRACE
      snprintf(currSE.tracestring, 
        TRACESTRING_SIZE, "%s lev (%d,%d) k=%d vlc=%d ", type,
          i, j, k, vlcnum);
#endif

      if (vlcnum == 0)
          readSyntaxElement_Level_VLC0(&currSE, dP);
      else
          readSyntaxElement_Level_VLCN(&currSE, vlcnum, dP);

      if (level_two_or_higher)
      {
          if (currSE.inf > 0)
          currSE.inf ++;
          else
          currSE.inf --;
          level_two_or_higher = 0;
      }

      level = levarr[k] = currSE.inf;
      if (abs(level) == 1)
        numones ++;

      // update VLC table
      if (abs(level)>incVlc[vlcnum])
        vlcnum++;

      if (k == numcoeff - 1 - numtrailingones && abs(level)>3)
        vlcnum = 2;

    }
    
    if (numcoeff < max_coeff_num)
    {
      // decode total run
      vlcnum = numcoeff-1;
      currSE.value1 = vlcnum;

#if TRACE
      snprintf(currSE.tracestring, 
        TRACESTRING_SIZE, "%s totalrun (%d,%d) vlc=%d ", type, i,j, vlcnum);
#endif
      if (cdc)
        readSyntaxElement_TotalZerosChromaDC(&currSE, dP);
      else
        readSyntaxElement_TotalZeros(&currSE, dP);

      totzeros = currSE.value1;
    }
    else
    {
      totzeros = 0;
    }

    // decode run before each coefficient
    zerosleft = totzeros;
    i = numcoeff-1;
    if (zerosleft > 0 && i > 0)
    {
      do 
      {
        // select VLC for runbefore
        vlcnum = zerosleft - 1;
        if (vlcnum > RUNBEFORE_NUM-1)
          vlcnum = RUNBEFORE_NUM-1;

        currSE.value1 = vlcnum;
#if TRACE
        snprintf(currSE.tracestring, 
          TRACESTRING_SIZE, "%s run (%d,%d) k=%d vlc=%d ",
            type, i, j, i, vlcnum);
#endif

        readSyntaxElement_Run(&currSE, dP);
        runarr[i] = currSE.value1;

        zerosleft -= runarr[i];
        i --;
      } while (zerosleft != 0 && i != 0);
    }
    runarr[i] = zerosleft;

  } // if numcoeff
}

/*!
 ************************************************************************
 * \brief
 *    Calculate the quantisation and inverse quantisation parameters
 *
 ************************************************************************
 */
void CalculateQuant8Param()
{
  int i, j, k, temp;

  for(k=0; k<6; k++)
    for(j=0; j<8; j++)
    {
      for(i=0; i<8; i++)
      {
        temp = (i<<3)+j;
        InvLevelScale8x8Luma_Intra[k][j][i] = dequant_coef8[k][j][i]*qmatrix[6][temp];
        InvLevelScale8x8Luma_Inter[k][j][i] = dequant_coef8[k][j][i]*qmatrix[7][temp];
      }
    }
}

/*!
************************************************************************
* \brief
*    Get coefficients (run/level) of one 8x8 block  
*    from the NAL (CABAC Mode)
************************************************************************
*/
void readLumaCoeff8x8_CABAC (struct img_par *img,struct inp_par *inp, int b8)
{
  int i,j,k;
  int level;
  int mb_nr = img->current_mb_nr;
  Macroblock *currMB = &img->mb_data[mb_nr];
  int cbp = currMB->cbp;
  SyntaxElement currSE;
  Slice *currSlice = img->currentSlice;
  DataPartition *dP;
  int *partMap = assignSE2partition[currSlice->dp_mode];
  int coef_ctr;// i0, j0;
  int start_scan;
  int boff_x, boff_y;
  int any_coeff;
  int dq_lshift = 0, dq_rshift = 0, dq_round = 0;
  
  int run, len;
  
  int qp_per    = (img->qp + img->bitdepth_luma_qp_scale - MIN_QP)/6;
  int qp_rem    = (img->qp + img->bitdepth_luma_qp_scale - MIN_QP)%6;
  Boolean lossless_qpprime = ((img->qp + img->bitdepth_luma_qp_scale)==0 && img->lossless_qpprime_flag==1);

  if (qp_per < 6)
  {
    dq_rshift = 6 - qp_per;
    dq_round  = 1<<(5-qp_per);
  }
  else
    dq_lshift = qp_per - 6;
  
  img->is_intra_block = IS_INTRA(currMB);
  
  
  if (cbp & (1<<b8))  // are there any coeff in current block at all
  {
    // === set offset in current macroblock ===
    boff_x = (b8%2)<<3;
    boff_y = (b8/2)<<3;
    
    img->subblock_x = boff_x>>2; // position for coeff_count ctx
    img->subblock_y = boff_y>>2; // position for coeff_count ctx
    
    start_scan = 0; // take all coeffs
    coef_ctr = start_scan-1;
    level    = 1;

    for(k=start_scan;(k < 65) && (level != 0);k++)
    {
      //============ read =============
      /*
      * make distinction between INTRA and INTER coded
      * luminance coefficients
      */
      currSE.context      = LUMA_8x8;
      currSE.type         = (IS_INTRA(currMB) ?
      (k==0 ? SE_LUM_DC_INTRA : SE_LUM_AC_INTRA) :
      (k==0 ? SE_LUM_DC_INTER : SE_LUM_AC_INTER));
      
#if TRACE
      sprintf(currSE.tracestring, "Luma8x8 sng ");
#endif
      dP = &(currSlice->partArr[partMap[currSE.type]]);
      currSE.reading = readRunLevel_CABAC;
      
      dP->readSyntaxElement(&currSE,img,inp,dP);
      level = currSE.value1;
      run   = currSE.value2;
      len   = currSE.len;
      
      
      //============ decode =============
      if (level != 0)    /* leave if len=1 */
      {
        any_coeff=1;
        coef_ctr += run+1;
        
        if ((img->structure == FRAME) && (!currMB->mb_field)) 
        {
          i=SNGL_SCAN8x8[coef_ctr][0];
          j=SNGL_SCAN8x8[coef_ctr][1];
        }
        else 
        { // Alternate scan for field coding
          i=FIELD_SCAN8x8[coef_ctr][0];
          j=FIELD_SCAN8x8[coef_ctr][1];
        }
        
        currMB->cbp_blk |= 51 << (4*b8-2*(b8%2)); // corresponds to 110011, as if all four 4x4 blocks contain coeff, shifted to block position

        if(lossless_qpprime)
        {
          img->m7[boff_x + i][boff_y + j] = level;
        }
        else if (qp_per>=6)
        {
          if(img->is_intra_block == 1)
            img->m7[boff_x + i][boff_y + j] = level*InvLevelScale8x8Luma_Intra[qp_rem][i][j]<<dq_lshift; // dequantization
          else
            img->m7[boff_x + i][boff_y + j] = level*InvLevelScale8x8Luma_Inter[qp_rem][i][j]<<dq_lshift; // dequantization
        }
        else
        {
          if(img->is_intra_block == 1)
            img->m7[boff_x + i][boff_y + j] = (level*InvLevelScale8x8Luma_Intra[qp_rem][i][j]+dq_round)>>dq_rshift; // dequantization
          else
            img->m7[boff_x + i][boff_y + j] = (level*InvLevelScale8x8Luma_Inter[qp_rem][i][j]+dq_round)>>dq_rshift; // dequantization
        }
      }
    }
  }
  
    
}

/*!
 ************************************************************************
 * \brief
 *    Get coded block pattern and coefficients (run/level)
 *    from the NAL
 ************************************************************************
 */
void readCBPandCoeffsFromNAL(struct img_par *img,struct inp_par *inp)
{
  int i,j,k;
  int level;
  int mb_nr = img->current_mb_nr;
  int ii,jj;
  int m2,jg2;// i1,j1;
  Macroblock *currMB = &img->mb_data[mb_nr];
  int cbp;
  SyntaxElement currSE;
  Slice *currSlice = img->currentSlice;
  DataPartition *dP;
  int *partMap = assignSE2partition[currSlice->dp_mode];
  int iii,jjj;
  int coef_ctr, i0, j0, b8;
  int ll;
  int block_x,block_y;
  int start_scan;
  int run, len;
  int levarr[16], runarr[16], numcoeff;

  int qp_const;
  int qp_per    = (img->qp + img->bitdepth_luma_qp_scale - MIN_QP)/6;
  int qp_rem    = (img->qp + img->bitdepth_luma_qp_scale - MIN_QP)%6;
  int smb       = ((img->type==SP_SLICE) && IS_INTER (currMB)) || (img->type == SI_SLICE && currMB->mb_type == SI4MB);

  int uv;
  int qp_uv[2];
  int qp_const_uv[2];
  int qp_per_uv[2];
  int qp_rem_uv[2];
  int qp_c[2];
  
  int intra     = IS_INTRA (currMB);
  int temp[4];
  
  int b4;
  int yuv = dec_picture->chroma_format_idc-1;
  int m5[4];
  int m6[4];

  int need_transform_size_flag;
  Boolean lossless_qpprime = ((img->qp + img->bitdepth_luma_qp_scale)==0 && img->lossless_qpprime_flag==1);
  
  // Residue Color Transform
  Boolean residual_transform_dc = ((img->residue_transform_flag==1) && (IS_OLDINTRA(currMB)||currMB->mb_type==I8MB) );

  // QPI
  //init constants for every chroma qp offset
  if (dec_picture->chroma_format_idc != YUV400)
  {
    for (i=0; i<2; i++)
    {
      qp_uv[i] = img->qp + dec_picture->chroma_qp_offset[i];
      qp_uv[i] = Clip3(-(img->bitdepth_chroma_qp_scale), 51, qp_uv[i]);
      qp_c[i]  = (qp_uv[i] < 0)? qp_uv[i] : QP_SCALE_CR[qp_uv[i]-MIN_QP];
      qp_per_uv[i] = (qp_c[i] + img->bitdepth_chroma_qp_scale)/6;
      qp_rem_uv[i] = (qp_c[i] + img->bitdepth_chroma_qp_scale)%6;
    }
  }

  // read CBP if not new intra mode
  if (!IS_NEWINTRA (currMB))
  {
    //=====   C B P   =====
    //---------------------
    if (IS_OLDINTRA (currMB) || currMB->mb_type == SI4MB || currMB->mb_type == I8MB)   currSE.type = SE_CBP_INTRA;
    else                        currSE.type = SE_CBP_INTER;

    dP = &(currSlice->partArr[partMap[currSE.type]]);
    
    if (active_pps->entropy_coding_mode_flag == UVLC || dP->bitstream->ei_flag)
    {
      if (IS_OLDINTRA (currMB) || currMB->mb_type == SI4MB || currMB->mb_type == I8MB)  currSE.mapping = linfo_cbp_intra;
      else                        currSE.mapping = linfo_cbp_inter;
    }
    else
    {
      currSE.reading = readCBP_CABAC;
    }

    TRACE_STRING("coded_block_pattern");

    dP->readSyntaxElement(&currSE,img,inp,dP);
    currMB->cbp = cbp = currSE.value1;


    //============= Transform size flag for INTER MBs =============
    //-------------------------------------------------------------
    need_transform_size_flag = (((currMB->mb_type >= 1 && currMB->mb_type <= 3)||
                                (IS_DIRECT(currMB) && active_sps->direct_8x8_inference_flag) ||
                                (currMB->NoMbPartLessThan8x8Flag))
                                && currMB->mb_type != I8MB && currMB->mb_type != I4MB
                                && (currMB->cbp&15)
                                && img->Transform8x8Mode);

    if (need_transform_size_flag)
    {
      currSE.type   =  SE_HEADER;
      dP = &(currSlice->partArr[partMap[SE_HEADER]]);
      currSE.reading = readMB_transform_size_flag_CABAC;
      TRACE_STRING("transform size 8x8 flag");

      // read UVLC transform_size_8x8_flag
      if (active_pps->entropy_coding_mode_flag == UVLC || dP->bitstream->ei_flag)
      {
        currSE.len = 1;
        readSyntaxElement_FLC(&currSE, dP->bitstream);
      } else 
      {
        dP->readSyntaxElement(&currSE,img,inp,dP);
      }
      currMB->luma_transform_size_8x8_flag = currSE.value1;
    }
    
    //=====   DQUANT   =====
    //----------------------
    // Delta quant only if nonzero coeffs
    if (cbp !=0)
    {
      if (IS_INTER (currMB))  currSE.type = SE_DELTA_QUANT_INTER;
      else                    currSE.type = SE_DELTA_QUANT_INTRA;

      dP = &(currSlice->partArr[partMap[currSE.type]]);
      
      if (active_pps->entropy_coding_mode_flag == UVLC || dP->bitstream->ei_flag)
      {
        currSE.mapping = linfo_se;
      }
      else
        currSE.reading= readDquant_CABAC; //gabi

      TRACE_STRING("mb_qp_delta");

      dP->readSyntaxElement(&currSE,img,inp,dP);
      currMB->delta_quant = currSE.value1;

      img->qp= ((img->qp + currMB->delta_quant + 52 + 2*img->bitdepth_luma_qp_scale)%(52+img->bitdepth_luma_qp_scale)) -
                 img->bitdepth_luma_qp_scale;
    }
  }
  else
  {
    cbp = currMB->cbp;
  }

  for (i=0;i<BLOCK_SIZE;i++)
    for (j=0;j<BLOCK_SIZE;j++)
      for(iii=0;iii<BLOCK_SIZE;iii++)
        for(jjj=0;jjj<BLOCK_SIZE;jjj++)
          img->cof[i][j][iii][jjj]=0;// reset luma coeffs


  if (IS_NEWINTRA (currMB)) // read DC coeffs for new intra modes
  {
    currSE.type = SE_DELTA_QUANT_INTRA;

    dP = &(currSlice->partArr[partMap[currSE.type]]);
    
    if (active_pps->entropy_coding_mode_flag == UVLC || dP->bitstream->ei_flag)
    {
      currSE.mapping = linfo_se;
    }
    else
    {
      currSE.reading= readDquant_CABAC;
    }
#if TRACE
    snprintf(currSE.tracestring, TRACESTRING_SIZE, "Delta quant ");
#endif
    dP->readSyntaxElement(&currSE,img,inp,dP);
    currMB->delta_quant = currSE.value1;
    
    img->qp= ((img->qp + currMB->delta_quant + 52 + 2*img->bitdepth_luma_qp_scale)%(52+img->bitdepth_luma_qp_scale)) -
               img->bitdepth_luma_qp_scale;

    for (i=0;i<BLOCK_SIZE;i++)
      for (j=0;j<BLOCK_SIZE;j++)
        img->ipredmode[img->block_x+i][img->block_y+j]=DC_PRED;


    if (active_pps->entropy_coding_mode_flag == UVLC)
    {
      readCoeff4x4_CAVLC(img, inp, LUMA_INTRA16x16DC, 0, 0,
                          levarr, runarr, &numcoeff);

      coef_ctr=-1;
      level = 1;                            // just to get inside the loop
      for(k = 0; k < numcoeff; k++)
      {
        if (levarr[k] != 0)                     // leave if len=1
        {
          coef_ctr=coef_ctr+runarr[k]+1;

          if ((img->structure == FRAME) && (!currMB->mb_field)) 
          {
            i0=SNGL_SCAN[coef_ctr][0];
            j0=SNGL_SCAN[coef_ctr][1];
          }
          else 
          { // Alternate scan for field coding
            i0=FIELD_SCAN[coef_ctr][0];
            j0=FIELD_SCAN[coef_ctr][1];
          }

          img->cof[i0][j0][0][0]=levarr[k];// add new intra DC coeff
        }
      }
    }
    else
    {

      currSE.type = SE_LUM_DC_INTRA;
      dP = &(currSlice->partArr[partMap[currSE.type]]);

      currSE.context      = LUMA_16DC;
      currSE.type         = SE_LUM_DC_INTRA;
      img->is_intra_block = 1;

      if (active_pps->entropy_coding_mode_flag == UVLC || dP->bitstream->ei_flag)
      {
        currSE.mapping = linfo_levrun_inter;
      }
      else
      {
        currSE.reading = readRunLevel_CABAC;
      }



      coef_ctr=-1;
      level = 1;                            // just to get inside the loop
      for(k=0;(k<17) && (level!=0);k++)
      {
#if TRACE
        snprintf(currSE.tracestring, TRACESTRING_SIZE, "DC luma 16x16 ");
#endif
        dP->readSyntaxElement(&currSE,img,inp,dP);
        level = currSE.value1;
        run   = currSE.value2;
        len   = currSE.len;

        if (level != 0)                     // leave if len=1
        {
          coef_ctr=coef_ctr+run+1;

          if ((img->structure == FRAME) && (!currMB->mb_field)) 
          {
            i0=SNGL_SCAN[coef_ctr][0];
            j0=SNGL_SCAN[coef_ctr][1];
          }
          else 
          { // Alternate scan for field coding
            i0=FIELD_SCAN[coef_ctr][0];
            j0=FIELD_SCAN[coef_ctr][1];
          }

          img->cof[i0][j0][0][0]=level;// add new intra DC coeff
        }
      }
    }
    if(!lossless_qpprime)
      itrans_2(img);// transform new intra DC
  }

  qp_per    = (img->qp + img->bitdepth_luma_qp_scale - MIN_QP)/6;
  qp_rem    = (img->qp + img->bitdepth_luma_qp_scale - MIN_QP)%6;
  qp_const  = 1<<(3-qp_per);
  
  //init constants for every chroma qp offset
  if (dec_picture->chroma_format_idc != YUV400)
  {
    for(i=0; i < 2; i++)
    {
      qp_uv[i] = img->qp + dec_picture->chroma_qp_offset[i];
      qp_uv[i] = Clip3(-(img->bitdepth_chroma_qp_scale), 51, qp_uv[i]);
      qp_c[i]  = (qp_uv[i] < 0)? qp_uv[i] : QP_SCALE_CR[qp_uv[i]-MIN_QP];
      qp_per_uv[i] = (qp_c[i] + img->bitdepth_chroma_qp_scale)/6;
      qp_rem_uv[i] = (qp_c[i] + img->bitdepth_chroma_qp_scale)%6;
    }
  }

  currMB->qp = img->qp;

  
  // luma coefficients
  for (block_y=0; block_y < 4; block_y += 2) /* all modes */
  {
    for (block_x=0; block_x < 4; block_x += 2)
    {

      b8 = 2*(block_y/2) + block_x/2;
      if (active_pps->entropy_coding_mode_flag == UVLC)
      {
        for (j=block_y; j < block_y+2; j++)
        {
          for (i=block_x; i < block_x+2; i++)
          {
            ii = block_x/2; jj = block_y/2;
            b8 = 2*jj+ii;

            if (cbp & (1<<b8))  /* are there any coeff in current block at all */
            {
              if (IS_NEWINTRA(currMB))
              {
                readCoeff4x4_CAVLC(img, inp, LUMA_INTRA16x16AC, i, j,
                                    levarr, runarr, &numcoeff);

                start_scan = 1;
              }
              else
              {
                readCoeff4x4_CAVLC(img, inp, LUMA, i, j,
                                    levarr, runarr, &numcoeff);
                start_scan = 0;
              }

              coef_ctr = start_scan-1;
              for (k = 0; k < numcoeff; k++)
              {
                if (levarr[k] != 0)
                {
                  coef_ctr             += runarr[k]+1;

                  if ((img->structure == FRAME) && (!currMB->mb_field)) 
                  {
                    i0=SNGL_SCAN[coef_ctr][0];
                    j0=SNGL_SCAN[coef_ctr][1];
                  }
                  else { // Alternate scan for field coding
                    i0=FIELD_SCAN[coef_ctr][0];
                    j0=FIELD_SCAN[coef_ctr][1];
                  }


                  if (!currMB->luma_transform_size_8x8_flag) 
                  { // inverse quant for 4x4 transform only
                    currMB->cbp_blk      |= 1 << ((j<<2) + i);

                    if(lossless_qpprime)
                    {
                      img->cof[i][j][i0][j0]= levarr[k];
                    }
                    else if(qp_per<4)
                    {
                      if(intra == 1)
                        img->cof[i][j][i0][j0]= (levarr[k]*InvLevelScale4x4Luma_Intra[qp_rem][i0][j0]+qp_const)>>(4-qp_per);
                      else
                        img->cof[i][j][i0][j0]= (levarr[k]*InvLevelScale4x4Luma_Inter[qp_rem][i0][j0]+qp_const)>>(4-qp_per);
                    }
                    else
                    {
                      if(intra == 1)
                        img->cof[i][j][i0][j0]= (levarr[k]*InvLevelScale4x4Luma_Intra[qp_rem][i0][j0])<<(qp_per-4);
                      else
                        img->cof[i][j][i0][j0]= (levarr[k]*InvLevelScale4x4Luma_Inter[qp_rem][i0][j0])<<(qp_per-4);
                    }

                  } //if (!currMB->luma_transform_size_8x8_flag)
                  else
                  {
                    // new inverse quant for 8x8 transform
                    int b4, iz, jz, dq_rshift = 0, dq_round = 0, dq_lshift = 0;

                    // do same as CABAC for deblocking: any coeff in the 8x8 marks all the 4x4s
                    //as containing coefficients
                    currMB->cbp_blk  |= 51 << ((block_y<<2) + block_x);

                    b4 = 2*(j-block_y)+(i-block_x);

                    if ((img->structure == FRAME) && (!currMB->mb_field)) 
                    {
                      iz=SNGL_SCAN8x8[coef_ctr*4+b4][0];
                      jz=SNGL_SCAN8x8[coef_ctr*4+b4][1];
                    }
                    else { // Alternate scan for field coding
                      iz=FIELD_SCAN8x8[coef_ctr*4+b4][0];
                      jz=FIELD_SCAN8x8[coef_ctr*4+b4][1];
                    }

                    if (qp_per < 6)
                    {
                      dq_rshift = 6 - qp_per;
                      dq_round  = 1<<(5-qp_per);
                    }
                    else
                      dq_lshift = qp_per - 6;

                    if(lossless_qpprime)   
                    {
                      img->m7[block_x*4 +iz][block_y*4 +jz] = levarr[k];
                    }
                    else if (qp_per>=6)
                    {
                      if(intra == 1)
                        img->m7[block_x*4 +iz][block_y*4 +jz] = levarr[k]*InvLevelScale8x8Luma_Intra[qp_rem][iz][jz]<<dq_lshift; // dequantization
                      else
                        img->m7[block_x*4 +iz][block_y*4 +jz] = levarr[k]*InvLevelScale8x8Luma_Inter[qp_rem][iz][jz]<<dq_lshift; // dequantization
                    }
                    else
                    {   
                      if(intra)
                        img->m7[block_x*4 +iz][block_y*4 +jz] = (levarr[k]*InvLevelScale8x8Luma_Intra[qp_rem][iz][jz]+dq_round)>>dq_rshift; // dequantization
                      else
                        img->m7[block_x*4 +iz][block_y*4 +jz] = (levarr[k]*InvLevelScale8x8Luma_Inter[qp_rem][iz][jz]+dq_round)>>dq_rshift; // dequantization
                    }

                  }//else (!currMB->luma_transform_size_8x8_flag)
                }
              }
            }
            else
            {
              img->nz_coeff[img->current_mb_nr][i][j] = 0;
            }
          }
        }
      } // VLC
      else
      { 
        if(currMB->luma_transform_size_8x8_flag)
          readLumaCoeff8x8_CABAC(img, inp, b8); //======= 8x8 trannsform size & CABAC ========
        else
        {
          //======= Other Modes & CABAC ========
          //------------------------------------
          for (j=block_y; j < block_y+2; j++)
          {
            for (i=block_x; i < block_x+2; i++)
            {
              if (IS_NEWINTRA (currMB))   start_scan = 1; // skip DC coeff
              else                        start_scan = 0; // take all coeffs
              
              img->subblock_x = i; // position for coeff_count ctx
              img->subblock_y = j; // position for coeff_count ctx
              if (cbp & (1<<b8))  // are there any coeff in current block at all
              {
                coef_ctr = start_scan-1;
                level    = 1;
                
                for(k=start_scan;(k<17) && (level!=0);k++)
                {
                /*
                * make distinction between INTRA and INTER coded
                * luminance coefficients
                  */
                  currSE.context      = (IS_NEWINTRA(currMB) ? LUMA_16AC : LUMA_4x4);
                  currSE.type         = (IS_INTRA(currMB) ?
                    (k==0 ? SE_LUM_DC_INTRA : SE_LUM_AC_INTRA) :
                    (k==0 ? SE_LUM_DC_INTER : SE_LUM_AC_INTER));
                  img->is_intra_block = IS_INTRA(currMB);
                  
#if TRACE
                  sprintf(currSE.tracestring, "Luma sng ");
#endif
                  dP = &(currSlice->partArr[partMap[currSE.type]]);
                  
                  if (active_pps->entropy_coding_mode_flag == UVLC || dP->bitstream->ei_flag)  currSE.mapping = linfo_levrun_inter;
                  else                                                     currSE.reading = readRunLevel_CABAC;
                  
                  dP->readSyntaxElement(&currSE,img,inp,dP);
                  level = currSE.value1;
                  run   = currSE.value2;
                  len   = currSE.len;
                  
                  if (level != 0)    /* leave if len=1 */
                  {
                    coef_ctr             += run+1;
                    
                    if ((img->structure == FRAME) && (!currMB->mb_field)) 
                    {
                      i0=SNGL_SCAN[coef_ctr][0];
                      j0=SNGL_SCAN[coef_ctr][1];
                    }
                    else { // Alternate scan for field coding
                      i0=FIELD_SCAN[coef_ctr][0];
                      j0=FIELD_SCAN[coef_ctr][1];
                    }
                    currMB->cbp_blk      |= 1 << ((j<<2) + i) ;

                    if(lossless_qpprime)
                    {
                      img->cof[i][j][i0][j0]= level;
                    }
                    else if(qp_per<4)
                    {
                      if(intra == 1)
                        img->cof[i][j][i0][j0]= (level*InvLevelScale4x4Luma_Intra[qp_rem][i0][j0]+qp_const)>>(4-qp_per);
                      else
                        img->cof[i][j][i0][j0]= (level*InvLevelScale4x4Luma_Inter[qp_rem][i0][j0]+qp_const)>>(4-qp_per);
                    }
                    else
                    {
                      if(intra == 1)
                        img->cof[i][j][i0][j0]= (level*InvLevelScale4x4Luma_Intra[qp_rem][i0][j0])<<(qp_per-4);
                      else
                        img->cof[i][j][i0][j0]= (level*InvLevelScale4x4Luma_Inter[qp_rem][i0][j0])<<(qp_per-4);
                    }

                  }
                }
              }
            }
          }
        }
      } 
    }
  }

  if (dec_picture->chroma_format_idc != YUV400)
  {
    for (j=4;j<(4+img->num_blk8x8_uv);j++) // reset all chroma coeffs before read
    for (i=0;i<4;i++)
    for (iii=0;iii<4;iii++)
    for (jjj=0;jjj<4;jjj++)
      img->cof[i][j][iii][jjj]=0;

    m2 =img->mb_x*2;
    jg2=img->mb_y*2;
  
    qp_const_uv[0] = 1<<(3-qp_per_uv[0]);
    qp_const_uv[1] = 1<<(3-qp_per_uv[1]);


    //========================== CHROMA DC ============================
    //-----------------------------------------------------------------
    // chroma DC coeff
    if(cbp>15)
    {
      for (ll=0;ll<3;ll+=2)
      {
        uv = ll>>1;

        if (dec_picture->chroma_format_idc == YUV420)
        {
          //===================== CHROMA DC YUV420 ======================
          for (i=0;i<4;i++)
            img->cofu[i]=0;
        
          if (active_pps->entropy_coding_mode_flag == UVLC)
          {
            readCoeff4x4_CAVLC(img, inp, CHROMA_DC, 0, 0,
                               levarr, runarr, &numcoeff);
            coef_ctr=-1;
            level=1;
            for(k = 0; k < numcoeff; k++)
            {
              if (levarr[k] != 0)
              {
                currMB->cbp_blk |= 0xf0000 << (ll<<1) ;
                coef_ctr=coef_ctr+runarr[k]+1;
                img->cofu[coef_ctr]=levarr[k];
              }
            }
          }
          else
          {
            coef_ctr=-1;
            level=1;
            for(k=0;(k<(img->num_cdc_coeff+1))&&(level!=0);k++)
            {
              currSE.context      = CHROMA_DC;
              currSE.type         = (IS_INTRA(currMB) ? SE_CHR_DC_INTRA : SE_CHR_DC_INTER);
              img->is_intra_block =  IS_INTRA(currMB);
              img->is_v_block     = ll;
            
  #if TRACE
              snprintf(currSE.tracestring, TRACESTRING_SIZE, " 2x2 DC Chroma ");
  #endif
              dP = &(currSlice->partArr[partMap[currSE.type]]);
            
              if (active_pps->entropy_coding_mode_flag == UVLC || dP->bitstream->ei_flag)
                currSE.mapping = linfo_levrun_c2x2;
              else
                currSE.reading = readRunLevel_CABAC;
            
              dP->readSyntaxElement(&currSE,img,inp,dP);
              level = currSE.value1;
              run = currSE.value2;
              len = currSE.len;
              if (level != 0)
              {
                currMB->cbp_blk |= 0xf0000 << (ll<<1) ;
                coef_ctr=coef_ctr+run+1;
                // Bug: img->cofu has only 4 entries, hence coef_ctr MUST be <4 (which is
                // caught by the assert().  If it is bigger than 4, it starts patching the
                // img->predmode pointer, which leads to bugs later on.
                //
                // This assert() should be left in the code, because it captures a very likely
                // bug early when testing in error prone environments (or when testing NAL
                // functionality).
                assert (coef_ctr < img->num_cdc_coeff);
                img->cofu[coef_ctr]=level;
              }
            }
          }
        
          if (smb // check to see if MB type is SPred or SIntra4x4 
              || lossless_qpprime)
          {
            img->cof[0+ll][4][0][0]=img->cofu[0];   img->cof[1+ll][4][0][0]=img->cofu[1];
            img->cof[0+ll][5][0][0]=img->cofu[2];   img->cof[1+ll][5][0][0]=img->cofu[3];
          }
          else
          {
            temp[0]=(img->cofu[0]+img->cofu[1]+img->cofu[2]+img->cofu[3]);
            temp[1]=(img->cofu[0]-img->cofu[1]+img->cofu[2]-img->cofu[3]);
            temp[2]=(img->cofu[0]+img->cofu[1]-img->cofu[2]-img->cofu[3]);
            temp[3]=(img->cofu[0]-img->cofu[1]-img->cofu[2]+img->cofu[3]);

            for (i=0;i<img->num_cdc_coeff;i++)
            {
              if(qp_per_uv[uv]<5)
              {
                if(intra == 1)
                  temp[i]=(temp[i]*InvLevelScale4x4Chroma_Intra[uv][qp_rem_uv[uv]][0][0])>>(5-qp_per_uv[uv]);
                else
                  temp[i]=(temp[i]*InvLevelScale4x4Chroma_Inter[uv][qp_rem_uv[uv]][0][0])>>(5-qp_per_uv[uv]);
              }
              else
              {
                if(intra == 1)
                  temp[i]=(temp[i]*InvLevelScale4x4Chroma_Intra[uv][qp_rem_uv[uv]][0][0])<<(qp_per_uv[uv]-5);
                else
                  temp[i]=(temp[i]*InvLevelScale4x4Chroma_Inter[uv][qp_rem_uv[uv]][0][0])<<(qp_per_uv[uv]-5);
              }
            }
            img->cof[0+ll][4][0][0]=temp[0];
            img->cof[1+ll][4][0][0]=temp[1];
            img->cof[0+ll][5][0][0]=temp[2];
            img->cof[1+ll][5][0][0]=temp[3];
          }
        }
        else if (dec_picture->chroma_format_idc == YUV422)
        {
          int i,j,j1;
          int uv_idx = ll;
          int m3[2][4] = {{0,0,0,0},{0,0,0,0}};
          int m4[2][4] = {{0,0,0,0},{0,0,0,0}};
          int qp_per_uv_dc = (qp_c[uv] + 3 + img->bitdepth_chroma_qp_scale)/6;       //for YUV422 only
          int qp_rem_uv_dc = (qp_c[uv] + 3 + img->bitdepth_chroma_qp_scale)%6;       //for YUV422 only
        
          //===================== CHROMA DC YUV422 ======================
          if (active_pps->entropy_coding_mode_flag == UVLC)
          {
            readCoeff4x4_CAVLC(img, inp, CHROMA_DC, 0, 0,
                               levarr, runarr, &numcoeff);
            coef_ctr=-1;
            level=1;
            for(k = 0; k < numcoeff; k++)
            {
              if (levarr[k] != 0)
              {
                currMB->cbp_blk |= ((int64)0xff0000) << (ll<<2);
                coef_ctr=coef_ctr+runarr[k]+1;
                i0=SCAN_YUV422[coef_ctr][0];
                j0=SCAN_YUV422[coef_ctr][1];
              
                m3[i0][j0]=levarr[k];
              }
            }
          }
          else
          {
            coef_ctr=-1;
            level=1;
            for(k=0;(k<9)&&(level!=0);k++)
            {
              currSE.context      = CHROMA_DC_2x4;
              currSE.type         = (IS_INTRA(currMB) ? SE_CHR_DC_INTRA : SE_CHR_DC_INTER);
              img->is_intra_block =  IS_INTRA(currMB);
              img->is_v_block     = ll;
            
  #if TRACE
              snprintf(currSE.tracestring, TRACESTRING_SIZE, "2x4 DC Chroma ");
  #endif
              dP = &(currSlice->partArr[partMap[currSE.type]]);
            
              if (active_pps->entropy_coding_mode_flag == UVLC || dP->bitstream->ei_flag)
                currSE.mapping = linfo_levrun_c2x2;
              else
                currSE.reading = readRunLevel_CABAC;
            
              dP->readSyntaxElement(&currSE,img,inp,dP);
              level = currSE.value1;
              run = currSE.value2;
              len = currSE.len;
              if (level != 0)
              {
                currMB->cbp_blk |= ((int64)0xff0000) << (ll<<2) ;
                coef_ctr=coef_ctr+run+1;
                assert (coef_ctr < img->num_cdc_coeff);
                i0=SCAN_YUV422[coef_ctr][0];
                j0=SCAN_YUV422[coef_ctr][1];
              
                m3[i0][j0]=level;
              }
            }
          }
          // inverse CHROMA DC YUV422 transform
          // horizontal
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
          }
          else
          {
            for(i=0;i<2;i++)
              for(j=0;j<4;j++)
                img->cof[i+uv_idx][j+4][0][0]=m3[i][j];
          }

          // vertical
          for (i=0;i<2 && !lossless_qpprime;i++)
          {
            for (j=0; j < 4;j++)    //TODO: remove m5 with m4
              m5[j]=m4[i][j]; 
          
            m6[0]=m5[0]+m5[2];
            m6[1]=m5[0]-m5[2];
            m6[2]=m5[1]-m5[3];
            m6[3]=m5[1]+m5[3];
          
            for (j=0;j<2;j++)
            {
              j1=3-j;
              if(qp_per_uv_dc<4)
              {
                if(intra == 1)
                {
                  img->cof[i+uv_idx][j +4][0][0]=((((m6[j]+m6[j1])*InvLevelScale4x4Chroma_Intra[uv][qp_rem_uv_dc][0][0]+(1<<(3-qp_per_uv_dc)))>>(4-qp_per_uv_dc))+2)>>2;
                  img->cof[i+uv_idx][j1+4][0][0]=((((m6[j]-m6[j1])*InvLevelScale4x4Chroma_Intra[uv][qp_rem_uv_dc][0][0]+(1<<(3-qp_per_uv_dc)))>>(4-qp_per_uv_dc))+2)>>2;
                }
                else
                {
                  img->cof[i+uv_idx][j +4][0][0]=((((m6[j]+m6[j1])*InvLevelScale4x4Chroma_Inter[uv][qp_rem_uv_dc][0][0]+(1<<(3-qp_per_uv_dc)))>>(4-qp_per_uv_dc))+2)>>2;
                  img->cof[i+uv_idx][j1+4][0][0]=((((m6[j]-m6[j1])*InvLevelScale4x4Chroma_Inter[uv][qp_rem_uv_dc][0][0]+(1<<(3-qp_per_uv_dc)))>>(4-qp_per_uv_dc))+2)>>2;
                }
              }
              else
              {
                if(intra == 1)
                {
                  img->cof[i+uv_idx][j +4][0][0]=((((m6[j]+m6[j1])*InvLevelScale4x4Chroma_Intra[uv][qp_rem_uv_dc][0][0])<<(qp_per_uv_dc-4))+2)>>2;
                  img->cof[i+uv_idx][j1+4][0][0]=((((m6[j]-m6[j1])*InvLevelScale4x4Chroma_Intra[uv][qp_rem_uv_dc][0][0])<<(qp_per_uv_dc-4))+2)>>2;
                }
                else
                {
                  img->cof[i+uv_idx][j +4][0][0]=((((m6[j]+m6[j1])*InvLevelScale4x4Chroma_Inter[uv][qp_rem_uv_dc][0][0])<<(qp_per_uv_dc-4))+2)>>2;
                  img->cof[i+uv_idx][j1+4][0][0]=((((m6[j]-m6[j1])*InvLevelScale4x4Chroma_Inter[uv][qp_rem_uv_dc][0][0])<<(qp_per_uv_dc-4))+2)>>2;
                }
              }
            }//for (j=0;j<2;j++)
          }//for (i=0;i<2;i++)
        }//else if (dec_picture->chroma_format_idc == YUV422)
        else
        {
          //===================== CHROMA DC YUV444 ======================
          int i,j,i1,j1;
          int uv_idx = 4 + (ll<<1);

          if (active_pps->entropy_coding_mode_flag == UVLC)
          {
            readCoeff4x4_CAVLC(img, inp, CHROMA_DC, 0, 0,
                               levarr, runarr, &numcoeff);
            coef_ctr=-1;
            level=1;
            for(k = 0; k < numcoeff; k++)
            {
              if (levarr[k] != 0)
              {
                currMB->cbp_blk |= ((int64)0xffff0000) << (ll<<3) ;
                coef_ctr=coef_ctr+runarr[k]+1;
                i0=SNGL_SCAN[coef_ctr][0];
                j0=SNGL_SCAN[coef_ctr][1];
 
                img->cof[i0][j0+uv_idx][0][0]=levarr[k];
              }
            }
          }
          else
          {
            coef_ctr=-1;
            level=1;
            for(k=0;(k<17)&&(level!=0);k++)
            {
              currSE.context      = CHROMA_DC_4x4;
              currSE.type         = (IS_INTRA(currMB) ? SE_CHR_DC_INTRA : SE_CHR_DC_INTER);
              img->is_intra_block =  IS_INTRA(currMB);
              img->is_v_block     = ll;
            
  #if TRACE
              snprintf(currSE.tracestring, TRACESTRING_SIZE, " DC Chroma ");
  #endif
              dP = &(currSlice->partArr[partMap[currSE.type]]);
            
              if (active_pps->entropy_coding_mode_flag == UVLC || dP->bitstream->ei_flag)
                currSE.mapping = linfo_levrun_c2x2;
              else
                currSE.reading = readRunLevel_CABAC;
            
              dP->readSyntaxElement(&currSE,img,inp,dP);
              level = currSE.value1;
              run = currSE.value2;
              len = currSE.len;
              if (level != 0)
              {
                currMB->cbp_blk |= ((int64)0xffff0000) << (ll<<3) ;
                coef_ctr=coef_ctr+run+1;
                assert (coef_ctr < img->num_cdc_coeff);
                i0=SNGL_SCAN[coef_ctr][0];
                j0=SNGL_SCAN[coef_ctr][1];
              
                img->cof[i0][j0+uv_idx][0][0]=level;
              }
            }
          }

          // Residue Color Transform
          if(!residual_transform_dc)
          {
            // inverse CHROMA DC YUV444 transform
            // horizontal
            for (j=uv_idx; (j < 4+uv_idx) && !lossless_qpprime;j++)
            {
              for (i=0;i<4;i++)
                m5[i]=img->cof[i][j][0][0];

              m6[0]=m5[0]+m5[2];
              m6[1]=m5[0]-m5[2];
              m6[2]=m5[1]-m5[3];
              m6[3]=m5[1]+m5[3];

              for (i=0;i<2;i++)
              {
                i1=3-i;
                img->cof[i][j][0][0]= m6[i]+m6[i1];
                img->cof[i1][j][0][0]=m6[i]-m6[i1];
              }
            }

            // vertical
            for (i=0;i<4 && !lossless_qpprime;i++)
            {
              for (j=0; j < 4;j++)
                m5[j]=img->cof[i][j+uv_idx][0][0]; 

              m6[0]=m5[0]+m5[2];
              m6[1]=m5[0]-m5[2];
              m6[2]=m5[1]-m5[3];
              m6[3]=m5[1]+m5[3];

              for (j=0;j<2;j++)
              {
                j1=3-j;
                if(qp_per_uv[uv]<4)
                {
                  if(intra == 1)
                  {
                    img->cof[i][j +uv_idx][0][0]=((((m6[j]+m6[j1])*InvLevelScale4x4Chroma_Intra[uv][qp_rem_uv[uv]][0][0]+(1<<(3-qp_per_uv[uv])))>>(4-qp_per_uv[uv]))+2)>>2;
                    img->cof[i][j1+uv_idx][0][0]=((((m6[j]-m6[j1])*InvLevelScale4x4Chroma_Intra[uv][qp_rem_uv[uv]][0][0]+(1<<(3-qp_per_uv[uv])))>>(4-qp_per_uv[uv]))+2)>>2;
                  } 
                  else 
                  {
                    img->cof[i][j +uv_idx][0][0]=((((m6[j]+m6[j1])*InvLevelScale4x4Chroma_Inter[uv][qp_rem_uv[uv]][0][0]+(1<<(3-qp_per_uv[uv])))>>(4-qp_per_uv[uv]))+2)>>2;
                    img->cof[i][j1+uv_idx][0][0]=((((m6[j]-m6[j1])*InvLevelScale4x4Chroma_Inter[uv][qp_rem_uv[uv]][0][0]+(1<<(3-qp_per_uv[uv])))>>(4-qp_per_uv[uv]))+2)>>2;
                  }
                }
                else
                {
                  if(intra == 1)
                  {
                    img->cof[i][j +uv_idx][0][0]=((((m6[j]+m6[j1])*InvLevelScale4x4Chroma_Intra[uv][qp_rem_uv[uv]][0][0])<<(qp_per_uv[uv]-4))+2)>>2;
                    img->cof[i][j1+uv_idx][0][0]=((((m6[j]-m6[j1])*InvLevelScale4x4Chroma_Intra[uv][qp_rem_uv[uv]][0][0])<<(qp_per_uv[uv]-4))+2)>>2;
                  } 
                  else 
                  {
                    img->cof[i][j +uv_idx][0][0]=((((m6[j]+m6[j1])*InvLevelScale4x4Chroma_Inter[uv][qp_rem_uv[uv]][0][0])<<(qp_per_uv[uv]-4))+2)>>2;
                    img->cof[i][j1+uv_idx][0][0]=((((m6[j]-m6[j1])*InvLevelScale4x4Chroma_Inter[uv][qp_rem_uv[uv]][0][0])<<(qp_per_uv[uv]-4))+2)>>2;
                  }
                }
              } 
            }//for (i=0;i<4;i++)
          } 
          else
          { //residual_transform_dc

            for (i=0;i<4  && !lossless_qpprime ;i++)
            for (j=0; j < 4;j++)
            {
              if(qp_per_uv[uv]<4)
              {
                if(intra == 1)
                {
                  img->cof[i][j +uv_idx][0][0]=((((img->cof[i][j +uv_idx][0][0])*InvLevelScale4x4Chroma_Intra[uv][qp_rem_uv[uv]][0][0]+(1<<(3-qp_per_uv[uv])))>>(4-qp_per_uv[uv])));
                } 
                else 
                {
                  img->cof[i][j +uv_idx][0][0]=((((img->cof[i][j +uv_idx][0][0])*InvLevelScale4x4Chroma_Inter[uv][qp_rem_uv[uv]][0][0]+(1<<(3-qp_per_uv[uv])))>>(4-qp_per_uv[uv])));
                }
              } 
              else 
              {
                if(intra == 1) 
                {
                  img->cof[i][j +uv_idx][0][0]=((((img->cof[i][j +uv_idx][0][0])*InvLevelScale4x4Chroma_Intra[uv][qp_rem_uv[uv]][0][0])<<(qp_per_uv[uv]-4)));
                } 
                else 
                {
                  img->cof[i][j +uv_idx][0][0]=((((img->cof[i][j +uv_idx][0][0])*InvLevelScale4x4Chroma_Inter[uv][qp_rem_uv[uv]][0][0])<<(qp_per_uv[uv]-4)));
                }
              }
            }
          } //residual_transform_dc
        }//else (dec_picture->chroma_format_idc == YUV444)
      }//for (ll=0;ll<3;ll+=2)
    }

    // chroma AC coeff, all zero fram start_scan
    if (cbp<=31)
      for (j=4; j < (4 + img->num_blk8x8_uv); j++)
        for (i=0; i < 4; i++)
          img->nz_coeff [img->current_mb_nr ][i][j]=0;


    //========================== CHROMA AC ============================
    //-----------------------------------------------------------------
    // chroma AC coeff, all zero fram start_scan
    if (cbp>31)
    {
      for (b8=0; b8 < img->num_blk8x8_uv; b8++)
      {
        for (b4=0; b4 < 4; b4++)
        {
          i = cofuv_blk_x[yuv][b8][b4];
          j = cofuv_blk_y[yuv][b8][b4];
        
          img->is_v_block = uv = (b8 > ((img->num_blk8x8_uv>>1) - 1 ));
        

          if (active_pps->entropy_coding_mode_flag == UVLC)
          {
            readCoeff4x4_CAVLC(img, inp, CHROMA_AC, i, j,
                                levarr, runarr, &numcoeff);
            coef_ctr=0;
            level=1;
            for(k = 0; k < numcoeff;k++)
            {
              if (levarr[k] != 0)
              {
                currMB->cbp_blk |= ((int64)1) << cbp_blk_chroma[b8][b4];
                coef_ctr=coef_ctr+runarr[k]+1;

                if ((img->structure == FRAME) && (!currMB->mb_field)) 
                {
                  i0=SNGL_SCAN[coef_ctr][0];
                  j0=SNGL_SCAN[coef_ctr][1];
                }
                else 
                { // Alternate scan for field coding
                  i0=FIELD_SCAN[coef_ctr][0];
                  j0=FIELD_SCAN[coef_ctr][1];
                }

                if(lossless_qpprime) 
                {
                  img->cof[i][j][i0][j0]=levarr[k];
                }
                else if(qp_per_uv[uv]<4)
                {
                  if(intra == 1)
                    img->cof[i][j][i0][j0]=(levarr[k]*InvLevelScale4x4Chroma_Intra[img->is_v_block][qp_rem_uv[uv]][i0][j0]+qp_const_uv[uv])>>(4-qp_per_uv[uv]);
                  else
                    img->cof[i][j][i0][j0]=(levarr[k]*InvLevelScale4x4Chroma_Inter[img->is_v_block][qp_rem_uv[uv]][i0][j0]+qp_const_uv[uv])>>(4-qp_per_uv[uv]);
                }
                else
                {
                  if(intra == 1)
                    img->cof[i][j][i0][j0]=(levarr[k]*InvLevelScale4x4Chroma_Intra[img->is_v_block][qp_rem_uv[uv]][i0][j0])<<(qp_per_uv[uv]-4);
                  else
                    img->cof[i][j][i0][j0]=(levarr[k]*InvLevelScale4x4Chroma_Inter[img->is_v_block][qp_rem_uv[uv]][i0][j0])<<(qp_per_uv[uv]-4);
                }
              }
            }
          }
          else
          {
            coef_ctr=0;
            level=1;

            img->subblock_y = subblk_offset_y[yuv][b8][b4]>>2;
            img->subblock_x = subblk_offset_x[yuv][b8][b4]>>2;

            currSE.context      = CHROMA_AC;
            currSE.type         = (IS_INTRA(currMB) ? SE_CHR_AC_INTRA : SE_CHR_AC_INTER);
            img->is_intra_block =  IS_INTRA(currMB);
          
            for(k=0;(k<16)&&(level!=0);k++)
            {
  #if TRACE
              snprintf(currSE.tracestring, TRACESTRING_SIZE, " AC Chroma ");
  #endif
              dP = &(currSlice->partArr[partMap[currSE.type]]);
          
              if (active_pps->entropy_coding_mode_flag == UVLC || dP->bitstream->ei_flag)
                currSE.mapping = linfo_levrun_inter;
              else
                currSE.reading = readRunLevel_CABAC;
                     
              dP->readSyntaxElement(&currSE,img,inp,dP);
              level = currSE.value1;
              run = currSE.value2;
              len = currSE.len;

              if (level != 0)
              {
                currMB->cbp_blk |= ((int64)1) << cbp_blk_chroma[b8][b4];
                coef_ctr=coef_ctr+run+1;

                if ((img->structure == FRAME) && (!currMB->mb_field)) 
                {
                  i0=SNGL_SCAN[coef_ctr][0];
                  j0=SNGL_SCAN[coef_ctr][1];
                }
                else { // Alternate scan for field coding
                  i0=FIELD_SCAN[coef_ctr][0];
                  j0=FIELD_SCAN[coef_ctr][1];
                }

                if(lossless_qpprime)
                {
                  img->cof[i][j][i0][j0]=level;
                }
                else if(qp_per_uv[uv]<4)
                {
                  if(intra == 1)
                    img->cof[i][j][i0][j0]=(level*InvLevelScale4x4Chroma_Intra[img->is_v_block][qp_rem_uv[uv]][i0][j0]+qp_const_uv[uv])>>(4-qp_per_uv[uv]);
                  else
                    img->cof[i][j][i0][j0]=(level*InvLevelScale4x4Chroma_Inter[img->is_v_block][qp_rem_uv[uv]][i0][j0]+qp_const_uv[uv])>>(4-qp_per_uv[uv]);
                }
                else
                {
                  if(intra == 1)
                    img->cof[i][j][i0][j0]=(level*InvLevelScale4x4Chroma_Intra[img->is_v_block][qp_rem_uv[uv]][i0][j0])<<(qp_per_uv[uv]-4);
                  else
                    img->cof[i][j][i0][j0]=(level*InvLevelScale4x4Chroma_Inter[img->is_v_block][qp_rem_uv[uv]][i0][j0])<<(qp_per_uv[uv]-4);
                }
              }
            } //for(k=0;(k<16)&&(level!=0);k++)
          } //else / if (active_pps->entropy_coding_mode_flag == UVLC)
        } //for (b4=0; b4 < 4; b4++)
      } //for (b8=0; b8 < img->num_blk8x8_uv; b8++)
    } //if (cbp>31)
  } //if (dec_picture->chroma_format_idc != YUV400)
}


/*!
 ************************************************************************
 * \brief
 *    Copy IPCM coefficients to decoded picture buffer and set parameters for this MB
 *    (for IPCM CABAC and IPCM CAVLC  28/11/2003)
 *
 * \author
 *    Dong Wang <Dong.Wang@bristol.ac.uk>
 ************************************************************************
 */

void decode_ipcm_mb(struct img_par *img)
{
  int i,j;

  Macroblock *currMb = &img->mb_data[img->current_mb_nr];    

  //Copy coefficients to decoded picture buffer
  //IPCM coefficients are stored in img->cof which is set in function readIPCMcoeffsFromNAL()

  for(i=0;i<16;i++)
    for(j=0;j<16;j++)
      dec_picture->imgY[img->pix_y+i][img->pix_x+j]=img->cof[i/4][j/4][i%4][j%4];

  if (dec_picture->chroma_format_idc != YUV400)
  {
    for(i=0;i<img->mb_cr_size_y;i++)
      for(j=0;j<img->mb_cr_size_x;j++)
        dec_picture->imgUV[0][img->pix_c_y+i][img->pix_c_x+j]=img->cof[i/4][j/4+4][i%4][j%4];   //TODO-VG

    for(i=0;i<img->mb_cr_size_y;i++)
      for(j=0;j<img->mb_cr_size_x;j++)
        dec_picture->imgUV[1][img->pix_c_y+i][img->pix_c_x+j]=img->cof[i/4+2][j/4+4][i%4][j%4]; //TODO-VG
  }



  // for deblocking filter
  currMb->qp=0;

  // for CAVLC: Set the nz_coeff to 16. 
  // These parameters are to be used in CAVLC decoding of neighbour blocks
  for(i=0;i<4;i++)
    for (j=0;j<(4 + img->num_blk8x8_uv);j++)
      img->nz_coeff[img->current_mb_nr][i][j]=16;


  // for CABAC decoding of MB skip flag 
  currMb->skip_flag = 0;

  //for deblocking filter CABAC
  currMb->cbp_blk=0xFFFF;

  //For CABAC decoding of Dquant
  last_dquant=0;
}

/*!
 ************************************************************************
 * \brief
 *    decode one macroblock
 ************************************************************************
 */

int decode_one_macroblock(struct img_par *img,struct inp_par *inp)
{
  int tmp_block[BLOCK_SIZE][BLOCK_SIZE];
  int tmp_blockbw[BLOCK_SIZE][BLOCK_SIZE];
  int i=0,j=0,k,l,ii=0,jj=0,i1=0,j1=0,j4=0,i4=0;
  int uv, hv;
  int vec1_x=0,vec1_y=0,vec2_x=0,vec2_y=0;
  int ioff,joff;
  int block8x8;   // needed for ABT

  int bw_pred=0, fw_pred=0, pred, ifx;
  int ii0,jj0,ii1,jj1,if1,jf1,if0,jf0;
  int mv_mul, f1_x, f1_y, f2_x, f2_y, f3, f4;

  const byte decode_block_scan[16] = {0,1,4,5,2,3,6,7,8,9,12,13,10,11,14,15};

  Macroblock *currMB   = &img->mb_data[img->current_mb_nr];
  short ref_idx, fw_refframe=-1, bw_refframe=-1;
  int mv_mode, pred_dir, intra_prediction; // = currMB->ref_frame;
  short fw_ref_idx=-1, bw_ref_idx=-1;

  short  *** mv_array, ***fw_mv_array, ***bw_mv_array;

  int mv_scale;

  int mb_nr     = img->current_mb_nr;
  int smb       = ((img->type==SP_SLICE) && IS_INTER (currMB)) || (img->type == SI_SLICE && currMB->mb_type == SI4MB);
  int list_offset;
  int max_y_cr;

  StorablePicture **list;

  int jf;

  char fw_rFrame=-1,bw_rFrame=-1;

  short pmvfw[2]={0,0},
        pmvbw[2]={0,0};              

  int direct_pdir=-1;

  int curr_mb_field = ((img->MbaffFrameFlag)&&(currMB->mb_field));

  byte  **    moving_block;
  short ****  co_located_mv;
  char  ***   co_located_ref_idx;
  int64 ***   co_located_ref_id;

  int need_4x4_transform = (!currMB->luma_transform_size_8x8_flag);

  int b8, b4;
  int uv_shift;
  int yuv = dec_picture->chroma_format_idc - 1;

  // Residue Color Transform
  int residue_transform_flag = img->residue_transform_flag;
  int residue_R, residue_G, residue_B, temp;

  if(currMB->mb_type==IPCM)
  {
    //copy readed data into imgY and set parameters
    decode_ipcm_mb(img);
    return 0;
  }

//////////////////////////

  // find out the correct list offsets
  if (curr_mb_field)
  {
    if(mb_nr%2)
    {
      list_offset = 4; // top field mb
      moving_block = Co_located->bottom_moving_block;
      co_located_mv = Co_located->bottom_mv;
      co_located_ref_idx = Co_located->bottom_ref_idx;
      co_located_ref_id = Co_located->bottom_ref_pic_id;
    }
    else
    {
      list_offset = 2; // bottom field mb
      moving_block = Co_located->top_moving_block;
      co_located_mv = Co_located->top_mv;
      co_located_ref_idx = Co_located->top_ref_idx;
      co_located_ref_id = Co_located->top_ref_pic_id;
    }
    max_y_cr = dec_picture->size_y_cr/2-1;
  }
  else
  {
    list_offset = 0;  // no mb aff or frame mb
    moving_block = Co_located->moving_block;
    co_located_mv = Co_located->mv;
    co_located_ref_idx = Co_located->ref_idx;
    co_located_ref_id = Co_located->ref_pic_id;
    max_y_cr = dec_picture->size_y_cr-1;
  }



  if (!img->MbaffFrameFlag)
  {
    for (l=0+list_offset;l<(2+list_offset);l++)
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
    if (curr_mb_field)
    {
      for (l=0+list_offset;l<(2+list_offset);l++)
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
      for (l=0+list_offset;l<(2+list_offset);l++)
      {
        for(k = 0; k < listXsize[l]; k++)
        {
          listX[l][k]->chroma_vector_adjustment= 0;
        }
      }
    }
  }

  mv_mul=4;

  // luma decoding **************************************************

  // get prediction for INTRA_MB_16x16
  if (IS_NEWINTRA (currMB))
  {
    intrapred_luma_16x16(img, currMB->i16mode);
  }

  if (img->type==B_SLICE && img->direct_spatial_mv_pred_flag && (IS_DIRECT (currMB) || 
    (IS_P8x8(currMB) && !(currMB->b8mode[0] && currMB->b8mode[1] && currMB->b8mode[2] && currMB->b8mode[3]))))
  {
    char fw_rFrameL, fw_rFrameU, fw_rFrameUL, fw_rFrameUR;
    char bw_rFrameL, bw_rFrameU, bw_rFrameUL, bw_rFrameUR;    

    PixelPos mb_left, mb_up, mb_upleft, mb_upright;              
    
    getLuma4x4Neighbour(img->current_mb_nr,0,0,-1, 0,&mb_left);
    getLuma4x4Neighbour(img->current_mb_nr,0,0, 0,-1,&mb_up);
    getLuma4x4Neighbour(img->current_mb_nr,0,0,16, -1,&mb_upright);
    getLuma4x4Neighbour(img->current_mb_nr,0,0, -1,-1,&mb_upleft);

    if (!img->MbaffFrameFlag)
    {
      fw_rFrameL = mb_left.available ? dec_picture->ref_idx[LIST_0][mb_left.pos_y][mb_left.pos_x] : -1;
      fw_rFrameU = mb_up.available ? dec_picture->ref_idx[LIST_0][mb_up.pos_y][mb_up.pos_x] : -1;
      fw_rFrameUL = mb_upleft.available ? dec_picture->ref_idx[LIST_0][mb_upleft.pos_y][mb_upleft.pos_x] : -1;
      fw_rFrameUR = mb_upright.available ? dec_picture->ref_idx[LIST_0][mb_upright.pos_y][mb_upright.pos_x] : fw_rFrameUL;      
      
      bw_rFrameL = mb_left.available ? dec_picture->ref_idx[LIST_1][mb_left.pos_y][mb_left.pos_x] : -1;
      bw_rFrameU = mb_up.available ? dec_picture->ref_idx[LIST_1][mb_up.pos_y][mb_up.pos_x] : -1;
      bw_rFrameUL = mb_upleft.available ? dec_picture->ref_idx[LIST_1][mb_upleft.pos_y][mb_upleft.pos_x] : -1;
      bw_rFrameUR = mb_upright.available ? dec_picture->ref_idx[LIST_1][mb_upright.pos_y][mb_upright.pos_x] : bw_rFrameUL;      
    }
    else
    {
      if (img->mb_data[img->current_mb_nr].mb_field)
      {
        fw_rFrameL = mb_left.available ? 
          img->mb_data[mb_left.mb_addr].mb_field  || dec_picture->ref_idx[LIST_0][mb_left.pos_y][mb_left.pos_x] < 0? 
          dec_picture->ref_idx[LIST_0][mb_left.pos_y][mb_left.pos_x] : 
          dec_picture->ref_idx[LIST_0][mb_left.pos_y][mb_left.pos_x] * 2: -1;

        fw_rFrameU = mb_up.available ? 
          img->mb_data[mb_up.mb_addr].mb_field || dec_picture->ref_idx[LIST_0][mb_up.pos_y][mb_up.pos_x] < 0? 
          dec_picture->ref_idx[LIST_0][mb_up.pos_y][mb_up.pos_x] : 
        dec_picture->ref_idx[LIST_0][mb_up.pos_y][mb_up.pos_x] * 2: -1;

        fw_rFrameUL = mb_upleft.available ? 
          img->mb_data[mb_upleft.mb_addr].mb_field || dec_picture->ref_idx[LIST_0][mb_upleft.pos_y][mb_upleft.pos_x] < 0?         
          dec_picture->ref_idx[LIST_0][mb_upleft.pos_y][mb_upleft.pos_x] : 
        dec_picture->ref_idx[LIST_0][mb_upleft.pos_y][mb_upleft.pos_x] *2: -1;      

        fw_rFrameUR = mb_upright.available ? 
          img->mb_data[mb_upright.mb_addr].mb_field || dec_picture->ref_idx[LIST_0][mb_upright.pos_y][mb_upright.pos_x] < 0?
          dec_picture->ref_idx[LIST_0][mb_upright.pos_y][mb_upright.pos_x] : 
        dec_picture->ref_idx[LIST_0][mb_upright.pos_y][mb_upright.pos_x] * 2: fw_rFrameUL;      
        
        bw_rFrameL = mb_left.available ? 
          img->mb_data[mb_left.mb_addr].mb_field || dec_picture->ref_idx[LIST_1][mb_left.pos_y][mb_left.pos_x] < 0? 
          dec_picture->ref_idx[LIST_1][mb_left.pos_y][mb_left.pos_x] : 
        dec_picture->ref_idx[LIST_1][mb_left.pos_y][mb_left.pos_x] * 2: -1;

        bw_rFrameU = mb_up.available ? 
          img->mb_data[mb_up.mb_addr].mb_field || dec_picture->ref_idx[LIST_1][mb_up.pos_y][mb_up.pos_x] < 0? 
          dec_picture->ref_idx[LIST_1][mb_up.pos_y][mb_up.pos_x] : 
        dec_picture->ref_idx[LIST_1][mb_up.pos_y][mb_up.pos_x] * 2: -1;

        bw_rFrameUL = mb_upleft.available ? 
          img->mb_data[mb_upleft.mb_addr].mb_field || dec_picture->ref_idx[LIST_1][mb_upleft.pos_y][mb_upleft.pos_x] < 0?         
          dec_picture->ref_idx[LIST_1][mb_upleft.pos_y][mb_upleft.pos_x] : 
        dec_picture->ref_idx[LIST_1][mb_upleft.pos_y][mb_upleft.pos_x] *2: -1;      

        bw_rFrameUR = mb_upright.available ? 
          img->mb_data[mb_upright.mb_addr].mb_field || dec_picture->ref_idx[LIST_1][mb_upright.pos_y][mb_upright.pos_x] < 0?         
          dec_picture->ref_idx[LIST_1][mb_upright.pos_y][mb_upright.pos_x] : 
        dec_picture->ref_idx[LIST_1][mb_upright.pos_y][mb_upright.pos_x] * 2: bw_rFrameUL;              
      }
      else
      {
        fw_rFrameL = mb_left.available ? 
          img->mb_data[mb_left.mb_addr].mb_field || dec_picture->ref_idx[LIST_0][mb_left.pos_y][mb_left.pos_x]  < 0 ?
          dec_picture->ref_idx[LIST_0][mb_left.pos_y][mb_left.pos_x] >> 1 : 
        dec_picture->ref_idx[LIST_0][mb_left.pos_y][mb_left.pos_x]: -1;
        
        fw_rFrameU = mb_up.available ? 
          img->mb_data[mb_up.mb_addr].mb_field || dec_picture->ref_idx[LIST_0][mb_up.pos_y][mb_up.pos_x] < 0 ?
          dec_picture->ref_idx[LIST_0][mb_up.pos_y][mb_up.pos_x] >> 1 :  
        dec_picture->ref_idx[LIST_0][mb_up.pos_y][mb_up.pos_x] : -1;
        
        fw_rFrameUL = mb_upleft.available ? 
          img->mb_data[mb_upleft.mb_addr].mb_field || dec_picture->ref_idx[LIST_0][mb_upleft.pos_y][mb_upleft.pos_x] < 0 ?
          dec_picture->ref_idx[LIST_0][mb_upleft.pos_y][mb_upleft.pos_x]>> 1 : 
        dec_picture->ref_idx[LIST_0][mb_upleft.pos_y][mb_upleft.pos_x] : -1;      
        
        fw_rFrameUR = mb_upright.available ? 
          img->mb_data[mb_upright.mb_addr].mb_field || dec_picture->ref_idx[LIST_0][mb_upright.pos_y][mb_upright.pos_x] < 0 ? 
          dec_picture->ref_idx[LIST_0][mb_upright.pos_y][mb_upright.pos_x] >> 1 :  
        dec_picture->ref_idx[LIST_0][mb_upright.pos_y][mb_upright.pos_x] : fw_rFrameUL;      
        
        bw_rFrameL = mb_left.available ? 
          img->mb_data[mb_left.mb_addr].mb_field || dec_picture->ref_idx[LIST_1][mb_left.pos_y][mb_left.pos_x] < 0 ?
          dec_picture->ref_idx[LIST_1][mb_left.pos_y][mb_left.pos_x] >> 1 :  
        dec_picture->ref_idx[LIST_1][mb_left.pos_y][mb_left.pos_x] : -1;
        
        bw_rFrameU = mb_up.available ? 
          img->mb_data[mb_up.mb_addr].mb_field || dec_picture->ref_idx[LIST_1][mb_up.pos_y][mb_up.pos_x] < 0 ?
          dec_picture->ref_idx[LIST_1][mb_up.pos_y][mb_up.pos_x] >> 1 : 
        dec_picture->ref_idx[LIST_1][mb_up.pos_y][mb_up.pos_x] : -1;
        
        bw_rFrameUL = mb_upleft.available ? 
          img->mb_data[mb_upleft.mb_addr].mb_field || dec_picture->ref_idx[LIST_1][mb_upleft.pos_y][mb_upleft.pos_x] < 0 ?
          dec_picture->ref_idx[LIST_1][mb_upleft.pos_y][mb_upleft.pos_x] >> 1 : 
        dec_picture->ref_idx[LIST_1][mb_upleft.pos_y][mb_upleft.pos_x] : -1;      
        
        bw_rFrameUR = mb_upright.available ? 
          img->mb_data[mb_upright.mb_addr].mb_field || dec_picture->ref_idx[LIST_1][mb_upright.pos_y][mb_upright.pos_x] < 0 ?
          dec_picture->ref_idx[LIST_1][mb_upright.pos_y][mb_upright.pos_x] >> 1: 
        dec_picture->ref_idx[LIST_1][mb_upright.pos_y][mb_upright.pos_x] : bw_rFrameUL;      
      }
    }

    fw_rFrame = (fw_rFrameL >= 0 && fw_rFrameU >= 0) ? min(fw_rFrameL,fw_rFrameU): max(fw_rFrameL,fw_rFrameU);
    fw_rFrame = (fw_rFrame >= 0 && fw_rFrameUR >= 0) ? min(fw_rFrame,fw_rFrameUR): max(fw_rFrame,fw_rFrameUR);

    bw_rFrame = (bw_rFrameL >= 0 && bw_rFrameU >= 0) ? min(bw_rFrameL,bw_rFrameU): max(bw_rFrameL,bw_rFrameU);
    bw_rFrame = (bw_rFrame >= 0 && bw_rFrameUR >= 0) ? min(bw_rFrame,bw_rFrameUR): max(bw_rFrame,bw_rFrameUR);        

    if (fw_rFrame >=0)
      SetMotionVectorPredictor (img, pmvfw, pmvfw+1, fw_rFrame, LIST_0, dec_picture->ref_idx, dec_picture->mv, 0, 0, 16, 16);

    if (bw_rFrame >=0)
      SetMotionVectorPredictor (img, pmvbw, pmvbw+1, bw_rFrame, LIST_1, dec_picture->ref_idx, dec_picture->mv, 0, 0, 16, 16);

  }

  for (block8x8=0; block8x8<4; block8x8++)
  {
    if (currMB->b8mode[block8x8] == I8MB)
    {
      //=========== 8x8 BLOCK TYPE ============
      ioff = 8*(block8x8%2);
      joff = 8*(block8x8/2);

      //PREDICTION
      if(!residue_transform_flag)
        intrapred8x8(img, block8x8);

      itrans8x8(img,ioff,joff);      // use DCT transform and make 8x8 block m7 from prediction block mpr

      for(ii=0;ii<8;ii++)
      {
        for(jj=0;jj<8;jj++)
        {
          // Residue Color Transform
          if(!residue_transform_flag)
          {
            dec_picture->imgY[img->pix_y + joff + jj][img->pix_x + ioff + ii]=img->m7[ii + ioff][jj + joff]; // contruct picture from 4x4 blocks
          }
          else
          {
            rec_res[0][ii+ioff][jj+joff] = img->m7[ii + ioff][jj + joff];
          }
        }
      }
      continue;
    }

    for (k = block8x8*4; k < block8x8*4+4; k ++)
    {
      i = (decode_block_scan[k] & 3);
      j = ((decode_block_scan[k] >> 2) & 3);
      
      ioff=i*4;
      i4=img->block_x+i;
      
      joff=j*4;
      j4=img->block_y+j;

      mv_mode  = currMB->b8mode[2*(j/2)+(i/2)];
      pred_dir = currMB->b8pdir[2*(j/2)+(i/2)];
      
      assert (pred_dir<=2);

      // PREDICTION
      if (mv_mode==IBLOCK)
      {
        // Residue Color Transform
        if(!residue_transform_flag)
        {
        //===== INTRA PREDICTION =====
          if (intrapred(img,ioff,joff,i4,j4)==SEARCH_SYNC)  /* make 4x4 prediction block mpr from given prediction img->mb_mode */
            return SEARCH_SYNC;                   /* bit error */
        }
      }
      else if (!IS_NEWINTRA (currMB))
      {
        if (pred_dir != 2)
        {
          //===== FORWARD/BACKWARD PREDICTION =====
          fw_refframe = ref_idx  = dec_picture->ref_idx[LIST_0 + pred_dir][j4][i4];
          mv_array = dec_picture->mv[LIST_0 + pred_dir];
          list     = listX[0+list_offset+ pred_dir];
          vec1_x = i4*4*mv_mul + mv_array[j4][i4][0];

          if (!curr_mb_field)
          {
            vec1_y = j4*4*mv_mul + mv_array[j4][i4][1];
          }
          else
          {
            if (mb_nr%2 == 0) 
              vec1_y = (img->block_y * 2 + joff) * mv_mul + mv_array[j4][i4][1];
            else
              vec1_y = ((img->block_y-4) * 2 + joff)* mv_mul + mv_array[j4][i4][1];
          }

          get_block (ref_idx, list, vec1_x, vec1_y, img, tmp_block);

          if (img->apply_weights)
          {
            if (((active_pps->weighted_pred_flag&&(img->type==P_SLICE|| img->type == SP_SLICE))||
                (active_pps->weighted_bipred_idc==1 && (img->type==B_SLICE))) && curr_mb_field)
            {
              ref_idx >>=1;
            }

            for(ii=0;ii<BLOCK_SIZE;ii++)
              for(jj=0;jj<BLOCK_SIZE;jj++)  
                img->mpr[ii+ioff][jj+joff] = Clip1(((img->wp_weight[pred_dir][ref_idx][0] *  tmp_block[ii][jj]+ img->wp_round_luma) >>img->luma_log2_weight_denom)  + img->wp_offset[pred_dir][fw_refframe>>curr_mb_field][0] );
          }
          else
          {
            for(ii=0;ii<BLOCK_SIZE;ii++)
              for(jj=0;jj<BLOCK_SIZE;jj++)  
                img->mpr[ii+ioff][jj+joff] = tmp_block[ii][jj];
          }
        }
        else
        {
          if (mv_mode != 0)
          {
            //===== BI-DIRECTIONAL PREDICTION =====
            fw_mv_array = dec_picture->mv[LIST_0];
            bw_mv_array = dec_picture->mv[LIST_1];
            
            fw_refframe = dec_picture->ref_idx[LIST_0][j4][i4];
            bw_refframe = dec_picture->ref_idx[LIST_1][j4][i4];
            fw_ref_idx = fw_refframe;
            bw_ref_idx = bw_refframe;
          }
          else
          {
            //===== DIRECT PREDICTION =====
            fw_mv_array = dec_picture->mv[LIST_0];
            bw_mv_array = dec_picture->mv[LIST_1];
            bw_refframe = 0;

            if (img->direct_spatial_mv_pred_flag )
            {
              int imgblock_y= ((img->MbaffFrameFlag)&&(currMB->mb_field))? (img->current_mb_nr%2) ? (img->block_y-4)/2:img->block_y/2: img->block_y;
              int j6=imgblock_y+j;


              if (fw_rFrame >=0)
              {
                if (!fw_rFrame  && ((!moving_block[j6][i4]) && (!listX[1+list_offset][0]->is_long_term)))
                {
                  dec_picture->mv  [LIST_0][j4][i4][0]= 0;
                  dec_picture->mv  [LIST_0][j4][i4][1]= 0;
                  dec_picture->ref_idx[LIST_0][j4][i4] = 0;
                }
                else
                {
                  dec_picture->mv  [LIST_0][j4][i4][0]= pmvfw[0];
                  dec_picture->mv  [LIST_0][j4][i4][1]= pmvfw[1];
                  dec_picture->ref_idx[LIST_0][j4][i4] = fw_rFrame;
                }
              }
              else
              {
                dec_picture->ref_idx[LIST_0][j4][i4] = -1;                
                dec_picture->mv  [LIST_0][j4][i4][0]= 0;
                dec_picture->mv  [LIST_0][j4][i4][1]= 0;
              }
              
              if (bw_rFrame >=0)
              {
                if  (bw_rFrame==0 && ((!moving_block[j6][i4]) && (!listX[1+list_offset][0]->is_long_term)))
                {                  
                  
                  dec_picture->mv  [LIST_1][j4][i4][0]= 0;
                  dec_picture->mv  [LIST_1][j4][i4][1]= 0;
                  dec_picture->ref_idx[LIST_1][j4][i4] = bw_rFrame;
                  
                }
                else
                {
                  dec_picture->mv  [LIST_1][j4][i4][0]= pmvbw[0];
                  dec_picture->mv  [LIST_1][j4][i4][1]= pmvbw[1];
                  
                  dec_picture->ref_idx[LIST_1][j4][i4] = bw_rFrame;
                }               
              }
              else
              {                  
                dec_picture->mv  [LIST_1][j4][i4][0]=0;
                dec_picture->mv  [LIST_1][j4][i4][1]=0;
                dec_picture->ref_idx[LIST_1][j4][i4] = -1;
                
              }
              
              if (fw_rFrame < 0 && bw_rFrame < 0)
              {
                dec_picture->ref_idx[LIST_0][j4][i4] = 0;
                dec_picture->ref_idx[LIST_1][j4][i4] = 0;
              }
              
              fw_refframe = (dec_picture->ref_idx[LIST_0][j4][i4]!=-1) ? dec_picture->ref_idx[LIST_0][j4][i4]:0;
              bw_refframe = (dec_picture->ref_idx[LIST_1][j4][i4]!=-1) ? dec_picture->ref_idx[LIST_1][j4][i4]:0;
              
              fw_ref_idx = fw_refframe;
              bw_ref_idx = bw_refframe;
              
              if      (dec_picture->ref_idx[LIST_1][j4][i4]==-1) direct_pdir = 0;
              else if (dec_picture->ref_idx[LIST_0][j4][i4]==-1) direct_pdir = 1;
              else                                               direct_pdir = 2;
              
            }
            else // Temporal Mode
            {
              
              int imgblock_y= ((img->MbaffFrameFlag)&&(currMB->mb_field))? (img->current_mb_nr%2) ? (img->block_y-4)/2:img->block_y/2: img->block_y;
              int j6= imgblock_y + j;
              
              int refList = (co_located_ref_idx[LIST_0][j6][i4]== -1 ? LIST_1 : LIST_0);
              int ref_idx =  co_located_ref_idx[refList][j6][i4];

              
              if(ref_idx==-1) // co-located is intra mode
              {
                for(hv=0; hv<2; hv++)
                {
                  dec_picture->mv  [LIST_0][j4][i4][hv]=0;
                  dec_picture->mv  [LIST_1][j4][i4][hv]=0;                    
                }
                
                dec_picture->ref_idx[LIST_0][j4][i4] = 0;
                dec_picture->ref_idx[LIST_1][j4][i4] = 0;
                
                fw_refframe = 0;
                fw_ref_idx = 0;
              }
              else // co-located skip or inter mode
              {
                int mapped_idx=0;
                int iref;          
                
                {
                  for (iref=0;iref<min(img->num_ref_idx_l0_active,listXsize[LIST_0 + list_offset]);iref++)
                  {
#if 1
                    if(img->structure==0 && curr_mb_field==0)
                    {
                      // If the current MB is a frame MB and the colocated is from a field picture, 
                      // then the co_located_ref_id may have been generated from the wrong value of 
                      // frame_poc if it references it's complementary field, so test both POC values
                      if(listX[0][iref]->top_poc*2 == co_located_ref_id[refList][j6][i4] || listX[0][iref]->bottom_poc*2 == co_located_ref_id[refList][j6][i4])
                      {
                        mapped_idx=iref;
                        break;
                      }
                      else //! invalid index. Default to zero even though this case should not happen
                        mapped_idx=INVALIDINDEX;
                      continue;
                    }    
#endif                                        
                    if (dec_picture->ref_pic_num[img->current_slice_nr][LIST_0 + list_offset][iref]==co_located_ref_id[refList][j6][i4])
                    {
                      mapped_idx=iref;
                      break;
                    }
                    else //! invalid index. Default to zero even though this case should not happen
                    {                        
                      mapped_idx=INVALIDINDEX;
                    }
                  }
                  if (INVALIDINDEX == mapped_idx)
                  {
                    error("temporal direct error\ncolocated block has ref that is unavailable",-1111);
                  }
                }
                
                fw_ref_idx = mapped_idx;
                mv_scale = img->mvscale[LIST_0 + list_offset][mapped_idx];
                
                //! In such case, an array is needed for each different reference.
                if (mv_scale == 9999 || listX[LIST_0+list_offset][mapped_idx]->is_long_term)
                {
                  dec_picture->mv  [LIST_0][j4][i4][0]=co_located_mv[refList][j6][i4][0];
                  dec_picture->mv  [LIST_0][j4][i4][1]=co_located_mv[refList][j6][i4][1];

                  dec_picture->mv  [LIST_1][j4][i4][0]=0;
                  dec_picture->mv  [LIST_1][j4][i4][1]=0;
                }
                else
                {
                  dec_picture->mv  [LIST_0][j4][i4][0]=(mv_scale * co_located_mv[refList][j6][i4][0] + 128 ) >> 8;
                  dec_picture->mv  [LIST_0][j4][i4][1]=(mv_scale * co_located_mv[refList][j6][i4][1] + 128 ) >> 8;
                  
                  dec_picture->mv  [LIST_1][j4][i4][0]=dec_picture->mv  [LIST_0][j4][i4][0] - co_located_mv[refList][j6][i4][0] ;
                  dec_picture->mv  [LIST_1][j4][i4][1]=dec_picture->mv  [LIST_0][j4][i4][1] - co_located_mv[refList][j6][i4][1] ;
                }
                
                fw_refframe = dec_picture->ref_idx[LIST_0][j4][i4] = mapped_idx; //listX[1][0]->ref_idx[refList][j4][i4];
                bw_refframe = dec_picture->ref_idx[LIST_1][j4][i4] = 0;
                
                fw_ref_idx = fw_refframe;
                bw_ref_idx = bw_refframe;
              }
            }
            // store reference picture ID determined by direct mode
            dec_picture->ref_pic_id[LIST_0][j4][i4] = dec_picture->ref_pic_num[img->current_slice_nr][LIST_0 + list_offset][(short)dec_picture->ref_idx[LIST_0][j4][i4]];
            dec_picture->ref_pic_id[LIST_1][j4][i4] = dec_picture->ref_pic_num[img->current_slice_nr][LIST_1 + list_offset][(short)dec_picture->ref_idx[LIST_1][j4][i4]];  
          }
                 
          if (mv_mode==0 && img->direct_spatial_mv_pred_flag )
          {
            if (dec_picture->ref_idx[LIST_0][j4][i4] >= 0)
            {
              
              vec1_x = i4*4*mv_mul + fw_mv_array[j4][i4][0];
              if (!curr_mb_field)
              {
                vec1_y = j4*4*mv_mul + fw_mv_array[j4][i4][1];
              }
              else
              {
                if (mb_nr%2 == 0)
                {
                  vec1_y = (img->block_y * 2 + joff) * mv_mul + fw_mv_array[j4][i4][1];
                }
                else
                {
                  vec1_y = ((img->block_y-4) * 2 + joff)* mv_mul + fw_mv_array[j4][i4][1];
                }
              }               
              get_block(fw_refframe, listX[0+list_offset], vec1_x, vec1_y, img, tmp_block);
            }
                  
            if (dec_picture->ref_idx[LIST_1][j4][i4] >= 0)
            {
              vec2_x = i4*4*mv_mul + bw_mv_array[j4][i4][0];
              if (!curr_mb_field)
              {
                vec2_y = j4*4*mv_mul + bw_mv_array[j4][i4][1];
              }
              else
              {
                if (mb_nr%2 == 0)
                {
                  vec2_y = (img->block_y * 2 + joff) * mv_mul + bw_mv_array[j4][i4][1];
                }
                else
                {
                  vec2_y = ((img->block_y-4) * 2 + joff)* mv_mul + bw_mv_array[j4][i4][1];
                }            
              }
              get_block(bw_refframe, listX[1+list_offset], vec2_x, vec2_y, img, tmp_blockbw);
            }              
          }
          else
          {
            vec1_x = i4*4*mv_mul + fw_mv_array[j4][i4][0];
            vec2_x = i4*4*mv_mul + bw_mv_array[j4][i4][0];
            
            if (!curr_mb_field)
            {
              vec1_y = j4*4*mv_mul + fw_mv_array[j4][i4][1];
              vec2_y = j4*4*mv_mul + bw_mv_array[j4][i4][1];
            }
            else
            {
              if (mb_nr%2 == 0)
              {
                vec1_y = (img->block_y * 2 + joff) * mv_mul + fw_mv_array[j4][i4][1];
                vec2_y = (img->block_y * 2 + joff) * mv_mul + bw_mv_array[j4][i4][1];
              }
              else
              {
                vec1_y = ((img->block_y-4) * 2 + joff)* mv_mul + fw_mv_array[j4][i4][1];
                vec2_y = ((img->block_y-4) * 2 + joff)* mv_mul + bw_mv_array[j4][i4][1];
              }
            }
            
            get_block(fw_refframe, listX[0+list_offset], vec1_x, vec1_y, img, tmp_block);
            get_block(bw_refframe, listX[1+list_offset], vec2_x, vec2_y, img, tmp_blockbw);
          }
          
          if (mv_mode==0 && img->direct_spatial_mv_pred_flag && direct_pdir==0)
          {
            if (img->apply_weights)
            {
              if (((active_pps->weighted_pred_flag&&(img->type==P_SLICE|| img->type == SP_SLICE))||
                (active_pps->weighted_bipred_idc==1 && (img->type==B_SLICE))) && curr_mb_field)
              {
                fw_ref_idx >>=1;
              }
              for(ii=0;ii<BLOCK_SIZE;ii++)
                for(jj=0;jj<BLOCK_SIZE;jj++)  
                  img->mpr[ii+ioff][jj+joff] = Clip1(((tmp_block[ii][jj] * img->wp_weight[0][fw_ref_idx][0]  
                                               + img->wp_round_luma)>>img->luma_log2_weight_denom) 
                                               + img->wp_offset[0][fw_refframe>>curr_mb_field][0]);
            }
            else
            {
              for(ii=0;ii<BLOCK_SIZE;ii++)
                for(jj=0;jj<BLOCK_SIZE;jj++)  
                  img->mpr[ii+ioff][jj+joff] = tmp_block[ii][jj];
            }
          }
          else if (mv_mode==0 && img->direct_spatial_mv_pred_flag && direct_pdir==1)
          {              
            if (img->apply_weights)
            {
              if (((active_pps->weighted_pred_flag&&(img->type==P_SLICE|| img->type == SP_SLICE))||
                (active_pps->weighted_bipred_idc==1 && (img->type==B_SLICE))) && curr_mb_field)
              {
                fw_ref_idx >>=1;
                bw_ref_idx >>=1;
              }

              for(ii=0;ii<BLOCK_SIZE;ii++)
                for(jj=0;jj<BLOCK_SIZE;jj++)  
                  img->mpr[ii+ioff][jj+joff] = Clip1(((tmp_blockbw[ii][jj] * img->wp_weight[1][bw_ref_idx][0] 
                                               + img->wp_round_luma)>>img->luma_log2_weight_denom) 
                                               + img->wp_offset[1][bw_refframe>>curr_mb_field][0]);
            }
            else
            {
              for(ii=0;ii<BLOCK_SIZE;ii++)
                for(jj=0;jj<BLOCK_SIZE;jj++)  
                  img->mpr[ii+ioff][jj+joff] = tmp_blockbw[ii][jj];
            }
          }
          else if(img->apply_weights)
          {
            int alpha_fw, alpha_bw;
            int wt_list_offset = (active_pps->weighted_bipred_idc==2)?list_offset:0;

            if (mv_mode==0 && img->direct_spatial_mv_pred_flag==0 )bw_ref_idx=0;    //temporal direct 

            if (((active_pps->weighted_pred_flag&&(img->type==P_SLICE|| img->type == SP_SLICE))||
              (active_pps->weighted_bipred_idc==1 && (img->type==B_SLICE))) && curr_mb_field)
            {
              fw_ref_idx >>=1;
              bw_ref_idx >>=1;
            }

            alpha_fw = img->wbp_weight[0+wt_list_offset][fw_ref_idx][bw_ref_idx][0];
            alpha_bw = img->wbp_weight[1+wt_list_offset][fw_ref_idx][bw_ref_idx][0];
            
            for(ii=0;ii<BLOCK_SIZE;ii++)
              for(jj=0;jj<BLOCK_SIZE;jj++)  
                img->mpr[ii+ioff][jj+joff] = (int)Clip1(((alpha_fw * tmp_block[ii][jj] + alpha_bw * tmp_blockbw[ii][jj]  
                                             + (1<<img->luma_log2_weight_denom)) >> (img->luma_log2_weight_denom+1)) 
                                             + ((img->wp_offset[wt_list_offset+0][fw_ref_idx][0] + img->wp_offset[wt_list_offset+1][bw_ref_idx][0] + 1) >>1));
          }
          else
          {
            for(ii=0;ii<BLOCK_SIZE;ii++)
              for(jj=0;jj<BLOCK_SIZE;jj++)  
                img->mpr[ii+ioff][jj+joff] = (tmp_block[ii][jj]+tmp_blockbw[ii][jj]+1)/2;
          }
        }
      }

      // =============== 4x4 itrans ================
      // -------------------------------------------
      if (smb && mv_mode!=IBLOCK)
      {
        itrans_sp(img,ioff,joff,i,j);
      }
      else
      {
        if(need_4x4_transform)
          itrans   (img,ioff,joff,i,j, 0);      // use DCT transform and make 4x4 block m7 from prediction block mpr
      }
      if(need_4x4_transform)
      {
        for(ii=0;ii<BLOCK_SIZE;ii++)
        {
          for(jj=0;jj<BLOCK_SIZE;jj++)
          {
            // Residue Color Transform
            if(!residue_transform_flag)
            {
              dec_picture->imgY[j4*BLOCK_SIZE+jj][i4*BLOCK_SIZE+ii]=img->m7[ii][jj]; // construct picture from 4x4 blocks
            } 
            else 
            {
              mprRGB[0][ii+ioff][jj+joff] = img->mpr[ii+ioff][jj+joff];
              rec_res[0][ii+ioff][jj+joff] = img->m7[ii][jj];
            }
          }
        }
      }// if(need_4x4_transform)
    }

    if(!need_4x4_transform)       
    {
      // =============== 8x8 itrans ================
      // -------------------------------------------
      ioff = 8*(block8x8%2);
      joff = 8*(block8x8/2);
      
      itrans8x8(img,ioff,joff);      // use DCT transform and make 8x8 block m7 from prediction block mpr
      
      for(ii=0;ii<8;ii++)
      {
        for(jj=0;jj<8;jj++)
        {
          // Residue Color Transform
          if(!residue_transform_flag)
          {
              dec_picture->imgY[img->pix_y + joff + jj][img->pix_x + ioff + ii]=img->m7[ii + ioff][jj + joff]; // construct picture from 4x4 blocks
          }
          else
          {
              mprRGB[0][ii+ioff][jj+joff] = img->mpr[ii+ioff][jj+joff];
              rec_res[0][ii+ioff][jj+joff] = img->m7[ii + ioff][jj + joff];
          }
        }
      }
    }
  }

  if (dec_picture->chroma_format_idc != YUV400)
  {
    // chroma decoding *******************************************************
    f1_x = 64/img->mb_cr_size_x;
    f2_x=f1_x-1;

    f1_y = 64/img->mb_cr_size_y;
    f2_y=f1_y-1;

    f3=f1_x*f1_y;
    f4=f3>>1;

    for(uv=0;uv<2;uv++)
    {
      uv_shift = uv*(img->num_blk8x8_uv/2);
      intra_prediction = IS_INTRA (currMB);

      if (intra_prediction)
      {
        intrapred_chroma(img, uv);
      }

      for (b8=0;b8<(img->num_blk8x8_uv/2);b8++)
      {
        for(b4=0;b4<4;b4++)
        {
          joff = subblk_offset_y[yuv][b8][b4];
          j4=img->pix_c_y+joff;
          ioff = subblk_offset_x[yuv][b8][b4];
          i4=img->pix_c_x+ioff;

          mv_mode  = currMB->b8mode[block8x8_idx[yuv][b8][b4]];
          pred_dir = currMB->b8pdir[block8x8_idx[yuv][b8][b4]];
          assert (pred_dir<=2);


          if (!intra_prediction)
          {
            if (pred_dir != 2)
            {
              //--- FORWARD/BACKWARD PREDICTION ---
              mv_array = dec_picture->mv[LIST_0 + pred_dir];
              list = listX[0+list_offset+pred_dir];
              for(jj=0;jj<4;jj++)
              {
                jf=(j4+jj)/(img->mb_cr_size_y/4);     // jf  = Subblock_y-coordinate
                for(ii=0;ii<4;ii++)
                {
                  ifx=(i4+ii)/(img->mb_cr_size_x/4);  // ifx = Subblock_x-coordinate
                  fw_refframe = ref_idx = dec_picture->ref_idx[LIST_0+pred_dir][jf][ifx];
                  i1=(i4+ii)*f1_x+mv_array[jf][ifx][0];

                  if (!curr_mb_field)
                    j1=(j4+jj)*f1_y+mv_array[jf][ifx][1];
                  else
                  {
                    if (mb_nr%2 == 0) 
                      j1=((img->pix_c_y/2)                   + jj + joff)*f1_y + mv_array[jf][ifx][1];
                    else
                      j1=((img->pix_c_y-img->mb_cr_size_y)/2 + jj + joff)*f1_y + mv_array[jf][ifx][1];
                  }

                  if (active_sps->chroma_format_idc == 1)
                    j1 += list[ref_idx]->chroma_vector_adjustment;

                  ii0=max (0, min (i1/f1_x,   img->width_cr-1));
                  jj0=max (0, min (j1/f1_y,   max_y_cr));
                  ii1=max (0, min ((i1+f2_x)/f1_x, img->width_cr-1));
                  jj1=max (0, min ((j1+f2_y)/f1_y, max_y_cr));
                
                  if1=(i1 & f2_x);
                  jf1=(j1 & f2_y);
                  if0=f1_x-if1;
                  jf0=f1_y-jf1;
                
                  if (img->apply_weights)
                  {
                    pred = (if0*jf0*list[ref_idx]->imgUV[uv][jj0][ii0]+
                            if1*jf0*list[ref_idx]->imgUV[uv][jj0][ii1]+
                            if0*jf1*list[ref_idx]->imgUV[uv][jj1][ii0]+
                            if1*jf1*list[ref_idx]->imgUV[uv][jj1][ii1]+f4)/f3;
                    if (((active_pps->weighted_pred_flag&&(img->type==P_SLICE|| img->type == SP_SLICE))||
                      (active_pps->weighted_bipred_idc==1 && (img->type==B_SLICE))) && curr_mb_field)
                    {
                      ref_idx >>=1;
                    }

                    img->mpr[ii+ioff][jj+joff] = Clip1_Chr(((img->wp_weight[pred_dir][ref_idx][uv+1] * pred  + img->wp_round_chroma)>>img->chroma_log2_weight_denom) + img->wp_offset[pred_dir][ref_idx][uv+1]);
                  }
                  else
                  {
                    img->mpr[ii+ioff][jj+joff]=(if0*jf0*list[ref_idx]->imgUV[uv][jj0][ii0]+
                                                if1*jf0*list[ref_idx]->imgUV[uv][jj0][ii1]+
                                                if0*jf1*list[ref_idx]->imgUV[uv][jj1][ii0]+
                                                if1*jf1*list[ref_idx]->imgUV[uv][jj1][ii1]+f4)/f3;
                  }
                }
              }
            }
            else
            {
              fw_mv_array = dec_picture->mv[LIST_0];
              bw_mv_array = dec_picture->mv[LIST_1];

              for(jj=0;jj<4;jj++)
              {
                jf=(j4+jj)/(img->mb_cr_size_y/4);     // jf  = Subblock_y-coordinate
                for(ii=0;ii<4;ii++)
                {
                  ifx=(i4+ii)/(img->mb_cr_size_x/4);  // ifx = Subblock_x-coordinate
                  direct_pdir = 2;

                  if (mv_mode == 0 && img->direct_spatial_mv_pred_flag)
                  {
                    //===== DIRECT PREDICTION =====
                    if (dec_picture->ref_idx[LIST_0][2*(jf/2)][(ifx/2)*2]!=-1)
                    {
                      fw_refframe = dec_picture->ref_idx[LIST_0][2*(jf/2)][(ifx/2)*2];
                      fw_ref_idx = fw_refframe;
                    }
                    if (dec_picture->ref_idx[LIST_1][2*(jf/2)][(ifx/2)*2]!=-1)
                    {
                      bw_refframe = dec_picture->ref_idx[LIST_1][2*(jf/2)][(ifx/2)*2];
                      bw_ref_idx = bw_refframe;
                    }

                    if      (dec_picture->ref_idx[LIST_1][2*(jf/2)][(ifx/2)*2]==-1) direct_pdir = 0;
                    else if (dec_picture->ref_idx[LIST_0][2*(jf/2)][(ifx/2)*2]==-1) direct_pdir = 1;

                    if (direct_pdir == 0 || direct_pdir == 2)
                    {
                      i1=(img->pix_c_x+ii+ioff)*f1_x+fw_mv_array[jf][ifx][0];
                    
                      if (!curr_mb_field)
                      {
                        j1=(img->pix_c_y+jj+joff)*f1_y+fw_mv_array[jf][ifx][1];
                      }
                      else
                      {
                        if (mb_nr%2 == 0) 
                          j1=((img->pix_c_y)/2                   + jj + joff)*f1_y + fw_mv_array[jf][ifx][1];
                        else
                          j1=((img->pix_c_y-img->mb_cr_size_y)/2 + jj + joff)*f1_y + fw_mv_array[jf][ifx][1];
                      }

                      if (active_sps->chroma_format_idc == 1)
                        j1 += listX[0+list_offset][fw_refframe]->chroma_vector_adjustment;
                    
                      ii0=max (0, min (i1/f1_x,   img->width_cr-1));
                      jj0=max (0, min (j1/f1_y,   max_y_cr));
                      ii1=max (0, min ((i1+f2_x)/f1_x, img->width_cr-1));
                      jj1=max (0, min ((j1+f2_y)/f1_y, max_y_cr));

                    
                      if1=(i1 & f2_x);
                      jf1=(j1 & f2_y);
                      if0=f1_x-if1;
                      jf0=f1_y-jf1;
                    
                      fw_pred=(if0*jf0*listX[0+list_offset][fw_refframe]->imgUV[uv][jj0][ii0]+
                               if1*jf0*listX[0+list_offset][fw_refframe]->imgUV[uv][jj0][ii1]+
                               if0*jf1*listX[0+list_offset][fw_refframe]->imgUV[uv][jj1][ii0]+
                               if1*jf1*listX[0+list_offset][fw_refframe]->imgUV[uv][jj1][ii1]+f4)/f3;
                    }
                    if (direct_pdir == 1 || direct_pdir == 2)
                    {
                      i1=(img->pix_c_x+ii+ioff)*f1_x+bw_mv_array[jf][ifx][0];
                    
                      if (!curr_mb_field)
                      {
                        j1=(img->pix_c_y+jj+joff)*f1_y+bw_mv_array[jf][ifx][1];
                      }
                      else
                      {
                        if (mb_nr%2 == 0) 
                          j1=((img->pix_c_y)/2                   + jj + joff)*f1_y + bw_mv_array[jf][ifx][1];
                        else
                          j1=((img->pix_c_y-img->mb_cr_size_y)/2 + jj + joff)*f1_y + bw_mv_array[jf][ifx][1];
                      }
                      if (active_sps->chroma_format_idc == 1)
                        j1 += listX[1+list_offset][bw_refframe]->chroma_vector_adjustment;

                      ii0=max (0, min (i1/f1_x,   img->width_cr-1));
                      jj0=max (0, min (j1/f1_y,   max_y_cr));
                      ii1=max (0, min ((i1+f2_x)/f1_x, img->width_cr-1));
                      jj1=max (0, min ((j1+f2_y)/f1_y, max_y_cr));
                    
                      if1=(i1 & f2_x);
                      jf1=(j1 & f2_y);
                      if0=f1_x-if1;
                      jf0=f1_y-jf1;
                
                      bw_pred=(if0*jf0*listX[1+list_offset][bw_refframe]->imgUV[uv][jj0][ii0]+
                               if1*jf0*listX[1+list_offset][bw_refframe]->imgUV[uv][jj0][ii1]+
                               if0*jf1*listX[1+list_offset][bw_refframe]->imgUV[uv][jj1][ii0]+
                               if1*jf1*listX[1+list_offset][bw_refframe]->imgUV[uv][jj1][ii1]+f4)/f3;
                    }

                  }
                  else
                  {
                    //===== BI-DIRECTIONAL PREDICTION =====
                    fw_refframe = dec_picture->ref_idx[LIST_0][jf][ifx];
                    bw_refframe = dec_picture->ref_idx[LIST_1][jf][ifx];

                    fw_ref_idx = fw_refframe;
                    bw_ref_idx = bw_refframe;

                    i1=(img->pix_c_x+ii+ioff)*f1_x+fw_mv_array[jf][ifx][0];

                    if (!curr_mb_field)
                    {
                      j1=(img->pix_c_y+jj+joff)*f1_y+fw_mv_array[jf][ifx][1];
                    }
                    else
                    {
                      if (mb_nr%2 == 0) 
                        j1=((img->pix_c_y)/2                   + jj + joff)*f1_y + fw_mv_array[jf][ifx][1];
                      else
                        j1=((img->pix_c_y-img->mb_cr_size_y)/2 + jj + joff)*f1_y + fw_mv_array[jf][ifx][1];
                    }

                    if (active_sps->chroma_format_idc == 1)
                      j1 += listX[0+list_offset][fw_refframe]->chroma_vector_adjustment;

                    ii0=max (0, min (i1/f1_x,   img->width_cr-1));
                    jj0=max (0, min (j1/f1_y,   max_y_cr));
                    ii1=max (0, min ((i1+f2_x)/f1_x, img->width_cr-1));
                    jj1=max (0, min ((j1+f2_y)/f1_y, max_y_cr));
                  
                    if1=(i1 & f2_x);
                    jf1=(j1 & f2_y);
                    if0=f1_x-if1;
                    jf0=f1_y-jf1;
                  
                    fw_pred=(if0*jf0*listX[0+list_offset][fw_refframe]->imgUV[uv][jj0][ii0]+
                             if1*jf0*listX[0+list_offset][fw_refframe]->imgUV[uv][jj0][ii1]+
                             if0*jf1*listX[0+list_offset][fw_refframe]->imgUV[uv][jj1][ii0]+
                             if1*jf1*listX[0+list_offset][fw_refframe]->imgUV[uv][jj1][ii1]+f4)/f3;
                  
                    i1=(img->pix_c_x+ii+ioff)*f1_x+bw_mv_array[jf][ifx][0];
                  
                    if (!curr_mb_field)
                    {
                      j1=(img->pix_c_y+jj+joff)*f1_y+bw_mv_array[jf][ifx][1];
                    }
                    else
                    {
                      if (mb_nr%2 == 0) 
                        j1=((img->pix_c_y)/2                   + jj + joff)*f1_y + bw_mv_array[jf][ifx][1];
                      else
                        j1=((img->pix_c_y-img->mb_cr_size_y)/2 + jj + joff)*f1_y + bw_mv_array[jf][ifx][1];
                    }

                    if (active_sps->chroma_format_idc == 1)
                      j1 += listX[1+list_offset][bw_refframe]->chroma_vector_adjustment;

                    ii0=max (0, min (i1/f1_x,   img->width_cr-1));
                    jj0=max (0, min (j1/f1_y,   max_y_cr));
                    ii1=max (0, min ((i1+f2_x)/f1_x, img->width_cr-1));
                    jj1=max (0, min ((j1+f2_y)/f1_y, max_y_cr));
                  
                    if1=(i1 & f2_x);
                    jf1=(j1 & f2_y);
                    if0=f1_x-if1;
                    jf0=f1_y-jf1;
                  
                    bw_pred=(if0*jf0*listX[1+list_offset][bw_refframe]->imgUV[uv][jj0][ii0]+
                             if1*jf0*listX[1+list_offset][bw_refframe]->imgUV[uv][jj0][ii1]+
                             if0*jf1*listX[1+list_offset][bw_refframe]->imgUV[uv][jj1][ii0]+
                             if1*jf1*listX[1+list_offset][bw_refframe]->imgUV[uv][jj1][ii1]+f4)/f3;
                  
                  }

                  if (img->apply_weights)
                  {
                    if (((active_pps->weighted_pred_flag&&(img->type==P_SLICE|| img->type == SP_SLICE))||
                      (active_pps->weighted_bipred_idc==1 && (img->type==B_SLICE))) && curr_mb_field)
                    {
                      fw_ref_idx >>=1;
                      bw_ref_idx >>=1;
                    }

                    if (img->direct_spatial_mv_pred_flag && direct_pdir==1)
                    {
                      img->mpr[ii+ioff][jj+joff]= Clip1_Chr(((img->wp_weight[1][bw_ref_idx][uv+1] * bw_pred  + img->wp_round_chroma)>>img->chroma_log2_weight_denom) + img->wp_offset[1][bw_refframe>>curr_mb_field][uv+1]);   // Replaced with integer only operations
                    }
                    else if (img->direct_spatial_mv_pred_flag && direct_pdir==0)
                    {
                      img->mpr[ii+ioff][jj+joff]=Clip1_Chr(((img->wp_weight[0][fw_ref_idx][uv+1] * fw_pred + img->wp_round_chroma)>>img->chroma_log2_weight_denom) + img->wp_offset[0][fw_refframe>>curr_mb_field][uv+1]);   // Replaced with integer only operations
                    }
                    else
                    {
                      int wt_list_offset = (active_pps->weighted_bipred_idc==2)?list_offset:0;

                      int alpha_fw = img->wbp_weight[0+wt_list_offset][fw_ref_idx][bw_ref_idx][uv+1];
                      int alpha_bw = img->wbp_weight[1+wt_list_offset][fw_ref_idx][bw_ref_idx][uv+1];

                      img->mpr[ii+ioff][jj+joff]= Clip1_Chr(((alpha_fw * fw_pred + alpha_bw * bw_pred  + (1<<img->chroma_log2_weight_denom)) >> (img->chroma_log2_weight_denom + 1))+ ((img->wp_offset[wt_list_offset + 0][fw_ref_idx][uv+1] + img->wp_offset[wt_list_offset + 1][bw_ref_idx][uv+1] + 1)>>1) );
                    }
                  }
                  else
                  {
                    if (img->direct_spatial_mv_pred_flag && direct_pdir==1)
                    {
                      img->mpr[ii+ioff][jj+joff]=bw_pred;
                    }
                    else if (img->direct_spatial_mv_pred_flag && direct_pdir==0)
                    {
                      img->mpr[ii+ioff][jj+joff]=fw_pred;
                    } 
                    else
                    {
                      img->mpr[ii+ioff][jj+joff]=(fw_pred + bw_pred + 1 )/2;
                    }
                  }
                }
              }
            }
          } //if (!intra_prediction)

          if (!smb)
          {
            itrans(img,ioff,joff, cofuv_blk_x[yuv][b8+uv_shift][b4], cofuv_blk_y[yuv][b8+uv_shift][b4], 1);
            for(ii=0;ii<4;ii++)
              for(jj=0;jj<4;jj++)
              {
                // Residue Color Transform
                if(!residue_transform_flag)
                {
                  dec_picture->imgUV[uv][j4+jj][i4+ii]=img->m7[ii][jj];
                } else
                {
                  mprRGB[uv+1][ii+ioff][jj+joff] = img->mpr[ii+ioff][jj+joff];
                  rec_res[uv+1][ii+ioff][jj+joff] = img->m7[ii][jj];
                }
              }
          }
        }
      }
    
      if(smb)
      {
        itrans_sp_chroma(img,2*uv);
        for (j=4;j<6;j++)
        {
          joff=(j-4)*4;
          j4=img->pix_c_y+joff;
          for(i=0;i<2;i++)
          {
            ioff=i*4;
            i4=img->pix_c_x+ioff;
            itrans(img,ioff,joff,2*uv+i,j, 1);

            for(ii=0;ii<4;ii++)
              for(jj=0;jj<4;jj++)
              {
                dec_picture->imgUV[uv][j4+jj][i4+ii]=img->m7[ii][jj];
              }
          }
        }
      }
    }  
  }

  // Residue Color Transform
  if(residue_transform_flag)
  {
    if(currMB->mb_type != I8MB)
    {
      for(k=0;k<16;k++)
      {
        
        i = (decode_block_scan[k] & 3);
        j = ((decode_block_scan[k] >> 2) & 3);
        
        ioff=i*4;
        i4=img->block_x+i;
        
        joff=j*4;
        j4=img->block_y+j;
        
        mv_mode  = currMB->b8mode[2*(j/2)+(i/2)];
        pred_dir = currMB->b8pdir[2*(j/2)+(i/2)];
        
        assert (pred_dir<=2);
        
        // PREDICTION
        if (mv_mode==IBLOCK)
        {
          //===== INTRA PREDICTION =====
          if (intrapred(img,ioff,joff,i4,j4)==SEARCH_SYNC)  /* make 4x4 prediction block mpr from given prediction img->mb_mode */
            return SEARCH_SYNC;                   /* bit error */
          
          for(ii=0;ii<4;ii++)
            for(jj=0;jj<4;jj++)
            {
              mprRGB[0][ii+ioff][jj+joff] = img->mpr[ii+ioff][jj+joff];
            }
        }
        
        for(jj=0;jj<BLOCK_SIZE;jj++)
        {
          for(ii=0;ii<BLOCK_SIZE;ii++)
          {
            /* Inverse Residue Transform */
            temp      = rec_res[0][ii+ioff][jj+joff]-(rec_res[1][ii+ioff][jj+joff]>>1);
            residue_G = rec_res[1][ii+ioff][jj+joff]+temp;
            residue_B = temp - (rec_res[2][ii+ioff][jj+joff]>>1);
            residue_R = residue_B+rec_res[2][ii+ioff][jj+joff];
            
            dec_picture->imgUV[0][j4*BLOCK_SIZE+jj][i4*BLOCK_SIZE+ii] = min(img->max_imgpel_value_uv,max(0,residue_B+mprRGB[1][ii+ioff][jj+joff]));
            dec_picture->imgY[j4*BLOCK_SIZE+jj][i4*BLOCK_SIZE+ii]     = min(img->max_imgpel_value,max(0,residue_G+mprRGB[0][ii+ioff][jj+joff]));
            dec_picture->imgUV[1][j4*BLOCK_SIZE+jj][i4*BLOCK_SIZE+ii] = min(img->max_imgpel_value_uv,max(0,residue_R+mprRGB[2][ii+ioff][jj+joff]));
          }
        }
      }// for(k=0;k<16;k++)
    }
    else // currMB->b8mode[block8x8] == I8MB
    {
      for(block8x8=0; block8x8<4; block8x8++)
      {
        
        //=========== 8x8 BLOCK TYPE ============
        ioff = 8*(block8x8%2);
        joff = 8*(block8x8/2);
        
        //PREDICTION
        intrapred8x8(img, block8x8);
        for(ii=0;ii<8;ii++)
          for(jj=0;jj<8;jj++)
            mprRGB[0][ii+ioff][jj+joff] = img->mpr[ii+ioff][jj+joff];
          
        for(jj=0;jj<8;jj++)
          for(ii=0;ii<8;ii++)
          {
            /* Inverse Residue Transform */
            temp      = rec_res[0][ii+ioff][jj+joff]-(rec_res[1][ii+ioff][jj+joff]>>1);
            residue_G = rec_res[1][ii+ioff][jj+joff]+temp;
            residue_B = temp - (rec_res[2][ii+ioff][jj+joff]>>1);
            residue_R = residue_B+rec_res[2][ii+ioff][jj+joff];
            
            dec_picture->imgUV[0][img->pix_y+joff+jj][img->pix_x+ioff+ii] = min(img->max_imgpel_value_uv,max(0,residue_B+mprRGB[1][ii+ioff][jj+joff]));
            dec_picture->imgY[img->pix_y+joff+jj][img->pix_x+ioff+ii]     = min(img->max_imgpel_value,max(0,residue_G+mprRGB[0][ii+ioff][jj+joff]));
            dec_picture->imgUV[1][img->pix_y+joff+jj][img->pix_x+ioff+ii] = min(img->max_imgpel_value_uv,max(0,residue_R+mprRGB[2][ii+ioff][jj+joff]));
          }
      }
    }
  }

  return 0;
}
