// author: chris-scientist
// created at: 05/02/2019
// updated at: 09/02/2019

#include "Character.h"

void initCharacter(Character &aCharacter) {
  // on force la position intiale du héro au milieu de l'écran et plaqué au sol
  aCharacter.x = 40;
  aCharacter.y = gb.display.height() - UNDER_CENTER_Y_HERO;

  // on initialise la position y précédente
  aCharacter.oldY = aCharacter.y;

  // on force la direction du personnage vers la droite
  aCharacter.toTheLeft = false;

  // on initialise la vitesse verticale et horizontale
  aCharacter.vy = 0;
  aCharacter.vx = 0;

  // par défaut, le joueur est sur le sol
  aCharacter.state = ON_THE_PLATFORM_STATE;
}

// Corriger la position y (la fonction évoluera à la prochaine étape)
void rectifyPositionY(Character &aCharacter) {
  aCharacter.y = (gb.display.height() - UNDER_CENTER_Y_HERO);
}
