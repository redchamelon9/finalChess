#include "Main.h"


void piece::revive(int myPieceX, int myPieceY) {

	if (myPieceX > this->PositionX && myPieceX < this->PositionX + 70 && myPieceY > this->PositionY && myPieceY < this->PositionY + 70) { //&& IsEliminated != true
		IsEliminated = false;
		this->PositionX = myPieceX;
		this->PositionY = myPieceY;
	}

}

void piece::move(board Board, int i) {

	// Before the piece is moved
	this->PositionX = Board.TileList[i]->posx;
	this->PositionY = Board.TileList[i]->posy;
	this->currentTile->occupiedState = false;
	this->currentTile->colour = 2;

	// After the piece is set to a new tile
	this->currentTile = Board.TileList[i];

	this->currentTile->colour = this->colour;
	this->currentTile->occupiedState = true;
	this->currentIndex = i;
	
	
}



bool piece::moveCheck(board Board,int movingTo) {
	for (int i = 0; i < this->pieceMoveList.size(); i++)
	{
		bool flag;
		cout << this->pieceMoveList[i] << endl;
		cout << i << endl << endl;


		if (movingTo - this->currentIndex == this->pieceMoveList[i] || (movingTo - this->currentIndex) * -1 == this->pieceMoveList[i]) {
			return  true;
		}
	}
	return false;
}

bool piece::eliminate() { 

	
		this->IsEliminated = true;
		this->PositionX = 600;
		this->PositionY = 500;
		
		if (this->pieceMoveList[2]==8) {
			ofRectangle(0,0,1000,800);
			if (this->colour == 0) {
				return true;
			}
			else if (this->colour == 1) {
				return true;
			}
		}
		return false;
}














/*
		if (this->currentIndex + this->pieceMoveList[i] < 64 && i > 0) { // Making sure not to index out of bounds

			if (Board.TileList[this->currentIndex + this->pieceMoveList[i]]->occupiedState == true ) { // Asking if the next tile is occupied

				if ((movingTo - this->currentIndex) % (this->pieceMoveList[i] - this->pieceMoveList[i - 1]) == 0)
				{
					return false;
				}
			}
		}
		*/