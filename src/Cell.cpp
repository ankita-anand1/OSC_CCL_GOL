#include "Cell.h"

//-------------------------------------------------------
Cell::Cell()
{

}

//-------------------------------------------------------
void Cell::setup(float _x, float _y, float _w)
{
    x = _x;
    y = _y;
    w = _w;

    state = int(ofRandom(2));
    previous = state;
    
    
    ofSetWindowTitle("oscSenderExample");
    //    ofSetFrameRate(60); // run at 60 fps
    ofSetVerticalSync(true);
    
    // open an outgoing connection to HOST:PORT
    sender.setup(HOST, PORT);
    
    //    // preload image to send into a buffer
    //    imgAsBuffer = ofBufferFromFile("of-logo.png", true);
}
//-------------------------------------------------------
void Cell::update(){

m.setAddress("/dancer/grid");
//    m.addFloatArg(ofMap(ofGetMouseX(), 0, ofGetWidth(), 0.f, 1.f, true));
//    m.addFloatArg(ofMap(ofGetMouseY(), 0, ofGetHeight(), 0.f, 1.f, true));

sender.sendMessage(m, false);
}

//--------------------------------------------------------------
void Cell::savePrevious(){
    previous = state;
}

//--------------------------------------------------------------
void Cell::newState(int s) {
    state = s;
}

//--------------------------------------------------------------
void Cell::display() {
    ofFill();
    if (state == 1) ofSetColor(0);
    else ofSetColor(255);
    ofRect(x, y, w, w);
    ofNoFill();
    ofSetColor(0);
    ofRect(x, y, w, w);
    
    // display instructions
    string buf = "sending osc messages to: " + string(HOST);
    buf += " " + ofToString(PORT);
    buf += "\npress A to send osc message [/test 1 3.5 hello <time>]\n";
    buf += "press I to send a (small) image as a osc blob to [/image]";
    ofDrawBitmapStringHighlight(buf, 10, 20);
}

/--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // send a test message
    if(key == 'a' || key == 'A'){
        ofxOscMessage m;
        m.setAddress("/test");
        m.addIntArg(1);
        m.addFloatArg(3.5f);
        m.addStringArg("hello");
        m.addFloatArg(ofGetElapsedTimef());
        sender.sendMessage(m, false);
    }
    
    // send an image
    // note: the size of the image depends greatly on your network buffer sizes,
    // if an image is too big the message won't come through and you may need
    // to break it up into multiple blobs
    if(key == 'i' || key == 'I'){
        
        //        // load image from buffer
        //        img.load(imgAsBuffer);
        
        // send as a binary blob
        ofxOscMessage m;
        m.setAddress("/image");
        m.addBlobArg(imgAsBuffer);
        sender.sendMessage(m);
        ofLog() << "sending image with size: " << imgAsBuffer.size();
    }
}



