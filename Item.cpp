#include "Item.h"

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

Item::~Item()
{
	delete image;
	image = nullptr;
}
