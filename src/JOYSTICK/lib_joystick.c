#include "LPC17xx.h"
#include "joystick.h"

void joystick_init(void) {
	
	// select
	LPC_PINCON->PINSEL3 &= ~(3<<18);
	LPC_GPIO1->FIODIR &= ~(1<<25);
	
	// down
	LPC_PINCON->PINSEL3 &= ~(3<<20);
	LPC_GPIO1->FIODIR &= ~(1<<26);
	
	// left
	LPC_PINCON->PINSEL3 &= ~(3<<22);
	LPC_GPIO1->FIODIR &= ~(1<<27);
	
	// right
	LPC_PINCON->PINSEL3 &= ~(3<<24);
	LPC_GPIO1->FIODIR &= ~(1<<28);
	
	// up
	LPC_PINCON->PINSEL3 &= ~(3<<26);
	LPC_GPIO1->FIODIR &= ~(1<<29);
	
	return;
}
