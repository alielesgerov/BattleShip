#include"board.h"
using namespace std;


void board_clean(Game game)
{
	for (int a = 0; a < 2; a++)
	{
		for (int i = 0; i < game.board_size; i++)
		{
			for (int j = 0; j < game.board_size; j++)
			{
				game.player[a].board[i][j]=' ';
			}
		}
	}
}


void set_ships(Game game, int player_trn)
{
	char direction;
	int coordinate[2];
	for (int a=0;a<5;a++)
	{
		system("CLS");
		board_print(game, player_trn);
		cout << game.player[player_trn].name << "'s turn to place ships." << endl;
		cout << "Place ship("<<a+1<<" spaces): \nEnter direction(h[horizontal] or v[vertical]:";
		direction = _getch();
		cout << direction;
		if (direction != 'h' && direction != 'v')
		{
			cout << "Enter a valid direction!" << endl;
			Sleep(300);
			a--;
			continue;
		}
		cout << "\nEnter coordinates: ";
		cin >> coordinate[0] >> coordinate[1];
		bool flag = 1;
		for (int buf1=coordinate[0],buf2=coordinate[1],i=0;i<a+1;i++)
		{
			if ( buf1 < 0 || buf1>9 ||buf2 < 0 || buf2>9)
			{
				flag = 0;
				break;
			}
			else if (game.player[player_trn].board[buf1][buf2] != ' ')
			{
				flag = 0;
				break;
			}
			if (direction == 'h')
			{
				buf2++;
			}
			else if (direction == 'v')
			{
				buf1++;
			}
		}
		if (flag == 0)
		{
			cout << "Enter a valid coordinate! " << endl;
			Sleep(300);
			a--;
			continue;
		}
		if (direction == 'h')
		{
			for (int i = 0; i < a+1; i++)
			{
				game.player[player_trn].ships.ship[a][i] = coordinate[0] * 10 + coordinate[1];
				game.player[player_trn].board[coordinate[0]][coordinate[1]] = 254;
				coordinate[1]++;
			}
		}
		else if (direction == 'v')
		{
			for (int i = 0; i < a+1; i++)
			{
				game.player[player_trn].ships.ship[a][i] = coordinate[0] * 10 + coordinate[1];
				game.player[player_trn].board[coordinate[0]][coordinate[1]] = 254;
				coordinate[0]++;
			}
		}
	}
}

void board_print(Game game,int player_trn)
{
	cout << "| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | " << endl;
	cout << "------------------------------------------" << endl;

	for (int i = 0; i < game.board_size; i++)
	{
		for (int j = 0; j < game.board_size; j++)
		{
			cout << "| " << game.player[player_trn].board[i][j]<<" "	;
		}
		cout << "| " << i << endl;
		cout << "------------------------------------------"<<endl;
	}
	
}

