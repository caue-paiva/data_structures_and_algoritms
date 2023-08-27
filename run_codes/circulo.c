 
#include "stdlib.h"
#include <math.h> 
#include "ponto.h"
#include "circulo.h"
const float PI = 3.14;
 struct circulo_ {
     PONTO *p1;
     float raio;
 };



CIRCULO* circulo_criar(PONTO*p, float raio){
    CIRCULO* circ = (CIRCULO*) malloc (sizeof(CIRCULO));
             if (circ ==NULL){
                  exit(1);
             }

    circ->p1 = p;
    circ->raio = raio;
            
   return circ;
}

void circulo_apagar (CIRCULO* circ){
    free(circ->p1);
    free(circ);
    circ =NULL;
}

float circulo_area(CIRCULO* circ){
  return (PI * pow(circ->raio,2));
}

float dist_ponto_circulo(CIRCULO* circ, PONTO*p2){
 float dist = dist_pontos(circ->p1, p2);
 return dist;
}

