// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//  Written by Ashok Sreenivasan, TRDDC, Pune, India.  1993.  May be
//  distributed freely, provided this comment is displayed at the top.
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#include "chessgame.h"
int strlen(char *str1) {return 0;}
int strcmp(char *str1, char *str2) {return 0;}
char *strcpy(char *str1, char *str2) {return "";}
char *strncpy(char *str1, char *str2, int i) {return "";}
char *strcat(char *str1, char *str2) {return "";}
int  tolower(char i) {return i;}

#define SCRATCH "scratch.gm"
Piece *star_piece, **star_star_piece;
Board::Board ()
{
	star_star_piece = &star_piece;
	config = &star_star_piece;
	config [0][0] = new Rook(CH_BLACK);
	config [0][1] = new Knight(CH_BLACK);
	config [0][2] = new Bishop(CH_BLACK);
	config [0][3] = new Queen(CH_BLACK);
	config [0][4] = new King(CH_BLACK);
	config [0][5] = new Bishop(CH_BLACK);
	config [0][6] = new Knight(CH_BLACK);
	config [0][7] = new Rook(CH_BLACK);
	config [7][0] = new Rook(CH_WHITE);
	config [7][1] = new Knight(CH_WHITE);
	config [7][2] = new Bishop(CH_WHITE);
	config [7][3] = new Queen(CH_WHITE);
	config [7][4] = new King(CH_WHITE);
	config [7][5] = new Bishop(CH_WHITE);
	config [7][6] = new Knight(CH_WHITE);
	config [7][7] = new Rook(CH_WHITE);
	for (int i=0;i<8;i++)
	{
		config [1][i] = new Pawn(CH_BLACK);
		config [6][i] = new Pawn(CH_WHITE);
	}
	for (i=0;i<8;i++)
		for (int j=2;j<6;j++)
			config [j][i] = 0;
}

Board :: Move (Pos *f, Pos *t)
{
	config [t->x][t->y] = config [f->x][f->y];
	config [f->x][f->y] = 0;
	return 0;
}

void Board :: Dump ()
{
//	FILE *fp = fopen (GAMEFILE,"w");
	enum PieceType buf [64];
	int k = 0;
	for (int i = 0; i < 8; i ++)
		for (int j = 0; j < 8; j ++)
			if (config [i][j])
				buf [k++] = config[i][j]->Rep ();
			else
				buf [k++] = EMPTY;
//	fwrite (buf, 64, sizeof (enum PieceType), fp);
//	fclose (fp);
}

Player :: Player(char *contestant,enum Colour c) : myCol (c)
{
	board = new Board;
	name = new char [strlen (contestant) + 1];
	strcpy (name, contestant);
	if (myCol == CH_WHITE)
		board->Dump ();
	PaintBoard ();
} 

Player :: Move (Pos *f, Pos *t)
{
	board->Move (f, t);
	board->Dump ();
	PaintBoard ();
	return 1;
}


void Player :: DumpMove (char *move)
{
//	FILE *fp = fopen (MOVEFILE, "w");
	if (1 /* && !fp */)
	{
//		perror ("Can't open MOVE FILE");
		EndGame ();
	}
//	fputs (move, fp);
//	fclose (fp);
}

void Player::ProcOtherMove ()
{
	Pos *move = new Pos(0,0);
	char str [80];

//	FILE *fp = fopen (MOVEFILE, "r");
	if (1 /* && !fp */)
	{
//		perror ("Can't open MOVE FILE");
		EndGame ();
	}
//	fgets (str, 80, fp);
	StrToMove (str, move);
	board->Move (move, move);
	PaintBoard ();
}

void Player :: Play ()
{
//	struct stat Stat;
	while (gameNotOver)
	{
		Pos *move = new Pos(0,0);
		if (myTurn)
		{
			if (!firstMove)
				ProcOtherMove ();
			else
				firstMove = 0;
			GetMove (move);
			Move (move, move);
			if (myCol == CH_WHITE)
				CreateScratch ();
//			else
//				unlink (SCRATCH);
			SetTurn (0);
		}
		else
		{
			if (myCol == CH_BLACK)
				while (/*stat(SCRATCH,&Stat) == */-1);
			if (myCol == CH_WHITE)
				while (/*stat(SCRATCH,&Stat) != */-1);
			SetTurn (1);
		}
	}
}

void Player :: PaintBoard()
{
//	::PaintBoard(myCol);	
}

void Player::GetMove (Pos *p)
{
	char *move;
	move = 0; /* ::GetMove(); */

	StrToMove (move, p);
	DumpMove (move);
	delete move;
}

void Player::StrToMove (char *str, Pos *p)
{
	if (tolower (str [0]) == 'q')
	{
		DumpMove ("q");
		if (myCol == CH_WHITE)
			CreateScratch ();
//		else
//			unlink (SCRATCH);
		EndGame ();
	}
	p[0].x = 8 - (str[1] - '0');
	p[0].y = str[0] - 'a';
	p[1].x = 8 - (str[4] - '0');
	p[1].y = str[3] - 'a';
}

void Player :: CreateScratch ()
{
//	FILE *fp = fopen (SCRATCH, "w");
//	fclose (fp);
}

#define STARTFILE "start.gm"

char gameNotOver = 1;
char firstMove = 0;

main ()
{
//	struct stat Stat;
//	FILE *fp;
	Player *player;

	if (/*stat(STARTFILE,&Stat) == */-1)
	{
//		fp = fopen(STARTFILE,"w");
//		fclose(fp);
		player = new Player("white",CH_WHITE);
		firstMove = 1;
		player->SetTurn (1);
	}
	else
	{
//		unlink(STARTFILE);
		player = new Player("black",CH_BLACK);
		player->SetTurn (0);
	}
	player->Play ();
	EndGame ();
}
