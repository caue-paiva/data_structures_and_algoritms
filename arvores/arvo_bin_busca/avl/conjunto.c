#define N 100

typedef struct {
    int arr[N];
    int num_elem;
}conjun;

void conjun_remove(conjun* s, int* remo_arr, int arr_size){
   int j = 0;
   int remo_count =0;

   for (int i = 0; i < s->num_elem; i++){
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
 (s->num_elem) -= (remo_count); 
 //printf( "%d ", remo_count);
}

int conjun_existe(conjun * C1, int num){
   
   for (int i = 0; i < (C1->num_elem); i++){
        if (C1->arr[i] == num)
            return 1;
   }   
   return 0;
}

conjun* conjun_criar(int *arra, int arr_size){
    conjun* new_set = (conjun*) malloc(sizeof(conjun));
         if (new_set==NULL)
           exit(1);
     new_set->num_elem = 0;
     for (int i = 0; i < arr_size; i++){ 
        if (!conjun_existe(new_set, arra[i])){
       
            new_set->arr[new_set->num_elem] = arra[i];
            new_set->num_elem++;
        }
     }    
    return new_set;
} 

void conjun_add_item(conjun * C1, int num){
   if (C1->num_elem >= N-1){ 
    return;
   } else if (conjun_existe(C1,num)){
    printf("already included on the conjun \n");
   } else {
     C1->arr[C1->num_elem] = num;
     (C1->num_elem)++;
   }
}

conjun* set_uni(conjun* C1,  conjun* C2){
     if (!C1 || !C2)
        return NULL;
    
    conjun* new_set = (conjun*) malloc(sizeof(conjun));
    if (!new_set)
        exit(1);
    NO* maior_conjun;
    NO* menor_conjun;

    if(C1->num_elem > C2->num_elem){
        maior_conjun = C1;
        menor_conjun = C2;
    }else{
        maior_conjun = C2;
        menor_conjun = C1;
    }
          
  //é mais eficiente loopar no menor conjunto e busca se os seus elementos existem no maior
    for (int i = 0; i < menor_conjun->num_elem ; i++){
    //achar um jeito de "ITERAR" pela AVL e pegar todos elementos
        if(!conjun_existe(maior_conjun, cur_set->arr[i])){
                 conjun_add_item(new_set,cur_set->arr[i]);
        } 
    }      

     return new_set;
}

void set_print(conjun* S){
  for (int i = 0; i < S->num_elem; i++)
  { printf(" %d ", S->arr[i]);}
    printf(" \n");
}

/*conju* set_intersec(int Scount, ...){
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

set* C1 = conjun_criar(arr1, sizeof(arr1)/sizeof(int)); //1,2,3,4,56

set* s2 = conjun_criar(arr2, sizeof(arr2)/sizeof(int));

set* s3 = set_uni(2,C1, s2);

//

conjun_remove(C1,arr3,sizeof(arr3)/sizeof(int));

set_print(C1);
//set_print(s2);

set_print(s3);

//conjun_remove

}