#include "stdlib.h"
#include "stdio.h"
//codigo feito para testars stacks com tamanho modificável
#define STACK_SIZE 100

typedef struct{
   int top;
   int items[STACK_SIZE];
} stack;

int empty_stack(stack * pS);
int pop(stack* pS);
void push (stack* pS, int new_item);
void expand_stack(stack *pS, int expan_size);
void inverte_stack(stack**pS);
void printa_stack(stack* S1);
int full_stack(stack* pS);
int stack_size(stack*pS);
stack* create_stack(void);
int compara_tam_pilhas(stack* S1, stack* S2);
int compara_pilhas(stack* S1, stack* S2);


int main(){

stack* S1 =create_stack();
stack* S2 =create_stack();

push(S1,3);
push(S1,4);
push(S1,5);
push(S1,6);

push(S2,3);
push(S2,4);
push(S2,5);
push(S2,6);
//print_stack(S1);

inverte_stack(&S1);
printf("\n\n");
printa_stack(S1);
printa_stack(S2);

if (compara_pilhas(S1,S2)){
   printf("iguais \n");
}





}

void inverte_stack(stack**pS){
   stack* tempS = create_stack();
   int size = stack_size(*pS);
   for (int i = 0; i < size; i++)
   {
      int temp = pop(*pS);
      push(tempS,temp);
   }

   free(pS);
   *pS = tempS;
   
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
   if (S1->top > S2->top){
      return 1;
   } else if( S1->top < S2->top) {
      return -2;
   } else {
      return 0;
   }
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
      printf("stack underflow");
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
