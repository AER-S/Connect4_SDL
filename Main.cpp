#include "GameEngine.h"

#define WIDTH 800
#define HEIGHT 600

int main(int argc, char* args[])
{
	GameEngine connect4("CONNECT 4", WIDTH, HEIGHT);
	connect4.Run();
	return 0;
}