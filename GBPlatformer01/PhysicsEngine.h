// author: chris-scientist
// created at: 09/02/2019

#ifndef PLATFORMER_PHYSICS_ENGINE
#define PLATFORMER_PHYSICS_ENGINE

#include <Gamebuino-Meta.h>

#include "Constantes.h"
#include "Character.h"

void jump(Character &aCharacter);
void jumpMovement(Character &aCharacter);
const uint8_t isOnOnePlatform(const Character &aCharacter);
bool isOutOfWorld(Character &aCharacter);

#endif
