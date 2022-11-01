#pragma once

#include "enemy.h"
#include "ofMain.h"
#include "point.h"
#include "player.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		const string TITLE = "Invade Your Space";

		ofImage spriteSheet{"spaceInvaders_spriteSheet.png"};

		Player player {10, static_cast<float>(screenSize.y + ofGetHeight())};

		array<vector<Enemy>,11> enemyTest;

		Point<int> screenSize = { 700, 500 };
};
