#include "ofApp.h"
#include <algorithm>
#include <ofImage.cpp>


//--------------------------------------------------------------
void ofApp::setup ()
{
	ofSetBackgroundColor (ofColor::darkGray);
	ofSetWindowTitle (TITLE); // Set the window title
	ofSetWindowShape (screenSize.x, screenSize.y);

	player.setCoords (21, static_cast <float> (screenSize.y - 50), false);
}

//--------------------------------------------------------------
void ofApp::update ()
{
}


//--------------------------------------------------------------
void ofApp::draw ()
{
	
	player.draw();
	enemyContainer.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed (int key)
{
	if ( key == OF_KEY_LEFT  || key == 'a')  player.move(false);
	if ( key == OF_KEY_RIGHT || key == 'd' ) player.move (true);

	if (key == OF_KEY_UP || key == 'w') player.fire();

	if ( key == 'e' )  player.kill(); 
}

//--------------------------------------------------------------
void ofApp::keyReleased (int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved (int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged (int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed (int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased (int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered (int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited (int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized (int w, int h)
{
	player.setCoords (static_cast <float> (h - 50), false);
}

//--------------------------------------------------------------
void ofApp::gotMessage (ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent (ofDragInfo dragInfo)
{
}
