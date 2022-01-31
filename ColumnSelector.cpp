#include "ColumnSelector.h"

ColumnSelector::ColumnSelector(GameManager* _gameManager, SDL_Renderer* _renderer /*= NULL*/, InputSystem* _inputSystem /*= nullptr*/):Selector(_renderer,_inputSystem)
{
	gameManager = _gameManager;
}

void ColumnSelector::Press()
{
	gameManager->PutBall(step);
}
