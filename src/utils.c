#include <stdio.h>
#include <raylib.h>
#include "logic.h"
#include "settings.h"


int load_file(const char* filename, int(*grid)[GAME_WIDTH]){
    FILE *f = fopen(filename, "r");
    if (!f){
        TraceLog(LOG_INFO, TextFormat("File '%s' can not be loaded", filename));
        return -1;
    }
    
    clear_grid(grid);

    int x, y;
    while (fscanf(f, "%d %d", &x, &y) == 2){
        if (x >= 0 && x < GAME_WIDTH && y >= 0 && y < GAME_HEIGHT){
            grid[x][y] = 1;
        } 
    }
    fclose(f);

    TraceLog(LOG_INFO, TextFormat("File '%s' was successfully downloaded", filename));
    return 1;
}