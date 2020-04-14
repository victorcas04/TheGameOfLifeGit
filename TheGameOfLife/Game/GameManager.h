#pragma once

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

	static CGameManager* m_instanceGameManager;

	CBoard* mBoard;

	bool bIsGameOver = false;

	float mTimeBetweenSteps;
	float mInnerTimer = 0.0f;

	int mRows;
	int mColumns;
};

