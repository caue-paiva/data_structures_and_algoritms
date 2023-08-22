/*this stack is a simple array, but where the first index of the array is the "top" of the stack

This algo solves the problem of the cars in the garage in the chapter 2 of the book

*/
#include "stdlib.h"
#include "stdio.h"

#define STACKSIZE 11

int stack[STACKSIZE]={0};
int stack2[STACKSIZE]={0};

//top =0 means the stack is empty
int pop (int *array);
void push (int *array, int new_item);
int empty(int *array);
int stack_top(int *array);

// array with 10 available spaces for the license plates
int main(){
char action;
int plate;

scanf("%c %d", &action, &plate);

while(action != 'K' ){
  
  if (action == 'A'){
   //printf("stack top : %d \n", stack[0]);
   printf("%d", plate);
   push(stack, plate);
   printf("car arriving \n");
  }

  if (action == 'D'){
   //printf("stack top : %d \n", stack[0]);
   int popped_plate;
   while((popped_plate = pop(stack)) != plate){
      printf("another car making way \n ");
    push(stack2, popped_plate);
   }
   printf("car left garage \n");

   while (!empty(stack2)){
      int returning_car = pop(stack2);
      push(stack, returning_car);
      printf("returning cars to OG place \n");
   }
   }
scanf("%c %d", &action, &plate);

}





   
}




int pop (int *array){
   int top = array[0];
   if (top <= 0){
      printf("empty stack");
      exit(1);
   }
   int result = array[top];
   array[0] = --top;
   return result;

}

void push (int *array, int new_item){
   int top =array[0] ;
   if (top >= (STACKSIZE-1)){
      printf("stack size overflow");
      exit(1);
   }
   array[top+1]= new_item;
   array[0] = ++top;
}

int empty(int *array){
   if (array[0]==0){
      return 1;
   } else {return 0;}
}

int stack_top(int *array){
   int top = array[0];
   return array[top];
}