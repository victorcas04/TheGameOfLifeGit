
#include "PlayerInmortal.h"

CPlayerInmortal::CPlayerInmortal()
{
#ifdef DRAWDEBUGINFO
	std::cout << "Inmortal player created!\n";
#endif
	mDrawChar = mInmortalDrawChar;
	bCanBeKilled = false;
}

CPlayerInmortal::~CPlayerInmortal()
{
#ifdef DRAWDEBUGINFO
	std::cout << "Inmortal player deleted!\n";
#endif
}