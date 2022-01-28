#pragma once
#include <SDL.h>

class GameEngine
{
	SDL_Window* window;
	bool run;
	
	void HandleEvents(SDL_Event* _events);

public:
	GameEngine(const char* _title, int _width, int _height);
	void Run();
	~GameEngine();
};

