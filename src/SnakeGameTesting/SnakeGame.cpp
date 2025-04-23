#include "SnakeGame.h"

SnakeGame::SnakeGame() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void SnakeGame::Draw() {
    clear();
    for (int i = 0; i < width + 2; i++)
        printw("#");
    printw("\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                printw("#");
            if (i == y && j == x)
                printw("O");
            else if (i == fruitY && j == fruitX)
                printw("F");
            else {
                bool print = false;
                for (auto segment : tail) {
                    if (segment.first == j && segment.second == i) {
                        printw("o");
                        print = true;
                    }
                }
                if (!print)
                    printw(" ");
            }
            if (j == width - 1)
                printw("#");
        }
        printw("\n");
    }

    for (int i = 0; i < width + 2; i++)
        printw("#");
    printw("\n");

    printw("Score: %d\n", score);
    refresh();
}

void SnakeGame::Input() {
    nodelay(stdscr, TRUE);
    int ch = getch();
    switch (ch) {
    case 'a':
        dir = LEFT;
        break;
    case 'd':
        dir = RIGHT;
        break;
    case 'w':
        dir = UP;
        break;
    case 's':
        dir = DOWN;
        break;
    case 'x':
        gameOver = true;
        break;
    }
}

void SnakeGame::Logic() {
    pair<int, int> prev = {x, y};
    pair<int, int> prev2;
    for (size_t i = 0; i < tail.size(); i++) {
        prev2 = tail[i];
        tail[i] = prev;
        prev = prev2;
    }

    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    for (auto segment : tail) {
        if (segment.first == x && segment.second == y) {
            gameOver = true;
        }
    }

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        tail.push_back({-1, -1});
    }
}

void SnakeGame::Run() {
    initscr();
    noecho();
    cbreak();

    while (!gameOver) {
        Draw();
        Input();
        Logic();
        usleep(100000); // Sleep for 100ms
    }

    endwin();
}