#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 25
#define HEIGHT 25
#define BACKGROUND '-'
#define CELL '#'
#define SPEED 200

typedef enum {
    DEAD, 
    ALIVE
} State;

typedef struct {
    State state;
} Cell;

Cell grid[WIDTH][HEIGHT] = {0};

void initGrid() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            grid[i][j].state = DEAD;
        }
    }
}

int printGrid() {
    int aliveCount = 0;
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (grid[i][j].state == DEAD) {
                printf("%c", BACKGROUND);
            } else {
                aliveCount++;
                printf("%c", CELL);
            }
        }
        printf("\n");
    }
    return aliveCount;
}

void genNext() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            int aliveNeighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 && l == 0) continue;
                    if (i + k >= 0 && i + k < WIDTH && j + l >= 0 && j + l < HEIGHT) {
                        if (grid[i + l][j + k].state == ALIVE) {
                            aliveNeighbors += 1 ;
                        }
                    }
                }
            }
            switch (aliveNeighbors) {
                case 0: 
                    grid[i][j].state = DEAD;
                    break;
                case 1:
                    grid[i][j].state = DEAD;
                    break;
                case 2: break;
                case 3: 
                    grid[i][j].state = ALIVE;
                    break;
                default:
                    grid[i][j].state = DEAD;
                    break;
            }
        }
    }
}

int main() {
    initGrid();
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j].state = ALIVE;
        }
    }
    while (printGrid() > 0) {
        usleep(SPEED * 1000);
        system("clear");
        genNext();
    }
    return 0;
}