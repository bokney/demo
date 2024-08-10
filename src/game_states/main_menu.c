
#include <gb/gb.h>
#include <stdio.h>
#include "main_menu.h"

// state mainMenuState;
mainMenuData mainMenu;

void main_menu_init(void *data) {
    printf("main_menu_init\n");
    mainMenuData *mmd = data;
    mmd->text = "MAIN MENU TIME!!\n";
    mmd->count = 0;
}

uint8_t main_menu_iter(void *data) {
    printf("main_menu_iter\n");
    mainMenuData *mmd = data;
    printf(mmd->text);
    printf("Count: %u\n", mmd->count);
    mmd->count += 1;
    if (mmd->count > 4) {
        return 1;
    }
    delay(480);
    return 0;
}

uint8_t main_menu_exit(void *data) {
    printf("main_menu_exit\n");
    return 0;
}

// state *create_main_menu(void) {
//     mainMenuState.init = main_menu_init;
//     mainMenuState.iter = main_menu_iter;
//     mainMenuState.exit = main_menu_exit;
//     mainMenuState.data = &mainMenu;
//     return &mainMenuState;
// }
