#ifndef STACK_H
    #define STACK_H
#define STACKSIZE 10

typedef int S_elem;  //typedef of the stack element/data type

S_elem pop (S_elem *array);
void push (S_elem *array, S_elem new_item);
S_elem empty(S_elem *array);
S_elem stack_top(S_elem *array);
S_elem* create_stack(S_elem N);

#endif