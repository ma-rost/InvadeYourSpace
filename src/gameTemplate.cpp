#include "gameTemplate.h"

void GameTemplate::update()
{

}

void GameTemplate::playerDied()
{
	playerLivesLeft_--;
	if (playerLivesLeft_ <= 0) isPlayerLive_ = false;
}

void GameTemplate::newGame()
{

}
