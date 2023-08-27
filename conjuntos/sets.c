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
}

int set_included(set * S1, int num){
   if(S1->size == 0){
     return 0;
   }

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
     if (arra==NULL){
        return new_set;       
     }
    
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
    if (Scount <= 1 ){
        printf("not possible to do this operation with less than 2 sets");
        return NULL;
    }

    va_list args;
    va_start(args, Scount);

    set* new_set = (set*) malloc(sizeof(set));
         if (new_set==NULL){
             exit(1);
         }

    new_set->size = 0;

     set* first_set = va_arg(args, set*);
     for (int k = 0; k < (first_set->size); k++){
            Set_add(new_set, (first_set->arr[k]));
     }

    for (int i = 1; i < Scount; i++){
        set* cur_set = va_arg(args, set*);
        set* temp_set = set_create(NULL, 0);
       
       
          for (int j = 0; j < new_set->size; ++j) {
            if (set_included(cur_set, new_set->arr[j])) {
                Set_add(temp_set, new_set->arr[j]);
            }

         }
         free(new_set);  
         new_set = temp_set;      
       
        }

       va_end(args);
       return new_set;
    
} */

set* set_intersec(int Scount, ...){   
    if (Scount <= 1 ){
        printf("not possible to do this operation with less than 2 sets");
        return NULL;
    }

    va_list args;
    va_start(args, Scount);

    set **sets_arr = malloc(Scount * sizeof(set*));
         if(sets_arr==NULL){exit(1);}
    
    int size=10000, tempSize, Smaller_index=0;
    
    for (int i = 0; i <Scount ; i++){      
        sets_arr[i] = va_arg(args, set*);
        
        tempSize = sets_arr[i]->size;
        
        if (tempSize < size){
            size = tempSize;
            Smaller_index = i;
        }
    }

     va_end(args);
    
    set* new_set = (set*) malloc(sizeof(set));
         if (new_set==NULL){
             exit(1);
         }

     new_set->size = 0;

     set* first_set =  sets_arr[Smaller_index];
     for (int k = 0; k < (first_set->size); k++){
            Set_add(new_set, (first_set->arr[k]));
     }

      for (int i = 0; i < Scount; i++){
        if (i == Smaller_index){
            continue;
        }

        set* cur_set =  sets_arr[i];
        set* temp_set = set_create(NULL, 0);
       
       
          for (int j = 0; j < new_set->size; ++j) {
            if (set_included(cur_set, new_set->arr[j])) {
                Set_add(temp_set, new_set->arr[j]);
            }

         }
         free(new_set);  
         new_set = temp_set;      
       
        }
           
       return new_set;
    
}    




 
int main(){  ///main just to test the functions

int arr1[]= {1,2,3,4,56,4,4,4,4};
int arr3[]= {1,2};
int arr2[]= {1,6,5,8,9,8,9,2,2,4};

set* s1 = set_create(arr1, sizeof(arr1)/sizeof(int)); //1,2,3,4,56

set* s2 = set_create(arr2, sizeof(arr2)/sizeof(int));

set* s3 = set_intersec(2,s1, s2);

//set* s4 = set_intersec(2,s1,s2);
//set_print(s1);

printf("\n");

//set_remove(s1, arr3,2);

set_print(s3);

//

//set_remove(s1,arr3,sizeof(arr3)/sizeof(int));



//set_print(s2);

//set_print(s3);

//set_print(s5);

//set_remove

}