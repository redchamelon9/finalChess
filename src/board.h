#pragma once

class board
{

public:

	int			position[2];
	bool		state;
	//int			TileList[64];
	
	tile		*TileList[64];
	
	ofImage		boardImage;

	bool		getState() {}
	void		setState() {}
	void		setTiles() {}


};

