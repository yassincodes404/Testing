#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <vector>

using namespace std;

class SnakeGame {
private:
    bool gameOver;
    const int width = 20;
    const int height = 20;
    int x, y, fruitX, fruitY, score;
    enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
    Direction dir;
    vector<pair<int, int>> tail;

    void Draw();
    void Input();
    void Logic();

public:
    SnakeGame();
    void Run();
};

#endif