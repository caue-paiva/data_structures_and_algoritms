/*this stack is a simple array, but where the first index of the array is the "top" of the stack

This algo solves the problem of the cars in the garage in the chapter 2 of the book

*/
#include "stdlib.h"
#include "stdio.h"
#include "stack.h"

//top =0 means the stack is empty

// array with 10 available spaces for the license plates

int main(){

   S_elem* stack = create_stack(STACKSIZE);
   S_elem* stack2 = create_stack(STACKSIZE);
   char action;
   S_elem plate;

   scanf("%c %d", &action, &plate);

while(action != 'K' ){
  
  if (action == 'A'){
   //printf("stack top : %d \n", stack[0]);
      push(stack, plate);
      printf("car number: %d arriving  \n", plate);
  }

  if (action == 'D'){
      //printf("stack top : %d \n", stack[0]);
      S_elem popped_plate;
      S_elem cars_out = 0; 
   while((popped_plate = pop(stack)) != plate){
      cars_out++;
      printf("%d cars have left to make way \n", cars_out);
      push(stack2, popped_plate);
   }
      printf("car left garage \n");
      S_elem NumRetur =0 ;
   while (!empty(stack2)){
      S_elem returning_car = pop(stack2);
      NumRetur++;
      push(stack, returning_car);
      printf("%d cars have returned to OG place \n", NumRetur);
   }
   }
scanf("%c %d", &action, &plate);

}

   
}

