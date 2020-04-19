#pragma once

#include <iostream>
#include "Player.h"

class CPlayerNormal : public CPlayer
{
public:
	CPlayerNormal();
	~CPlayerNormal();

protected:

private:
	const char mNormalDrawChar = DRAWPLAYER_NORMALCHAR;
};
