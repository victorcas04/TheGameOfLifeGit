
#include "Cell.h"
#include "Player.h"

CCell::CCell(CVec2D* newPos)
{
	mPos = newPos;
	mWasEmptyLastUpdate = true;
}

void CCell::Update(float dTime)
{
	mWasEmptyLastUpdate = IsEmpty();
	mPj->Update(dTime);
}

void CCell::Draw()
{
	std::cout << (IsEmpty() ? " +" : (mPj->GetCanBeKilled() ? " O" : " @"));
}

CVec2D * CCell::GetPos()
{
	return mPos;
}

CPlayer* CCell::GetPlayerFromCell()
{
	return mPj;
}

void CCell::SetIsInitPos(bool isInitPos)
{
	mWasEmptyLastUpdate = !isInitPos;
}

bool CCell::WasEmptyLastUpdate()
{
	return mWasEmptyLastUpdate;
}

bool CCell::IsEmpty()
{
	return mPj == nullptr;
}

bool CCell::AddPlayerToCell(bool playerCanDie)
{
	if (!mPj)
	{
		mPj = new CPlayer(playerCanDie);
		return true;
	}
	return false;
}

bool CCell::RemovePlayerFromCell()
{
	if (mPj && mPj->GetCanBeKilled())
	{
		mPj->~CPlayer();
		mPj = nullptr;
		return true;
	}
	return false;
}
