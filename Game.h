#pragma once
#include "GameEngine.h"

#define WIDTH 800
#define HEIGHT 600

class Game
{
	GameEngine* gameEngine;
	int width;
	int height;

	void Lobby(SDL_Renderer* _renderer, InputSystem* _inputSystem);
	void Rules(SDL_Renderer* _renderer, InputSystem* _inputSystem);
	void HowToPlay(SDL_Renderer* _renderer, InputSystem* _inputSystem);

public:
	Game(const char* _title, int _width=WIDTH, int _height=HEIGHT);
	void Start();
	void Run();
	~Game();
};

