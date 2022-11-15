#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(glb::screen_size.x, glb::screen_size.y,OF_WINDOW);			// <-------- setup the GL context
	ofSetWindowTitle(glb::title); // Set the window title
	//ofSetFrameRate(8);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
