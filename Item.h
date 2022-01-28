#pragma once
#include <SDL.h>

class Item
{
	SDL_Surface* image;
	SDL_Rect position;

public:
	Item();
	void Draw(SDL_Surface* _screen);
	~Item();
};

