
#include "page_02.h"

typedef struct _page02Data {
    uint8_t count;
} page02Data;

page02Data page_02_data;

void page_02_init(void) {
    page_02_data.count = 0;
}

uint8_t page_02_iter(void) {
    page_02_data.count += 1;
    return 0;
}

uint8_t page_02_exit(void) {
    return 0;
}
