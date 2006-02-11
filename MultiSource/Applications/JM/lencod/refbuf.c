
/*!
 ************************************************************************
 * \file refbuf.c
 *
 * \brief
 *    Declarations of teh reference frame buffer types and functions
 ************************************************************************
 */

#include <stdlib.h>
#include <memory.h>
#include "global.h"

#include "refbuf.h"

/*!
 ************************************************************************
 * \brief
 *    Reference buffer write routines
 ************************************************************************
 */
void PutPel_14 (pel_t **Pic, int y, int x, pel_t val)
{
  Pic [y][x] = val;
}

void PutPel_11 (pel_t *Pic, int pel_pos, pel_t val)
{
  Pic [pel_pos] = val;
}

/*!
 ************************************************************************
 * \note
 *    The following functions returning line are NOT reentrant!  Use a buffer
 *    provided by the caller to change that (but it costs a memcpy()...
 ************************************************************************
 */
static pel_t line[16];
static pel_t line4[64];

pel_t *FastLine16Y_11 (pel_t *Pic, int y, int x, int height, int width)
{
  return &Pic [y*width+x];
}


pel_t *UMVLine16Y_11 (pel_t *Pic, int y, int x, int height, int width)
{
  int i, maxx;
  pel_t *Picy;

  Picy = &Pic [max(0,min(height-1,y)) * width];

  if (x < 0) {                    // Left edge ?

    maxx = min(0,x+16);
    for (i = x; i < maxx; i++)
      line[i-x] = Picy [0];       // Replicate left edge pixel

    maxx = x+16;
    for (i = 0; i < maxx; i++)    // Copy non-edge pixels
      line[i-x] = Picy [i];
  }
  else if (x > width-16)  {  // Right edge ?

    maxx = width;
    for (i = x; i < maxx; i++)
      line[i-x] = Picy [i];       // Copy non-edge pixels

    maxx = x+16;
    for (i = max(width,x); i < maxx; i++)
      line[i-x] = Picy [width-1];  // Replicate right edge pixel
  }
  else                            // No edge
    return &Picy [x];

  return line;
}


pel_t *FastLineX (int dummy, pel_t* Pic, int y, int x, int height, int width)
{
  return Pic + y*width + x;
}


pel_t *UMVLineX (int size, pel_t* Pic, int y, int x, int height, int width)
{
  int i;
  pel_t *Picy;

  Picy = Pic + max(0,min(height-1,y)) * width;

  if (x < 0)                            // Left edge
  {   
    for (i = x; i < min(0,x+size); i++)
    {
      line[i-x] = Picy [0];             // Replicate left edge pixel
    }

    memcpy(&line[min(-x,15)],Picy,max(x+size,0) * sizeof(pel_t)); // Copy non-edge pixels
  }
  else if (x > width-size)         // Right edge
  {
    memcpy(line,&Picy[x], max((width - x),0) * sizeof(pel_t)); // Copy non-edge pixels
    for (i = max(width,x); i < x+size; i++)
    {
      line[i-x] = Picy [width-1];  // Replicate right edge pixel
    }
  }
  else                                  // No edge
  {
    return Picy + x;
  }

  return line;
}

/*!
 ************************************************************************
 * \brief
 *    Reference buffer, 1/4 pel
 ************************************************************************
 */
pel_t UMVPelY_14 (pel_t **Pic, int y, int x, int height4, int width4)
{
  int ypos = (y < 0 ? y&3 : (y >  height4 ? height4+(y&3) : y));
  int xpos = (x < 0 ? x&3 : (x >  width4 ? width4+(x&3) : x));

  return Pic [ypos][xpos];
}

pel_t FastPelY_14 (pel_t **Pic, int y, int x, int height, int width)
{
  return Pic [y][x];
}



pel_t *FastLine4X (pel_t **Pic, int y, int x, int height, int width)
{
  return &Pic [y][x];
}

/*!
 ************************************************************************
 * \brief
 *    Reference buffer, 1/4 pel
 ************************************************************************
 */
pel_t *UMVLine4X (pel_t **Pic, int y, int x, int height4, int width4)
{
  int i, xx;

  int xpos, ypos = (y < 0 ? y&3 : (y >  height4 ? height4+(y&3) : y));

  for (i=0; i< 64; i+=4)
  {
    xx = x + i;
    xpos = (xx < 0 ? (xx) &3 : ((xx) >  width4 ? width4+((xx) &3) : (xx) ));
    line4[i] = Pic [ypos][xpos];
  }
  return line4;
}

