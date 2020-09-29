#ifndef ENGINE_H
#define ENGINE_H

#include <chrono>
#include <thread>

#include "Singletons.h"

class Engine : Id {
public:
	Engine();
	~Engine();

	void engineLoop();
	void destroy();

	double clockToSeconds(clock_t ticks);
	double clockToMilliseconds(clock_t ticks);
	double clockToNanoseconds(clock_t ticks);
	void doStuff(bool a = false);

private:
	clock_t deltaTime;

	unsigned int totalFrames;
	unsigned int FPS;
	unsigned int timesUnderDeltaTime;

	bool quitEngineLoop;
};

#endif // !ENGINE_H
