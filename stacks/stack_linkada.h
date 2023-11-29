#ifndef STACK_LINK_H
   #define  STACK_LINK_H
    #include "item.h"
    typedef struct pilha PILHA;
    typedef struct no NO;
    int pilha_vazia(PILHA*P1);
    void inverte_pilha(PILHA*P1);
    PILHA* pilha_criar(void);
    int push(PILHA * P1,int item)
    int pop(PILHA*P1);
    int pilha_tam(PILHA* P1);
    int lista_encad_apagar(NO** NO_);
    int pilha_apagar(PILHA** P1);


#endif 