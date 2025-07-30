#include "LPC17xx.h"
#include "timer.h"
#include "./PACMAN/pacman.h"

extern uint16_t pacmanX, pacmanY, pacmanScore;
extern uint8_t pacmanDirection, pacmanType, gameTime;

void TIMER0_IRQHandler (void)
{
	if (LPC_TIM0->IR==1) {
		pacmanType = 1;
		LPC_TIM0->IR = 1;			/* clear interrupt flag */
	} else if (LPC_TIM0->IR==2) {
		pacmanType = 2;
		LPC_TIM0->IR = 10;			/* clear interrupt flag */
	}
	if (pacmanScore < 2800) GAME_Dispatcher();
	else GAME_End("VICTORY!");
	return;
}

void TIMER1_IRQHandler (void)
{
	if (0 < gameTime) gameTime --;
	else GAME_End("Game Over!");
	LPC_TIM1->IR = 1;			/* clear interrupt flag */
	return;
}

void TIMER2_IRQHandler (void)
{
	LPC_TIM2->IR = 1;			/* clear interrupt flag */
	return;
}

void TIMER3_IRQHandler (void)
{
	LPC_TIM3->IR = 1;			/* clear interrupt flag */
	return;
}
