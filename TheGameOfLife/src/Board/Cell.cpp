
#include "Cell.h"
#include "Player.h"

CCell::CCell(CVec2D* newPos)
{
	mPos = newPos;
	mWasEmptyLastUpdate = true;
}

void CCell::Update(float dTime)
{
	//
	mWasEmptyLastUpdate = IsEmpty();
	mPj->Update(dTime);
}

void CCell::Draw()
{
	// TODO

	std::cout << (IsEmpty() ? " E" : " P");
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
