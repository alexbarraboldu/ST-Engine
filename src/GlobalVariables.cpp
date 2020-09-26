#include <SDL.h>

#include "GlobalVariables.h"
#include "Macros.h"

GlobalVariables* GlobalVariables::instance = NULL;

GlobalVariables::GlobalVariables()
{
	if (instance != NULL) return;

	quiteEngineLoop = true;
	frameRate = FPS_UNLIMITED;
	windowWidth = W_WIDTH_600;
	windowHeight = W_HEIGHT_600;
}

GlobalVariables::~GlobalVariables() {}


//	Setters

void GlobalVariables::setQuiteEngineLoop(bool b, unsigned int flags)
{
	if (flags & GlobalVar::QUITE_ENGINE_LOOP)
	{
		if (quiteEngineLoop != 0)
			quiteEngineLoop = b;
	}
}

void GlobalVariables::setFrametRate(int d, unsigned int flags)
{
	if (flags & GlobalVar::FRAME_RATE)
	{
		frameRate = d;
	}
}

void GlobalVariables::setWindowWidth(unsigned int w, unsigned int flags)
{
	if (flags & GlobalVar::WIDTH_HEIGHT)
	{
		windowWidth = w;
	}
}

void GlobalVariables::setWindowHeight(unsigned int h, unsigned int flags)
{
	if (flags & GlobalVar::WIDTH_HEIGHT)
	{
		windowHeight = h;
	}
}

void GlobalVariables::setWindowWH(unsigned int w, unsigned int h, unsigned int flags)
{
	if (flags & GlobalVar::WIDTH_HEIGHT)
	{
		windowWidth = w;
		windowHeight = h;
	}
}


//	Getters

GlobalVariables* GlobalVariables::getInstance()
{
	if (!instance)
	{
		instance = new GlobalVariables();
	}
	return instance;
}
