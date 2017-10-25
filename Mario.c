#include "MarioFCT.h"
#include "event.h"
#include "sprite.h"

int main(int argc, char* argv[]){

    SDL_Surface  *screen, *world, *temp, *brick, *garane, *grass;
    /* Colorkey for the girl */
    int colorkey;


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

    int ntab_girl = 0;
    sprite_t *tab_girl;
    tab_girl = malloc(1 * sizeof (sprite_t));
    sprite_add(tab_girl, &ntab_girl, 1, garane, 32, 32, 50, 760, 0, 0, 1, 1, 8, 3, 1);


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
                sprite_add(tab_brick, &ntab_brick, 1400, brick, 32, 32, 32*i, 32*j, 0, 0, 1, 1, 1, 0, 1);
            }

            /* if it is a 2 we draw grass and earth */
            if (tab[i][j] == '2'){
                sprite_add(tab_grass, &ntab_grass, 1400, grass, 32, 32, 32*i, 32*j, 0, 0, 1, 1, 2, 0, 1);
            }

            /* if it is a 3 we draw only earth */
            if (tab[i][j] == '3'){
                sprite_add(tab_grass, &ntab_grass, 1400, grass, 32, 32, 32*i, 32*j, 0, 0, 1, 1, 2, 1, 1);
            }
          }
        }
    int fclose(FILE* fichier);


    int Exit = 0;
    char key[SDLK_LAST] = {0};


    while (!Exit){

        update_events(key, &Exit);
        alternative_HandleEvent(key, &Exit, tab_girl);


        //sprite_move(tab_girl);


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
        for (int h = 0; h <= ntab_girl; h++){
            sprite_draw(&tab_girl[0], screen);
        }

        /* update the world */
        SDL_UpdateRect(screen, 0, 0, 0, 0);
        SDL_BlitSurface(world, NULL, screen, &position);

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



