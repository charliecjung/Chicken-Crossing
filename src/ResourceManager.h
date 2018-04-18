#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include "Player.h"

#include "ofMain.h"

class ResourceManager : public ofBaseApp {
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
	void killPlayer();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void endGame();

private:
	ofImage frogUp_;
	ofImage frogLeft_;
	ofImage frogRight_;
	ofImage frogDown_;
	ofImage backgroundImage_;
	ofImage currentImage_;
	Player player_;
	ofSoundPlayer SoundPlayer_;
};

#endif // RESOURCE_MANAGER_H