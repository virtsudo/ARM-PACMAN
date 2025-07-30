#include "LPC17xx.h"
#include "./PACMAN/pacman.h"
#include "./LED/led.h"
#include "./BUTTON/button.h"
#include "./TIMER/timer.h"
#include "./RIT/RIT.h"
#include "./JOYSTICK/joystick.h"
#include "./GLCD/GLCD.h"
#include "./TOUCH_PANEL/TouchPanel.h"

extern uint16_t pacmanColor;

#ifndef SIMULATOR
#define MOTION_REACT 0xBEBC20
#define JOYSTICK_REACT 0x004C4B40
#define TIMEOUT_REACT 0x17D7840
#endif

#ifdef SIMULATOR
extern uint8_t ScaleFlag; // <- ScaleFlag needs to visible in order for the emulator to find the symbol (can be placed also inside system_LPC17xx.h but since it is RO, it needs more work)
#define MOTION_REACT 0x7A120
#define JOYSTICK_REACT 0x1312D0
#define TIMEOUT_REACT 0xF0F5C
#endif

int main(void) {
	SystemInit();
	//LED_init();
	BUTTON_init();
	joystick_init();
	LCD_Initialization();
	//TP_Init();
	init_timer(0, MOTION_REACT);			
	init_RIT(JOYSTICK_REACT);				
	init_timer(1, TIMEOUT_REACT);			
	//TouchPanel_Calibrate();
	PACMAN_Draw_PlayGround();
	
	//PACMAN_Print_Text(120, 180, "Ready!", Black, Black);
	
	PACMAN_Print_Text(120, 180, "Pause", pacmanColor, Black);
	
	//enable_timer(0);
	enable_RIT();
	//enable_timer(1);
	
	
	LPC_SC->PCON |= 0x1;
	LPC_SC->PCON &= ~(0x2);						
	while(1){__ASM("wfi");}
}
