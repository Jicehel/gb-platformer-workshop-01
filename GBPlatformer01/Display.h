// author: chris-scientist
// created at: 05/02/2019

#ifndef PLATFORMER_DISPLAY
#define PLATFORMER_DISPLAY

#include <Gamebuino-Meta.h>

#include "Constantes.h"
#include "Lang.h"
#include "Character.h"

const uint8_t paintMenu();
void paint(Character &aCharacter);
void paintHero(Character &aCharacter);
void paintBox(const int8_t aX, const int8_t aY, const uint8_t aWidth, const uint8_t aHeight, const Color aColor);

#endif
