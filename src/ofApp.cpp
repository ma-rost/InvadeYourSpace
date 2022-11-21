#include "ofApp.h"
#include <ofImage.cpp>

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetBackgroundColor (53);

	gameTemplate_.setup();
}

//--------------------------------------------------------------
void ofApp::update()
{

	gameTemplate_.update();
}


//--------------------------------------------------------------
void ofApp::draw()
{
	ofSetColor(ofColor::black);
	ofDrawRectangle(0, 0, ofGetWidth(), 90);
	ofDrawRectangle(0, glb::SCREEN_SIZE.y - 60, ofGetWidth(), 90);

	gameTemplate_.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	gameTemplate_.keyPress(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	gameTemplate_.keyRelease(key);
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
	//player.setCoords (static_cast <float> (h - 50), false);
	
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
