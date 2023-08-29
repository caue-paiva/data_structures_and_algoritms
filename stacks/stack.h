#ifndef STACK_H
    #define STACK_H
#define STACKSIZE 20

typedef int S_elem;  //typedef of the stack element/data type

S_elem pop (S_elem *array);
void push (S_elem *array, S_elem new_item);
int empty(S_elem *array);
S_elem stack_top(S_elem *array);
S_elem* create_stack(int N);
void free_stack(S_elem **sta);

#endif