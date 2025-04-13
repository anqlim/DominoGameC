#pragma once
#include <glfw3.h>
#include <string.h>
#include <math.h>
#include "domino.h"

#define WINDOW_WIDTH 1900
#define WINDOW_HEIGHT 1100
#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 200
#define BUTTONX WINDOW_WIDTH - 50 - BUTTON_WIDTH
#define BUTTONY 50
#define FIELD_LOW 300
#define FIELD_UP WINDOW_HEIGHT - 300

void drawDot(float x, float y, float size);

//отрисовка текста
void drawDigit(int digit, float x, float y, float size);
void drawText(char* str, float x, float y, float size);

//отрисовка кнопок
void drawButton();
void drawMissButton();
void drawExitButton();

//отрисовка костяшки
void drawHalfTile(float x, float y, float width, float height, int value);
void drawTile(float x, float y, float width, float height, int left, int right);
void drawSelected(float x, float y);

//отрисовка игровых зон (рука игрока, бота, игровое поле)
void drawPlayerHand(const Player* player);
void drawBotHand(const Player* bot);
void drawField(const Field* field);

//отрисовка окон
void drawMenu();
void drawHelp();
void drawGame();
void drawRecords();