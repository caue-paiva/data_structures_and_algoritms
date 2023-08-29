#ifndef STACK_GENE_H
    #define STACK_GENE_H
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdarg.h>


    sta* create_stac(int argNum,...);
    void increase_sta_size(sta** sec_ptr);
    void push(sta* stac1, void*N);
    int empty_sta(sta*stac1);
    void print_stack(sta* stac1);
    void* pop(sta* stac1);
    void* check_top(sta*stac1);









#endif  