
/*!
 ***************************************************************************
 * \file
 *    cabac.h
 *
 * \brief
 *    Headerfile for entropy coding routines
 *
 * \author
 *    Detlev Marpe                                                         \n
 *    Copyright (C) 2000 HEINRICH HERTZ INSTITUTE All Rights Reserved.
 *
 * \date
 *    21. Oct 2000 (Changes by Tobias Oelbaum 28.08.2001)
 ***************************************************************************
 */


#ifndef _CABAC_H_
#define _CABAC_H_

// CABAC
int get_pic_bin_count();
void reset_pic_bin_count();

void arienco_start_encoding(EncodingEnvironmentPtr eep, unsigned char *code_buffer, int *code_len);
int  arienco_bits_written(EncodingEnvironmentPtr eep);
void arienco_done_encoding(EncodingEnvironmentPtr eep);
void biari_init_context (BiContextTypePtr ctx, const int* ini);
void rescale_cum_freq(BiContextTypePtr bi_ct);
void biari_encode_symbol(EncodingEnvironmentPtr eep, signed short symbol, BiContextTypePtr bi_ct );
void biari_encode_symbol_eq_prob(EncodingEnvironmentPtr eep, signed short symbol);
void biari_encode_symbol_final(EncodingEnvironmentPtr eep, signed short symbol);
MotionInfoContexts* create_contexts_MotionInfo(void);
TextureInfoContexts* create_contexts_TextureInfo(void);
void init_contexts_MotionInfo (MotionInfoContexts  *enco_ctx);
void init_contexts_TextureInfo(TextureInfoContexts *enco_ctx);
void delete_contexts_MotionInfo(MotionInfoContexts *enco_ctx);
void delete_contexts_TextureInfo(TextureInfoContexts *enco_ctx);
void writeHeaderToBuffer();
int  writeSyntaxElement_CABAC(SyntaxElement *se, DataPartition *this_dataPart);
void writeMB_typeInfo_CABAC(SyntaxElement *se, EncodingEnvironmentPtr eep_dp);
void writeIntraPredMode_CABAC(SyntaxElement *se, EncodingEnvironmentPtr eep_dp);
void writeB8_typeInfo_CABAC(SyntaxElement *se, EncodingEnvironmentPtr eep_dp);
void writeRefFrame2Buffer_CABAC(SyntaxElement *se, EncodingEnvironmentPtr eep_dp);
void writeRefFrame_CABAC(SyntaxElement *se, EncodingEnvironmentPtr eep_dp);
void writeMVD_CABAC(SyntaxElement *se, EncodingEnvironmentPtr eep_dp);
void writeCBP_CABAC(SyntaxElement *se, EncodingEnvironmentPtr eep_dp);
void writeDquant_CABAC(SyntaxElement *se, EncodingEnvironmentPtr eep_dp);
void writeRunLevel_CABAC(SyntaxElement *se, EncodingEnvironmentPtr eep_dp);
void writeBiDirBlkSize_CABAC(SyntaxElement *se, EncodingEnvironmentPtr eep_dp);
void writeCIPredMode_CABAC(SyntaxElement *se, EncodingEnvironmentPtr eep_dp);
void print_ctx_TextureInfo(TextureInfoContexts *enco_ctx);
void writeMB_skip_flagInfo_CABAC(SyntaxElement *se, EncodingEnvironmentPtr eep_dp);
void writeFieldModeInfo_CABAC(SyntaxElement *se, EncodingEnvironmentPtr eep_dp); //GB
void writeCBP_BIT_CABAC (int b8, int bit, int cbp, Macroblock* currMB, int inter, EncodingEnvironmentPtr eep_dp);
void cabac_new_slice();
void CheckAvailabilityOfNeighborsCABAC();

void writeMB_transform_size_CABAC(SyntaxElement *se, EncodingEnvironmentPtr eep_dp);


#endif  // CABAC_H

