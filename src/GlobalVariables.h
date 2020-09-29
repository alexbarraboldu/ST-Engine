#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H

#include "Structures.h"


class GlobalVariables {
public:

	GlobalVariables();
	~GlobalVariables();

	//	Setters
	void setQuiteEngineLoop(bool b, unsigned short flags);
	void setVSync(bool b, unsigned short flags);
	void setFrametRate(int f, unsigned short flags);
	void setWindowWidth(unsigned int w, unsigned short flags);
	void setWindowHeight(unsigned int h, unsigned short flags);
	void setWindowWH(unsigned int w, unsigned int h, unsigned short flags);

	//	Getters
	static GlobalVariables* getInstance();

	bool getQuiteEngineLoop(unsigned short flags);
	bool getVSync(unsigned short flags);
	int getFrameRate(unsigned short flags);
	int getWindowWidth(unsigned short flags);
	int getWindowHeight(unsigned short flags);

private:

	static GlobalVariables* instance;

	//	GLOBAL VARIABLES
	//	Integers
	int frameRate;
	int windowWidth, windowHeight;

	//	Booleans
	bool quiteEngineLoop;
	bool VSync;
};

//-----------------------------
//	SOLO DEFINICIONES DE GETTERS

inline bool GlobalVariables::getQuiteEngineLoop(unsigned short flags) try
{
	if (flags & GlobalVar::QUITE_ENGINE_LOOP)
	{
		return quiteEngineLoop;
	}
	throw nullptr;

}
catch (bool t)
{
	return t;
}

inline int GlobalVariables::getFrameRate(unsigned short flags) try
{
	if (flags & GlobalVar::FRAME_RATE)
	{
		return frameRate;
	}
	throw nullptr;
}
catch (int t)
{
	return t;
}

inline int GlobalVariables::getWindowWidth(unsigned short flags) try
{
	if (flags & GlobalVar::WIDTH_HEIGHT)
	{
		return windowWidth;
	}
	throw nullptr;
}
catch (int t)
{
	return t;
}

inline int GlobalVariables::getWindowHeight(unsigned short flags) try
{
	if (flags & GlobalVar::WIDTH_HEIGHT)
	{
		return windowHeight;
	}
	throw nullptr;
}
catch (int t)
{
	return t;
}

inline bool GlobalVariables::getVSync(unsigned short flags) try
{
	if (flags & GlobalVar::VSYNC)
	{
		return VSync;
	}
}
catch (bool t)
{
	return t;
}


#endif // !GLOBAL_VARIABLES_H
