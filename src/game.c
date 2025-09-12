#include <raylib.h>

int main(void){
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Game of life by Kaifarik");

    SetTargetFPS(60);

    while (!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Test window", 350, 200, 32, BLACK);
        EndDrawing();
    }

    CloseWindow();
}