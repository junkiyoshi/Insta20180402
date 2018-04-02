#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
	ofSetLineWidth(3);

	for (int i = 0; i < 1024; i++) {

		unique_ptr<Particle> particle(new Particle(500));
		this->particles.push_back(std::move(particle));
	}
}

//--------------------------------------------------------------
void ofApp::update() {

	for (int i = 0; i <  this->particles.size(); i++) {

		this->particles[i]->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(180);

	for (int i = 0; i < this->particles.size(); i++) {

		this->particles[i]->draw();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}