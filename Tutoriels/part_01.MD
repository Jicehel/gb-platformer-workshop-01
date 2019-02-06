
# Partie 1 - le personnage : création et affichage et gestion d'un menu

## Introduction

Dans cette partie, nous allons créer le personnage et l'afficher. Nous verrons également comment créer un menu.

## Programme basique

Avant de créer le personnage, il faut écrire le programme de base, il faut :
* penser à initialiser la Gamebuino META dans la fonction setup ;
* ajouter une boucle d'attente dans la fonction loop ;
* effacer l'écran toujours dans la fonction loop.

Pour tester que tout marche bien, afficher un message avec `gb.display.println("Votre message");`.

Voici mon programme de base :
```
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
```

Téléversez votre programme pour constater l'affichage du message.

Vous pouvez télécharger [ici le programme de base](https://github.com/chris-scientist/gb-platformer-workshop-01/archive/v0.0.zip).

## Le personnage

### Créer la structure

Bien, maintenant que nous avons un programme qui fonctionne, regardons de quoi nous avons besoin pour gérer le personnage.

Bien que nous allons qu'afficher ce personnage sans gérer les mouvements, ils seront aborder dans la prochaine partie, nous avons besoin :
* de la position x gérée avec un entier ;
* de la position y également gérée avec un entier ;
* de la direction gérée avec un booléen, true aller à gaucher et false aller à droite.

Pour représenter le personnage nous allons utiliser une structure, dont voici un exemple :
```
struct Car {
  int8_t speed;
  bool isStarted;
};
```

Dans cet exemple, nous avons créer une structure voiture, nommé `Car` qui possède deux attributs :
* la vitesse gérée avec un entier ;
* et un indicateur pour préciser si la voiture est démarrée, géré avec un booléen.

Placons la structure du personnage dans le fichier `Character.h`.

Si vous ne voyez pas comment implémenter la structure du personnage ou si vous avez réussi et que vous souhaitez comparer votre code, voici la structure que nous utiliserons au cours de ce workshop :
```
struct Character {
  int8_t x;
  int8_t y;
  bool toTheLeft;
};
```

### Initialiser le personnage

Maintenant que nous avons la structure du personnage il faut écrire une fonction qui initialise les données du personnage. Nous allons faire en sorte que notre personnage s'affiche en bas et au centre de l'écran, et qu'il se dirige vers la droite, pour cela nous devons initialiser :
* la position x du personnage à 40, soit la moitié de l'écran ;
* la position y du personnage à hauteur de l'écran - delta ;
* la direction (à ne pas oublier).

Remarque : le delta pour la position y du personnage, c'est le nombre de pixels en dessous du centre du personnage.

Nous allons avant de voir la solution définir quelques constantes.

Créez un fichier `Constantes.h`, et ajoutez y les constantes suivantes :
```
#ifndef PLATFORMER_CONSTANTES
#define PLATFORMER_CONSTANTES

// Pour un personnage de 8 pixels de haut sur 6 pixels de large
const uint8_t WIDTH_HERO = 6;
const uint8_t HEIGHT_HERO = 8;
const uint8_t UNDER_CENTER_X_HERO = 3; // à droite du héro
const uint8_t UNDER_CENTER_Y_HERO = 4; // en dessous du héro
const uint8_t OVER_CENTER_X_HERO = 3; // à gauche du héro
const uint8_t OVER_CENTER_Y_HERO = 4; // au dessus du héro

#endif
```

Comme vous pouvez le voir notre personnage fera 6 pixels de large sur 8 pixels de haut. Et pour le delta dont nous avons précédement parler il s'agit de la constante `UNDER_CENTER_Y_HERO`.

Voici la signature de la fonction servant à initialiser le personnage, fonction que nous allons déclarer dans `Character.h` :
```
void initCharacter(Character &aCharacter);
```

Vous remarquerez que nous utilisons un passage par référence grâce au symbole `&`. Sans ce passage par référence nous aurions un problème, en effet un passage par copie : `void initCharacter(Character aCharacter);` appliqerai l'initialisation qu'à l'intérieur de cette fonction, une fois de retour dans le programme principale ce serait comme si rien n'avait été fait. De plus, un passage par copie est plus groumand en mémoire.

Le code de cette fonction, a placé dans `Character.cpp`, est le suivant :
```
void initCharacter(Character &aCharacter) {
  // on force la position intiale du héro au milieu de l'écran et plaqué au sol
  aCharacter.x = 40;
  aCharacter.y = gb.display.height() - UNDER_CENTER_Y_HERO;

  // on force la direction du personnage vers la droite
  aCharacter.toTheLeft = false;
}
```

Il ne faut pas oublier d'inclure le fichier de constantes dans `Character.h`.

### Programme principale

Modifions le programme principale pour créer un personnage, l'initialiser et afficher ces informations. Mais avant nous allons en profiter pour ajouter un système d'états à notre jeu et ainsi moduler l'affichage en fonction de l'état.

Ajoutons d'abord les constantes suivantes dans `Constantes.h`, qui correspondent au état dont nous aurons besoin pour commencer :
```
const uint8_t HOME_STATE = 1;
const uint8_t LAUNCH_PLAY_STATE = 2;
const uint8_t PLAY_STATE = 3;
```

N'oublions pas d'inclure les constantes dans le programme principale.

Ensuite ajoutons une variable dans le programme principal pour gérer l'état, elle doit être déclaré en dehors des fonctions `setup` et `loop` :
```
uint8_t stateOfGame;
```

Dans la fonction `setup`, après l'initialisation de la console, initialisons l'état du jeu à la valeur `HOME_STATE`, comme ceci :
```
stateOfGame = HOME_STATE;
```

Il faut instancier notre structure personnage, comme pour la variable qui gère l'état, il faut créer le personnage en dehors des fonctions `setup` et `loop` :
```
Character hero;
```

Enfin, modifions le programme dans la fonction `loop` pour :
* lorsque nous sommes dans l'état `HOME_STATE`, passé à l'état `LAUNCH_PLAY_STATE` (nous ajouterons le menu à cet état à la fin de cette partie);
* lorsque nous sommes dans l'état `LAUNCH_PLAY_STATE` nous devons initialisé les informations du personnage grâce à la fonction `initCharacter` et passer à l'état `PLAY_STATE` ;
* lorsque nous sommes dans l'état `PLAY_STATE` afficher les informations du personnage ;
* par défaut, si nous ne sommes dans aucun de ces états (ce qui ne devrait pas ce produire) alors nous afficherons le texte de départ.

Nous utiliserons la structure conditionnelle `switch` pour faire ce travail.

Pour afficher les informations du personnage nous allons utiliser `gb.display.printf`, cette fonction s'utilise comme ceci :
```
gb.display.printf("Speed = %d", myCar.speed);
```

Voici à quoi ressemble notre gestion des états :
```
switch(stateOfGame) {
  case HOME_STATE:
    stateOfGame = LAUNCH_PLAY_STATE;
    break;
  case LAUNCH_PLAY_STATE:
    initCharacter(hero);
    stateOfGame = PLAY_STATE;
    break;
  case PLAY_STATE:
    gb.display.printf("x,y = %d,%d", hero.x, hero.y);
    gb.display.println("");
    gb.display.printf("to the left = %d", hero.toTheLeft);
  	break;
  default:
    gb.display.println("Votre message");
}
```

Vous pouvez téléverser votre programme vers la console, qui devrait afficher quelque chose comme :
```
x,y = 40,60
to the left = 0
```

Notons qu'un booléen affiche 0 s'il vaut `false` et 1 s'il vaut `true`.

### Afficher le personnage

Avant passer à l'affichage du personnage, définissons deux nouvelles constantes :
* une constante qui définit la couleur quand le personnage va à gauche (par exemple, `LIGHTBLUE`) ;
* une autre constante qui définit la couleur quand le personnage va à droite (par exemple, `BLUE`).

Pour ce faire, ajoutons dans le fichier `Constantes.h` les constantes suivantes :
```
const Color HERO_L_COLOR = LIGTHBLUE;
const Color HERO_R_COLOR = BLUE;
```

Il est nécessaire d'ajouter la bibliothèque de la console dans le fichier de constantes.

Nous allons gérer l'affichage du jeu dans les fichiers `Display.h` et `Display.cpp`.

Voici le contenu du fichier `Display.h` :
```
#ifndef PLATFORMER_DISPLAY
#define PLATFORMER_DISPLAY

#include <Gamebuino-Meta.h>

#include "Constantes.h"
#include "Character.h"

void paint(Character &aCharacter);
void paintHero(Character &aCharacter);
void paintBox(const int8_t aX, const int8_t aY, const uint8_t aWidth, const uint8_t aHeight, const Color aColor);

#endif
```

Quelques précisions sur les fonctions qui sont déclarées dans `Display.h` :
* `paint` sera la seule fonction utilisé dans le programme principale et c'est elle qui se chargera de faire tout l'affichage ;
* `paintHero` réalise l'affichage du personnage via `paintBox` ;
* `paintBox` dessine un rectangle en fonction des paramètres qui lui sont passés.

La fonction `paint` fera pour l'instant qu'un appel à `paintHero`.

Toutes ces fonctions doivent définit dans `Display.cpp`.

Pour changer la couleur il faut utiliser [gb.display.setColor](https://gamebuino.com/fr/academy/reference/graphics-setcolor) et pour dessiner un rectangle plein il faut utiliser [gb.display.fillRect](https://gamebuino.com/fr/academy/reference/graphics-fillrect).

Voici le code de la fonction `paintBox` :
```
void paintBox(const uint8_t aX, const uint8_t aY, const uint8_t aWidth, const uint8_t aHeight, const Color aColor) {
  gb.display.setColor(aColor);
  gb.display.fillRect(aX, aY, aWidth, aHeight);
}
```

Pour l'affichage du personnage nous allons utilisé une ternaire, ceci afin de choisir la couleur.

Voici un code classique :
```
char signe = '-';
if(nb > 0) {
  signe = '+';
}
```

Ce dernier peut-être remplacé par un condition ternaire que voici :
```
char signe (nb > 0) ? '+' : '-';
```

Voici le code de la fonction `paintHero` :
```
void paintHero(Character &aCharacter) {
  Color heroColor = (aCharacter.toTheLeft ? HERO_L_COLOR : HERO_R_COLOR);
  paintBox(aCharacter.x - OVER_CENTER_X_HERO, aCharacter.y - OVER_CENTER_Y_HERO, WIDTH_HERO, HEIGHT_HERO, heroColor);
}
```

Et voici le code de la fonction `paint` :
```
void paint(Character &aCharacter) {
  paintHero(aCharacter);
}
```

Retournons dans le programme principale, n'oubliez pas d'inclure `Display.h`, remplacons l'affichage des informations du personnage par l'affichage du jeu, soit le code suivant :
```
paint(hero);
```

Si vous téléverser votre programme, vous devriez voir un joli rectangle bleu en bas de l'écran : c'est votre personnage !

## Ajouter un menu

Nous allons ajouter un menu à notre jeu, nous le compléterons au fil de l'avancée du workshop.

Créons un fichier nommé `Lang.h`, dans ce dernier nous mettrons dans une prochaine partie une version en français et en anglais de tout les textes affichés à l'écran. Dans un premier temps nous nous limiterons au français. Voici le contenu du fichier :
```
#ifndef PLATFORMER_LANG
#define PLATFORMER_LANG

static const char * PLAY_FR = "Jouer";

#endif
```

Nous allons ajouter la gestion du menu dans `Display.h` et dans `Display.cpp`. D'abord, il faut inclure `Lang.h` dans `Display.h`. Ensuite ajouter le prototype de la fonction suivante (toujours dans `Display.h`) :
```
const uint8_t paintMenu();
```

Pour le menu nous allons utiliser la fonction [gb.gui.menu](https://gamebuino.com/fr/academy/reference/gb-gui-menu), cette fonction prend en paramètre une chaîne de caractères pour le nom du menu, et un tableau de chaîne de caractères pour les items. Pour l'instant le menu ne comporte qu'un seul item.

Voici le code de la fonction `paintMenu` à placé dans `Display.h` :
```
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
```

Dans le programme principale, remplacez `stateOfGame = LAUNCH_PLAY_STATE;` par `stateOfGame = paintMenu();`, rappelez vous c'est dans l'état `HOME_STATE`.

En complément de ce menu, nous allons ajouter une commande permettant de revenir au menu lorsque le jeu est en cours. Pour cela, créons le fichier `Commands.h` avec le code suivant :
```
#ifndef PLATFORMER_COMMANDS
#define PLATFORMER_COMMANDS

#include <Gamebuino-Meta.h>

#include "Constantes.h"

const uint8_t manageCommands();

#endif
```

Le code de la méthode `manageCommands` est relativement simple, si le bouton menu est pressé alors on retourne au menu, sinon on reste dans le jeu, soit le code suivant :
```
#include "Commands.h"

const uint8_t manageCommands() {
  return (gb.buttons.pressed(BUTTON_MENU) ? HOME_STATE : PLAY_STATE);
}
```

Comme vous le voyez nous utilisons à nouveau une condition ternaire.

Dans le programme principale, dans l'état `PLAY_STATE` et avant l'affichage du jeu, ajoutons l'appel à la fonction `manangeCommands` soit le code suivant :
```
stateOfGame = manageCommands();
```

Vous pouvez téléverser votre programme sur la console, vous aurez au démarrage du jeu un menu avec l'item "Jouer", qui permet de lancer le jeu. Pendant le jeu vous pouvez revenir au menu grâce au bouton menu.

## Conclusion

Vous voici arrivez à la fin de cette première partie, nous avons créer et afficher un personnage et gérer les commandes basiques pour naviguer dans notre jeu, en partie grâce à un menu.

Si vous avez terminé ou si vous rencontrez des problèmes vous pouvez télécharger la solution ici.

Dans la prochaine partie, c'est-à-dire la deuxième, nous aborderons les déplacements du personnage.

N'hésitez pas à me faire un retour : les améliorations que vous apporteriez (un regard extérieur est toujours bienvenu), les fautes, etc.
