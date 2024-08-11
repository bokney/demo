
#include <gb/gb.h>
#include <stdio.h>
#include "splash.h"

extern uint8_t basic_tiles;

typedef struct _splashData {
    char *text;
    uint8_t count;
} splashData;

splashData splash_data;

void splash_init(void *data) {
    splashData *data_ptr = data;
    data_ptr->text = "Hello from splashData!!\n";
    data_ptr->count = 0;

    set_bkg_data(0, 0, &basic_tiles);
    init_bkg(5);
}

uint8_t splash_iter(void *data) {
    splashData *data_ptr = data;    
    data_ptr->count += 1;
    init_bkg(5 + data_ptr->count);
    if (data_ptr->count > 4) {
        return 1;
    }
    return 0;
}

uint8_t splash_exit(void *data) {
    return 2;
}
