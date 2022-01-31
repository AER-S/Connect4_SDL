#include "GameManager.h"

void GameManager::UpdatePlayer()
{
	player++;
	player = player % 2;
}

void GameManager::RedWin()
{
	sceneManager->SetActive(5);
}

void GameManager::BlueWin()
{
	sceneManager->SetActive(6);
}

void GameManager::Draw()
{
	sceneManager->SetActive(7);
}

void GameManager::StartTurn()
{
	SDL_Color red = { 255,0,0 };
	SDL_Color blue = { 0,128,255 };
	if (player == 0)
	{
		playerTD->SetText("Red Player Turn!");
		playerTD->SetColor(red);
	}
	else
	{
		playerTD->SetText("Blue Player Turn!");
		playerTD->SetColor(blue);
	}
}



GameManager::GameManager(SDL_Renderer* _renderer /*= NULL*/, InputSystem* _inputSystem /*= nullptr*/):Item(_renderer,_inputSystem)
{
	Reset();
	playerTD = nullptr;
	balls = nullptr;
	sceneManager = nullptr;
}

void GameManager::Update()
{
	if (board->IsFull() || won) SDL_Delay(1500);
	if (winner == 0) RedWin();
	else if (winner == 1) BlueWin();
	if (board->IsFull()) Draw();
}

void GameManager::PutBall(int _column)
{
	
	char color = (player == 0) ? 'R' : 'B';
	int row =board->Put(color,_column);
	if (player == 0) balls[row][_column]->LoadImage("Red_ball.png");
	else balls[row][_column]->LoadImage("Blue_ball.png");
	if (board->CheckForWin(color, row, _column)) 
	{ 
		winner = player;
		won = true;
		return;
	}
	if (board->IsFull())
	{
		SDL_Delay(1500);
		Draw();
	}
	UpdatePlayer();
	StartTurn();
}

void GameManager::SetPlayerTDisplay(Text* _playerTD)
{
	playerTD = _playerTD;
}

void GameManager::SetSceneManager(SceneManager* _sceneManager)
{
	sceneManager = _sceneManager;
}

void GameManager::SetBalls(TitleBanner*** _balls)
{
	balls = _balls;
}

void GameManager::Reset()
{
	delete board;
	board = new Board(4,6,7);
	player = 0;
	won = false;
	winner = -1;
	if (balls!=nullptr)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				balls[i][j]->DeleteImage();
			}
		}
	}
}

GameManager::~GameManager()
{
	delete board;
	board = nullptr;
}
