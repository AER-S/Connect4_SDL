#include <sstream>
#include <string>
#include "Game.h"
#include "TitleBanner.h"
#include "LobbySelector.h"
#include "Scene.h"
#include "Text.h"
#include "GameManager.h"
#include "ColumnSelector.h"

void Game::Lobby(SDL_Renderer* _renderer, InputSystem* _inputSystem)
{
	//*********************************************
	//************* First Scene *******************
	//*********************************************
	Scene* lobby = new Scene();
	gameEngine->GetSceneManager()->AddScene(lobby);
	//************** Title Banner ******************
	Item* titleBanner = new TitleBanner(_renderer);
	titleBanner->LoadImage("Connet_4.png");
	titleBanner->SetSize(688, 115);
	titleBanner->SetPosition(60, 30);
	lobby->AddItem(titleBanner);
	//gameEngine->GetSceneManager()->GetScene(0)->AddItem(titleBanner);

	//************** Rules Banner ******************
	Item* rules = new TitleBanner(_renderer);
	rules->LoadImage("Rules_orange.png");
	rules->SetSize(218, 68);
	rules->SetPosition((width / 2) - 109, (height / 2) - 94);
	lobby->AddItem(rules);
	//gameEngine->GetSceneManager()->GetScene(0)->AddItem(rules);

	//************** How To Play Banner ******************
	Item* howToPlay = new TitleBanner(_renderer);
	howToPlay->LoadImage("Htp_orange.png");
	howToPlay->SetSize(408, 68);
	howToPlay->SetPosition((width / 2) - 204, (height / 2) - 24);
	lobby->AddItem(howToPlay);
	//gameEngine->GetSceneManager()->GetScene(0)->AddItem(HowToPlay);

	//************** Rules Banner ******************
	Item* play = new TitleBanner(_renderer);
	play->LoadImage("Play_orange.png");
	play->SetSize(178, 68);
	play->SetPosition((width / 2) - 89, (height / 2) + 50);
	lobby->AddItem(play);
	//gameEngine->GetSceneManager()->GetScene(0)->AddItem(play);

	//************** Selector **************************
	LobbySelector* selector = new LobbySelector(_renderer, _inputSystem, gameEngine->GetSceneManager());
	selector->LoadImage("Button.png");
	selector->SetSize(620, 160);
	selector->AddItem(rules);
	selector->AddItem(howToPlay);
	selector->AddItem(play);
	selector->Initialize();
	lobby->AddItem(selector);
	//**************************************************
	gameEngine->GetSceneManager()->SetActive(lobby);
}

void Game::Rules(SDL_Renderer* _renderer, InputSystem* _inputSystem)
{
	//***************************************************
	//***************** Second Scene ********************
	//***************************************************
	Scene* rulesScene = new Scene();
	gameEngine->GetSceneManager()->AddScene(rulesScene);

	//**************** Title Banner *********************
	Item* titleBanner2 = new TitleBanner(_renderer);
	titleBanner2->LoadImage("Connet_4.png");
	titleBanner2->SetSize(688, 115);
	titleBanner2->SetPosition(60, 30);
	rulesScene->AddItem(titleBanner2);

	//************** Rules Banner ******************
	Item* rules = new TitleBanner(_renderer);
	rules->LoadImage("Rules_orange.png");
	rules->SetSize(218, 68);
	rules->SetPosition((width / 2) - 109, (height / 2) - 94);
	rulesScene->AddItem(rules);

	//**************** Rules line 1 *********************
	SDL_Color textCorlor = { 0,128,255 };
	int textSize = 22;
	Text* rule1 = new Text("1. Two Player (RED & BLUE) game.", textSize, _renderer, textCorlor);
	rule1->SetPosition(90, 300);
	rulesScene->AddItem(rule1);

	//**************** Rules line 2 *********************
	Text* rule2 = new Text("2. The board size is 6 rows & 7 columns.",textSize,_renderer,textCorlor);
	rule2->SetPosition(90, 330);
	rulesScene->AddItem(rule2);

	//**************** Rules line 3 *********************
	Text* rule31 = new Text("3. A player win if he/she is able to", textSize, _renderer, textCorlor);
	rule31->SetPosition(90, 360);
	rulesScene->AddItem(rule31);
	Text* rule32 = new Text("connect 4 dots horizontally, vertically", textSize, _renderer, textCorlor);
	rule32->SetPosition(128, 390);
	rulesScene->AddItem(rule32);
	Text* rule33 = new Text("or diagonally.", textSize, _renderer, textCorlor);
	rule33->SetPosition(128, 420);
	rulesScene->AddItem(rule33);

	//**************** Rules line 4 **********************
	Text* rule4 = new Text("4. A draw when the board is fully filled.", textSize, _renderer, textCorlor);
	rule4->SetPosition(90, 450);
	rulesScene->AddItem(rule4);

	//**************** Back Banner ***********************
	TitleBanner* backBanner = new TitleBanner(_renderer);
	backBanner->LoadImage("Back_orange.png");
	backBanner->SetSize(185, 68);
	backBanner->SetPosition((width / 2) - 92, 520);
	rulesScene->AddItem(backBanner);

	//**************** Back Selector *********************
	LobbySelector* backSelector = new LobbySelector(_renderer, _inputSystem, gameEngine->GetSceneManager());
	backSelector->LoadImage("Button.png");
	backSelector->SetSize(350, 160);
	backSelector->AddItem(backBanner);
	backSelector->Initialize();
	rulesScene->AddItem(backSelector);
	//****************************************************

}

void Game::HowToPlay(SDL_Renderer* _renderer, InputSystem* _inputSystem)
{
	//***************************************************
	//***************** Third Scene *********************
	//***************************************************
	Scene* HTPScene = new Scene();
	gameEngine->GetSceneManager()->AddScene(HTPScene);

	//**************** Title Banner *********************
	Item* titleBanner2 = new TitleBanner(_renderer);
	titleBanner2->LoadImage("Connet_4.png");
	titleBanner2->SetSize(688, 115);
	titleBanner2->SetPosition(60, 30);
	HTPScene->AddItem(titleBanner2);

	//************** How To Play Banner ******************
	Item* howToPlay = new TitleBanner(_renderer);
	howToPlay->LoadImage("Htp_orange.png");
	howToPlay->SetSize(408, 68);
	howToPlay->SetPosition((width / 2) - 204, (height / 2) - 94);
	HTPScene->AddItem(howToPlay);

	//************* How To Play line 1 ******************
	SDL_Color textCorlor = { 0,128,255 };
	int textSize = 22;
	Text* htp1 = new Text("1. Game Start with player 1 red.", textSize, _renderer, textCorlor);
	htp1->SetPosition(90, 300);
	HTPScene->AddItem(htp1);

	//************* How To Play line 2 *******************
	Text* htp21 = new Text("2. In Each step choose the column in which", textSize, _renderer, textCorlor);
	htp21->SetPosition(90, 330);
	HTPScene->AddItem(htp21);
	Text* htp22 = new Text(" you want to drop the ball.", textSize, _renderer, textCorlor);
	htp22->SetPosition(128, 360);
	HTPScene->AddItem(htp22);

	//************* How to Play line 3 *******************
	Text* htp3 = new Text("3. Rows will be filled from bottom to top in any column.", textSize, _renderer, textCorlor);
	htp3->SetPosition(90, 390);
	HTPScene->AddItem(htp3);

	//**************** Back Banner ***********************
	TitleBanner* backBanner = new TitleBanner(_renderer);
	backBanner->LoadImage("Back_orange.png");
	backBanner->SetSize(185, 68);
	backBanner->SetPosition((width / 2) - 92, 460);
	HTPScene->AddItem(backBanner);

	//**************** Back Selector *********************
	LobbySelector* backSelector = new LobbySelector(_renderer, _inputSystem, gameEngine->GetSceneManager());
	backSelector->LoadImage("Button.png");
	backSelector->SetSize(350, 160);
	backSelector->AddItem(backBanner);
	backSelector->Initialize();
	HTPScene->AddItem(backSelector);
	//****************************************************
}

void Game::Play(SDL_Renderer* _renderer, InputSystem* _inputSystem)
{
	//***************************************************
	//***************** Forth Scene *********************
	//***************************************************
	Scene* PlayScene = new Scene();
	gameEngine->GetSceneManager()->AddScene(PlayScene);

	//**************** Title Banner *********************
	Item* titleBanner2 = new TitleBanner(_renderer);
	titleBanner2->LoadImage("Connet_4.png");
	titleBanner2->SetSize(688, 115);
	titleBanner2->SetPosition(60, 30);
	PlayScene->AddItem(titleBanner2);

	//**************** Board Image **********************
	Item* boardImage = new TitleBanner(_renderer);
	boardImage->LoadImage("Board.png");
	boardImage->SetSize(420, 360);
	boardImage->SetPosition(190, 140);
	PlayScene->AddItem(boardImage);
	//***************************************************
	//************* columns indices ******************
	SDL_Color textCorlor = { 0,128,255 };
	int textSize = 40;
	Text** columns;
	columns = new Text * [7];
	for (int i = 0; i < 7; i++)
	{
		std::stringstream strs;
		strs << i+1;
		std::string index = strs.str();
		char* colIndex = (char*)index.c_str();
		columns[i] = new Text(colIndex, textSize, _renderer, textCorlor);
		columns[i]->SetPosition(215+i*58, 500);
		PlayScene->AddItem(columns[i]);
	}

	//************** Player Turn Text *******************
	SDL_Color playerTurnColor = { 250,10,10 };
	int playerTurnFontSize = 24;
	const char* playerTurnText = "Red Player Turn!";
	Text* playerTurnDisplay = new Text(playerTurnText, playerTurnFontSize, _renderer);
	playerTurnDisplay->SetPosition(270, 560);
	PlayScene->AddItem(playerTurnDisplay);

	//**************** Balls *****************************
	TitleBanner*** balls;
	balls = new TitleBanner * *[6];
	for (int i = 0; i < 6; i++)
	{
		balls[i] = new TitleBanner * [7];
		for (int j = 0; j < 7; j++)
		{
			balls[i][j] = new TitleBanner(_renderer);
			//balls[i][j]->LoadImage("Blue_ball.png");
			balls[i][j]->SetSize(60, 60);
			balls[i][j]->SetPosition(190 + j * 60, 140 + i * 60);
			PlayScene->AddItem(balls[i][j]);
		}
	}
	//*************** GameManger *************************
	GameManager* gameManager = new GameManager(_renderer, _inputSystem);
	gameManager->SetPlayerTDisplay(playerTurnDisplay);
	gameManager->SetBalls(balls);
	gameManager->SetSceneManager(gameEngine->GetSceneManager());
	gameManager->StartTurn();
	PlayScene->AddItem(gameManager);

	//******************* Colomn Selector ****************
	ColumnSelector* columnSelector = new ColumnSelector(gameManager, _renderer, _inputSystem);
	columnSelector->LoadImage("Button.png");
	columnSelector->SetSize(60, 100);
	for (int i = 0; i < 7; i++)
	{
		columnSelector->AddItem(columns[i]);
	}
	columnSelector->Initialize();
	PlayScene->AddItem(columnSelector);
}

void Game::RedWin(SDL_Renderer* _renderer, InputSystem* _inputSystem)
{
	//***************************************************
	//***************** Fifth Scene *********************
	//***************************************************
	Scene* redWin = new Scene();
	gameEngine->GetSceneManager()->AddScene(redWin);
	//**************** Title Banner *********************
	Item* titleBanner2 = new TitleBanner(_renderer);
	titleBanner2->LoadImage("Connet_4.png");
	titleBanner2->SetSize(688, 115);
	titleBanner2->SetPosition(60, 30);
	redWin->AddItem(titleBanner2);
	//****************** Red Ball ***********************
	TitleBanner* redBall = new TitleBanner(_renderer);
	redBall->LoadImage("Red_ball.png");
	redBall->SetSize(200, 200);
	redBall->SetPosition((width / 2) - 100, (height / 2) - 100);
	redWin->AddItem(redBall);
	
	//******************* Win Message *******************
	SDL_Color textColor = { 255,0,0 };
	int textFontSize = 40;
	Text* message = new Text("Red Player Wins", textFontSize, _renderer, textColor);
	message->SetPosition(175, 400);
	redWin->AddItem(message);

	//******************** Back Banner ******************
	TitleBanner* backBanner = new TitleBanner(_renderer);
	backBanner->LoadImage("Back_orange.png");
	backBanner->SetSize(185, 68);
	backBanner->SetPosition((width / 2) - 92, 500);
	redWin->AddItem(backBanner);

	//**************** Back Selector *********************
	LobbySelector* backSelector = new LobbySelector(_renderer, _inputSystem, gameEngine->GetSceneManager());
	backSelector->LoadImage("Button.png");
	backSelector->SetSize(350, 160);
	backSelector->AddItem(backBanner);
	backSelector->Initialize();
	redWin->AddItem(backSelector);
	//****************************************************
}

void Game::BlueWin(SDL_Renderer* _renderer, InputSystem* _inputSystem)
{
	//***************************************************
	//***************** sixth Scene *********************
	//***************************************************
	Scene* blueWin = new Scene();
	gameEngine->GetSceneManager()->AddScene(blueWin);
	//**************** Title Banner *********************
	Item* titleBanner2 = new TitleBanner(_renderer);
	titleBanner2->LoadImage("Connet_4.png");
	titleBanner2->SetSize(688, 115);
	titleBanner2->SetPosition(60, 30);
	blueWin->AddItem(titleBanner2);
	//****************** Red Ball ***********************
	TitleBanner* redBall = new TitleBanner(_renderer);
	redBall->LoadImage("Blue_ball.png");
	redBall->SetSize(200, 200);
	redBall->SetPosition((width / 2) - 100, (height / 2) - 100);
	blueWin->AddItem(redBall);

	//******************* Win Message *******************
	SDL_Color textColor = { 0,128,255 };
	int textFontSize = 40;
	Text* message = new Text("Blue Player Wins", textFontSize, _renderer, textColor);
	message->SetPosition(175, 400);
	blueWin->AddItem(message);

	//******************** Back Banner ******************
	TitleBanner* backBanner = new TitleBanner(_renderer);
	backBanner->LoadImage("Back_orange.png");
	backBanner->SetSize(185, 68);
	backBanner->SetPosition((width / 2) - 92, 500);
	blueWin->AddItem(backBanner);

	//**************** Back Selector *********************
	LobbySelector* backSelector = new LobbySelector(_renderer, _inputSystem, gameEngine->GetSceneManager());
	backSelector->LoadImage("Button.png");
	backSelector->SetSize(350, 160);
	backSelector->AddItem(backBanner);
	backSelector->Initialize();
	blueWin->AddItem(backSelector);
	//****************************************************
}

void Game::Draw(SDL_Renderer* _renderer, InputSystem* _inputSystem)
{
	//***************************************************
	//***************** sixth Scene *********************
	//***************************************************
	Scene* draw = new Scene();
	gameEngine->GetSceneManager()->AddScene(draw);
	//**************** Title Banner *********************
	Item* titleBanner2 = new TitleBanner(_renderer);
	titleBanner2->LoadImage("Connet_4.png");
	titleBanner2->SetSize(688, 115);
	titleBanner2->SetPosition(60, 30);
	draw->AddItem(titleBanner2);
	

	//******************* Win Message *******************
	SDL_Color textColor = { 255,255,255 };
	int textFontSize = 40;
	Text* message = new Text("The Game is a Draw", textFontSize, _renderer, textColor);
	message->SetPosition(110, 250);
	draw->AddItem(message);

	//******************** Back Banner ******************
	TitleBanner* backBanner = new TitleBanner(_renderer);
	backBanner->LoadImage("Back_orange.png");
	backBanner->SetSize(185, 68);
	backBanner->SetPosition((width / 2) - 92, 500);
	draw->AddItem(backBanner);

	//**************** Back Selector *********************
	LobbySelector* backSelector = new LobbySelector(_renderer, _inputSystem, gameEngine->GetSceneManager());
	backSelector->LoadImage("Button.png");
	backSelector->SetSize(350, 160);
	backSelector->AddItem(backBanner);
	backSelector->Initialize();
	draw->AddItem(backSelector);
	//****************************************************
	//gameEngine->GetSceneManager()->SetActive(draw);
}

Game::Game(const char* _title, int _width/*=WIDTH*/, int _height/*=HEIGHT*/)
{
	width = _width;
	height = _height;
	gameEngine = new GameEngine(_title, _width, _height);
}

void Game::Start()
{
	SDL_Renderer* renderer = gameEngine->GetScreen();
	InputSystem* inputSystem = gameEngine->GetInputSystem();
	
	Lobby(renderer, inputSystem);
	Rules(renderer, inputSystem);
	HowToPlay(renderer, inputSystem);
	Play(renderer, inputSystem);
	RedWin(renderer, inputSystem);
	BlueWin(renderer, inputSystem);
	Draw(renderer, inputSystem);
}

void Game::Run()
{
	gameEngine->Run();
}

Game::~Game()
{
	delete gameEngine;
	gameEngine = nullptr;
}
