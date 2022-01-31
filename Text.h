#pragma once
#include "Item.h"
#include <SDL_ttf.h>
//#include <string>

class Text :public Item
{
	const char* text;
	TTF_Font* font;
	int fontSize;
	SDL_Color color;
	
	void MakeImage();

public:
	Text(const char* _text, int _size, SDL_Renderer* _renderer = NULL, SDL_Color _color = { 255, 255, 255 }, InputSystem* _inputSystem = nullptr);
	void Update();
	void SetColor(SDL_Color _color);
	void SetText(const char* _text);
};

