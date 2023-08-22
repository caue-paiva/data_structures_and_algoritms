#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#define N 100

typedef struct {
    int arr[N];
    int size;
}set;

void set_remove(set* s, int* remo_arr, int arr_size){
   int j = 0;
   int remo_count =0;

   for (int i = 0; i < s->size; i++){
       int should_remove = 0;
       for (int k = 0; k < arr_size; k++){
           if (s->arr[i] == remo_arr[k]){
               should_remove = 1;
               break;
           }
       }
       if (should_remove){
           remo_count++;
       } else {
           s->arr[j] = s->arr[i];
           j++;   
       }
   }
 (s->size) -= (remo_count); 
 //printf( "%d ", remo_count);
}


int set_included(set * S1, int num){
   
   for (int i = 0; i < (S1->size); i++){
        if (S1->arr[i] == num)
            return 1;
   }   
   return 0;
}

set* set_create(int *arra, int arr_size){
    set* new_set = (set*) malloc(sizeof(set));
         if (new_set==NULL)
           exit(1);
     new_set->size = 0;
     for (int i = 0; i < arr_size; i++){ 
        if (!set_included(new_set, arra[i])){
       
            new_set->arr[new_set->size] = arra[i];
            new_set->size++;
        }
     }    
    return new_set;
} 

void Set_add(set * S1, int num){
   if (S1->size >= N-1){ 
    return;
   } else if (set_included(S1,num)){
    printf("already included on the set \n");
   } else {
     S1->arr[S1->size] = num;
     (S1->size)++;
   }
}

set* set_uni(int Scount, ...){
     if (Scount <= 1 ){
        printf("not possible to do this operation with less than 2 sets");
        return NULL;
    }
    char str[]= "";
    printf(str);
    va_list args;
    va_start(args, Scount);

    set* new_set = (set*) malloc(sizeof(set));
         if (new_set==NULL){
             exit(1);
         }
          
    for (int i = 0; i < Scount; i++)
    {   set* cur_set = va_arg(args, set*);       
        for (int k = 0; k < (cur_set->size) ; k++)
        {
          if(!set_included(new_set, cur_set->arr[k])){
                 Set_add(new_set,cur_set->arr[k]);
          } 
        }      
    }
     va_end(args);
     return new_set;
}

void set_print(set* S){
  for (int i = 0; i < S->size; i++)
  { printf(" %d ", S->arr[i]);}
    printf(" \n");
}

/*set* set_intersec(int Scount, ...){
    if (Scount =<1 ){
        printf("not possible to do this operation with less than 2 sets");
        return NULL;
    }

    va_list args;
    va_start(args, Scount);

    set* new_set = (set*) malloc(sizeof(set));
         if (new_set==NULL){
             exit(1);
         }
     for (int i = 0; i < Scount; i++){
       set* cur_set =var_arg(args, set*);
       
       if (i == 0){
        for (int i = 0; i < (cur_set->size); i++){
           Set_add(new_set, (cur_set->arr[i]));
         }
     } else{

     }

     }
}*/

 
int main(){  ///main just to test the functions

int arr1[]= {1,2,3,4,56,4,4,4,4};
int arr3[]= {1,2};
int arr2[]= {1,6,5,8,9,8,9};

set* s1 = set_create(arr1, sizeof(arr1)/sizeof(int)); //1,2,3,4,56

set* s2 = set_create(arr2, sizeof(arr2)/sizeof(int));

set* s3 = set_uni(2,s1, s2);

//

set_remove(s1,arr3,sizeof(arr3)/sizeof(int));

set_print(s1);
//set_print(s2);

//set_print(s3);

//set_remove

}