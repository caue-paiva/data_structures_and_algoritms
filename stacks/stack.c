#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h" // a fazer: reimplementar funções com bool
#include "stack.h"


void free_stack(S_elem **sta){
     free(*sta);
}
//this stack is implemented as a simple array

S_elem pop (S_elem *array){
   S_elem top = array[0];
   if (top <= 0){
     printf("empty stack");
      exit(1);
   }
   S_elem result = array[top];
   array[0] = --top;
   return result;

}

void push (S_elem *array, S_elem new_item){
   S_elem top =array[0] ;
   if (top >= (STACKSIZE-1)){
      printf("stack size overflow");
      exit(1);
   }
   array[top+1]= new_item;
   array[0] = ++top;
}

int empty(S_elem *array){
   if (array[0]==0){
      return 1;
   } else {return 0;}
}

S_elem stack_top(S_elem *array){
   if(empty(array)){
    printf("empty stack");
    return 0; 
    }else {
    S_elem top = array[0];
    return array[top];
    }
     
}

S_elem* create_stack(int N){
    S_elem* arr = (S_elem*) calloc(sizeof(S_elem), N+1);
      if(arr==NULL)
        exit(1);
 return arr;
}