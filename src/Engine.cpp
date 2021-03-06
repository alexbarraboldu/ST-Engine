#include "string"

#include "Engine.h"

Engine::Engine() : Id()
{
	initializeSingletons();

	id = GlobalVar::FRAME_RATE | GlobalVar::QUITE_ENGINE_LOOP;

	deltaTime = 1000.0f / sGlobalVariables->getFrameRate(id);

	//totalFrames = 0;

	FPS = 0;

	timesUnderDeltaTime = 0;

	quitEngineLoop = true;

}

Engine::~Engine() {}

void Engine::engineLoop()
{
	unsigned int T = 0;

	using dsec = std::chrono::duration<double>;
	auto invFpsLimit = std::chrono::round<std::chrono::system_clock::duration>(dsec{1./sGlobalVariables->getFrameRate(id)});
	auto m_BeginFrame = std::chrono::system_clock::now();
	auto m_EndFrame = m_BeginFrame + invFpsLimit;
	unsigned frame_count_per_second = 0;
	auto prev_time_in_seconds = std::chrono::time_point_cast<std::chrono::seconds>(m_BeginFrame);

	std::string title = "";

	std::chrono::high_resolution_clock::duration m_DeltaTime;

	while (sGlobalVariables->getQuiteEngineLoop(id) == true)
	{
		////----------------------------------------------
		////

		sInput->updateEvents();

		sSceneDirector->mCurrentScene->onLoad();

		sSceneDirector->mCurrentScene->onUpdate(clockToNanoseconds(deltaTime));

		sSceneDirector->mCurrentScene->onRender();

		////
		////----------------------------------------------

		auto time_in_seconds = std::chrono::time_point_cast<std::chrono::seconds>(std::chrono::system_clock::now());
		++frame_count_per_second;

		if (time_in_seconds > prev_time_in_seconds)	//	Frames per Second
		{
			FPS = frame_count_per_second;
			frame_count_per_second = 0;
			prev_time_in_seconds = time_in_seconds;
			deltaTime = 1000.0f / FPS;

			T++;

			title = "FPS: " + std::to_string(FPS) +
					" | DeltaTime (s): " + std::to_string(deltaTime / 1000.0f) +
					" | DeltaTime (ms): " + std::to_string(deltaTime) +
					" | Time (s): " + std::to_string(T) +
					" | Times Under DeltaTime: " + std::to_string(timesUnderDeltaTime);

			SDL_SetWindowTitle(sRenderer->getWindow(), title.c_str());
		}

		//	FPS Manager
		if (m_EndFrame > m_BeginFrame && invFpsLimit != dsec(1) )
		{
			std::this_thread::sleep_until(m_EndFrame);
			timesUnderDeltaTime++;
		}
		m_BeginFrame = m_EndFrame;
		m_EndFrame = m_BeginFrame + invFpsLimit;
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
	deleteSingletons();
}