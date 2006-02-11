
/*!
 ***************************************************************************
 * \file rdopt_coding_state.c
 *
 * \brief
 *    Storing/restoring coding state for
 *    Rate-Distortion optimized mode decision
 *
 * \author
 *    Heiko Schwarz
 *
 * \date
 *    17. April 2001
 **************************************************************************/

#include <stdlib.h>
#include <memory.h>

#include "global.h"

#include "rdopt_coding_state.h"
#include "cabac.h"



/*!
 ************************************************************************
 * \brief
 *    delete structure for storing coding state
 ************************************************************************
 */
void
delete_coding_state (CSptr cs)
{
  if (cs != NULL)
  {
    //=== structures of data partition array ===
    if (cs->encenv    != NULL)   free (cs->encenv);
    if (cs->bitstream != NULL)   free (cs->bitstream);

    //=== contexts for binary arithmetic coding ===
    delete_contexts_MotionInfo  (cs->mot_ctx);
    delete_contexts_TextureInfo (cs->tex_ctx);

    //=== coding state structure ===
    free (cs);
    cs=NULL;
  }
}


/*!
 ************************************************************************
 * \brief
 *    create structure for storing coding state
 ************************************************************************
 */
CSptr
create_coding_state ()
{
  CSptr cs;

  //=== coding state structure ===
  if ((cs = (CSptr) calloc (1, sizeof(CSobj))) == NULL)
    no_mem_exit("init_coding_state: cs");

  //=== important variables of data partition array ===
  cs->no_part = input->partition_mode==0?1:3;
  if (input->symbol_mode == CABAC)
  {
    if ((cs->encenv = (EncodingEnvironment*) calloc (cs->no_part, sizeof(EncodingEnvironment))) == NULL)
      no_mem_exit("init_coding_state: cs->encenv");
  }
  else
  {
    cs->encenv = NULL;
  }
  if ((cs->bitstream = (Bitstream*) calloc (cs->no_part, sizeof(Bitstream))) == NULL)
    no_mem_exit("init_coding_state: cs->bitstream");

  //=== context for binary arithmetic coding ===
  cs->symbol_mode = input->symbol_mode;
  if (cs->symbol_mode == CABAC)
  {
    cs->mot_ctx = create_contexts_MotionInfo ();
    cs->tex_ctx = create_contexts_TextureInfo();
  }
  else
  {
    cs->mot_ctx = NULL;
    cs->tex_ctx = NULL;
  }

  return cs;
}


/*!
 ************************************************************************
 * \brief
 *    store coding state (for rd-optimized mode decision)
 ************************************************************************
 */
void
store_coding_state (CSptr cs)
{
  int  i;
  int  i_last = img->currentPicture->idr_flag? 1:cs->no_part; 
  Slice *currSlice = img->currentSlice;

  Macroblock *currMB  = &(img->mb_data [img->current_mb_nr]);
  
  
  if (!input->rdopt)  return;
  
  if (cs->symbol_mode==CABAC)
  {
    //=== important variables of data partition array ===
    //only one partition for IDR img
    for (i = 0; i < i_last; i++)
    {
      memcpy (&(cs->encenv[i]), &(currSlice->partArr[i].ee_cabac), sizeof(EncodingEnvironment));
      memcpy (&(cs->bitstream[i]), currSlice->partArr[i].bitstream, sizeof(Bitstream));
    }
    
    //=== contexts for binary arithmetic coding ===
    memcpy (cs->mot_ctx, currSlice->mot_ctx, sizeof(MotionInfoContexts));
    memcpy (cs->tex_ctx, currSlice->tex_ctx, sizeof(TextureInfoContexts));
    
  }
  else
  {
    //=== important variables of data partition array ===
    for (i = 0; i < i_last; i++)
    {    
      memcpy (&(cs->bitstream[i]), currSlice->partArr[i].bitstream, sizeof(Bitstream));
    }
  }
  //=== syntax element number and bitcounters ===
  cs->currSEnr = currMB->currSEnr;
  memcpy (cs->bitcounter, currMB->bitcounter, MAX_BITCOUNTER_MB * sizeof(int));
  
  //=== elements of current macroblock ===
  memcpy (cs->mvd, currMB->mvd, BLOCK_CONTEXT * sizeof(int));
  cs->cbp_bits = currMB->cbp_bits;
}


/*!
 ************************************************************************
 * \brief
 *    restore coding state (for rd-optimized mode decision)
 ************************************************************************
 */
void
reset_coding_state (CSptr cs)
{
  int  i;
  int  i_last = img->currentPicture->idr_flag? 1:cs->no_part; 
  Slice *currSlice = img->currentSlice;

  Macroblock *currMB  = &(img->mb_data [img->current_mb_nr]);
  
  if (!input->rdopt)  return;
  
  if (cs->symbol_mode==CABAC) 
  {
    //=== important variables of data partition array ===
    //only one partition for IDR img
    for (i = 0; i < i_last; i++)
    {
      //--- parameters of encoding environments ---
      memcpy (&(currSlice->partArr[i].ee_cabac), &(cs->encenv   [i]), sizeof(EncodingEnvironment));
      memcpy (currSlice->partArr[i].bitstream, &(cs->bitstream[i]), sizeof(Bitstream));
    }
    
    
    //=== contexts for binary arithmetic coding ===
    memcpy (currSlice->mot_ctx, cs->mot_ctx, sizeof(MotionInfoContexts));
    memcpy (currSlice->tex_ctx, cs->tex_ctx, sizeof(TextureInfoContexts));
    
  }
  else
  {
    //=== important variables of data partition array ===
    //only one partition for IDR img
    for (i = 0; i < i_last; i++)      
    {
      //--- parameters of encoding environments ---   
      memcpy (currSlice->partArr[i].bitstream, &(cs->bitstream[i]), sizeof(Bitstream));
    }
  }
  
  //=== syntax element number and bitcounters ===
  currMB->currSEnr = cs->currSEnr;
  memcpy (currMB->bitcounter, cs->bitcounter, MAX_BITCOUNTER_MB * sizeof(int));
  
  //=== elements of current macroblock ===
  memcpy (currMB->mvd, cs->mvd, BLOCK_CONTEXT * sizeof(int));
  currMB->cbp_bits = cs->cbp_bits;
}

