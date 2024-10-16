
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

void assign_splash(state *state) {
    state->init = &splash_init;
    state->iter = &splash_iter;
    state->exit = &splash_exit;
}

void assign_main_menu(state *state) {
    state->init = &main_menu_init;
    state->iter = &main_menu_iter;
    state->exit = &main_menu_exit;
}

void assign_page_01(state *state) {
    state->init = &page_01_init;
    state->iter = &page_01_iter;
    state->exit = &page_01_exit;
}

void assign_page_02(state *state) {
    state->init = &page_02_init;
    state->iter = &page_02_iter;
    state->exit = &page_02_exit;
}

void assign_page_03(state *state) {
    state->init = &page_03_init;
    state->iter = &page_03_iter;
    state->exit = &page_03_exit;
}
