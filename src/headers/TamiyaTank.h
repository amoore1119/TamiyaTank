#include <samc21.h>
#include <Motor.h>

void tick (void );

typedef struct _system {
	uint32_t millis;
	uint32_t delay; //hard delay
	
	//
	Motor main; //engine
	Motor steering;
	Motor head;
	
} System;
extern System sys;

typedef struct _routine {
	uint8_t task1Hz : 1;
	uint8_t task10Hz : 1;
	uint8_t task100Hz : 1;
	uint8_t task30Hz : 1;
	uint8_t task60Hz : 1;
} Routine;
extern Routine routine;