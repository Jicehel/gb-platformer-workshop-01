// author: chris-scientist
// created at: 05/02/2019
// updated at: 09/02/2019

#ifndef PLATFORMER_CONSTANTES
#define PLATFORMER_CONSTANTES

#include <Gamebuino-Meta.h>

// Couleur des box
const Color HERO_L_COLOR = LIGHTBLUE;
const Color HERO_R_COLOR = BLUE;

// Pour un personnage de 8 pixels de haut sur 6 pixels de large
const uint8_t WIDTH_HERO = 6;
const uint8_t HEIGHT_HERO = 8;
const uint8_t UNDER_CENTER_X_HERO = 3; // ... à droite du héro
const uint8_t UNDER_CENTER_Y_HERO = 4; // ... en dessous du héro
const uint8_t OVER_CENTER_X_HERO = 3; // .... à gauche du héro
const uint8_t OVER_CENTER_Y_HERO = 4; // .... au dessus du héro

// Etat du personnage
const uint8_t ON_THE_PLATFORM_STATE = 0; // ... le joueur est sur le sol
const uint8_t FREE_FALL_STATE = 1; // ......... le joueur est en chute libre
const uint8_t PUSH_FOR_JUMP_STATE = 2; // ..... le joueur donne une impulsion pour sauter
const uint8_t JUMP_STATE = 3; // .............. le joueur saute

// Identifiants des plateformes
const uint8_t NO_ID = 0;
const uint8_t ID_GROUND = 1;

// Etat du jeu
const uint8_t HOME_STATE = 1;
const uint8_t LAUNCH_PLAY_STATE = 2;
const uint8_t PLAY_STATE = 3;

// Gravité
const uint8_t GRAVITY = 1;

// Paramétrage du saut
const uint8_t HORIZONTAL_VELOCITY = 2; // ...... vitesse horizontale
const uint8_t INIT_VERTICAL_VELOCITY = 6; // ... vitesse verticale initiale

#endif
