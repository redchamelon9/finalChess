#pragma once



class board
{

public:

	int			position[2];
	bool		state;
	//piece		piece;
	bool		TileListState[64];
	ofImage		boardImage;

	bool		getState() {}
	void		setState() {}
	void		setTiles() {}


};

