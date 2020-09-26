#include "Singletons.h"

ResourceManager* ResourceManager::instance = NULL;

ResourceManager::ResourceManager() : Id()
{
	if (instance != NULL) return;

	id = GlobalVar::NO_PERMISSION;
	
}

ResourceManager::~ResourceManager() {}


//	SETTERS

void ResourceManager::loadImage(const char* filepath)
{
	SDL_Surface* auxSurface = IMG_Load(filepath);

	if (auxSurface == NULL) printf("Error when loadin image: %s\n", filepath);

	Sprite* auxSpr = new Sprite (SDL_CreateTextureFromSurface(sRenderer->getRenderer(), auxSurface));
	
	//if (true)
	//{
	//	
	//}
	////mSpriteMap[0];
	mSpriteVector.push_back(auxSpr);
	mSpriteMap.insert(std::pair<std::string, Sprite*>(filepath, auxSpr));

}


//	GETTERS

ResourceManager* ResourceManager::getInstance()
{
	if (!instance)
	{
		instance = new ResourceManager();
	}
	return instance;
}

Sprite* ResourceManager::getSpriteByID(unsigned int ID)
{
	if (ID < mSpriteVector.size())
	{
		return mSpriteVector[ID];
	}
	else return NULL;
}

Sprite* ResourceManager::getSpriteByName(const char* filename)
{
	//int ID = getSpriteById(filename);
	return NULL;
}

//SDL_Texture* ResourceManager::getTextureByID(unsigned int ID)
//{
//	if (ID < mTextureVector.size())
//	{
//		return mTextureVector[ID];
//	}
//	else return NULL;
//}

int ResourceManager::getSpriteID(const char* filename)
{
	/*std::vector<std::string> lel;*/

	std::map<std::string, Sprite*>::iterator it = mSpriteMap.find(filename);

	int index = std::distance(mSpriteMap.begin(), it);

	return index;
}
