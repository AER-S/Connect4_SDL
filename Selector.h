#pragma once
#include "Item.h"
#include <vector>

class Selector :public Item
{
protected:
	std::vector<Item*> itemsToSelectFrom;
	Item* selectedItem;
	int step;
	bool initialized;

	void MoveUp();
	void MoveDown();
	void TakeSelectedPosition();

public:
	Selector(SDL_Renderer* _renderer = NULL, InputSystem* _inputSystem = nullptr);
	void Update();
	void AddItem(Item* _item);
	void Initialize();
	virtual void Press()=0;
};

