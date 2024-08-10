
#include <gb/gb.h>

typedef struct _state {
    void (*init)(void *data);
    uint8_t (*iter)(void *data);
    void (*exit)(void *data);
    void *data;
} state;

typedef struct _stateManager {
    state *state;
    uint8_t step;
} stateManager;

// void setStateProperties(
//     state *target,
//     void (*init)(void *data),
//     void (*iter)(void *data),
//     void (*exit)(void *data),
//     void *data);
    
void stateManagerRun(stateManager *target);
