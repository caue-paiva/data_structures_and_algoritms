#include "circulo.h"
#include "stdio.h"
#include "math.h"


int main(){
    
float pX, pY, cX, cY, r;

scanf("%f  %f", &pX, &pY);
scanf("%f %f %f",&cX, &cY,&r);
PONTO* novoPonto =  ponto_criar(pX,pY);
PONTO* ponto_circu= ponto_criar(cX,cY);
CIRCULO* circ = circulo_criar(ponto_circu, r);
float dist = dist_ponto_circulo(circ, novoPonto);

if(dist > r){
  printf("O ponto é exterior à circunferência.\nDistância: %.2f\n", dist);
} else if ( dist < r){
  printf("O ponto é interior à circunferência.\nDistância: %.2f\n", dist);
} else {
  printf("O ponto pertence à circunferência.\nDistância: %.2f\n", dist);
}

circulo_apagar(circ);
ponto_apagar(novoPonto);


}