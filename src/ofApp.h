#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

	private:
	  void load_shader();
		void enumerate();
		void next();

		ofShader shader;
		ofTrueTypeFont font;
		std::vector<ofImage> images;
		std::vector<std::string> shaders;
		ofPlanePrimitive plane;

		bool valid_load = false;
		size_t selected_index = 0;
		size_t no_shaders;
		float mouseX;
		float lastChange = 0;

		glm::vec2 rectSize;
};
