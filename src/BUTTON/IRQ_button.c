#include "button.h"
#include "LPC17xx.h"

extern int int0, key1, key2;

void EINT0_IRQHandler (void)	  	/* INT0														 */
{
	NVIC_DisableIRQ(EINT0_IRQn);
	LPC_PINCON->PINSEL4 &= ~(1<<20);
	int0=1;
	LPC_SC->EXTINT &= (1 << 0);     /* clear pending interrupt         */
}

void EINT1_IRQHandler (void)	  	/* KEY1														 */
{
	NVIC_DisableIRQ(EINT1_IRQn);
	LPC_PINCON->PINSEL4 &= ~(1<<22);
	key1=1;
	LPC_SC->EXTINT &= (1 << 1);     /* clear pending interrupt         */
}

void EINT2_IRQHandler (void)	  	/* KEY2														 */
{
	NVIC_DisableIRQ(EINT2_IRQn);
	LPC_PINCON->PINSEL4 &= ~(1<<24);
	key2=1;
	LPC_SC->EXTINT &= (1 << 2);     /* clear pending interrupt         */    
}
