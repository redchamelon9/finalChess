#include "Main.h"



player::player() {
	 
}

player::~player() {

}


void player::setUpPieces(board Board, bool colour) {


	if (colour == true) {


		for (int i = 0; i < 16; i++)
		{
			pieceList[i] = new piece;
			pieceList[i]->IsEliminated = false;
			pieceList[i]->PositionX = Board.TileList[i]->posx;
			pieceList[i]->PositionY = Board.TileList[i]->posy;

			pieceList[i]->currentTile = Board.TileList[i];


			Board.TileList[i]->occupiedState = true;
			Board.TileList[i]->colour = true;


			
			//Board.TileList[i]->typeOfPiece = *pieceList[i];

			if (i == 0 || i == 7) { //Condition for Rooks
				pieceList[i]->piecePic = pieceImageList[0];
				pieceList[i]->type = "r";
			}
			else if (i == 1 || i == 6) {  //Condition for Knight
				pieceList[i]->piecePic = pieceImageList[1];
				pieceList[i]->type = "n";
			}
			else if (i == 2 || i == 5) { //Condition for Bishop
				pieceList[i]->piecePic = pieceImageList[2];
				pieceList[i]->type = "b";
			}
			else if (i == 3) { //Condition for Queen
				pieceList[i]->piecePic = pieceImageList[3];
				pieceList[i]->type = "q";
			}
			else if (i == 4) { //Condition for King
				pieceList[i]->piecePic = pieceImageList[4];
				pieceList[i]->type = "k";
			}
			else if (i >= 8) { //Condition for Pawn
				pieceList[i]->piecePic = pieceImageList[5];
				pieceList[i]->type = "p";
			}

			pieceList[i]->piecePic.draw(Board.TileList[i]->posx, Board.TileList[i]->posy);
			pieceList[i]->piecePic.resize(60, 60);
		}
	}
	else if (colour == false) {


		for (int i = 0; i < 16; i++)
		{
			pieceList[i] = new piece; // Creates a new piece for the first sixteen tiles
			pieceList[i]->IsEliminated = false; // Just sets the alive state for the piece
			
			pieceList[i]->PositionX = Board.TileList[i + 48]->posx;
			pieceList[i]->PositionY = Board.TileList[i + 48]->posy;
			pieceList[i]->currentTile = Board.TileList[i];


			Board.TileList[i]->occupiedState = true;
			Board.TileList[i]->colour = false;
			//Board.TileList[i]->typeOfPiece = *pieceList[i];

			if (i == 8 || i == 15) { //Condition for Rooks
				pieceList[i]->piecePic = pieceImageList[0];
				pieceList[i]->type = "r";
			}
			else if (i == 9 || i == 14) { 
				pieceList[i]->piecePic = pieceImageList[1];
				pieceList[i]->type = "n";
			}
			else if (i == 10 || i == 13) { //Condition for Knight
				pieceList[i]->piecePic = pieceImageList[2];
				pieceList[i]->type = "b";
			}
			else if (i == 11) { //Condition for Bishop
				pieceList[i]->piecePic = pieceImageList[3];
				pieceList[i]->type = "q";
			}
			else if (i == 12) { //Condition for Queen
				pieceList[i]->piecePic = pieceImageList[4];
				pieceList[i]->type = "k";
			}
			else if (i <= 7) { //Condition for King
				pieceList[i]->piecePic = pieceImageList[5];
				pieceList[i]->type = "p";
			}

			pieceList[i]->piecePic.draw(Board.TileList[i]->posx, Board.TileList[i]->posy);
			pieceList[i]->piecePic.resize(60, 60);
		}
	}
}


void	player::setName() {

	string name1 = "Player1";
	string name2 = "Player2";



	cout << "Player 1's name: \n";
	cin >> name1;
	cout << "Player 2's name: \n";
	cin >> name2;

	cout << "Player 1's name is " << name1;
	cout << "Player 2's name is " << name2;
}