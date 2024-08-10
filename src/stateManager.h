
#include <gb/gb.h>

typedef struct _state {
    void (*init)(void *data);
    uint8_t (*iter)(void *data);
    uint8_t (*exit)(void *data);
    void *data;
} state;

typedef struct _stateManager {
    state *state;
    uint8_t step;
} stateManager;
    
void stateManagerRun(stateManager *target);
