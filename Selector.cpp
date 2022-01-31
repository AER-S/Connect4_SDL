#include "Selector.h"

void Selector::MoveUp()
{
	step--;
	if (step < 0) step = itemsToSelectFrom.size() - 1;
	selectedItem = itemsToSelectFrom[step];
	TakeSelectedPosition();
}

void Selector::MoveDown()
{
	step++;
	if ((unsigned)step >= itemsToSelectFrom.size()) step = 0;
	selectedItem = itemsToSelectFrom[step];
	TakeSelectedPosition();
}

void Selector::TakeSelectedPosition()
{
	position.x = (selectedItem->GetPosition().x + (selectedItem->GetPosition().w / 2)) - (position.w / 2);
	position.y = (selectedItem->GetPosition().y + (selectedItem->GetPosition().h / 2)) - (position.h / 2);
}

Selector::Selector(SDL_Renderer* _renderer /*= NULL*/, InputSystem* _inputSystem /*= nullptr*/):Item(_renderer,_inputSystem)
{
	selectedItem = nullptr;
	step = 0;
	initialized = false;
}

void Selector::Update()
{
	if (inputSystem)
	{
		if (inputSystem->Use(&(inputSystem->upKey)) || inputSystem->Use(&(inputSystem->leftKey)))
		{
			MoveUp();
		}
		if (inputSystem->Use(&(inputSystem->downKey))|| inputSystem->Use(&(inputSystem->rightKey)))
		{
			MoveDown();
		}
		if (inputSystem->Use(&(inputSystem->fire)))
		{
			Press();
		}
	}
}

void Selector::AddItem(Item* _item)
{
	itemsToSelectFrom.push_back(_item);
}

void Selector::Initialize()
{
	if (!initialized && itemsToSelectFrom.size()>0)
	{
		initialized = true;
		selectedItem = itemsToSelectFrom[0];
		TakeSelectedPosition();
	}
}


