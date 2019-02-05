// author: chris-scientist
// created at: 05/02/2019

#include <Gamebuino-Meta.h>

#include "Constantes.h"
#include "Character.h"

Character hero;
uint8_t stateOfGame;

void setup() {
  // initialisation de la Gamebuino META
  gb.begin();

  // initialisation du programme
  stateOfGame = HOME_STATE;
}

void loop() {
  // boucle d'attente
  while(!gb.update());

  // effacer l'écran
  gb.display.clear();

  switch(stateOfGame) {
    case HOME_STATE:
      // gestion d'un menu à implementer...
      stateOfGame = LAUNCH_PLAY_STATE;
      break;
    case LAUNCH_PLAY_STATE:
      initCharacter(hero); // ...... on réinitialise les données du personnage
      stateOfGame = PLAY_STATE;
      break;
    case PLAY_STATE:
      gb.display.printf("x,y = %d,%d", hero.x, hero.y);
      gb.display.println("");
      gb.display.printf("to the left = %d", hero.toTheLeft);
      break;
    default:
      /*************************************************/
      /**/   /* A REMPLACER PAR VOTRE PROGRAMME */   /**/
      /**/ gb.display.println("");                   /**/
      /**/ gb.display.println("   - Platformer -");  /**/
      /**/ gb.display.println("");                   /**/
      /**/ gb.display.println("");                   /**/
      /**/ gb.display.println("   Workshop 01 :");   /**/
      /**/ gb.display.println("     Les bases");     /**/
      /*************************************************/
  }
}