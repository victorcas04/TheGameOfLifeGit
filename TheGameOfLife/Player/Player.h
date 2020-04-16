#pragma once

#include <iostream>
#include "../Other/Vec2D.h"

class CPlayer
{
public:
	CPlayer(CVec2D* newPos);
	~CPlayer() {}

	void Update(float dTime);
	void Draw();

	CVec2D* GetPos();

protected:

private:
	CVec2D* mPos;
};