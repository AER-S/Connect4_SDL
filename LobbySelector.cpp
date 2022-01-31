#include "LobbySelector.h"

LobbySelector::LobbySelector(SDL_Renderer* _renderer /*= NULL*/, InputSystem* _inputSystem /*= nullptr*/, SceneManager* _sceneManager /*= nullptr*/):Selector(_renderer,_inputSystem)
{
	sceneManager = _sceneManager;
}

void LobbySelector::Press()
{
	if (itemsToSelectFrom.size() <= 1) sceneManager->SetActive(1);
	else sceneManager->SetActive(step + 2);
}
