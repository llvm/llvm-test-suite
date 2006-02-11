
/*!
 ***************************************************************************
 * \file
 *    q_offsets.h
 *
 * \brief
 *    Headerfile for q_offsets array
 *
 * \date
 *    18. Nov 2004
 ***************************************************************************
 */

#ifndef _Q_OFFSETS_H_
#define _Q_OFFSETS_H_

extern int ****LevelOffset4x4Luma;
extern int *****LevelOffset4x4Chroma;
extern int ****LevelOffset8x8Luma;

extern int AdaptRndWeight;

void Init_QOffsetMatrix ();
void CalculateOffsetParam();
void CalculateOffset8Param();
void free_QOffsets ();
#endif
