#include "GameState.h"

GameState::GameState()
{
	this->restaurant = new Restaurant();
}
void GameState::tick()
{
	restaurant->tick();
	if (restaurant->win)
	{
		setFinished(true);
		setNextState("Win");
	}
	if (restaurant->lose)
	{
		setFinished(true);
		setNextState("Lose");
	}
}
void GameState::render()
{
	restaurant->render();
}

void GameState::keyPressed(int key)
{
	restaurant->keyPressed(key);
}

void GameState::mousePressed(int x, int y, int button)
{
}

void GameState::keyReleased(int key)
{
	restaurant->keyReleased(key);
}

void GameState::reset()
{
	setFinished(false);
	setNextState("");
}