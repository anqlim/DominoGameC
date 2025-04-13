#include "globals.h"
#include "domino.h"

void freePlayer(Node* tail) {
    if (tail == NULL)
        return;
    Node* prev = tail->prev;
    free(tail);
    freePlayer(prev);
}
void freeGame(DominoTile* set, Player* player, Player* bot, Field* field) {
    freePlayer(player->tail);
    player->head = NULL;
    player->tail = NULL;
    freePlayer(bot->tail);
    bot->head = NULL;
    bot->tail = NULL;
    freePlayer(field->tail);
    field->head = NULL;
    field->tail = NULL;
    free(set);
}
void fileData() {
    FILE* file = fopen("records.txt", "r");
    fscanf(file, "%d", &balance);
    fscanf(file, "%d", &victories);
    fscanf(file, "%d", &games);
    fscanf(file, "%d", &record);
    percent = (int)(((float)victories / games) * 100);
    fclose(file);
}
void delay(int sec) {
    clock_t start = clock();
    while ((clock() - start) / CLOCKS_PER_SEC < sec);
}
void addTile(Player* player, const DominoTile* tile) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return;
    }

    newNode->tile = *tile;
    newNode->prev = NULL;
    newNode->next = player->head;

    if (player->head == NULL) {
        player->head = newNode;
        player->tail = newNode;
    }
    else {
        player->head->prev = newNode;
        player->head = newNode;
    }
}
void deleteTile(Player* player, Node* tile) {
    if (tile->prev != NULL) {
        tile->prev->next = tile->next;
    }
    else {
        player->head = tile->next;
    }
    if (tile->next != NULL) {
        tile->next->prev = tile->prev;
    }
    else {
        player->tail = tile->prev;
    }
    free(tile);
}
void createFullSet(DominoTile* tiles, int* count) {
    int index = 0;
    for (int i = 0; i <= 6; i++) {
        for (int j = i; j <= 6; j++) {
            tiles[index].left = i;
            tiles[index].right = j;
            index++;
        }
    }
    *count = index;
}
void shuffleTiles(DominoTile* tiles, int count) {
    for (int i = count - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        DominoTile temp = tiles[i];
        tiles[i] = tiles[j];
        tiles[j] = temp;
    }
}
void dealTiles(Player* player, DominoTile* tiles, int* count, int numTiles) {
    for (int i = 0; i < numTiles && *count > 0; i++) {
        addTile(player, &tiles[*count - 1]);
        (*count)--;
    }
}
void InitialSet(Player* player, Player* bot, Field* field, DominoTile* tiles, int* tileCount) {
    srand(time(NULL));

    createFullSet(tiles, tileCount);
    shuffleTiles(tiles, *tileCount);
    dealTiles(player, tiles, tileCount, 7);
    dealTiles(bot, tiles, tileCount, 7);
    dealTiles(field, tiles, tileCount, 1);
}
void swap(DominoTile* tile) {
    int t = tile->left;
    tile->left = tile->right;
    tile->right = t;
}
int match(DominoTile* tile, int val) {
    return tile->left == val || tile->right == val;
}
void transfer(Player* bot, Field* field, Node* current) {
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    else {
        bot->tail = current->prev;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    else {
        bot->head = current->next;
    }
    if (match(&(current->tile), field->head->tile.left)) {
        if (field->head->tile.left != current->tile.right) {
            swap(&(current->tile));
        }
        field->head->prev = current;
        current->next = field->head;
        current->prev = NULL;
        field->head = current;
    }
    else {
        if (field->tail->tile.right != current->tile.left) {
            swap(&(current->tile));
        }
        field->tail->next = current;
        current->prev = field->tail;
        current->next = NULL;
        field->tail = current;
    }
}
int chooseMove(Player* bot, Field* field, int flag) {
    Node* current = bot->head;
    Node* moves[20];
    int countMoves = 0;
    int values[7][3] = { {0, 0, 0} }; //0 - среди решений; 1 - на поле; 2 - в наборе
    while (current != NULL) {
        values[current->tile.left][2]++;
        values[current->tile.right][2]++;
        if (match(&(current->tile), field->head->tile.left) || match(&(current->tile), field->tail->tile.right)) {
            moves[countMoves++] = current;
            values[current->tile.left][0]++;
            values[current->tile.right][0]++;
        }
        current = current->next;
    }

    if (countMoves == 0) {
        if (tileCount != 0 && !flag) {
            dealTiles(bot, set, &tileCount, 1);
            if (match(&(bot->head->tile), field->head->tile.left) || match(&(bot->head->tile), field->head->tile.right)) {
                return chooseMove(bot, field, 1);
            }
            else return 0; //не сделал ход
        }
        else return 0; //не сделал ход
    }

    //1. дубли
    DominoTile bestDouble = { -1, -1 };
    Node* best = NULL;
    for (int i = 0; i < countMoves; i++) {
        if (moves[i]->tile.left == moves[i]->tile.right && moves[i]->tile.left > bestDouble.left) {
            bestDouble = moves[i]->tile;
            best = moves[i];
        }
    }
    if (bestDouble.left != -1) {
        transfer(bot, field, best);
        return 1; //сделал ход
    }

    //2. минимизация "закрытых" чисел
    current = field->head;
    while (current != NULL) {
        values[current->tile.left][1]++;
        values[current->tile.right][1]++;
        current = current->next;
    }

    best = NULL;
    int val = -1;
    for (int i = 0; i < countMoves; i++) {
        if (values[moves[i]->tile.left][0] == 1 && values[moves[i]->tile.left][1] == 6) {
            if (moves[i]->tile.left > val) {
                best = moves[i];
                val = moves[i]->tile.left;
            }
        }
        if (values[moves[i]->tile.right][0] == 1 && values[moves[i]->tile.right][1] == 6) {
            if (moves[i]->tile.right > val) {
                best = moves[i];
                val = moves[i]->tile.right;
            }
        }
    }
    if (val != -1) {
        current = best;
        transfer(bot, field, best);
        return 1; //сделал ход
    }

    //3. избавление от наиболее повторяющихся
    best = moves[0];
    int left = moves[0]->tile.left, right = moves[0]->tile.right;
    for (int i = 1; i < countMoves; i++) {
        if (values[moves[i]->tile.left][2] + values[moves[i]->tile.right][2] > values[left][2] + values[right][2] ||
            values[moves[i]->tile.left][2] + values[moves[i]->tile.right][2] == values[left][2] + values[right][2] &&
            moves[i]->tile.left + moves[i]->tile.right > left + right) {
            best = moves[i];
            left = moves[i]->tile.left;
            right = moves[i]->tile.right;
        }
    }
    transfer(bot, field, best);
    return 1; //сделал ход
}
int noSolutions(Player* player, Field* field) {
    Node* current = player->head;
    while (current != NULL) {
        if (match(&(current->tile), field->head->tile.left) || match(&(current->tile), field->tail->tile.right)) {
            return 0;
        }
        current = current->next;
    }
    return 1;
}
void endOfGame(Player* loser, gameResult result, state* currentState) {
    int points = 0;
    Node* current = loser->head;
    while (current != NULL) {
        points += current->tile.left;
        points += current->tile.right;
        current = current->next;
    }
    games++;
    if (result == win) {
        victories++;
        balance += points;
        record = (record > points) ? record : points;
    }
    else {
        balance -= points;
    }
    percent = (int)(((float)victories / games) * 100);
    FILE* file = fopen("records.txt", "w");
    fprintf(file, "%d\n%d\n%d\n%d", balance, victories, games, record);
    fclose(file);
    freeGame(set, &player, &bot, &playField);
    set = NULL;
    *currentState = records;
}
int comparePoints(Player* player, Player* bot) {
    int sumP = 0, sumB = 0;
    Node* current = player->head;
    while (current != NULL) {
        sumP += current->tile.left + current->tile.right;
        current = current->next;
    }
    current = bot->head;
    while (current != NULL) {
        sumB += current->tile.left + current->tile.right;
        current = current->next;
    }

    return sumP - sumB;
}
