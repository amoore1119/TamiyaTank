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

void setMotorOutput (Motor *m, uint16_t target) {
	uint16_t diff;
	
	m->output.target = target;
	
	if (m->deadTime) {
		//do nothing
	} else if (m->output.target > m->output.present) { //up
		diff = m->output.target - m->output.present;
		
		if (diff > 200) {
			diff = 160; //16%
		} else if (diff > 100) {
			diff = 80; //8%	
		} else if (diff > 50) {
			diff = 40; //4%
		} else {
			diff = 1;
		}
		
		if ((m->output.present + diff) > m->para.max) {
			m->output.present = m->para.max;
		} else {
			m->output.present += diff;
		}
		
	} else if (m->output.target < m->output.present) { //down
		m->output.present = m->output.target;
	}
}
