#ifndef ENGINE_H
#define ENGINE_H

#include <chrono>
#include <thread>

#include "Singletons.h"

//#include <SDL.h>
//#include "Id.h"

class Engine : Id {
public:
	Engine();
	~Engine();

	//void initSingletons();
	void engineLoop();
	void destroy();

	double clockToSeconds(clock_t ticks);
	double clockToMilliseconds(clock_t ticks);
	double clockToNanoseconds(clock_t ticks);
	void doStuff();

private:
	//double frameRate;
	clock_t timer;
	clock_t time;
	clock_t deltaTime;

	unsigned int totalFrames;
	unsigned int FPS;

	int Timer;
	int externalTimer;

	unsigned int timesUnderDeltaTime;

	bool quitEngineLoop;
};

#endif // !ENGINE_H
