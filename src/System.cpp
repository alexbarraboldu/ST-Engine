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
	ButtonVector.resize(4);
	ButtonVector[0] = new BasicButton(SDL_Rect{ 40, 200, 200, 20});
	ButtonVector[1] = new BasicButton(SDL_Rect{400, 400, 100, 70});
	ButtonVector[2] = new BasicDropdownButton(30, 30, SDL_Color{0, 255, 0, 255});
	ButtonVector[3] = new Button(SDL_Rect{600, 600, 200, 50}, "Botón Funcional", new Padding{ 10,10,10,10 });

	testText = new Text();
	testText->LoadFont("OpenSans-Regular.ttf", 30);
	testText->LoadTextContent("LMAO THIS SHIT WORKS");
}

void System::render()
{
	size_t ButtonVectorSize = ButtonVector.size();
	for (size_t i = 0; i < ButtonVectorSize; i++)
	{
		ButtonVector[i]->render();
	}

	testText->RenderFont();
}

void System::update()
{
	size_t ButtonVectorSize = ButtonVector.size();
	for (size_t i = 0; i < ButtonVectorSize; i++)
	{
		ButtonVector[i]->update();
	}
}