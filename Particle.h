#pragma once

#include "ofMain.h"

class Particle {

public:
	Particle(int len);

	void update();
	void draw();
private:
	ofPoint location;
	ofPoint log;
	vector<ofPoint> logs;
	int len;
	float radius;
};
