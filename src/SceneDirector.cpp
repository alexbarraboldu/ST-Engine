#include "Singletons.h"

SceneDirector* SceneDirector::instance = NULL;

SceneDirector::SceneDirector() : Id()
{
	if (instance != NULL) return;

	id = GlobalVar::NO_PERMISSION;

	initScenes();
}

SceneDirector::~SceneDirector() {}

SceneDirector* SceneDirector::getInstance()
{
	if (!instance)
	{
		instance = new SceneDirector();
	}
	return instance;
}

void SceneDirector::changeScene(SceneEnum next_scene, bool load_on_return, bool history)
{
	mCurrentScene->setLoaded(!load_on_return);
	if (history)
	{
		mSceneHistory.push(mCurrentScene);
	}

	mCurrentScene = mScenes[next_scene];
}

void SceneDirector::goBack(bool load_on_return, bool preload)
{
	if (mSceneHistory.empty()) return;

	Scene* prevScene = mSceneHistory.top();
	
	if (prevScene != NULL)
	{
		mSceneHistory.pop();
		mCurrentScene->setLoaded(!load_on_return);
		mCurrentScene = prevScene;
	}

	if (preload) mCurrentScene->setPreload(preload);
}

void SceneDirector::initScenes()
{
	mScenes.reserve(SceneEnum::LAST_NO_USE);

	Scene* scene_preLoad = new Scene();
	SceneMenu* scene_menu = new SceneMenu();
	SceneGame* scene_game = new SceneGame();

	mScenes.push_back(scene_preLoad);
	mScenes.push_back(scene_menu);
	mScenes.push_back(scene_game);

	mScenes.shrink_to_fit();

	for (size_t i = 0; i < mScenes.size(); i++)
	{
		mScenes[i]->preLoad();
 	}

	mCurrentScene = mScenes[SceneEnum::PRE_LOAD];
}