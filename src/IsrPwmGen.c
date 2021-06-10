#include <TamiyaTank.h>

//barrel, led dimmers
//72Hz PWM
void TC1_Handler (void ) {
	TC1->COUNT16.COUNT.reg = 10000;

	//BARREL SERVO 1.52MS NEUTRO
	TC1->COUNT16.CC[0].reg = 1520;
	
	//LED DIMMER 50%
	TC1->COUNT16.CC[1].reg = 5000;

	TC1->COUNT16.INTFLAG.reg = 1;
}

//steering motor pwm
void TC2_Handler (void ) {
	TC2->COUNT16.COUNT.reg = 1000;
	
	//One of CC[0, 1] must be 0, or causes MOSFET hi/lo side short
	TC2->COUNT16.CC[0].reg = 0; //CW
	TC2->COUNT16.CC[1].reg = 0; //CCW
	
	TC2->COUNT16.INTFLAG.reg = 1;
}

//throttle motor pwm
void TC3_Handler (void ) {
	TC3->COUNT16.COUNT.reg = 1000;

	//One of CC[0, 1] must be 0, or causes MOSFET hi/lo side short
	if (sys.throttle.deadTime) {
		TC3->COUNT16.CC[0].reg = 0; //CW
		TC3->COUNT16.CC[1].reg = 0; //CCW
	} else {
		if (sys.throttle.isCw) {
			TC3->COUNT16.CC[0].reg = sys.throttle.output.present;
			TC3->COUNT16.CC[1].reg = 0;
		} else {
			TC3->COUNT16.CC[0].reg = 0;
			TC3->COUNT16.CC[1].reg = sys.throttle.output.present;
		}
	}
	
	TC3->COUNT16.INTFLAG.reg = 1;
}

//
void TC4_Handler (void ) {
	TC4->COUNT16.COUNT.reg = 1000;
	
	//One of CC[0, 1] must be 0, or causes MOSFET hi/lo side short
	TC4->COUNT16.CC[0].reg = 0; //CW
	TC4->COUNT16.CC[1].reg = 0; //CCW
	
	TC4->COUNT16.INTFLAG.reg = 1;
}
