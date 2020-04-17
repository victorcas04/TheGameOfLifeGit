
#include "GameManager.h"
#include "../Board/Board.h"

CGameManager* CGameManager::m_instanceGameManager = nullptr;

#define TEST
#define DRAW

CGameManager::CGameManager()
{
	std::cout << "GameManager created!\n";
	Init();
	CreateBoard();

#ifdef TEST
	_testInit();
#endif
}

void CGameManager::Init()
{
	// TODO
	// user input
	mRows = 4;
	mColumns = 4;
	mMaxIterations = 3;
	mTimeBetweenSteps = 4.0f;
	// time needs to be in ms
	mTimeBetweenSteps *= 1000;
}

void CGameManager::_testInit()
{
	//CVec2D::Test(mColumns);
	mBoard->AddPlayerToPos(new CVec2D(0, 1));
	mBoard->AddPlayerToPos(new CVec2D(1, 0));
	mBoard->AddPlayerToPos(new CVec2D(1, 1));
	mBoard->AddPlayerToPos(new CVec2D(1, 2));
}

void CGameManager::CreateBoard()
{
	mBoard = new CBoard(mRows, mColumns);
}

void CGameManager::Update(float dTime)
{
	if (mInnerIterations < mMaxIterations)
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
	else
	{
		bIsGameOver = true;
	}
}

void CGameManager::Draw()
{
#ifdef DRAW
	if (bMustDraw)
	{
		// clear screen before each draw
		system("CLS");
		std::cout << "----- Drawing iteration " << mInnerIterations << "\t-----\n";
		bMustDraw = false;
		mBoard->Draw();
	}
#endif
}

bool CGameManager::GetIsGameOver()
{
	return bIsGameOver;
}
