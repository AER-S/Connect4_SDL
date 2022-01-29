#pragma once
#include "Scene.h"
#include <vector>

class SceneManager
{
	Scene* activeScene;
	std::vector<Scene*> scesnes;
public:
	SceneManager();
	void SetActive(int _index);
	void AddScene(Scene* _newScene);
	Scene* GetActive();
	Scene* GetScene(int _index);
};

