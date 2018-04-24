#ifndef COORDINATOR_H
#define COORDINATOR_H

#include "Enemy.h"
#include "Player.h"
#include "ofMain.h"
#include "ofxBox2d.h"

class Coordinator : public ofBaseApp {
	public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	void KillPlayer();
	void EndGame();

	//Cited from:
	// https://github.com/vanderlin/ofxBox2d/blob/master/example-ContactListener/src/ofApp.h

	// this is the function for contacts
	void contactStart(ofxBox2dContactArgs &e);
	void contactEnd(ofxBox2dContactArgs &e);


	private:
	
	ofxBox2d box2d;
	vector < shared_ptr<ofxBox2dRectangle> rectangles;
	Player player_;
	Enemy testEnemy_;
	ofSoundPlayer SoundPlayer_;
	ofImage backgroundImage_;
	const int kEnemySpeed = 15;
};

#endif // COORDINATOR_H