
/*!
 *************************************************************************************
 * \file vlc.h
 *
 * \brief
 *    Prototypes for VLC coding funtions
 * \author
 *     Karsten Suehring
 *************************************************************************************
 */

#ifndef _VLC_H_
#define _VLC_H_

int u_1  (char *tracestring, int value, Bitstream *bitstream);
int se_v (char *tracestring, int value, Bitstream *bitstream);
int ue_v (char *tracestring, int value, Bitstream *bitstream);
int u_v  (int n, char *tracestring, int value, Bitstream *bitstream);


void levrun_linfo_c2x2(int level,int run,int *len,int *info);
void levrun_linfo_intra(int level,int run,int *len,int *info);
void levrun_linfo_inter(int level,int run,int *len,int *info);

int   writeSyntaxElement_UVLC(SyntaxElement *se, DataPartition *this_dataPart);

int   writeSyntaxElement2Buf_UVLC(SyntaxElement *se, Bitstream* this_streamBuffer );
void  writeUVLC2buffer(SyntaxElement *se, Bitstream *currStream);
int   writeSyntaxElement2Buf_Fixed(SyntaxElement *se, Bitstream* this_streamBuffer );
int   symbol2uvlc(SyntaxElement *se);
void  ue_linfo(int n, int dummy, int *len,int *info);
void  se_linfo(int mvd, int dummy, int *len,int *info);
void  cbp_linfo_intra(int cbp, int dummy, int *len,int *info);
void  cbp_linfo_inter(int cbp, int dummy, int *len,int *info);

// CAVLC
void  CAVLC_init();
int writeCoeff4x4_CAVLC (int block_type, int b8, int b4, int param);

int   writeSyntaxElement_VLC(SyntaxElement *se, DataPartition *this_dataPart);
int   writeSyntaxElement_TotalZeros(SyntaxElement *se, DataPartition *this_dataPart);
int   writeSyntaxElement_TotalZerosChromaDC(SyntaxElement *se, DataPartition *this_dataPart);
int   writeSyntaxElement_Run(SyntaxElement *se, DataPartition *this_dataPart);
int   writeSyntaxElement_NumCoeffTrailingOnes(SyntaxElement *se, DataPartition *this_dataPart);
int   writeSyntaxElement_NumCoeffTrailingOnesChromaDC(SyntaxElement *se, DataPartition *this_dataPart);
int   writeSyntaxElement_Level_VLC1(SyntaxElement *se, DataPartition *this_dataPart);
int   writeSyntaxElement_Level_VLCN(SyntaxElement *se, int vlc, DataPartition *this_dataPart);
int   writeSyntaxElement_Intra4x4PredictionMode(SyntaxElement *se, DataPartition *this_dataPart);

#endif

