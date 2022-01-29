#include "Item.h"
#include <SDL_image.h>

//Debug
//#include <iostream>

Item::Item(SDL_Renderer* _renderer, InputSystem* _inputSystem)
{
	position.x = 30;
	position.y = 60;
	image = NULL;
	position.w = 100;
	position.h = 100;
	inputSystem = _inputSystem;
	renderer = _renderer;
}

void Item::Draw()
{
	if (image)
	{
		SDL_RenderCopy(renderer, image, NULL, &position);
	}
}

void Item::SetInputSystem(InputSystem* _inputSystem)
{
	inputSystem = _inputSystem;
}

void Item::Update()
{
	
	if (inputSystem)
	{
		if (inputSystem->Use(&(inputSystem->numbers[5])))
		{
			position.x += 5;
			//debug
			//std::cout << position.x << std::endl;
		}
	}
}

void Item::SetPosition(int _xpos, int _ypos)
{
	position.x = _xpos;
	position.y = _ypos;
}

void Item::SetSize(int _witdth, int _height)
{
	position.w = _witdth;
	position.h = _height;
}

bool Item::LoadImage(std::string _filename)
{
	if (image)
	{
		SDL_DestroyTexture(image);
	}

	SDL_Surface* newImage = IMG_Load(_filename.c_str());
	image = SDL_CreateTextureFromSurface(renderer,newImage);
	SDL_FreeSurface(newImage);
	if (image)return true;
	else return false;
}

Item::~Item()
{
	if (image)
	{
		SDL_DestroyTexture(image);
		image = NULL;
	}
}
