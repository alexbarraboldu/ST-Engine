#include "Engine.h"

Engine::Engine() : Id()
{
	initializeSingletons();

	id = GlobalVar::FRAME_RATE | GlobalVar::QUITE_ENGINE_LOOP;

	timer = 0;
	time = 0;
	deltaTime = 1000 / sGlobalVariables->getFrameRate(id);
	totalFrames = 0;
	FPS = 1000 / sGlobalVariables->getFrameRate(id);

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
	while (sGlobalVariables->getQuiteEngineLoop(id) == true)
	{
		std::chrono::high_resolution_clock::time_point beginFrame = std::chrono::high_resolution_clock::now();

		system("cls");

		if (beginFrame.time_since_epoch().count() / 1000000000 >= Timer)
		{
			if (Timer == 0) 
			{
				Timer = beginFrame.time_since_epoch().count() / 1000000000;
			}
			else 
			{
				Timer = beginFrame.time_since_epoch().count() / 1000000000 + 1; 
				externalTimer++;
				timer = externalTimer;
			}
		}

		//----------------------------------------------
		//

		sInput->updateEvents();

		sSceneDirector->mCurrentScene->onLoad();

		sSceneDirector->mCurrentScene->onUpdate(clockToMilliseconds(deltaTime));

		sSceneDirector->mCurrentScene->onRender();

		//	
		//----------------------------------------------

		printf("\nDelta Time (ms): %d", deltaTime);
		printf("\nDelta Time (s): %.3f", deltaTime / 1000.0f);

		printf("\n\nTotal Time (s): %d", externalTimer);
		printf("\nTotal time (min): %d", int(externalTimer / 60.0f));

		printf("\n\nFPS: %d", FPS);
		printf("\nTotal FPS: %d", totalFrames);
		printf("\nTimes deltaTime went under frameRate: %d", timesUnderDeltaTime);

		totalFrames++;

		if (timer >= 1)	//	PARA SABER CUANTOS Frames POR SEGUNDO
		{
			timer = 0;
			FPS = totalFrames;
			totalFrames = 0;
		}

		std::chrono::high_resolution_clock::time_point endFrame = std::chrono::high_resolution_clock::now();
		deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(endFrame - beginFrame).count();

		if (deltaTime < int(1000.0f / sGlobalVariables->getFrameRate(id)) && sGlobalVariables->getFrameRate(id) != -1)
		{
			timesUnderDeltaTime++;
			/*
			// 1000/frameRate -> te da el DeltaTime al que debería ir la simulación
			// por eso más abajo esperamos la diferencia entre ellos, pk es el tiempo
			// que necesitamos para llegar a los 60fps (16,66ms)
			*/
			std::this_thread::sleep_for(std::chrono::milliseconds((long)(1000.0f / sGlobalVariables->getFrameRate(id) - deltaTime)));

			// Cambias el deltaTime para ajustarse a la velocidad de simulación deseada
			deltaTime = deltaTime + (1000.0f / sGlobalVariables->getFrameRate(id) - deltaTime);

			//---	SI QUIERES CAMBIOS DE FPS POR CUADRO
			//FPS = 1000 / (deltaTime + (1000.0f / frameRate - deltaTime)) ; //	==	"FPS = frameRate;"
			//---
		}
	}
}

double Engine::clockToMilliseconds(clock_t ticks) {
	// units/(units/time) => time (seconds) * 1000 = milliseconds
	return (ticks / (double)CLOCKS_PER_SEC) * 1000.0;
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
	//	AQUI LLAMO A TODO QUISQUI PARA DESTRUIR;
}