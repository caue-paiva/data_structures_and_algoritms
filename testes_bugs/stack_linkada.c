#include "stack_linkada.h"



struct no_ {
   ITEM* item;
   NO_* prox;
   int teste;
};

struct pilha {
   NO_* topo;
   int tam;
};


int pilha_vazia(PILHA*P1){
   return (P1->tam == 0);
}


/*void inverte_pilha(PILHA*P1){
   if(pilha_vazia(P1) || P1->tam ==1 ){return;}
   NO_* ante=  NULL;
   NO_* atual = P1->topo;
   NO_* prox = atual->prox;
   //printf("tam PILHA %d ", P1->tam);
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
 */

PILHA* pilha_criar(void){
    PILHA* nova_pilha = (PILHA*) malloc(sizeof(PILHA));
           if(nova_pilha == NULL) { exit(1);}
    
    nova_pilha->topo = NULL;
    nova_pilha->tam =0;

    return nova_pilha;
}

PILHA* pilha_criar_valor(ITEM* item){
    PILHA* nova_pilha = (PILHA*) malloc(sizeof(PILHA));
         if(nova_pilha == NULL) { exit(1);}
    
    nova_pilha->topo = item;
    nova_pilha->tam =0;

    return nova_pilha;
}

NO_* no_criar(ITEM* item){
   NO_* N1 = (NO_*) malloc(sizeof(NO_));
     if (!N1) {exit(1);}

   N1->item = item;
   N1->prox = NULL;

   return N1;
}


int pilha_push(PILHA* P1,ITEM* item){
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

ITEM* pilha_pop(PILHA*P1){
    if(pilha_vazia(P1)){exit(1);}

    NO_* N1= P1->topo;
    P1->topo =P1->topo->prox;
    --(P1->tam);
    return  N1->item;
}

ITEM* pilha_topo(PILHA* P1){
   if(!P1)
     return NULL;
   
   return P1->topo->item;
}

int pilha_tam(PILHA* P1){
   return (P1->tam);
}

int lista_encad_apagar(NO_** NO_){
   if(!(*NO_))
      return 0;
   NO_* prox;
   
   while(*NO_)
   {  
      prox = (*NO_)->prox;
      item_apagar((*NO_)->item);
      free(*NO_);
      (*NO_) = prox;
     
   } ;
   
   *NO_ = NULL;
   return 1;
}

int pilha_apagar(PILHA** P1){
    if( !(*P1) )
      return 0;
   
   lista_encad_apagar( &(*P1)->topo );
   free(*P1);
   *P1 = NULL;
   return 1;
}
