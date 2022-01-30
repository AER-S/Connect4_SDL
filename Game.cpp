#include "Game.h"
#include "TitleBanner.h"
#include "Button.h"
#include "Scene.h"


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
	
	//*********************************************
	//************* First Scene *******************
	//*********************************************
	Scene* lobby = new Scene();
	gameEngine->GetSceneManager()->AddScene(lobby);
	//************** Title Banner ******************
	Item* titleBanner = new TitleBanner(renderer);
	titleBanner->LoadImage("Connet_4.png");
	titleBanner->SetSize(688, 115);
	titleBanner->SetPosition(60, 60);
	lobby->AddItem(titleBanner);
	//gameEngine->GetSceneManager()->GetScene(0)->AddItem(titleBanner);

	//************** Rules Banner ******************
	Item* rules = new TitleBanner(renderer);
	rules->LoadImage("Rules_orange.png");
	rules->SetSize(218, 68);
	rules->SetPosition((width / 2)-109, (height / 2)-94);
	lobby->AddItem(rules);
	//gameEngine->GetSceneManager()->GetScene(0)->AddItem(rules);

	//************** How To Play Banner ******************
	Item* howToPlay = new TitleBanner(renderer);
	howToPlay->LoadImage("Htp_orange.png");
	howToPlay->SetSize(408, 68);
	howToPlay->SetPosition((width / 2) - 204, (height / 2) - 34);
	lobby->AddItem(howToPlay);
	//gameEngine->GetSceneManager()->GetScene(0)->AddItem(HowToPlay);

	//************** Rules Banner ******************
	Item* play = new TitleBanner(renderer);
	play->LoadImage("Play_orange.png");
	play->SetSize(178, 68);
	play->SetPosition((width / 2) - 89, (height / 2) + 30);
	lobby->AddItem(play);
	//gameEngine->GetSceneManager()->GetScene(0)->AddItem(play);

	//************** Selection Button ***************
	Item* selector = new Button(renderer, inputSystem, gameEngine->GetSceneManager());
	selector->LoadImage("Button.png");
	selector->SetSize(620, 160);
	selector->SetPosition((width / 2) - 310, (height / 2) - 75);
	lobby->AddItem(selector);
	//gameEngine->GetSceneManager()->SetActive(0);
	//**************************************************
	gameEngine->GetSceneManager()->SetActive(lobby);
	//***************************************************
	
	//***************************************************
	//***************** Second Scene ********************
	//***************************************************
	Scene* HTP = new Scene();
	gameEngine->GetSceneManager()->AddScene(HTP);
	//**************** Title Banner *********************
	Item* titleBanner2 = new TitleBanner(renderer);
	titleBanner2->LoadImage("Connet_4.png");
	titleBanner2->SetSize(688, 115);
	titleBanner2->SetPosition(60, 60);
	HTP->AddItem(titleBanner2);
	//****************************************************
	
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
