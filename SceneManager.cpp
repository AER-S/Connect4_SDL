#include "SceneManager.h"

SceneManager::SceneManager()
{
	Scene* newScene = new Scene();
	scesnes.push_back(newScene);
}

void SceneManager::SetActive(int _index)
{
	if ((unsigned)_index <scesnes.size())
	{
		activeScene = scesnes[_index];
	}
}

void SceneManager::AddScene(Scene* _newScene)
{
	scesnes.push_back(_newScene);
}

Scene* SceneManager::GetActive()
{
	return activeScene;
}

Scene* SceneManager::GetScene(int _index)
{
	if ((unsigned)_index < scesnes.size())
	{
		return scesnes[_index];
	}
	else return nullptr;
}


