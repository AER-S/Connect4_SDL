#include "GameEngine.h"
#include <SDL_image.h>
#include "Item.h"


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
				//inputSystem.fire.Trig();
				break;
			case SDLK_0:
				inputSystem.Trig(&(inputSystem.numbers[0]));
				break;
			case SDLK_1:
				inputSystem.Trig(&(inputSystem.numbers[1]));
				break;
			case SDLK_2:
				inputSystem.Trig(&(inputSystem.numbers[2]));
				break;
			case SDLK_3:
				inputSystem.Trig(&(inputSystem.numbers[3]));
				break;
			case SDLK_4:
				inputSystem.Trig(&(inputSystem.numbers[4]));
				break;
			case SDLK_5:
				inputSystem.Trig(&(inputSystem.numbers[5]));
				break;
			case SDLK_6:
				inputSystem.Trig(&(inputSystem.numbers[6]));
				break;
			case SDLK_7:
				inputSystem.Trig(&(inputSystem.numbers[7]));
				break;
			case SDLK_8:
				inputSystem.Trig(&(inputSystem.numbers[8]));
				break;
			case SDLK_9:
				inputSystem.Trig(&(inputSystem.numbers[9]));
				break;
			default:
				break;
			}
		default:
			break;
		}
	}
}

void GameEngine::DrawActiveScene()
{
	sceneManger.GetActive()->Draw(screen);
}

GameEngine::GameEngine(const char* _title, int _width, int _height)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	window = SDL_CreateWindow(_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_RESIZABLE);
	screen = SDL_GetWindowSurface(window);
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
		DrawActiveScene();
		SDL_UpdateWindowSurface(window);
	}
}

SDL_Surface* GameEngine::GetScreen()
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
}

void GameEngine::Update()
{
	sceneManger.GetActive()->Update();
}
