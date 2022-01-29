#include "InputSystem.h"

InputSystem::InputSystem()
{
	used = true;
	horizontal = 0;
	vertical = 0;
	fire = false;
	enter = false;
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

bool InputSystem::Use(bool* _trigger)
{
	if (!used)
	{
		used = true;
		bool state = _trigger;
		*_trigger = false;
		return state;
	}
	else return false;
}

void InputSystem::Trig(bool* _trigger)
{
	if (used)
	{
		used = false;
		*_trigger = true;
	}
}
