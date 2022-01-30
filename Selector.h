#pragma once
#include "Item.h"
#include "SceneManager.h"
#include <vector>

class Selector :public Item
{
	SceneManager* sceneManager;
	std::vector<Item*> itemsToSelectFrom;
	Item* selectedItem;
	int step;
	bool initialized;

	void MoveUp();
	void MoveDown();
	void TakeSelectedPosition();

public:
	Selector(SDL_Renderer* _renderer = NULL, InputSystem* _inputSystem = nullptr, SceneManager* _sceneManager = nullptr);
	void Update();
	void AddItem(Item* _item);
	void Initialize();
	void Press();
};

