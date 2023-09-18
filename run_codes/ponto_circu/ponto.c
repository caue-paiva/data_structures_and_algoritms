
#include "stdlib.h"
#include "ponto.h"	
#include "math.h"

  struct ponto_ {
     float x;
     float y;
 };




PONTO*ponto_criar(float x1, float y1){
    PONTO* P1 = (PONTO*) malloc (sizeof(PONTO));
           if (P1 ==NULL){
            exit(1);
        }
         
    P1->x = x1;
    P1->y = y1;    
    return P1;
}

void ponto_apagar(PONTO* p){
   free(p);
   p = NULL;
}

bool ponto_set(PONTO* p, float x1, float y1){
    if (p==NULL)
       return false;
    
     p->x = x1;
     p->y = y1;

     return true;    
}

float dist_pontos(PONTO*p1, PONTO*p2){
 float dist = (pow((p1->x - p2->x ),2) +  pow((p1->y - p2->y ),2));
 dist = sqrt(dist);
 return dist;
}