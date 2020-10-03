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
	ButtonVector = new Button[1];
}

void System::render()
{
	Uint8 ButtonVectorSize = sizeof(*ButtonVector)/sizeof(Button);
	for (size_t i = 0; i < ButtonVectorSize; i++)
	{
		ButtonVector[i].render();
	}
}

void System::update()
{
	Uint8 ButtonVectorSize = sizeof(*ButtonVector)/sizeof(Button);
	for (size_t i = 0; i < ButtonVectorSize; i++)
	{
		ButtonVector[i].update();
	}
}