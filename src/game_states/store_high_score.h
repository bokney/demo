
#include <gb/gb.h>

typedef struct _storeHighScoreData storeHighScoreData;

extern storeHighScoreData store_high_score_data;

void store_high_score_init(void *data);
uint8_t store_high_score_iter(void *data);
uint8_t store_high_score_exit(void *data);
