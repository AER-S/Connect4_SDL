#include "Game.h"
#include "Item.h"
#include "Scene.h"


Game::Game(const char* _title, int _width/*=WIDTH*/, int _height/*=HEIGHT*/)
{
	gameEngine = new GameEngine(_title, _width, _height);
}

void Game::Start()
{
	SDL_Renderer* renderer = gameEngine->GetScreen();
	InputSystem* inputSystem = gameEngine->GetInputSystem();
	//Item* bobi = new Item(renderer,inputSystem);
	//gameEngine->GetSceneManager()->GetScene(0)->AddItem(bobi);
	Item* nounou = new Item(renderer, inputSystem);
	nounou->LoadImage("Blue_ball.png");
	nounou->SetPosition(100, 200);
	gameEngine->GetSceneManager()->GetScene(0)->AddItem(nounou);
	Scene* secondScnene = new Scene();
	Item* sousoou = new Item(renderer,inputSystem);
	sousoou->SetPosition(300, 300);
	secondScnene->AddItem(sousoou);
	gameEngine->GetSceneManager()->AddScene(secondScnene);
	
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
