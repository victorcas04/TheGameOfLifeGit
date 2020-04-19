/**
 * @author Víctor de Castro Hurtado
 * @description Game based on the concept The Game Of Life from John Horton Conway
 * @link https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
 */

#pragma once

#include "defines.h"
#include <iostream>
#include <ctime>			// std::clock()
#include "GameManager.h"

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
	if (gameManager)
	{
		gameManager->Init();
	}
	else
	{
		std::cout << "ERROR: cannot create game manager.\n";
	}
}

void _update()
{
	if (gameManager)
	{
		while (!gameManager->GetIsGameOver())
		{
			deltaTime = postFrame - preFrame;
			preFrame = postFrame;

			_input();
			_logic();
			_render();

			postFrame = static_cast<float>(std::clock());
		}
	}
}

void _input()
{
	// no need for user input since it's a 0 player game
}

void _logic()
{
	gameManager->Update(deltaTime);
}

void _render()
{
	gameManager->Draw();
}

void _shutdown()
{

}
