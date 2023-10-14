#include "stdlib.h"
#include "stdio.h"
//codigo feito para testars stacks com tamanho modificável
#define STACK_SIZE 100

typedef struct{
   int top;
   int items[STACK_SIZE];
} stack;

typedef struct{
  stack* ordenada;
  stack* aux;
  int tam;
} fila;

/*void inverte_stack(stack**pS){
   stack* tempS = create_stack();
   int size = stack_size(*pS);
   for (int i = 0; i < size; i++)
   {
      int temp = pop(*pS);
      push(tempS,temp);
   }

   free(pS);
   *pS = tempS;
   
}*/


int full_stack(stack* pS){
   return ((pS->top +1) == STACK_SIZE);
}

stack* create_stack(void){
     stack* new_stack = (stack*) malloc(sizeof(stack));
      if(new_stack == NULL){exit(1);}
      new_stack->top = -1;
      return new_stack;
}

int stack_size(stack*pS){
   if(pS == NULL) {exit(1);}
   return (pS->top+1);
}

int empty_stack(stack * pS){
   if (pS ->top  < 0){
      return 1;
   } else { return 0;}
}

int pop(stack* pS){
   if (empty_stack(pS)){
      printf( "stack underflow");
      exit(1);
   }
   int result = pS->items[pS->top];
   pS->top--;
   return result;
}

void push (stack* pS, int new_item){
   if (pS->top >= (STACK_SIZE-1)){
   printf("not enought space on array");
   exit(1);
   }
   pS->top++;
   pS->items[pS->top] = new_item;
}

void printa_stack(stack* S1){
   stack* tempS1 = create_stack();
   int temp1;
   int tam = stack_size(S1);

   for (int i = 0; i < tam; i++)
   {
      temp1 = pop(S1);
      printf(" %d ", temp1);
      push(tempS1,temp1);
      
   }

   for (int i = 0; i < tam; i++)
   {
      temp1 = pop(tempS1);
      push(S1,temp1);
   }
  printf("\n");
}

int compara_tam_pilhas(stack* S1, stack* S2){
   if (S1->top > S2->top){return 1;
   } else if( S1->top < S2->top) {return -2;
   } else {return 0;}
}

int compara_pilhas(stack* S1, stack* S2){
   if (S1->top != S2-> top){return 0;}
   stack* tempS1 = create_stack();
   stack* tempS2 = create_stack();
   int temp1, temp2;
   int tam = stack_size(S1);

   for (int i = 0; i < tam; i++)
   {
      temp1 = pop(S1);
      temp2 = pop(S2);
      if (temp1 != temp2){ return 0;}
      push(tempS1,temp1);
      push(tempS2, temp2);
   }

   for (int i = 0; i < tam; i++)
   {
      temp1 = pop(tempS1);
      temp2 = pop(tempS2);
      push(S1,temp1);
      push(S2, temp2);
   }
   return 1;
}


fila* cria_fila(void){
    fila* nova_fila = (fila*) malloc(sizeof(fila));
       if(!nova_fila){exit(1);}

   stack* orde = create_stack();
   stack* aux = create_stack();
   nova_fila->ordenada = orde;
   nova_fila->aux = aux;
   nova_fila->tam = 0;

   return nova_fila;
}

int fila_tam(fila* fila){
   return (fila->tam);
}

int fila_vazia(fila* fila){
    return (fila->tam == 0);
}

int fila_pop(fila*fila){
   if (fila_vazia(fila)){exit(1);}
   int item;
    
   if(empty_stack(fila->ordenada) && !empty_stack(fila->aux)){
         int tam = stack_size(fila->aux);
         for (int i = 0; i < tam ; i++){
               int item2 = pop(fila->aux);
               push(fila->ordenada,item2);
         }
         item = pop(fila->ordenada);
         (fila->tam)--;
         return item;        
   } else if(!empty_stack(fila->ordenada)){
        item = pop(fila->ordenada);
        (fila->tam)--;
        return item;
   }
   
   
}

int fila_push(int item, fila* fila){
    if(empty_stack(fila->aux) && empty_stack(fila->ordenada)){
       push(fila->ordenada,item);
    }else{
       push(fila->aux,item);
    }
   (fila->tam)++;
   return 1;
}


int main(){

  fila* F1 = cria_fila();

  fila_push(3,F1);
  fila_push(4,F1);
  fila_push(5,F1);
  fila_push(6,F1);

  for (int i =0; i < 4 ; i++){
     printf("%d ", fila_pop(F1));
  }

  
  fila_push(7,F1);
  printf("\n%d ", fila_pop(F1));









}