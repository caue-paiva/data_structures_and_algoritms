#ifndef PONTO_H
    #define PONTO_H
	#include <stdbool.h>
    #include <stdlib.h>

    typedef struct ponto_ PONTO;
    PONTO*ponto_criar(float x1, float y1);
    void ponto_apagar(PONTO *p);
    bool ponto_set(PONTO *p, float x1, float y1);
    float dist_pontos(PONTO*p1, PONTO*p2);  //essa função retorna a distancia entre 2 pontos, é utilizada por funções no circulo.c para achar a distancia entre 1 circulo e um ponto,

    /*
    Pode ser necessário definir outras operações para o TAD.
    Se for o caso, faça e justifique!
    */
#endif





