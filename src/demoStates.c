
#include <gb/gb.h>
#include <stdio.h>
#include "demoStates.h"

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
    sd->count += 1;
    if (sd->count > 4) {
        return 1;
    }
    delay(160);
    return 0;
}

void splash_exit(void *data) {
    printf("splash_exit\n");
}

