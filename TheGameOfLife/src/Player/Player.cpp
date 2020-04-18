
#include "Player.h"

CPlayer::CPlayer()
{
#ifdef DEBUGINFO
	std::cout << "Player created!\n";
#endif
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
	// TODO
}
