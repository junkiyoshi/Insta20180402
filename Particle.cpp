#include "Particle.h"

Particle::Particle(int len) {

	this->len = len;
	this->location = ofPoint(ofRandom(-this->len / 2, this->len / 2), ofRandom(-this->len, this->len), ofRandom(-this->len / 2, this->len / 2));
	this->radius = this->len / 2;
}

void Particle::update() {

	ofPoint log = ofPoint(this->location.x, (int)(this->location.y + ofGetFrameNum() * 3) % (len * 2) - len, this->location.z);

	if (log.length() < this->radius) {

		log = log.normalize() * this->radius;
	}

	if (log.y <= -len + 3) {

		this->logs.clear();
	}

	if (this->logs.size() > 24) {

		this->logs.erase(this->logs.begin());
	}
	this->logs.push_back(log);
}

void Particle::draw() {

	if (this->logs.size() > 2) {

		for (int i = 1; i < this->logs.size(); i++) {

			ofSetColor(39, 10 * i - ofMap(this->logs[i].z, -this->len / 2, this->len / 2, 0, 255));
			ofDrawLine(this->logs[i - 1], this->logs[i]);
		}
	}
}