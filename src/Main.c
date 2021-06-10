#include <TamiyaTank.h>
#include <Initialize.h>
#include <I2cMaster.h>

System sys;
Routine routine;

void main () {
	initGpio ();
	initClock ();
	initEic ();
	initEvsys ();
	initPwm72Hz (TC1);
	//initPwm (TC2);
	initPwm (TC3);
	//initPwm (TC4);
	initPpmMeasure ();
	
	initI2cMaster (SERCOM5);
	
	//initialize motor parameters
	sys.throttle.para.gap = 400; //ms
	sys.throttle.para.max = 980; //0.1% pwm
	sys.throttle.para.min = 320;
	sys.throttle.para.stickRes = (float) (sys.throttle.para.max - sys.throttle.para.min) / 800; //800->stick range
	
	sys.steering.para.gap = 150;
	sys.steering.para.max = 980;
	sys.steering.para.min = 300;
	sys.steering.para.stickRes = (float) (sys.steering.para.max - sys.steering.para.min) / 400;
	
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
			
			routine.task10Hz = 0;
		}
		
		if (routine.task100Hz) {
			
			routine.task100Hz = 0;
		}
		
		if (routine.task60Hz) {
			
			receiverParser ();
			
			routine.task60Hz = 0;
		}
		
		if (routine.task30Hz) {
			
			ctrlMotor ();
			
			routine.task30Hz = 0;
		}
	}
}