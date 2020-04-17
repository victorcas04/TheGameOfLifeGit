#pragma once

#include <stdlib.h>
#include <iostream>

class CBoard;

class CGameManager
{
public:
	static CGameManager* getInstance()
	{
		return (!m_instanceGameManager) ? m_instanceGameManager = new CGameManager() : m_instanceGameManager;
	}

	void Init();
	void CreateBoard();

	void Update(float dTime);
	void Draw();

	bool GetIsGameOver();


protected:

private:
	CGameManager();
	~CGameManager() {}

	void _testInit();

	CBoard* mBoard;

	bool bIsGameOver = false;
	bool bMustDraw = true;

	// TODO: add limits to input
	int mMaxIterations;
	int mInnerIterations = 0;

	float mTimeBetweenSteps;
	float mInnerTimer = 0.0f;

	int mRows;
	int mColumns;

	static CGameManager* m_instanceGameManager;
};

