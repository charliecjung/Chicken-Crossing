#include "ResourceManager.h"

//--------------------------------------------------------------
void ResourceManager::setup() {
	frogUp.load("images/FROG//FROG_UP.png");
	frogLeft.load("images/FROG/FROG_LEFT.png");
	frogRight.load("images/FROG/FROG_RIGHT.png");
	frogDown.load("images/FROG/FROG_DOWN.png");
	//backgroundImage.load("images/backgroundImage.png");
}

//--------------------------------------------------------------
void ResourceManager::update() {

}

//--------------------------------------------------------------
void ResourceManager::draw() {
	frogUp.draw(0, 0);

}

//--------------------------------------------------------------
void ResourceManager::keyPressed(int key) {

}

//--------------------------------------------------------------
void ResourceManager::keyReleased(int key) {

}

//--------------------------------------------------------------
void ResourceManager::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ResourceManager::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ResourceManager::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ResourceManager::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ResourceManager::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ResourceManager::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ResourceManager::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ResourceManager::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ResourceManager::dragEvent(ofDragInfo dragInfo) {

}
