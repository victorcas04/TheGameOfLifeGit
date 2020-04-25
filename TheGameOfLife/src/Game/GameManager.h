#pragma once

#define _WIN32_WINNT 0x0500
#include <windows.h>

#include "defines.h"
#include <stdlib.h>
#include <iostream>

#include "DataDriven.h"

class CBoard;

#define MAXROWS 40
#define MINROWS 6

#define MAXCOLS 60
#define MINCOLS 14

#define MAXITER 99999
#define MINITER 0

#define MAXTIME 60
#define MINTIME .1

class CGameManager
{
public:
	static CGameManager* getInstance()
	{
		return (!m_instanceGameManager) ? m_instanceGameManager = new CGameManager() : m_instanceGameManager;
	}

	void Init();
	void Update(float dTime);
	void Draw();
	void Shutdown();
	bool InitInput();
	void ResizeScreen();
	bool CreateBoard();
	void FillBoard();
	bool GetIsGameOver();
	void WaitCloseConsole();

protected:

private:
	CGameManager();
	~CGameManager() {}

	void _testInit();

	inline bool _checkNumRows(int nRows);
	inline bool _checkNumCols(int nCols);
	inline bool _checkNumIter(int nIter);
	inline bool _checkTimeUpdates(float timeUpdates);

	HWND mConsole;
	CBoard* mBoard;

	bool bIsGameOver = false;
	bool bMustDraw = true;
	int mInnerIterations = 0;
	float mInnerTimer = 0.0f;

	CDataDriven* mData;

	int mRows;
	int mColumns;
	int mMaxIterations;
	float mTimeBetweenSteps;

	static CGameManager* m_instanceGameManager;
};

