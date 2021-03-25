#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "punto.h"


      
punto creapunto(float x, float y){
      punto temp;
      temp.x = x;
      temp.y = y;

      return temp;
      }

float ascissa(punto p){
     return p.x;
      }

float ordinata(punto p){
      return p.y;
      }

float distanza(punto p1, punto p2){
     float x = p1.x - p2.x;
     float y = p2.y - p2.y;

     return sqrt((x * x) + (y * y));
      }

void  stampa (punto p){
	printf("\nAscissa: %f\nOrdinata: %f\n", p.x, p.y);
	
}


