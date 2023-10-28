#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef struct no NO;
typedef struct arvore ARVO;
typedef  int a_elem;

struct no {
    NO* dir;
    NO* esq;
    a_elem item;
};


struct arvore {
    NO* raiz;   
    int num_items;
    int num_niveis;
};

NO* no_criar(a_elem item){
     NO* novo_no = (NO*) malloc(sizeof(NO));
          if(!novo_no)
             exit(1);
     novo_no->item = item;
     novo_no->dir = NULL;
     novo_no->esq = NULL;

     return novo_no;
}

ARVO* arvore_criar(void){
      ARVO* nova_arvo = (ARVO*) malloc (sizeof(ARVORE));
            if(!nova_arvo)
               exit(1);
      nova_arvo->num_items = 0;
      nova_arvo->num_niveis = 1;
      NO* novo_no = (NO*) malloc(sizeof(NO));
          if(!novo_no)
             exit(1);
      novo_no->dir = NULL;
      novo_no->esq = NULL;
      nova_arvo->raiz = novo_no;

      return nova_arvo;
}


bool arvore_adicionar(a_elem item, ARVO* arvo, NO* no){
   if(!arvo)
      return false;
   if(arvo->num_items == 0){
      arvo->raiz->item = item;
      (arvo->num_items)++;
      return true;
   }

   if(!no)
      no = arvo->raiz;
   
   if(!no->dir){
      no->dir = no_criar(item);
      (arvo->num_items)++;
      return true;
   }

   if(!no->esq){
      no->esq = no_criar(item);
      (arvo->num_items)++;
      return true;
   }
   
   arvore_adicionar(item,arvo, );

}


