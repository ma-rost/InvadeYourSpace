#include "ofApp.h"
#include <ofImage.cpp>



//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(ofColor::black);
    ofSetWindowTitle(TITLE); // Set the window title
    ofSetWindowShape(screenSize.x, screenSize.y);
    player.setSprites(spriteSheet, {1, 49}, {16, 8});
    player.setSprites(spriteSheet, {19, 49}, {16, 8});
    player.setSprites(spriteSheet, {37, 49 }, { 16, 8 });
}

//--------------------------------------------------------------
void ofApp::update(){
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    player.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == OF_KEY_LEFT || key == 'a')
    {
        player.move(false);
    }

    if (key == OF_KEY_RIGHT || key == 'd')
    {
        player.move(true);
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
