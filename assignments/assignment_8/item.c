#include "item.h"

struct puntoitem{
       float x;
       float y;
};

int eq(item a, item b){
       if (a->x == b->x && a->y == b->y)
              return 1;
       return 0;
}

item creaItem(float a, float o){
       item new = xmalloc(sizeof(struct puntoitem));
       new->x = a;
       new->y = o;
       return new;
}

item input_item(){
    float a,b;
    scanf("%f", &a);
    scanf("%f", &b);
    return creaItem(a,b);
}

float distanza(item p1, item p2){
      return sqrt(pow((p1->x + p2->x), 2) + pow((p1->y + p2->y), 2));
}
      

void output_item(item it){
     printf("Ascissa: %f, Ordinata: %f\n", it->x, it->y);
}

float item_x(item i){
       return i->x;
}

float item_y(item i){
       return i->y;

}