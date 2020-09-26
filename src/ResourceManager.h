#ifndef RESOURCE_MANAGER_H
#define	RESOURCE_MANAGER_H

#include <SDL_image.h>
#include <string>
#include <vector>
#include <map>

#include "Id.h"

class ResourceManager : public Id
{
public:
	ResourceManager();
	~ResourceManager();

	static ResourceManager* getInstance();
	Sprite* getSpriteByID(unsigned int ID);
	Sprite* getSpriteByName(const char* filename);
//	SDL_Texture* getTextureByID(unsigned int ID);
	int getSpriteID(const char* filename);

	void loadImage(const char* filepath);

private:
	static ResourceManager* instance;

	//	PARA OBJETOS/PERSONAJES
	std::map<std::string, Sprite*> mSpriteMap;
	std::vector<Sprite*> mSpriteVector;

	//	PARA BACKGROUNDS
	//std::map<std::string, SDL_Texture*> mTextureMap;
	//std::vector<SDL_Texture*> mTextureVector;

	std::map<std::string, int> mIdMap;

	SDL_Texture* mTexture;
};

#endif //RESOURCE_MANAGER_H

