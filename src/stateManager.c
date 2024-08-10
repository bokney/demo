#include <gb/gb.h>
#include <gb/crash_handler.h>
// #include "stateManager.h"
#include "states.h"

void stateManagerRun(stateManager *target) {
    switch (target->step){
        case 0:
            target->state->init(target->state->data);
            target->step = 1;
        case 1:
            if (!target->state->iter(target->state->data)) break;
            target->step = 2;
        case 2:
            uint8_t next_state = target->state->exit(target->state->data);
            target->step = 0;
            switch (next_state) {
                case 0:
                    target->state = &splashState;
                    break;
                case 1:
                    target->state = &mainMenuState;
                    break;
                default:
                    __HandleCrash();
            }
            break;
    } 
}
