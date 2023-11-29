#include "stack_linkada.h"


/* Implementacao de um stack(Pilha) feita com lista encadeada (linkada) para o uso na travessia dos valores da AVL, 
pois essa operacao requere um TAD pilha para ser feita de uma forma que gere valores graduamente (como é necessario nas operacoes do conjunto)

*/



struct no_ {  //essa pilha contem os nós da lista encadeada usada para representar pilha  e os nós das arvores que sao seu conteudo
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

   NO_* N1 = no_criar(no_arv); //cria um NO_ (pilha) com seu conteudo sendo o no da arvore
   if(P1->topo){
      N1->prox = P1->topo; //coloca ele no topo da pilha
      P1->topo = N1;
   } else{
      P1->topo =  N1;
   }
   (P1->tam)++;
   return true; 
}

NO_ARV* pilha_pop(PILHA*P1){  //remove o valor do topo da lista e o retorna
    if(pilha_vazia(P1)){exit(1);}
    
    NO_ARV* N1 = P1->topo->item; //no arvore (conteudo da pilha) e guardado num variavel
    NO_* topo = P1->topo;
    P1->topo = P1->topo->prox; //prox elemento vira o topo
    free(topo); //free no topo antigo
   
    (P1->tam)--; //reduz tam da pilha
    return  N1;
}

NO_ARV* pilha_topo(PILHA* P1){//retorna o valor no topo da pilha, mas sem remove-lo
   if(!P1)
     return NULL;
   return P1->topo->item;
}

int pilha_tam(PILHA* P1){ //retorna o tamanho da lista
   return (P1->tam);
}

bool lista_encad_apagar(NO_** NO){ //funcao para apagar a lista encadeada da pilha
   if(!(*NO)){
      return false;
   }

   NO_* prox;
   while(*NO)
   {  //loop para dar free na lista encadeada
      prox = (*NO)->prox;
      ITEM* item_temp = retorna_item_no_ARV((*NO)->item);
      free(*NO);  //nao vamos apagar os items presentes no no, por que a pilha e usada apenas na travessia dos valores da arvore e nao modifica seus elementos
      (*NO) = prox; 
   }
   
   *NO = NULL;
   return true;
}

bool pilha_apagar(PILHA** P1){ //funcao para apagar a pilha
    if( !(*P1) )
      return false;
   
   lista_encad_apagar( &(*P1)->topo ); //apaga a lista que representa a pilha
   free(*P1); //apaga a pilha em si
   *P1 = NULL;
   return true;
}
