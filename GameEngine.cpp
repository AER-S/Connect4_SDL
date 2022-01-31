#include "GameEngine.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Item.h"

//debug
#include <iostream>


void GameEngine::HandleEvents(SDL_Event* _events)
{
	while (SDL_PollEvent(_events))
	{
		switch (_events->type)
		{
		case SDL_QUIT:
			run = false;
			break;
		case  SDL_KEYDOWN:
			switch (_events->key.keysym.sym)
			{
			case SDLK_RETURN:
				inputSystem.Trig(&(inputSystem.fire));
				break;
			case SDLK_UP:
				inputSystem.Trig(&(inputSystem.upKey));
				break;
			case SDLK_DOWN:
				inputSystem.Trig(&(inputSystem.downKey));
				break;
			case SDLK_RIGHT:
				inputSystem.Trig(&(inputSystem.rightKey));
				break;
			case SDLK_LEFT:
				inputSystem.Trig(&(inputSystem.leftKey));
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			inputSystem.SetDown(false);
			break;
		default:
			break;
		}
	}
}

void GameEngine::DrawActiveScene()
{
	sceneManger.GetActive()->Draw();
}

GameEngine::GameEngine(const char* _title, int _width, int _height)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	window = SDL_CreateWindow(_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_SHOWN);
	screen = SDL_CreateRenderer(window, -1, 0);
	//SDL_SetRenderDrawColor(screen, 0, 100, 128, 255);
	//SDL_RenderFillRect(screen, NULL);
	sceneManger.SetActive(0);
	run = true;
}

void GameEngine::Run()
{
	SDL_Event ev;
	while (run)
	{
		HandleEvents(&ev);
		Update();
		SDL_RenderClear(screen);
		DrawActiveScene();
		SDL_RenderPresent(screen);
		SDL_Delay(100 / 6);
	}
}

SDL_Renderer* GameEngine::GetScreen()
{
	return screen;
}

SceneManager* GameEngine::GetSceneManager()
{
	return &sceneManger;
}

InputSystem* GameEngine::GetInputSystem()
{
	return &inputSystem;
}

GameEngine::~GameEngine()
{
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_Quit();
	IMG_Quit();
	TTF_Quit();
}

void GameEngine::Update()
{
	sceneManger.GetActive()->Update();
}
