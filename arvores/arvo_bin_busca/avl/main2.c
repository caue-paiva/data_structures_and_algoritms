#include "avl.h"


int main(){

   AVL* arvo1 = avl_criar();
   ITEM* i1 = item_criar(2);
   ITEM* i2 = item_criar(4);
   ITEM* i3 = item_criar(6);
   ITEM* i4 = item_criar(8);
   ITEM* i5 = item_criar(9);

   avl_inserir(arvo1,i1);
   avl_inserir(arvo1,i2);
   avl_inserir(arvo1,i3);
   avl_inserir(arvo1,i4);
   avl_imprime(arvo1);
   printf("num de elem da arvo : %d \n", avl_num_elem(arvo1));
   avl_remove(arvo1,i1);
   avl_imprime(arvo1);
   int* novo_vetor = avl_para_vetor(arvo1);
   printf("num de elem da arvo : %d \n", avl_num_elem(arvo1));
   printf("\n");
   for (int i = 0; i < avl_num_elem(arvo1); i++){
      printf("%d ", novo_vetor[i]);
   }
   

}