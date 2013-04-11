#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0, 0, 0);
    ofSetCircleResolution(100);
    ofEnableAlphaBlending();
    ofSetFullscreen(true);
    
    //Stars Settings
    for (int i = 0; i < NUM; i++) {
        pos[i].x = ofRandom(-ofGetWidth(), ofGetWidth());
        pos[i].y = ofRandom(-ofGetHeight(), ofGetHeight());
        pos[i].z = ofRandom(0, 3000);
    }
    
    //EasyCam Settings
    int camDis = 1000;
    cam.setDistance(camDis);
    
    //Frame Counter
    fNum = 0;
    
    //Event Flag
    eventFlag = 0;
    
    //Rotate Degree
    deg = 0;
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    cam.begin();
    
    //Rotate Angles
    deg += 0.1;
    ofRotate(deg, -20, -100, 0);
    
    ofPushMatrix();
    ofTranslate(0, 0, -1000);
    
    //Draw Stars
    for (int i = 0; i < NUM-1; i++) {
        //Stars
        ofPushMatrix();
        ofTranslate(pos[i].x, pos[i].y, pos[i].z);
        ofSetColor(255, 255, 255, 180);
        ofCircle(0, 0, 0, 1);
        //Space Gus
        ofSetColor(255, 255, 255, 3);
        ofLine(pos[i].x, pos[i].y, pos[i].z, pos[i+1].x, pos[i+1].y, pos[i+1].z);
        ofPopMatrix();
    }
    
    
    //Event0 : Stars Only
    if (eventFlag == 0) {
        fNum = 0;
    }
    //Event1 : Generate Lines
    if (eventFlag == 1) {
        fNum += 1;
        if (fNum >= NUM) {
            fNum = 0;
        }
        ofSetColor(255, 255, 255, 30);
        for (int i = 0; i < fNum-1; i++) {
            ofLine(pos[i].x, pos[i].y, pos[i].z, pos[i+2].x, pos[i+2].y, pos[i+2].z);
        }
    }
    
    
    ofPopMatrix();
    
    cam.end();
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case '0':
            eventFlag = 0;
            break;
            
        case '1':
            eventFlag = 1;
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}