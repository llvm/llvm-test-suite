#ifndef DOSGREED_H
#define DOSGREED_H

#include "greed.hpp"

class Dosgreed : public Greed {
		virtual void UpdateScreen (void);
		virtual void Error (int ErrorNo);
		virtual void Error (char *ErrorMsg);

		virtual int ReadFile  (char *pszFileName,
			char *psBuffer, int iSize);
		virtual int WriteFile (char *pszFileName,
			char *psBuffer, int iSize);

	public:
		Dosgreed (uint nXmax, uint nYmax,
				char *pszScoreFile = DEFAULT_SCORE_FILE,
				char *pszSaveFile = DEFAULT_SAVE_FILE)
		: Greed (nXmax, nYmax,
				pszScoreFile, pszSaveFile) {};

		void ShowScore (int HighLight);
		// Highlight = -1 if no high light wanted

		void Setup (void);
		void PlayGame (void);
		virtual void GameEnd (void);

		virtual void FillScreen (void);
		virtual ~Dosgreed () {};
};


// Support functions for PlayGame
extern void MsgAtBot (char *Message);
extern void Sound (void);
extern void SplSound (void);
extern void ShowHelp (void);
extern int GetInteger (void);

extern int SoundFlag;
extern int nLastLine, nLastCol;

#endif			// of DOSGREED_H
