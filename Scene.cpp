#include "Scene.h"

#define LOOP_THROUGH_ITEMS for(auto i = items.begin(); i!=items.end(); i++)

void Scene::AddItem(Item* _item)
{
	if (_item)
	{
		items.push_back(_item);
	}
}

void Scene::Draw()
{
	if (!items.empty())
	{
		LOOP_THROUGH_ITEMS
		{
			(*i)->Draw();
		}
	}
}

void Scene::Update()
{
	if (!items.empty())
	{
		LOOP_THROUGH_ITEMS
		{
			(*i)->Update();
		}
	}
}

Scene::~Scene()
{
	if (!items.empty())
	{
		LOOP_THROUGH_ITEMS
		{
			delete * i;
		}
	}
}
