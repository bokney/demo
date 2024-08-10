#include <gb/gb.h>
#include "stateManager.h"

void setStateProperties(
    state *target,
    void (*init)(void *data),
    void (*iter)(void *data),
    void (*exit)(void *data),
    void *data){
        target->init = init;
        target->iter = iter;
        target->exit = exit;
        target->data = data;
    }

void stateManagerRun(stateManager *target) {
    switch (target->step){
        case 0:
            target->state->init(target->state->data);
        case 1:
            if (!target->state->iter(target->state->data)) break;
        case 2:
            target->state->exit(target->state->data);
            break;
    } 
}
