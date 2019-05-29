#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetFrameRate(3);
    gol.setup(ofGetWidth(), 10);
  
}

//--------------------------------------------------------------
void ofApp::update(){
    gol.generate();
    ofxOscMessage m;
  
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    gol.display();
    
//    gol.sendOSC();
    

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    gol.setup(ofGetWidth(), 10);
    gol.generate();
}


