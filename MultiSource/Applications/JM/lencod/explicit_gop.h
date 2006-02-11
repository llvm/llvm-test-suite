
/*!
 *************************************************************************************
 * \file explicit_gop.h
 *
 * \brief
 *    Functions for explicit gop and pyramid support
 *
 * \author
 *     Main contributors (see contributors.h for copyright, address and affiliation details)
 *     - Alexis Michael Tourapis          <alexismt@ieee.org>
 *************************************************************************************
 */

#ifndef _EXPLICIT_GOP_H_
#define _EXPLICIT_GOP_H_

// GOP Pyramid
void init_gop_structure(); 
void interpret_gop_structure();
void create_pyramid();
void clear_gop_structure();
void encode_enhancement_layer();

#endif
