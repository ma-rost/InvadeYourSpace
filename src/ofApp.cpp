#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(ofColor::black);
    ofSetWindowTitle(TITLE); // Set the window title
    ofSetWindowShape(screenSize.x, screenSize.y);

}

//--------------------------------------------------------------
void ofApp::update(){
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(ofColor::white);
    player.draw();
    //ofDrawRectangle(drawRestrictions.x, 0, drawRestrictions.y, ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // Left Arrow (37), A (65)
    // Right Arrow (39), D (68)

    if (key == 37 || key == 65)
    {

    }

    if (key == 39 || key == 68)
    {

    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
