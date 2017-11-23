#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "sprite.h"



#define SCREEN_WIDTH  1600
#define SCREEN_HEIGHT 900
#define SPRITE_SIZE 32
#define DIR_UP 0
#define DIR_RIGHT 1
#define DIR_DOWN 2
#define DIR_LEFT 3
#define ESCAPE 4
#define TAB_WIDTH 51
#define TAB_HEIGHT 28

#define TAB_NUMBER  1400


bool collide (sprite_t *sprite1, sprite_t *sprite2);

bool collision2 (sprite_t *s1, sprite_t *s2);

double max (double a, double b);

double min (double a, double b);
