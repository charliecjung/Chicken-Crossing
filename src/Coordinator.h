#ifndef COORDINATOR_H
#define COORDINATOR_H

#include "Enemy.h"
#include "Player.h"
#include "ofMain.h"

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

	//
	// Referenced from:
	// https://www.geeksforgeeks.org/find-two-rectangles-overlap/

	// l1: Top Left coordinate of first rectangle.
	// r1: Bottom Right coordinate of first rectangle.
	// l2 : Top Left coordinate of second rectangle.
	// r2 : Bottom Right coordinate of second rectangle.
	bool doOverlap(int leftX1, int leftY1, int rightX1, int rightY1, int leftX2, int leftY2, int rightX2, int rightY2);
	private:
	Player player_;
	Enemy testEnemy_;
	ofSoundPlayer SoundPlayer_;
	ofImage backgroundImage_;
	
};

#endif // COORDINATOR_H