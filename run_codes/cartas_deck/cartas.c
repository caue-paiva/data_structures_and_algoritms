#include "fila.h"

void cartas(int n){
 QUEUE* q1 =queue_create();

 for (int i = 1; i <= n; i++){
    ITEM* novo = item_criar(i);
     queue_push(novo,q1);
 }

 int array[n];

 printf("Discarded cards:  ");
 int index = 0;
 while (queue_size(q1) != 1){
    ITEM* lixo = queue_pop(q1);
    array[index] = item_get_chave(lixo);
    item_apagar(lixo);

    index++;
    ITEM* luxo = queue_pop(q1);

    queue_push(luxo , q1);

 }

 for (int i = 0; i < index; i++)
 {  if(i == index-1){
     printf("%d",array[i]);
    } else{ 
        printf("%d, ",array[i]);
    }
 }
 

 
ITEM* final = queue_pop(q1);

int int_final = item_get_chave(final);

printf("\nRemaining card:%d" ,int_final);

queue_free(&q1);

}


int main(){


    cartas(7);
}