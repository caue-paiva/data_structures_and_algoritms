#ifndef CIRCULO_H
    #define CIRCULO_H
      #include <math.h> 
      #include "ponto.h"
   
     //inclusão da lib math.h para usar as funções pow e sqrt
    
    typedef struct circulo_ CIRCULO;    
    CIRCULO *circulo_criar(PONTO *p, float raio);
    void circulo_apagar (CIRCULO* circ);
    float circulo_area (CIRCULO* circ);
    float dist_ponto_circulo(CIRCULO* circ, PONTO*p);  //essa função recebe um circulo e um ponto, e utiliza o centro do circulo e o outro ponto como argumentos (tipo de dado PONTO) Para função de distancia de pontos
   
    
    /*
    Pode ser necessário definir outras operações para o TAD.
    Se for o caso, faça e justifique!
    */

#endif


