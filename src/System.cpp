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
	//ButtonVector.resize(3);
	ButtonVector.push_back(new BasicButton(SDL_Rect{ 40, 200, 200, 20 }));
	ButtonVector.push_back(new BasicDropdownButton(30, 30, SDL_Color{ 0, 255, 0, 255 }));
	ButtonVector.push_back(new Button(SDL_Rect{ 600, 400, 300, 80 }, "Botón Funcional", new Padding(0, 25, 0, 25)));

	//testText = new Text();
	//testText->LoadFont("OpenSans-Regular.ttf", 30);
	//testText->LoadTextContent("LMAO THIS SHIT WORKS");
}

void System::render()
{
	size_t ButtonVectorSize = ButtonVector.size();
	for (size_t i = 0; i < ButtonVectorSize; i++)
	{
		ButtonVector[i]->render();
	}

	//testText->RenderFont();
}

void System::update()
{
	size_t ButtonVectorSize = ButtonVector.size();
	for (size_t i = 0; i < ButtonVectorSize; i++)
	{
		ButtonVector[i]->update();
	}
}