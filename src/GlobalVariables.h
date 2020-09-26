#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H

#include "Structures.h"


class GlobalVariables {
public:

	GlobalVariables();
	~GlobalVariables();

	//	Setters
	void setQuiteEngineLoop(bool b, unsigned int flags);
	void setFrametRate(int d, unsigned int flags);
	void setWindowWidth(unsigned int w, unsigned int flags);
	void setWindowHeight(unsigned int h, unsigned int flags);
	void setWindowWH(unsigned int w, unsigned int h, unsigned int flags);

	//	Getters
	static GlobalVariables* getInstance();

	bool getQuiteEngineLoop(unsigned int flags);
	int getFrameRate(unsigned int flags);
	int getWindowWidth(unsigned int flags);
	int getWindowHeight(unsigned int flags);

private:

	static GlobalVariables* instance;

	//	GLOBAL VARIABLES
	bool quiteEngineLoop;
	int frameRate;
	int windowWidth, windowHeight;
};

//-----------------------------
//	SOLO DEFINICIONES DE GETTERS

inline bool GlobalVariables::getQuiteEngineLoop(unsigned int flags) try
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

inline int GlobalVariables::getFrameRate(unsigned int flags) try
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

inline int GlobalVariables::getWindowWidth(unsigned int flags) try
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

inline int GlobalVariables::getWindowHeight(unsigned int flags) try
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

#endif // !GLOBAL_VARIABLES_H
