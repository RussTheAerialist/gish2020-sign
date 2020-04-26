#include "ofApp.h"
#include <cmath>

const int FONT_SIZE = 24;
const string FONT_NAME = "Montserrat-Medium.ttf";
const int BUFFER = 50;

//--------------------------------------------------------------
void ofApp::setup(){
	if (!font.load(FONT_NAME, FONT_SIZE)) {
		ofLog(OF_LOG_ERROR) << "Unable to load font " << FONT_NAME;
		ofExit(1);
	}

	enumerate();

	rectSize.x = ofGetWidth() - BUFFER * 2;
	rectSize.y = ofGetHeight() - BUFFER * 2;

	load_shader();

	float planeScale = 1.;
	int planeWidth = ofGetWidth() * planeScale;
	int planeHeight = ofGetHeight() * planeScale;
	int planeGridSize = 20;
	int planeColumns = planeWidth / planeGridSize;
	int planeRows = planeHeight / planeGridSize;

	plane.set(planeWidth, planeHeight, planeColumns, planeRows, OF_PRIMITIVE_TRIANGLES);
	plane.mapTexCoordsFromTexture(images[selected_index].getTexture());
}

void ofApp::enumerate() {
	ofDirectory dir("./images");
	dir.allowExt("png");
	dir.listDir();

	for(size_t i=0; i < dir.size(); i++) {
		string name = dir.getName(i);
		size_t position = name.size() - 3;
		images.push_back(ofImage("images/" + name));
		shaders.push_back("shaders/" + name.erase(position, 3) + "frag");
	}

	no_shaders = shaders.size();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw() {

	float percentX = mouseX / (float)ofGetWidth();
    		percentX = ofClamp(percentX, 0, 1);

	ofBackground(0.);
	// images[selected_index].draw(0,0);
	images[selected_index].getTexture().bind();

	shader.begin();
		shader.setUniform2f("u_resolution", ofGetWindowSize());
		shader.setUniform1f("time", ofGetElapsedTimef());
    shader.setUniform1f("mouseX", percentX);
		float tx = ofGetWidth() / 2;
    float ty = ofGetHeight() / 2;
    ofTranslate(tx, ty);
		// ofScale(0, -1);
		// ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
		plane.draw();
	shader.end();
	images[selected_index].getTexture().unbind();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
		case ' ': selected_index = (selected_index + 1) % no_shaders; load_shader(); break;
		case 'r': load_shader(); break;
		case OF_KEY_RETURN: ofToggleFullscreen(); break;
	}
}

void ofApp::load_shader() {
	valid_load = shader.load("basic.vert", shaders[selected_index]);
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
