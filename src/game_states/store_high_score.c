
#include <gb/gb.h>
#include <stdio.h>
#include "store_high_score.h"
#include "../fade.h"

typedef struct _storeHighScore {
    uint8_t count;
} storeHighScoreData;

storeHighScoreData store_high_score_data;

void store_high_score_init(void *data) {
    storeHighScoreData *data_ptr = data;
    data_ptr->count = 0;
    fade_in();
}

uint8_t store_high_score_iter(void *data) {
    storeHighScoreData *data_ptr = data;

    return 0;
}

uint8_t store_high_score_exit(void *data) {
    storeHighScoreData *data_ptr = data;
    fade_out();
    return 1;
}
