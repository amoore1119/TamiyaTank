#include <TamiyaTank.h>
#include <Initialize.h>
#include <I2cMaster.h>

System sys;
Routine routine;

uint8_t flip = 0;

void main () {
	initGpio ();
	initClock ();
	initEic ();
	initEvsys ();
	//initPwm72Hz (TC1);
	//initPwm (TC2);
	//initPwm (TC3);
	//initPwm (TC4);
	initPpmMeasure ();
	
	initI2cMaster (SERCOM5);
	
	initTick ();
	
	NVIC_EnableIRQ (EIC_IRQn);
	NVIC_EnableIRQ (EVSYS_IRQn);
	NVIC_EnableIRQ (TCC0_IRQn);
	NVIC_EnableIRQ (TCC1_IRQn);
	NVIC_EnableIRQ (TCC2_IRQn);
	NVIC_EnableIRQ (TC1_IRQn);
	NVIC_EnableIRQ (TC2_IRQn);
	NVIC_EnableIRQ (TC3_IRQn);
	NVIC_EnableIRQ (TC4_IRQn);
	__enable_irq ();
	
	//
	//Main loop
	//
	while (1) {
		if (routine.task1Hz) {
			
			routine.task1Hz = 0;
		}
		
		if (routine.task10Hz) {
			if (flip) {
				gpioLedIndicatorOn ();
			} else {
				gpioLedIndicatorOff ();
			}
			flip ^= 1;
			
			routine.task10Hz = 0;
		}
		
		if (routine.task100Hz) {
			
			routine.task100Hz = 0;
		}
		
		if (routine.task60Hz) {
			
			routine.task60Hz = 0;
		}
		
		if (routine.task30Hz) {
			
			routine.task30Hz = 0;
		}
	}
}