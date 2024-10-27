
#include "page_03.h"

typedef struct _page03Data {
    uint8_t count;
} page03Data;

page03Data page_03_data;

void page_03_init(void) {
    page_03_data.count = 0;
}

uint8_t page_03_iter(void) {
    page_03_data.count += 1;
    return 0;
}

uint8_t page_03_exit(void) {
    return 0;
}
