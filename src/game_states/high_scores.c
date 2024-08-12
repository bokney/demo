
#include <gb/gb.h>
#include <stdio.h>
#include "high_scores.h"
#include "../fade.h"

typedef struct _highScores {
    uint8_t count;
} highScoresData;

highScoresData high_scores_data;

void high_scores_init(void *data) {
    highScoresData *data_ptr = data;
    data_ptr->count = 0;
    fade_in();
}

uint8_t high_scores_iter(void *data) {
    highScoresData *data_ptr = data;

    return 0;
}

uint8_t high_scores_exit(void *data) {
    highScoresData *data_ptr = data;
    fade_out();
    return 1;
}
