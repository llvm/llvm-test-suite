// Greed header file
// class definition and function prototypes
extern "C" {
char *strcpy(char *str1, char *str2);
char *strcat(char *str1, char *str2);
}

#ifndef GREED_H
#define GREED_H


#ifndef TRUE
#define TRUE -1
#endif

#ifndef FALSE
#define FALSE 0
#endif

const DEFAULT_X = 80;		// default dimensions
const DEFAULT_Y = 24;

// buffer for encoding and decoding etc.
#define BUFFER_SIZE 4096

#define SCORE_CARD_SIZE		(sizeof (Score) * MAX_SCORE)
#define SAVE_FILE_SIZE		BUFFER_SIZE


typedef unsigned int uint;
typedef unsigned char uchar;

const MAX_SCORE = 10;

#define DEFAULT_SCORE_FILE "greed.sco"
#define DEFAULT_SAVE_FILE  "greed.sav"


struct Score {
	char szName [20];
	uint nScore;
	int  iSeed;
};

class Greed {

	private:
		uint nScore;			// current Score
		int iSeed;				// current seed

		char szScoreFile[256];	// the name of the score file
		char szSaveFile[256];	// the name of the save game file

		Score ScoreCard [MAX_SCORE];	// the list of high scores
		// 0 has highest score
		void CheckScore (void);

		int AddScore (int nDeltaX, int nDeltaY);
		// will return the number of moves to make besides adding the score

		int UpdateTable (int nDeltaX, int nDeltaY, int nNumber);
		// will update table with dots

		void FillTable (void);
		// randomly fills the table with the numbers seed is iSeed

		uchar SetPlayTable (uint X, uint Y, uchar Value);
		// to set character in play table
		// Private, cannot let others tamper with play table

	protected:
		uint nXPos, nYPos;	// current X and Y cursor position
		uint nMaxX, nMaxY;	// Max X and Y coordinates
					// coordinates range from 0 - nMax[XY]-1

		char *cPlayTable;	// the two dimensional playing table

		uchar GetPlayTable (uint X, uint Y);
		// to access characters in play table

		// pure virtual functions
		virtual void UpdateScreen (void) = 0;
		virtual void Error (int ErrorNo) = 0;
		virtual void Error (char *ErrorMsg) = 0;
		virtual int ReadFile  (char *pszFileName,
			char *psBuffer, int iSize) = 0;
		virtual int WriteFile (char *pszFileName,
			char *psBuffer, int iSize) = 0;

	public:
		// constructor requires the size of the playing table,
		// the names of the score file and the save file
		Greed (uint nXmax, uint nYmax,
				char *pszScoreFile = DEFAULT_SCORE_FILE,
				char *pszSaveFile  = DEFAULT_SAVE_FILE);

		virtual ~Greed (void);

		void Initialize (void);

		virtual void GameEnd (void) = 0;
		virtual void FillScreen (void) = 0;

		// functions handling scores
		int GetCurrentScore (void);
		Score *GetHighScore (int Pos);
		int IsHighScore (void);
		void InsertHighScore (char *pszName);

		int GetSeed (void);

		int SaveGame (void);
		int RestoreGame (void);

		void NewGame (int iSeed);

		int MoveNorth     (void); int MoveSouth     (void);
		int MoveEast      (void); int MoveWest      (void);
		int MoveNorthEast (void); int MoveNorthWest (void);
		int MoveSouthEast (void); int MoveSouthWest (void);
};


#endif		// of GREED_H
