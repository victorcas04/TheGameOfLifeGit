
#include "Cell.h"
#include "../Player/Player.h"

CCell::CCell(CVec2D* newPos)
{
	mPos = newPos;
}

void CCell::Update(float dTime)
{
	//
}

void CCell::Draw()
{
	// TODO
	std::cout << mPos->ToString();
	std::cout << (IsEmpty() ? " empty" : " player");
	std::cout << "\n";
}

CVec2D * CCell::GetPos()
{
	return mPos;
}

CPlayer* CCell::GetPlayerFromCell()
{
	return mPj;
}

bool CCell::IsEmpty()
{
	return mPj == nullptr;
}

void CCell::AddPlayerToCell()
{
	if (!mPj)
	{
		mPj = new CPlayer();
	}
}

void CCell::RemovePlayerFromCell()
{
	if (mPj)
	{
		mPj->~CPlayer();
		mPj = nullptr;
	}
}
