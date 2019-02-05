// author: chris-scientist
// created at: 05/02/2019

#ifndef PLATFORMER_CHARACTER
#define PLATFORMER_CHARACTER

#include <Gamebuino-Meta.h>

#include "Constantes.h"

struct Character {
  uint8_t x; // ............ position x
  uint8_t y; // ............ position y
  bool toTheLeft; // ... true si le personnage va vers la gauche, false sinon
};

void initCharacter(Character &aCharacter);

#endif
