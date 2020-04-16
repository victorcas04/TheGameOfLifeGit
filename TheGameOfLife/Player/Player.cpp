
#include "Player.h"

CPlayer::CPlayer(CVec2D* newPos)
{
	std::cout << "Player created!\n";
	mPos = newPos;
}

void CPlayer::Update(float dTime)
{
	// TODO
}

void CPlayer::Draw()
{
	// TODO
}

CVec2D * CPlayer::GetPos()
{
	return mPos;
}
