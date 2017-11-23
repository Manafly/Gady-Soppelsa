#include "sprite.h"

void sprite_init (sprite_t *sprite, float x, float y, float vx, float vy, float ax, float ay,
		  int w, int h, SDL_Surface *picture, int current_frame,
		  int num_frame, int vie, bool jump){

  sprite->x = x;
  sprite->y = y;
  sprite->vx = vx;
  sprite->vy = vy;
  sprite->ax = ax;
  sprite->ay = ay;
  sprite->w = w;
  sprite->h = h;
  sprite->picture = picture;
  sprite->current_frame = current_frame;
  sprite->num_frame = num_frame;
  sprite->vie = vie;
  sprite->isJumping = jump;
}

void sprite_draw (sprite_t *name, SDL_Surface *screen){

  /* Define the source rectangle for the BlitSurface */
  SDL_Rect nameImage, namePosition;
  nameImage.y = 0;
  nameImage.w = name->w;
  nameImage.h = name->h;

  /* choose image according to direction and animation flip: */
  nameImage.x = name->w*((int)name->current_frame);
  namePosition.x = (int)name->x;
  namePosition.y = (int)name->y;
  SDL_BlitSurface(name->picture, &nameImage, screen, &namePosition);
}

/* Addition of objects in the table */
void sprite_add (sprite_t *tab, int *ntab, int maxi, SDL_Surface *sprite_picture,
                  int sprite_size_w, int sprite_size_h, float x, float y,
                  float vx, float vy, float ax, float ay, int n_frame, int c_frame,
                  float nb_life, bool jump){
  if (*ntab < maxi){
    sprite_init(&tab[*ntab], x, y, vx, vy, ax, ay, sprite_size_w, sprite_size_h,
                sprite_picture, c_frame, n_frame, nb_life, jump);
    *ntab += 1;
  }
}

/* Suppression of objects in the table */
void sprite_del (sprite_t *tab, int *ntab, int i){
  for (int j = i; j < *ntab-1; j++){
    tab[j] = tab[j+1];
  }
  *ntab -= 1;
}

/* Movement of objects */
void sprite_move (sprite_t *sprite, int dir){

    sprite->x += dir;
    sprite->y += sprite->vy;

}


/* Handle the sprite to turn left */
void sprite_turn_left (sprite_t *sprite){
    if (sprite->current_frame == 6){
        sprite->current_frame = 7;
    }
    else{
        sprite->current_frame = 6;
    }
}

/* Handle the sprite to turn right */
void sprite_turn_right (sprite_t *sprite){
    if (sprite->current_frame == 2){
        sprite->current_frame = 3;
    }
    else{
        sprite->current_frame = 2;
    }
}


void sprite_jump (sprite_t *sprite){

    /*if (!(*isJumping)){
        sprite->vy = GRAVITY * timer + jumpPower;
        *isJumping = true;
    }*/

    if (!(sprite->isJumping) && sprite->vy == 0){
        sprite->vy = -jumpPower;
        sprite->isJumping = true;
    }

}

void sprite_jump_down (sprite_t *sprite, double *timer){

    /*if (*isJumping){
       sprite->vy = -GRAVITY * timer;
    }*/

    if (sprite->isJumping){
        sprite->vy -= GRAVITY * (*timer);
        //printf("y = %f, x = %f\n", sprite->y, sprite->x);
        *timer += 1;
    } else{
        sprite->vy = 0;
    }
}
