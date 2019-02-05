// author: chris-scientist
// created at: 05/02/2019

#include "Commands.h"

const uint8_t manageCommands() {
  return (gb.buttons.pressed(BUTTON_MENU) ? HOME_STATE : PLAY_STATE);
}
