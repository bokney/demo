
#include <gb/crash_handler.h>
#include "state_manager.h"

uint8_t runState(state *target) {
    switch (target->step) {
        case 0:
            if (target->init)
                target->init();
            target->step = 1;
        case 1:
            if (target->iter)
                if (!target->iter())
                    break;
        case 2:
            target->step = 0;
            if (target->exit)
                return target->exit();
            else
                return 0;
        default:
            __HandleCrash();
    }
    return 0;
}
