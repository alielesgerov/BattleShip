#pragma once
#include<Windows.h>
#include<conio.h>
#include<iostream>


struct Ships
{
	int** ship = new int* [5];
};

struct Player
{
	char** board = new char* [10];
	char* name;
	Ships ships;
};

struct Game
{
	int board_size = 10;
	Player*player = new Player[2];
};

