#ifndef SYSTEM_H
#define	SYSTEM_H

#include <vector>

#include "buttons/DropdownButton.h"

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
	std::vector<Button*> ButtonVector;

};

#endif // !SYSTEM_H