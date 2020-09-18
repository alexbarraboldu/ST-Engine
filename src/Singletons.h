#ifndef SINGLETONS_H
#define SINGLETONS_H

#include "GlobalVariables.h"
#include "Input.h"
#include "Renderer.h"
//#include "ResourceManager.h"
#include "SceneDirector.h"
//#include "SoundManager.h"

void initializeSingletons();

extern GlobalVariables* sGlobalVariables;
extern Input* sInput;
extern Renderer* sRenderer;
//extern ResourceManager* sResManager;
extern SceneDirector* sSceneDirector;
//extern SoundManager* sSndManager;

#endif