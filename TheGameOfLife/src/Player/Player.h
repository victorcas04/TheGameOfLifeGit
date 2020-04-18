#pragma once

#include <iostream>

class CPlayer
{
public:
	CPlayer(bool canDie = true);
	~CPlayer();

	void Update(float dTime);
	void Draw();

	bool GetCanBeKilled();

protected:

private:
	bool bCanBeKilled;
};