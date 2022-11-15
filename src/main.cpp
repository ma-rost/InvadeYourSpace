#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(glb::SCREEN_SIZE.x, glb::SCREEN_SIZE.y,OF_WINDOW);			// <-------- setup the GL context
	ofSetWindowTitle(glb::TITLE); // Set the window title
	//ofSetFrameRate(8);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
