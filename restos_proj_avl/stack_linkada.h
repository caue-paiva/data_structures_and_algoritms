#ifndef STACK_LINK_H
   #define  STACK_LINK_H
    #include "item.h"
    typedef struct no_ NO_;
    typedef struct pilha PILHA;

    int pilha_vazia(PILHA*P1);
    PILHA* pilha_criar(void);
    int pilha_push(PILHA* P1,ITEM* item);
    ITEM* pilha_pop(PILHA*P1);
    int pilha_tam(PILHA* P1);
    int pilha_apagar(PILHA** P1);
    PILHA* pilha_criar_valor(ITEM* item);
    ITEM* pilha_topo(PILHA* P1);
#endif 