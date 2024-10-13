
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
                    return 0;
        case 2:
            target->step = 0;
            if (target->exit)
                return target->exit();
            return 0;
        default:
            __HandleCrash();
    }
}
