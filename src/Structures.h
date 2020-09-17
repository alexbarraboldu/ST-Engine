#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef enum {

	FRAME_RATE = 1,
	QUITE_ENGINE_LOOP = FRAME_RATE << 1,
	WIDTH_HEIGHT = QUITE_ENGINE_LOOP << 1,
	D = WIDTH_HEIGHT << 1,
	E = D << 1,

	NO_PERMISSION = E << 1,

} GlobalVar;

#endif // !STRUCUTRES_H
