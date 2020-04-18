
#include "Board.h"
#include "Cell.h"

CBoard::CBoard(int rows, int columns)
{
#ifdef DEBUGINFO
	std::cout << "Creating board...\n";
#endif
	mRows = rows;
	mCols = columns;
	mPopulation = 0;
	_initBoard();
}

void CBoard::_initBoard()
{
	for (int i = 0; i < mRows; ++i)
	{
		for (int j = 0; j < mCols; ++j)
		{
			mBoard.push_back(new CCell(new CVec2D(i, j)));
		}
	}
}

void CBoard::AddInitPlayers(std::list<CVec2D*> listInitPosNormal, std::list<CVec2D*> listInitPosInmortal)
{
	for (std::list<CVec2D*>::iterator it = listInitPosNormal.begin(); it != listInitPosNormal.end(); ++it)
	{
		if (AddPlayerToPos((*it))) { _getCellOnPos(CVec2D::Pos2DToPos((*it), mCols))->SetIsInitPos(); }
	}
	for (std::list<CVec2D*>::iterator it = listInitPosInmortal.begin(); it != listInitPosInmortal.end(); ++it)
	{
		if (AddPlayerToPos((*it), false)) { _getCellOnPos(CVec2D::Pos2DToPos((*it), mCols))->SetIsInitPos(); }
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
	for (int pos = 0; pos < GetSize(); ++pos)
	{
		_getCellOnPos(pos)->Update(dTime);
	}
	bIsStabilized = true;
	for (int pos = 0; pos < GetSize(); ++pos)
	{
		int numPjNearby = _getNumPlayersNearby(pos);
		if (numPjNearby == 3)
		{
			// no need to check this here, but reduces operations when no needed
			if (_getCellOnPos(pos)->IsEmpty())
			{
				if (AddPlayerToPos(CVec2D::PosToPos2D(pos, mCols))) { bIsStabilized = false; }
			}
		}
		else if (numPjNearby > 3 || numPjNearby < 2)
		{
			// no need to check this here, but reduces operations when no needed
			if (!_getCellOnPos(pos)->IsEmpty())
			{
				if (RemovePlayerFromPos(CVec2D::PosToPos2D(pos, mCols))) { bIsStabilized = false; }
			}
		}
	}
}

void CBoard::Draw()
{
	std::cout << "\n  ";
	for (std::list<CCell*>::iterator it = mBoard.begin(); it != mBoard.end(); ++it)
	{
		(*it)->Draw();
		if ((*it)->GetPos()->GetY() == (mCols - 1))
		{
			std::cout << "\n  ";
		}
	}
}

int CBoard::GetSize()
{
	return mRows * mCols;
}

int CBoard::GetPopulation()
{
	return mPopulation;
}

bool CBoard::IsStabilized()
{
	return bIsStabilized;
}

bool CBoard::AddPlayerToPos(CVec2D * pos, bool playerCanDie)
{
	return _addPlayerToPos(CVec2D::Pos2DToPos(pos, mCols), playerCanDie);
}

bool CBoard::RemovePlayerFromPos(CVec2D * pos)
{
	return _removePlayerFromPos(CVec2D::Pos2DToPos(pos, mCols));
}

CPlayer * CBoard::GetPlayerOnPos(CVec2D * pos)
{
	return _getPlayerOnPos(CVec2D::Pos2DToPos(pos, mCols));
}

int CBoard::GetNumPlayersNearbyPos(CVec2D * pos)
{
	std::list<CCell*> cellsNearby = _getCellsNearby(pos);
	int pjNearby = 0;
	for (std::list<CCell*>::iterator it = cellsNearby.begin(); it != cellsNearby.end(); ++it)
	{
		if (!(*it)->WasEmptyLastUpdate())
		{
			++pjNearby;
		}
	}
	return pjNearby;
}

std::list<CCell*> CBoard::_getCellsNearby(CVec2D * pos)
{
	std::list<CCell*> listCellsNearby;
	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			if (i != 0 || j != 0)
			{
				CVec2D* nearbyPos = new CVec2D(i + pos->GetX(), j + pos->GetY());
				if (_isPosInsideBoard(nearbyPos))
				{
					listCellsNearby.push_back(_getCellOnPos(CVec2D::Pos2DToPos(nearbyPos, mCols)));
				}
			}
		}
	}
	return listCellsNearby;
}

CCell* CBoard::_getCellOnPos(int pos)
{
	std::list<CCell*>::iterator it = mBoard.begin();
	for (int i = 0; i < pos; ++i)
	{
		++it;
	}
	return (*it);
}

bool CBoard::_isPosInsideBoard(CVec2D* pos)
{
	return (pos->GetX() < mRows 
		&& pos->GetX() >= 0 
		&& pos->GetY() < mCols 
		&& pos->GetY() >= 0);
}

bool CBoard::_addPlayerToPos(int pos, bool playerCanDie)
{
	if (_getCellOnPos(pos)->AddPlayerToCell(playerCanDie))
	{
		++mPopulation;
		return true;
	}
	return false;
}

bool CBoard::_removePlayerFromPos(int pos)
{
	if (_getCellOnPos(pos)->RemovePlayerFromCell())
	{
		--mPopulation;
		return true;
	}
	return false;
}

CPlayer * CBoard::_getPlayerOnPos(int pos)
{
	return _getCellOnPos(pos)->GetPlayerFromCell();
}

int CBoard::_getNumPlayersNearby(int pos)
{
	return GetNumPlayersNearbyPos(CVec2D::PosToPos2D(pos, mCols));
}
