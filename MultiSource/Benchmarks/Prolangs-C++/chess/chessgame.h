// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//  Written by Ashok Sreenivasan, TRDDC, Pune, India.  1993.  May be
//  distributed freely, provided this comment is displayed at the top.
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#ifndef __CHESS__

#define __CHESS__

#include "piece.h"

#define GAMEFILE	"chess.gm"
#define MOVEFILE	"move.gm"

enum Colour
{
	CH_WHITE,
	CH_BLACK,
};

class Board;
class Player;

class Pos
{
	public :

		Pos (int a = 0, int b = 0) : x (a), y (b) {}
//		friend class Board;
//		friend class Player;

//	private :

		int x, y;
};

class Piece
{
	public :

		Piece (enum Colour c) : myCol (c) {}
		virtual int Validate (Board *, Pos *, Pos *) = 0;
		virtual enum PieceType Rep () = 0;
		enum Colour myCol;
};

class Board
{
	public :	

		Board ();
		int Move (Pos *from, Pos *to); 
		void Dump ();
		void Retrieve ();
		int Undo ();
		~Board ();

	private :

		Piece ***config/* [8][8]*/;
};

class Pawn : public Piece
{
	public :

		Pawn (enum Colour c) : Piece (c) {}
		int Validate (Board *, Pos *, Pos *){return 1;}
		enum PieceType Rep () 
			{ if (myCol == CH_WHITE) return WPAWN; else return BPAWN; };
};

class Rook : public Piece
{
	public :

		Rook (enum Colour c) : Piece (c) {}
		int Validate (Board *, Pos *, Pos *) {return 1;}
		enum PieceType Rep () 
			{ if (myCol == CH_WHITE) return WROOK; else return BROOK; };
};

class Knight : public Piece
{
	public :

		Knight (enum Colour c) : Piece (c) {}
		int Validate (Board *, Pos *, Pos *){return 1;}
		enum PieceType Rep () 
			{ if (myCol == CH_WHITE) return WKNIGHT; else return BKNIGHT; };
};

class Bishop : public Piece
{
	public :

		Bishop (enum Colour c) : Piece (c) {}
		int Validate (Board *, Pos *, Pos *){return 1;}
		enum PieceType Rep () 
			{ if (myCol == CH_WHITE) return WBISHOP; else return BBISHOP; };
};

class Queen : public Piece
{
	public :

		Queen (enum Colour c) : Piece (c) {}
		int Validate (Board *, Pos *, Pos *){return 1;}
		enum PieceType Rep () 
			{ if (myCol == CH_WHITE) return WQUEEN; else return BQUEEN; };
};

class King : public Piece
{
	public :

		King (enum Colour c) : Piece (c) {}
		int Validate (Board *, Pos *, Pos *){return 1;}
		enum PieceType Rep () 
			{ if (myCol == CH_WHITE) return WKING; else return BKING; };
};

class Player
{
	public :

		Player (char *, enum Colour c = CH_WHITE);
		int Move (Pos *, Pos *);
		int Undo ();
		int Resign ();
		void PaintBoard();
		void SetTurn (char i) { myTurn = i; }
		void Play ();

	private :

		char *name;
		Board *board;
		enum Colour myCol;
		char myTurn;

		void StrToMove (char *, Pos *);
		void GetMove (Pos *);
		void ProcOtherMove ();
		void DumpMove (char *);
		void CreateScratch ();
};

extern char gameNotOver;
extern char firstMove;

void EndGame () {}

#endif	/* __CHESS__ */
