#include "Start_Game.h"
#include"structs.h"
#include"board.h"
using namespace std;
void Start(Game game)
{
	char* buf=new char[30];
	system("CLS");
	cout << "Enter player1 name: ";
	cin.getline(buf,30);
	game.player[0].name = _strdup(buf);
	Sleep(150);
	system("CLS");
	cout << "Enter player2 name: ";
	cin.getline(buf, 30);
	game.player[1].name = _strdup(buf);
	Sleep(150);
	system("CLS");
	board_clean(game);
	for (int i = 0; i < 2; i++)
	{
		set_ships(game,i);
	}
	board_clean(game);
	game_play(game);
}

void game_play(Game game)
{
	int coordinate[2];
	int player_trn = 0;
	while (true) 
	{
		bool flag = false;
		system("CLS");
		board_print(game, player_trn);
		if (player_trn == 1)
			cout << game.player[player_trn-1].name << "'s turn to fire." << endl;
		else
			cout << game.player[player_trn+1].name << "'s turn to fire." << endl;
		cout << "Enter coordinates:";
		cin >> coordinate[0] >> coordinate[1];
		if (coordinate[0]<0 || coordinate[0]>9 || coordinate[1] < 0 || coordinate[1]>9|| game.player[player_trn].board[coordinate[0]][coordinate[1]]!=' ')
		{
			cout << "Enter a valid coordinate!" << endl;
			Sleep(300);
			continue;
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (game.player[player_trn].ships.ship[i][j] == coordinate[0] * 10 + coordinate[1])
				{
					flag = true;
				}
				else
					continue;
			}
		}
		if (flag == true)
		{
			game.player[player_trn].board[coordinate[0]][coordinate[1]] = 'X';
			cout << "You hit the ship" << endl;
			Sleep(1000);
		}
		else
		{
			game.player[player_trn].board[coordinate[0]][coordinate[1]] = 'O';
			cout << "You miss" << endl;

			if (player_trn == 1)
				player_trn = 0;
			else
				player_trn = 1;
			Sleep(1000);
		}
		if (win_check(game, player_trn) == true)
		{
			if (player_trn == 1)
				player_trn = 0;
			else
				player_trn = 1;
			system("CLS");
			cout << game.player[player_trn].name << " WIN" << endl;
			system("pause");
			return;
		}
		else
			continue;
	}

}

bool win_check(Game game,int player_trn)
{
	int buffer_cor[2];
	int destroyed_ship_spaces=0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			buffer_cor[0] = game.player[player_trn].ships.ship[i][j] / 10;
			buffer_cor[1] = game.player[player_trn].ships.ship[i][j] % 10;
			if (game.player[player_trn].board[buffer_cor[0]][buffer_cor[1]] == 'X')
			{
				destroyed_ship_spaces++;
			}
		}
	}
	if (destroyed_ship_spaces == 15)
		return true;
	else
		return false;
}