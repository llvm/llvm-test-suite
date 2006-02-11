
/*!
 *************************************************************************************
 * \file mb_access.h
 *
 * \brief
 *    Functions for macroblock neighborhoods
 *
 * \author
 *     Main contributors (see contributors.h for copyright, address and affiliation details)
 *     - Karsten Sühring          <suehring@hhi.de>
 *************************************************************************************
 */

#ifndef _MB_ACCESS_H_
#define _MB_ACCESS_H_

void CheckAvailabilityOfNeighbors();

void getNeighbour(int curr_mb_nr, int xN, int yN, int luma, PixelPos *pix);
void getLuma4x4Neighbour (int curr_mb_nr, int block_x, int block_y, int rel_x, int rel_y, PixelPos *pix);
void getChroma4x4Neighbour (int curr_mb_nr, int block_x, int block_y, int rel_x, int rel_y, PixelPos *pix);

int  mb_is_available(int mbAddr, int currMbAddr);
void get_mb_pos (int mb_addr, int *x, int*y);
void get_mb_block_pos (int mb_addr, int *x, int*y);



#endif
