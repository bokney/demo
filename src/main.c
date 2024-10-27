
#ifdef TEST
#include "mock_crash_handler.h"
#else
#include <gb/crash_handler.h>
#endif

#include "game_states.h"

uint32_t global_counter = 0;

int main(void) {

    obj currentState;
    assign_splash(&currentState);

    for (;;) {
        switch (run(&currentState)) {
            case 0:
                break;
            case 1:
                assign_splash(&currentState);
                break;
            case 2:
                assign_main_menu(&currentState);
                break;
            case 3:
                assign_page_01(&currentState);
                break;
            case 4:
                assign_page_02(&currentState);
                break;
            case 5:
                assign_page_03(&currentState);
                break;
            default:
                __HandleCrash();
                break;
        }
        global_counter++;
        delay(10);
        wait_vbl_done();
    }
}
