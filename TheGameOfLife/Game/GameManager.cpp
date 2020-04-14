
#include "GameManager.h"
#include "../Board/Board.h"

CGameManager* CGameManager::m_instanceGameManager = nullptr;

CGameManager::CGameManager()
{
	std::cout << "GameManager created!\n";
	Init();
	CreateBoard();
}

void CGameManager::Init()
{
	// TODO
	// user input
	mTimeBetweenSteps = 1.0f;
	// time needs to be in ms
	mTimeBetweenSteps *= 1000;
	mRows = 4;
	mColumns = 4;
}

void CGameManager::CreateBoard()
{
	mBoard = new CBoard();
}

void CGameManager::Update(float dTime)
{
	mInnerTimer += dTime;
	if (mInnerTimer >= mTimeBetweenSteps)
	{
		std::cout << "Updating game!\n";
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
