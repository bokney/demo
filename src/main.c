
#include <gb/gb.h>
#include <gb/crash_handler.h>
#include "game_states.h"

state currentState;

uint16_t global_counter = 0;

void main(void) {

    assign_splash(&currentState);

    for (;;) {
        switch (runState(&currentState)) {
            case 0:
                __HandleCrash();
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
        wait_vbl_done();
    }
}

