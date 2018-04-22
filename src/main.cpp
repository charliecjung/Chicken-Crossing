#include "ofMain.h"
#include "ofxGui.h"

#include "Coordinator.h"
//========================================================================
int main() {
	ofSetupOpenGL(20, 20, OF_FULLSCREEN);
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:sdf
	
	ofRunApp(new Coordinator());
}
