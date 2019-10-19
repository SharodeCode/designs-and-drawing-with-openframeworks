#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	a = 0;
	
	numerator = 8;
	denominator = 5;

	offsetX = 50;
	offsetY = 50;

	change = 50;
}

//--------------------------------------------------------------
void ofApp::update(){

	a < (TWO_PI * denominator) ? a += 0.1 : a = 0;

	if (a == 0) {
		change += 50;
		offsetX += 200;
		offsetY += 200;
	}

	k = numerator / denominator;

	r = 200 * cos(k * a);
	x = r * cos(a);
	y = r * sin(a);


}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(255, 0, 0);
	ofVec3f vector = ofVec3f(x, y, 0);

	//vector.x += (ofGetWidth() / 2);
	//vector.y += (ofGetHeight() / 2);

	vector.x += offsetX;
	vector.y += offsetY;

	line.addVertex(vector);

	ofBackground(0);
	ofSetLineWidth(2.0);
	ofSetColor(change, 100, 0);
	line.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
