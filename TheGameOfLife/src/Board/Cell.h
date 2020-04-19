#pragma once

#include "defines.h"
#include <iostream>
#include "Vec2D.h"
#include "Player.h"

class CCell
{
public:
	CCell(CVec2D* newPos);
	~CCell() {}

	void Update(float dTime);
	void Draw();

	CVec2D* GetPos();

	void SetIsInitPos(bool isInitPos = true);
	bool WasEmptyLastUpdate();
	bool IsEmpty();
	CPlayer* GetPlayerFromCell();
	bool AddPlayerToCell(CPlayer::PLAYER_TYPE pjType);
	bool RemovePlayerFromCell();	

protected:

private:
	CPlayer* mPj;
	CVec2D* mPos;

	bool mWasEmptyLastUpdate;
};
