#include "fila.h"

void cartas(int n){
 FILA* F1 =fila_criar(); 

 for (int i = 1; i <= n; i++){
    ITEM* novo = item_criar(i);
     fila_inserir(F1,novo);
 }

 int array[n];

 printf("Discarded cards: ");
 int index = 0;
 while (fila_tamanho(F1) != 1){
    ITEM* lixo = fila_remover(F1);
    array[index] = item_get_chave(lixo);
    item_apagar(&lixo);

    index++;
    ITEM* luxo = fila_remover(F1);

    fila_inserir(F1,luxo);

 }

 for (int i = 0; i < index; i++)
 {  if(i == index-1){
     printf("%d",array[i]);
    } else{ 
        printf("%d, ",array[i]);
    }
 }
 

 
ITEM* final = fila_remover(F1);

int int_final = item_get_chave(final);

printf("\nRemaining card: %d\n" ,int_final);

fila_apagar(&F1);

}


// int main(){
//     cartas(7);
// }