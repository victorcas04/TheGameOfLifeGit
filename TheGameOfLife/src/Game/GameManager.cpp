
#define _WIN32_WINNT 0x0500
#include <windows.h>

#include "GameManager.h"
#include "Board.h"

CGameManager* CGameManager::m_instanceGameManager = nullptr;

//#define TEST
#define DRAW
#define CLEANSCREEN
//#define DEBUGINFO

CGameManager::CGameManager()
{
#ifdef DEBUGINFO
	std::cout << "Creating game manager...\n";
#endif
}

void CGameManager::Init()
{
	bIsGameOver = true;
	if (InitUserInput())
	{
		// time needs to be in ms
		mTimeBetweenSteps *= 1000;
		ResizeScreen();

		if (CreateBoard())
		{
			FillBoard();
#ifdef TEST
			_testInit();
#endif
			bIsGameOver = false;
		}
		else
		{
			std::cout << "ERROR: cannot create board.\n";
		}
	}
	else
	{
		std::cout << "ERROR: wrong input parameters.\n";
	}
}

bool CGameManager::InitUserInput()
{
	// TODO: add user input
	// TODO: data driven
	int inputRows = 24;
	if (_checkNumRows(inputRows))
	{
		mRows = inputRows;
	}
	else
	{
		return false;
	}

	int inputCols = 32;
	if (_checkNumCols(inputCols))
	{
		mColumns = inputCols;
	}
	else
	{
		return false;
	}

	int inputIter = 1000;
	if (_checkNumIter(inputIter))
	{
		mMaxIterations = inputIter;
	}
	else
	{
		return false;
	}

	float inputTime = 2.0f;
	if (_checkTimeUpdates(inputTime))
	{
		mTimeBetweenSteps = inputTime;
	}
	else
	{
		return false;
	}

	return true;
}

void CGameManager::ResizeScreen()
{
	HWND console = GetConsoleWindow();
	RECT r;

	//stores the console's current dimensions
	GetWindowRect(console, &r);
	// resize window to desire size

	// TODO: set good size
	MoveWindow(console, r.left, r.top, (mColumns * 2) * 10, ((mRows + 5) * 2) * 10, TRUE);

	// disable manual resize
	SetWindowLong(console, GWL_STYLE, 
		GetWindowLong(console, GWL_STYLE) & ~(WS_MAXIMIZE | WS_SIZEBOX));
	// disable minimize button
	SetWindowLong(console, GWL_STYLE,
		GetWindowLong(console, GWL_STYLE) & ~WS_MINIMIZEBOX);
	// disable maximize button
	SetWindowLong(console, GWL_STYLE,
		GetWindowLong(console, GWL_STYLE) & ~WS_MAXIMIZEBOX);
}

void CGameManager::_testInit()
{
	//CVec2D::Test(mColumns);
}

bool CGameManager::_checkNumRows(int nRows)
{
	return (nRows <= MAXROWS && nRows >= MINROWS);
}

bool CGameManager::_checkNumCols(int nCols)
{
	return (nCols <= MAXCOLS && nCols >= MINCOLS);
}

bool CGameManager::_checkNumIter(int nIter)
{
	return (nIter <= MAXITER && nIter >= MINITER);
}

bool CGameManager::_checkTimeUpdates(float timeUpdates)
{
	return (timeUpdates <= MAXTIME && timeUpdates >= MINTIME);
}

bool CGameManager::CreateBoard()
{
	mBoard = new CBoard(mRows, mColumns);
	return (mBoard != nullptr);
}

void CGameManager::FillBoard()
{
	// TODO: add user input
	// TODO: data driven
	std::list<CVec2D*> listInitPosNormal = {
		new CVec2D(0, 1) ,
		new CVec2D(1, 0) ,
		new CVec2D(1, 1) ,
		new CVec2D(1, 2) };
	std::list<CVec2D*> listInitPosInmortal = {
		new CVec2D(3, 0) ,
		new CVec2D(3, 3) };
	mBoard->AddInitPlayers(listInitPosNormal, listInitPosInmortal);
}

void CGameManager::Update(float dTime)
{
	if (mInnerIterations >= mMaxIterations || 
		mBoard->GetPopulation() == 0 || 
		mBoard->GetPopulation() == mBoard->GetSize() ||
		mBoard->IsStabilized())
	{
		bIsGameOver = true;
		bMustDraw = true;
	}
	else
	{
		mInnerTimer += dTime;
		if (mInnerTimer >= mTimeBetweenSteps)
		{
			mInnerTimer = 0.0f;
			++mInnerIterations;
			bMustDraw = true;
			mBoard->Update(dTime);
		}
	}
}

void CGameManager::Draw()
{
#ifdef DRAW
	if (bMustDraw)
	{
#ifdef CLEANSCREEN
		// clear screen before each draw
		system("CLS");
#endif
		bMustDraw = false;
		mBoard->Draw();

		if (!bIsGameOver)
		{
			std::cout << "\n    RUNNING SIMULATION!\n";
		}
		else
		{
			if (mBoard->GetPopulation() == 0)
			{
				std::cout << "\n YOUR CIVILIZATION IS DEAD!\n";
			}
			else if(mBoard->GetPopulation() == mBoard->GetSize())
			{
				std::cout << "\n YOU CONQUERED ALL THE LAND!\n";
			}
			else if (mBoard->IsStabilized())
			{
				std::cout << "\n THE POPULATION STABILIZED!\n";
			}
			else
			{
				std::cout << "\n YOU SURVIVED THE SIMULATION!\n";
			}
		}
		std::cout << " ITERATIONS - " << mInnerIterations << " -" << " POPULATION - " << mBoard->GetPopulation() << " -\n";
	}
#endif
}

bool CGameManager::GetIsGameOver()
{
	return bIsGameOver;
}
