#pragma once
#include <SDL.h>
#include "InputSystem.h"
#include <string>

class Item
{
	SDL_Renderer* renderer;
	SDL_Texture* image;
	SDL_Rect position;
	InputSystem* inputSystem;

public:
	Item(SDL_Renderer* _renderer=NULL, InputSystem* _inputSystem=nullptr);
	void Draw();
	void SetInputSystem(InputSystem* _inputSystem);
	void SetRenderer(SDL_Renderer* _renderer);
	void Update();
	void SetPosition(int _xpos, int _ypos);
	void SetSize(int _witdth, int _height);
	bool LoadImage(std::string _filename);
	~Item();
};

