#include "Game.h"
#include "Item.h"
#include "Scene.h"


Game::Game(const char* _title, int _width/*=WIDTH*/, int _height/*=HEIGHT*/)
{
	gameEngine = new GameEngine(_title, _width, _height);
}

void Game::Start()
{
	Item* bobi = new Item();
	gameEngine->GetSceneManager()->GetScene(0)->AddItem(bobi);
	Item* nounou = new Item();
	nounou->LoadImage("Blue_ball.png",gameEngine->GetScreen());
	nounou->SetPosition(100, 200);
	gameEngine->GetSceneManager()->GetScene(0)->AddItem(nounou);
	Scene* secondScnene = new Scene();
	Item* sousoou = new Item;
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
