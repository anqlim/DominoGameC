#include "globals.h"
#include "graphics.h"

void drawDot(float x, float y, float size) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159f / 180.0f;
        glVertex2f(x + size * cos(angle), y + size * sin(angle));
    }
    glEnd();
}
void drawDigit(int digit, float x, float y, float size) {
    glLineWidth(size / 8);
    if (digit == 'a' || digit == 'b' || digit == 'c' ||
        digit == 'd' || digit == 'e' || digit == 'f' ||
        digit == 'g' || digit == 'h' || digit == 'j' ||
        digit == 'k' || digit == 'l' || digit == 'm' ||
        digit == 'n' || digit == 'o' || digit == 'p' ||
        digit == 'q' || digit == 'r' || digit == 'u' ||
        digit == 'w' || digit == '0' || digit == '2' ||
        digit == '6' || digit == '8') {
        glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x, y + size);
        glEnd();
    }
    if (digit == 'a' || digit == 'b' || digit == 'c' ||
        digit == 'd' || digit == 'e' || digit == 'f' ||
        digit == 'g' || digit == 'h' || digit == 'k' ||
        digit == 'l' || digit == 'm' || digit == 'n' ||
        digit == 'o' || digit == 'p' || digit == 'q' ||
        digit == 'r' || digit == 's' || digit == 'u' ||
        digit == 'v' || digit == 'w' || digit == 'y' ||
        digit == '0' || digit == '4' || digit == '5' ||
        digit == '6' || digit == '7' || digit == '8' ||
        digit == '9') {
        glBegin(GL_LINES);
        glVertex2f(x, y + size);
        glVertex2f(x, y + 2 * size);
        glEnd();
    }
    if (digit == 'a' || digit == 'c' || digit == 'e' ||
        digit == 'f' || digit == 'g' || digit == 'i' ||
        digit == 'j' || digit == 'o' || digit == 'p' ||
        digit == 'q' || digit == 'r' || digit == 's' ||
        digit == 't' || digit == 'z' || digit == '0' ||
        digit == '2' || digit == '3' || digit == '5' ||
        digit == '6' || digit == '7' || digit == '8' ||
        digit == '9') {
        glBegin(GL_LINES);
        glVertex2f(x, y + 2 * size);
        glVertex2f(x + size, y + 2 * size);
        glEnd();
    }
    if (digit == 'a' || digit == 'h' || digit == 'j' ||
        digit == 'm' || digit == 'n' || digit == 'o' ||
        digit == 'p' || digit == 'q' || digit == 'r' ||
        digit == 'u' || digit == 'v' || digit == 'w' ||
        digit == 'y' || digit == '0' || digit == '1' ||
        digit == '2' || digit == '3' || digit == '4' ||
        digit == '7' || digit == '8' || digit == '9') {
        glBegin(GL_LINES);
        glVertex2f(x + size, y + 2 * size);
        glVertex2f(x + size, y + size);
        glEnd();
    }
    if (digit == 'a' || digit == 'g' || digit == 'h' ||
        digit == 'j' || digit == 'm' || digit == 'n' ||
        digit == 'o' || digit == 'q' || digit == 's' ||
        digit == 'u' || digit == 'w' || digit == 'y' ||
        digit == '0' || digit == '1' || digit == '3' ||
        digit == '4' || digit == '5' || digit == '6' ||
        digit == '7' || digit == '8' || digit == '9') {
        glBegin(GL_LINES);
        glVertex2f(x + size, y + size);
        glVertex2f(x + size, y);
        glEnd();
    }
    if (digit == 'c' || digit == 'e' || digit == 'g' ||
        digit == 'i' || digit == 'j' || digit == 'l' ||
        digit == 'o' || digit == 'q' || digit == 's' ||
        digit == 'u' || digit == 'y' || digit == 'z' ||
        digit == '0' || digit == '2' || digit == '3' ||
        digit == '5' || digit == '6' || digit == '8' ||
        digit == '9') {
        glBegin(GL_LINES);
        glVertex2f(x + size, y);
        glVertex2f(x, y);
        glEnd();
    }
    if (digit == 'a' || digit == 'e' || digit == 'f' ||
        digit == 'h' || digit == 'p' || digit == 'r' ||
        digit == 's' || digit == 'y' || digit == 'z' ||
        digit == '2' || digit == '3' || digit == '4' ||
        digit == '5' || digit == '6' || digit == '8' ||
        digit == '9') {
        glBegin(GL_LINES);
        glVertex2f(x, y + size);
        glVertex2f(x + size, y + size);
        glEnd();
    }
    if (digit == 'b') {
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y + size * 2);
        glVertex2f(x + size * 7 / 8, y + size * 2);
        glVertex2f(x + size, y + size * 15 / 8);
        glVertex2f(x + size, y + size * 9 / 8);
        glVertex2f(x + size * 7 / 8, y + size);
        glVertex2f(x, y + size);
        glVertex2f(x + size * 7 / 8, y + size);
        glVertex2f(x + size, y + size * 7 / 8);
        glVertex2f(x + size, y + size / 8);
        glVertex2f(x + size * 7 / 8, y);
        glVertex2f(x, y);
        glEnd();
    }
    if (digit == 'd') {
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y + size * 2);
        glVertex2f(x + size * 3 / 4, y + size * 2);
        glVertex2f(x + size, y + size * 7 / 4);
        glVertex2f(x + size, y + size / 4);
        glVertex2f(x + size * 3 / 4, y);
        glVertex2f(x, y);
        glEnd();
    }
    if (digit == 'g') {
        glBegin(GL_LINES);
        glVertex2f(x + size / 2, y + size);
        glVertex2f(x + size, y + size);
        glEnd();
    }
    if (digit == 'i' || digit == 't') {
        glBegin(GL_LINES);
        glVertex2f(x + size / 2, y);
        glVertex2f(x + size / 2, y + size * 2);
        glEnd();
    }
    if (digit == 'k') {
        glBegin(GL_LINES);
        glVertex2f(x + size, y + 2 * size);
        glVertex2f(x, y + size);
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(x, y + size);
        glVertex2f(x + size, y);
        glEnd();
    }
    if (digit == 'm') {
        glBegin(GL_LINES);
        glVertex2f(x, y + 2 * size);
        glVertex2f(x + size / 2, y + size);
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(x + size / 2, y + size);
        glVertex2f(x + size, y + 2 * size);
        glEnd();
    }
    if (digit == 'n' || digit == '0') {
        glBegin(GL_LINES);
        glVertex2f(x, y + 2 * size);
        glVertex2f(x + size, y + size);
        glEnd();
    }
    if (digit == 'q' || digit == 'r') {
        glBegin(GL_LINES);
        glVertex2f(x + size / 2, y + size);
        glVertex2f(x + size, y);
        glEnd();
    }
    if (digit == 'v') {
        glBegin(GL_LINES);
        glVertex2f(x, y + size);
        glVertex2f(x + size / 2, y);
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(x + size / 2, y);
        glVertex2f(x + size, y + size);
        glEnd();
    }
    if (digit == 'x' || digit == 'z') {
        glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x + size, y + 2 * size);
        glEnd();
    }
    if (digit == 'x') {
        glBegin(GL_LINES);
        glVertex2f(x + size, y);
        glVertex2f(x, y + 2 * size);
        glEnd();
    }
    if (digit == 'w') {
        glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x + size / 2, y + size);
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(x + size / 2, y + size);
        glVertex2f(x + size, y);
        glEnd();
    }
    if (digit == '.') {
        drawDot(x, y, size / 8);
    }
    if (digit == ',') {
        glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x, y - size / 2);
        glEnd();
    }
    if (digit == '%') {
        drawDot(x + size / 4, y + size * 3 / 2, size / 4);
        drawDot(x + size * 3 / 4, y + size / 2, size / 4);
        glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x + size, y + 2 * size);
        glEnd();
        glColor3f(0.449f, 0.5098f, 0.5432f);
        drawDot(x + size / 4, y + size * 3 / 2, size / 8);
        drawDot(x + size * 3 / 4, y + size / 2, size / 8);
        glColor3f(0.1451f, 0.2157f, 0.2706f);
    }
}
void drawText(char* str, float x, float y, float size) {
    int n = strlen(str);
    float width;
    for (int i = 0; i < n; i++) {
        drawDigit((int)str[i], x, y, size / 2);
        x += size * 5 / 8;
    }
}
void drawButton() {
    glColor3f(0.2902f, 0.3608f, 0.4157f);
    glBegin(GL_QUADS);
    glVertex2f(BUTTONX, BUTTONY);
    glVertex2f(BUTTONX, BUTTONY + BUTTON_HEIGHT);
    glVertex2f(BUTTONX + BUTTON_WIDTH, BUTTONY + BUTTON_HEIGHT);
    glVertex2f(BUTTONX + BUTTON_WIDTH, BUTTONY);
    glEnd();

    glColor3f(0.1451f, 0.2157f, 0.2706f);
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(BUTTONX, BUTTONY);
    glVertex2f(BUTTONX, BUTTONY + BUTTON_HEIGHT);
    glVertex2f(BUTTONX + BUTTON_WIDTH, BUTTONY + BUTTON_HEIGHT);
    glVertex2f(BUTTONX + BUTTON_WIDTH, BUTTONY);
    glEnd();

    drawText("bazaar", BUTTONX + 10, BUTTONY + 110, 50.0f);
    char counter[3];
    if (tileCount < 10) {
        drawText(_itoa(tileCount, counter, 10), BUTTONX + BUTTON_WIDTH / 2 - 12.5f, BUTTONY + 30, 50.0f);
    }
    else {
        drawText(_itoa(tileCount, counter, 10), BUTTONX + BUTTON_WIDTH / 2 - 37.5f, BUTTONY + 30, 50.0f);
    }
}
void drawMissButton() {
    glColor3f(0.2902f, 0.3608f, 0.4157f);
    glBegin(GL_QUADS);
    glVertex2f(BUTTONX - 70, BUTTONY);
    glVertex2f(BUTTONX - 70, BUTTONY + BUTTON_HEIGHT);
    glVertex2f(BUTTONX - 20, BUTTONY + BUTTON_HEIGHT);
    glVertex2f(BUTTONX - 20, BUTTONY);
    glEnd();

    glColor3f(0.1451f, 0.2157f, 0.2706f);
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(BUTTONX - 70, BUTTONY);
    glVertex2f(BUTTONX - 70, BUTTONY + BUTTON_HEIGHT);
    glVertex2f(BUTTONX - 20, BUTTONY + BUTTON_HEIGHT);
    glVertex2f(BUTTONX - 20, BUTTONY);
    glEnd();

    drawText("m", BUTTONX - 55, BUTTONY + 152, 40.0f);
    drawText("i", BUTTONX - 55, BUTTONY + 104, 40.0f);
    drawText("s", BUTTONX - 55, BUTTONY + 56, 40.0f);
    drawText("s", BUTTONX - 55, BUTTONY + 8, 40.0f);
}
void drawExitButton() {
    glColor3f(0.8196f, 0.7804f, 0.7412f);
    glBegin(GL_QUADS);
    glVertex2f(WINDOW_WIDTH - 50, WINDOW_HEIGHT - 50);
    glVertex2f(WINDOW_WIDTH - 50, WINDOW_HEIGHT);
    glVertex2f(WINDOW_WIDTH, WINDOW_HEIGHT);
    glVertex2f(WINDOW_WIDTH, WINDOW_HEIGHT - 50);
    glEnd();

    glColor3f(0.1451f, 0.2157f, 0.2706f);
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(WINDOW_WIDTH - 50, WINDOW_HEIGHT - 50);
    glVertex2f(WINDOW_WIDTH - 50, WINDOW_HEIGHT);
    glVertex2f(WINDOW_WIDTH, WINDOW_HEIGHT);
    glVertex2f(WINDOW_WIDTH, WINDOW_HEIGHT - 50);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glVertex2f(WINDOW_WIDTH - 40, WINDOW_HEIGHT - 40);
    glVertex2f(WINDOW_WIDTH - 10, WINDOW_HEIGHT - 10);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(WINDOW_WIDTH - 40, WINDOW_HEIGHT - 10);
    glVertex2f(WINDOW_WIDTH - 10, WINDOW_HEIGHT - 40);
    glEnd();
}
void drawHalfTile(float x, float y, float width, float height, int value) {
    glColor3f(0.1451f, 0.2157f, 0.2706f);
    if (value == 1) {
        drawDot(x + width / 2, y + height / 2, width / 16);
    }
    else if (value == 2) {
        drawDot(x + width / 4, y + height / 2, width / 16);
        drawDot(x + width * 3 / 4, y + height / 2, width / 16);
    }
    else if (value == 3) {
        drawDot(x + width / 4, y + height / 4, width / 16);
        drawDot(x + width / 2, y + height / 2, width / 16);
        drawDot(x + width * 3 / 4, y + height * 3 / 4, width / 16);
    }
    else if (value == 4) {
        drawDot(x + width / 4, y + height / 4, width / 16);
        drawDot(x + width * 3 / 4, y + height / 4, width / 16);
        drawDot(x + width / 4, y + height * 3 / 4, width / 16);
        drawDot(x + width * 3 / 4, y + height * 3 / 4, width / 16);
    }
    else if (value == 5) {
        drawDot(x + width / 4, y + height / 4, width / 16);
        drawDot(x + width * 3 / 4, y + height / 4, width / 16);
        drawDot(x + width / 4, y + height * 3 / 4, width / 16);
        drawDot(x + width * 3 / 4, y + height * 3 / 4, width / 16);
        drawDot(x + width / 2, y + height / 2, width / 16);
    }
    else if (value == 6) {
        drawDot(x + width / 4, y + height / 4, width / 16);
        drawDot(x + width * 3 / 4, y + height / 4, width / 16);
        drawDot(x + width / 4, y + height / 2, width / 16);
        drawDot(x + width * 3 / 4, y + height / 2, width / 16);
        drawDot(x + width / 4, y + height * 3 / 4, width / 16);
        drawDot(x + width * 3 / 4, y + height * 3 / 4, width / 16);
    }
}
void drawTile(float x, float y, float width, float height, int left, int right) {
    glColor3f(0.8196f, 0.7804f, 0.7412f);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();

    glColor3f(0.1451f, 0.2157f, 0.2706f);
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();

    glLineWidth(1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y + height / 2);
    glVertex2f(x + width, y + height / 2);
    glEnd();

    drawHalfTile(x, y, width, height / 2, left);
    drawHalfTile(x, y + height / 2, width, height / 2, right);
}
void drawSelected(float x, float y) {
    glColor3f(0.1451f, 0.2157f, 0.2706f);
    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}
void drawPlayerHand(const Player* player) {
    Node* current = player->head;
    float x = 50, y = 50;
    while (current != NULL) {
        drawTile(x, y, width, height, current->tile.left, current->tile.right);
        x += width + 10;
        current = current->next;
    }
}
void drawBotHand(const Player* bot) {
    Node* current = bot->head;
    float x = 300, y = WINDOW_HEIGHT - height - 50;
    while (current != NULL) {
        glColor3f(0.7196f, 0.6804f, 0.6412f);
        glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
        glEnd();
        glColor3f(0.1451f, 0.2157f, 0.2706f);
        glLineWidth(3.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
        glEnd();

        x += width + 10;
        current = current->next;
    }
}
void drawField(const Field* field) {
    Node* current = field->head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    float x, y;
    if (height * count + 100 > WINDOW_WIDTH) {
        height = (WINDOW_WIDTH - 100) / count;
        width = height / 2;
    }
    x = WINDOW_WIDTH / 2 - count * height / 2;
    y = WINDOW_HEIGHT / 2 - height / 2;

    current = field->head;
    while (current != NULL) {
        if (current->tile.left == current->tile.right) {
            drawTile(x, y, width, height, current->tile.left, current->tile.right);
            x += width;
        }
        else {
            glPushMatrix();
            glTranslatef(x + width / 2, y + height / 2, 0.0f);
            glRotatef(270.0f, 0.0f, 0.0f, 1.0f);
            glTranslatef(-(x + width / 2), -(y + height / 4), 0.0f);
            drawTile(x, y, width, height, current->tile.left, current->tile.right);
            glPopMatrix();
            x += height;
        }
        current = current->next;
    }
    height = 150.0f;
    width = 75.0f;
}
void drawMenu() {
    glColor3f(0.2902f, 0.3608f, 0.4157f);
    glBegin(GL_QUADS);
    glVertex2f(WINDOW_WIDTH / 2 - BUTTON_WIDTH, WINDOW_HEIGHT / 2 - BUTTON_HEIGHT / 2);
    glVertex2f(WINDOW_WIDTH / 2 - BUTTON_WIDTH, WINDOW_HEIGHT / 2 + BUTTON_HEIGHT / 2);
    glVertex2f(WINDOW_WIDTH / 2 + BUTTON_WIDTH, WINDOW_HEIGHT / 2 + BUTTON_HEIGHT / 2);
    glVertex2f(WINDOW_WIDTH / 2 + BUTTON_WIDTH, WINDOW_HEIGHT / 2 - BUTTON_HEIGHT / 2);
    glEnd();
    glColor3f(0.1451f, 0.2157f, 0.2706f);
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(WINDOW_WIDTH / 2 - BUTTON_WIDTH, WINDOW_HEIGHT / 2 - BUTTON_HEIGHT / 2);
    glVertex2f(WINDOW_WIDTH / 2 - BUTTON_WIDTH, WINDOW_HEIGHT / 2 + BUTTON_HEIGHT / 2);
    glVertex2f(WINDOW_WIDTH / 2 + BUTTON_WIDTH, WINDOW_HEIGHT / 2 + BUTTON_HEIGHT / 2);
    glVertex2f(WINDOW_WIDTH / 2 + BUTTON_WIDTH, WINDOW_HEIGHT / 2 - BUTTON_HEIGHT / 2);
    glEnd();
    glColor3f(0.0667f, 0.1294f, 0.1765f);
    drawText("play", WINDOW_WIDTH / 2 - BUTTON_WIDTH * 3 / 5, WINDOW_HEIGHT / 2 - BUTTON_HEIGHT / 4, 100.0f);

    glColor3f(0.449f, 0.5098f, 0.5432f);
    glBegin(GL_QUADS);
    glVertex2f(50, BUTTONY);
    glVertex2f(50, BUTTONY + BUTTON_HEIGHT / 2);
    glVertex2f(50 + BUTTON_WIDTH, BUTTONY + BUTTON_HEIGHT / 2);
    glVertex2f(50 + BUTTON_WIDTH, BUTTONY);
    glEnd();
    glColor3f(0.1451f, 0.2157f, 0.2706f);
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(50, BUTTONY);
    glVertex2f(50, BUTTONY + BUTTON_HEIGHT / 2);
    glVertex2f(50 + BUTTON_WIDTH, BUTTONY + BUTTON_HEIGHT / 2);
    glVertex2f(50 + BUTTON_WIDTH, BUTTONY);
    glEnd();
    drawText("help", 90, BUTTONY + 25, 50.0f);

    glColor3f(0.449f, 0.5098f, 0.5432f);
    glBegin(GL_QUADS);
    glVertex2f(BUTTON_WIDTH + 80, BUTTONY);
    glVertex2f(BUTTON_WIDTH + 80, BUTTONY + BUTTON_HEIGHT / 2);
    glVertex2f(BUTTON_WIDTH + 80 + BUTTON_WIDTH * 3 / 2, BUTTONY + BUTTON_HEIGHT / 2);
    glVertex2f(BUTTON_WIDTH + 80 + BUTTON_WIDTH * 3 / 2, BUTTONY);
    glEnd();
    glColor3f(0.1451f, 0.2157f, 0.2706f);
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(BUTTON_WIDTH + 80, BUTTONY);
    glVertex2f(BUTTON_WIDTH + 80, BUTTONY + BUTTON_HEIGHT / 2);
    glVertex2f(BUTTON_WIDTH + 80 + BUTTON_WIDTH * 3 / 2, BUTTONY + BUTTON_HEIGHT / 2);
    glVertex2f(BUTTON_WIDTH + 80 + BUTTON_WIDTH * 3 / 2, BUTTONY);
    glEnd();
    drawText("records", BUTTON_WIDTH + 125, BUTTONY + 25, 50.0f);

    drawText("domino", 50, WINDOW_HEIGHT - 150, 100.0f);
    glColor3f(0.8196f, 0.7804f, 0.7412f);
    drawText("main menu", 50, WINDOW_HEIGHT - 250, 50.0f);
    char str[6];
    drawText(_itoa(balance, str, 10), WINDOW_WIDTH - 300, BUTTONY, 100.0f);
}
void drawHelp() {
    glColor3f(0.449f, 0.5098f, 0.5432f);
    glBegin(GL_QUADS);
    glVertex2f(0, 220);
    glVertex2f(0, 480);
    glVertex2f(WINDOW_WIDTH, 480);
    glVertex2f(WINDOW_WIDTH, 220);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(0, 880);
    glVertex2f(0, WINDOW_HEIGHT);
    glVertex2f(WINDOW_WIDTH, WINDOW_HEIGHT);
    glVertex2f(WINDOW_WIDTH, 880);
    glEnd();

    drawExitButton();

    glColor3f(0.1451f, 0.2157f, 0.2706f);
    drawText("the playing field is highlighted.to insert a domino into the right or left", 30, WINDOW_HEIGHT - 110, 40.0f);
    drawText("edge,click on the corresponding part of the field.", 30, WINDOW_HEIGHT - 180, 40.0f);

    drawText("if you have no possible moves,click on the bazaar button.if the domino", 30, WINDOW_HEIGHT - 300, 40.0f);
    drawText("does not fit in this case,you skip a move.if there are no dominoes left", 30, WINDOW_HEIGHT - 370, 40.0f);
    drawText("in the bazaar,you can skip a move by clicking on the miss button.the game", 30, WINDOW_HEIGHT - 440, 40.0f);
    drawText("ends when one of the players has laid out all the dominoes.he is the", 30, WINDOW_HEIGHT - 510, 40.0f);
    drawText("winner.", 30, WINDOW_HEIGHT - 580, 40.0f);

    drawText("when both players cannot make a move and there are no dominoes in the", 30, 400, 40.0f);
    drawText("bazaar,the player with the lowest sum of values on the remaining dominoes", 30, 330, 40.0f);
    drawText("wins.if the sums are equal,the player who made the last move first wins.", 30, 260, 40.0f);

    drawText("the winner is awarded points based on the sum of the values of the", 30, 140, 40.0f);
    drawText("remaining dominoes of opponent.these points are subtracted from the loser.", 30, 70, 40.0f);

}
void drawGame() {
    glColor3f(0.449f, 0.5098f, 0.5432f);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(0, FIELD_LOW);
    glVertex2f(WINDOW_WIDTH, FIELD_LOW);
    glVertex2f(WINDOW_WIDTH, 0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0, FIELD_UP);
    glVertex2f(0, WINDOW_HEIGHT);
    glVertex2f(WINDOW_WIDTH, WINDOW_HEIGHT);
    glVertex2f(WINDOW_WIDTH, FIELD_UP);
    glEnd();

    drawMissButton();
    drawButton();
    drawExitButton();
    glColor3f(0.1451f, 0.2157f, 0.2706f);
    drawText("bot", 50, WINDOW_HEIGHT - 150, 100.0f);
    drawPlayerHand(&player);
    drawBotHand(&bot);
    drawField(&playField);
    if (selectedTile != NULL) {
        drawSelected(selectedX, selectedY);
    }
}
void drawRecords() {
    glColor3f(0.449f, 0.5098f, 0.5432f);
    glBegin(GL_QUADS);
    glVertex2f(500, 300);
    glVertex2f(500, 740);
    glVertex2f(1400, 740);
    glVertex2f(1400, 300);
    glEnd();
    drawExitButton();

    if (result == win) {
        glColor3f(0.8196f, 0.7804f, 0.7412f);
        drawText("congratulations", WINDOW_WIDTH / 2 - 180, WINDOW_HEIGHT - 330, 40.0f);
        glColor3f(0.1451f, 0.2157f, 0.2706f);
        drawText("you won", WINDOW_WIDTH / 2 - 210, WINDOW_HEIGHT - 250, 100.0f);
    }
    else if (result == lose) {
        glColor3f(0.1451f, 0.2157f, 0.2706f);
        drawText("you lost", WINDOW_WIDTH / 2 - 230, WINDOW_HEIGHT - 300, 100.0f);
    }
    else {
        glColor3f(0.1451f, 0.2157f, 0.2706f);
        drawText("results of previous games", 150, WINDOW_HEIGHT - 280, 100.0f);
    }
    char str1[20], str2[25], str3[25], str4[30], str5[15];
    sprintf(str1, "balance  %d", balance);
    sprintf(str2, "count of victories  %d", victories);
    sprintf(str3, "count of games  %d", games);
    sprintf(str4, "percent of victories  %d%%", percent);
    sprintf(str5, "record  %d", record);
    drawText(str1, 580, 650, 50.0f);
    drawText(str2, 580, 570, 50.0f);
    drawText(str3, 580, 490, 50.0f);
    drawText(str4, 580, 410, 50.0f);
    drawText(str5, 580, 330, 50.0f);
}