#include "Main.h"

void player::setUpPieces(board Board, bool colour) {


	if (colour == true) {


		for (int i = 0; i < 16; i++)
		{
			pieceList[i] = new piece;
			pieceList[i]->IsEliminated = false;
			pieceList[i]->PositionX = Board.TileList[i]->posx;
			pieceList[i]->PositionY = Board.TileList[i]->posy;

			Board.TileList[i]->typeOfPiece = *pieceList[i];

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
			pieceList[i] = new piece;
			pieceList[i]->IsEliminated = false;
			
			pieceList[i]->PositionX = Board.TileList[i + 48]->posx;
			pieceList[i]->PositionY = Board.TileList[i + 48]->posy;

			Board.TileList[i]->typeOfPiece = *pieceList[i];

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