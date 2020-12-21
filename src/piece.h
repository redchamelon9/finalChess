#pragma once
#include <vector>
#include <iostream>

class piece
{
public:
	int			PlayerID;
	int			PositionX;
	int			PositionY;
	int			colour;

	int			pawnArray[4] = { 8,16,7,9 };
	int			rookArray[14] = { 1,2,3,4,5,6,7,8,16,24,32,40,48,56 };
	int			bishopLArray[13] = {9,18,27,36,45,54,63,7,14,21,28,35,42};
	int			bishopRArray[13] = {9,18,27,36,45,54,7,14,21,28,35,42,49 };
	int			knightArray[4] = { 15,17,10,6 };
	int			queenArray[28] = { 1,2,3,4,5,6,7,8,16,24,32,40,48,56,9,18,27,36,45,54,63,7,14,21,28,35,42,49 };
	int			kingArray[4] = { 1,7,8,9};

	int			thisPieceArray[28];
	
	vector		<int> pieceMoveList;

	int			currentIndex;

	bool		IsEliminated;
	int			MoveTo;
	ofImage		piecePic;
	tile		*currentTile;

	//ofImage	pieceImageList[6];
	//piece*	alivePieceList;
	//piece*	eliminatedPieceList;
	const char*	type;
	

	//piece	getPiece(){}
	void	move(board, int);
	bool	eliminate();
	bool	moveCheck(board,int);


	void	revive(int reviveX, int reviveY);
	void	isChecked() {}
	void	isCheckmate() {}


};

