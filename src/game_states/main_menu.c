
#include "main_menu.h"

typedef struct _mainMenuData {
    uint8_t count;
} mainMenuData;

mainMenuData main_menu_data;

void main_menu_init(void) {
    main_menu_data.count = 0;
}

uint8_t main_menu_iter(void) {
    main_menu_data.count += 1;
    return 0;
}

uint8_t main_menu_exit(void) {
    return 0;
}
