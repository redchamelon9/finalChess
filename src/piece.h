#pragma once
class piece
{
public:
	int		PlayerID;
	int		PositionX;
	int		PositionY;

	bool	IsEliminated;
	int		MoveTo;
	ofImage piecePic;

	//ofImage	pieceImageList[6];
	//piece*	alivePieceList;
	//piece*	eliminatedPieceList;
	const char*	type;
	

	//piece	getPiece(){}
	void	move(int locationX, int locationY) {}
	void	eliminate(int opponentX, int opponentY);
	void	revive(int reviveX, int reviveY);
	void	isChecked() {}
	void	isCheckmate() {}


};

