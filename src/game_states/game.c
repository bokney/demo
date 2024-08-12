
#include <gb/gb.h>
#include <stdio.h>
#include "game.h"
#include "../fade.h"

typedef struct _game {
    uint8_t count;
} gameData;

gameData game_data;

void game_init(void *data) {
    gameData *data_ptr = data;
    data_ptr->count = 0;
    fade_in();
}

uint8_t game_iter(void *data) {
    gameData *data_ptr = data;

    return 0;
}

uint8_t game_exit(void *data) {
    gameData *data_ptr = data;
    fade_out();
    return 1;
}
