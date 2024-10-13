
#include <stdio.h>
#include "splash.h"

typedef struct _splashData {
    uint8_t count;
} splashData;

splashData splash_data;

void splash_init(void) {
    splash_data.count = 0;
    printf("hello!\n");
}

uint8_t splash_iter(void) {
    splash_data.count += 1;
    return 0;
}

uint8_t splash_exit(void) {
    printf("goodbye!\n");
    return 1;
}
