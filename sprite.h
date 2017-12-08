#ifndef SPRITE_H
#define SPRITE_H


#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define SCREEN_WIDTH  1120
#define SCREEN_HEIGHT 960

#define SPRITE_SIZE 32

#define TAB_WIDTH 36
#define TAB_HEIGHT 30
#define TAB_NUMBER  1050

#define ACCEL 0.005
#define jumpPower     1
#define GRAVITY     -0.7

#define NBPLAYERS    1


/* Define the structure of a sprite. It has coordinates, speed coordinates, acceleration coordinates **
** width and height, a picture which is associate to the sprite, tools for frames of the sprite, life,**
** a boolean to know whether the sprite is jumping and a force */
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
  float f;
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

void sprite_turn_left(sprite_t *sprite);

void sprite_turn_right(sprite_t *sprite);

void sprite_jump (sprite_t *sprite);

//void sprite_jump_down(sprite_t *sprite);

void sprite_move (sprite_t *sprite);

void sprite_boost (sprite_t *sprite, float accel);


#endif // SPRITE_H
