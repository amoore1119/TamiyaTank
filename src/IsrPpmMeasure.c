#include <TamiyaTank.h>

//PPM Ch1-Ch4
void TCC0_Handler (void ) {
	if (TCC0->INTFLAG.bit.TRG) {
		//
		TCC0->INTFLAG.reg = 0x02; //clear trg
	}
	
	if (TCC0->INTFLAG.bit.MC0) {
		sys.radio.value[0] = TCC0->CC[0].bit.CC;
		TCC0->INTFLAG.reg = 0x10000; //MC0
	}

	if (TCC0->INTFLAG.bit.MC1) {
		sys.radio.value[1] = TCC0->CC[1].bit.CC;
		TCC0->INTFLAG.reg = 0x20000; //MC1
	}

	if (TCC0->INTFLAG.bit.MC2) {
		sys.radio.value[2] = TCC0->CC[2].bit.CC;
		TCC0->INTFLAG.reg = 0x40000; //MC2
	}

	if (TCC0->INTFLAG.bit.MC3) {
		sys.radio.value[3] = TCC0->CC[3].bit.CC;
		TCC0->INTFLAG.reg = 0x80000; //MC3
	}

	if (TCC0->INTFLAG.bit.OVF) {
		//接收器意外掉電處理方式
		TCC0->INTFLAG.reg = 1; //OVF
	}
}

//measure Ch5-Ch6
void TCC1_Handler (void ) {
	if (TCC1->INTFLAG.bit.TRG) {
		TCC1->INTFLAG.reg = 0x02; //TRG
	}

	if (TCC1->INTFLAG.bit.MC0) {
		sys.radio.value[4] = TCC1->CC[0].bit.CC;
		TCC1->INTFLAG.reg = 0x10000; //MC0
	}

	if (TCC1->INTFLAG.bit.MC1) {
		sys.radio.value[5] = TCC1->CC[1].bit.CC;
		TCC1->INTFLAG.reg = 0x20000; //MC1
	}

	if (TCC1->INTFLAG.bit.OVF) {
		TCC1->INTFLAG.reg = 1; //OVF
	}
}

//meausre Ch7-Ch8
void TCC2_Handler (void ) {
	if (TCC2->INTFLAG.bit.TRG) {
		TCC2->INTFLAG.reg = 0x02; //TRG
	}

	if (TCC2->INTFLAG.bit.MC0) {
		sys.radio.value[6] = TCC2->CC[0].bit.CC;
		TCC2->INTFLAG.reg = 0x10000; //MC0
	}

	if (TCC2->INTFLAG.bit.MC1) {
		sys.radio.value[7] = TCC2->CC[1].bit.CC;
		TCC2->INTFLAG.reg = 0x20000; //MC1
	}

	if (TCC2->INTFLAG.bit.OVF) {
		TCC2->INTFLAG.reg = 1; //OVF
	}
}