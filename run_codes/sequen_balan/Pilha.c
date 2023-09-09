#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "item.h"
#include "Pilha.h"

struct pilha {
    ITEM *item[1000];
    int tamanho;
};

PILHA *pilha_criar(void) {
    PILHA* pilha = (PILHA *) malloc(sizeof (PILHA));
           if (pilha ==NULL){exit(1);}
    if (pilha != NULL)
        pilha->tamanho = 0;
    printf("pilha_criada \n");
    return (pilha);
}

bool pilha_vazia(PILHA* pilha) {
    if (pilha != NULL)
        return ((pilha->tamanho == 0) ? true : false);
    return(false);
}

bool pilha_cheia(PILHA *pilha) {
    if (pilha != NULL)
        return ((pilha->tamanho == 100) ? true : false);
    return(false);
}

int pilha_tamanho(PILHA *pilha) {
    return ((pilha != NULL) ? pilha->tamanho: 0);
}

bool pilha_empilhar(PILHA* pilha, ITEM* item) {
    if ((pilha!=NULL) && (!pilha_cheia(pilha))) {
        pilha->item[pilha->tamanho] = item;
        pilha->tamanho++;
        printf("empilhar deu certo \n");
        return (true);
    }
    return (false);
}

ITEM* pilha_desempilhar(PILHA* pilha) {
    ITEM* i;
    if ((pilha != NULL) && (!pilha_vazia(pilha))) {
        i = pilha_topo(pilha);
        pilha->item[pilha->tamanho-1] = NULL;
        pilha->tamanho--;
        printf("desempilhar deu certo\n ");
        return (i);
    }
    return (NULL);
}

ITEM *pilha_topo(PILHA *pilha) {
   ITEM* novo = pilha->item[(pilha->tamanho) - 1];
   printf("topo funciona\n");
    return  novo;
}
