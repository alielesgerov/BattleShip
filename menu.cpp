#include<iostream>
#include "structs.h"
#include "Start_Game.h"
using namespace std;
int main()
{
	Game game;
	game.player = new Player[2];
	for (int i=0; i < 2; i++)
	{
		for (int j = 0; j < game.board_size; j++)
		{
			game.player[i].board[j] = new char[10];
		}
		game.player[i].ships.ship[0] = new int[1];//destroyer
		game.player[i].ships.ship[1] = new int[2];//submarine
		game.player[i].ships.ship[2] = new int[3];//cruiser
		game.player[i].ships.ship[3] = new int[4];//battleship
		game.player[i].ships.ship[4] = new int[5];//carrier
	}
	int chc;
	while (true)
	{
		system("CLS");
		cout << " ____       _______ _______ _      ______  _____ _    _ _____ _____ " << endl;
		cout << "|  _ \\   /\\|__   __|__   __| |    |  ____|/ ____| |  | |_   _|  __ \\" << endl;
		cout << "| |_) | /  \\  | |     | |  | |    | |__  | (___ | |__| | | | | |__) |" << endl;
		cout << "|  _ < / /\\ \\ | |     | |  | |    |  __|  \\___ \\|  __  | | | |  ___/ " << endl;
		cout << "| |_) / ____ \\| |     | |  | |____| |____ ____) | |  | |_| |_| |     " << endl;
		cout << "|____/_/    \\_\\_|     |_|  |______|______|_____/|_|  |_|_____|_|   " << endl;
		cout << "/////////////////////////////////////////////////////////////////////" << endl;
		cout << "1.PLAY(for to start the game press any button)" << endl;
		cout << "2.EXIT( press the 'esc' button to exit)" << endl;
		chc = _getch();
		switch (chc)
		{
		case 27:
				return 0;
				break;
		default:
			Start(game);
			break;
		}
	}
	return 0;
}
