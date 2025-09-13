#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include <style_amber.h>

#include "settings.h"
#include "graphics.h"

typedef enum GameState{
    GAMEPLAY = 0,
    PAUSE
} GameState;


int main(void){
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game of life by Kaifarik");
    GuiLoadStyleAmber();
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20); 
    SetTargetFPS(60);

    GameState gameState = GAMEPLAY;
    int button_status = 0;

    while (!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(RAYWHITE);
            draw_game_board();
            draw_menu(&button_status);
        EndDrawing();
    }

    CloseWindow();
}