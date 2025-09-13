#include <raylib.h>
#include "raygui.h"
#include "settings.h"
#include "graphics.h"
#include "utils.h"



void draw_game_board(){
    DrawRectangle(0, 0, SCREEN_HEIGHT, SCREEN_HEIGHT, BLACK);
    for (int i = 0; i < GAME_WIDTH; i++){
        DrawLine(i * CELL_SIZE, 0, i * CELL_SIZE, SCREEN_HEIGHT, DARKGRAY);
        DrawLine(0, i * CELL_SIZE, SCREEN_HEIGHT, i * CELL_SIZE, DARKGRAY);
    }
}

void draw_alive_cells(int (*grid)[GAME_WIDTH]){
    for (int row=0; row < GAME_WIDTH; row++){
        for (int col=0; col < GAME_HEIGHT; col++){
            if (grid[row][col] == 1){
                DrawRectangle(col * CELL_SIZE, row * CELL_SIZE, CELL_SIZE, CELL_SIZE, CELL_COLOR);
            }
        }
    }
}

void draw_menu(int* button_status, DropboxStatus* dropbox_status, int (*grid)[GAME_WIDTH], float game_speed){
    const char* example_files[] = {
        "assets/test1.txt", "assets/test2.txt", "assets/test3.txt", "assets/test4.txt", "assets/test5.txt"
    }; 

    DrawRectangle(600, 0, 250, 600, DARKGRAY);
    
    int clicked = 0;
    if (GuiButton((Rectangle){620, 20, 100, 50}, "Start")){
        clicked = 1;
    }
    if (GuiButton((Rectangle){730, 20, 100, 50}, "Stop")){
        clicked = 2;
    }
    if (clicked != 0){
        *button_status = clicked;
    }

    GuiLabel((Rectangle){620, 80, 150, 50}, TextFormat("Speed: %.2f seconds", game_speed));

    GuiLabel((Rectangle){620, 150, 100, 50}, "Examples");

    if (GuiDropdownBox((Rectangle){620, 200, 150, 50}, "Choose file;test_1;test_2;test_3;test_4;test_5", &(dropbox_status->active), dropbox_status->edit)){
        dropbox_status->edit = !dropbox_status->edit;

        if (dropbox_status->active > 0){
            // dropbox_status->active - 1 для того, чтобы не выйти за границы массива example_files
            const char* filename = example_files[dropbox_status->active - 1];
            load_file(filename, grid);
        }
    }
}