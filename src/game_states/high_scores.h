
#include <gb/gb.h>

typedef struct _highScoresData highScoresData;

extern highScoresData high_scores_data;

void high_scores_init(void *data);
uint8_t high_scores_iter(void *data);
uint8_t high_scores_exit(void *data);
