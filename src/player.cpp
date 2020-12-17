#include "Main.h"

player::player() {

}

player::~player() {

}

int	player::setName() {

	string name1 = "Player1";
	string name2 = "Player2";



	cout << "Player 1's name: \n";
	cin >> name1;
	cout << "Player 2's name: \n";
	cin >> name2;

	cout << "Player 1's name is " << name1;
	cout << "Player 2's name is " << name2;
}
