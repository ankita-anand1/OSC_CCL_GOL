#pragma once
#include "ofMain.h"
#include "GOL.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void mousePressed(int x, int y, int button);
		GOL gol;
        void keyPressed(int key);
    
    
    ofTrueTypeFont font;
    ofxOscSender sender;
    ofBuffer imgAsBuffer;
    ofImage img;
    
};
