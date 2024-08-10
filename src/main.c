
#include <gb/gb.h>
// #include "stateManager.h"
// #include "game_states/splash.h"
// #include "game_states/main_menu.h"
#include "states.h"

void main(void) {

    init_splashState();
    init_mainMenuState();

    stateManager sm;
    sm.state = &mainMenuState;
    sm.step = 0;

    for (;;) {
        stateManagerRun(&sm);
        delay(512);
    }
    
}
