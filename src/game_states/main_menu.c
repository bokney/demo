
#include <gb/gb.h>
#include <stdio.h>
#include "main_menu.h"
#include "../fade.h"

typedef struct _mainMenuData {
    char *text;
    uint8_t count;
} mainMenuData;

mainMenuData main_menu_data;

void main_menu_init(void *data) {
    printf("main_menu_init\n");
    mainMenuData *data_ptr = data;
    data_ptr->text = "MAIN MENU TIME!!\n";
    data_ptr->count = 0;
    fade_in();
}

uint8_t main_menu_iter(void *data) {    
    printf("main_menu_iter\n");
    mainMenuData *data_ptr = data;
    printf(data_ptr->text);
    printf("Count: %u\n", data_ptr->count);
    data_ptr->count += 1;
    if (data_ptr->count > 4) {
        return 1;
    }
    return 0;
}

uint8_t main_menu_exit(void *data) {
    printf("main_menu_exit\n");
    return 1;
}
