#pragma once

#include <iostream>
#include <list>

class CPlayer;

class CBoard
{
public:
	CBoard();
	~CBoard() {}

	void Update(float dTime);

	int GetSize();
	CPlayer* GetPlayerOnPos(int pos);
	int GetNumPlayersNearby(int pos);

protected:
	void AddPlayer(int pos);
	void RemovePlayer(CPlayer* pj);

private:
	int mMaxSize = 16;
	std::list<CPlayer*> mBoard;
};