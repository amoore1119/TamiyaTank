#include <TamiyaTank.h>

void gpioLedIndicatorOn () {
	PORT->Group[0].OUTCLR.reg = (1 << 10);
}

void gpioLedIndicatorOff () {
	PORT->Group[0].OUTSET.reg = (1 << 10);
}

void gpioLedErrorOn () {
	PORT->Group[0].OUTCLR.reg = (1 << 11);
}

void gpioLedErrorOff () {
	PORT->Group[0].OUTSET.reg = (1 << 11);
}

void gpioRelayForward () {
	PORT->Group[1].OUTSET.reg = (1 << 3);
}

void gpioRelayBackward () {
	PORT->Group[1].OUTCLR.reg = (1 << 3);
}
