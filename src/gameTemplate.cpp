#include "gameTemplate.h"

void GameTemplate::setup()
{
	ofTrueTypeFont::setGlobalDpi(72);
	retroFont_.load(ofToDataPath("DePixelBreit.ttf"), 30, true, true);

	player_.setCoords(21, static_cast <float> (glb::SCREEN_SIZE.y - 50), false);



	ofAddListener(GameEvent::events_, this, &GameTemplate::gameEvent);
	
}

void GameTemplate::update()
{
	if (!player_.isLiving()) playerDied();
	if (!enemyContainer_.enemiesLive()) state_ = won;

	//player.getDigits(player.score_);

	switch (state_)
	{
		case startScreen:
			std::cout << "startScreen\n";
			break;
		case inPlay:
			Character::setDestructibles(player_, enemyContainer_);
			enemyContainer_.checkForHit();
			enemyContainer_.moveWhole();

		/*if (ofGetFrameNum() % 60 == 0) enemyContainer_.fireEvent();*/
			break;
		case won:
			break;
		case lost:
			break;
		default:
			std::cout << "Default Case\n";
			break;
	}

	for (auto& i : enemyContainer_.getAllEnemies())
	{
		for (auto& j : i)
		{
			
		}
	}
}

void GameTemplate::drawScore()
{
	ofSetColor(ofColor::white);

	char fpsStr[255]; // an array of chars
	retroFont_.drawString(fpsStr, 100, 600);

	switch (state_)
	{
	case startScreen:
		std::cout << "startScreen\n";
		break;
	case inPlay:
		retroFont_.drawString("SCORE <1> | HI-SCORE | SCORE <2>", 10, 30);
		retroFont_.drawString("0000 \t 0000 \t 0000", 10, 90);
		break;
	case won:
		retroFont_.drawString("YOU WON", 350, 450);
		retroFont_.drawString("SCORE: ", 350, 500);
		break;
	case lost:
		retroFont_.drawString("YOU LOST", 350, 450);
		break;
	default:
		std::cout << "Default Case\n";
		break;
	}
}

void GameTemplate::draw()
{
	drawScore();
	switch (state_)
	{
		case startScreen:
			std::cout << "startScreen\n";
			break;
		case inPlay:
			player_.draw();
			enemyContainer_.draw();
			break;
		case won:
			break;
		case lost:
			break;
		default:
			std::cout << "Default Case\n";
			break;
	}
}

void GameTemplate::playerDied()
{
	playerLivesLeft_--;
	if (playerLivesLeft_ <= 0) gameLost();
	else player_.respawn();
}

void GameTemplate::newGame()
{
	playerLivesLeft_ = 3;
}

void GameTemplate::gameLost()
{
	state_ = lost;
	playerLivesLeft_ = 0;
}

void GameTemplate::gameWon()
{
	state_ = won;
	std::cout << "game won\n";
}

void GameTemplate::keyRelease(int key)
{
	if (key == 'e') enemyContainer_.debugKillAllEnemies();
	if (key == 'r') player_.kill();
}

void GameTemplate::keyPress(int key)
{
	if (key == OF_KEY_LEFT || key == 'a') player_.move(false);
	if (key == OF_KEY_RIGHT || key == 'd') player_.move(true);

	if (key == OF_KEY_UP || key == 'w') player_.fire();
}

void GameTemplate::gameEvent(GameEvent& e)
{
	cout << "Game Event: " + e.message << endl;

	e.chara_->isLiving();
	score_ += e.score_;

	cout << score_ << "\n";
}
