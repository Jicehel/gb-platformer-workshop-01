// author: chris-scientist
// created at: 05/02/2019
// updated at: 07/02/2019

#include "Commands.h"

const uint8_t manageCommands(Character &aCharacter) {

  // par défaut, pas de vitesse horizontale
  aCharacter.vx = 0;

  if(gb.buttons.repeat(BUTTON_RIGHT, 1)) {
    if(aCharacter.x < (gb.display.width() - UNDER_CENTER_X_HERO)) {
      aCharacter.x++;
      aCharacter.toTheLeft = false;
      aCharacter.vx = HORIZONTAL_VELOCITY; // vitesse horizontale positive pour aller à drotie
    }
  } else if(gb.buttons.repeat(BUTTON_LEFT, 1)) {
    if(aCharacter.x > OVER_CENTER_X_HERO) {
      aCharacter.x--;
      aCharacter.toTheLeft = true;
      aCharacter.vx = -HORIZONTAL_VELOCITY; // vitesse horizonale négative pour aller à gauche
    }
  }

  if(gb.buttons.pressed(BUTTON_A) && aCharacter.state != JUMP_STATE) {
    aCharacter.state = PUSH_FOR_JUMP_STATE;
  }
  
  return (gb.buttons.pressed(BUTTON_MENU) ? HOME_STATE : PLAY_STATE);
}
