#pragma once

#include "defines.h"
#include <iostream>
#include <list>
#include "Vec2D.h"
#include "Player.h"

class CCell;

class CBoard
{
public:
	CBoard(int rows, int columns);
	~CBoard() {}

	void AddInitPlayers(std::list<CVec2D*> listInitPosNormal, CPlayer::PLAYER_TYPE pjType);

	void Update(float dTime);
	void Draw();

	int GetSize();
	int GetPopulation();
	bool IsStabilized();
	bool AddPlayerToPos(CVec2D* pos, CPlayer::PLAYER_TYPE pjType = CPlayer::NORMAL);
	bool RemovePlayerFromPos(CVec2D* pos);
	CPlayer* GetPlayerOnPos(CVec2D* pos);
	int GetNumPlayersNearbyPos(CVec2D* pos);

protected:
	void _initBoard();

	CCell* _getCellOnPos(int pos);
	CPlayer* _getPlayerOnPos(int pos);
	bool _addPlayerToPos(int pos, CPlayer::PLAYER_TYPE pjType = CPlayer::NORMAL);
	bool _removePlayerFromPos(int pos);

	std::list<CCell*> _getCellsNearby(CVec2D * pos);
	int _getNumPlayersNearby(int pos);

	bool _isPosInsideBoard(CVec2D* pos);

private:
	std::list<CCell*> mBoard;
	int mPopulation;
	bool bIsStabilized;

	int mRows;
	int mCols;
};