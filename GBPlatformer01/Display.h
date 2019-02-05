// author: chris-scientist
// created at: 05/02/2019

#ifndef PLATFORMER_DISPLAY
#define PLATFORMER_DISPLAY

#include <Gamebuino-Meta.h>

#include "Constantes.h"
#include "Character.h"

void paint(Character &aCharacter);
void paintHero(Character &aCharacter);
void paintBox(const uint8_t aX, const uint8_t aY, const uint8_t aWidth, const uint8_t aHeight, const Color aColor);

#endif
