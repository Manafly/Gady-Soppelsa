#include "event.h"

/* for an alternative keyboard management */
void alternative_HandleEvent(char *key, int *Exit, sprite_t *sprite){

    // prepare multiplayer game
    SDLKey tabkey[NBPLAYERS][6] = {{SDLK_z ,SDLK_s ,SDLK_q ,SDLK_d , SDLK_SPACE, SDLK_ESCAPE}};
    int i;
    for(i=0; i < NBPLAYERS; i++){

        if (key[tabkey[i][2]]){ // LEFT
            sprite_turn_left(sprite);
            sprite_move(sprite, -1);
        }

        if (key[tabkey[i][3]]){ // RIGHT
            sprite_turn_right(sprite);
            sprite_move(sprite, 1);

        }

        if (key[tabkey[i][4]]){ // SPACE
            sprite_jump(sprite);
            sprite_move(sprite, 0);
        }

        if (key[tabkey[i][5]]){ // ESCAPE
            *Exit = 1;
        }
    }
}


void update_events(char* keys, int *Exit, sprite_t *sprite){

      SDL_Event event;
      while(SDL_PollEvent(&event)){
        switch (event.type){
        case SDL_QUIT:
            *Exit = 1;
            break;
        case SDL_KEYUP:
            keys[event.key.keysym.sym] = 0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym){
            case SDLK_ESCAPE:
                break;
            default:
                break;
            }
            keys[event.key.keysym.sym] = 1;
            break;
        }
    }
}
