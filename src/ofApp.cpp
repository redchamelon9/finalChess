#include "ofApp.h"
#include "Main.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	Board.boardImage.load("chessBoard.png");
	wPawn.piecePic.load("pawn-w.png"); // Can use a for loop later for this
	wPawn.piecePic.resize(100, 100);


	bPawn.piecePic.load("pawn-b.png"); // Can use a for loop later for this
	bPawn.piecePic.resize(100, 100);

	wPawn.PositionX = 115;
	wPawn.PositionY = 300;

	bPawn.PositionX = 115;
	bPawn.PositionY = 185;
	wPawn.IsEliminated = false;

	bool mouseDraggingPiece = false;

}

//--------------------------------------------------------------
void ofApp::update(){

	
	
	
	wPawn.PositionX;
	wPawn.PositionY;

	bPawn.PositionX;
	bPawn.PositionY;

}

//--------------------------------------------------------------
void ofApp::draw(){
	Board.boardImage.draw(0, 0);
	
	bPawn.piecePic.draw(bPawn.PositionX, bPawn.PositionY);
	wPawn.piecePic.draw(wPawn.PositionX, wPawn.PositionY);

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
	if (mouseDraggingPiece == true ) {
		


		wPawn.PositionX = x - 50;
		wPawn.PositionY = y - 50;
		
		
	}
}




//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if ( x > wPawn.PositionX && x < wPawn.PositionX + 70 && y > wPawn.PositionY && y < wPawn.PositionY + 70 && button == 0) {
		mouseDraggingPiece = true;
		
		
	}
}




//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

	if (button == 0) {
			mouseDraggingPiece = false;
	
			bPawn.eliminate(wPawn.PositionX, wPawn.PositionY);

	}

	

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


void ofApp::draggingPiece(int x, int y, piece draggedPiece) {

}