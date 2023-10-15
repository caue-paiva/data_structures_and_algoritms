#ifndef LISTA_ENCAD_H
   #define LISTA_ENCAD_D
 #include "stdio.h"
 #include "stdlib.h"
 typedef struct no NO_;
 typedef struct lista_ LISTA;
 
 enum Position {
   COMECO=1,
   FIM =0
};
 
 NO_* no_criar(int item);
 LISTA* lista_criar(void);
 int lista_adicionar(LISTA* lista, int item, enum Position posicao);
 int lista_procurar(LISTA* lista, int item);
 int lista_remover(LISTA* lista, int item);
 void lista_printa(LISTA*lista);
 NO_* lista_comeco(LISTA* l1);
 int no_valor(NO_* no);
 void no_avanca(NO_** no);
 
#endif