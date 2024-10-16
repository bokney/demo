
#ifdef TEST
#include "mock_crash_handler.h"
#else
#include <gb/crash_handler.h>
#endif

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
        default:
            __HandleCrash();
    }
    return 0;
}
