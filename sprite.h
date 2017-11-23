#ifndef SPRITE_H
#define SPRITE_H


#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define SCREEN_WIDTH  1600
#define SCREEN_HEIGHT 900

#define jumpPower     2
#define GRAVITY     -0.7


struct Sprite_t {
  float x,y;
  float vx,vy;
  float ax,ay;
  int w,h;
  SDL_Surface *picture;
  int current_frame;
  int num_frame;
  int vie;
  bool isJumping;
};

typedef struct Sprite_t sprite_t;

void sprite_init (sprite_t *sprite, float x, float y, float vx, float vy, float ax, float ay,
                  int w, int h, SDL_Surface *picture, int current_frame,
                  int num_frame, int vie, bool jump);

void sprite_draw(sprite_t *name, SDL_Surface *background);

void sprite_add (sprite_t *tab, int *ntab, int maxi, SDL_Surface *sprite_picture,
                  int sprite_size_w, int sprite_size_h, float x, float y,
                  float vx, float vy, float ax, float ay, int n_frame,
                  int c_frame, float nb_life, bool jump);

void sprite_del (sprite_t *tab, int *ntab, int i);

void sprite_move(sprite_t *sprite, int dir);

void sprite_turn_left(sprite_t *sprite);

void sprite_turn_right(sprite_t *sprite);

void sprite_jump (sprite_t *sprite);

void sprite_jump_down(sprite_t *sprite, double *timer);


#endif // SPRITE_H
