#include "GameEngine.h"


void GameEngine::HandleEvents(SDL_Event* _events)
{
	while (SDL_PollEvent(_events))
	{
		switch (_events->type)
		{
		case SDL_QUIT:
			run = false;
			break;
		default:
			break;
		}
	}
}

GameEngine::GameEngine(const char* _title, int _width, int _height)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_RESIZABLE);
	run = true;
}

void GameEngine::Run()
{
	SDL_Event ev;
	while (run)
	{
		HandleEvents(&ev);
	}
}

GameEngine::~GameEngine()
{
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_Quit();
}
