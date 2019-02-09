// author: chris-scientist
// created at: 09/02/2019

#include "PhysicsEngine.h"

// Implémentation du saut du personnage
void jump(Character &aCharacter) {
  const uint8_t platformId = isOnOnePlatform(aCharacter);

  if(aCharacter.state == PUSH_FOR_JUMP_STATE) {
    // le joueur donne une impulsion pour le saut
    // on initialise alors les données pour le saut
    aCharacter.vy = -INIT_VERTICAL_VELOCITY;
    aCharacter.state = JUMP_STATE;

    jumpMovement(aCharacter);
  } else if( platformId != NO_ID) {
    rectifyPositionY(aCharacter);
    aCharacter.vy = 0;
    aCharacter.state = ON_THE_PLATFORM_STATE;
  } else if( isOutOfWorld(aCharacter) ) {
    // si le saut nous conduit en dehots du monde
    // alors on applique la gravité
    aCharacter.state = FREE_FALL_STATE;
  } else {
    // le personnage saute
    jumpMovement(aCharacter);
  }
  
}

// Réalise le déplacement du personnage lors du saut
void jumpMovement(Character &aCharacter) {
  aCharacter.oldY = aCharacter.y; // ... on enregistre la position verticale précédente
  aCharacter.vy += GRAVITY; // ......... on fait évoluer la vitesse verticale
  aCharacter.x += aCharacter.vx; // .... on fait évoluer la position horizontale
  aCharacter.y += aCharacter.vy; // .... on fait évoluer la position verticale
}

// Chute libre
void gravity(Character &aCharacter) {

  const uint8_t platformId = isOnOnePlatform(aCharacter);
  if( platformId == NO_ID ) {
    // Chute libre
    aCharacter.oldY = aCharacter.y;
    aCharacter.vy += GRAVITY;
    aCharacter.state = FREE_FALL_STATE;
    aCharacter.y += aCharacter.vy;
  } else {
    // en contact avec une structure
    rectifyPositionY(aCharacter);
    aCharacter.vy = 0;
    aCharacter.state = ON_THE_PLATFORM_STATE;
  }
  
}

// Permet de détecter une collision avec le sol (cette fonction évoluera à l'étape suivante)
const uint8_t isOnOnePlatform(const Character &aCharacter) {
  return ( (aCharacter.y + aCharacter.vy) >= (gb.display.height() - UNDER_CENTER_Y_HERO) ) ? ID_GROUND : NO_ID ;
}

// Permet de détecter si nous sommes en dehors du monde
bool isOutOfWorld(Character &aCharacter) {
  if( aCharacter.x <= OVER_CENTER_X_HERO ) {
    // Si le personnage sort à gauche de l'écran
    // alors on force ses coordonnées pour qu'il soit toujours sur l'écran
    aCharacter.x = OVER_CENTER_X_HERO;
    return true;
  } else if( aCharacter.x >= (gb.display.width() - UNDER_CENTER_X_HERO) ) {
    // Si le personnage sort à droite de l'écran
    // alors on force ses coordonnées pour qu'il soit toujours sur l'écran
    aCharacter.x = gb.display.width() - UNDER_CENTER_X_HERO;
    return true;
  }
  return false;
}
