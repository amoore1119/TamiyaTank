#include <TamiyaTank.h>

void EIC_Handler () {
	if (EIC->INTFLAG.reg & 0x02) {
		
		//
		
		EIC->INTFLAG.reg = 0x02;
	}
}