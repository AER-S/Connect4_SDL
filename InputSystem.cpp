#include "InputSystem.h"

//debug
//#include <iostream>

InputSystem::InputSystem()
{
	used = true;
	horizontal = 0;
	vertical = 0;
	fire = false;
	enter = false;
	down = false;
	numbers = new bool[10]{};
}

void InputSystem::SetHorizontal(float _horizontal)
{
	horizontal = _horizontal;
}

void InputSystem::SetVertical(float _vertical)
{
	vertical = _vertical;
}

float InputSystem::GetHorizontal()
{
	return horizontal;
}

float InputSystem::GetVertical()
{
	return vertical;
}

void InputSystem::SetDown(bool _state)
{
	down = _state;
}

bool InputSystem::GetDown()
{
	return down;
}

bool InputSystem::Use(bool* _trigger)
{
	if (!used)
	{
		used = true;
		bool state = *_trigger;
		*_trigger = false;
		return state;
	}
	else return false;
}

void InputSystem::Trig(bool* _trigger)
{
	if (!down)
	{
		if (used)
		{
			used = false;
			*_trigger = true;
			down = true;
		}
	}
	//debug
	//std::cout << "triggered!\n";
}
