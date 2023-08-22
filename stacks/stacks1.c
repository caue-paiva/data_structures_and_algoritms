#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#define stack_size 10

typedef struct{
int top;
char items[stack_size];
} stack;

int empty_stack(stack * pS);
char pop(stack* pS);
void push (stack* pS, char new_item);
char stack_top (stack *pS);
//void expand_stack(stack *pS, int expan_size);





int main(){

char string[]= "AABABBACABBABAB";
int str_len = strlen(string);
int mid_point = (str_len-1)/2; //index of the C letter

stack s = {
.top = 0,
.items = { [0 ... stack_size-1] = 0 }
};
stack* pS= &s;
int VALID = 1;

for (int i = 0; i < str_len; i++)
{   
   if (i > mid_point && pS->top == 0){
      break;
   }

   if (i < mid_point){
      printf("pushing %c \n ", string[i]);
      push(pS, string[i]);
      printf("top : %d \n", pS->top);
   }

  
   char top = stack_top(pS);
   if(i > mid_point && (stack_top(pS)== string[i])){
      printf( "after the c: %c \n", string[i]);
      pop(pS);
      printf("top : %d \n", pS->top);
   }
}



if (!empty_stack(pS)){
   VALID =0;
}

if (!VALID){
   printf("not a valid string");
} else {printf("valid string");}
        



}


int empty_stack(stack * pS){
if (pS ->top  <= 0){
   return 1;
} else { return 0;}
}

char pop(stack* pS){
   if (empty_stack(pS)){
      printf( "stack underflow");
      exit(1);
   }
   char result = pS->items[pS->top];
   pS->top--;
   return result;
}

void push (stack* pS, char new_item){
   char temp_top = pS->top;
   if (temp_top >= (stack_size-1)){
   printf("not enought space on array");
   exit(1);
   }
   pS->top++;
   pS->items[pS->top] = new_item;
}

char stack_top (stack *pS){
if (empty_stack(pS)){ 
  printf("stack is empty");
   
} else {return (pS->items[pS->top]);}
 
}


// void expand_stack(stack *pS, int expan_size){
//    int* old_pointer = pS->items;
//    int* pNewStack = realloc(old_pointer, sizeof(int)* (stack_size+expan_size));
//    pS->items = pNewStack;
//    stack_size = stack_size + expan_size;
// }