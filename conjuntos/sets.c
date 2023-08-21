#include <stdlib.h>
#include <stdarg.h>
#define N 100

typedef struct {
    int arr[N];
    int size;
}set;


int Set_included(set * S1, int num, int size){
   for (int i = 0; i < size; i++){
        if (S1->arr[i] == num)
            return 1;
   }   
   return 0;
}

set* create_set(int *arr, int arr_size){
    set* new_set = (set*) malloc(sizeof(set)*1);
         if (new_set==NULL)
           exit(1);

     for (int i = 0; i < arr_size; i++){  
        new_set->arr[i] = arr[i];
     }
     new_set->size = arr_size;
    
    return new_set;
} 

void Set_add(set * S1, int num){
   if (Set_included(S1,num. S1->size)){
    printf("already included on the set \n");
   } else {
     S1->arr[S1->size] = num;
     (S1->size)++;
   }
}

set* set_union(set* s1, set* s2...){
    va_list args;
    va_start(args,s2);

}



 
int main(){  ///main just to test the functions
}