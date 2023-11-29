#include "stack_linkada.h"






struct no_ {  //essa pilha contem os nos da lista encad usada para representar pilha e os nos das arvores
   NO_ARV* item;
   NO_* prox;
};


struct pilha {
   NO_* topo;
   int tam;
};


bool pilha_vazia(PILHA*P1){
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

NO_* no_criar(NO_ARV* no_arv){ 
   NO_* N1 = (NO_*) malloc(sizeof(NO_));
     if (!N1) {exit(1);}
   N1->item = no_arv;
   N1->prox = NULL;
   return N1;
}


bool pilha_push(PILHA* P1,NO_ARV* no_arv){
   if(!P1){return false;}

   NO_* N1 = no_criar(no_arv);

   if(P1->topo){
      N1->prox = P1->topo;
      P1->topo = N1;
   } else{
      P1->topo =  N1;
   }
   (P1->tam)++;
   return true; 
}

NO_ARV* pilha_pop(PILHA*P1){
    if(pilha_vazia(P1)){exit(1);}
    
    NO_ARV* N1 = P1->topo->item;
    NO_* topo = P1->topo;
    P1->topo = P1->topo->prox;
    free(topo);
   
    (P1->tam)--;
    return  N1;
}

NO_ARV* pilha_topo(PILHA* P1){
   if(!P1)
     return NULL;
   
   return P1->topo->item;
}

int pilha_tam(PILHA* P1){
   return (P1->tam);
}

bool lista_encad_apagar(NO_** NO){
   if(!(*NO)){
      return false;
   }

   NO_* prox;
   
   while(*NO)
   {  
      prox = (*NO)->prox;
      ITEM* item_temp = retorna_item_no_ARV((*NO)->item);
      free(*NO);
      (*NO) = prox; 
   }
   
   *NO = NULL;
   return true;
}

bool pilha_apagar(PILHA** P1){
    if( !(*P1) )
      return false;
   
   lista_encad_apagar( &(*P1)->topo );
   free(*P1);
   *P1 = NULL;
   return true;
}
