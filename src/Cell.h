#pragma once
#include "ofMain.h"

#include "ofxOsc.h"

// send host (aka ip address)
#define HOST "localhost"

/// send port
#define PORT 4000

class Cell{

	public:
		Cell();
		void setup(float _x, float _y, float _w);

        float x, y;
        float w;
        int state;
        int previous;

        //member functions
        void savePrevious();
        void newState(int s);
        void display();
        void update();
    
    void keyPressed(int key);
};
