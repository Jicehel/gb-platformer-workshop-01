// author: chris-scientist
// created at: 05/02/2019
// updated at: 07/02/2019

#include <Gamebuino-Meta.h>

#include "Constantes.h"
#include "Display.h"
#include "Commands.h"
#include "PhysicsEngine.h"
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
      stateOfGame = paintMenu();
      break;
    case LAUNCH_PLAY_STATE:
      initCharacter(hero); // ...... on réinitialise les données du personnage
      stateOfGame = PLAY_STATE;
      break;
    case PLAY_STATE:
      if(hero.state == ON_THE_PLATFORM_STATE) {
        stateOfGame = manageCommands(hero);
      }

      if(hero.state != JUMP_STATE && hero.state != PUSH_FOR_JUMP_STATE) {
        gb.display.println("GRAVITY");
      } else if(hero.state == JUMP_STATE || hero.state == PUSH_FOR_JUMP_STATE) {
        jump(hero);
      }
      
      paint(hero);
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
