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
bool collision2 (sprite_t *s1, sprite_t *s2){
    if ((is_between(s1->x, s1->x + s1->w, s2->x) && (is_between(s1->y, s1->y + s1->w, s2->y)))
        || (is_between(s2->x, s2->x + s2->w, s1->x + s1->w) && (is_between(s2->y, s2->y + s2->w, s1->y)))
         || (is_between(s1->x, s1->x + s1->w, s2->x + s2->w) && (is_between(s1->y, s1->y + s1->w, s2->y)))
         || (is_between(s2->x, s2->x + s2->w, s1->x) && (is_between(s2->y, s2->y + s2->w, s1->y)))){

            return true;
         } else {
            return false;
         }
}


/* bool collision (sprite_t *s1, sprite_t *s2){
    if ((s2->x >= s1->x + s1->w)
        || (s2->x + s2->w <= s1->x)
        || (s2->y >= s1->y + s1->h)
        || (s2->y + s2->h <= s1->y)){
        return false;
     }
     else {
        return true;
     }
}*/

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
