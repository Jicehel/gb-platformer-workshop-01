// author: chris-scientist
// created at: 05/02/2019

#include "Character.h"

void initCharacter(Character &aCharacter) {
  // on force la position intiale du héro au milieu de l'écran et plaqué au sol
  aCharacter.x = 40;
  aCharacter.y = gb.display.height() - UNDER_CENTER_Y_HERO;

  // on force la direction du personnage vers la droite
  aCharacter.toTheLeft = false;
}
