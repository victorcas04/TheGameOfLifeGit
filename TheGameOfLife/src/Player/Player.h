#pragma once

#include "defines.h"
#include <iostream>

class CPlayer
{
public:
	
	enum PLAYER_TYPE
	{
		NORMAL,
		INMORTAL
	};

	CPlayer();
	virtual ~CPlayer();

	void Update(float dTime);
	void Draw();
	const char GetDrawChar();

	bool GetCanBeKilled();

	static CPlayer* NewPlayer(PLAYER_TYPE pjType);

protected:
	char mDrawChar;
	bool bCanBeKilled;

private:
};