#include "ofApp.h"
#include <ofImage.cpp>

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetBackgroundColor(0);

	bgMusic_.load("lightyear.mp3");
	bgMusic_.play();
	bgMusic_.setVolume(0.05f);
	bgMusic_.setLoop(true); //Sound will loop

	

	winSFX_.load("gameWin.mp3");
	winSFX_.setLoop(false);

	loseSFX_.load("gameLoss.mp3");
	loseSFX_.setLoop(false);


	ofTrueTypeFont::setGlobalDpi(72);
	retroFont_.load(ofToDataPath("DePixelBreit.ttf"), 30, true, true);

	player_.setCoords(21, static_cast<float>(glb::SCREEN_SIZE.y - 100), false);

	ofAddListener(GameEvent::events_, this, &ofApp::gameEvent);
	ofAddListener(GameStateEvent::events_, this, &ofApp::gameStateEvent);
}

//--------------------------------------------------------------
void ofApp::update()
{
	if (!player_.isLiving()) playerDied();
	if (!enemyContainer_.enemiesLive()) curState_ = won;

	//player.getDigits(player.score_);

	switch (curState_)
	{
		case startScreen:
			std::cout << "startScreen\n";
			break;
		case inPlay:
			Character::setDestructibles(player_, enemyContainer_);
			enemyContainer_.checkForHit();
			enemyContainer_.moveWhole();

			if (ofGetFrameNum() % 60 == 0) enemyContainer_.fireEvent();
			break;
		case won:
			if (!winSFX_.isPlaying() && !sfxAlreadyPlayed)
			{
				sfxAlreadyPlayed = true;
				winSFX_.play();
			}
			break;
		case lost:
			if(!loseSFX_.isPlaying() && !sfxAlreadyPlayed)
			{
				sfxAlreadyPlayed = true;
				loseSFX_.play();
			}
			
			break;
		default:
			std::cout << "Default Case\n";
			break;
	}
}

void ofApp::drawScore()
{
	ofSetColor(ofColor::white);

	char fpsStr[255]; // an array of chars
	retroFont_.drawString(fpsStr, 100, 600);

	switch (curState_)
	{
		case startScreen:
			std::cout << "startScreen\n";
			break;
		case inPlay:
			retroFont_.drawString("SCORE: " + std::to_string(score_), 20, 60);
			retroFont_.drawString("LIVES: ", 20, glb::SCREEN_SIZE.y - 15);

			// Draw Remaining Lives
			for (int i = 0; i < playerLivesLeft_; ++i)
			{
				Sprite sprite{};
				ofSetColor(ofColor::gray);
				sprite.drawSprite(i * 60 + 140, glb::SCREEN_SIZE.y - 40);
			}
			break;
		case won:
			retroFont_.drawString("YOU WON", 350, 450);
			retroFont_.drawString("SCORE: " + std::to_string(score_), 350, 500);
			break;
		case lost:
			retroFont_.drawString("YOU LOST", 350, 450);
			retroFont_.drawString("SCORE: " + std::to_string(score_), 350, 500);
			break;
		default:
			std::cout << "Default Case\n";
			break;
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	// Draw the lines that act to demonstrate "menu's"
	ofSetColor(ofColor::white);
	ofDrawRectangle(0, 90, static_cast<float>(ofGetWidth()), 1);
	ofDrawRectangle(0, glb::SCREEN_SIZE.y - 60, static_cast<float>(ofGetWidth()), 1);

	drawScore();
	switch (curState_)
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

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == OF_KEY_LEFT || key == 'a') player_.move(false);
	if (key == OF_KEY_RIGHT || key == 'd') player_.move(true);
	if (key == OF_KEY_UP || key == 'w') player_.fire();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	if (key == 'e') enemyContainer_.debugKillAllEnemies();
	if (key == 'r') player_.kill();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

void ofApp::gameEvent(GameEvent& e)
{
	cout << "Game Event: " + e.message << endl;
	e.chara_->isLiving();
	score_ += e.score_;
}

void ofApp::gameStateEvent(GameStateEvent& e)
{
	curState_ = e.state_;
	std::cout << curState_;
}

void ofApp::playerDied()
{
	playerLivesLeft_--;
	if (playerLivesLeft_ <= 0) gameLost();
	else player_.respawn();
}

void ofApp::newGame()
{
	sfxAlreadyPlayed = true;
	playerLivesLeft_ = 3;
}

void ofApp::endGame()
{
	playerLivesLeft_ = 3;
}

void ofApp::gameLost()
{
	curState_ = lost;
	playerLivesLeft_ = 0;
}

void ofApp::gameWon()
{
	curState_ = won;
	std::cout << "game won\n";
}
