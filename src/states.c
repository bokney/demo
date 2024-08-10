
#include <gb/gb.h>
#include "states.h"
#include "game_states/splash.h"
#include "game_states/main_menu.h"

state splashState;
state mainMenuState;

state *init_splashState(void) {
    splashState.init = splash_init;
    splashState.iter = splash_iter;
    splashState.exit = splash_exit;
    splashState.data = &splash;
    return &splashState;
}

state *init_mainMenuState(void) {
    mainMenuState.init = main_menu_init;
    mainMenuState.iter = main_menu_iter;
    mainMenuState.exit = main_menu_exit;
    mainMenuState.data = &mainMenu;
    return &mainMenuState;
}