#include "Game.h"
#include "TitleBanner.h"
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
	
	//************** Title Banner ******************
	Item* titleBanner = new TitleBanner(renderer);
	titleBanner->LoadImage("Connet_4.png");
	titleBanner->SetSize(688, 115);
	titleBanner->SetPosition(60, 60);
	gameEngine->GetSceneManager()->GetScene(0)->AddItem(titleBanner);

	//************** Rules Banner ******************
	Item* rules = new TitleBanner(renderer);
	rules->LoadImage("Rules_orange.png");
	rules->SetSize(218, 68);
	rules->SetPosition((width / 2)-109, (height / 2)-94);
	gameEngine->GetSceneManager()->GetScene(0)->AddItem(rules);

	//************** How To Play Banner ******************
	Item* HowToPlay = new TitleBanner(renderer);
	HowToPlay->LoadImage("Htp_orange.png");
	HowToPlay->SetSize(408, 68);
	HowToPlay->SetPosition((width / 2) - 204, (height / 2) - 34);
	gameEngine->GetSceneManager()->GetScene(0)->AddItem(HowToPlay);

	//************** Rules Banner ******************
	Item* play = new TitleBanner(renderer);
	play->LoadImage("Play_orange.png");
	play->SetSize(178, 68);
	play->SetPosition((width / 2) - 89, (height / 2) + 30);
	gameEngine->GetSceneManager()->GetScene(0)->AddItem(play);
	//gameEngine->GetSceneManager()->SetActive(0);
	
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
