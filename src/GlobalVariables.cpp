#include <SDL.h>

#include "GlobalVariables.h"
#include "Macros.h"

GlobalVariables* GlobalVariables::instance = NULL;

GlobalVariables::GlobalVariables()
{
	if (instance != NULL) return;

	frameRate = FPS_60;
	windowWidth = W_WIDTH_600;
	windowHeight = W_HEIGHT_600;

	quiteEngineLoop = true;
	VSync = false;
}

GlobalVariables::~GlobalVariables() {}


//	Setters

void GlobalVariables::setQuiteEngineLoop(bool b, unsigned short flags)
{
	if (flags & GlobalVar::QUITE_ENGINE_LOOP)
	{
		if (quiteEngineLoop != 0)
			quiteEngineLoop = b;
	}
}

void GlobalVariables::setFrametRate(int d, unsigned short flags)
{
	if (flags & GlobalVar::FRAME_RATE)
	{
		frameRate = d;
	}
}

void GlobalVariables::setWindowWidth(unsigned int w, unsigned short flags)
{
	if (flags & GlobalVar::WIDTH_HEIGHT)
	{
		windowWidth = w;
	}
}

void GlobalVariables::setWindowHeight(unsigned int h, unsigned short flags)
{
	if (flags & GlobalVar::WIDTH_HEIGHT)
	{
		windowHeight = h;
	}
}

void GlobalVariables::setWindowWH(unsigned int w, unsigned int h, unsigned short flags)
{
	if (flags & GlobalVar::WIDTH_HEIGHT)
	{
		windowWidth = w;
		windowHeight = h;
	}
}

void GlobalVariables::setVSync(bool b, unsigned short flags)
{
	if (flags & GlobalVar::VSYNC)
	{
		VSync = b;
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
