#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum { win, lose, intermediate } gameResult;
typedef enum { menu, help, records, game } state;
typedef struct {
    int left;
    int right;
} DominoTile;
typedef struct Node {
    DominoTile tile;
    struct Node* prev;
    struct Node* next;
} Node;
typedef struct {
    Node* head;
    Node* tail;
} Player;
typedef Player Field;

void freePlayer(Node* tail);
void freeGame(DominoTile* set, Player* player, Player* bot, Field* field);

void fileData(); //извлечение данных из файла

void delay(int sec); //задержка

void addTile(Player* player, const DominoTile* tile);
void deleteTile(Player* player, Node* tile);

//функции для формирования набора костяшек и раздачи их игрокам
void createFullSet(DominoTile* tiles, int* count);
void shuffleTiles(DominoTile* tiles, int count);
void dealTiles(Player* player, DominoTile* tiles, int* count, int numTiles);
void InitialSet(Player* player, Player* bot, Field* field, DominoTile* tiles, int* tileCount);

//вспомогательные функции для логики бота
void swap(DominoTile* tile);
int match(DominoTile* tile, int val);
void transfer(Player* bot, Field* field, Node* current);

int chooseMove(Player* bot, Field* field, int flag); //алгоритм бота

//вспомогательные функции для проверок при ходах
int noSolutions(Player* player, Field* field);
int comparePoints(Player* player, Player* bot);

void endOfGame(Player* loser, gameResult result, state* currentState); //конец игры