
#include "Board.h"

#include "../Player/Player.h"

CBoard::CBoard()
{
	std::cout << "Board created!\n";
}

void CBoard::Update(float dTime)
{
	for(int pos = 0; pos < mMaxSize; ++pos)
	{
		CPlayer* playerOnPos = GetPlayerOnPos(pos);
		if (!playerOnPos)
		{
			if (GetNumPlayersNearby(pos) < 2)
			{
				CPlayer* newPlayer = new CPlayer(pos);
				// TODO
				// add newPlayer to board
			}
		}
		else
		{
			if (GetNumPlayersNearby(pos) > 3)
			{
				RemovePlayer(GetPlayerOnPos(pos));
			}
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
