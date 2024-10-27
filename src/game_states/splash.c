
#include <stdio.h>
#include "splash.h"

typedef struct _splashData {
    uint8_t count;
} splashData;

splashData splash_data;

void splash_init(void) {
    splash_data.count = 0;
    printf("Splash Init\n");
}

uint8_t splash_iter(void) {
    printf("Splash Iter %i\n", splash_data.count);
    splash_data.count += 1;
    if (splash_data.count > 8)
        return 1;
    return 0;
}

uint8_t splash_exit(void) {
    printf("Splash Exit\n");
    return 0;
}

