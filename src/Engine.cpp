#include "string"

#include "Engine.h"

Engine::Engine() : Id()
{
	initializeSingletons();

	id = GlobalVar::FRAME_RATE | GlobalVar::QUITE_ENGINE_LOOP;

	deltaTime = 0; /* (clock_t)(1000000000.0f / sGlobalVariables->getFrameRate(id))*/;

	totalFrames = 0;

	FPS = 0;

	timesUnderDeltaTime = 0;

	quitEngineLoop = true;

}

Engine::~Engine() {}

void Engine::engineLoop()
{
	//unsigned long Dsum = 0;
	unsigned int T = 0;

	std::chrono::high_resolution_clock::time_point lastTime = std::chrono::high_resolution_clock::now();

	while (sGlobalVariables->getQuiteEngineLoop(id) == true)
	{
		std::chrono::high_resolution_clock::time_point beginFrame = std::chrono::high_resolution_clock::now();

		////----------------------------------------------
		////

		sInput->updateEvents();

		sSceneDirector->mCurrentScene->onLoad();

		sSceneDirector->mCurrentScene->onUpdate(clockToNanoseconds(deltaTime));

		sSceneDirector->mCurrentScene->onRender();

		////
		////----------------------------------------------

		//printf("\nDelta Time (ms): %d", deltaTime);
		//printf("\nDelta Time (s): %.3f", deltaTime / 1000.0f);

		//printf("\n\nFPS: %d", FPS);
		//printf("\nTotal FPS: %d", totalFrames);
		//printf("\nTimes deltaTime went under frameRate: %d", timesUnderDeltaTime);

		//Dsum += deltaTime;

		if (std::chrono::high_resolution_clock::now() <= 1000000000)	//	PARA SABER CUANTOS Frames POR SEGUNDO
		{
			T++;
			Dsum = 0;
			FPS = totalFrames;
			totalFrames = 0;

			std::string title = "FPS: " + std::to_string(FPS);
			title += " | DeltaTime (s): " + std::to_string(deltaTime / 1000000000.0f);
			title += " | DeltaTime (ms): " + std::to_string(deltaTime / 1000000.0f);
			title += " | DeltaTime (µs): " + std::to_string(deltaTime / 1000.0f);
			title += " | DeltaTime (ns): " + std::to_string(deltaTime);
			title += " | Time: " + std::to_string(T);

			SDL_SetWindowTitle(sRenderer->getWindow(), title.c_str());
		}

		totalFrames++;

		//std::chrono::high_resolution_clock::time_point endFrame = std::chrono::high_resolution_clock::now();
		deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - beginFrame).count();


		if (deltaTime < 1000000000 / sGlobalVariables->getFrameRate(id) && sGlobalVariables->getFrameRate(id) != -1)
		{
			timesUnderDeltaTime++;

			std::this_thread::sleep_for(std::chrono::nanoseconds((1000000000 / sGlobalVariables->getFrameRate(id) - deltaTime)));

			// Cambias el deltaTime para ajustarse a la velocidad de simulación deseada
			//deltaTime += (clock_t)(1000000000 / sGlobalVariables->getFrameRate(id) - deltaTime);
		}


	}
}

double Engine::clockToSeconds(clock_t ticks) {
	// units/(units/time) => time (seconds) = seconds
	return (ticks / (double)CLOCKS_PER_SEC);
}

double Engine::clockToMilliseconds(clock_t ticks) {
	// units/(units/time) => time (seconds) * 1000 = milliseconds
	return (ticks / (double)CLOCKS_PER_SEC) * 1000.0f;
}

double Engine::clockToNanoseconds(clock_t ticks) {
	// units/(units/time) => time (seconds) * 1000000 = nanoseconds
	return (ticks / (double)CLOCKS_PER_SEC) * 1000000.0f;
}

void Engine::doStuff(bool a)
{
	for (size_t i = 0; i < 100000; i++)
	{
		int lmao = i;
		if (a) {
			int* lol = new int;
			*lol = lmao;
			lmao++;

			delete lol;
		}
		else {
			int* lol = &lmao;
			lmao++;
		}

	}
}

void Engine::destroy()
{
	SDL_DestroyWindow(sRenderer->getWindow());

	SDL_DestroyRenderer(sRenderer->getRenderer());

	
	deleteSingletons();
}