// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//  Written by Ashok Sreenivasan, TRDDC, Pune, India.  1993.  May be
//  distributed freely, provided this comment is displayed at the top.
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#ifndef __PIECE__
extern "C" {
int strlen(char *str1);
int strcmp(char *str1, char *str2);
char *strcpy(char *str1, char *str2);
char *strncpy(char *str1, char *str2, int i);
char *strcat(char *str1, char *str2);
}

enum PieceType
{
	WPAWN,
	BPAWN,
	WROOK,
	BROOK,
	WKNIGHT,
	BKNIGHT,
	WBISHOP,
	BBISHOP,
	WQUEEN,
	BQUEEN,
	WKING,
	BKING,
	EMPTY,
	UNKNOWN,
};

#define ISWHITE(p)	(p == WPAWN || p == WROOK || p == WKNIGHT || \
					p == WBISHOP || p == WQUEEN || p == WKING)

#define ISBLACK (P)	(!ISWHITE(p) && p != EMPTY && p != UNKNOWN)

#define __PIECE__

#endif
