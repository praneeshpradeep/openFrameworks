#include "testApp.h"

void addFace(ofMesh& mesh, ofVec3f a, ofVec3f b, ofVec3f c) {
	ofVec3f normal = ((b - a).cross(c - a)).normalize();
	mesh.addNormal(normal);
	mesh.addVertex(a);
	mesh.addNormal(normal);
	mesh.addVertex(b);
	mesh.addNormal(normal);
	mesh.addVertex(c);
}

void addFace(ofMesh& mesh, ofVec3f a, ofVec3f b, ofVec3f c, ofVec3f d) {
	addFace(mesh, a, b, c);
	addFace(mesh, a, c, d);
}

ofVec3f get(ofFloatImage& img, int x, int y) {
	float scaleFactor = 0.5;
	return ofVec3f(x, y, scaleFactor * img.getColor(x, y).getBrightness());
}

//--------------------------------------------------------------
void testApp::setup(){
	img.loadImage("nyc-small.exr");
	
	light.enable();
	
	mesh.setMode(OF_PRIMITIVE_TRIANGLES);
	int skip = 1;	
	int width = img.getWidth();
	int height = img.getHeight();
	for(int y = 0; y < height - skip; y += skip) {
		for(int x = 0; x < width - skip; x += skip) {
			ofVec3f nw = get(img, x, y);
			ofVec3f ne = get(img, x + skip, y);
			ofVec3f sw = get(img, x, y + skip);
			ofVec3f se = get(img, x + skip, y + skip);
			
			addFace(mesh, nw, ne, se, sw);
		}
	}
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0);
	
	easyCam.begin();
	ofScale(1, -1, 1);
	ofTranslate(-img.getWidth() / 2, -img.getHeight() / 2, 0);
	ofSetColor(255);
	glEnable(GL_DEPTH_TEST);
	mesh.draw();
	glDisable(GL_DEPTH_TEST);
	easyCam.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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