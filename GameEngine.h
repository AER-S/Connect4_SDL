#pragma once
#include <SDL.h>
#include "SceneManager.h"
#include "InputSystem.h"



class GameEngine
{
	SDL_Window* window;
	SDL_Renderer* screen;

	SceneManager sceneManger;
	InputSystem inputSystem;

	bool run;
	
	void HandleEvents(SDL_Event* _events);
	void DrawActiveScene();
	void Update();

public:
	GameEngine(const char* _title, int _width, int _height);
	void Run();
	SDL_Renderer* GetScreen();
	SceneManager* GetSceneManager();
	InputSystem* GetInputSystem();
	~GameEngine();

};

