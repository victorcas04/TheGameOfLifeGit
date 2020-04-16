
#include "Board.h"

#include "../Player/Player.h"

CBoard::CBoard(int rows, int columns)
{
	std::cout << "Board created!\n";
	mRows = rows;
	mCols = columns;

	_demoInit();
}

void CBoard::_demoInit()
{
	for (int i = 0; i < mRows; ++i)
	{
		for (int j = 0; j < mCols; ++j)
		{
			AddPlayerToPos(new CVec2D(i, j));
		}
	}
}

// RULES

// any dead cell...
//// ...with exactly three live neighbours becomes a live cell
// any live cell...
//// ...with more than three live neighbours dies
//// ...with fewer than two live neighbours dies
//// ...with two or three live neighbours lives

void CBoard::Update(float dTime)
{
	// TODO: remove this
	/*
	for(int pos = 0; pos < GetSize(); ++pos)
	{
		CPlayer* playerOnPos = _getPlayerOnPos(pos);
		
		if (!playerOnPos)
		{
			
			if (_getNumPlayersNearby(pos) == 3)
			{
				_addPlayerToPos(new CPlayer(CVec2D::PosToPos2D(pos, mCols)), pos);
			}
		}
		
		else
		{
			
			if (_getNumPlayersNearby(pos) > 3 || _getNumPlayersNearby(pos) < 2)
			{
				RemovePlayer(playerOnPos);
			}
			
		}
	}
	*/
	for (int pos = 0; pos < GetSize(); ++pos)
	{
		if (_getNumPlayersNearby(pos) == 3)
		{
			AddPlayerToPos(CVec2D::PosToPos2D(pos, mCols));
		}
		else if (_getNumPlayersNearby(pos) > 3 || _getNumPlayersNearby(pos) < 2)
		{
			RemovePlayerFromPos(CVec2D::PosToPos2D(pos, mCols));
		}
	}
}

void CBoard::Draw()
{
	// TODO
	int i = 0;
	for (std::list<CPlayer*>::iterator it = mBoard.begin(); it != mBoard.end(); ++it)
	{
		std::cout << "pos: " << i << " - pjPos: " << (*it)->GetPos()->ToString() << "\n";
		++i;
	}
}

int CBoard::GetSize()
{
	return mRows * mCols;
}

void CBoard::AddPlayerToPos(CVec2D * pos)
{
	if (!GetPlayerOnPos(pos))
	{
		_addPlayerToPos(new CPlayer(pos), CVec2D::Pos2DToPos(pos, mCols));
	}
}

void CBoard::RemovePlayerFromPos(CVec2D * pos)
{
	// TODO
	if (GetPlayerOnPos(pos))
	{
		// _removePlayerFromPos(pos);
	}
}


void CBoard::RemovePlayer(CPlayer * pj)
{
	// TODO
	// RemovePlayerFromPos(pj.GetPos());
}

CPlayer * CBoard::GetPlayerOnPos(CVec2D * pos)
{
	// TODO
	// return _getPlayerOnPos(pos);
	return nullptr;
}

int CBoard::GetNumPlayersNearbyPos(CVec2D * pos)
{
	// TODO
	return 0;
}

int CBoard::GetNumPlayersNearbyPlayer(CPlayer* pj)
{
	// TODO
	return 0;
}

void CBoard::_addPlayerToPos(CPlayer* newPlayer, int pos)
{
	// TODO
	std::list<CPlayer*>::iterator it = mBoard.begin();
	for (int i = 0; i < pos; ++i)
	{
		++it;
	}
	mBoard.insert(it, newPlayer);
}

void CBoard::_removePlayerFromPos(int pos)
{
	// TODO
}

CPlayer * CBoard::_getPlayerOnPos(int pos)
{
	// TODO
	return nullptr;
}

int CBoard::_getNumPlayersNearby(int pos)
{
	// TODO
	return 0;
}
