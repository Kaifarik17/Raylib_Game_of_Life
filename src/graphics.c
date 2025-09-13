#include <raylib.h>
#include "raygui.h"
#include "settings.h"


void draw_game_board(){
    DrawRectangle(0, 0, SCREEN_HEIGHT, SCREEN_HEIGHT, BLACK);
    // Отрисовка вертикальной и горизонтальной сетки
    for (int i = 0; i < GAME_WIDTH; i++){
        DrawLine(i * CELL_SIZE, 0, i * CELL_SIZE, SCREEN_HEIGHT, DARKGRAY);
        DrawLine(0, i * CELL_SIZE, SCREEN_HEIGHT, i * CELL_SIZE, DARKGRAY);
    }
}

void draw_menu(int* button_status){
    DrawRectangle(600, 0, 250, 600, DARKGRAY);
    if (*button_status == 0){
        if (GuiButton((Rectangle){620, 20, 100, 50}, "Start")){
            *button_status = 1;
        }
    } else {
        if (GuiButton((Rectangle){620, 20, 100, 50}, "Restart")){
            *button_status = 0;
        }
    }

    if (GuiButton((Rectangle){730, 20, 100, 50}, "Stop")){

    }
    GuiLabel((Rectangle){620, 80, 100, 50}, "Speed");
    GuiLabel((Rectangle){670, 80, 100, 50}, "100");
}