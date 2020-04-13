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
	void Draw();

	int GetSize();
	CPlayer* GetPlayerOnPos(int pos);
	int GetNumPlayersNearby(int pos);

protected:
	void AddPlayer(int pos);
	void RemovePlayer(CPlayer* pj);

private:
	std::list<CPlayer*> mBoard;

	// TODO: public inputeable
	int mMaxSize = 16;
};