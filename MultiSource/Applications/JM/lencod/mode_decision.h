
/*!
 ***************************************************************************
 * \file
 *    rdopt.h
 *
 * \author
 *    Alexis Michael Tourapis
 *
 * \date
 *    21. February 2005
 *
 * \brief
 *    Headerfile for for rd-optimized mode decision
 **************************************************************************
 */

#ifndef _RD_OPT_H_
#define _RD_OPT_H_

#define KS_MV

extern CSptr cs_mb, cs_b8, cs_cm, cs_imb, cs_ib8, cs_ib4, cs_pc;
extern imgpel   mpr_8x8ts[16][16];
extern imgpel   rec_mbY[16][16], rec_mbU[16][16], rec_mbV[16][16];    // reconstruction values
extern RD_8x8DATA tr4x4, tr8x8;

extern const  int LEVELMVLIMIT[17][6];
extern int    ****cofAC_8x8ts;        // [8x8block][4x4block][level/run][scan_pos]
extern int    ****cofAC, ****cofAC8x8;        // [8x8block][4x4block][level/run][scan_pos]
extern int    QP2QUANT[40];
extern int    cbp_blk8x8;
extern int    cbp, cbp8x8, cnt_nonz_8x8;
extern int64  cbp_blk;
extern int64  cbp_blk8_8x8ts;
extern int    cbp8_8x8ts;
extern int    cnt_nonz8_8x8ts;
extern int    QP,QP2;
extern int    DELTA_QP,DELTA_QP2;
extern int    diffy[16][16];

// Residue Color Transform
extern int    cofAC4x4_chroma[2][2][18];
extern int    mprRGB_8x8[3][16][16], mprRGB_8x8ts[3][16][16];
extern char   b4_ipredmode[16], b4_intra_pred_modes[16];

extern short  bi_pred_me;
extern short  best_mode;
extern short  best8x8mode          [4]; // [block]
extern short  best8x8pdir [MAXMODE][4]; // [mode][block]
extern short  best8x8fwref[MAXMODE][4]; // [mode][block]
extern short  best8x8bwref[MAXMODE][4]; // [mode][block]
extern imgpel pred[16][16];

extern void   set_stored_macroblock_parameters ();
extern void   StoreMV8x8(int);
extern void   RestoreMV8x8(int);
extern void   store_macroblock_parameters (int);
extern void   SetModesAndRefframeForBlocks (int);
extern void   SetRefAndMotionVectors (int, int, int, int, int);
extern void   StoreNewMotionVectorsBlock8x8(int, int, int, int, int, int, int);
extern void   assign_enc_picture_params(int, int, int, int, int, int, int);
extern void   update_refresh_map(int intra, int intra1, Macroblock *currMB);
extern void   SetMotionVectorsMB (Macroblock*, int);
extern void   SetCoeffAndReconstruction8x8 (Macroblock*);

extern int    GetBestTransformP8x8();
extern int    I16Offset (int, int);
extern int    CheckReliabilityOfRef (int, int, int, int);
extern int    Mode_Decision_for_Intra4x4Macroblock (double, int*);
extern int    RDCost_for_macroblocks (double, int, double*, double*, int);
extern double RDCost_for_8x8blocks (int*, int64*, double, int, int, short, short, short);

extern const int  b8_mode_table[6];
extern const int  mb_mode_table[9];
  // Residue Color Transform
extern const int  mb_mode_table_RCT[11];

void rc_store_diff(int cpix_x, int cpix_y, imgpel prediction[16][16]);
void update_rc(Macroblock *currMB, short best_mode);
void submacroblock_mode_decision(RD_PARAMS, RD_8x8DATA *, Macroblock *,int ***, int *, short, int, int *, int *, int *, int);
void init_enc_mb_params(Macroblock* currMB, RD_PARAMS *enc_mb, int intra, int bslice);
void list_prediction_cost(int list, int block, int mode, RD_PARAMS enc_mb, int bmcost[5], char best_ref[2]);
void determine_prediction_list(int, int [5], char [2], short *, int *, short *);

#endif

