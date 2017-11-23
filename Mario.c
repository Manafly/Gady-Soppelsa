#include "MarioFCT.h"
#include "event.h"
#include "sprite.h"

int main(int argc, char* argv[]){

    SDL_Surface  *screen, *world, *temp, *brick, *garane, *grass;
    /* Colorkey for the girl */
    int colorkey;

    double timer = 0;


    /* initialize SDL */
    SDL_Init(SDL_INIT_VIDEO);

    /* set the title bar */
    SDL_WM_SetCaption("SDL Animation", "SDL Animation");

    /* create window */
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);

    /* set keyboard repeat */
    SDL_EnableKeyRepeat(20, 20);

    /* load Background */
    temp  = SDL_LoadBMP("Background.bmp");
    world = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);

    /* load Blocks */
    temp  = SDL_LoadBMP("brique.bmp");
    brick = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);

    /* load grass */
    temp = SDL_LoadBMP("dirt.bmp");
    grass = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);

    /* load Garane */
    temp  = SDL_LoadBMP("sprite.bmp");
    garane = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);

    colorkey = SDL_MapRGB(screen->format, 255, 0, 255);
    SDL_SetColorKey(garane, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);

    /* tab's memory */
    int **tab;
    tab = (int**)malloc(TAB_WIDTH * sizeof(int*));
    for (int a = 0; a < TAB_WIDTH; a++){
        tab[a] = (int*)malloc(TAB_HEIGHT * sizeof(int));
    }

    /* open and read the enters file */

    FILE* fichier = fopen("Niveau1.txt" , "r+");

    int caract;

    /* initialisation for bricks */
    int ntab_brick = 0;
    sprite_t *tab_brick;
    tab_brick = malloc(TAB_NUMBER * sizeof (sprite_t));

    /* initialisation for grass */
    int ntab_grass = 0;
    sprite_t *tab_grass;
    tab_grass = malloc(TAB_NUMBER * sizeof (sprite_t));

    /* initilisation of the girl */
    sprite_t girl;
    sprite_init (&girl, 50, 760, 0, 0, 1, 1, 32, 32, garane, 3, 8, 1, false);


    /* read the file and set the tab */
    for (int j = 0; j < TAB_HEIGHT; j++){
        for (int i = 0; i < TAB_WIDTH; i++){

            /* to get back the caracter in the file */
            caract = fgetc(fichier);

            /* if it isn't a number we don't put it in the tab */
            if (caract != '\n'){
                tab[i][j] = caract;
            }

            /* if it is a 1 we draw a brick */
            if (tab[i][j] == '1'){
                sprite_add(tab_brick, &ntab_brick, 1400, brick, 32, 32, 32*i, 32*j, 0, 0, 1, 1, 1, 0, 1, false);
            }

            /* if it is a 2 we draw grass and earth */
            if (tab[i][j] == '2'){
                sprite_add(tab_grass, &ntab_grass, 1400, grass, 32, 32, 32*i, 32*j, 0, 0, 1, 1, 2, 0, 1, false);
            }

            /* if it is a 3 we draw only earth */
            if (tab[i][j] == '3'){
                sprite_add(tab_grass, &ntab_grass, 1400, grass, 32, 32, 32*i, 32*j, 0, 0, 1, 1, 2, 1, 1, false);
            }
          }
        }
    int fclose(FILE* fichier);


    int Exit = 0;
    char key[SDLK_LAST] = {0};


    while (!Exit){

        update_events(key, &Exit, &girl);
        alternative_HandleEvent(key, &Exit, &girl);
        sprite_move(&girl, 0);
        //sprite_jump_down(&girl, &timer);

        /* Collide with the screen */
        if (girl.x < 0.0){
            girl.x = SCREEN_WIDTH - girl.w;
        }
        if(girl.x > SCREEN_WIDTH - girl.w){
            girl.x = 0.0;
        }
        if (girl.y < 0.0){
            girl.y = 0.0;
            //girl.isJumping = true;
            sprite_jump_down(&girl, &timer);
        }
        if (girl.y > SCREEN_HEIGHT - girl.w){
            girl.y = SCREEN_HEIGHT;
            girl.isJumping = false;
        }


        bool collide1;
        bool collide2;

        for (int r = 0; r <= ntab_grass; r++){
            collide1 = collision2(&girl, &tab_grass[r]);

            if (collide1){
                girl.y = tab_grass[r].y - girl.w;
                girl.vy = 0;
                girl.isJumping = false;
            }
        }

        for (int s = 0; s <= ntab_brick; s++){
            collide2 = collision2(&girl, &tab_brick[s]);

            if (collide2 && (girl.current_frame == 2 || girl.current_frame == 3){


            }

        }



        /* collision avec l'herbe (le sol) */
        /*for (int r = 0; r <= ntab_grass; r++){
            collide1 = collision2(&girl, &tab_grass[r]);

            if (collide1){
                girl.y = tab_grass[r].y - girl.w;
                girl.isJumping = false;
            }
        }*/

        /* collision avec les briques du jeu */
      /*  for (int q = 0; q <= ntab_brick; q++){
            collide2 = collision(&girl, &tab_brick[q]);

            for (int i = tab_brick[q].x; i <= tab_brick[q].x + 32; i++){

                //si le personnage entre en collision vers le bas de la brique, il tombe
                if ((collide2) && ((tab_brick[q].y) + 32 == girl.y)){
                    girl.isJumping = true;
                    sprite_jump_down(&girl, &timer);
                }

                //si le personnage entre en collision par le haut de la brique, il reste dessus
                if ((collide2) && (tab_brick[q].y == girl.y)){
                    girl.y = tab_brick[q].y;
                    girl.isJumping = false;
                }
            }

            for (int a = tab_brick[q].y; a <= tab_brick[q].y + 32; a++){

                //si le personnage entre en collision par la gauche de la brique, il tombe et n'avance plus
                if ((collide2) && ((girl.x / 32)  == (tab_brick[q].x))){
                    sprite_jump_down(&girl, &timer);
                    girl.x = tab_brick[q].x - 32;
                }

                //si le personnage entre en collision par la droite de la brique, il tombe et ne recule plu
                if ((collide2) && (girl.x == (tab_brick[q].x) + 32)){
                    sprite_jump_down(&girl, &timer);
                    girl.x = tab_brick[q].x + 33;
                }
            }
        }*/



        SDL_Rect position;
        position.x = 0;
        position.y = 0;
        position.w = SCREEN_WIDTH;
        position.h = SCREEN_HEIGHT;


        for (int i = 0; i <= ntab_brick; i++){
            sprite_draw(&tab_brick[i], screen);
        }
        for (int j = 0; j <= ntab_grass; j++){
            sprite_draw(&tab_grass[j], screen);
        }
        sprite_draw(&girl, screen);

        /* update the world */
        SDL_UpdateRect(screen, 0, 0, 0, 0);
        SDL_BlitSurface(world, NULL, screen, &position);

        timer += 0.001;

    }

    /* Free variables */

    for (int r = 0; r < TAB_HEIGHT; r++){
        free(tab[r]);
    }
    free(tab);

    SDL_FreeSurface(world);
    SDL_Quit();

    return 0;
}



