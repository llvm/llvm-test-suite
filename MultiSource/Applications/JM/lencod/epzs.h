 
/*!
 ************************************************************************
 * \file epzs.h
 *
 * \author
 *    Alexis Michael Tourapis        <alexismt@ieee.org>              
 *
 ************************************************************************
 */

#ifndef _EPZS_H_
#define _EPZS_H_


#define CHECK_RANGE  ((cand_x >= 0) && (cand_x < img_width  - blocksize_x) &&(cand_y >= 0) && (cand_y < img_height - blocksize_y)) 


typedef struct 
{
  int         mb_adaptive_frame_field_flag;
  int         size_x, size_y;

  // Frame
  short ****  mv;            //!< motion vector       [list][subblock_x][subblock_y][component]  
  // Top field
  short ****  top_mv;        //!< motion vector       [list][subblock_x][subblock_y][component]  
  // Bottom field params
  short ****  bottom_mv;     //!< motion vector       [list][subblock_x][subblock_y][component]   

} EPZSColocParams;

typedef struct
{
  int x;
  int y;
  int start_nmbr;
  int next_points;
}
SPoint;

typedef struct 
{
  int  searchPoints;
  SPoint *point;
}
EPZSStructure;

typedef enum
{
  SDIAMOND = 0,
  SQUARE   = 1,
  EDIAMOND = 2,
  LDIAMOND = 3
} EPZSPatterns;

extern EPZSColocParams *EPZSCo_located;
extern int ***EPZSDistortion;  //!< Array for storing SAD Values

extern int EPZSInit();
extern void EPZSDelete ();
extern void EPZSOutputStats(FILE *stat,short stats_file);
extern void EPZSSliceInit(EPZSColocParams* p, StorablePicture **listX[6]);
extern int EPZSPelBlockMotionSearch (pel_t **, short, int, int, char ***, short ****, 
                                     int, int, int, short, short, short*, short*, int, int, int);

extern int EPZSBiPredBlockMotionSearch (pel_t **,	short, int, int, char  ***, short  ****, 
                                        int, int, int, short, short, short, short, 
                                        short *, short *,	short *, short *, int, int, int);	     

#endif
