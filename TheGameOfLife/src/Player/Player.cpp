
#include "Player.h"

CPlayer::CPlayer(bool canDie)
{
#ifdef DEBUGINFO
	std::cout << "Player created!\n";
#endif
	bCanBeKilled = canDie;
}

CPlayer::~CPlayer()
{
#ifdef DEBUGINFO
	std::cout << "Player deleted!\n";
#endif
}

void CPlayer::Update(float dTime)
{
	//
}

void CPlayer::Draw()
{
	//
}

bool CPlayer::GetCanBeKilled()
{
	return bCanBeKilled;
}
