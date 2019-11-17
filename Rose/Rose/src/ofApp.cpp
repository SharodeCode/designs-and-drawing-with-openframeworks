#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0);
	translate = 400;

	numerator = 5;
	denominator = 49;

	ReduceFraction(numerator, denominator);
	NumOfCycles(numerator, denominator, cycles);

	n = 0;
	g = 0;
	k = (float)numerator / (float)denominator;
	change = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

	if (g < (PI * cycles)) {
		n += 0.1;
		g += 0.1;
	}
	else {
		vectors.clear();
		change = 0;
		n = 0;
		g = 0;
	}

	vector<float> coordinates = rose();

	glm::vec3 vector = glm::vec3(coordinates[0] + translate, coordinates[1] + translate, 0);

	vectors.push_back(vector);

	line.clear();
	line.addVertices(vectors);
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(255, 0, 0);

	ofSetLineWidth(2.0);
	ofSetColor(255, 100, 0);

	line.draw();
}

void ofApp::ReduceFraction(int &numerator, int &denominator)
{
	for (int i = denominator * numerator; i > 1; i--) {
		if ((denominator % i == 0) && (numerator % i == 0)) {
			denominator /= i;
			numerator /= i;
		}
	}
}

void ofApp::NumOfCycles(int &numerator, int &denominator, int &cycles)
{
	if (numerator == denominator) {
		cycles = 1;
	}
	else if (denominator % 2 != 0 && numerator % 2 != 0) {
		cycles = denominator;
	}
	else {
		cycles = (denominator * 2);
	}
}

vector<float> ofApp::rose() {
	r = 200 * cos(k * n);
	x = r * cos(n);
	y = r * sin(n);

	return vector<float>{ x, y };
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
