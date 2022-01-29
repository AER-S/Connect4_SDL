#include "Item.h"
#include <SDL_image.h>

Item::Item()
{
	position.x = 30;
	position.y = 60;
	image = SDL_CreateRGBSurface(0, 20, 20, 32, 0, 0, 0, 0);
	position.w = image->clip_rect.w;
	position.h = image->clip_rect.h;
	SDL_FillRect(image, NULL, 0xffff00);
}

void Item::Draw(SDL_Surface* _screen)
{
	if (image)
	{
		SDL_BlitSurface(image, NULL, _screen, &position);
	}
}

void Item::Update()
{

}

void Item::SetPosition(int _xpos, int _ypos)
{
	position.x = _xpos;
	position.y = _ypos;
}

bool Item::LoadImage(std::string _filename, SDL_Surface* _screen)
{
	if (image)
	{
		SDL_FreeSurface(image);
	}

	SDL_Surface* newImage = IMG_Load(_filename.c_str());
	image = SDL_ConvertSurface(newImage, _screen->format, 0);
	SDL_FreeSurface(newImage);
	if (image)return true;
	else return false;
}

Item::~Item()
{
	delete image;
	image = nullptr;
}
