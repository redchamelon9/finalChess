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
	char	type;
	

	//piece	getPiece(){}
	char	getType() {}
	void	move(int locationX, int locationY) {}
	void	eliminate(int opponentX, int opponentY);
	void	revive(int reviveX, int reviveY);
	void	isChecked() {}
	void	isCheckmate() {}


};

