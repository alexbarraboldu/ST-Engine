#ifndef SINGLETONS_H
#define SINGLETONS_H

#include "GlobalSingletons/GlobalVariables.h"
#include "GlobalSingletons/Input.h"
#include "GlobalSingletons/Renderer.h"
#include "GlobalSingletons/ResourceManager.h"
#include "GlobalSingletons/SceneDirector.h"
//#include "SoundManager.h"

const void initializeSingletons();
const void deleteSingletons();

extern GlobalVariables* sGlobalVariables;
extern Input* sInput;
extern Renderer* sRenderer;
extern ResourceManager* sResourceManager;
extern SceneDirector* sSceneDirector;
//extern SoundManager* sSndManager;

#endif
