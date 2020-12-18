#include "ofApp.h"
#include "Main.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	Board.boardImage.load("chessBoard.png"); // Load image of board

	int boardCount = 0;
	int defaultx = 0;
	int defaulty = 0;

	

	for (int i = 0; i < 6; i++) { //Load in image names for the piece pictures
		wPlayer.pieceImageList[i].load(wPlayer.wImageNames[i]);
		bPlayer.pieceImageList[i].load(bPlayer.bImageNames[i]);
	}


	for (int i = 0; i < 64; i++) //Board setup
	{

		Board.TileList[i] = new tile;
		Board.TileList[i]->posx = defaultx;
		Board.TileList[i]->posy = defaulty;
		Board.TileList[i]->occupiedState = false;

		defaultx += 65;
		boardCount++;

		if (boardCount == 8) {
			defaultx = 0;
			defaulty += 65;
			boardCount = 0;
		}

	}

	wPlayer.setUpPieces(Board,true); // Setup white
	bPlayer.setUpPieces(Board, false); // Setup black

	currentPiece = wPlayer.pieceList[1]; // Just initializes the currentPiece variable

	//Piece setup



	wPawn.piecePic.load("pawn-w.png"); // Can use a for loop later for this
	wPawn.piecePic.resize(80, 80);


	bPawn.piecePic.load("pawn-b.png"); // Can use a for loop later for this
	bPawn.piecePic.resize(80, 80);

	wPawn.PositionX = 115;
	wPawn.PositionY = 300;

	bPawn.PositionX = 115;
	bPawn.PositionY = 185;
	wPawn.IsEliminated = false;

	bool mouseDraggingPiece = false;
	bool mouseReleasePiece = false;


}

//--------------------------------------------------------------
void ofApp::update(){

	
	
	
	wPawn.PositionX;
	wPawn.PositionY;

	bPawn.PositionX;
	bPawn.PositionY;

	/*
	for (int i = 0; i < 16; i++)
	{
		wPlayer.pieceList[i]->PositionX, wPlayer.pieceList[i]->PositionY;
		bPlayer.pieceList[i]->PositionX, bPlayer.pieceList[i]->PositionY;
	}
	*/
	

	currentPiece->PositionX;
	currentPiece->PositionY;

}

//--------------------------------------------------------------
void ofApp::draw(){
	Board.boardImage.draw(0, 0);
	
	for (int i = 0; i < 16; i++)
	{
		wPlayer.pieceList[i]->piecePic.draw(wPlayer.pieceList[i]->PositionX, wPlayer.pieceList[i]->PositionY);
		wPlayer.pieceList[i]->piecePic.resize(62, 62);

		bPlayer.pieceList[i]->piecePic.draw(bPlayer.pieceList[i]->PositionX, bPlayer.pieceList[i]->PositionY);
		bPlayer.pieceList[i]->piecePic.resize(62, 62);


		//bPlayer.pieceImageList[i].draw(bPlayer.pieceList[i]->PositionX, bPlayer.pieceList[i]->PositionY);
	}
	
	
	
	//ofEnableAlphaBlending();
	
	currentPiece->piecePic.draw(currentPiece->PositionX, currentPiece->PositionY);
	//ofSetColor(255, 255, 255, 100);
//	ofDisableAlphaBlending();

	
	
	

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
		
		cout << "Dragging";

		currentPiece->PositionX = x - 40;
		currentPiece->PositionY = y - 40;

		//wPawn.PositionX = x - 40;
		//wPawn.PositionY = y - 40;


		//mouseReleasePiece == true;
		
		
	}
}




//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	//if ( x > wPawn.PositionX && x < wPawn.PositionX + 70 && y > wPawn.PositionY && y < wPawn.PositionY + 70 && button == 0) {
		
		
		for (int i = 0; i < 16; i++) // 64 for tiles
		{

			/*
			if (x > Board.TileList[i]->posx && x < Board.TileList[i]->posx + 70 && y > Board.TileList[i]->posy && y < Board.TileList[i]->posy + 70) {

				currentPiece = Board.TileList[i]->typeOfPiece;

				cout << currentPiece.type;
				
				mouseDraggingPiece = true;
			}
			*/
		
			if (x > wPlayer.pieceList[i]->PositionX && x < wPlayer.pieceList[i]->PositionX + 70 && y > wPlayer.pieceList[i]->PositionY && y < wPlayer.pieceList[i]->PositionY + 70) {
				currentPiece = wPlayer.pieceList[i];

				cout << "clicked on Piece";
				cout << currentPiece->type;

				mouseDraggingPiece = true;
			}

			if (x > bPlayer.pieceList[i]->PositionX && x < bPlayer.pieceList[i]->PositionX + 70 && y > bPlayer.pieceList[i]->PositionY && y < bPlayer.pieceList[i]->PositionY + 70) {
				currentPiece = bPlayer.pieceList[i];

				cout << "clicked on Piece";
				cout << currentPiece->type;

				mouseDraggingPiece = true;
			}

		}
		
	//}
}




//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

	if (button == 0) {
			
		if (mouseDraggingPiece == true) {
			for (int i = 0; i < 64; i++)
			{
				if (x > Board.TileList[i]->posx && x < Board.TileList[i]->posx + 70 && y > Board.TileList[i]->posy && y < Board.TileList[i]->posy + 70 ) { //&& Board.TileList[i]->occupiedState == false
					// Board.TileList[i]->posx; 
					// Board.TileList[i]->posy;

					if (Board.TileList[i]->occupiedState == false) {
						currentPiece->PositionX = Board.TileList[i]->posx;
						currentPiece->PositionY = Board.TileList[i]->posy;

						currentPiece->currentTile->occupiedState = false;
						currentPiece->currentTile = Board.TileList[i];
						currentPiece->currentTile->occupiedState = true;

					}
					else if (Board.TileList[i]->occupiedState == true && Board.TileList[i]->colour != currentPiece->currentTile->colour)
					{
						for (int i = 0; i < 16; i++) // 64 for tiles
						{
							if (x > bPlayer.pieceList[i]->PositionX && x < bPlayer.pieceList[i]->PositionX + 70 && y > bPlayer.pieceList[i]->PositionY && y < bPlayer.pieceList[i]->PositionY + 70) {
								
								
							}
						}

					}
					else {
						currentPiece->PositionX = currentPiece->currentTile->posx;
						currentPiece->PositionY = currentPiece->currentTile->posy;


					}
					

					// NEEDS AND IF STATEMENT			if( Move is allowed ) {
					//Board.TileList[i]->typeOfPiece = *currentPiece;

					//wPlayer.pieceList->

				}
			}

		
		}
		mouseDraggingPiece = false;
			//mouseReleasePiece = false;
	
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