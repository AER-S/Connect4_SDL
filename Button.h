#pragma once
#include "Item.h"
#include "SceneManager.h"

class Button : public Item
{
	SceneManager* sceneManager;

	int step;
	bool initialized;
	int initXPos;
	int initYPos;

	void MoveUp();
	void MoveDown();
	void Initialize();
	void Press();

public:
	Button(SDL_Renderer* _renderer = NULL, InputSystem* _inputSystem= nullptr, SceneManager* _sceneManager = nullptr);
	void Update();
};

