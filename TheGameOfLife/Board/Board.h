#pragma once

#include <iostream>
#include <list>

#include "../Other/Vec2D.h"

class CPlayer;
class CCell;

class CBoard
{
public:
	CBoard(int rows, int columns);
	~CBoard() {}

	void AddInitPlayers(std::list<CVec2D*> listInitPos);

	void Update(float dTime);
	void Draw();

	int GetSize();
	int GetPopulation();
	void AddPlayerToPos(CVec2D* pos);
	void RemovePlayerFromPos(CVec2D* pos);
	CPlayer* GetPlayerOnPos(CVec2D* pos);
	int GetNumPlayersNearbyPos(CVec2D* pos);

protected:
	void _initBoard();

	CCell* _getCellOnPos(int pos);
	CPlayer* _getPlayerOnPos(int pos);
	void _addPlayerToPos(int pos);
	void _removePlayerFromPos(int pos);

	std::list<CCell*> _getCellsNearby(CVec2D * pos);
	int _getNumPlayersNearby(int pos);

	bool _isPosInsideBoard(CVec2D* pos);

private:
	std::list<CCell*> mBoard;
	int mPopulation;

	int mRows;
	int mCols;
};