#pragma once
#include "Item.h"
class TitleBanner : public Item
{
public:
	TitleBanner(SDL_Renderer* _renderer = NULL, InputSystem* _inputSystem = nullptr);
	void Update();
};

