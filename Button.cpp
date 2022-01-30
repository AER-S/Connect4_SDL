#include "Button.h"

#define MOVE_ON_Y position.y = initYPos - step * 60

void Button::MoveUp()
{
	Initialize();
	step++;
	if (step > 1) step = -1;
	MOVE_ON_Y;
	
}

void Button::MoveDown()
{
	Initialize();
	step--;
	if (step < -1) step = 1;
	MOVE_ON_Y;
}

void Button::Initialize()
{
	if (!initialized)
	{
		initialized = true;
		initXPos = position.x;
		initYPos = position.y;
	}
}

Button::Button(SDL_Renderer* _renderer /*= NULL*/, InputSystem* _inputSystem /*= nullptr*/):Item(_renderer,_inputSystem)
{
	step = 0;
	initialized = false;
	initXPos = 0;
	initYPos = 0;
}

void Button::Update()
{
	if (inputSystem)
	{
		if (inputSystem->Use(&(inputSystem->upKey)))
		{
			MoveUp();
		}
		if (inputSystem->Use(&(inputSystem->downKey)))
		{
			MoveDown();
		}
	}
}

