#include "Text.h"


void Text::MakeImage()
{
	SDL_Surface* temp = TTF_RenderText_Solid(font, text, color);
	image = SDL_CreateTextureFromSurface(renderer, temp);
	position.h = temp->h;
	position.w = temp->w;
	SDL_FreeSurface(temp);
}

Text::Text(const char* _text, int _size, SDL_Renderer* _renderer /*= NULL*/, SDL_Color _color /*= { 255,255,255 }*/, InputSystem* _inputSystem /*= nullptr*/):Item(_renderer,_inputSystem)
{
	text = _text;
	fontSize = _size;
	font = TTF_OpenFont("Cruiser.ttf", fontSize);
	color = _color;
	MakeImage();
}

void Text::Update()
{

}
