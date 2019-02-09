// author: chris-scientist
// created at: 05/02/2019
// updated at: 09/02/2019

#ifndef PLATFORMER_CHARACTER
#define PLATFORMER_CHARACTER

#include <Gamebuino-Meta.h>

#include "Constantes.h"

struct Character {
  int8_t x; // ............ position x
  int8_t y; // ............ position y
  int8_t oldY; // ......... position y au dernier rafraîchissement
  int8_t vx; // ........... vitesse horizontale
  int8_t vy; // ........... vitesse verticale
  bool toTheLeft; // ...... true si le personnage va vers la gauche, false sinon
  uint8_t state; // ....... état du personnage : voir constantes
};

void initCharacter(Character &aCharacter);
void rectifyPositionY(Character &aCharacter);

#endif
