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
	sys.radio.value[1]; //verti
	
	//throttle
	if (sys.radio.value[2] > RECEIVER_PPM_MAX) {
		sys.throttle.output.target = sys.throttle.para.max;
	} else if (sys.radio.value[2] < (RECEIVER_PPM_MIN + 50)) {
		sys.throttle.output.target = 0;
	} else {
		sys.throttle.output.target = sys.throttle.para.min + (uint16_t) ((sys.radio.value[2] - RECEIVER_PPM_MIN) * sys.throttle.para.stickRes);
	}
	
	sys.radio.value[3];
	
	//sw
	sys.radio.value[5];
	
	//sw
	sys.radio.value[6];
	
	//vr
	sys.radio.value[7];
}
