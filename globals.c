#include "globals.h"

DominoTile* set = NULL;
int tileCount = 0;
int balance, victories, games, record, percent;
Player player = { NULL, NULL };
Player bot = { NULL, NULL };
Field playField = { NULL, NULL };
state currentState = menu;
gameResult result = intermediate;

float width = 75, height = 150;
float selectedX = -1, selectedY = -1;
Node* selectedTile = NULL;