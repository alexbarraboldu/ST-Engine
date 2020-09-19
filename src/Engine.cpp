#include "Engine.h"
#include "string"

Engine::Engine() : Id()
{
	initializeSingletons();

	id = GlobalVar::FRAME_RATE | GlobalVar::QUITE_ENGINE_LOOP;

	timer = 0;
	time = 0;
	deltaTime = 1000000000.0f / sGlobalVariables->getFrameRate(id);
	totalFrames = 0;
	FPS = 1000000000.0f / sGlobalVariables->getFrameRate(id);

	Timer = 0;
	externalTimer = -1;

	timesUnderDeltaTime = 0;

	quitEngineLoop = true;

}

Engine::~Engine()
{
}

void Engine::engineLoop()
{
	double Dsum = 0.0f;

	while (sGlobalVariables->getQuiteEngineLoop(id) == true)
	{
		std::chrono::high_resolution_clock::time_point beginFrame = std::chrono::high_resolution_clock::now();

		Dsum += deltaTime;
		totalFrames++;

		if (beginFrame.time_since_epoch().count() / 1000000000.0f >= Timer)
		{
			if (Timer == 0)
			{
				Timer = beginFrame.time_since_epoch().count() / 1000000000.0f;
			}
			else
			{
				Timer = beginFrame.time_since_epoch().count() / 1000000000.0f + 1;
				externalTimer++;
				timer = externalTimer;
			}
		}


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

		//printf("\n\nTotal Time (s): %d", externalTimer);
		//printf("\nTotal time (min): %d", int(externalTimer / 60.0f));

		//printf("\n\nFPS: %d", FPS);
		//printf("\nTotal FPS: %d", totalFrames);
		//printf("\nTimes deltaTime went under frameRate: %d", timesUnderDeltaTime);


		if (/*timer >= 1*/ Dsum >= 1000000000.0f)	//	PARA SABER CUANTOS Frames POR SEGUNDO
		{
			timer = 0;
			Dsum = 0;
			FPS = totalFrames;
			totalFrames = 0;

			std::string title = "FPS: " + std::to_string(FPS);
			title += " | DeltaTime (ms): " + std::to_string(deltaTime / 1000000.0f);
			title += " | Dsum (ns): " + std::to_string(Dsum);

			SDL_SetWindowTitle(sRenderer->getWindow(), title.c_str());
		}

		std::chrono::high_resolution_clock::time_point endFrame = std::chrono::high_resolution_clock::now();
		deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endFrame - beginFrame).count();

		if (deltaTime < int(1000000000.0f / sGlobalVariables->getFrameRate(id)) && sGlobalVariables->getFrameRate(id) != -1)
		{
			timesUnderDeltaTime++;

			std::this_thread::sleep_for(std::chrono::nanoseconds((long)(1000000000.0f / sGlobalVariables->getFrameRate(id) - (deltaTime / 1000000000.0f))));

			// Cambias el deltaTime para ajustarse a la velocidad de simulación deseada
			deltaTime += 1000000000.0f / sGlobalVariables->getFrameRate(id) - (deltaTime / 1000000000.0f);
		}
	}
}

double Engine::clockToMilliseconds(clock_t ticks) {
	// units/(units/time) => time (seconds) * 1000 = milliseconds
	return (ticks / (double)CLOCKS_PER_SEC) * 1000.0f;
}

double Engine::clockToNanoseconds(clock_t ticks) {
	// units/(units/time) => time (seconds) * 1000000 = nanoseconds
	return (ticks / (double)CLOCKS_PER_SEC) * 1000000.0f;
}

void Engine::doStuff()
{
	for (size_t i = 0; i < 100000; i++)
	{
		int lmao;
		int* lol = &lmao;
		lmao = 10;

		lol = NULL;
		delete lol;
	}
}

void Engine::destroy()
{
	SDL_DestroyWindow(sRenderer->getWindow());

	SDL_DestroyRenderer(sRenderer->getRenderer());
}