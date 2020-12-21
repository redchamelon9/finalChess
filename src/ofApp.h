#pragma once

#include "Main.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();


		//player	Player1;
		//player	Player2;
		board	Board;
		piece	wPawn;
		piece	bPawn;

		piece	*currentPiece;
		player	*currentPlayer;

		player bPlayer;
		player wPlayer;

		bool mouseDraggingPiece;
		bool mouseReleasePiece;

		bool	turn;
		//		Display
		//		Input
		bool	endState = false;
		//AI	AI

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void draggingPiece(int x, int y, piece draggedPiece);


		
};
