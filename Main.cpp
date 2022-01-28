#include <iostream>
#include <SDL.h>

#define WIDTH 800
#define HEIGHT 600

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Connect 4", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
	SDL_Delay(5000);
	SDL_DestroyWindow(window);
	SDL_Quit();
	//std::cout << "Hello World!" << std::endl;
	return 0;
}