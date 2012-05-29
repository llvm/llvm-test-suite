/*
 *	MAIN.C
 *	Tom Kerrigan's Simple Chess Program (TSCP)
 *
 *	Copyright 1997 Tom Kerrigan
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "defs.h"
#include "data.h"
#include "protos.h"


#if 0
/* get_ms() returns the milliseconds elapsed since midnight,
   January 1, 1970. */

#include <sys/timeb.h>
BOOL ftime_ok = FALSE;  /* does ftime return milliseconds? */
int get_ms()
{
	struct timeb timebuffer;
	ftime(&timebuffer);
	if (timebuffer.millitm != 0)
		ftime_ok = TRUE;
	return (timebuffer.time * 1000) + timebuffer.millitm;
}
#endif


/* main() is basically an infinite loop that either calls
   think() when it's the computer's turn to move or prompts
   the user for a command (and deciphers it). */

int main()
{
	int computer_side;
	char s[256];
	int m;

	printf("\n");
	printf("Tom Kerrigan's Simple Chess Program (TSCP)\n");
	printf("version 1.81, 2/5/03\n");
	printf("Copyright 1997 Tom Kerrigan\n");
	printf("\n");
	printf("\"help\" displays a list of commands.\n");
	printf("\n");
	init_hash();
	init_board();
	open_book();
	gen();
	computer_side = EMPTY;
	max_time = 1 << 25;
	max_depth = 4;
#if 1
        bench();
#else
	for (;;) {
		if (side == computer_side) {  /* computer's turn */
			
			/* think about the move and make it */
			think(1);
			if (!pv[0][0].u) {
				printf("(no legal moves)\n");
				computer_side = EMPTY;
				continue;
			}
			printf("Computer's move: %s\n", move_str(pv[0][0].b));
			makemove(pv[0][0].b);
			ply = 0;
			gen();
			print_result();
			continue;
		}

		/* get user input */
		printf("tscp> ");
		if (scanf("%s", s) == EOF)
			return 0;
		if (!strcmp(s, "on")) {
			computer_side = side;
			continue;
		}
		if (!strcmp(s, "off")) {
			computer_side = EMPTY;
			continue;
		}
		if (!strcmp(s, "st")) {
			scanf("%d", &max_time);
			max_time *= 1000;
			max_depth = 32;
			continue;
		}
		if (!strcmp(s, "sd")) {
			scanf("%d", &max_depth);
			max_time = 1 << 25;
			continue;
		}
		if (!strcmp(s, "undo")) {
			if (!hply)
				continue;
			computer_side = EMPTY;
			takeback();
			ply = 0;
			gen();
			continue;
		}
		if (!strcmp(s, "new")) {
			computer_side = EMPTY;
			init_board();
			gen();
			continue;
		}
		if (!strcmp(s, "d")) {
			print_board();
			continue;
		}
		if (!strcmp(s, "bench")) {
			computer_side = EMPTY;
			bench();
			continue;
		}
		if (!strcmp(s, "bye")) {
			printf("Share and enjoy!\n");
			break;
		}
		if (!strcmp(s, "xboard")) {
			xboard();
			break;
		}
		if (!strcmp(s, "help")) {
			printf("on - computer plays for the side to move\n");
			printf("off - computer stops playing\n");
			printf("st n - search for n seconds per move\n");
			printf("sd n - search n ply per move\n");
			printf("undo - takes back a move\n");
			printf("new - starts a new game\n");
			printf("d - display the board\n");
			printf("bench - run the built-in benchmark\n");
			printf("bye - exit the program\n");
			printf("xboard - switch to XBoard mode\n");
			printf("Enter moves in coordinate notation, e.g., e2e4, e7e8Q\n");
			continue;
		}

		/* maybe the user entered a move? */
		m = parse_move(s);
		if (m == -1 || !makemove(gen_dat[m].m.b))
			printf("Illegal move.\n");
		else {
			ply = 0;
			gen();
			print_result();
		}
	}
#endif
	close_book();
	return 0;
}


/* parse the move s (in coordinate notation) and return the move's
   index in gen_dat, or -1 if the move is illegal */

int parse_move(char *s)
{
	int from, to, i;

	/* make sure the string looks like a move */
	if (s[0] < 'a' || s[0] > 'h' ||
			s[1] < '0' || s[1] > '9' ||
			s[2] < 'a' || s[2] > 'h' ||
			s[3] < '0' || s[3] > '9')
		return -1;

	from = s[0] - 'a';
	from += 8 * (8 - (s[1] - '0'));
	to = s[2] - 'a';
	to += 8 * (8 - (s[3] - '0'));

	for (i = 0; i < first_move[1]; ++i)
		if (gen_dat[i].m.b.from == from && gen_dat[i].m.b.to == to) {

			/* if the move is a promotion, handle the promotion piece;
			   assume that the promotion moves occur consecutively in
			   gen_dat. */
			if (gen_dat[i].m.b.bits & 32)
				switch (s[4]) {
					case 'N':
						return i;
					case 'B':
						return i + 1;
					case 'R':
						return i + 2;
					default:  /* assume it's a queen */
						return i + 3;
				}
			return i;
		}

	/* didn't find the move */
	return -1;
}


/* move_str returns a string with move m in coordinate notation */

char *move_str(move_bytes m)
{
	static char str[6];

	char c;

	if (m.bits & 32) {
		switch (m.promote) {
			case KNIGHT:
				c = 'n';
				break;
			case BISHOP:
				c = 'b';
				break;
			case ROOK:
				c = 'r';
				break;
			default:
				c = 'q';
				break;
		}
		sprintf(str, "%c%d%c%d%c",
				COL(m.from) + 'a',
				8 - ROW(m.from),
				COL(m.to) + 'a',
				8 - ROW(m.to),
				c);
	}
	else
		sprintf(str, "%c%d%c%d",
				COL(m.from) + 'a',
				8 - ROW(m.from),
				COL(m.to) + 'a',
				8 - ROW(m.to));
	return str;
}


/* print_board() prints the board */

void print_board()
{
	int i;
	
	printf("\n8 ");
	for (i = 0; i < 64; ++i) {
		switch (color[i]) {
			case EMPTY:
				printf(" .");
				break;
			case LIGHT:
				printf(" %c", piece_char[piece[i]]);
				break;
			case DARK:
				printf(" %c", piece_char[piece[i]] + ('a' - 'A'));
				break;
		}
		if ((i + 1) % 8 == 0 && i != 63)
			printf("\n%d ", 7 - ROW(i));
	}
	printf("\n\n   a b c d e f g h\n\n");
}


/* xboard() is a substitute for main() that is XBoard
   and WinBoard compatible. See the following page for details:
   http://www.research.digital.com/SRC/personal/mann/xboard/engine-intf.html */

void xboard()
{
	int computer_side;
	char line[256], command[256];
	int m;
	int post = 0;

	signal(SIGINT, SIG_IGN);
	printf("\n");
	init_board();
	gen();
	computer_side = EMPTY;
	for (;;) {
		fflush(stdout);
		if (side == computer_side) {
			think(post);
			if (!pv[0][0].u) {
				computer_side = EMPTY;
				continue;
			}
			printf("move %s\n", move_str(pv[0][0].b));
			makemove(pv[0][0].b);
			ply = 0;
			gen();
			print_result();
			continue;
		}
		if (!fgets(line, 256, stdin))
			return;
		if (line[0] == '\n')
			continue;
		sscanf(line, "%s", command);
		if (!strcmp(command, "xboard"))
			continue;
		if (!strcmp(command, "new")) {
			init_board();
			gen();
			computer_side = DARK;
			continue;
		}
		if (!strcmp(command, "quit"))
			return;
		if (!strcmp(command, "force")) {
			computer_side = EMPTY;
			continue;
		}
		if (!strcmp(command, "white")) {
			side = LIGHT;
			xside = DARK;
			gen();
			computer_side = DARK;
			continue;
		}
		if (!strcmp(command, "black")) {
			side = DARK;
			xside = LIGHT;
			gen();
			computer_side = LIGHT;
			continue;
		}
		if (!strcmp(command, "st")) {
			sscanf(line, "st %d", &max_time);
			max_time *= 1000;
			max_depth = 32;
			continue;
		}
		if (!strcmp(command, "sd")) {
			sscanf(line, "sd %d", &max_depth);
			max_time = 1 << 25;
			continue;
		}
		if (!strcmp(command, "time")) {
			sscanf(line, "time %d", &max_time);
			max_time *= 10;
			max_time /= 30;
			max_depth = 32;
			continue;
		}
		if (!strcmp(command, "otim")) {
			continue;
		}
		if (!strcmp(command, "go")) {
			computer_side = side;
			continue;
		}
		if (!strcmp(command, "hint")) {
			think(0);
			if (!pv[0][0].u)
				continue;
			printf("Hint: %s\n", move_str(pv[0][0].b));
			continue;
		}
		if (!strcmp(command, "undo")) {
			if (!hply)
				continue;
			takeback();
			ply = 0;
			gen();
			continue;
		}
		if (!strcmp(command, "remove")) {
			if (hply < 2)
				continue;
			takeback();
			takeback();
			ply = 0;
			gen();
			continue;
		}
		if (!strcmp(command, "post")) {
			post = 2;
			continue;
		}
		if (!strcmp(command, "nopost")) {
			post = 0;
			continue;
		}
		m = parse_move(line);
		if (m == -1 || !makemove(gen_dat[m].m.b))
			printf("Error (unknown command): %s\n", command);
		else {
			ply = 0;
			gen();
			print_result();
		}
	}
}


/* print_result() checks to see if the game is over, and if so,
   prints the result. */

void print_result()
{
	int i;

	/* is there a legal move? */
	for (i = 0; i < first_move[1]; ++i)
		if (makemove(gen_dat[i].m.b)) {
			takeback();
			break;
		}
	if (i == first_move[1]) {
		if (in_check(side)) {
			if (side == LIGHT)
				printf("0-1 {Black mates}\n");
			else
				printf("1-0 {White mates}\n");
		}
		else
			printf("1/2-1/2 {Stalemate}\n");
	}
	else if (reps() == 3)
		printf("1/2-1/2 {Draw by repetition}\n");
	else if (fifty >= 100)
		printf("1/2-1/2 {Draw by fifty move rule}\n");
}


/* bench: This is a little benchmark code that calculates how many
   nodes per second TSCP searches.
   It sets the position to move 17 of Bobby Fischer vs. J. Sherwin,
   New Jersey State Open Championship, 9/2/1957.
   Then it searches five ply three times. It calculates nodes per
   second from the best time. */

int bench_color[64] = {
	6, 1, 1, 6, 6, 1, 1, 6,
	1, 6, 6, 6, 6, 1, 1, 1,
	6, 1, 6, 1, 1, 6, 1, 6,
	6, 6, 6, 1, 6, 6, 0, 6,
	6, 6, 1, 0, 6, 6, 6, 6,
	6, 6, 0, 6, 6, 6, 0, 6,
	0, 0, 0, 6, 6, 0, 0, 0,
	0, 6, 0, 6, 0, 6, 0, 6
};

int bench_piece[64] = {
	6, 3, 2, 6, 6, 3, 5, 6,
	0, 6, 6, 6, 6, 0, 0, 0,
	6, 0, 6, 4, 0, 6, 1, 6,
	6, 6, 6, 1, 6, 6, 1, 6,
	6, 6, 0, 0, 6, 6, 6, 6,
	6, 6, 0, 6, 6, 6, 0, 6,
	0, 0, 4, 6, 6, 0, 2, 0,
	3, 6, 2, 6, 3, 6, 5, 6
};

void bench()
{
	int i;
	int t[3];
	double nps;

	/* setting the position to a non-initial position confuses the opening
	   book code. */
	close_book();

	for (i = 0; i < 64; ++i) {
		color[i] = bench_color[i];
		piece[i] = bench_piece[i];
	}
	side = LIGHT;
	xside = DARK;
	castle = 0;
	ep = -1;
	fifty = 0;
	ply = 0;
	hply = 0;
	set_hash();
	print_board();
	max_time = 1 << 25;
	max_depth = 5;
	for (i = 0; i < 3; ++i) {
		think(1);
#if 0
		t[i] = get_ms() - start_time;
		printf("Time: %d ms\n", t[i]);
#endif
	}
#if 0
	if (t[1] < t[0])
		t[0] = t[1];
	if (t[2] < t[0])
		t[0] = t[2];
	printf("\n");
	printf("Nodes: %d\n", nodes);
	printf("Best time: %d ms\n", t[0]);
	if (!ftime_ok) {
		printf("\n");
		printf("Your compiler's ftime() function is apparently only accurate\n");
		printf("to the second. Please change the get_ms() function in main.c\n");
		printf("to make it more accurate.\n");
		printf("\n");
		return;
	}
	if (t[0] == 0) {
		printf("(invalid)\n");
		return;
	}
	nps = (double)nodes / (double)t[0];
	nps *= 1000.0;

	/* Score: 1.000 = my Athlon XP 2000+ */
	printf("Nodes per second: %d (Score: %.3f)\n", (int)nps, (float)nps/243169.0);
#endif

	init_board();
	open_book();
	gen();
}
