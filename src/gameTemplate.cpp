#include "gameTemplate.h"

#include "ofEvents.h"

void GameTemplate::setup()
{
	player_.setCoords(21, static_cast <float> (glb::SCREEN_SIZE.y - 50), false);
}

void GameTemplate::update()
{
	if (!player_.isLiving()) playerDied();
	if (!enemyContainer_.allEnemiesLive()) gameWon();

	//player.getDigits(player.score_);

	Character::setDestructibles(player_, enemyContainer_);
	enemyContainer_.checkForHit();
}

void GameTemplate::draw()
{
	player_.draw();
	enemyContainer_.moveWhole();
}

void GameTemplate::playerDied()
{
	player_.kill();
	playerLivesLeft_--;
	if (playerLivesLeft_ <= 0) gameLost();
}

void GameTemplate::newGame()
{

}

void GameTemplate::gameLost()
{
	std::cout << "game lost\n";
}

void GameTemplate::gameWon()
{
	std::cout << "game won\n";
}

void GameTemplate::keyPress(int key)
{
	if (key == OF_KEY_LEFT || key == 'a') player_.move(false);
	if (key == OF_KEY_RIGHT || key == 'd') player_.move(true);

	if (key == OF_KEY_UP || key == 'w') player_.fire();

	if (key == 'e') player_.killEnemy();
}
