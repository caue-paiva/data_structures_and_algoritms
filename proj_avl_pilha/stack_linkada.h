#ifndef STACK_LINK_H
   #define  STACK_LINK_H
    #include "avl.h"
    typedef struct no_ NO_;
    typedef struct pilha PILHA;

    bool pilha_vazia(PILHA*P1);
    PILHA* pilha_criar(void);
    bool pilha_push(PILHA* P1,NO_ARV* item);
    NO_ARV* pilha_pop(PILHA*P1);
    int pilha_tam(PILHA* P1);
    bool pilha_apagar(PILHA** P1);
    NO_ARV* pilha_topo(PILHA* P1);
#endif 