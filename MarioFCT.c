#include "MarioFCT.h"

/* Says if a point is between two others */
bool is_between (float coord1, float coord2, float coordtest){
    if ((coord1 <= coordtest) && (coordtest <= coord2)){
        return true;
    } else{
        return false;
    }
}


/* Collision between two blocks */
int collision (sprite_t *sprite1, sprite_t *sprite2){

    float x1 = sprite1->x;
    float x2 = sprite2->x;
    float y1 = sprite1->y;
    float y2 = sprite2->y;
    float w1 = sprite1->w;
    float w2 = sprite2->w;

    if ((max(x1, x2) < min(x1 + w1, x2 + w2)) && (max(y1, y2) < min(y1 + w1, y2 + w2))){
        return 1;
    } else {
        return 0;
    }
}


/* Gives the maximum between 2 numbers */
double max (double a, double b){
  if (a>b){
    return a;
  }else {
    return b;
  }
}


/* Gives the minimum between 2 numbers */
double min (double a, double b){
  if (a<b){
    return a;
  }else {
    return b;
  }
}
