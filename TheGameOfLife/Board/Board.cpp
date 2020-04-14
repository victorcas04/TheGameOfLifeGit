
#include "Board.h"

#include "../Player/Player.h"

CBoard::CBoard()
{
	std::cout << "Board created!\n";
}

/// RULES

void CBoard::Update(float dTime)
{
	for(int pos = 0; pos < mMaxSize; ++pos)
	{
		CPlayer* playerOnPos = GetPlayerOnPos(pos);
		// any dead cell...
		if (!playerOnPos)
		{
			// ...with exactly three live neighbours becomes a live cell
			if (GetNumPlayersNearby(pos) == 3)
			{
				CPlayer* newPlayer = new CPlayer(pos);
				// TODO
				// add newPlayer to board
			}
		}
		// any live cell...
		else
		{
			// ...with more than three live neighbours dies
			// ...with fewer than two live neighbours dies
			if (GetNumPlayersNearby(pos) > 3 || GetNumPlayersNearby(pos) < 2)
			{
				RemovePlayer(GetPlayerOnPos(pos));
			}
			// ...with two or three live neighbours lives
		}
	}
	
}

void CBoard::Draw()
{
	// TODO
	// print board state
}

int CBoard::GetSize()
{
	return mMaxSize;
}

void CBoard::SetSize(int size)
{
	mMaxSize = size;
}

CPlayer * CBoard::GetPlayerOnPos(int pos)
{
	// TODO
	return nullptr;
}

int CBoard::GetNumPlayersNearby(int pos)
{
	// TODO
	return 0;
}

void CBoard::AddPlayer(int pos)
{
	// TODO
	// new pj
	// add pj to pos in list
}

void CBoard::RemovePlayer(CPlayer * pj)
{
	// TODO
	// remove pj from list
	// ~pj
}
