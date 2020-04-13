
#include "GameManager.h"
#include "../Board/Board.h"

CGameManager* CGameManager::m_instanceGameManager = nullptr;

CGameManager::CGameManager()
{
	std::cout << "GameManager created!\n";
	mBoard = new CBoard();
}

void CGameManager::Update(float dTime)
{
	mInnerTimer += dTime;
	if (mInnerTimer >= mTimeBetweenSteps)
	{
		mInnerTimer = 0.0f;
		mBoard->Update(dTime);
	}
}

void CGameManager::Draw()
{
	// TODO: optimization if not updated (?)
	mBoard->Draw();
}

bool CGameManager::GetIsGameOver()
{
	return bIsGameOver;
}
