#include <TamiyaTank.h>

void receiverParser () {
	if (!sys.radio.isRunning) {
		return;
	}
	
	//GEAR
	if (sys.radio.value[4] > RECEIVER_PPM_MAX) {
		if (!sys.throttle.isCw) {
			sys.throttle.deadTime = sys.throttle.para.gap;
			sys.throttle.isCw = 1;
		}
		
		gpioRelayForward ();
		gpioLedIndicatorOff ();
		
	} else if (sys.radio.value[4] < RECEIVER_PPM_MIN) {
		if (sys.throttle.isCw) {
			sys.throttle.deadTime = sys.throttle.para.gap;
			sys.throttle.isCw = 0;
		}
		
		gpioRelayBackward ();
		gpioLedIndicatorOn ();
	} else {
		//power lock
	}
	
	//right hand sticks
	sys.radio.value[0];
	
	if (sys.radio.value[1] > RECEIVER_PPM_MAX) { // stick pull to botton
		sys.barrelVerital.target = sys.barrelVerital.para.neutro + sys.barrelVerital.para.rps;
	} else if (sys.radio.value[1] < RECEIVER_PPM_MIN) { //stick push to top
		sys.barrelVerital.target = sys.barrelVerital.para.neutro - sys.barrelVerital.para.rps;
	} else {
		sys.barrelVerital.target = sys.radio.value[1];
	}
	
	//throttle
	if (sys.radio.value[2] > RECEIVER_PPM_MAX) {
		sys.throttle.output.target = sys.throttle.para.max;
	} else if (sys.radio.value[2] < (RECEIVER_PPM_MIN + 50)) {
		sys.throttle.output.target = 0;
	} else {
		sys.throttle.output.target = sys.throttle.para.min + (uint16_t) ((sys.radio.value[2] - RECEIVER_PPM_MIN) * sys.throttle.para.stickRes);
	}
	
	//steer
	if (sys.radio.value[3] > RECEIVER_PPM_MAX) { //->CW
		if (!sys.steering.isCw) {
			sys.steering.deadTime = sys.steering.para.gap;
			sys.steering.isCw = 1;
		}
		//max target output
	} else if (sys.radio.value[3] < RECEIVER_PPM_MIN) { //->CCW
		if (sys.steering.isCw) {
			sys.steering.deadTime = sys.steering.para.gap;
			sys.steering.isCw = 0;
		}
		//max target output
	} else {
		if (sys.radio.value[3] > RECEIVER_PPM_NEUTRO) {
			//
		} else if (sys.radio.value[3] < RECEIVER_PPM_NEUTRO) {
			//
		}
	}
	
	//sw
	sys.radio.value[5];
	
	//sw
	sys.radio.value[6];
	
	//vr
	sys.radio.value[7];
}
