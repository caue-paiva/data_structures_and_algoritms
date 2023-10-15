#include "stdlib.h"
#include "stdio.h"
#define TAM 100

typedef struct no NO;

struct no {
   void* item;
   NO* prox;
};

struct pilha {
   NO* topo;
   int tam;
};

enum tipos {
   INT = 1,
   CHAR = 2,
   FLOAT = 0
};

typedef struct pilha PILHA;

int pilha_vazia(PILHA*P1){
   return (P1->tam == 0);
}


void inverte_pilha(PILHA*P1){
   if(pilha_vazia(P1) || P1->tam ==1 ){return;}
   NO* ante=  NULL;
   NO* atual = P1->topo;
   NO* prox = atual->prox;
   //printf("tam pilha %d ", P1->tam);
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


PILHA* pilha_criar(void){
    PILHA* nova_pilha = (PILHA*) malloc(sizeof(PILHA));
           if(nova_pilha == NULL) { exit(1);}
    
    nova_pilha->topo = NULL;
    nova_pilha->tam =0;

    return nova_pilha;
}

NO* no_criar(void* item){
   NO* N1 = (NO*) malloc(sizeof(NO));
     if (!N1) {exit(1);}

   N1->item = item;
   N1->prox = NULL;

   return N1;
}


int push(PILHA* P1,void* item){
   if(!P1){return 0;}

   NO* N1 = no_criar(item);

   if(P1->topo){
      N1->prox = P1->topo;
      P1->topo = N1;
   } else{
      P1->topo =  N1;
   }
   ++(P1->tam);
   return 1; 
}

NO* pop(PILHA*P1){
    if(pilha_vazia(P1)){exit(1);}

    NO* N1= P1->topo;
    P1->topo =P1->topo->prox;
    --(P1->tam);

    return  N1;
}

void pop_print(PILHA* P1){
   NO* no = pop(P1);

   switch()
}

int pilha_tam(PILHA* P1){
   return (P1->tam);
}

int main(){

   PILHA* P1 = pilha_criar();

   push(P1,3);
   push(P1,4);
   push(P1,5);
   push(P1,6);
   inverte_pilha(P1);
   int tam = pilha_tam(P1);
   int item;

   for (int i = 0; i < tam; i++)
   {
      item = pop(P1);
      printf("%d ", item);
   }








}