#include "GameEngine.h"


GameEngine::GameEngine(const char* _title, int _width, int _height)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_RESIZABLE);
}

GameEngine::~GameEngine()
{
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_Quit();
}
