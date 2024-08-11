
#include <gb/gb.h>
#include <gb/crash_handler.h>
#include "game_states.h"

void main(void) {

    init_splashState();
    init_mainMenuState();

    state *currentState = &splashState;

    for (;;) {
        switch (runState(currentState)) {
            case 0:
                break;
            case 1:
                currentState = &splashState;
                break;
            case 2:
                currentState = &mainMenuState;
                break;
            default:
                __HandleCrash();
        }
        delay(640);
    }
    
}
