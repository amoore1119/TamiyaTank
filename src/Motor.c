#include <TamiyaTank.h>

void ctrlMotor () { //30Hz
	uint16_t diff;
	
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
		/*
		diff = sys.throttle.output.present - sys.throttle.output.target;
		
		if (diff > 200) {
			diff = 16;
		} else if (diff > 100) {
			diff = 8;
		} else if (diff > 50) {
			diff = 4;
		} else {
			diff = 1;
		}
		
		if (diff > sys.throttle.output.present) {
			sys.throttle.output.present = 0;
		} else {
			sys.throttle.output.present -= diff;
		}*/
		
		sys.throttle.output.present = sys.throttle.output.target;
	}
	
}
