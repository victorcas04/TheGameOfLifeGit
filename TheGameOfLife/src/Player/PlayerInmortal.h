#pragma once

#include <iostream>
#include "Player.h"

class CPlayerInmortal : public CPlayer
{
public:
	CPlayerInmortal();
	~CPlayerInmortal();

protected:

private:
	const char mInmortalDrawChar = DRAWPLAYER_INMORTALCHAR;
};
