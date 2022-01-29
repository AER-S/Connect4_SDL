#include "Game.h"



int main(int argc, char* args[])
{
	Game newGame("Connect4");
	newGame.Start();
	newGame.Run();
	return 0;
}