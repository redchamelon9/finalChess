#pragma once
class player
{
public:
	//string		PlayerName;
	//bool		colour;
	int			PlayerID;
	//piece		Piece;

	string		wImageNames[6] = { "wr.png","wn.png","wb.png","wq.png","wk.png", "wp.png"};
	string		bImageNames[6] = { "br.png","bn.png","bb.png","bq.png","bk.png","bp.png" };
	ofImage		pieceImageList[12];
	piece*		pieceList[16];
	//piece*		eliminatedPieceList[16];

	void		setUpPieces(board, bool);
	
	void		setName();
	void		setPlayerID() {}
	int			getPlayerID() {}

	player();
	~player();


};

