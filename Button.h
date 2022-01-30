#pragma once
#include "Item.h"
class Button : public Item
{
	int step;
	bool initialized;
	int initXPos;
	int initYPos;
	void MoveUp();
	void MoveDown();
	void Initialize();

public:
	Button(SDL_Renderer* _renderer = NULL, InputSystem* _inputSystem= nullptr);
	void Update();
};

