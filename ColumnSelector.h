#pragma once
#include "Selector.h"
#include "GameManager.h"

class ColumnSelector : public Selector
{
	GameManager* gameManager;
public:
	ColumnSelector(GameManager* _gameManager, SDL_Renderer* _renderer = NULL, InputSystem* _inputSystem = nullptr);
	void Press();
};


