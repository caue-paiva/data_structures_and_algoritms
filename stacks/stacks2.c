#include "stdlib.h"
#include "stdio.h"
//codigo feito para testars stacks com tamanho modificável
int stack_size = 100;

typedef struct{
   int top;
   int items[stack_size];
} stack;

int empty_stack(stack * pS);
int pop(stack* pS);
void push (stack* pS, int new_item);
void expand_stack(stack *pS, int expan_size);





int main(){

  stack s = {
        .top = 0,
        .items = { [0 ... stack_size-1] = 0 }
    };

stack* pS= &s;

int max_test_size ==99;
int increase_size = 50;

printf(" number: %d \n", s[max_test_size]);

expand_stack(pS, increase_size);

max_test_size += increase_size;


printf(" number: %d \n", s[max_test_size]);











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
   int result = pS->items[ps->top];
   pS->top--;
   return result;
}

void push (stack* pS, int new_item){
   int temp_top = pS->top;
   if (top >= (stack_size-1)){
   printf("not enought space on array");
   exit(1);
   }
   pS->top++;
   pS[top] == new_item;
}


void expand_stack(stack *pS, int expan_size){
   int* old_pointer = pS->items;
   int* pNewStack = realloc(old_pointer, sizeof(int)* (stack_size+expan_size));
   pS->items = pNewStack;
   stack_size = stack_size + expan_size;
}