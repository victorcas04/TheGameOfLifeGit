
#include "PlayerNormal.h"


CPlayerNormal::CPlayerNormal()
{
#ifdef DRAWDEBUGINFO
	std::cout << "Normal player created!\n";
#endif
	mDrawChar = mNormalDrawChar;
	bCanBeKilled = true;
}

CPlayerNormal::~CPlayerNormal()
{
#ifdef DRAWDEBUGINFO
	std::cout << "Normal player deleted!\n";
#endif
}
