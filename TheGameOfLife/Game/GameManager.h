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

	float mTimeBetweenSteps = 1.0f;

	// TODO: public inputeable
	float mInnerTimer = 0.0f;
};

