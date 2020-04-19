
#define _WIN32_WINNT 0x0500
#include <windows.h>

#include "GameManager.h"
#include "Board.h"

CGameManager* CGameManager::m_instanceGameManager = nullptr;

CGameManager::CGameManager()
{
#ifdef DRAWDEBUGINFO
	std::cout << "Creating game manager...\n";
#endif
}

void CGameManager::Init()
{
	bIsGameOver = true;
	if (InitInput())
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

bool CGameManager::InitInput()
{
	mData = new CDataDriven();
	mData->ReadBoardFile(FILENAMEBOARD);
	mData->ReadPlayersFile(FILENAMEPLAYERS);

	int inputRows = mData->GetDataRows();
	if (_checkNumRows(inputRows))
	{
		mRows = inputRows;
	}
	else
	{
		return false;
	}

	int inputCols = mData->GetDataCols();
	if (_checkNumCols(inputCols))
	{
		mColumns = inputCols;
	}
	else
	{
		return false;
	}

	int inputIter = mData->GetDataIter();
	if (_checkNumIter(inputIter))
	{
		mMaxIterations = inputIter;
	}
	else
	{
		return false;
	}

	float inputTime = mData->GetDataTime();
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
	mBoard->AddInitPlayers(mData->GetDataPlayersNormal(), CPlayer::PLAYER_TYPE::NORMAL);
	mBoard->AddInitPlayers(mData->GetDataPlayersInmortal(), CPlayer::PLAYER_TYPE::INMORTAL);
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
