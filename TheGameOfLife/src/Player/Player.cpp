
#include "Player.h"
#include "PlayerNormal.h"
#include "PlayerInmortal.h"

CPlayer::CPlayer()
{
#ifdef DRAWDEBUGINFO
	std::cout << "Player created!\n";
#endif
}

CPlayer::~CPlayer()
{
#ifdef DRAWDEBUGINFO
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

const char CPlayer::GetDrawChar()
{
	return mDrawChar;
}

bool CPlayer::GetCanBeKilled()
{
	return bCanBeKilled;
}

CPlayer * CPlayer::NewPlayer(PLAYER_TYPE pjType)
{
	if (pjType == PLAYER_TYPE::NORMAL)
	{
		return new CPlayerNormal();
	}
	else if (pjType == PLAYER_TYPE::INMORTAL)
	{
		return new CPlayerInmortal();
	}
	return nullptr;
}
