/*
 *	BOOK.C
 *	Tom Kerrigan's Simple Chess Program (TSCP)
 *
 *	Copyright 1997 Tom Kerrigan
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "defs.h"
#include "data.h"
#include "protos.h"


/* the opening book file, declared here so we don't have to include stdio.h in
   a header file */
FILE *book_file;


/* open_book() opens the opening book file and initializes the random number
   generator so we play random book moves. */

void open_book()
{
	srand(time(NULL));
	book_file = fopen("book.txt", "r");
	if (!book_file)
		printf("Opening book missing.\n");
}


/* close_book() closes the book file. This is called when the program exits. */

void close_book()
{
	if (book_file)
		fclose(book_file);
	book_file = NULL;
}


/* book_move() returns a book move (in integer format) or -1 if there is no
   book move. */

int book_move()
{
	char line[256];
	char book_line[256];
	int i, j, m;
	int move[50];  /* the possible book moves */
	int count[50];  /* the number of occurrences of each move */
	int moves = 0;
	int total_count = 0;

	if (!book_file || hply > 25)
		return -1;

	/* line is a string with the current line, e.g., "e2e4 e7e5 g1f3 " */
	line[0] = '\0';
	j = 0;
	for (i = 0; i < hply; ++i)
		j += sprintf(line + j, "%s ", move_str(hist_dat[i].m.b));

	/* compare line to each line in the opening book */
	fseek(book_file, 0, SEEK_SET);
	while (fgets(book_line, 256, book_file)) {
		if (book_match(line, book_line)) {

			/* parse the book move that continues the line */
			m = parse_move(&book_line[strlen(line)]);
			if (m == -1)
				continue;
			m = gen_dat[m].m.u;

			/* add the book move to the move list, or update the move's
			   count */
			for (j = 0; j < moves; ++j)
				if (move[j] == m) {
					++count[j];
					break;
				}
			if (j == moves) {
				move[moves] = m;
				count[moves] = 1;
				++moves;
			}
			++total_count;
		}
	}

	/* no book moves? */
	if (moves == 0)
		return -1;

	/* Think of total_count as the set of matching book lines.
	   Randomly pick one of those lines (j) and figure out which
	   move j "corresponds" to. */
	j = rand() % total_count;
	for (i = 0; i < moves; ++i) {
		j -= count[i];
		if (j < 0)
			return move[i];
	}
	return -1;  /* shouldn't get here */
}


/* book_match() returns TRUE if the first part of s2 matches s1. */

BOOL book_match(char *s1, char *s2)
{
	int i;

	for (i = 0; i < (signed int)strlen(s1); ++i)
		if (s2[i] == '\0' || s2[i] != s1[i])
			return FALSE;
	return TRUE;
}
