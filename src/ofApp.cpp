#include "ofApp.h"
#include <ofImage.cpp>

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetBackgroundColor (53);

	ofTrueTypeFont::setGlobalDpi (72);
	retroFont_.load (ofToDataPath ("DePixelBreit.ttf"), 30, true, true);

	player.setCoords (21, static_cast <float> (glb::SCREEN_SIZE.y - 50), false);
}

//--------------------------------------------------------------
void ofApp::update()
{
	Character::setDestructibles(player, enemyContainer);
	//player.getDigits(player.score_);
	
	enemyContainer.checkForHit();
}


//--------------------------------------------------------------
void ofApp::draw()
{
	ofSetColor(ofColor::black);
	ofDrawRectangle(0, 0, ofGetWidth(), 90);

	ofSetColor (ofColor::white);
	retroFont_.drawString ("SCORE <1> | HI-SCORE | SCORE <2>", 10, 30);
	retroFont_.drawString ("0000 \t 0000 \t 0000", 10, 90);

	

	char fpsStr[255]; // an array of chars
	retroFont_.drawString(fpsStr, 100, 600);

	player.draw();
	enemyContainer.moveWhole();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == OF_KEY_LEFT || key == 'a') player.move (false);
	if (key == OF_KEY_RIGHT || key == 'd') player.move (true);

	if (key == OF_KEY_UP || key == 'w') player.fire();

	if (key == 'e') player.killEnemy();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
	player.setCoords (static_cast <float> (h - 50), false);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
