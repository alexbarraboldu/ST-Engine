#ifndef SCENE_GAME
#define SCENE_GAME

#include "Scene.h"

class SceneGame : public Scene {
public:
	SceneGame();
	~SceneGame();

	virtual void preLoad();

protected:
	virtual void init();

	virtual void updateBegin();
	virtual void update();
	virtual void updateEnd();

	virtual void renderBegin();
	virtual void render();
	virtual void renderEnd();

	virtual void renderGUI();

private:
	int soundID;
	char mPhase;

	void updateStartGame();
	void renderStartGame();
};


#endif // !SCENE_GAME
