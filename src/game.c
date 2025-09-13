#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include <style_amber.h>

#include "settings.h"
#include "graphics.h"
#include "logic.h"


typedef enum GameState{
    GAMEPLAY = 0,
    PAUSE
} GameState;

int main(void){
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game of life by Kaifarik");
    GuiLoadStyleAmber();
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
    SetTargetFPS(TARGET_FPS);

    GameState gameState = PAUSE;
    int grid[GAME_HEIGHT][GAME_WIDTH];
    int new_grid[GAME_HEIGHT][GAME_WIDTH];
    // Скорость обновления игры
    float game_speed = START_GAME_SPEED;
    float timer = 0.0f;

    clear_grid(grid);
    clear_grid(new_grid);
    
    // Кнопка "Start" - 1, кнопка "Stop" - 2
    int button_status = 2;
    DropboxStatus dropbox_status = {0, false};

    while (!WindowShouldClose()){
        // Обработка нажатий
        if (IsKeyPressed(KEY_UP)){
            game_speed += GAME_SPEED_STEP;
        } else if (IsKeyPressed(KEY_DOWN)){
            if (game_speed >= GAME_SPEED_STEP){
                game_speed -= GAME_SPEED_STEP;
            }
        }
        if (button_status == 1){
            gameState = GAMEPLAY;
        }
        if (button_status == 2){
            gameState = PAUSE;
        }
        
        // Обновление игры
        switch (gameState)
            {
            case GAMEPLAY:
                timer += GetFrameTime();
                if (timer >= game_speed) {
                    update(grid, new_grid);
                    timer = 0.0f;
                }
                break;
            case PAUSE:
                break;
            default:
                break;
            }
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            draw_game_board();
            draw_menu(&button_status, &dropbox_status, grid, game_speed);
            draw_alive_cells(grid);
        EndDrawing();
    }

    CloseWindow();
}