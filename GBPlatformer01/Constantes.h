// author: chris-scientist
// created at: 05/02/2019

#ifndef PLATFORMER_CONSTANTES
#define PLATFORMER_CONSTANTES

#include <Gamebuino-Meta.h>

// Couleur des box
const Color HERO_L_COLOR = LIGHTBLUE;
const Color HERO_R_COLOR = BLUE;

// Pour un personnage de 8 pixels de haut sur 6 pixels de large
const uint8_t WIDTH_HERO = 6;
const uint8_t HEIGHT_HERO = 8;
const uint8_t UNDER_CENTER_X_HERO = 3; // à droite du héro
const uint8_t UNDER_CENTER_Y_HERO = 4; // en dessous du héro
const uint8_t OVER_CENTER_X_HERO = 3; // à gauche du héro
const uint8_t OVER_CENTER_Y_HERO = 4; // au dessus du héro

// Etat du jeu
const uint8_t HOME_STATE = 1;
const uint8_t LAUNCH_PLAY_STATE = 2;
const uint8_t PLAY_STATE = 3;

#endif
