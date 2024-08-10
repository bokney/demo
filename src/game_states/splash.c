
#include <gb/gb.h>
#include <stdio.h>
#include "splash.h"

splashData splash;

void splash_init(void *data) {
    printf("splash_init\n");
    splashData *sd = data;
    sd->text = "Hello from splashData!!\n";
    sd->count = 0;
}

uint8_t splash_iter(void *data) {
    printf("splash_iter\n");
    splashData *sd = data;
    printf(sd->text);
    printf("Count: %u\n", sd->count);
    sd->count += 1;
    if (sd->count > 4) {
        return 1;
    }
    return 0;
}

uint8_t splash_exit(void *data) {
    printf("splash_exit\n");
    return 1;
}

