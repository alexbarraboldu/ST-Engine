#ifndef SCENE_DIRECTOR_H
#define SCENE_DIRECTOR_H

#include <stack>
#include <vector>

#include "SceneMenu.h"
#include "SceneGame.h"

class SceneDirector : Id {
public:
	enum SceneEnum {
		PRE_LOAD, MAIN_MENU, GAME, LAST_NO_USE
	};

	SceneDirector();
	~SceneDirector();

	//	Getters
	static SceneDirector* getInstance();

	std::stack<Scene*> getSceneHistory() { return mSceneHistory; }


	//	Functions
	void changeScene(SceneEnum next_scene, bool load_on_return = true, bool history = true);

	void goBack(bool load_on_return = true, bool preload = false);

	Scene* mCurrentScene;

private:
	void initScenes();

	static SceneDirector* instance;
	std::vector<Scene*> mScenes;
	std::stack<Scene*> mSceneHistory;

};

#endif // !SCENE_DIRECTOR_H
