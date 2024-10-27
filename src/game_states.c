
#ifdef TEST
#include "mock_gb.h"
#else
#include <gb/gb.h>
#endif

#include "game_states.h"
#include "game_states/splash.h"
#include "game_states/main_menu.h"
#include "game_states/page_01.h"
#include "game_states/page_02.h"
#include "game_states/page_03.h"

void assign_splash(obj *target) {
    assign(
        target,
        &splash_init,
        &splash_iter,
        &splash_exit
    );
}

void assign_main_menu(obj *target) {
    assign(
        target,
        &main_menu_init,
        &main_menu_iter,
        &main_menu_exit
    );
}

void assign_page_01(obj *target) {
    assign(
        target,
        &page_01_init,
        &page_01_iter,
        &page_01_exit
    );
}

void assign_page_02(obj *target) {
    assign(
        target,
        &page_02_init,
        &page_02_iter,
        &page_02_exit
    );
}

void assign_page_03(obj *target) {
    assign(
        target,
        &page_03_init,
        &page_03_iter,
        &page_03_exit
    );
}
