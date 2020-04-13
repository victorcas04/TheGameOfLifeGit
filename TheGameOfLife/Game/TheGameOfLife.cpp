/**
 * @author Víctor de Castro Hurtado
 * @description Game based on the concept The Game Of Life from John Horton Conway
 * @link https://en.wikipedia.org/wiki/Conway's_Game_of_Life
 */

#include <iostream>
#include <ctime>

#include "../Game/GameManager.h"

void _init();
void _update();
void _input();
void _logic();
void _render();
void _shutdown();

CGameManager *gameManager;
float deltaTime; float preFrame; float postFrame;

int main()
{
	_init();
	_update();
	_shutdown();
	return 0;
}

void _init()
{
	// times
	postFrame = static_cast<float>(std::clock());
	preFrame = 0;
	deltaTime = 0;

	// managers
	gameManager = gameManager->getInstance();
}

void _update()
{
	while (gameManager->GetIsGameOver())
	{
		deltaTime = postFrame - preFrame;
		preFrame = postFrame;

		_input();
		_logic();
		_render();

		postFrame = static_cast<float>(std::clock());
	}
}

void _input()
{

}

void _logic()
{
	gameManager->Update(deltaTime);
}

void _render()
{

}

void _shutdown()
{

}
