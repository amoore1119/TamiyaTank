#include <TamiyaTank.h>

void tick () {
	static uint32_t div1Hz = 0;
	static uint32_t div10Hz = 0;
	static uint32_t div100Hz = 0;
	static uint32_t div30Hz = 0;
	static uint32_t div60Hz = 0;

	sys.millis++;

	if (sys.delay) {
		sys.delay--;
	}

	if (div1Hz < 1000) {
		div1Hz++;
	} else {
		div1Hz = 0;
		routine.task1Hz = 1;
	}

	if (div10Hz < 100) {
		div10Hz++;
	} else {
		div10Hz = 0;
		routine.task10Hz = 1;
	}

	if (div100Hz < 10) {
		div100Hz++;
	} else {
		div100Hz = 0;
		routine.task100Hz = 1;
	}

	if (div30Hz < 32) {
		div30Hz++;
	} else {
		div30Hz = 0;
		routine.task30Hz = 1;
	}

	if (div60Hz < 16) {
		div60Hz++;
	} else {
		div60Hz = 0;
		routine.task60Hz = 1;
	}
}
