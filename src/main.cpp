#include "ResourceManager.h"

#include "ofMain.h"
#include "ofxGui.h"
//========================================================================
int main() {
    ofSetupOpenGL(20, 20, OF_FULLSCREEN);	
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    

    // In the future, I will have a class like a Coordinator run everything in conjuction.
    // For now, ResourceManager is the placeholder because it essentially handles like a game engine.

    ofRunApp(new ResourceManager());
}
