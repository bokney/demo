
#include <gb/gb.h>

typedef struct _splashData {
    char *text;
    uint8_t count;
} splashData;

extern splashData splash;

void splash_init(void *data);
uint8_t splash_iter(void *data);
uint8_t splash_exit(void *data);
