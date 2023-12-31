#include "stdlib.h"
#include "stdio.h"

typedef struct no NO_;

struct no {
   int item;
   NO_* prox;
};

struct pilha {
   NO_* topo;
   int tam;
};

typedef struct pilha PILHA_;

int pilha_vazia(PILHA_*P1){
   return (P1->tam == 0);
}


void inverte_pilha(PILHA_*P1){
   if(pilha_vazia(P1) || P1->tam ==1 ){return;}
   NO_* ante=  NULL;
   NO_* atual = P1->topo;
   NO_* prox = atual->prox;
   //printf("tam PILHA_ %d ", P1->tam);
   int tam =  P1->tam;
   do
    {  
      ante = atual;
      atual = prox;
      prox = prox->prox;
      atual->prox = ante;
        
    } while (prox);

   P1->topo =atual;
   
}


PILHA_* pilha_criar(void){
    PILHA_* nova_pilha = (PILHA_*) malloc(sizeof(PILHA_));
           if(nova_pilha == NULL) { exit(1);}
    
    nova_pilha->topo = NULL;
    nova_pilha->tam =0;

    return nova_pilha;
}

NO_* no_criar(int item){
   NO_* N1 = (NO_*) malloc(sizeof(NO_));
     if (!N1) {exit(1);}

   N1->item = item;
   N1->prox = NULL;

   return N1;
}


int push(PILHA_* P1,int item){
   if(!P1){return 0;}

   NO_* N1 = no_criar(item);

   if(P1->topo){
      N1->prox = P1->topo;
      P1->topo = N1;
   } else{
      P1->topo =  N1;
   }
   ++(P1->tam);
   return 1; 
}

int pop(PILHA_*P1){
    if(pilha_vazia(P1)){exit(1);}

    NO_* N1= P1->topo;
    P1->topo =P1->topo->prox;
    --(P1->tam);

    return  N1->item;
}

int pilha_tam(PILHA_* P1){
   return (P1->tam);
}

int lista_encad_apagar(NO_** NO_){
   if(!(*NO_))
      return 0;
   NO_* prox;
   
   while(*NO_)
   {  
      prox = (*NO_)->prox;
      free(*NO_);
      (*NO_) = prox;
     
   } ;
   
   *NO_ = NULL;
   return 1;
}

int pilha_apagar(PILHA_** P1){
    if( !(*P1) )
      return 0;
   
   lista_encad_apagar( &(*P1)->topo );
   free(*P1);
   *P1 = NULL;
   return 1;
}
