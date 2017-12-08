#ifndef EVENT_H
#define EVENT_H

#include "sprite.h"


/* Define events functions */

void alternative_HandleEvent(char *key, int *Exit, sprite_t *sprite);

void update_events(char* keys, int *Exit, sprite_t *sprite);

#endif
