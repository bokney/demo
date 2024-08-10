
#include <gb/gb.h>
// #include "../stateManager.h"

typedef struct _mainMenuData {
    char *text;
    uint8_t count;
} mainMenuData;

extern mainMenuData mainMenu;

void main_menu_init(void *data);
uint8_t main_menu_iter(void *data);
uint8_t main_menu_exit(void *data);

// state *create_main_menu(void);