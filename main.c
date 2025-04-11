#include "globals.h"
#include "graphics.h"

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double mouseX, mouseY;
        glfwGetCursorPos(window, &mouseX, &mouseY);
        mouseY = WINDOW_HEIGHT - mouseY;

        if (currentState == menu) {
            if (mouseX >= WINDOW_WIDTH / 2 - BUTTON_WIDTH && mouseX <= WINDOW_WIDTH / 2 + BUTTON_WIDTH &&
                mouseY >= WINDOW_HEIGHT / 2 - BUTTON_HEIGHT / 2 && mouseY <= WINDOW_HEIGHT / 2 + BUTTON_HEIGHT / 2) {
                set = (DominoTile*)malloc(sizeof(DominoTile) * 28);
                InitialSet(&player, &bot, &playField, set, &tileCount);
                currentState = game;
                if (games % 2) {
                    glClear(GL_COLOR_BUFFER_BIT);
                    drawGame();
                    glfwSwapBuffers(window);
                    
                    delay(1);
                    chooseMove(&bot, &playField, 0);
                }
            }
            else if (mouseX >= BUTTON_WIDTH + 80 && mouseX <= BUTTON_WIDTH + 80 + BUTTON_WIDTH * 3 / 2 &&
                mouseY >= BUTTONY && mouseY <= BUTTONY + BUTTON_HEIGHT / 2) {
                result = intermediate;
                currentState = records;
            }
            else if (mouseX >= 50 && mouseX <= 50 + BUTTON_WIDTH &&
                mouseY >= BUTTONY && mouseY <= BUTTONY + BUTTON_HEIGHT / 2) {
                currentState = help;
            }
        }
        else if (currentState == game) {
            if (mouseX >= BUTTONX && mouseX <= BUTTONX + BUTTON_WIDTH &&
                mouseY >= BUTTONY && mouseY <= BUTTONY + BUTTON_HEIGHT && noSolutions(&player, &playField)) {
                selectedTile = NULL;
                dealTiles(&player, set, &tileCount, 1);

                if (!match(&(player.head->tile), playField.head->tile.left) && !match(&(player.head->tile), playField.tail->tile.right)) {
                    glClear(GL_COLOR_BUFFER_BIT);
                    drawGame();
                    glfwSwapBuffers(window);

                    delay(1);
                    int botRes = chooseMove(&bot, &playField, 0);
                    if (bot.head == NULL) {
                        glClear(GL_COLOR_BUFFER_BIT);
                        drawGame();
                        glfwSwapBuffers(window);
                        delay(1);
                        result = lose;
                        endOfGame(&player, result, &currentState);
                    }
                    else {
                        if (!botRes && noSolutions(&player, &playField) && tileCount == 0) {
                            int Winner = comparePoints(&player, &bot);
                            if (Winner > 0) {
                                glClear(GL_COLOR_BUFFER_BIT);
                                drawGame();
                                glfwSwapBuffers(window);
                                delay(1);
                                result = lose;
                                endOfGame(&player, result, &currentState);
                            }
                            else if (Winner <= 0) {
                                glClear(GL_COLOR_BUFFER_BIT);
                                drawGame();
                                glfwSwapBuffers(window);
                                delay(1);
                                result = win;
                                endOfGame(&bot, result, &currentState);
                            }
                        }
                    }
                }
            }
            else if (mouseX >= BUTTONX - 70 && mouseX <= BUTTONX - 20 &&
                mouseY >= BUTTONY && mouseY <= BUTTONY + BUTTON_HEIGHT &&
                tileCount == 0 && noSolutions(&player, &playField)) {
                glClear(GL_COLOR_BUFFER_BIT);
                drawGame();
                glfwSwapBuffers(window);

                delay(1);
                int botRes = chooseMove(&bot, &playField, 0);
                if (bot.head == NULL) {
                    glClear(GL_COLOR_BUFFER_BIT);
                    drawGame();
                    glfwSwapBuffers(window);
                    delay(1);
                    result = lose;
                    endOfGame(&player, result, &currentState);
                }
                else {
                    if (!botRes && noSolutions(&player, &playField) && tileCount == 0) {
                        int Winner = comparePoints(&player, &bot);
                        if (Winner > 0) {
                            glClear(GL_COLOR_BUFFER_BIT);
                            drawGame();
                            glfwSwapBuffers(window);
                            delay(1);
                            result = lose;
                            endOfGame(&player, result, &currentState);
                        }
                        else if (Winner <= 0) {
                            glClear(GL_COLOR_BUFFER_BIT);
                            drawGame();
                            glfwSwapBuffers(window);
                            delay(1);
                            result = win;
                            endOfGame(&bot, result, &currentState);
                        }
                    }
                }
            }
            else if (mouseX >= WINDOW_WIDTH - 50 && mouseX <= WINDOW_WIDTH &&
                mouseY >= WINDOW_HEIGHT - 50 && mouseY <= WINDOW_HEIGHT) {
                currentState = menu;
                if (set != NULL) {
                    freeGame(set, &player, &bot, &playField);
                    set = NULL;
                }
            }
            else {
                Node* current = player.head;
                float x = 50, y = 50;
                while (current != NULL) {
                    if (mouseX >= x && mouseX <= x + width &&
                        mouseY >= y && mouseY <= y + height) {
                        selectedTile = current;
                        selectedX = x;
                        selectedY = y;
                        break;
                    }
                    x += width + 10;
                    current = current->next;
                }
                if (selectedTile != NULL) {
                    if (mouseX < WINDOW_WIDTH / 2 && mouseY >= FIELD_LOW && mouseY <= FIELD_UP) {
                        if (match(&(selectedTile->tile), playField.head->tile.left)) {
                            if (selectedTile->next != NULL) {
                                selectedTile->next->prev = selectedTile->prev;
                            }
                            else {
                                player.tail = selectedTile->prev;
                            }
                            if (selectedTile->prev != NULL) {
                                selectedTile->prev->next = selectedTile->next;
                            }
                            else {
                                player.head = selectedTile->next;
                            }

                            if (playField.head->tile.left != selectedTile->tile.right) {
                                swap(&(selectedTile->tile));
                            }
                            playField.head->prev = selectedTile;
                            selectedTile->next = playField.head;
                            selectedTile->prev = NULL;
                            playField.head = selectedTile;

                            selectedTile = NULL;

                            if (player.head == NULL) {
                                glClear(GL_COLOR_BUFFER_BIT);
                                drawGame();
                                glfwSwapBuffers(window);
                                delay(1);
                                result = win;
                                endOfGame(&bot, result, &currentState);
                                return;
                            }

                            glClear(GL_COLOR_BUFFER_BIT);
                            drawGame();
                            glfwSwapBuffers(window);

                            delay(1);
                            int botRes = chooseMove(&bot, &playField, 0);
                            if (bot.head == NULL) {
                                glClear(GL_COLOR_BUFFER_BIT);
                                drawGame();
                                glfwSwapBuffers(window);
                                delay(1);
                                result = lose;
                                endOfGame(&player, result, &currentState);
                            }
                            else {
                                if (!botRes && noSolutions(&player, &playField) && tileCount == 0) {
                                    int Winner = comparePoints(&player, &bot);
                                    if (Winner >= 0) {
                                        glClear(GL_COLOR_BUFFER_BIT);
                                        drawGame();
                                        glfwSwapBuffers(window);
                                        delay(1);
                                        result = lose;
                                        endOfGame(&player, result, &currentState);
                                    }
                                    else if (Winner < 0) {
                                        glClear(GL_COLOR_BUFFER_BIT);
                                        drawGame();
                                        glfwSwapBuffers(window);
                                        delay(1);
                                        result = win;
                                        endOfGame(&bot, result, &currentState);
                                    }
                                }
                            }
                        }
                    }
                    else if (mouseX > WINDOW_WIDTH / 2 && mouseY >= FIELD_LOW && mouseY <= FIELD_UP) {
                        if (match(&(selectedTile->tile), playField.tail->tile.right)) {
                            if (selectedTile->next != NULL) {
                                selectedTile->next->prev = selectedTile->prev;
                            }
                            else {
                                player.tail = selectedTile->prev;
                            }
                            if (selectedTile->prev != NULL) {
                                selectedTile->prev->next = selectedTile->next;
                            }
                            else {
                                player.head = selectedTile->next;
                            }

                            if (playField.tail->tile.right != selectedTile->tile.left) {
                                swap(&(selectedTile->tile));
                            }
                            playField.tail->next = selectedTile;
                            selectedTile->prev = playField.tail;
                            selectedTile->next = NULL;
                            playField.tail = selectedTile;

                            selectedTile = NULL;

                            if (player.head == NULL) {
                                glClear(GL_COLOR_BUFFER_BIT);
                                drawGame();
                                glfwSwapBuffers(window);
                                delay(1);
                                result = win;
                                endOfGame(&bot, result, &currentState);
                                return;
                            }

                            glClear(GL_COLOR_BUFFER_BIT);
                            drawGame();
                            glfwSwapBuffers(window);

                            delay(1);
                            int botRes = chooseMove(&bot, &playField, 0);
                            if (bot.head == NULL) {
                                glClear(GL_COLOR_BUFFER_BIT);
                                drawGame();
                                glfwSwapBuffers(window);
                                delay(1);
                                result = lose;
                                endOfGame(&player, result, &currentState);
                            }
                            else {
                                if (!botRes && noSolutions(&player, &playField) && tileCount == 0) {
                                    int Winner = comparePoints(&player, &bot);
                                    if (Winner >= 0) {
                                        delay(1);
                                        result = lose;
                                        endOfGame(&player, result, &currentState);
                                    }
                                    else if (Winner < 0) {
                                        delay(1);
                                        result = win;
                                        endOfGame(&bot, result, &currentState);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        else if (currentState == help) {
            if (mouseX >= WINDOW_WIDTH - 50 && mouseX <= WINDOW_WIDTH &&
                mouseY >= WINDOW_HEIGHT - 50 && mouseY <= WINDOW_HEIGHT) {
                currentState = menu;
            }
        }
        else if (currentState == records) {
            if (mouseX >= WINDOW_WIDTH - 50 && mouseX <= WINDOW_WIDTH &&
                mouseY >= WINDOW_HEIGHT - 50 && mouseY <= WINDOW_HEIGHT) {
                currentState = menu;
            }
        }
    }
}

int main() {
    if (!glfwInit()) {
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Domino", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glClearColor(0.6078f, 0.6588f, 0.6706f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    fileData();

    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        if (currentState == menu) {
            drawMenu();
        }
        else if (currentState == game) {
            drawGame();
        }
        else if (currentState == help) {
            drawHelp();
        }
        else if (currentState == records) {
            drawRecords();
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    if (set != NULL) {
        freeGame(set, &player, &bot, &playField);
        set = NULL;
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}