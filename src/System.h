#ifndef SYSTEM_H
#define	SYSTEM_H

#include <vector>

#include "buttons/Button.h"
#include "buttons/BasicDropdownButton.h"
#include "Text.h"

class System
{
public:
	System();
	System(Uint8 numOfButtons);
	~System();

	virtual void init();
	virtual void update();
	virtual void render();

private:
	std::vector<BasicButton*> ButtonVector;
	Text* testText;

};

#endif // !SYSTEM_H