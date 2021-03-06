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
	ButtonVector.push_back(new Button(SDL_Rect{ 500, 400, 300, 80 }, "Bot�n Funcional", new Padding(0, 25, 0, 25)));
	ButtonVector.push_back(new DropdownButton(SDL_Rect{ 800, 400, 300, 20 }, "Bot�n Disfuncional", new Padding(10, 25, 10, 25)));

	//	WITH THIS WE JUST CAST TO <BUTTON> AND THEN CALL THE FUNCTION CenterText()
	BasicButtontToButton(ButtonVector[2])->centerText();
	BasicButtontToButton(ButtonVector[3])->centerText();

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