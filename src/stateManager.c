#include <gb/gb.h>
#include <gb/crash_handler.h>
#include "game_states.h"

uint8_t runState(state *target) {
    switch (target->step){
        case 0:
            target->init(target->data);
            target->step = 1;
        case 1:
            if (!target->iter(target->data)) break;
            target->step = 2;
        case 2:
            target->step = 0;
            return target->exit(target->data);
    }
    return 0;
}
