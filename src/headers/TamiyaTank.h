#include <samc21.h>
#include <stdio.h>
#include <Gpio.h>
#include <Receiver.h>
#include <Motor.h>
#include <Servo.h>

void tick (void );

typedef struct _system {
	uint32_t millis;
	uint32_t delay; //hard delay
	
	uint8_t mode;
	uint8_t error;
	
	//receiver
	RadioReceiver radio;
	
	//
	Motor throttle;
	Motor steering;
	
	//
	Servo turretV;
	Motor turretH;
	
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