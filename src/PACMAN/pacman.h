#ifndef __PACMAN_H 
#define __PACMAN_H

#include "LPC17xx.h"

// #functions ----------------------------------------------------------------------------------------------------------

int PACMAN_Validate_Move(uint8_t direction);
void PACMAN_Print_Text(uint16_t x, uint16_t y, char *str, uint16_t fG, uint16_t bG);
void PACMAN_Draw_PlayGround();
void GAME_End(char *msg);
void GAME_Dispatcher();
// ---------------------------------------------------------------------------------------------------------------------

#endif