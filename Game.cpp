#include "Game.h"
#include "TitleBanner.h"
#include "LobbySelector.h"
#include "Scene.h"
#include "Text.h"

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
	titleBanner->SetPosition(60, 60);
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
	titleBanner2->SetPosition(60, 60);
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
