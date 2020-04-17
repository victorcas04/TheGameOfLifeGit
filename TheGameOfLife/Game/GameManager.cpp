
#include "GameManager.h"
#include "../Board/Board.h"

CGameManager* CGameManager::m_instanceGameManager = nullptr;

//#define TEST
#define DRAW
#define CLEANSCREEN
//#define DEBUGINFO

CGameManager::CGameManager()
{
#ifdef DEBUGINFO
	std::cout << "GameManager created!\n";
#endif
	Init();
	CreateBoard();
	FillBoard();
#ifdef TEST
	_testInit();
#endif
}

void CGameManager::Init()
{
	// TODO
	// user input
	mRows = 6;
	mColumns = 12;
	mMaxIterations = 10000;
	mTimeBetweenSteps = 1.0f;
	// time needs to be in ms
	mTimeBetweenSteps *= 1000;
}

void CGameManager::_testInit()
{
	//CVec2D::Test(mColumns);
}

void CGameManager::CreateBoard()
{
	mBoard = new CBoard(mRows, mColumns);
}

void CGameManager::FillBoard()
{
	std::list<CVec2D*> listInitPos = {
		new CVec2D(0, 1),
		new CVec2D(1, 0) ,
		new CVec2D(1, 1) ,
		new CVec2D(1, 2) };
	mBoard->AddInitPlayers(listInitPos);
}

void CGameManager::Update(float dTime)
{
	if (mInnerIterations < mMaxIterations)
	{
		if (mBoard->GetPopulation() == 0)
		{
			std::cout << "\nYOUR CIVILIZATION IS DEAD!\n";
			bIsGameOver = true;
		}
		else if (mBoard->GetPopulation() == mBoard->GetSize())
		{
			std::cout << "\nYOU CONQUERED ALL THE LAND!\n";
			bIsGameOver = true;
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
#ifdef CLEANSCREEN
		// clear screen before each draw
		system("CLS");
#endif
#ifdef DEBUGINFO
		std::cout << "----- Drawing iteration " << mInnerIterations << "\t-----\n";
#endif
		bMustDraw = false;
		mBoard->Draw();
	}
#endif
}

bool CGameManager::GetIsGameOver()
{
	return bIsGameOver;
}
