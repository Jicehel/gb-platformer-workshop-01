// author: chris-scientist
// created at: 05/02/2019

#include "Display.h"

// Afficher un menu
const uint8_t paintMenu() {
  const char* items[] = {
    PLAY_FR
  };

  const uint8_t indexItem = gb.gui.menu("Menu", items);
  uint8_t choice = HOME_STATE;
  if(items[indexItem] == PLAY_FR) {
    choice = LAUNCH_PLAY_STATE;
  }
  return choice;
}

// Réalise tout l'affichage
void paint(Character &aCharacter) {
  paintHero(aCharacter);
}

// Réalise l'affichage du personnage
void paintHero(Character &aCharacter) {
  Color heroColor = (aCharacter.toTheLeft ? HERO_L_COLOR : HERO_R_COLOR);
  paintBox(aCharacter.x - OVER_CENTER_X_HERO, aCharacter.y - OVER_CENTER_Y_HERO, WIDTH_HERO, HEIGHT_HERO, heroColor);
}

// Dessine un rectangle de la couleur passée en paramètre
void paintBox(const uint8_t aX, const uint8_t aY, const uint8_t aWidth, const uint8_t aHeight, const Color aColor) {
  gb.display.setColor(aColor);
  gb.display.fillRect(aX, aY, aWidth, aHeight);
}
