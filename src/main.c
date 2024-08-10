
#include <gb/gb.h>
#include "stateManager.h"
#include "demoStates.h"

void main(void) {
    
    state s;
    s.init = splash_init;
    s.iter = splash_iter;
    s.exit = splash_exit;
    s.data = &splash;

    stateManager sm;
    sm.step = 0;
    sm.state = &s;

    for (;;) {
        stateManagerRun(&sm);
        delay(80);
    }
    
}
