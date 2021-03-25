#include <stdio.h>
#include <stdlib.h>
#include "punto.h"


int main(int argc, char *argv[])
{
  
  int n = 0, m=0;
  float d = 0;
  float ascissa=0, ordinata=0;
  punto *p;
  
  printf("Quanti numeri vuoi inserire?");
  scanf("%d", &n);
  
  TODO
  
  for (int i =0; i<n; i++){
     TODO
  }
      
  printf("Dammi la distanza:");
  scanf("%f", &d);
  
  //calcola le distanze a coppie e controlla che siano minori di d
  TODO
   
  printf("Le coppie di punti a distanza minore di %f sono %d", d, m);
  
  system("PAUSE");	
  return 0;
}
