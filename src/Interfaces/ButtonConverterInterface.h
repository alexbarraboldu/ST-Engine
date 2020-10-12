#ifndef BUTTON_CONVERTER_INTERFACE_H
#define BUTTON_CONVERTER_INTERFACE_H

#include "../Buttons/Button.h"

class ButtonConverterInterface
{
public:
	virtual Button* BasicButtontToButton(BasicButton* buttonToCast) {
		return (Button*)buttonToCast;
	};

};

#endif // !BUTTON_CONVERTER_INTERFACE_H
