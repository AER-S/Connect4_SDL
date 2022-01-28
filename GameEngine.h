#pragma once
#include <SDL.h>

class GameEngine
{
	SDL_Window* window;

public:
	GameEngine(const char* _title, int _width, int _height);
	~GameEngine();
};

