#pragma once
#include <SDL.h>
#include <string>

class Item
{
	SDL_Surface* image;
	SDL_Rect position;

public:
	Item();
	void Draw(SDL_Surface* _screen);
	void Update();
	void SetPosition(int _xpos, int _ypos);
	bool LoadImage(std::string _filename, SDL_Surface* _screen);
	~Item();
};

