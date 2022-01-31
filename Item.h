#pragma once
#include <SDL.h>
#include "InputSystem.h"
#include <string>

class Item
{
protected:
	SDL_Renderer* renderer;
	SDL_Texture* image;
	SDL_Rect position;
	InputSystem* inputSystem;
	bool visible;

public:
	Item(SDL_Renderer* _renderer=NULL, InputSystem* _inputSystem=nullptr);
	void Draw();
	void SetInputSystem(InputSystem* _inputSystem);
	void SetRenderer(SDL_Renderer* _renderer);
	virtual void Update()=0;
	void SetPosition(int _xpos, int _ypos);
	void SetSize(int _witdth, int _height);
	void SetVisible(bool _state);
	bool LoadImage(std::string _filename);
	void DeleteImage();
	virtual void Reset();
	SDL_Rect GetPosition();
	~Item();
};

