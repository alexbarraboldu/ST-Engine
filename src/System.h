#ifndef SYSTEM_H
#define	SYSTEM_H

#include <vector>

#include "buttons/Button.h"
#include "buttons/DropdownButton.h"
#include "Text.h"
#include "Interfaces/ButtonConverterInterface.h"

class System : public ButtonConverterInterface
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