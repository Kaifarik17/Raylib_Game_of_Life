#include "settings.h"

void update(int (*grid)[GAME_WIDTH], int (*new_grid)[GAME_WIDTH]);
void clear_grid(int (*grid)[GAME_WIDTH]);
void clone_array(int (*grid)[GAME_WIDTH], int (*new_grid)[GAME_WIDTH]);
int count_neighbors(int (*grid)[GAME_WIDTH], int row, int col);


void clear_grid(int (*grid)[GAME_WIDTH]) {
    for (int row = 0; row < GAME_HEIGHT; row++) {
        for (int col = 0; col < GAME_WIDTH; col++) {
            grid[row][col] = 0;
        }
    }
}

void update(int (*grid)[GAME_WIDTH], int (*new_grid)[GAME_WIDTH]) {
    for (int row = 0; row < GAME_HEIGHT; row++) {
        for (int col = 0; col < GAME_WIDTH; col++) {
            int count = count_neighbors(grid, row, col);
            if (grid[row][col] == 1) {
                if (count < 2 || count > 3) {
                    new_grid[row][col] = 0;
                } else {
                    new_grid[row][col] = 1;
                }
            } else {
                if (count == 3) {
                    new_grid[row][col] = 1;
                } else {
                    new_grid[row][col] = 0;
                }
            }
        }
    }
    clone_array(grid, new_grid);
}

void clone_array(int (*grid)[GAME_WIDTH], int (*new_grid)[GAME_WIDTH]) {
    for (int row = 0; row < GAME_HEIGHT; row++) {
        for (int col = 0; col < GAME_WIDTH; col++) {
            grid[row][col] = new_grid[row][col];
        }
    }
}

int count_neighbors(int (*grid)[GAME_WIDTH], int row, int col) {
    int count = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int neighbor_row = (row + i + GAME_HEIGHT) % GAME_HEIGHT;
            int neighbor_col = (col + j + GAME_WIDTH) % GAME_WIDTH;
            count += grid[neighbor_row][neighbor_col];
        }
    }
    return count;
}