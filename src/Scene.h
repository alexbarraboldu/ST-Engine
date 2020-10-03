#ifndef SCENE_H
#define SCENE_H

#include "Id.h"
#include "System.h"

class Scene : public Id
{
public:
	Scene();
	~Scene();

	virtual void preLoad();
	void onLoad();
	void onUpdate(double deltaTime);
	void onRender();

	void setLoaded(bool loaded) { mSceneLoaded = loaded; }
	void setPreload(bool preload) { mPreloadScene = preload; }

protected:
	bool mPutInStack;
	bool mSceneLoaded;
	bool mPreloadScene;

	virtual void init();

	virtual void updateBegin(double deltaTime);
	virtual void update(double deltaTime);
	virtual void updateEnd(double deltaTime);

	virtual void renderBegin();
	virtual void render();
	virtual void renderEnd();

	virtual void renderGUI();

private:
	System* system;
};

#endif // !SCENE_H
