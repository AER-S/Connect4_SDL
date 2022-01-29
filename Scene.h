#pragma once
#include <SDL.h>
#include "Item.h"
#include <vector>

class Scene
{
	std::vector<Item*> items;
public:
	void AddItem(Item* _item);
	void Draw(SDL_Surface* _screen);
	void Update();
	~Scene();
};
