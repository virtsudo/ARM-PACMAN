#include "LPC17xx.h"
#include "RIT.h"
#include "./TIMER/timer.h"
#include "./PACMAN/pacman.h"
#include "./GLCD/GLCD.h"

volatile int int0=0, key1=0, key2=0;
extern uint8_t pacmanDirection, gamePause;

void RIT_IRQHandler(void) {

	// Joystick
	static int select=0,up=0,down=0,left=0,right=0;
	
	if ((LPC_GPIO1->FIOPIN & (1<<25))==0) {
		select++;
		switch(select) {
			case 1:
				//
				break;
			default:
				break;
		}
	} else select=0;
	
	if ((LPC_GPIO1->FIOPIN & (1<<26))==0) {
		down++;
		switch(down) {
			case 1:
				if (PACMAN_Validate_Move(3)) pacmanDirection = 3;
				break;
			default:
				break;
		}
	} else down=0;
	
	if ((LPC_GPIO1->FIOPIN & (1<<27))==0) {
		left++;
		switch(left) {
			case 1:
				if (PACMAN_Validate_Move(1)) pacmanDirection = 1;
				break;
			default:
				break;
		}
	} else left=0;
	
	if ((LPC_GPIO1->FIOPIN & (1<<28))==0) {
		right++;
		switch(right) {
			case 1:
				if (PACMAN_Validate_Move(0)) pacmanDirection = 0;
				break;
			default:
				break;
		}
	} else right=0;
	
	if ((LPC_GPIO1->FIOPIN & (1<<29))==0) {
		up++;
		switch(up) {
			case 1:
				if (PACMAN_Validate_Move(2)) pacmanDirection = 2;
				break;
			default:
				break;
		}
	} else up=0;
	
	// Button
	if (int0>=1) {
		if ((LPC_GPIO2->FIOPIN & (1<<10))==0) {
			switch(int0) {
				case 1:
					if (!gamePause) {
						PACMAN_Print_Text(120, 180, "Pause", RGB565CONVERT(255, 204, 0), Black);
						disable_timer(0);
						disable_timer(1);
						gamePause = 1;
					} else {
						PACMAN_Print_Text(120, 180, "Pause", Black, Black);
						enable_timer(0);
						enable_timer(1);
						gamePause = 0;
					}
					break;
				default:
					break;
			}
			int0++;
		} else {
			int0=0;
			NVIC_EnableIRQ(EINT0_IRQn);
			LPC_PINCON->PINSEL4 |= (1<<20);
		}
	}

	
	if ((LPC_GPIO2->FIOPIN & (1<<11))==0) {
		switch(key1) {
			case 1:
				// 
				break;
			default:
				break;
		}
	} else {
		key1=0;
		NVIC_EnableIRQ(EINT1_IRQn);
		LPC_PINCON->PINSEL4 |= (1<<22);
	}
	
		
	if ((LPC_GPIO2->FIOPIN & (1<<12))==0) {
		switch(key2) {
			case 1:
				//
				break;
			default:
				break;
		}
	} else {
		key2=0;
		NVIC_EnableIRQ(EINT2_IRQn);
		LPC_PINCON->PINSEL4 |= (1<<24);
	}
	
	LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
	return;
}