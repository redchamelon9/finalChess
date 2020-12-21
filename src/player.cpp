#include "Main.h"



player::player() {
	 
}

player::~player() {

}


void player::setUpPieces(board Board, bool colour) {



		for (int i = 0; i < 16; i++)
		{
			pieceList[i] = new piece;


			int blackPiecesIndex = 0;
			int blackPiecesIndex2 = 0;
			if (colour == false) {
				blackPiecesIndex = 48;
				blackPiecesIndex2 = 8;

				pieceList[i]->colour = 0;
				Board.TileList[i]->colour = 0;
			}
			else if (colour == true) {
				pieceList[i]->colour = 1;
				Board.TileList[i]->colour = 1;
			}


			pieceList[i]->IsEliminated = false;
			pieceList[i]->PositionX = Board.TileList[i + blackPiecesIndex]->posx;
			pieceList[i]->PositionY = Board.TileList[i + blackPiecesIndex]->posy;
			pieceList[i]->currentTile = Board.TileList[i + blackPiecesIndex];

			pieceList[i]->currentIndex = i + blackPiecesIndex;

			Board.TileList[i]->occupiedState = true;



			if (i == 0 + blackPiecesIndex2 || i == 7 + blackPiecesIndex2) { //Condition for Rooks
				pieceList[i]->piecePic = pieceImageList[0];
				pieceList[i]->type = "r";

				for (size_t j = 0; j < sizeof(pieceList[j]->rookArray) / sizeof(pieceList[j]->rookArray[0]); j++)
				{
					pieceList[i]->pieceMoveList.push_back(pieceList[i]->rookArray[j]);
				}
			}
			else if (i == 1 + blackPiecesIndex2 || i == 6 + blackPiecesIndex2) {  //Condition for Knight
				pieceList[i]->piecePic = pieceImageList[1];
				pieceList[i]->type = "n";
				
				for (size_t j = 0; j < sizeof(pieceList[j]->knightArray) / sizeof(pieceList[j]->knightArray[0]); j++)
				{
					pieceList[i]->pieceMoveList.push_back(pieceList[i]->knightArray[j]);
				}
			}
			else if (i == 2 + blackPiecesIndex2 || i == 5 + blackPiecesIndex2) { //Condition for Bishop
				pieceList[i]->piecePic = pieceImageList[2];
				pieceList[i]->type = "b";

				if (i == 2) {
					
					for (size_t j = 0; j < sizeof(pieceList[j]->bishopLArray) / sizeof(pieceList[j]->bishopLArray[0]); j++)
					{
						pieceList[i]->pieceMoveList.push_back(pieceList[i]->bishopLArray[j]);
					}
				}
				else if (i == 5) {
					
					for (size_t j = 0; j < sizeof(pieceList[j]->bishopRArray) / sizeof(pieceList[j]->bishopRArray[0]); j++)
					{
						pieceList[i]->pieceMoveList.push_back(pieceList[i]->bishopRArray[j]);
					}
				}
				
			}
			else if (i == 3 + blackPiecesIndex2) { //Condition for Queen
				pieceList[i]->piecePic = pieceImageList[3];
				pieceList[i]->type = "q";
				
				for (size_t j = 0; j < sizeof(pieceList[j]->queenArray) / sizeof(pieceList[j]->queenArray[0]); j++)
				{
					pieceList[i]->pieceMoveList.push_back(pieceList[i]->queenArray[j]);
				}
			}
			else if (i == 4 + blackPiecesIndex2) { //Condition for King
				pieceList[i]->piecePic = pieceImageList[4];
				pieceList[i]->type = "k";
				
				for (size_t j = 0; j < sizeof(pieceList[j]->kingArray) / sizeof(pieceList[j]->kingArray[0]); j++)
				{
					pieceList[i]->pieceMoveList.push_back(pieceList[i]->kingArray[j]);
				}
			}
			else if (i >= 8 && colour == true) { //Condition for Pawn
				pieceList[i]->piecePic = pieceImageList[5];
				pieceList[i]->type = "p";

				for (size_t j = 0; j < sizeof(pieceList[j]->pawnArray) / sizeof(pieceList[j]->pawnArray[0]); j++)
				{
					pieceList[i]->pieceMoveList.push_back(pieceList[i]->pawnArray[j]);
				}
			}
			else if (i <= 7 && colour == false) { //Condition for Pawn
				pieceList[i]->piecePic = pieceImageList[5];
				pieceList[i]->type = "p";

				for (size_t j = 0; j < sizeof(pieceList[j]->pawnArray) / sizeof(pieceList[j]->pawnArray[0]); j++)
				{
					pieceList[i]->pieceMoveList.push_back(pieceList[i]->pawnArray[j]);
				}
			}

			pieceList[i]->piecePic.draw(Board.TileList[i + blackPiecesIndex]->posx, Board.TileList[i + blackPiecesIndex]->posy);
			pieceList[i]->piecePic.resize(60, 60);
		}
	
	/*
	else if (colour == false) {


		for (int i = 0; i < 16; i++)
		{
			int blackPiecesIndex = 0;
			if (colour == false) {
				blackPiecesIndex = 48;
				pieceList[i]->colour = 0;

			}

			pieceList[i] = new piece; // Creates a new piece for the first sixteen tiles
			pieceList[i]->IsEliminated = false; // Just sets the alive state for the piece
			pieceList[i]->PositionX = Board.TileList[i + 48]->posx;
			pieceList[i]->PositionY = Board.TileList[i + 48]->posy;
			pieceList[i]->currentTile = Board.TileList[i + 48];
			
			pieceList[i]->currentIndex = i + 48;

			Board.TileList[i + 48]->occupiedState = true;
			Board.TileList[i + 48]->colour = 0;
			

			if (i == 8 || i == 15) { //Condition for Rooks
				pieceList[i]->piecePic = pieceImageList[0];
				pieceList[i]->type = "r";

				for (size_t j = 0; j < sizeof(pieceList[j]->rookArray) / sizeof(pieceList[j]->rookArray[0]); j++)
				{
					pieceList[i]->pieceMoveList.push_back(pieceList[i]->rookArray[j]);
				}
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

			pieceList[i]->piecePic.draw(Board.TileList[i + 48]->posx, Board.TileList[i + 48]->posy);
			pieceList[i]->piecePic.resize(60, 60);
		}
	}
	*/

	

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