#pragma once
#include "Selector.h"
#include "SceneManager.h"

class LobbySelector :public Selector
{
	SceneManager* sceneManager;
public:
	LobbySelector(SDL_Renderer* _renderer = NULL, InputSystem* _inputSystem = nullptr, SceneManager* _sceneManager = nullptr);
	void Press();
};

