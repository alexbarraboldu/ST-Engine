#ifndef ENGINE_H
#define ENGINE_H

#include <chrono>
#include <thread>

#include "Singletons.h"

class Engine : Id {
public:
	Engine();
	Engine(int argc, char* arg[]);
	~Engine();

	void engineLoop();
	void gameLoop(bool useIt = true);
	void editorLoop(bool useIt = true);

	void destroy();

	double clockToSeconds(clock_t ticks);
	double clockToMilliseconds(clock_t ticks);
	double clockToNanoseconds(clock_t ticks);
	void doStuff(bool a = false);

private:
	std::string argvToString();

	double deltaTime;

	//unsigned int totalFrames;
	unsigned int FPS;
	unsigned int timesUnderDeltaTime;

	bool quitEngineLoop;

	int argc;
	char** argv;
	std::string argString;
};

#endif // !ENGINE_H
