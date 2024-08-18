
#include <gb/gb.h>
#include <stdio.h>
#include "splash.h"
#include "../fade.h"

extern uint8_t basic_tiles;

typedef struct _splashData {
    char *text;
    uint8_t count;
    uint8_t bgk_tile_offset;
} splashData;

splashData splash_data;

void splash_init(void *data) {
    splashData *data_ptr = data;
    data_ptr->text = "Hello from splashData!!\n";
    data_ptr->count = 0;
    data_ptr->bgk_tile_offset = 96;

    set_bkg_data(data_ptr->bgk_tile_offset, 0, &basic_tiles);
    HIDE_BKG;
    init_bkg(5);
    SHOW_BKG;
    fade_in();
}

uint8_t splash_iter(void *data) {
    splashData *data_ptr = data;    
    data_ptr->count += 1;
    HIDE_BKG;
    init_bkg(data_ptr->bgk_tile_offset + 5 + data_ptr->count);
    SHOW_BKG;
    if (data_ptr->count > 4) {
        return 1;
    }
    return 0;
}

uint8_t splash_exit(void *data) {
    fade_out();
    return 2;
}
