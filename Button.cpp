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

void Button::Press()
{
	switch (step)
	{
	case 1:
		sceneManager->SetActive(2);
		break;
	case 0:
		sceneManager->SetActive(3);
		break;
	case -1:
		sceneManager->SetActive(4);
	default:
		break;
	}
}

Button::Button(SDL_Renderer* _renderer /*= NULL*/, InputSystem* _inputSystem /*= nullptr*/, SceneManager* _sceneManager /*= nullptr*/) :Item(_renderer, _inputSystem)
{
	sceneManager = _sceneManager;
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
		if (inputSystem->Use(&(inputSystem->fire)))
		{
			Press();
		}
	}
}

