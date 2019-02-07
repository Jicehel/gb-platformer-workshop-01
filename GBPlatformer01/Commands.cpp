// author: chris-scientist
// created at: 05/02/2019
// updated at: 07/02/2019

#include "Commands.h"

const uint8_t manageCommands(Character &aCharacter) {

  if(gb.buttons.repeat(BUTTON_RIGHT, 1)) {
    if(aCharacter.x < (gb.display.width() - UNDER_CENTER_X_HERO)) {
      aCharacter.x++;
      aCharacter.toTheLeft = false;
    }
  }
  
  return (gb.buttons.pressed(BUTTON_MENU) ? HOME_STATE : PLAY_STATE);
}
