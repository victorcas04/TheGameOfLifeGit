#pragma once

#define _WIN32_WINNT 0x0500
#include <windows.h>

#include "defines.h"
#include <stdlib.h>
#include <iostream>
#include <iomanip>		// std::setprecision

#include "DataDriven.h"

class CBoard;

class CGameManager
{
public:
	static CGameManager* getInstance()
	{
		return (!m_instanceGameManager) ? m_instanceGameManager = new CGameManager() : m_instanceGameManager;
	}

	// default
	void Init();
	void Update(float dTime);
	void Draw();
	void Shutdown();

	// other
	bool InitInput();
	bool GetIsGameOver();

	// board
	bool CheckBoardData();
	bool CreateBoard();
	void FillBoard();

	// window
	void ResizeScreen();
	void WaitCloseConsole();

protected:

private:
	CGameManager();
	~CGameManager() {}

	// test
	void _testInit();

	// checks
	inline bool _checkNumRows(int nRows);
	inline bool _checkNumCols(int nCols);
	inline bool _checkNumIter(int nIter);
	inline bool _checkTimeUpdates(float timeUpdates);

	// window
	HWND mConsole;

	// other
	bool bIsGameOver = false;
	bool bMustDraw = true;
	CDataDriven* mData;

	// board
	CBoard* mBoard;
	int mRows;
	int mColumns;
	int mIterations;
	int mInnerIterations = 0;
	float mTime;
	float mInnerTimer = 0.0f;

	static CGameManager* m_instanceGameManager;
};

