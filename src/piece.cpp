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



bool piece::moveCheck(int movingTo) {
	for (int i = 0; i < this->pieceMoveList.size(); i++)
	{

		cout << this->pieceMoveList[i] << endl;
		cout << i << endl << endl;

		if (movingTo - this->currentIndex == this->pieceMoveList[i] || (movingTo - this->currentIndex) * -1 == this->pieceMoveList[i]) {
			return  true;
		}
	}
	return false;
}

void piece::eliminate() { 

	
		this->IsEliminated = true;
		this->PositionX = 600;
		this->PositionY = 500;

}