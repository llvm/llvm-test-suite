
/*!
 ************************************************************************
 *  \file
 *     global.h
 *
 *  \brief
 *     global definitions for for H.264 encoder.
 *
 *  \author
 *     Copyright (C) 1999  Telenor Satellite Services,Norway
 *                         Ericsson Radio Systems, Sweden
 *
 *     Inge Lille-Langoy               <inge.lille-langoy@telenor.com>
 *
 *     Telenor Satellite Services
 *     Keysers gt.13                       tel.:   +47 23 13 86 98
 *     N-0130 Oslo,Norway                  fax.:   +47 22 77 79 80
 *
 *     Rickard Sjoberg                 <rickard.sjoberg@era.ericsson.se>
 *
 *     Ericsson Radio Systems
 *     KI/ERA/T/VV
 *     164 80 Stockholm, Sweden
 *
 ************************************************************************
 */
#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <stdio.h>

#include "defines.h"
#include "parsetcommon.h"
#include "q_matrix.h"
#include "q_offsets.h"
#include "minmax.h"

#ifdef WIN32
  #define  snprintf _snprintf
#endif

#if defined(WIN32) && !defined(__GNUC__)
  typedef __int64   int64;
#ifndef INT64_MIN
# define INT64_MIN        (-9223372036854775807i64 - 1i64)
#endif
#else
  typedef long long int64;
#ifndef INT64_MIN
# define INT64_MIN        (-9223372036854775807LL - 1LL)
#endif
#endif

#ifdef WIN32
#define  snprintf _snprintf
#define  open     _open
#define  close    _close
#define  read     _read
#define  write    _write
#define  lseek    _lseeki64
#define  fsync    _commit
#define  OPENFLAGS_WRITE _O_WRONLY|_O_CREAT|_O_BINARY|_O_TRUNC
#define  OPEN_PERMISSIONS _S_IREAD | _S_IWRITE
#define  OPENFLAGS_READ  _O_RDONLY|_O_BINARY
#else
#define  OPENFLAGS_WRITE O_WRONLY|O_CREAT|O_TRUNC
#define  OPENFLAGS_READ  O_RDONLY
#define  OPEN_PERMISSIONS S_IRUSR | S_IWUSR
#endif


/***********************************************************************
 * T y p e    d e f i n i t i o n s    f o r    T M L
 ***********************************************************************
 */

//#define pel_t byte

#define imgpel unsigned short
#define distpel int
//#define imgpel byte
//#define distpel unsigned short

#define pel_t imgpel

//! Data Partitioning Modes
typedef enum
{
  PAR_DP_1,   //!< no data partitioning is supported
  PAR_DP_3    //!< data partitioning with 3 partitions
} PAR_DP_TYPE;


//! Output File Types
typedef enum
{
  PAR_OF_ANNEXB,    //!< Annex B byte stream format
  PAR_OF_RTP       //!< RTP packets in outfile
} PAR_OF_TYPE;

//! Field Coding Types
typedef enum 
{
  FRAME_CODING,
  FIELD_CODING,
  ADAPTIVE_CODING
} CodingType;

//! definition of H.264 syntax elements
typedef enum 
{
  SE_HEADER,
  SE_PTYPE,
  SE_MBTYPE,
  SE_REFFRAME,
  SE_INTRAPREDMODE,
  SE_MVD,
  SE_CBP_INTRA,
  SE_LUM_DC_INTRA,
  SE_CHR_DC_INTRA,
  SE_LUM_AC_INTRA,
  SE_CHR_AC_INTRA,
  SE_CBP_INTER,
  SE_LUM_DC_INTER,
  SE_CHR_DC_INTER,
  SE_LUM_AC_INTER,
  SE_CHR_AC_INTER,
  SE_DELTA_QUANT_INTER,
  SE_DELTA_QUANT_INTRA,
  SE_BFRAME,
  SE_EOS,
  SE_MAX_ELEMENTS  //!< number of maximum syntax elements
} SE_type;         // substituting the definitions in elements.h


typedef enum 
{
  INTER_MB,
  INTRA_MB_4x4,
  INTRA_MB_16x16
} IntraInterDecision;


typedef enum 
{
  BITS_HEADER,
  BITS_TOTAL_MB,
  BITS_MB_MODE,
  BITS_INTER_MB,
  BITS_CBP_MB,
  BITS_COEFF_Y_MB,
  BITS_COEFF_UV_MB,
  BITS_DELTA_QUANT_MB,
  MAX_BITCOUNTER_MB
} BitCountType;


typedef enum 
{
  NO_SLICES,
  FIXED_MB,
  FIXED_RATE,
  CALLBACK,
  FMO
} SliceMode;


typedef enum 
{
  UVLC,
  CABAC
} SymbolMode;


typedef enum 
{
  FRAME,
  TOP_FIELD,
  BOTTOM_FIELD
} PictureStructure;           //!< New enum for field processing

typedef enum 
{
  P_SLICE = 0,
  B_SLICE,
  I_SLICE,
  SP_SLICE,
  SI_SLICE
} SliceType;

/***********************************************************************
 * D a t a    t y p e s   f o r  C A B A C
 ***********************************************************************
 */

//! struct to characterize the state of the arithmetic coding engine
typedef struct
{
  unsigned int  Elow, Erange;
  unsigned int  Ebuffer;
  unsigned int  Ebits_to_go;
  unsigned int  Ebits_to_follow;
  byte          *Ecodestrm;
  int           *Ecodestrm_len;
  int           C;
  int           E;

  // storage in case of recode MB
  unsigned int  ElowS, ErangeS;
  unsigned int  EbufferS;
  unsigned int  Ebits_to_goS;
  unsigned int  Ebits_to_followS;
  byte          *EcodestrmS;
  int           *Ecodestrm_lenS;
  int           CS;
  int           ES;
} EncodingEnvironment;

typedef EncodingEnvironment *EncodingEnvironmentPtr;

//! struct for context management
typedef struct
{
  unsigned short state;         // index into state-table CP  
  unsigned char  MPS;           // Least Probable Symbol 0/1 CP

  unsigned long  count;

} BiContextType;

typedef BiContextType *BiContextTypePtr;


/**********************************************************************
 * C O N T E X T S   F O R   T M L   S Y N T A X   E L E M E N T S
 **********************************************************************
 */


#define NUM_MB_TYPE_CTX  11
#define NUM_B8_TYPE_CTX  9
#define NUM_MV_RES_CTX   10
#define NUM_REF_NO_CTX   6
#define NUM_DELTA_QP_CTX 4
#define NUM_MB_AFF_CTX 4

#define NUM_TRANSFORM_SIZE_CTX 3

typedef struct
{
  BiContextType mb_type_contexts [3][NUM_MB_TYPE_CTX];
  BiContextType b8_type_contexts [2][NUM_B8_TYPE_CTX];
  BiContextType mv_res_contexts  [2][NUM_MV_RES_CTX];
  BiContextType ref_no_contexts  [2][NUM_REF_NO_CTX];
  BiContextType delta_qp_contexts   [NUM_DELTA_QP_CTX];
  BiContextType mb_aff_contexts     [NUM_MB_AFF_CTX];
  BiContextType transform_size_contexts   [NUM_TRANSFORM_SIZE_CTX];
} MotionInfoContexts;


#define NUM_IPR_CTX    2
#define NUM_CIPR_CTX   4
#define NUM_CBP_CTX    4
#define NUM_BCBP_CTX   4
#define NUM_MAP_CTX   15
#define NUM_LAST_CTX  15
#define NUM_ONE_CTX    5
#define NUM_ABS_CTX    5


typedef struct
{
  BiContextType  ipr_contexts [NUM_IPR_CTX]; 
  BiContextType  cipr_contexts[NUM_CIPR_CTX]; 
  BiContextType  cbp_contexts [3][NUM_CBP_CTX];
  BiContextType  bcbp_contexts[NUM_BLOCK_TYPES][NUM_BCBP_CTX];
  BiContextType  map_contexts [NUM_BLOCK_TYPES][NUM_MAP_CTX];
  BiContextType  last_contexts[NUM_BLOCK_TYPES][NUM_LAST_CTX];
  BiContextType  one_contexts [NUM_BLOCK_TYPES][NUM_ONE_CTX];
  BiContextType  abs_contexts [NUM_BLOCK_TYPES][NUM_ABS_CTX];
  BiContextType  fld_map_contexts [NUM_BLOCK_TYPES][NUM_MAP_CTX];
  BiContextType  fld_last_contexts[NUM_BLOCK_TYPES][NUM_LAST_CTX];
} TextureInfoContexts;

//*********************** end of data type definition for CABAC *******************

typedef struct pix_pos
{
  int available;
  int mb_addr;
  int x;
  int y;
  int pos_x;
  int pos_y;
} PixelPos;

/*! Buffer structure for RMPNI commands */
typedef struct RMPNIbuffer_s
{
  int RMPNI;
  int Data;
  struct RMPNIbuffer_s *Next;
} RMPNIbuffer_t;

/*! Buffer structure for decoded referenc picture marking commands */
typedef struct DecRefPicMarking_s
{
  int memory_management_control_operation;
  int difference_of_pic_nums_minus1;
  int long_term_pic_num;
  int long_term_frame_idx;
  int max_long_term_frame_idx_plus1;
  struct DecRefPicMarking_s *Next;
} DecRefPicMarking_t;

//! Syntaxelement
typedef struct syntaxelement
{
  int                 type;           //!< type of syntax element for data part.
  int                 value1;         //!< numerical value of syntax element
  int                 value2;         //!< for blocked symbols, e.g. run/level
  int                 len;            //!< length of code
  int                 inf;            //!< info part of UVLC code
  unsigned int        bitpattern;     //!< UVLC bitpattern
  int                 context;        //!< CABAC context
  int                 k;              //!< CABAC context for coeff_count,uv

#if TRACE
  #define             TRACESTRING_SIZE 100            //!< size of trace string
  char                tracestring[TRACESTRING_SIZE];  //!< trace string
#endif

  //!< for mapping of syntaxElement to UVLC
  void    (*mapping)(int value1, int value2, int* len_ptr, int* info_ptr);
  //!< used for CABAC: refers to actual coding method of each individual syntax element type
  void    (*writing)(struct syntaxelement *, EncodingEnvironmentPtr);

} SyntaxElement;

//! Macroblock
typedef struct macroblock
{
  int                 currSEnr;                   //!< number of current syntax element
  int                 slice_nr;
  int                 delta_qp;
  int                 qp ;
  int                 qpsp ;
  int                 bitcounter[MAX_BITCOUNTER_MB];

  struct macroblock   *mb_available_up;   //!< pointer to neighboring MB (CABAC)
  struct macroblock   *mb_available_left; //!< pointer to neighboring MB (CABAC)

  int                 mb_type;
  int                 mvd[2][BLOCK_MULTIPLE][BLOCK_MULTIPLE][2];          //!< indices correspond to [forw,backw][block_y][block_x][x,y]
  char                intra_pred_modes[MB_BLOCK_PARTITIONS];
  char                intra_pred_modes8x8[MB_BLOCK_PARTITIONS];                             //!< four 8x8 blocks in a macroblock
  int                 cbp ;
  int64               cbp_blk ;    //!< 1 bit set for every 4x4 block with coefs (not implemented for INTRA)
  int                 b8mode[4];
  int                 b8pdir[4];
  int64               cbp_bits;

  int                 c_ipred_mode;      //!< chroma intra prediction mode
  int                 IntraChromaPredModeFlag;
  
  int                 mb_field;
  int                 list_offset;

  int mbAddrA, mbAddrB, mbAddrC, mbAddrD;
  int mbAvailA, mbAvailB, mbAvailC, mbAvailD;

  int                 all_blk_8x8;
  int                 luma_transform_size_8x8_flag;
  int                 NoMbPartLessThan8x8Flag;

  short    bi_pred_me;
  
  // rate control
  double              actj;               // macroblock activity measure for macroblock j
  int                 prev_qp;
  int                 prev_delta_qp;
  int                 prev_cbp;
  int                 predict_qp;
  int                 predict_error;

  int                 LFDisableIdc;
  int                 LFAlphaC0Offset;
  int                 LFBetaOffset;

  int                 skip_flag;
} Macroblock;



//! Bitstream
typedef struct
{
  int             byte_pos;           //!< current position in bitstream;
  int             bits_to_go;         //!< current bitcounter
  byte            byte_buf;           //!< current buffer for last written byte
  int             stored_byte_pos;    //!< storage for position in bitstream;
  int             stored_bits_to_go;  //!< storage for bitcounter
  byte            stored_byte_buf;    //!< storage for buffer of last written byte

  byte            byte_buf_skip;      //!< current buffer for last written byte
  int             byte_pos_skip;      //!< storage for position in bitstream;
  int             bits_to_go_skip;    //!< storage for bitcounter

  byte            *streamBuffer;      //!< actual buffer for written bytes
  int             write_flag;         //!< Bitstream contains data and needs to be written

} Bitstream;

//! DataPartition
typedef struct datapartition
{

  Bitstream           *bitstream;
  EncodingEnvironment ee_cabac;

  int                 (*writeSyntaxElement)(SyntaxElement *, struct datapartition *);
                      /*!< virtual function;
                           actual method depends on chosen data partition and
                           entropy coding method  */
} DataPartition;

//! Slice
typedef struct
{
  int                 picture_id;
  int                 qp;
  int                 picture_type; //!< picture type
  int                 start_mb_nr;
  int                 max_part_nr;  //!< number of different partitions
  int                 num_mb;       //!< number of MBs in the slice
  DataPartition       *partArr;     //!< array of partitions
  MotionInfoContexts  *mot_ctx;     //!< pointer to struct of context models for use in CABAC
  TextureInfoContexts *tex_ctx;     //!< pointer to struct of context models for use in CABAC

  // !KS: RMPNI buffer should be retired. just do some sore simple stuff
  RMPNIbuffer_t        *rmpni_buffer; //!< stores the slice temporary buffer remapping commands

  int                 ref_pic_list_reordering_flag_l0;
  int                 *reordering_of_pic_nums_idc_l0;
  int                 *abs_diff_pic_num_minus1_l0;
  int                 *long_term_pic_idx_l0;
  int                 ref_pic_list_reordering_flag_l1;
  int                 *reordering_of_pic_nums_idc_l1;
  int                 *abs_diff_pic_num_minus1_l1;
  int                 *long_term_pic_idx_l1;

  Boolean             (*slice_too_big)(int bits_slice); //!< for use of callback functions

  int                 field_ctx[3][2]; //GB

} Slice;


#define MAXSLICEPERPICTURE 100
typedef struct 
{
  int   no_slices;
  int   idr_flag;
  Slice *slices[MAXSLICEPERPICTURE];
  int bits_per_picture;
  float distortion_y;
  float distortion_u;
  float distortion_v;
} Picture;

Picture *top_pic;
Picture *bottom_pic;
Picture *frame_pic;
Picture *frame_pic_1;
Picture *frame_pic_2;
Picture *frame_pic_3;

// global picture format dependend buffers, mem allocation in image.c
imgpel **imgY_org;           //!< Reference luma image
imgpel ***imgUV_org;         //!< Reference chroma image
int    **img4Y_tmp;          //!< for quarter pel interpolation

unsigned int log2_max_frame_num_minus4;
unsigned int log2_max_pic_order_cnt_lsb_minus4;

int  me_tot_time,me_time;
pic_parameter_set_rbsp_t *active_pps;
seq_parameter_set_rbsp_t *active_sps;

// B pictures
// motion vector : forward, backward, direct
int  mb_adaptive;       //!< For MB level field/frame coding tools
int  MBPairIsField;     //!< For MB level field/frame coding tools


//Weighted prediction
int ***wp_weight;  // weight in [list][index][component] order
int ***wp_offset;  // offset in [list][index][component] order
int ****wbp_weight;  // weight in [list][fwd_index][bwd_idx][component] order
int luma_log_weight_denom;
int chroma_log_weight_denom;
int wp_luma_round;
int wp_chroma_round;

// global picture format dependend buffers, mem allocation in image.c (field picture)
imgpel   **imgY_org_top;
imgpel   **imgY_org_bot;

imgpel  ***imgUV_org_top;
imgpel  ***imgUV_org_bot;

imgpel   **imgY_org_frm;
imgpel  ***imgUV_org_frm;

imgpel   **imgY_com;               //!< Encoded luma images
imgpel  ***imgUV_com;              //!< Encoded croma images

char    ***direct_ref_idx;           //!< direct mode reference index buffer
short    **direct_pdir;              //!< direct mode reference index buffer

// Buffers for rd optimization with packet losses, Dim. Kontopodis
byte **pixel_map;   //!< Shows the latest reference frame that is reliable for each pixel
byte **refresh_map; //!< Stores the new values for pixel_map  
int intras;         //!< Counts the intra updates in each frame.

int  frame_ctr[5];
int  frame_no, nextP_tr_fld, nextP_tr_frm;
int  tot_time;

#define ET_SIZE 300      //!< size of error text buffer
char errortext[ET_SIZE]; //!< buffer for error message for exit with error()

// Residue Color Transform
int resTrans_R[16][16], resTrans_G[16][16], resTrans_B[16][16];
int rec_resR[16][16], rec_resG[16][16], rec_resB[16][16];
int mprRGB[3][16][16];
int dc_level[2][4][4], dc_level_temp[2][4][4];
int   cbp_chroma_block[2][4][4], cbp_chroma_block_temp[2][4][4];
char b8_ipredmode8x8[4][4], b8_intra_pred_modes8x8[16];

//! Info for the "decoders-in-the-encoder" used for rdoptimization with packet losses
typedef struct
{
  int  **resY;               //!< Residue of Luminance
  imgpel ***decY;            //!< Decoded values at the simulated decoders
  imgpel ****decref;         //!< Reference frames of the simulated decoders
  imgpel ***decY_best;       //!< Decoded frames for the best mode for all decoders
  imgpel **RefBlock;
  byte **status_map;
  byte **dec_mb_mode;
} Decoders;
extern Decoders *decs;

//! SNRParameters
typedef struct
{
  float snr_y;               //!< current Y SNR
  float snr_u;               //!< current U SNR
  float snr_v;               //!< current V SNR
  float snr_y1;              //!< SNR Y(dB) first frame
  float snr_u1;              //!< SNR U(dB) first frame
  float snr_v1;              //!< SNR V(dB) first frame
  float snr_yt[5];           //!< SNR Y(dB) based on frame type
  float snr_ut[5];           //!< SNR U(dB) based on frame type
  float snr_vt[5];           //!< SNR V(dB) based on frame type
  float snr_ya;              //!< Average SNR Y(dB) remaining frames
  float snr_ua;              //!< Average SNR U(dB) remaining frames
  float snr_va;              //!< Average SNR V(dB) remaining frames
  float sse_y;               //!< SSE Y
  float sse_u;               //!< SSE U
  float sse_v;               //!< SSE V
  float msse_y;              //!< Average SSE Y
  float msse_u;              //!< Average SSE U
  float msse_v;              //!< Average SSE V
  int   frame_ctr;           //!< number of coded frames
} SNRParameters;

#define FILE_NAME_SIZE 200
                             //! all input parameters
typedef struct
{
  int ProfileIDC;               //!< profile idc
  int LevelIDC;                 //!< level idc

  int no_frames;                //!< number of frames to be encoded
  int qp0;                      //!< QP of first frame
  int qpN;                      //!< QP of remaining frames
  int jumpd;                    //!< number of frames to skip in input sequence (e.g 2 takes frame 0,3,6,9...)
  int hadamard;                 /*!< 0: 'normal' SAD in sub pixel search.  1: use 4x4 Hadamard transform and '
                                     Sum of absolute transform difference' in sub pixel search                   */
  int DisableSubpelME;          //!< Disable Subpixel Motion Estimation
  int search_range;             /*!< search range - integer pel search and 16x16 blocks.  The search window is
                                     generally around the predicted vector. Max vector is 2xmcrange.  For 8x8
                                     and 4x4 block sizes the search range is 1/2 of that for 16x16 blocks.       */
  int num_ref_frames;           //!< number of reference frames to be used
  int P_List0_refs;
  int B_List0_refs;
  int B_List1_refs;
  int Log2MaxFNumMinus4;
  int Log2MaxPOCLsbMinus4;
  int ResendPPS;
  int GenerateMultiplePPS;

  int img_width;                //!< image width  (must be a multiple of 16 pels)
  int img_height;               //!< image height (must be a multiple of 16 pels)
  int yuv_format;               //!< YUV format (0=4:0:0, 1=4:2:0, 2=4:2:2, 3=4:4:4)
  int intra_upd;                /*!< For error robustness. 0: no special action. 1: One GOB/frame is intra coded
                                     as regular 'update'. 2: One GOB every 2 frames is intra coded etc.
                                     In connection with this intra update, restrictions is put on motion vectors
                                     to prevent errors to propagate from the past                                */
  int blc_size[8][2];           //!< array for different block sizes
  int part_size[8][2];          //!< array for different partition sizes
  int slice_mode;               //!< Indicate what algorithm to use for setting slices
  int slice_argument;           //!< Argument to the specified slice algorithm
  int UseConstrainedIntraPred;  //!< 0: Inter MB pixels are allowed for intra prediction 1: Not allowed
  int  infile_header;           //!< If input file has a header set this to the length of the header
  char infile[FILE_NAME_SIZE];             //!< YUV 4:2:0 input format
  char outfile[FILE_NAME_SIZE];            //!< H.264 compressed output bitstream
  char ReconFile[FILE_NAME_SIZE];          //!< Reconstructed Pictures
  char TraceFile[FILE_NAME_SIZE];          //!< Trace Outputs
  char QmatrixFile[FILE_NAME_SIZE];        //!< Q matrix cfg file
  int intra_period;             //!< Random Access period though intra
  int EnableOpenGOP;            //!< support for open gops.

  int idr_enable;				//!< Encode intra slices as IDR
  int start_frame;				//!< Encode sequence starting from Frame start_frame

  // B pictures
  int successive_Bframe;        //!< number of B frames that will be used
  int qpB;                      //!< QP for non-reference B slice coded pictures
  int qpBRSOffset;                     //!< QP for reference B slice coded pictures
  int direct_spatial_mv_pred_flag;              //!< Direct Mode type to be used (0: Temporal, 1: Spatial)
  int directInferenceFlag;      //!< Direct Inference Flag

  int BiPredMotionEstimation;
  int BiPredMERefinements;
  int BiPredMESearchRange;
  int BiPredMESubPel;


  // SP Pictures
  int sp_periodicity;           //!< The periodicity of SP-pictures
  int qpsp;                     //!< SP Picture QP for prediction error
  int qpsp_pred;                //!< SP Picture QP for predicted block

  int WeightedPrediction;        //!< Weighted prediciton for P frames (0: not used, 1: explicit)
  int WeightedBiprediction;      //!< Weighted prediciton for B frames (0: not used, 1: explicit, 2: implicit)
  int UseWeightedReferenceME;    //!< Use Weighted Reference for ME.
  int RDPictureDecision;         //!< Perform RD optimal decision between various coded versions of same picture
  int RDPictureIntra;            //!< Enabled RD pic decision for intra as well.
  int RDPSliceWeightOnly;        //!< If enabled, does not check QP variations for P slices.
  int RDPSliceBTest;             //!< Tests B slice replacement for P.      
  int RDBSliceWeightOnly;        //!< If enabled, does not check QP variations for B slices.
  int SkipIntraInInterSlices;    //!< Skip intra type checking in inter slices if best_mode is skip/direct
  int BRefPictures;              //!< B coded reference pictures replace P pictures (0: not used, 1: used)
  int PyramidCoding;
  int PyramidLevelQPEnable;
  char ExplicitPyramidFormat[1024];  //!< Explicit GOP format (PyramidCoding==3). 
  int PyramidRefReorder;       //!< Reordering based on Poc distances for PyramidCoding
  int PocMemoryManagement;       //!< Memory management based on Poc distances for PyramidCoding

  int symbol_mode;              //!< Specifies the mode the symbols are mapped on bits
  int of_mode;                  //!< Specifies the mode of the output file
  int partition_mode;           //!< Specifies the mode of data partitioning

  int InterSearch16x16;
  int InterSearch16x8;
  int InterSearch8x16;
  int InterSearch8x8;
  int InterSearch8x4;
  int InterSearch4x8;
  int InterSearch4x4;

  int IntraDisableInterOnly;
  int Intra4x4ParDisable;
  int Intra4x4DiagDisable;
  int Intra4x4DirDisable;
  int Intra16x16ParDisable;
  int Intra16x16PlaneDisable;
  int ChromaIntraDisable;

  int EnableIPCM;

  double FrameRate;

  int EPZSPattern;
  int EPZSDual;
  int EPZSFixed;
  int EPZSTemporal;
  int EPZSSpatialMem;
  int EPZSMinThresScale;
  int EPZSMaxThresScale;
  int EPZSMedThresScale;

  int chroma_qp_index_offset;
#ifdef _FULL_SEARCH_RANGE_
  int full_search;
#endif
#ifdef _ADAPT_LAST_GROUP_
  int last_frame;
#endif
#ifdef _CHANGE_QP_
  int qpN2, qpB2, qp2start;
  int qp02, qpBRS2Offset;
#endif
  int rdopt;
  int disthres;
  int nobskip;

#ifdef _LEAKYBUCKET_
  int NumberLeakyBuckets;
  char LeakyBucketRateFile[FILE_NAME_SIZE];
  char LeakyBucketParamFile[FILE_NAME_SIZE];
#endif

  int PicInterlace;           //!< picture adaptive frame/field
  int MbInterlace;            //!< macroblock adaptive frame/field

  int IntraBottom;            //!< Force Intra Bottom at GOP periods.

  int LossRateA;              //!< assumed loss probablility of partition A (or full slice), in per cent, used for loss-aware R/D optimization
  int LossRateB;              //!< assumed loss probablility of partition B, in per cent, used for loss-aware R/D 
  int LossRateC;              //!< assumed loss probablility of partition C, in per cent, used for loss-aware R/D 
  int NoOfDecoders;
  int RestrictRef;
  int NumFramesInELSubSeq;
  int NumFrameIn2ndIGOP;

  int RandomIntraMBRefresh;     //!< Number of pseudo-random intra-MBs per picture

  int LFSendParameters;
  int LFDisableIdc;
  int LFAlphaC0Offset;
  int LFBetaOffset;

  int SparePictureOption;
  int SPDetectionThreshold;
  int SPPercentageThreshold;

  // FMO
  char SliceGroupConfigFileName[FILE_NAME_SIZE];    //!< Filename for config info fot type 0, 2, 6	
  int num_slice_groups_minus1;           //!< "FmoNumSliceGroups" in encoder.cfg, same as FmoNumSliceGroups, which should be erased later
  int slice_group_map_type; 

  int *top_left;                         //!< top_left and bottom_right store values indicating foregrounds
  int *bottom_right; 
  byte *slice_group_id;                   //!< slice_group_id is for slice group type being 6  
  int *run_length_minus1;                //!< run_length_minus1 is for slice group type being 0

  int slice_group_change_direction_flag;
  int slice_group_change_rate_minus1;
  int slice_group_change_cycle;

  int redundant_slice_flag; //! whether redundant slices exist,  JVT-D101
  int pic_order_cnt_type;   // POC200301

  int context_init_method;
  int model_number;
  int Transform8x8Mode;
  int ReportFrameStats;
  int DisplayEncParams;
  int Verbose;

  //! Rate Control on JVT standard 
  int RCEnable;    
  int bit_rate;
  int SeinitialQP;
  int basicunit;
  int channel_type;

  int ScalingMatrixPresentFlag;
  int ScalingListPresentFlag[8];

  // FastME enable
  int FMEnable;

  // Fidelity Range Extensions
  int BitDepthLuma;
  int BitDepthChroma;
  int img_height_cr;
  int img_width_cr;
  int rgb_input_flag;
  int cb_qp_index_offset;
  int cr_qp_index_offset;

  // Lossless Coding
  int lossless_qpprime_y_zero_flag;

  //Residue Color Transform
  int residue_transform_flag;

  // Lambda Params
  int UseExplicitLambdaParams;
  double LambdaWeight[6];

  char QOffsetMatrixFile[FILE_NAME_SIZE];        //!< Quantization Offset matrix cfg file
  int  OffsetMatrixPresentFlag;                  //!< Enable Explicit Quantization Offset Matrices

  int AdaptiveRounding;                          //!< Adaptive Rounding parameter based on JVT-N011
  int AdaptRndPeriod;                            //!< Set period for adaptive rounding of JVT-N011 in MBs
  int AdaptRndChroma;
  int AdaptRndWFactor[2][5];                     //!< Weighting factors based on reference indicator and slice type 
  // Fast Mode Decision
  int EarlySkipEnable;
  int SelectiveIntraEnable;
  int DisposableP;
  int DispPQPOffset;
} InputParameters;

//! ImageParameters
typedef struct
{
  int number;                  //!< current image number to be encoded
  int pn;                      //!< picture number
  int LevelIndex;              //!< mapped level idc
  int current_mb_nr;
  int total_number_mb;
  int current_slice_nr;
  int type;
  int structure;               //!< picture structure
  int num_ref_frames;          //!< number of reference frames to be used
  int max_num_references;      //!< maximum number of reference pictures that may occur
  int qp;                      //!< quant for the current frame
  int qpsp;                    //!< quant for the prediction frame of SP-frame
  float framerate;
  int width;                   //!< Number of pels
  int width_cr;                //!< Number of pels chroma
  int height;                  //!< Number of lines
  int height_cr;               //!< Number of lines  chroma
  int height_cr_frame;         //!< Number of lines  chroma frame
  int subblock_x;              //!< current subblock horizontal
  int subblock_y;              //!< current subblock vertical
  int is_intra_block;
  int is_v_block;
  int mb_y_upd;
  int mb_y_intra;              //!< which GOB to intra code
  int block_c_x;               //!< current block chroma vertical
  char **ipredmode;             //!< intra prediction mode
  char **ipredmode8x8;          //!< help storage for 8x8 modes, inserted by YV

  int cod_counter;             //!< Current count of number of skipped macroblocks in a row
  int ***nz_coeff;             //!< number of coefficients per block (CAVLC)

  int mb_x;                    //!< current MB horizontal
  int mb_y;                    //!< current MB vertical
  int block_x;                 //!< current block horizontal
  int block_y;                 //!< current block vertical
  int pix_x;                   //!< current pixel horizontal
  int pix_y;                   //!< current pixel vertical
  int pix_c_x;                 //!< current pixel chroma horizontal
  int pix_c_y;                 //!< current pixel chroma vertical

  int opix_x;                   //!< current original picture pixel horizontal
  int opix_y;                   //!< current original picture pixel vertical
  int opix_c_x;                 //!< current original picture pixel chroma horizontal
  int opix_c_y;                 //!< current original picture pixel chroma vertical


  // some temporal buffers
  imgpel mprr[9][16][16];      //!< all 9 prediction modes? // enlarged from 4 to 16 for ABT (is that neccessary?)

  imgpel mprr_2[5][16][16];    //!< all 4 new intra prediction modes
  imgpel mprr_3[9][8][8];      //!< all 9 prediction modes for 8x8 transformation
  imgpel mprr_c[2][4][16][16]; //!< chroma intra prediction modes
  imgpel mpr[16][16];          //!< current best prediction mode
  int m7[16][16];              //!< the diff pixel values between orginal image and prediction

  int ****cofAC;               //!< AC coefficients [8x8block][4x4block][level/run][scan_pos]
  int ***cofDC;                //!< DC coefficients [yuv][level/run][scan_pos]

  int fadjust4x4[4][16][16];        //!< Transform coefficients for 4x4 luma. Excludes DC for I16x16
  int fadjust8x8[3][16][16];        //!< Transform coefficients for 8x8 luma       
  int fadjust4x4Cr[4][2][16][16];   //!< Transform coefficients for 4x4 chroma. Excludes DC chroma.
  int fadjust8x8Cr[1][2][16][16];   //!< Transform coefficients for 4x4 chroma within 8x8 inter blocks. 

  Picture     *currentPicture; //!< The coded picture currently in the works (typically frame_pic, top_pic, or bottom_pic)
  Slice       *currentSlice;                                //!< pointer to current Slice data struct
  Macroblock    *mb_data;                                   //!< array containing all MBs of a whole frame
  SyntaxElement   MB_SyntaxElements[MAX_SYMBOLS_PER_MB];    //!< temporal storage for all chosen syntax elements of one MB

  int *quad;               //!< Array containing square values,used for snr computation  */                                         /* Values are limited to 5000 for pixel differences over 70 (sqr(5000)).
  int *intra_block;

  int tr;
  int fld_type;                        //!< top or bottom field
  unsigned int fld_flag;                                
  unsigned int rd_pass;
  int direct_intraP_ref[4][4];
  int pstruct_next_P;
  int imgtr_next_P_frm;
  int imgtr_last_P_frm;
  int imgtr_next_P_fld;
  int imgtr_last_P_fld;

  // B pictures
  double b_interval;
  int p_interval;
  int b_frame_to_code;
  int fw_mb_mode;
  int bw_mb_mode;

  short****** pred_mv;                 //!< motion vector predictors for all block types and all reference frames
  short****** all_mv;                  //!< replaces local all_mv

  short****** bipred_mv1;              //!< Biprediction MVs
  short****** bipred_mv2;              //!< Biprediction MVs
  short bi_pred_me[MAXMODE];

  int LFDisableIdc;
  int LFAlphaC0Offset;
  int LFBetaOffset;

  int direct_spatial_mv_pred_flag;              //!< Direct Mode type to be used (0: Temporal, 1: Spatial)

  int num_ref_idx_l0_active;
  int num_ref_idx_l1_active;

  int field_mode;     //!< For MB level field/frame -- field mode on flag
  int top_field;      //!< For MB level field/frame -- top field flag
  int mvscale[6][MAX_REFERENCE_PICTURES];
  int buf_cycle;
  int i16offset;

  int layer;             //!< which layer this picture belonged to
  int old_layer;         //!< old layer number
  int NoResidueDirect;
  int AdaptiveRounding;                          //!< Adaptive Rounding parameter based on JVT-N011

  int redundant_pic_cnt; // JVT-D101

  int MbaffFrameFlag;    //!< indicates frame with mb aff coding

  //the following should probably go in sequence parameters
  // unsigned int log2_max_frame_num_minus4;
  unsigned int pic_order_cnt_type;
  // for poc mode 0, POC200301
  // unsigned int log2_max_pic_order_cnt_lsb_minus4;  
  // for poc mode 1, POC200301
  unsigned int delta_pic_order_always_zero_flag;
           int offset_for_non_ref_pic;
           int offset_for_top_to_bottom_field;
  unsigned int num_ref_frames_in_pic_order_cnt_cycle;
           int offset_for_ref_frame[1];  // MAX_LENGTH_POC_CYCLE in decoder

  // POC200301
  //the following is for slice header syntax elements of poc
  // for poc mode 0.
  unsigned int pic_order_cnt_lsb;
           int delta_pic_order_cnt_bottom;
  // for poc mode 1.
           int delta_pic_order_cnt[2];


  // POC200301
  unsigned int field_picture;
    signed int toppoc;      //!< poc for this frame or field
    signed int bottompoc;   //!< for completeness - poc of bottom field of a frame (always = poc+1)
    signed int framepoc;    //!< min (toppoc, bottompoc)
    signed int ThisPOC;     //!< current picture POC
  unsigned int frame_num;   //!< frame_num for this frame
  
  unsigned PicWidthInMbs;
  unsigned PicHeightInMapUnits;
  unsigned FrameHeightInMbs;
  unsigned PicHeightInMbs;
  unsigned PicSizeInMbs;
  unsigned FrameSizeInMbs;

  //the following should probably go in picture parameters
  unsigned int pic_order_present_flag; // ????????

  //the following are sent in the slice header
//  int delta_pic_order_cnt[2];
  int nal_reference_idc;

  int adaptive_ref_pic_buffering_flag;
  int no_output_of_prior_pics_flag;
  int long_term_reference_flag;

  DecRefPicMarking_t *dec_ref_pic_marking_buffer;

  int model_number;


  /*rate control*/
  int NumberofHeaderBits; 
  int NumberofTextureBits;
  int NumberofBasicUnitHeaderBits;
  int NumberofBasicUnitTextureBits;
  double TotalMADBasicUnit;
  int NumberofMBTextureBits;
  int NumberofMBHeaderBits;
  int NumberofCodedBFrame; 
  int NumberofCodedPFrame;
  int NumberofGOP;
  int TotalQpforPPicture;
  int NumberofPPicture;
  double *MADofMB;
  int BasicUnitQP;
  int TopFieldFlag;
  int FieldControl;
  int FieldFrame;
  int Frame_Total_Number_MB;
  int IFLAG;
  int NumberofCodedMacroBlocks;
  int BasicUnit;
  int write_macroblock;
  int bot_MB;
  int write_macroblock_frame;

  int DeblockCall;
        
  int last_pic_bottom_field;
  int last_has_mmco_5;
  int pre_frame_num;

  int slice_group_change_cycle;

  int pic_unit_size_on_disk;
  int bitdepth_luma;
  int bitdepth_chroma;
  int bitdepth_luma_qp_scale;
  int bitdepth_chroma_qp_scale;
  int bitdepth_lambda_scale;
  // Lagrangian Parameters
  double lambda_md[10][52];     //!< Mode decision Lambda
  double lambda_me[10][52];     //!< Motion Estimation Lambda
  int lambda_mf[10][52];        //!< Integer formatted Motion Estimation Lambda

  unsigned int dc_pred_value;   //!< value for DC prediction (depends on pel bit depth)
  int max_imgpel_value;         //!< max value that one picture element (pixel) can take (depends on pic_unit_bitdepth)
  int max_imgpel_value_uv;

  int num_blk8x8_uv;
  int num_cdc_coeff;
  int yuv_format;
  int lossless_qpprime_flag;
  int mb_cr_size_x;
  int mb_cr_size_y;

  int chroma_qp_offset[2];      //!< offset for qp for chroma [0-Cb, 1-Cr] 

  // Residue Color Transform
  int residue_transform_flag;

  int auto_crop_right;
  int auto_crop_bottom;

  short checkref;
  int last_valid_reference;


  int bytes_in_picture;
} ImageParameters;

#define NUM_PIC_TYPE 5
                                //!< statistics
typedef struct
{
  int   quant0;                 //!< quant for the first frame
  int   quant1;                 //!< average quant for the remaining frames
  float bitr;                   //!< bit rate for current frame, used only for output til terminal
  float bitrate;                //!< average bit rate for the sequence except first frame
  int   bit_ctr;                //!< counter for bit usage
  int   bit_ctr_n;              //!< bit usage for the current frame
  int   bit_slice;              //!< number of bits in current slice
  int   bit_ctr_emulationprevention; //!< stored bits needed to prevent start code emulation
  int   b8_mode_0_use[NUM_PIC_TYPE][2];
  int   mode_use_transform_8x8[NUM_PIC_TYPE][MAXMODE];
  int   mode_use_transform_4x4[NUM_PIC_TYPE][MAXMODE];
  int   intra_chroma_mode[4];
  
  // B pictures
  int   successive_Bframe;
  int   *mode_use_Bframe;
  int   *bit_use_mode_Bframe;
  int   bit_ctr_I;
  int   bit_ctr_P;
  int   bit_ctr_B;
  float bitrate_I;
  float bitrate_P;
  float bitrate_B;

  int   mode_use            [NUM_PIC_TYPE][MAXMODE]; //!< Macroblock mode usage for Intra frames
  int   bit_use_mode        [NUM_PIC_TYPE][MAXMODE]; //!< statistics of bit usage
  int   bit_use_stuffingBits[NUM_PIC_TYPE];
  int   bit_use_mb_type     [NUM_PIC_TYPE];
  int   bit_use_header      [NUM_PIC_TYPE];
  int   tmp_bit_use_cbp     [NUM_PIC_TYPE];
  int   bit_use_coeffY      [NUM_PIC_TYPE];
  int   bit_use_coeffC      [NUM_PIC_TYPE];
  int   bit_use_delta_quant [NUM_PIC_TYPE];

  int   em_prev_bits_frm;
  int   em_prev_bits_fld;
  int  *em_prev_bits;
  int   bit_ctr_parametersets;
  int   bit_ctr_parametersets_n;
  } StatParameters;

//!< For MB level field/frame coding tools
//!< temporary structure to store MB data for field/frame coding
typedef struct
{
  double min_rdcost;

  imgpel rec_mbY[16][16];       // hold the Y component of reconstructed MB
  imgpel rec_mbU[16][16], rec_mbV[16][16]; 
  int    ****cofAC;
  int    ***cofDC;
  int    mb_type;
  short  bi_pred_me;

  int    b8mode[4], b8pdir[4];
  char   **ipredmode;
  char   intra_pred_modes[16];
  int    cbp;
  int64  cbp_blk;
  int    mode;
  short  ******pred_mv;        //!< predicted motion vectors
  short  ******all_mv;         //!< all modes motion vectors
  char   refar[2][4][4];       //!< reference frame array [list][y][x]
  int    i16offset;
  int    c_ipred_mode;

  int    luma_transform_size_8x8_flag;
  int    NoMbPartLessThan8x8Flag;
  
  int    qp;
  int    prev_qp;
  int    prev_delta_qp;
  int    delta_qp;
  int    prev_cbp;
} RD_DATA;


//!< Set Explicit GOP Parameters.
//!< Currently only supports Enhancement GOP but could be easily extended
typedef struct
{
  int slice_type;       //! Slice type
  int display_no;       //! GOP Display order
  int reference_idc;    //! Is reference?
  int slice_qp;         //! Assigned QP
  int pyramid_layer;    //! Pyramid layer (used with GOP Pyramid option 2
  int pyramidPocDelta;  //! Currently unused
} GOP_DATA;


typedef struct
{
  int cost8x8;
  int rec_resG_8x8[16][16];
  int resTrans_R_8x8[16][16];
  int resTrans_B_8x8[16][16];
  int mprRGB_8x8[3][16][16];
  short part8x8mode[4];
  short part8x8pdir[4];
  char  part8x8fwref[4];
  char  part8x8bwref[4];
  imgpel rec_mbY8x8[16][16];    
  imgpel mpr8x8[16][16];
} RD_8x8DATA;

typedef struct
{  
  double lambda_md;     //!< Mode decision Lambda
  double lambda_me;     //!< Motion Estimation Lambda
  int    lambda_mf;     //!< Integer formatted Motion Estimation Lambda

  short  valid[MAXMODE];
  short  list_offset[2];
  short  curr_mb_field;
  short  best_ref[2];
  int    best_mcost[2];
} RD_PARAMS;

GOP_DATA *gop_structure;
RD_DATA *rdopt; 
RD_DATA rddata_top_frame_mb, rddata_bot_frame_mb; //!< For MB level field/frame coding tools
RD_DATA rddata_top_field_mb, rddata_bot_field_mb; //!< For MB level field/frame coding tools

extern InputParameters *input;
extern ImageParameters *img;
extern StatParameters  *stats;

extern SNRParameters *snr;

// files
FILE *p_stat;                    //!< status file for the last encoding session
FILE *p_log;                     //!< SNR file
FILE *p_trace;                   //!< Trace file
int  p_in;                       //!< original YUV file handle
int  p_dec;                      //!< decoded image file handle


/***********************************************************************
 * P r o t o t y p e s   f o r    T M L
 ***********************************************************************
 */

void intrapred_luma(int CurrPixX,int CurrPixY, int *left_available, int *up_available, int *all_available);
void init();
int  dct_luma(int pos_mb1,int pos_mb2,int *cnt_nonz, int intra);
int  dct_luma_sp(int pos_mb1,int pos_mb2,int *cnt_nonz);
void copyblock_sp(int pos_mb1,int pos_mb2);
int  dct_chroma(int uv,int i11);
int  dct_chroma_sp(int uv,int i11);
// Residue Color Transform
int  dct_chroma4x4(int uv, int b8, int b4);
int  dct_chroma_DC(int uv, int cr_cbp);

int  motion_search(int isi);
int  sign(int a,int b);
void intrapred_chroma(int,int,int uv);
void intrapred_luma_16x16();
int  find_sad_16x16(int *intra_mode);

int dct_luma_16x16(int);

void init_poc();

void init_img();
void report();
void information_init();
int  get_picture_type();
int clip1a(int a);
void DeblockFrame(ImageParameters *img, imgpel **, imgpel ***) ;
void MarkAllMacroblockModes(ImageParameters *img, imgpel **, imgpel ***);

int  TransformDecision(int, int*);
int  SATD8X8(int*, int);

void LumaPrediction4x4 (int, int, int, int, int, short, short);
int  SATD (int*, int);
int  find_SATD (int c_diff[MB_PIXELS], int blocktype);

pel_t* FastLineX (int, pel_t*, int, int, int, int);
pel_t* UMVLineX  (int, pel_t*, int, int, int, int);

void LumaResidualCoding ();
void ChromaResidualCoding (int*);
void IntraChromaPrediction (int*, int*, int*);
void ChromaPrediction4x4 (int, int, int, int, int, int, short, short);

int writeMBLayer (int rdopt, int *coeff_rate);

extern int*   refbits;
extern int**** motion_cost;

void  Get_Direct_Motion_Vectors ();
void  PartitionMotionSearch     (int, int, int);
int   BIDPartitionCost          (int, int, short, short, int);
int   LumaResidualCoding8x8     (int*, int64*, int, short, int, int, short, short);
int   writeLumaCoeff8x8         (int, int, int);
int   writeMotionVector8x8      (int  i0, int  j0, int  i1, int  j1, int  refframe, int  list_idx, int  mv_mode);
int   writeReferenceFrame       (int, int, int, int, int);
int   writeAbpCoeffIndex        (int, int, int, int);
int   writeIntra4x4Modes        (int);
int   writeChromaIntraPredMode  ();

void estimate_weighting_factor_B_slice();
void estimate_weighting_factor_P_slice(int offset);
int  test_wp_P_slice(int offset);
int  test_wp_B_slice(int method);
void poc_based_ref_management(int current_pic_num);
int  picture_coding_decision (Picture *picture1, Picture *picture2, int qp);

unsigned CeilLog2( unsigned uiVal);

int  Get_Direct_Cost8x8 (int, int*);

int   BPredPartitionCost  (int, int, short, short, int, int);
void  LumaPrediction4x4Bi (int, int,   int,   int, int, short, short, int);
int   SATDBI (int* , int );

int  Get_Direct_CostMB  (int);
int  B8Mode2Value (int b8mode, int b8pdir);

int  GetSkipCostMB (int lambda_factor);
void FindSkipModeMotionVector ();


// dynamic mem allocation
int  init_global_buffers();
void free_global_buffers();
void no_mem_exit  (char *where);

int  get_mem_mv  (short*******);
void free_mem_mv (short******);
void free_img    ();

int  get_mem_ACcoeff  (int*****);
int  get_mem_DCcoeff  (int****);
void free_mem_ACcoeff (int****);
void free_mem_DCcoeff (int***);

int  decide_fld_frame(float snr_frame_Y, float snr_field_Y, int bit_field, int bit_frame, double lambda_picture);
void combine_field();

Picture *malloc_picture();
void     free_picture (Picture *pic);

int   encode_one_slice(int SLiceGroupId, Picture *pic, int TotalCodedMBs);   //! returns the number of MBs in the slice

void  start_macroblock(int mb_addr, int mb_field);
void  set_MB_parameters (int mb_addr);           //! sets up img-> according to input-> and currSlice->

int   writeMotionInfo2NAL ();

void  terminate_macroblock(Boolean *end_of_slice, Boolean *recode_macroblock);
int   slice_too_big(int rlc_bits);
void  write_one_macroblock(int eos_bit);
void  proceed2nextMacroblock();

void free_slice_list(Picture *currPic);

void report_stats_on_error();

#if TRACE
void  trace2out(SyntaxElement *se);
#endif


void error(char *text, int code);
int  start_sequence();
int  terminate_sequence();
int  start_slice();
int  terminate_slice();
int  write_PPS(int, int);

// B pictures
int  get_fwMV(int *min_fw_sad, int tot_intra_sad);
void get_bwMV(int *min_bw_sad);
void get_bid(int *bid_sad, int fw_predframe_no);
void get_dir(int *dir_sad);
void compare_sad(int tot_intra_sad, int fw_sad, int bw_sad, int bid_sad, int dir_sad, int);
int  BlkSize2CodeNumber(int blc_size_h, int blc_size_v);

void InitMotionVectorSearchModule();

int  field_flag_inference();

void set_mbaff_parameters();  // For MB AFF
void writeVlcByteAlign(Bitstream* currStream);


int   writeLumaCoeff4x4_CABAC     (int, int, int);
int   writeLumaCoeff8x8_CABAC     (int, int);
int   writeCBPandLumaCoeff        ();
int   writeChromaCoeff            ();
int   writeMB_bits_for_4x4_luma   (int, int, int);
int   writeMB_bits_for_16x16_luma ();
int   writeMB_bits_for_luma       (int);
int   writeMB_bits_for_DC_chroma  (int);
int   writeMB_bits_for_AC_chroma  (int);
int   writeMB_bits_for_CBP        ();

int   SingleUnifiedMotionSearch   (int, int, int**, int***, int*****, int, int*****, double);

//============= rate-distortion optimization ===================
void  clear_rdopt      ();
void  init_rdopt       ();
void  RD_Mode_Decision ();
//============= rate-distortion opt with packet losses ===========
void decode_one_macroblock();
void decode_one_mb (int, Macroblock*);
void decode_one_b8block (int, int, int, int, int);
void Get_Reference_Block(imgpel **imY, int block_y, int block_x, int mvhor, int mvver, imgpel **out);
byte Get_Reference_Pixel(imgpel **imY, int y, int x);
int  Half_Upsample(imgpel **imY, int j, int i);
void DecOneForthPix(imgpel **dY, imgpel ***dref);
void compute_residue(int mode);
void compute_residue_b8block (int, int);
void compute_residue_mb (int);
void UpdateDecoders();
void Build_Status_Map(byte **s_map);
void Error_Concealment(imgpel **inY, byte **s_map, imgpel ***refY);
void Conceal_Error(imgpel **inY, int mb_y, int mb_x, imgpel ***refY, byte **s_map);
//============= restriction of reference frames based on the latest intra-refreshes==========
void UpdatePixelMap();

//============= fast full integer search =======================
#ifdef _FAST_FULL_ME_
void  ClearFastFullIntegerSearch    ();
void  ResetFastFullIntegerSearch    ();
#endif

void process_2nd_IGOP();
void SetImgType();

// Tian Dong: for IGOPs
extern Boolean In2ndIGOP;
extern int start_frame_no_in_this_IGOP;
extern int start_tr_in_this_IGOP;
extern int FirstFrameIn2ndIGOP;
#define IMG_NUMBER (img->number-start_frame_no_in_this_IGOP)

void AllocNalPayloadBuffer();
void FreeNalPayloadBuffer();
void SODBtoRBSP(Bitstream *currStream);
int RBSPtoEBSP(byte *streamBuffer, int begin_bytepos, int end_bytepos, int min_num_bytes);
int Bytes_After_Header;

// JVT-D101: the bit for redundant_pic_cnt in slice header may be changed, 
// therefore the bit position in the bitstream must be stored.
int rpc_bytes_to_go;
int rpc_bits_to_go;
void modify_redundant_pic_cnt(unsigned char *streamBuffer);
// End JVT-D101

// Fast ME enable
int BlockMotionSearch (short,int,int,int,int,int, int);
void low_complexity_encode_md (void);
void encode_one_macroblock (void);
void fasthigh_complexity_encode_md (void);

int RDCost_for_4x4Blocks_Chroma (int b8, int b4, int  chroma);

#endif

#include "context_ini.h"

void store_coding_state_cs_cm();
void reset_coding_state_cs_cm();

int writeIPCMBytes(Bitstream *currStream);
int writePCMByteAlign(Bitstream *currStream);

