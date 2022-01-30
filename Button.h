#pragma once
#include "Item.h"
class Button : public Item
{
public:
	Button(SDL_Renderer* _renderer = NULL, InputSystem* _inputSystem= nullptr);
	void Update();
};

