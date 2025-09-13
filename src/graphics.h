#ifndef GRAPHICS_H
#define GRAPHICS_H


typedef struct DropboxStatus{
    int active;
    bool edit;
} DropboxStatus;

void draw_game_board();
void draw_menu(int* button_status, DropboxStatus* dropbox_status, int (*grid)[GAME_WIDTH], float game_speed);
void draw_alive_cells(int (*grid)[GAME_WIDTH]);

#endif