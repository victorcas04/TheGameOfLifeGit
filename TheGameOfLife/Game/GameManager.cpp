
#include "GameManager.h"
#include "../Board/Board.h"

CGameManager* CGameManager::m_instanceGameManager = nullptr;

CGameManager::CGameManager()
{
	std::cout << "GameManager created!\n";
	Init();
	CreateBoard();

	_demoInit();
}

void CGameManager::Init()
{
	// TODO
	// user input
	mRows = 8;
	mColumns = 10;
	mMaxIterations = 1;
	mTimeBetweenSteps = 1.0f;
	// time needs to be in ms
	mTimeBetweenSteps *= 1000;
}

void CGameManager::_demoInit()
{
	CVec2D* test2D = new CVec2D(7, 9);
	int test2Dint = CVec2D::Pos2DToPos(test2D, mColumns);
	std::cout << "test2d: " << test2D->ToString() << " - test2dint: " << test2Dint << "\n";
	

	int test = 79;
	CVec2D* testto2D = CVec2D::PosToPos2D(test, mColumns);
	std::cout << "test: " << test << " - testto2d: " << testto2D->ToString() << "\n";
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
	if (bMustDraw)
	{
		std::cout << "----- Drawing iteration " << mInnerIterations << "\t-----\n";
		bMustDraw = false;
		mBoard->Draw();
	}
}

bool CGameManager::GetIsGameOver()
{
	return bIsGameOver;
}
