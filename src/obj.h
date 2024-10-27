
#ifdef TEST
#include "mock_gb.h"
#else
#include <gb/gb.h>
#endif

typedef struct _obj {
    uint8_t state;
    void (*init)(void);
    uint8_t (*step)(void);
    uint8_t (*exit)(void);
} obj;

void assign(
    obj *target,
    void (*init)(void),
    uint8_t (*step)(void),
    uint8_t (*exit)(void)
);

uint8_t run(obj *self);
