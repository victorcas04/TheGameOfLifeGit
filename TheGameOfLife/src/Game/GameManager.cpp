
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
	mConsole = GetConsoleWindow();

	mData = new CDataDriven();

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
			WaitCloseConsole();
		}
	}
	else
	{
		WaitCloseConsole();
	}
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
			else if (mBoard->GetPopulation() == mBoard->GetSize())
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

void CGameManager::Shutdown()
{
	WaitCloseConsole();
}

bool CGameManager::InitInput()
{
	// BOARD DATA
	std::string boardFilename = CDataDriven::AskFileName(CDataDriven::FILETYPES::BOARD);
	mData->InitBoardStruct();
	if (boardFilename != "random")
	{
		if (!mData->ReadBoardFile(boardFilename)) { return false; }
		int inputRows = mData->GetDataRows();
		if (!_checkNumRows(inputRows))
		{
			std::cout << "ERROR: rows parameter [ " << inputRows << " ] out of range [ " << ROWS_MIN << " , " << ROWS_MAX << "]\n";
			return false;
		}
		mRows = inputRows;

		int inputCols = mData->GetDataCols();
		if (!_checkNumCols(inputCols))
		{
			std::cout << "ERROR: columns parameter [ " << inputCols << " ] out of range [ " << COLUMNS_MIN << " , " << COLUMNS_MAX << "]\n";
			return false;
		}
		mColumns = inputCols;

		int inputIter = mData->GetDataIter();
		if (!_checkNumIter(inputIter))
		{
			std::cout << "ERROR: iterations parameter [ " << inputIter << " ] out of range [ " << ITERATIONS_MIN << " , " << ITERATIONS_MAX << "]\n";
			return false;
		}

		mMaxIterations = inputIter;

		float inputTime = mData->GetDataTime();
		if (!_checkTimeUpdates(inputTime))
		{
			std::cout << "ERROR: time between simulation steps parameter [ " << inputTime << " ] out of range [ " << TIME_MIN << " , " << TIME_MAX << "]\n";
			return false;
		}
		mTimeBetweenSteps = inputTime;
	}
	else
	{
		// TODO: random board
	}

	// PLAYER LIST DATA
	std::string playerListFilename = CDataDriven::AskFileName(CDataDriven::FILETYPES::PLAYERLIST);
	mData->InitPlayerListStruct();
	if (playerListFilename != "random")
	{
		if (!mData->ReadPlayersFile(playerListFilename)) { return false; }
	}
	else
	{
		// TODO: random board
	}
	return true;
}

void CGameManager::ResizeScreen()
{
	RECT r;

	//stores the console's current dimensions
	GetWindowRect(mConsole, &r);
	// resize window to desire size

	// TODO: set good size
	MoveWindow(mConsole, r.left, r.top, (mColumns * 2) * 10, ((mRows + 5) * 2) * 10, TRUE);

	// disable manual resize
	SetWindowLong(mConsole, GWL_STYLE, 
		GetWindowLong(mConsole, GWL_STYLE) & ~(WS_MAXIMIZE | WS_SIZEBOX));
	// disable minimize button
	SetWindowLong(mConsole, GWL_STYLE,
		GetWindowLong(mConsole, GWL_STYLE) & ~WS_MINIMIZEBOX);
	// disable maximize button
	SetWindowLong(mConsole, GWL_STYLE,
		GetWindowLong(mConsole, GWL_STYLE) & ~WS_MAXIMIZEBOX);
}

void CGameManager::_testInit()
{
	//CVec2D::Test(mColumns);
}

bool CGameManager::_checkNumRows(int nRows)
{
	return (nRows <= ROWS_MAX && nRows >= ROWS_MIN);
}

bool CGameManager::_checkNumCols(int nCols)
{
	return (nCols <= COLUMNS_MAX && nCols >= COLUMNS_MIN);
}

bool CGameManager::_checkNumIter(int nIter)
{
	return (nIter <= ITERATIONS_MAX && nIter >= ITERATIONS_MIN);
}

bool CGameManager::_checkTimeUpdates(float timeUpdates)
{
	return (timeUpdates <= TIME_MAX && timeUpdates >= TIME_MIN);
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

bool CGameManager::GetIsGameOver()
{
	return bIsGameOver;
}

void CGameManager::WaitCloseConsole()
{
	while (mConsole != NULL);
}
