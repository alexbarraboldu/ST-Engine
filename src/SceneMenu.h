#ifndef SCENE_MENU
#define SCENE_MENU

#include "Scene.h"

class SceneMenu : public Scene {
public:
	SceneMenu();
	~SceneMenu();

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

	void updateStartMenu();
	void renderStartMenu();
};

#endif // !SCENE_MENU
