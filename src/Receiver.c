#include <TamiyaTank.h>

void receiverParser () {
	if (!sys.radio.isRunning) {
		return;
	}
	
	//GEAR
	if (sys.radio.value[4] > RECEIVER_PPM_MAX) {
		//check cw/ccw, set gap time
		
		gpioRelayForward ();
		gpioLedIndicatorOff ();
		
	} else if (sys.radio.value[4] < RECEIVER_PPM_MIN) {
		//backward
	} else {
		//power lock
	}
	
	//right hand sticks
	sys.radio.value[0];
	sys.radio.value[1]; //verti
	
	//throttle
	if (sys.radio.value[2] > RECEIVER_PPM_MAX) {
		sys.throttle.output.target = sys.throttle.para.max;
	} else if (sys.radio.value[2] < RECEIVER_PPM_MIN) {
		sys.throttle.output.target = 0;
	} else {
		sys.throttle.output.target = (RECEIVER_PPM_MIN - sys.radio.value[2]) * sys.throttle.para.stickRes;
	}
	
	sys.radio.value[3];
	
	//sw
	sys.radio.value[5];
	
	//sw
	sys.radio.value[6];
	
	//vr
	sys.radio.value[7];
}