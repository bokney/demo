
#include "page_01.h"

typedef struct _page01Data {
    uint8_t count;
} page01Data;

page01Data page_01_data;

void page_01_init(void) {
    page_01_data.count = 0;
}

uint8_t page_01_iter(void) {
    page_01_data.count += 1;
    return 0;
}

uint8_t page_01_exit(void) {
    return 0;
}
