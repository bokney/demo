
#ifdef TEST
#include "mock_gb.h"
#else
#include <gb/gb.h>
#endif

typedef struct _state {
    uint8_t step;
    void (*init)(void);
    uint8_t (*iter)(void);
    uint8_t (*exit)(void);
} state;

uint8_t runState(state *state);
