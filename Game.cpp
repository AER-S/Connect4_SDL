#include "Game.h"
#include "TitleBanner.h"
#include "Selector.h"
#include "Scene.h"
#include "Text.h"

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
	howToPlay->SetPosition((width / 2) - 204, (height / 2) - 24);
	lobby->AddItem(howToPlay);
	//gameEngine->GetSceneManager()->GetScene(0)->AddItem(HowToPlay);

	//************** Rules Banner ******************
	Item* play = new TitleBanner(renderer);
	play->LoadImage("Play_orange.png");
	play->SetSize(178, 68);
	play->SetPosition((width / 2) - 89, (height / 2) + 50);
	lobby->AddItem(play);
	//gameEngine->GetSceneManager()->GetScene(0)->AddItem(play);

	//************** Selector **************************
	Selector* selector = new Selector(renderer, inputSystem, gameEngine->GetSceneManager());
	selector->LoadImage("Button.png");
	selector->SetSize(620, 160);
	selector->AddItem(rules);
	selector->AddItem(howToPlay);
	selector->AddItem(play);
	selector->Initialize();
	lobby->AddItem(selector);
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
	//**************** Rules line 1 *********************
	Text* rule1 = new Text("1. Two Player (RED & BLUE) game.", 25, renderer, {0,128,255});
	rule1->SetPosition(80, 250);
	HTP->AddItem(rule1);

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
