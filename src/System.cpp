#include "System.h"

System::System()
{

}

System::~System()
{
	//	DESTROY ButtonVector;
}

void System::init()
{
	ButtonVector.resize(3);
	ButtonVector[0] = new Button(SDL_Rect{ 40, 200, 200, 20});
	ButtonVector[1] = new Button(SDL_Rect{400, 400, 100, 70});
	ButtonVector[2] = new DropdownButton(30, 30, SDL_Color{0, 255, 0, 255});

}

void System::render()
{
	size_t ButtonVectorSize = ButtonVector.size();
	for (size_t i = 0; i < ButtonVectorSize; i++)
	{
		ButtonVector[i]->render();
	}
}

void System::update()
{
	size_t ButtonVectorSize = ButtonVector.size();
	for (size_t i = 0; i < ButtonVectorSize; i++)
	{
		ButtonVector[i]->update();
	}
}