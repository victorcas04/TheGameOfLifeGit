
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
	mBoard->Update(dTime);
}

bool CGameManager::GetIsGameOver()
{
	return bIsGameOver;
}
