#include <samc21.h>
#include <Initialize.h>

void initPpmMeasure () {
	//RF PPM Measure
	while (TCC0->CTRLA.bit.SWRST);
	TCC0->CTRLA.bit.CPTEN0 = 1;
	TCC0->CTRLA.bit.CPTEN1 = 1;
	TCC0->CTRLA.bit.CPTEN2 = 1;
	TCC0->CTRLA.bit.CPTEN3 = 1;

	TCC0->EVCTRL.bit.MCEI0 = 1;
	TCC0->EVCTRL.bit.MCEI1 = 1;
	TCC0->EVCTRL.bit.MCEI2 = 1;
	TCC0->EVCTRL.bit.MCEI3 = 1;

	TCC0->EVCTRL.bit.MCEO0 = 1; //TEST DMA

	TCC0->EVCTRL.bit.TCEI0 = 1;
	TCC0->EVCTRL.bit.EVACT0 = 1; //when TCE0 -> restart

	TCC0->INTENSET.bit.OVF = 1;
	TCC0->INTENSET.bit.MC0 = 1;
	TCC0->INTENSET.bit.MC1 = 1;
	TCC0->INTENSET.bit.MC2 = 1;
	TCC0->INTENSET.bit.MC3 = 1;

	//TCC0->CTRLA.bit.PRESCALER = 5;
	TCC0->CTRLA.bit.PRESCALER = 3; // 8Mhz / DIV8;
	TCC0->CTRLA.bit.ENABLE = 1;
	TCC0->CTRLBSET.bit.CMD = 0x01; //force start

	//RF PPM Measure
	while (TCC1->CTRLA.bit.SWRST);
	TCC1->CTRLA.bit.CPTEN0 = 1;
	TCC1->CTRLA.bit.CPTEN1 = 1;

	TCC1->EVCTRL.bit.MCEI0 = 1;
	TCC1->EVCTRL.bit.MCEI1 = 1;

	TCC1->EVCTRL.bit.TCEI0 = 1;
	TCC1->EVCTRL.bit.EVACT0 = 1; //when TCE0 -> restart

	TCC1->INTENSET.bit.OVF = 1;
	TCC1->INTENSET.bit.MC0 = 1;
	TCC1->INTENSET.bit.MC1 = 1;

	//TCC1->CTRLA.bit.PRESCALER = 4;
	TCC1->CTRLA.bit.PRESCALER = 3; // 8Mhz / DIV8;
	TCC1->CTRLA.bit.ENABLE = 1;
	TCC1->CTRLBSET.bit.CMD = 0x01; //force start

	//RF PPM Measure
	while (TCC2->CTRLA.bit.SWRST);
	TCC2->CTRLA.bit.CPTEN0 = 1;
	TCC2->CTRLA.bit.CPTEN1 = 1;

	TCC2->EVCTRL.bit.MCEI0 = 1;
	TCC2->EVCTRL.bit.MCEI1 = 1;

	TCC2->EVCTRL.bit.TCEI0 = 1;
	TCC2->EVCTRL.bit.EVACT0 = 1; //when TCE0 -> restart

	TCC2->INTENSET.bit.OVF = 1;
	TCC2->INTENSET.bit.MC0 = 1;
	TCC2->INTENSET.bit.MC1 = 1;

	TCC2->CTRLA.bit.PRESCALER = 3; // 8Mhz / DIV8;
	TCC2->CTRLA.bit.ENABLE = 1;
	TCC2->CTRLBSET.bit.CMD = 0x01; //force start
}
