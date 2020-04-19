#pragma once

#include "defines.h"
#include <stdlib.h>
#include <iostream>

class CBoard;

#define MAXROWS 40
#define MINROWS 6

#define MAXCOLS 60
#define MINCOLS 12

#define MAXITER 99999
#define MINITER 0

#define MAXTIME 60
#define MINTIME .1

#define INPUTROWS 24
#define INPUTCOLS 32
#define INPUTITER 1000
#define INPUTTIME .5

class CGameManager
{
public:
	static CGameManager* getInstance()
	{
		return (!m_instanceGameManager) ? m_instanceGameManager = new CGameManager() : m_instanceGameManager;
	}

	void Init();
	bool InitUserInput();
	void ResizeScreen();
	bool CreateBoard();
	void FillBoard();

	void Update(float dTime);
	void Draw();

	bool GetIsGameOver();


protected:

private:
	CGameManager();
	~CGameManager() {}

	void _testInit();

	inline bool _checkNumRows(int nRows);
	inline bool _checkNumCols(int nCols);
	inline bool _checkNumIter(int nIter);
	inline bool _checkTimeUpdates(float timeUpdates);

	CBoard* mBoard;

	bool bIsGameOver = false;
	bool bMustDraw = true;

	int mMaxIterations;
	int mInnerIterations = 0;

	float mTimeBetweenSteps;
	float mInnerTimer = 0.0f;

	int mRows;
	int mColumns;

	static CGameManager* m_instanceGameManager;
};

