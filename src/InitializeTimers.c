#include <samc21.h>
#include <Initialize.h>

void initPwm72Hz (Tc *tc) {
	while (tc->COUNT16.CTRLA.bit.SWRST);
	tc->COUNT16.CTRLA.bit.MODE = 0; //16bit mode
	tc->COUNT16.CTRLA.bit.PRESCALER = 0x0; //div1

	tc->COUNT16.CTRLBSET.bit.DIR = 0; //count down
	tc->COUNT16.CTRLBSET.bit.ONESHOT = 1;

	//tc->COUNT16.COUNT.reg = 10000;
	tc->COUNT16.CCBUF[0].reg = 0;
	tc->COUNT16.CCBUF[1].reg = 0;
	tc->COUNT16.CC[0].reg = 0;
	tc->COUNT16.CC[1].reg = 0;

	tc->COUNT16.WAVE.bit.WAVEGEN = 0x02;
	tc->COUNT16.INTENSET.bit.OVF = 1;
	tc->COUNT16.CTRLA.bit.ENABLE = 1;
}

void initPwm (Tc *tc) {
	while (tc->COUNT16.CTRLA.bit.SWRST);
	tc->COUNT16.CTRLA.bit.MODE = 0; //16bit mode
	//tc->COUNT16.CTRLA.bit.PRESCALER = 0x00; //div1 = 8Khz
	tc->COUNT16.CTRLA.bit.PRESCALER = 0x06; //div256
	//tc->COUNT16.CTRLA.bit.PRESCALER = 0x05; //div64
	//tc->COUNT16.CTRLA.bit.PRESCALER = 0x04; //div16
	//tc->COUNT16.CTRLA.bit.PRESCALER = 0x03; //div8

	tc->COUNT16.CTRLBSET.bit.DIR = 1;

	tc->COUNT16.COUNT.reg = 1000;
	tc->COUNT16.CCBUF[0].reg = 0;
	tc->COUNT16.CCBUF[1].reg = 0;
	tc->COUNT16.CC[0].reg = 0;
	tc->COUNT16.CC[0].reg = 0;

	tc->COUNT16.WAVE.bit.WAVEGEN = 0x02;
	tc->COUNT16.INTENSET.bit.OVF = 1;
	tc->COUNT16.CTRLA.bit.ENABLE = 1;
}
