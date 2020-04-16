#pragma once

#include <iostream>
#include <list>

#include "../Other/Vec2D.h"

class CPlayer;

class CBoard
{
public:
	CBoard(int rows, int columns);
	~CBoard() {}

	// TODO: remove this
	void _demoInit();

	void Update(float dTime);
	void Draw();

	int GetSize();
	void AddPlayerToPos(CVec2D* pos);
	void RemovePlayerFromPos(CVec2D* pos);
	void RemovePlayer(CPlayer* pj);
	CPlayer* GetPlayerOnPos(CVec2D* pos);
	int GetNumPlayersNearbyPos(CVec2D* pos);
	int GetNumPlayersNearbyPlayer(CPlayer* pj);

protected:
	void _addPlayerToPos(CPlayer* newPlayer, int pos);
	void _removePlayerFromPos(int pos);

	CPlayer* _getPlayerOnPos(int pos);
	int _getNumPlayersNearby(int pos);

private:
	std::list<CPlayer*> mBoard;

	int mRows;
	int mCols;
};