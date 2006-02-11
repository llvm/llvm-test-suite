
/*!
 **************************************************************************************
 * \file
 *    slice.c
 * \brief
 *    generate the slice header, setup the bit buffer for slices,
 *    and generates the slice NALU(s)

 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *      - Thomas Stockhammer            <stockhammer@ei.tum.de>
 *      - Detlev Marpe                  <marpe@hhi.de>
 *      - Stephan Wenger                <stewe@cs.tu-berlin.de>
 *      - Alexis Michael Tourapis       <alexismt@ieee.org>
 ***************************************************************************************
 */

#include "contributors.h"

#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <float.h>

#include "global.h"
#include "header.h"
#include "rtp.h"
#include "fmo.h"
#include "vlc.h"
#include "image.h"
#include "cabac.h"
#include "elements.h"
#include "epzs.h"

// Local declarations
static Slice *malloc_slice();
static void  free_slice(Slice *slice);
static void  init_slice(int start_mb_addr);
static void set_ref_pic_num();
extern ColocatedParams *Co_located;
extern StorablePicture **listX[6];
void poc_ref_pic_reorder(StorablePicture **list, unsigned num_ref_idx_lX_active, int *reordering_of_pic_nums_idc, int *abs_diff_pic_num_minus1, int *long_term_pic_idx, int weighted_prediction, int list_no);
void SetLagrangianMultipliers();

/*!
 ************************************************************************
 * \brief
 *    init_ref_pic_list_reordering initializations should go here
 ************************************************************************
 */
void init_ref_pic_list_reordering()
{
  Slice* currSlice = img->currentSlice;

  currSlice->ref_pic_list_reordering_flag_l0 = 0;
  currSlice->ref_pic_list_reordering_flag_l1 = 0;
}


/*!
 ************************************************************************
 *  \brief
 *     This function generates the slice (and partition) header(s) 
 *
 *  \return number of bits used for the slice (and partition) header(s)
 *
 *  \par Side effects:
 *      Adds slice/partition header symbols to the symbol buffer
 *      increments Picture->no_slices, allocates memory for the
 *      slice, sets img->currSlice
 ************************************************************************
*/
int start_slice()
{
  EncodingEnvironmentPtr eep;
  Slice *currSlice = img->currentSlice;
  Bitstream *currStream;
  int header_len = 0;
  int i;
  int NumberOfPartitions = (input->partition_mode == PAR_DP_1?1:3);

  //one  partition for IDR img
  if(img->currentPicture->idr_flag)
  {
     NumberOfPartitions = 1;
  }

  RTPUpdateTimestamp (img->tr);   // this has no side effects, just leave it for all NALs

  for (i=0; i<NumberOfPartitions; i++)
  {
    currStream = (currSlice->partArr[i]).bitstream;

    currStream->write_flag = 0;
    if (i==0)     // First partition
      header_len += SliceHeader (0);
    else          // Second/Third partition
      header_len += Partition_BC_Header(i);
     
    //! Initialize CABAC
    if (input->symbol_mode == CABAC)
    {
      eep = &((currSlice->partArr[i]).ee_cabac);
      if (currStream->bits_to_go != 8)
        header_len+=currStream->bits_to_go;
      writeVlcByteAlign(currStream);
      arienco_start_encoding(eep, currStream->streamBuffer, &(currStream->byte_pos));
      cabac_new_slice();
    } 
    else 
    {
      // Initialize CA-VLC
      CAVLC_init();
    }
  }
  if(input->symbol_mode == CABAC)
  {
    init_contexts();
  }
  return header_len;
}



/*!
 ************************************************************************
 * \brief
 *    This function terminates a slice (but doesn't write it out), 
 *    the old terminate_slice (0)
 * \return
 *    0 if OK,                                                         \n
 *    1 in case of error
 *
 ************************************************************************
 */
int terminate_slice(int lastslice)
{
  static int MbWidthC  [4]= { 0, 8, 8,  16};
  static int MbHeightC [4]= { 0, 8, 16, 16};

  int bytes_written;
  Bitstream *currStream;
  Slice *currSlice = img->currentSlice;
  EncodingEnvironmentPtr eep;
  int i;
  int byte_pos_before_startcode_emu_prevention;
  int min_num_bytes=0;
  int stuffing_bytes=0;
  int RawMbBits;

  if (input->symbol_mode == CABAC)
    write_terminating_bit (1);      // only once, not for all partitions
  
  for (i=0; i<currSlice->max_part_nr; i++)
  {
    currStream = (currSlice->partArr[i]).bitstream;
    if (input->symbol_mode == UVLC)
    {
      SODBtoRBSP(currStream);
      byte_pos_before_startcode_emu_prevention = currStream->byte_pos;
      currStream->byte_pos = RBSPtoEBSP(currStream->streamBuffer, 0 , currStream->byte_pos, 0);
      *(stats->em_prev_bits) += (currStream->byte_pos - byte_pos_before_startcode_emu_prevention) * 8;
    }
    else     // CABAC
    {
      eep = &((currSlice->partArr[i]).ee_cabac);
      // terminate the arithmetic code
      arienco_done_encoding(eep);
      currStream->bits_to_go = eep->Ebits_to_go;
      currStream->byte_buf = 0;
      bytes_written = currStream->byte_pos;
      img->bytes_in_picture += currStream->byte_pos;

      byte_pos_before_startcode_emu_prevention= currStream->byte_pos;
      if (lastslice && i==((currSlice->max_part_nr-1)))
      {
        RawMbBits = 256 * img->bitdepth_luma + 2 * MbWidthC[active_sps->chroma_format_idc] * MbHeightC[active_sps->chroma_format_idc] * img->bitdepth_chroma;
        min_num_bytes = ((96 * get_pic_bin_count()) - (RawMbBits * (int)img->PicSizeInMbs *3) + 1023) / 1024;
        if (min_num_bytes>img->bytes_in_picture)
        {
          stuffing_bytes = min_num_bytes - img->bytes_in_picture;
          printf ("CABAC stuffing words = %6d\n", stuffing_bytes/3);
        }
      }

//      printf ("bytepos: %d\n", currStream->byte_pos);
      currStream->byte_pos = RBSPtoEBSP(currStream->streamBuffer, 0, currStream->byte_pos, currStream->byte_pos + stuffing_bytes);
      *(stats->em_prev_bits) += (currStream->byte_pos - byte_pos_before_startcode_emu_prevention) * 8;
    }           // CABAC
  }           // partition loop
  if( input->symbol_mode == CABAC )
  {
    store_contexts();
  }
  return 0;   
}

/*!
************************************************************************
* \brief
*    Encodes one slice
* \par
*   returns the number of coded MBs in the SLice 
************************************************************************
*/
int encode_one_slice (int SliceGroupId, Picture *pic, int TotalCodedMBs)
{
  Boolean end_of_slice = FALSE;
  Boolean recode_macroblock;
  int len;
  int NumberOfCodedMBs = 0;
  int CurrentMbAddr;
  double FrameRDCost = DBL_MAX, FieldRDCost = DBL_MAX;
  
  img->cod_counter = 0;

  CurrentMbAddr = FmoGetFirstMacroblockInSlice (SliceGroupId);
// printf ("\n\nEncode_one_slice: PictureID %d SliceGroupId %d  SliceID %d  FirstMB %d \n", img->tr, SliceGroupId, img->current_slice_nr, CurrentMbInScanOrder);

  init_slice (CurrentMbAddr);
  Bytes_After_Header = img->currentSlice->partArr[0].bitstream->byte_pos;

  SetLagrangianMultipliers();

  if (input->symbol_mode==CABAC)
  {
    SetCtxModelNumber ();
  }
  
  img->checkref = (input->rdopt && input->RestrictRef && (img->type==P_SLICE || img->type==SP_SLICE));

/*
  // Tian Dong: June 7, 2002 JVT-B042
  // When the pictures are put into different layers and subseq, not all the reference frames
  // in multi-frame buffer are valid for prediction. The acutual number of the valid reference
  // frames, fb->num_short_used, will be given by start_slice(sym).
  // Save the fb->short_used.
  if (input->NumFramesInELSubSeq)
    {
      short_used = fb->short_used;
    }
*/

  len = start_slice ();

  // Rate control
  img->NumberofHeaderBits +=len;

  // basic unit layer rate control
  if(img->BasicUnit<img->Frame_Total_Number_MB)
    img->NumberofBasicUnitHeaderBits +=len;

//  printf("short size, used, num-used: (%d,%d,%d)\n", fb->short_size, fb->short_used, fb->num_short_used);

/*
  // Tian Dong: June 7, 2002 JVT-B042
  if (input->NumFramesInELSubSeq)
    {
      fb->short_used = fb->num_short_used;
    }
*/
  // Update statistics
  stats->bit_slice += len;
  stats->bit_use_header[img->type] += len;
// printf ("\n\n");

  while (end_of_slice == FALSE) // loop over macroblocks
  {
    if (img->AdaptiveRounding && input->AdaptRndPeriod && (img->current_mb_nr % input->AdaptRndPeriod == 0))
    {
      CalculateOffsetParam();
      
      if(input->Transform8x8Mode)
      {
        CalculateOffset8Param();
      }
    }

    //sw paff
    if (!img->MbaffFrameFlag)
    {
      recode_macroblock = FALSE;
      rdopt = &rddata_top_frame_mb;   // store data in top frame MB 
      
      start_macroblock (CurrentMbAddr, FALSE);
      encode_one_macroblock ();

      write_one_macroblock (1);
      
      terminate_macroblock (&end_of_slice, &recode_macroblock);
      
//       printf ("encode_one_slice: mb %d,  slice %d,   bitbuf bytepos %d EOS %d\n", 
//       img->current_mb_nr, img->current_slice_nr, 
//       img->currentSlice->partArr[0].bitstream->byte_pos, end_of_slice);
      
      if (recode_macroblock == FALSE)       // The final processing of the macroblock has been done
      {
        CurrentMbAddr = FmoGetNextMBNr (CurrentMbAddr);
        if (CurrentMbAddr == -1)   // end of slice
        {
//          printf ("FMO End of Slice Group detected, current MBs %d, force end of slice\n", NumberOfCodedMBs+1);
          end_of_slice = TRUE;
        }
        NumberOfCodedMBs++;       // only here we are sure that the coded MB is actually included in the slice
        proceed2nextMacroblock (CurrentMbAddr);
      }
      else
      {
        //!Go back to the previous MB to recode it
        img->current_mb_nr = FmoGetPreviousMBNr(img->current_mb_nr);
        if(img->current_mb_nr == -1 )   // The first MB of the slice group  is too big,
                                        // which means it's impossible to encode picture using current slice bits restriction
        {
          snprintf (errortext, ET_SIZE, "Error encoding first MB with spcified parameter, bits of current MB may be too big");
          error (errortext, 300);
        }
      }
    }
    else                      // TBD -- Addition of FMO
    {
      
//! This following ugly code breaks slices, at least for a slice mode that accumulates a certain
//! number of bits into one slice.  
//! The suggested algorithm is as follows:
//!
//! SaveState (Bitstream, stats,  etc. etc.);
//! BitsForThisMBPairInFrameMode = CodeMB (Upper, FRAME_MODE) + CodeMB (Lower, FRAME_MODE);
//! DistortionForThisMBPairInFrameMode = CalculateDistortion(Upper) + CalculateDistortion (Lower);
//! RestoreState();
//! BitsForThisMBPairInFieldMode = CodeMB (Upper, FIELD_MODE) + CodeMB (Lower, FIELD_MODE);
//! DistortionForThisMBPairInFrameMode = CalculateDistortion(Upper) + CalculateDistortion (Lower);
//! FrameFieldMode = Decision (...)
//! RestoreState()
//! if (FrameFieldMode == FRAME) {
//!   CodeMB (Upper, FRAME); CodeMB (Lower, FRAME);
//! } else {
//!   CodeMB (Upper FIELD); CodeMB (Lower, FIELD);
//! }
//!
//! Open questions/issues:
//!   1. CABAC/CA-VLC state:  It seems that the CABAC/CA_VLC states are changed during the
//!      dummy encoding processes (for the R-D based selection), but that they are never
//!      reset, once the selection is made.  I believe that this breaks the MB-adaptive
//!      frame/field coding.  The necessary code for the state saves is readily available
//!      in macroblock.c, start_macroblock() and terminate_macroblock() (this code needs
//!      to be double checked that it works with CA-VLC as well
//!   2. would it be an option to allocate Bitstreams with zero data in them (or copy the
//!      already generated bitstream) for the "test coding"?  
      
      if (input->MbInterlace == ADAPTIVE_CODING)
      {
        //================ code MB pair as frame MB ================
        //----------------------------------------------------------
        recode_macroblock = FALSE;
        
        
        img->field_mode = 0;  // MB coded as frame
        img->top_field = 0;   // Set top field to 0
        
        //Rate control
        img->write_macroblock = 0;
        img->bot_MB = 0;   
        
        start_macroblock (CurrentMbAddr, FALSE);
        
        rdopt = &rddata_top_frame_mb; // store data in top frame MB 
        encode_one_macroblock ();     // code the MB as frame
        FrameRDCost = rdopt->min_rdcost;
        //***   Top MB coded as frame MB ***//

        //Rate control
        img->bot_MB = 1; //for Rate control
        
        // go to the bottom MB in the MB pair
        img->field_mode = 0;  // MB coded as frame  //GB
        
        start_macroblock (CurrentMbAddr+1, FALSE);
        rdopt = &rddata_bot_frame_mb; // store data in top frame MB
        encode_one_macroblock ();     // code the MB as frame
        FrameRDCost += rdopt->min_rdcost;

        //***   Bottom MB coded as frame MB ***//
      }

      if ((input->MbInterlace == ADAPTIVE_CODING) || (input->MbInterlace == FIELD_CODING))
      {
        //Rate control
        img->bot_MB = 0; 
        
        //=========== start coding the MB pair as a field MB pair =============
        //---------------------------------------------------------------------
        img->field_mode = 1;  // MB coded as frame
        img->top_field = 1;   // Set top field to 1
        img->buf_cycle <<= 1;
        input->num_ref_frames <<= 1;
        img->num_ref_idx_l0_active <<= 1;
        img->num_ref_idx_l0_active += 1;
        start_macroblock (CurrentMbAddr, TRUE);
        

        rdopt = &rddata_top_field_mb; // store data in top frame MB 
//        TopFieldIsSkipped = 0;        // set the top field MB skipped flag to 0
        encode_one_macroblock ();     // code the MB as frame
        FieldRDCost = rdopt->min_rdcost;
        //***   Top MB coded as field MB ***//
        //Rate control
        img->bot_MB = 1;//for Rate control

        img->top_field = 0;   // Set top field to 0
        start_macroblock (CurrentMbAddr+1, TRUE);
        rdopt = &rddata_bot_field_mb; // store data in top frame MB 
        encode_one_macroblock ();     // code the MB as frame
        FieldRDCost += rdopt->min_rdcost;
        //***   Bottom MB coded as field MB ***//
      }

      //Rate control
      img->write_macroblock_frame = 0;  //Rate control

      //=========== decide between frame/field MB pair ============
      //-----------------------------------------------------------
      if ((input->MbInterlace == ADAPTIVE_CODING) && (FrameRDCost < FieldRDCost))
      {
        img->field_mode = 0;
        img->buf_cycle >>= 1;
        input->num_ref_frames >>= 1;
        MBPairIsField = 0;
        img->num_ref_idx_l0_active -= 1;
        img->num_ref_idx_l0_active >>= 1;
        
        //Rate control
        img->write_macroblock_frame = 1;  //for Rate control
      }
      else
      {
        img->field_mode = 1;
        MBPairIsField = 1;
      }
      
      //Rate control
      img->write_macroblock = 1;//Rate control 
      
      if (MBPairIsField)
        img->top_field = 1;
      else
        img->top_field = 0;
      
      //Rate control
      img->bot_MB = 0;// for Rate control

      // go back to the Top MB in the MB pair
      start_macroblock (CurrentMbAddr, img->field_mode);
      
      rdopt =  img->field_mode ? &rddata_top_field_mb : &rddata_top_frame_mb;
      copy_rdopt_data (0);  // copy the MB data for Top MB from the temp buffers
      write_one_macroblock (1);     // write the Top MB data to the bitstream
      NumberOfCodedMBs++;   // only here we are sure that the coded MB is actually included in the slice
      terminate_macroblock (&end_of_slice, &recode_macroblock);     // done coding the Top MB 
      proceed2nextMacroblock (CurrentMbAddr);        // Go to next macroblock
      
      //Rate control
      img->bot_MB = 1;//for Rate control
      // go to the Bottom MB in the MB pair
      img->top_field = 0;
      start_macroblock (CurrentMbAddr+1, img->field_mode);

      rdopt = img->field_mode ? &rddata_bot_field_mb : &rddata_bot_frame_mb;
      copy_rdopt_data (1);  // copy the MB data for Bottom MB from the temp buffers
      
      write_one_macroblock (0);     // write the Bottom MB data to the bitstream
      NumberOfCodedMBs++;   // only here we are sure that the coded MB is actually included in the slice
      terminate_macroblock (&end_of_slice, &recode_macroblock);     // done coding the Top MB 
      proceed2nextMacroblock (CurrentMbAddr);        // Go to next macroblock
      
      if (MBPairIsField)    // if MB Pair was coded as field the buffer size variables back to frame mode
      {
        img->buf_cycle >>= 1;
        input->num_ref_frames >>= 1;
        img->num_ref_idx_l0_active -= 1;
        img->num_ref_idx_l0_active >>= 1;
      }
      img->field_mode = img->top_field = 0; // reset to frame mode
      
      
      // go to next MB pair, not next MB
      CurrentMbAddr = FmoGetNextMBNr (CurrentMbAddr);
      CurrentMbAddr = FmoGetNextMBNr (CurrentMbAddr);
      
      if (CurrentMbAddr == FmoGetLastCodedMBOfSliceGroup (FmoMB2SliceGroup (CurrentMbAddr)))
        end_of_slice = TRUE;        // just in case it does n't get set in terminate_macroblock
    }
  }  
/*
  // Tian Dong: June 7, 2002 JVT-B042
  // Restore the short_used
  if (input->NumFramesInELSubSeq)
    {
      fb->short_used = short_used;
    }
*/
  terminate_slice ( (NumberOfCodedMBs+TotalCodedMBs >= (int)img->PicSizeInMbs) );
  return NumberOfCodedMBs;
}



/*!
 ************************************************************************
 * \brief
 *    Initializes the parameters for a new slice and
 *     allocates the memory for the coded slice in the Picture structure
 *  \par Side effects:
 *      Adds slice/partition header symbols to the symbol buffer
 *      increments Picture->no_slices, allocates memory for the
 *      slice, sets img->currSlice
 ************************************************************************
 */
static void init_slice (int start_mb_addr)
{
  int i;
  Picture *currPic = img->currentPicture;
  DataPartition *dataPart;
  Bitstream *currStream;
  Slice *currSlice;

  img->current_mb_nr = start_mb_addr;

  // Allocate new Slice in the current Picture, and set img->currentSlice
  assert (currPic != NULL);
  currPic->no_slices++;
  
  if (currPic->no_slices >= MAXSLICEPERPICTURE)
    error ("Too many slices per picture, increase MAXSLICEPERPICTURE in global.h.", -1);

  currPic->slices[currPic->no_slices-1] = malloc_slice();
  currSlice = currPic->slices[currPic->no_slices-1];

  img->currentSlice = currSlice;

  currSlice->picture_id = img->tr % 256;
  currSlice->qp = img->qp;
  currSlice->start_mb_nr = start_mb_addr;
  currSlice->slice_too_big = dummy_slice_too_big;

  for (i = 0; i < currSlice->max_part_nr; i++)
  {
    dataPart = &(currSlice->partArr[i]);
    if (input->symbol_mode == UVLC)
      dataPart->writeSyntaxElement = writeSyntaxElement_UVLC;
    else
      dataPart->writeSyntaxElement = writeSyntaxElement_CABAC;
    
    currStream = dataPart->bitstream;
    currStream->bits_to_go = 8;
    currStream->byte_pos = 0;
    currStream->byte_buf = 0;
  }

  img->num_ref_idx_l0_active = active_pps->num_ref_idx_l0_active_minus1 + 1; 
  img->num_ref_idx_l1_active = active_pps->num_ref_idx_l1_active_minus1 + 1;

  // generate reference picture lists
  init_lists(img->type, img->structure);

  // assign list 0 size from list size
  img->num_ref_idx_l0_active = listXsize[0];
  img->num_ref_idx_l1_active = listXsize[1];
  
  // code now also considers fields. Issue whether we should account this within the appropriate input params directly
  if ((img->type == P_SLICE || img->type == SP_SLICE) && input->P_List0_refs)
  {
    img->num_ref_idx_l0_active = min(img->num_ref_idx_l0_active, input->P_List0_refs * ((img->structure !=0) + 1));
    listXsize[0] = min(listXsize[0], input->P_List0_refs * ((img->structure !=0) + 1));  
  }
  if (img->type == B_SLICE )
  {
    if (input->B_List0_refs)
    {
      img->num_ref_idx_l0_active = min(img->num_ref_idx_l0_active, input->B_List0_refs * ((img->structure !=0) + 1));
      listXsize[0] = min(listXsize[0], input->B_List0_refs * ((img->structure !=0) + 1));  
    }
    if (input->B_List1_refs)
    {
      
      img->num_ref_idx_l1_active = min(img->num_ref_idx_l1_active, input->B_List1_refs * ((img->structure !=0) + 1));
      listXsize[1] = min(listXsize[1], input->B_List1_refs * ((img->structure !=0) + 1));  
    }
  }

  //Perform memory management based on poc distances for PyramidCoding
  if (img->nal_reference_idc  && input->PyramidCoding && input->PocMemoryManagement && dpb.ref_frames_in_buffer==active_sps->num_ref_frames)
  {    
    poc_based_ref_management(img->frame_num);
  }

  if (input->EnableOpenGOP)
  {
    for (i = 0; i<listXsize[0]; i++)
    {    
      if (listX[0][i]->poc < img->last_valid_reference && img->ThisPOC > img->last_valid_reference)      
      {
        listXsize[0] = img->num_ref_idx_l0_active = max(1,i);
        break;
      }
    }
    
    for (i = 0; i<listXsize[1]; i++)
    {
      if (listX[1][i]->poc < img->last_valid_reference && img->ThisPOC > img->last_valid_reference)
      {
        listXsize[1] = img->num_ref_idx_l1_active = max(1,i);
        break;
      }
    }
  }

  init_ref_pic_list_reordering();

  //Perform reordering based on poc distances for PyramidCoding
  if (img->type==P_SLICE && input->PyramidCoding && input->PyramidRefReorder)
  {
    
    int i, num_ref;

    alloc_ref_pic_list_reordering_buffer(currSlice);
    
    if ((img->type != I_SLICE) && (img->type !=SI_SLICE))
    {
      for (i=0; i<img->num_ref_idx_l0_active + 1; i++)
      {
        currSlice->reordering_of_pic_nums_idc_l0[i] = 3;
        currSlice->abs_diff_pic_num_minus1_l0[i] = 0;
        currSlice->long_term_pic_idx_l0[i] = 0;
      }
      
      if (img->type == B_SLICE)
      {
        for (i=0; i<img->num_ref_idx_l1_active + 1; i++)
        {
          currSlice->reordering_of_pic_nums_idc_l1[i] = 3;
          currSlice->abs_diff_pic_num_minus1_l1[i] = 0;
          currSlice->long_term_pic_idx_l1[i] = 0;
        }
      }
    }
    
    if ((img->type != I_SLICE) && (img->type !=SI_SLICE))
    {
      num_ref = img->num_ref_idx_l0_active;
      poc_ref_pic_reorder(listX[LIST_0], 
                          num_ref, 
                          currSlice->reordering_of_pic_nums_idc_l0, 
                          currSlice->abs_diff_pic_num_minus1_l0, 
                          currSlice->long_term_pic_idx_l0, 0, LIST_0);
      
      //reference picture reordering
      reorder_ref_pic_list(listX[LIST_0], &listXsize[LIST_0], 
                           img->num_ref_idx_l0_active - 1, 
                           currSlice->reordering_of_pic_nums_idc_l0, 
                           currSlice->abs_diff_pic_num_minus1_l0, 
                           currSlice->long_term_pic_idx_l0);
      
		// This is not necessary since order is already poc based...  
      if (img->type == B_SLICE)
      {
        num_ref = img->num_ref_idx_l1_active;
        poc_ref_pic_reorder(listX[LIST_1], 
                            num_ref, 
                            currSlice->reordering_of_pic_nums_idc_l1, 
                            currSlice->abs_diff_pic_num_minus1_l1, 
                            currSlice->long_term_pic_idx_l1, 0, LIST_1);
        
        //reference picture reordering
        reorder_ref_pic_list(listX[LIST_1], &listXsize[LIST_1], 
                             img->num_ref_idx_l1_active - 1, 
                             currSlice->reordering_of_pic_nums_idc_l1, 
                             currSlice->abs_diff_pic_num_minus1_l1, 
                             currSlice->long_term_pic_idx_l1);
      }
    }
  }


  //if (img->MbaffFrameFlag)
  if (img->structure==FRAME)
    init_mbaff_lists();

  if (img->type != I_SLICE && (active_pps->weighted_pred_flag == 1 || (active_pps->weighted_bipred_idc > 0 && (img->type == B_SLICE))))
  {
  	if (img->type==P_SLICE || img->type==SP_SLICE)
    {
      if (input->GenerateMultiplePPS && input->RDPictureDecision)
      {
        if (enc_picture==enc_frame_picture2)
          estimate_weighting_factor_P_slice (0);
        else
          estimate_weighting_factor_P_slice (1);
      }
      else
        estimate_weighting_factor_P_slice (0);
      
    }
    else
       estimate_weighting_factor_B_slice ();
  }

  set_ref_pic_num();

  if (img->type == B_SLICE)
    compute_colocated(Co_located, listX);
  if (img->type != I_SLICE && input->FMEnable == 3)
    EPZSSliceInit(EPZSCo_located, listX);
}


/*!
 ************************************************************************
 * \brief
 *    Allocates a slice structure along with its dependent data structures
 * \return
 *    Pointer to a Slice
 ************************************************************************
 */
static Slice *malloc_slice()
{
  int i;
  DataPartition *dataPart;
  Slice *slice;

//  const int buffer_size = (img->width * img->height * 4); // AH 190202: There can be data expansion with 
                                                          // low QP values. So, we make sure that buffer 
                                                          // does not overflow. 4 is probably safe multiplier.
  const int buffer_size = 500 + img->FrameSizeInMbs * (128 + 256 * img->bitdepth_luma + 512 * img->bitdepth_chroma);
                                                          // KS: this is approx. max. allowed code picture size

  if ((slice = (Slice *) calloc(1, sizeof(Slice))) == NULL) no_mem_exit ("malloc_slice: slice structure");

  if (input->symbol_mode == CABAC)
    {
      // create all context models
      slice->mot_ctx = create_contexts_MotionInfo();
      slice->tex_ctx = create_contexts_TextureInfo();
    }

  slice->max_part_nr = input->partition_mode==0?1:3;

  //for IDR img there should be only one partition
  if(img->currentPicture->idr_flag)
    slice->max_part_nr = 1;
  
  assignSE2partition[0] = assignSE2partition_NoDP;
  //ZL 
  //for IDR img all the syntax element should be mapped to one partition        
  if(!img->currentPicture->idr_flag&&input->partition_mode==1)
    assignSE2partition[1] =  assignSE2partition_DP;
  else
    assignSE2partition[1] =  assignSE2partition_NoDP;        



  slice->num_mb = 0;          // no coded MBs so far

  if ((slice->partArr = (DataPartition *) calloc(slice->max_part_nr, sizeof(DataPartition))) == NULL) no_mem_exit ("malloc_slice: partArr");
  for (i=0; i<slice->max_part_nr; i++) // loop over all data partitions
  {
    dataPart = &(slice->partArr[i]);
    if ((dataPart->bitstream = (Bitstream *) calloc(1, sizeof(Bitstream))) == NULL) no_mem_exit ("malloc_slice: Bitstream");
    if ((dataPart->bitstream->streamBuffer = (byte *) calloc(buffer_size, sizeof(byte))) == NULL) no_mem_exit ("malloc_slice: StreamBuffer");
    // Initialize storage of bitstream parameters
  }
  return slice;
}


/*!
 ************************************************************************
 * \brief
 *    Memory frees of all Slice structures and of its dependent
 *    data structures
 * \par Input:
 *    Image Parameters struct struct img_par *img
 ************************************************************************
 */
void free_slice_list(Picture *currPic)
{
  int i;

  for (i=0; i<currPic->no_slices; i++)
  {
    free_slice (currPic->slices[i]);
    currPic->slices[i]=NULL;
  }
}


/*!
 ************************************************************************
 * \brief
 *    Memory frees of the Slice structure and of its dependent
 *    data structures
 * \param slice:
 *    Slice to be freed
 ************************************************************************
 */
static void free_slice(Slice *slice)
{
  int i;
  DataPartition *dataPart;

  if (slice != NULL)
  {
    for (i=0; i<slice->max_part_nr; i++) // loop over all data partitions
    {
      dataPart = &(slice->partArr[i]);
      if (dataPart != NULL)
      {
        if (dataPart->bitstream->streamBuffer != NULL)
          free(dataPart->bitstream->streamBuffer);
        if (dataPart->bitstream != NULL)
          free(dataPart->bitstream);
      }
    }
    if (slice->partArr != NULL)
      free(slice->partArr);
    if (input->symbol_mode == CABAC)
    {
      delete_contexts_MotionInfo(slice->mot_ctx);
      delete_contexts_TextureInfo(slice->tex_ctx);
    }

    free(slice);
  }
}


/*!
 ************************************************************************
 * \brief
 *    This function set the value of a bit in a bitstream to 1
 ************************************************************************
 */
void modify_redundant_pic_cnt(unsigned char *buffer)
{
  unsigned char tmp = 1 << (rpc_bits_to_go-1);
  buffer[rpc_bytes_to_go] |= tmp;
}

void set_ref_pic_num()
{
  int i,j;
  StorablePicture *this_ref;
  
  //! need to add field ref_pic_num that handles field pair.
  
  for (i=0;i<listXsize[LIST_0];i++)
  {
    this_ref = listX[LIST_0][i];
    enc_picture->ref_pic_num        [LIST_0][i] = this_ref->poc * 2 + ((this_ref->structure==BOTTOM_FIELD)?1:0) ; 
    enc_picture->frm_ref_pic_num    [LIST_0][i] = this_ref->frame_poc * 2; 
    enc_picture->top_ref_pic_num    [LIST_0][i] = this_ref->top_poc * 2; 
    enc_picture->bottom_ref_pic_num [LIST_0][i] = this_ref->bottom_poc * 2 + 1; 
  }
  
  for (i=0;i<listXsize[LIST_1];i++)
  {
    this_ref = listX[LIST_1][i];
    enc_picture->ref_pic_num        [LIST_1][i] = this_ref->poc  *2 + ((this_ref->structure==BOTTOM_FIELD)?1:0);
    enc_picture->frm_ref_pic_num    [LIST_1][i] = this_ref->frame_poc * 2; 
    enc_picture->top_ref_pic_num    [LIST_1][i] = this_ref->top_poc * 2; 
    enc_picture->bottom_ref_pic_num [LIST_1][i] = this_ref->bottom_poc * 2 + 1; 
  }
  
  if (!active_sps->frame_mbs_only_flag && img->structure==FRAME)
  {
    for (j=2;j<6;j++)
      for (i=0;i<listXsize[j];i++)
      {    
        this_ref = listX[j][i];
        enc_picture->ref_pic_num[j][i] = this_ref->poc * 2 + ((this_ref->structure==BOTTOM_FIELD)?1:0);
        enc_picture->frm_ref_pic_num[j][i] = this_ref->frame_poc * 2 ;
        enc_picture->top_ref_pic_num[j][i] = this_ref->top_poc * 2 ;
        enc_picture->bottom_ref_pic_num[j][i] = this_ref->bottom_poc * 2 + 1;
      }
  }
}

/*!
************************************************************************
* \brief
*    decide reference picture reordering, Frame only
************************************************************************
*/
void poc_ref_pic_reorder(StorablePicture **list, unsigned num_ref_idx_lX_active, int *reordering_of_pic_nums_idc, int *abs_diff_pic_num_minus1, int *long_term_pic_idx, int weighted_prediction, int list_no)
{
  unsigned i,j,k;
  
  int currPicNum, picNumLXPred;

  int default_order[32];
  int re_order[32];
  int tmp_reorder[32];
  int list_sign[32];
  int reorder_stop, no_reorder;
  int poc_diff[32];
  int tmp_value, diff;  

  int abs_poc_dist;
  int maxPicNum, MaxFrameNum = 1 << (log2_max_frame_num_minus4 + 4);
  
  if (img->structure==FRAME)
  {
    maxPicNum  = MaxFrameNum;
    currPicNum = img->frame_num;
  }
  else
  {
    maxPicNum  = 2 * MaxFrameNum;
    currPicNum = 2 * img->frame_num + 1;
  }
  
  picNumLXPred = currPicNum;
  
  // First assign default list order. 
  for (i=0; i<num_ref_idx_lX_active; i++)
  {
    default_order[i] = list[i]->pic_num;
  }
  
  // Now access all references in buffer and assign them
  // to a pottential reordering list. For each one of these 
  // references compute the poc distance compared to current
  // frame.
  for (i=0; i<dpb.ref_frames_in_buffer; i++)
  {
    re_order[i] = dpb.fs_ref[i]->frame->pic_num;
  
    if (dpb.fs_ref[i]->is_used==3 && (dpb.fs_ref[i]->frame->used_for_reference)&&(!dpb.fs_ref[i]->frame->is_long_term))
    {
      abs_poc_dist = abs(dpb.fs_ref[i]->frame->poc - enc_picture->poc) ;
      poc_diff[i] = abs_poc_dist;
      if (list_no == LIST_0)
      {
        list_sign[i] = (enc_picture->poc < dpb.fs_ref[i]->frame->poc) ? +1 : -1;
      }
      else
      {
        list_sign[i] = (enc_picture->poc > dpb.fs_ref[i]->frame->poc) ? +1 : -1;
      }
    }
  }
  
  
  // now sort these references based on poc (temporal) distance
  for (i=0; i< dpb.ref_frames_in_buffer-1; i++)
  {
    for (j=i+1; j< dpb.ref_frames_in_buffer; j++)
    {      
      if (poc_diff[i]>poc_diff[j] || (poc_diff[i] == poc_diff[j] && list_sign[j] > list_sign[i]))
      {
        
        tmp_value = poc_diff[i];
        poc_diff[i] = poc_diff[j];
        poc_diff[j] = tmp_value;
        tmp_value  = re_order[i];
        re_order[i] = re_order[j];
        re_order[j] = tmp_value ;
        tmp_value  = list_sign[i];
        list_sign[i] = list_sign[j];        
        list_sign[j] = tmp_value ;
      }
    }
  }
  
  // Check versus default list to see if any
  // change has happened
  no_reorder = 1;
  for (i=0; i<num_ref_idx_lX_active; i++)
  {
    if (default_order[i] != re_order[i])
    {
      no_reorder = 0;
    }
  }
  
  // If different, then signal reordering
  if (no_reorder==0)
  {
    for (i=0; i<num_ref_idx_lX_active; i++)
    {
      diff = re_order[i]-picNumLXPred;
      if (diff <= 0)
      {
        reordering_of_pic_nums_idc[i] = 0;
        abs_diff_pic_num_minus1[i] = abs(diff)-1;
        if (abs_diff_pic_num_minus1[i] < 0)
          abs_diff_pic_num_minus1[i] = maxPicNum -1; 
      }
      else
      {
        reordering_of_pic_nums_idc[i] = 1;
        abs_diff_pic_num_minus1[i] = abs(diff)-1;
      }
      picNumLXPred = re_order[i];
      
      tmp_reorder[i] = re_order[i];
      
      k = i;
      for (j=i; j<num_ref_idx_lX_active; j++)
      {
        if (default_order[j] != re_order[i])
        {
          ++k;
          tmp_reorder[k] = default_order[j];
        }
      }
      reorder_stop = 1;
      for(j=i+1; j<num_ref_idx_lX_active; j++)
      {
        if (tmp_reorder[j] != re_order[j])
        {
          reorder_stop = 0;
          break;
        }
      }
      
      if (reorder_stop==1)
      {
        ++i;
        break;
      }
      
      
      for(j=0; j<num_ref_idx_lX_active; j++)
      {
        default_order[j] = tmp_reorder[j];
      }
            
    }
    reordering_of_pic_nums_idc[i] = 3;
    
    for(j=0; j<num_ref_idx_lX_active; j++)
    {
      default_order[j] = tmp_reorder[j];
    }
    
    if (list_no==0)
    {
      img->currentSlice->ref_pic_list_reordering_flag_l0=1;
    }
    else
    {
      img->currentSlice->ref_pic_list_reordering_flag_l1=1;
    }
  }
}

extern int QP2QUANT[40];

void SetLagrangianMultipliers()
{
  int qp, j;
  double qp_temp;
  double lambda_scale = 1.0 - Clip3(0.0,0.5,0.05 * (double) input->jumpd);;
  
  if (input->rdopt) // RDOPT on computation of Lagrangian multipliers
  {
    for (j = 0; j < 5; j++)
    {
      for (qp = 0; qp < 52; qp++)
      {          
        qp_temp = max(0.0,(double)qp - SHIFT_QP);

        if (input->UseExplicitLambdaParams) // consideration of explicit weights.
        {
          img->lambda_md[j][qp] = input->LambdaWeight[j] * pow (2, img->bitdepth_lambda_scale + qp_temp/3.0);
          // Scale lambda due to hadamard qpel only consideration
          img->lambda_md[j][qp] = (input->hadamard == 2 ? 0.95 : 1.00) * img->lambda_md[j][qp];
          img->lambda_me[j][qp] = sqrt(img->lambda_md[j][qp]);
          img->lambda_mf[j][qp] = LAMBDA_FACTOR (img->lambda_me[j][qp]);
          if (j == B_SLICE)
          {
            img->lambda_md[5][qp] = input->LambdaWeight[5] * pow (2, img->bitdepth_lambda_scale + qp_temp/3.0);
            img->lambda_md[5][qp] = (input->hadamard == 2 ? 0.95 : 1.00) * img->lambda_md[5][qp];
            img->lambda_me[5][qp] = sqrt(img->lambda_md[5][qp]);
            img->lambda_mf[5][qp] = LAMBDA_FACTOR (img->lambda_me[5][qp]);
          }
        }
        else
        {                          
          if (input->successive_Bframe>0)
            img->lambda_md[j][qp] = 0.68 * pow (2, img->bitdepth_lambda_scale + qp_temp/3.0) 
            * (j == B_SLICE ? Clip3(2.00,4.00,(qp_temp / 6.0)) : (j == SP_SLICE) ? Clip3(1.4,3.0,(qp_temp / 12.0)) : 1.0);
          else
            img->lambda_md[j][qp] = 0.85 * pow (2, img->bitdepth_lambda_scale + qp_temp/3.0) 
            * ( (j == B_SLICE) ? 4.0 : (j == SP_SLICE) ? Clip3(1.4,3.0,(qp_temp / 12.0)) : 1.0);
          // Scale lambda due to hadamard qpel only consideration
          img->lambda_md[j][qp] = (input->hadamard == 2 ? 0.95 : 1.00) * img->lambda_md[j][qp];
          img->lambda_md[j][qp] = (j == B_SLICE && input->BRefPictures == 2 && img->b_frame_to_code == 0 ? 0.50 : 1.00) * img->lambda_md[j][qp];
          
          if (j == B_SLICE)
          {
            img->lambda_md[5][qp] = img->lambda_md[j][qp];

            if (input->PyramidCoding == 2)
              img->lambda_md[5][qp] *= (1.0 - min(0.4,0.2 * (double) gop_structure[img->b_frame_to_code-1].pyramid_layer)) ;
            else
              img->lambda_md[5][qp] *= 0.80;
            img->lambda_md[5][qp] *= lambda_scale;
            img->lambda_me[5][qp] = sqrt(img->lambda_md[5][qp]);
            img->lambda_mf[5][qp] = LAMBDA_FACTOR (img->lambda_me[5][qp]);
          }
          else
            img->lambda_md[j][qp] *= lambda_scale;

          img->lambda_me[j][qp] = sqrt(img->lambda_md[j][qp]);  
          img->lambda_mf[j][qp] = LAMBDA_FACTOR (img->lambda_me[j][qp]);
        }
      }
    }
  }
  else // RDOPT off computation of Lagrangian multipliers
  {
    for (j = 0; j < 6; j++)
    {
      for (qp = 0; qp < 52; qp++)
      {
        img->lambda_md[j][qp] = img->lambda_me[j][qp] = QP2QUANT[max(0,qp-SHIFT_QP)];
        img->lambda_mf[j][qp] = LAMBDA_FACTOR (img->lambda_me[j][qp]);
      }
    }
  }
}
 
