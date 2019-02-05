// author: chris-scientist
// created at: 05/02/2019

#include <Gamebuino-Meta.h>

void setup() {
  // initialisation de la Gamebuino META
  gb.begin();
}

void loop() {
  // boucle d'attente
  while(!gb.update());

  // effacer l'écran
  gb.display.clear();

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
