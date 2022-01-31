#pragma once
#include "Text.h"
#include "Item.h"
#include "Board.h"
#include "TitleBanner.h"
#include "SceneManager.h"

class GameManager :public Item
{

	Board* board;
	int player;
	bool won;
	int winner;

	Text* playerTD;
	TitleBanner*** balls;
	SceneManager* sceneManager;

	void UpdatePlayer();
	void RedWin();
	void BlueWin();
	void Draw();
	

public:
	GameManager(SDL_Renderer* _renderer = NULL, InputSystem* _inputSystem = nullptr);
	void StartTurn();
	void Update();
	void PutBall(int _column);
	void SetPlayerTDisplay(Text* _playerTD);
	void SetSceneManager(SceneManager* _sceneManager);
	void SetBalls(TitleBanner*** _balls);
	void Reset() override;
	~GameManager();
};

