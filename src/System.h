#ifndef SYSTEM_H
#define	SYSTEM_H

#//include <vector>

#include "Button.h"

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
	Button* ButtonVector;

};

#endif // !SYSTEM_H