#include <TamiyaTank.h>

void NMI_Handler (void ) {
	//collision detected
}

void HardFault_Handler (void ) {
	while (1);
}

void SVC_Handler (void ) {
	while (1);
}

void PendSV_Handler (void ) {
	while (1);
}

void SysTick_Handler (void ) {
	tick ();
}
