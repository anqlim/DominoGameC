#pragma once
#include "domino.h"

extern DominoTile* set;
extern int tileCount;
extern int balance, victories, games, record, percent;
extern Player player, bot;
extern Field playField;
extern state currentState;
extern gameResult result;

extern float width, height, selectedX, selectedY;
extern Node* selectedTile;