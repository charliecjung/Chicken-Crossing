#include "ofMain.h"
#include "ResourceManager.h"
#include "ofxGui.h"
//========================================================================
int main( ){
	ofSetupOpenGL(20, 20, OF_FULLSCREEN);	
	ResourceManager rm;
	ofSetColor(ofColor::blue);
	ofDrawBitmapString("Width: " + ofToString(ofGetWindowWidth()), 200, 200);
	ofDrawBitmapString("Height: " + ofToString(ofGetWindowHeight()), 600, 600);
	ofDrawBitmapString("HIYA", 400, 400);// <-------- setup the GL context
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(&rm);
}
