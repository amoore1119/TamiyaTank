#include <TamiyaTank.h>

void ctrlMotor () { //30Hz
	uint16_t diff;
	
	//throttle motor
	if (sys.throttle.deadTime) {
		//
	} else if (sys.throttle.output.target > sys.throttle.output.present) { //speed up
		diff = sys.throttle.output.target - sys.throttle.output.present;
		
		if (diff > 200) {
			diff = 160;
		} else if (diff > 100) {
			diff = 80;
		} else if (diff > 50) {
			diff = 40;
		} else {
			diff = 1;
		}
		
		if ((sys.throttle.output.present + diff) > sys.throttle.para.max) {
			sys.throttle.output.present = sys.throttle.para.max;
		} else {
			sys.throttle.output.present += diff;
		}
		
	} else if (sys.throttle.output.target < sys.throttle.output.present) { //speed down		
		sys.throttle.output.present = sys.throttle.output.target;
	}
	
	//steer motor
	if (sys.steering.deadTime) {
		//
	} else if (sys.steering.output.target > sys.steering.output.present) { //speed up
		diff = sys.steering.output.target - sys.steering.output.present;
		
		if (diff > 200) {
			diff = 160;
		} else if (diff > 100) {
			diff = 80;
		} else if (diff > 50) {
			diff = 40;
		} else {
			diff = 1;
		}
		
		if ((sys.steering.output.present + diff) > sys.steering.para.max) {
			sys.steering.output.present = sys.steering.para.max;
		} else {
			sys.steering.output.present += diff;
		}
		
	} else if (sys.steering.output.target < sys.steering.output.present) { //speed down		
		sys.steering.output.present = sys.steering.output.target;
	}
	
}
