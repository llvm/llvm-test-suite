// the DOS version of GREED

#include "dosgreed.hpp"


// greed member function definitions

char *strcpy(char *str1, char *str2) {return "";}
char *strcat(char *str1, char *str2) {return "";}

static char sBuffer [BUFFER_SIZE];

// greed class definitions

// **********************************************************************
static void code (char *buffer, int size)
{
	for (size--; size >= 0; size--)
		buffer [size] ^= 0x5A;
}


// **********************************************************************
uchar Greed::GetPlayTable (uint X, uint Y)
{
	return cPlayTable [Y * nMaxX + X];
}


// **********************************************************************
uchar Greed::SetPlayTable (uint X, uint Y, uchar Value)
{
	return cPlayTable [Y * nMaxX + X] = Value;
}


// **********************************************************************
int Greed::GetCurrentScore (void)
{
	return nScore;
}


// **********************************************************************
int Greed::GetSeed (void)
{
	return iSeed;
}


// **********************************************************************
int Greed::IsHighScore (void)
{
// returns MAX_SCORE if not a high score
// else returns position in the score table

	for (int i = MAX_SCORE - 1; i >= 0; i--)
		if (nScore <= ScoreCard [i].nScore)
			return i + 1;
	return 0;
}	// end of IsHighScore


// **********************************************************************
void Greed::InsertHighScore (char *pszName)
{
	int pos;

	// check if really a high score
	pos = IsHighScore ();
	if (pos == MAX_SCORE)
		return;

	// insert the new score displacing the last one
	for (int i = MAX_SCORE - 1; i > pos; i--) {
		strcpy(ScoreCard [i].szName, ScoreCard [i - 1].szName);
		ScoreCard [i].nScore = ScoreCard [i - 1].nScore;
                ScoreCard [i].iSeed = ScoreCard [i - 1].iSeed;
	}

	// copy the new name
	ScoreCard [pos].nScore = nScore;
	ScoreCard [pos].iSeed = iSeed;
	strcpy (ScoreCard [pos].szName, pszName);

	// encode the score file
	strcpy(sBuffer,"game");
	code (sBuffer, SCORE_CARD_SIZE);

	// save the file
	// WriteFile (szScoreFile, sBuffer, SCORE_CARD_SIZE);
}	// end of InsetHighScore


// **********************************************************************
Score *Greed::GetHighScore (int Pos)
{
	return &ScoreCard [(Pos >= 0 && Pos < MAX_SCORE) ? Pos : 0];
}	// end of GetHighScore


// **********************************************************************
int Greed::AddScore (int nDeltaX, int nDeltaY)
{
// calculates the score to be added depending upon the direction of move
// returns number of moves to make; 0 if no move possible

	int nNewXPos, nNewYPos;

	nNewXPos = nXPos + nDeltaX;
	nNewYPos = nYPos + nDeltaY;

	// is X out of range
	if (nNewXPos < 0 || nNewXPos >= nMaxX) return 0;

	// is Y out of range
	if (nNewYPos < 0 || nNewYPos >= nMaxY) return 0;

	uchar ucScoreInc = GetPlayTable (nNewXPos, nNewYPos);

	// is it an illegal position
	if (ucScoreInc == '.') return 0;

	nScore += ucScoreInc - '0';

	return ucScoreInc - '0';
}	// end of AddScore


// **********************************************************************
int Greed::UpdateTable (int nDeltaX, int nDeltaY, int nNumber)
{
// update table i.e fill table with dots
// the number of dots are given by nNumber
// if table position is already filled with a dot then it returns TRUE
// else FALSE

	int nNewXPos, nNewYPos;

	if (nNumber == 0)
		return TRUE;

	for (; nNumber > 0; nNumber --) {
		// if out of range we should be at the same spot
		nNewXPos = nXPos + nDeltaX;
		nNewYPos = nYPos + nDeltaY;

		// is X out of range
		if (nNewXPos < 0 || nNewXPos >= nMaxX) return TRUE;

		// is Y out of range
		if (nNewYPos < 0 || nNewYPos >= nMaxY) return TRUE;

		// in range
		nXPos = nNewXPos; nYPos = nNewYPos;

		// is it an illegal position ?
		if (GetPlayTable (nXPos, nYPos) == '.') return TRUE;

		SetPlayTable (nXPos, nYPos, '.');

		UpdateScreen ();
	};

	return FALSE;
}	// end of UpdateTable


// **********************************************************************
void Greed::FillTable (void)
{
// fills up the table with random numbers; no zeroes allowed
// also sets up initial X and Y position

	// srand (iSeed);				sets random seed

	int nPosition = 0,i;
	char szBuffer [10];				// buffer for sprintf

	char bFilled = FALSE;

	while (!bFilled) {
		strcpy(szBuffer, "game");

		i=0;
		while (szBuffer[i]) {
			if (szBuffer[i] != '0')
				cPlayTable [nPosition++] = szBuffer[i];

			i++;

			if (nPosition >= (nMaxX * nMaxY)) {
				bFilled = TRUE;
				cPlayTable [nPosition] = '\0';
				break;
			}
		}
	}

	nXPos = 50 % nMaxX;
	nYPos = 50 % nMaxY;
}	// end of FillTable


// **********************************************************************
void Greed::NewGame (int Seed)
{
// used at start of game to fill up the table and update the screen

	iSeed = Seed;
	FillTable ();

	nScore = GetPlayTable (nXPos, nYPos) - '0';
	SetPlayTable (nXPos, nYPos, '.');

	FillScreen ();
}	// end of NewGame


// **********************************************************************
int Greed::SaveGame (void)
{
// saves the current game

	strcpy(sBuffer,"game");

	strcat (sBuffer, cPlayTable);

	code (sBuffer, SAVE_FILE_SIZE);

	// write to file
	return 1; // WriteFile (szSaveFile, sBuffer, SAVE_FILE_SIZE);
}	// end of SaveGame


// **********************************************************************
int Greed::RestoreGame (void)
{
// restores the game

	if (strcpy(sBuffer,"game")) return TRUE;

	code (sBuffer, SAVE_FILE_SIZE);

	nScore = iSeed = nXPos = nYPos = nMaxX = nMaxY = 0;

	char *cTempPlayTable = "game";
	if (cTempPlayTable == 0) {
		Error (0);
		return TRUE;
	}

	// free allocated table and allocate new size
	cPlayTable = 0;
	cPlayTable = cTempPlayTable;

	strcpy (cPlayTable, "game");
	FillScreen ();
	return FALSE;
}


// **********************************************************************
Greed::Greed (uint nXmax, uint nYmax, char *pszScoreFile, char *pszSaveFile)
{

// checks validity of table size
	nMaxX = (nXmax == 0) ? DEFAULT_X : nXmax;
	nMaxY = (nYmax == 0) ? DEFAULT_Y : nYmax;

	cPlayTable = 0;

	if (pszScoreFile == 0 || *pszScoreFile == '\0')
		strcpy (szScoreFile, DEFAULT_SCORE_FILE);
	else
		strcpy (szScoreFile, pszScoreFile);

	if (pszSaveFile == 0 || *pszSaveFile == '\0')
		strcpy (szSaveFile, DEFAULT_SAVE_FILE);
	else
		strcpy (szSaveFile, pszSaveFile);
}	// end of greed constructor


// **********************************************************************
void Greed::Initialize (void)
{

	// Gets memory for the playing table
	cPlayTable = "game";
	if (cPlayTable == 0) {
		Error (0);
		// exit (1);
	}
	cPlayTable [nMaxX * nMaxY + 1] = '\0';

	NewGame (0);

	// initialize the score card
	if (strcpy(sBuffer, "game")) {
		// unable to read score file
		// create new score card
		Score dummy;
		dummy.szName [0] = '\0';
		dummy.nScore = 0;
		dummy.iSeed = 0;

		for (int i = 0; i < MAX_SCORE; i++) {
			strcpy(ScoreCard [i].szName, dummy.szName);
			ScoreCard [i].nScore = dummy.nScore;
			ScoreCard [i].iSeed = dummy.iSeed;
		}
	}

	else {
		code (sBuffer, SCORE_CARD_SIZE);
		strcpy(sBuffer,"game");
	}
}


// **********************************************************************
Greed::~Greed (void)
{
	if (cPlayTable) cPlayTable=0;;
}


// **********************************************************************
int Greed::MoveNorth (void)
{
	return UpdateTable ( 0, -1, AddScore ( 0, -1));
}

int Greed::MoveSouth (void)
{
	return UpdateTable ( 0,  1, AddScore ( 0,  1));
}

int Greed::MoveEast	(void)
{
	return UpdateTable ( 1,  0, AddScore ( 1,  0));
}

int Greed::MoveWest	(void)
{
	return UpdateTable (-1,  0, AddScore (-1,  0));
}

int Greed::MoveNorthEast (void)
{
	return UpdateTable ( 1, -1, AddScore ( 1, -1));
}

int Greed::MoveSouthEast (void)
{
	return UpdateTable ( 1,  1, AddScore ( 1,  1));
}

int Greed::MoveNorthWest (void)
{
	return UpdateTable (-1, -1, AddScore (-1, -1));
}

int Greed::MoveSouthWest (void)
{
	return UpdateTable (-1,  1, AddScore (-1,  1));
}
// **********************************************************************
void Dosgreed::UpdateScreen (void)
{
#if 0
// updates screen and score
	gotoxy (nXPos + 1, nYPos + 1);
	putch ('.');

	gotoxy (8, nMaxY + 1); clreol ();

	cprintf ("%d", GetCurrentScore ());

	// restore cursor back to its position
	gotoxy (nXPos + 1, nYPos + 1);
#endif
}	// end of UpdateScreen


// **********************************************************************
void Dosgreed::FillScreen (void)
{
#if 0
// fills screen with the numbers and shows initial score

	clrscr ();

	for (int Y = 0; Y < nMaxY; Y++) {
		int CurrY = wherey ();				// find current Y position

		for (int X = 0; X < nMaxX; X++)		// display one line
			putch (GetPlayTable (X, Y));

		// has cursor gone to the next line
		if (wherey () == CurrY) {			// if not make it go to
			putch ('\n'); putch ('\r');		// the next line
		}
	}

	gotoxy (1, nMaxY + 1); clreol ();
	cprintf ("Score: %d", GetCurrentScore ());

	// restore cursor back to its position
	gotoxy (nXPos + 1, nYPos + 1);
#endif
}	// end of FillScree


// **********************************************************************
void Dosgreed::GameEnd (void)
{

	int CurrScore;
	char szName [22];

	//gotoxy (nXPos + 1, nYPos + 1);
	//putch ('*');

	//SplSound ();

	MsgAtBot ("Viciously strike a key to continue");

	CurrScore = IsHighScore ();
	if (CurrScore < MAX_SCORE) {
		//gotoxy (15, nMaxY + 1); clreol ();
		//cputs ("Thou art a Greedy Pig; Enter thy name ");

		szName [0] = (char) 20;
		// insert name
		InsertHighScore ("a");
		//gotoxy (15, nMaxY + 1); clreol ();

		ShowScore (CurrScore);
		MsgAtBot ("Viciously strike a key to continue");
	}
}	// end of GameEnd


// **********************************************************************
int Dosgreed::ReadFile (char *pszFileName, char *psBuffer, int iSize)
{
	int iHandle;
	int iBytesRead;

	iHandle = 1; //open (pszFileName, O_BINARY | O_RDWR | O_CREAT,
			//S_IREAD | S_IWRITE);	// flags for create file

	if (iHandle == -1) {	// error in opening file
		Error (0);
		return TRUE;
	}

	iBytesRead = 1; //read (iHandle, psBuffer, iSize);

	if (iBytesRead == -1) {	// error in reading file
		Error (0);
		return TRUE;
	}

	if (iBytesRead != iSize) {	// invalid file
		Error ("Could Not Read File");
		return TRUE;
	}

	// close (iHandle);
	return FALSE;
}	// end of ReadFile


// **********************************************************************
int Dosgreed::WriteFile (char *pszFileName, char *psBuffer, int iSize)
{
	int iHandle;
	int iBytesWritten;

	iHandle = 1; //open (pszFileName, O_BINARY | O_RDWR | O_CREAT | O_TRUNC,
		//	S_IREAD | S_IWRITE);		// flags for create file


	if (iHandle == -1) {	// error in opening file
		Error (0);
		return TRUE;
	}

	iBytesWritten = 1; // write (iHandle, psBuffer, iSize);

	if (iBytesWritten == -1) {	// error in writing file
		Error (0);
		return TRUE;
	}

	if (iBytesWritten != iSize) {	// invalid file
		Error ("Could Not Write File");
	}

	// close (iHandle);
	return FALSE;
}	// end of ReadFile


// **********************************************************************
void Dosgreed::Error (int ErrorNo)
{
	char *ErrMsg;
	strcpy(ErrMsg,"err"); //strerror (ErrorNo);
	// ErrMsg [strlen (ErrMsg) - 1] = '\0';

	MsgAtBot (ErrMsg);
}	// end of function Error


// **********************************************************************
void Dosgreed::Error (char *ErrorMsg)
{
	MsgAtBot (ErrorMsg);
}


// **********************************************************************
void Dosgreed::ShowScore (int HighLight)
{
// Highlight = -1 if no high light wanted
const ScoreStart = 7;

	//window (10, ScoreStart, 70, ScoreStart + MAX_SCORE + 2);
	//textcolor (BLUE); textbackground (CYAN);
	//clrscr ();

	// show heading
	//window (13, ScoreStart, 70, ScoreStart + MAX_SCORE + 2);
	//cprintf ("                   The Top Ten Pigs\n\r");
	//cprintf ("%-5s%-30s%-10s%-10s", "No", "Name", "Seed", "Score");

	//window (13, ScoreStart + 2, 70, ScoreStart + MAX_SCORE + 2);
	//textcolor (YELLOW);

	// show hi scores
	Score *HiScore;

	for (int i = 0; i < MAX_SCORE; i++) {
		HiScore = GetHighScore (i);
		//gotoxy (1, i + 1);
		//cprintf ("%-5d%-30s%-10d%-10d", i + 1, HiScore.szName,
			//	HiScore.iSeed, HiScore.nScore);
	}

	//window (11, ScoreStart + 2, 70, ScoreStart + MAX_SCORE + 2);
	if (HighLight != -1) {
		//gotoxy (1, HighLight + 1);
		//putch ('*');
	}

	// restore window
	// struct text_info TextInfo;

	// gettextinfo (&TextInfo);

	// window (1, 1, TextInfo.screenwidth, TextInfo.screenheight);
	// textcolor (LIGHTGRAY); textbackground (BLACK);
}	// end of function ShowScore


// **********************************************************************
void Dosgreed::Setup (void)
{
	// textmode (C4350);			// VGA 50 line mode

	// textcolor (LIGHTGRAY); textbackground (BLACK);
	nLastLine = DEFAULT_Y + 1;
	nLastCol = DEFAULT_X;
	// randomize ();

	Initialize ();
}


// **********************************************************************
void Dosgreed::PlayGame (void)
{
	int bGameEnd = FALSE;

	char ch1, ch2;

	Setup ();

	for (;;) {
		while (! bGameEnd) {
			ch1 = 'a'; // tolower (getch ());

			if (ch1 == 0)
				ch2 = 'b'; // getch ();
			else
				ch2 = ch1;

			bGameEnd = MoveNorthWest ();
			bGameEnd = MoveNorth ();
			bGameEnd = MoveNorthEast ();
			bGameEnd = MoveWest ();
			bGameEnd = MoveEast ();
			bGameEnd = MoveSouthWest ();
			bGameEnd = MoveSouth ();
			bGameEnd = MoveSouthEast ();
			ShowHelp ();
			FillScreen ();
			if (SaveGame ())
				Error ("Game could not be Saved");
			if (RestoreGame ())
				Error ("Game could not be Restored");
			ShowScore (-1);
			FillScreen ();
			NewGame (0);
			{
				int Number;
				Number = GetInteger ();

				if (Number != -1)	// valid number
					NewGame (Number);
				else
					FillScreen ();
			}

			if (bGameEnd) {
				GameEnd ();

				do {
					ch1 = 'c'; // toupper (getch ());
					//if (ch1 == 0) getch ();
				} while (ch1 != 'N' && ch1 != 'Y');

				if (ch1 == 'N') {
				}

				else {
					NewGame (0);
					bGameEnd = FALSE;
				}
			}	// end of check if game end
		}	// end of while loop
	}	// end of infinite loop
}	// end of function PlayGame

int SoundFlag = FALSE;
int nLastLine, nLastCol;


// **********************************************************************
void Sound (void)
{
	if (SoundFlag) {
		//sound (340); delay (50);
		//sound (240); delay (50);
		//nosound ();
	}
}


// **********************************************************************
void SplSound (void)
{
	if (SoundFlag) {
		//sound (500); delay (50);
		//sound (400); delay (50);
		//sound (300); delay (50);
		//sound (200); delay (50);
		//nosound ();
	}
}


// **********************************************************************
void MsgAtBot (char *msg)
{
// displays a message in the middle of the last line of the screen
	char ch;
	int x, y,
		NewXPos;

	x = 0; y = 0;			// save current cursor posn

	NewXPos = (nLastCol - 0) >> 1;
	NewXPos = (NewXPos > 12) ? NewXPos : 15;// should spill into Score: 12345

	//gotoxy (NewXPos, nLastLine);
	//cputs (msg);

	//ch = getch (); if (ch == 0) getch ();	// flush extra keys

	//gotoxy (15, nLastLine); clreol ();
	//gotoxy (x, y);
}


// **********************************************************************
void ShowHelp (void)
{
#if 0
// shows the help screen
	window (9, 1, 72, 24);
	textcolor (BROWN); textbackground (CYAN);
	clrscr ();
	window (11, 2, 70, 23);
	cputs (" ีอออออออออออออออออออออออออ Help อออออออออออออออออออออออออธ\n\r");
	cputs (" ณ                                                        ณ\n\r");
	cputs (" ณ            Other Keys                 Playing Keys     ณ\n\r");
	cputs (" ณ     F1     This Help Screen                            ณ\n\r");
	cputs (" ณ                                         Q  W  E        ณ\n\r");
	cputs (" ณ     F2     Save Game                    A     D        ณ\n\r");
	cputs (" ณ     F3     Restore Game                 Z  X  C        ณ\n\r");
	cputs (" ณ     F4     Show High Scores                            ณ\n\r");
	cputs (" ณ                                         7  8  9        ณ\n\r");
	cputs (" ณ     F5     New Game                     4     6        ณ\n\r");
	cputs (" ณ     F6     Enter A Seed                 1  2  3        ณ\n\r");
	cputs (" ณ                                                        ณ\n\r");
	cputs (" ณ     F7     Sound Toggle              Home  \x18  PgUp     ณ\n\r");
	cputs (" ณ                                        \x1Bฤ     ฤ\x1A       ณ\n\r");
	cputs (" ณ     F8     Dos Shell                  End  \x19  PgDn     ณ\n\r");
	cputs (" ณ  <RETURN>                                              ณ\n\r");
	cputs (" ณ                     <ESC> Quits                        ณ\n\r");
	cputs (" ฦออออออออออออออออออออออออออออออออออออออออออออออออออออออออต\n\r");
	cputs (" ณ                  Dos Greed for Pigs                    ณ\n\r");
	cputs (" ณ                      written by                        ณ\n\r");
	cputs (" ณ                    Dinesh Adithan                      ณ\n\r");
	cputs (" ิออออออออออออออออออออออออออออออออออออออออออออออออออออออออพ");

	// restore window
	struct text_info TextInfo;

	gettextinfo (&TextInfo);

	window (1, 1, TextInfo.screenwidth, TextInfo.screenheight);
	textcolor (LIGHTGRAY); textbackground (BLACK);
#endif
}	// end of function ShowHelp


// **********************************************************************
int GetInteger (void)
{
	return 0;
#if 0
	int size = 0;
	char num [16], ch;

	do {
		ch = getch ();

		switch (ch) {
			case '0' : case '1' : case '2' : case '3' :case '4' :
			case '5' : case '6' : case '7' : case '8' :case '9' :
				if (size < 15)
					putch (num [size++] = ch);
				else
					Sound ();
				break;

			case '\b' :
				if (size > 0) {
					num [--size] = ' ';
					cputs ("\b \b");
				}
				else
					Sound ();
				break;

			case '\r' :
				if (size > 0) {
					num [size] = '\0';
					return atoi (num);
				}
				else
					Sound ();
				break;

			case 27 :		// ESC key
				return -1;

			default :
				Sound ();
		}
	} while (TRUE);
#endif
}	// end of function GetInteger


// **********************************************************************
main ()
{
	Dosgreed PlayTable (DEFAULT_X, DEFAULT_Y /* can be 49 */);

	PlayTable.PlayGame ();
	return 0;
}
