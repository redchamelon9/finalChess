#include "Main.h"






















void piece::revive(int myPieceX, int myPieceY) {

	if (myPieceX > this->PositionX && myPieceX < this->PositionX + 70 && myPieceY > this->PositionY && myPieceY < this->PositionY + 70) { //&& IsEliminated != true
		IsEliminated = false;
		this->PositionX = myPieceX;
		this->PositionY = myPieceY;
	}

}


void piece::eliminate(int opponentX, int opponentY) {

	if (opponentX > this->PositionX && opponentX < this->PositionX + 70 && opponentY > this->PositionY && opponentY < this->PositionY + 70 ) { //&& IsEliminated != true
		IsEliminated = true;
		this->PositionX = 500;
		this->PositionY = 200;
	}

}