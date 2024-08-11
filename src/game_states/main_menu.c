
#include <gb/gb.h>
#include <stdio.h>
#include "main_menu.h"

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
    return 0;
}

uint8_t main_menu_exit(void *data) {
    printf("main_menu_exit\n");
    return 1;
}
