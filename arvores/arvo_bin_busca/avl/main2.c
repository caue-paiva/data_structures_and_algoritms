/*
Operacoes testadas ate agora 26/11/2023: 

Criar conjun: um pouco de teste, funciona bem
Add conjun: bastante teste, parece que funciona bem
remover e pertence: um pouco de teste, funciona bem


A melhorar:
1) algoritmo para iterar sobre elementos da arvore (se existir um melhor que transformar em vetor)

2) Algoritmo da uniao entre 2 conjuntos, ver como otimizar ele por si so e a questao acima


Relatorio:
Colocar a prova da nossa solucao da func intersec ser mais eficiente (colcoar grafico do geogebra se puder)
Justificativa do por que usar AVL

Lembrar de verificar se existe memory leak com a valgrind antes de entregar
*/
#include "conjunto.h"


int main(){
   ITEM* i1 = item_criar(2);
   ITEM* i2 = item_criar(4);
   ITEM* i3 = item_criar(6);
   ITEM* i4 = item_criar(8);
   ITEM* i5 = item_criar(9);
   conjun* C1 = conjun_criar();
   conjun_add_item(C1,i1);
   conjun_add_item(C1,i2);
   conjun_add_item(C1,i3);
   printf("pertence %d \n",conjun_pertence(C1,i3));
   //conjun_imprime(C1);
   //printf(" %d \n",conjun_add_item(C1,i3));
   printf("remove %d \n",conjun_remove(C1,i3));
   //conjun_imprime(C1);
   printf("pertence %d \n",conjun_pertence(C1,i3));
   conjun_add_item(C1,i3);
   printf("pertence %d \n",conjun_pertence(C1,i3));



}

  /*AVL* arvo1 = avl_criar();
   ITEM* i1 = item_criar(2);
   ITEM* i2 = item_criar(4);
   ITEM* i3 = item_criar(6);
   ITEM* i4 = item_criar(8);
   ITEM* i5 = item_criar(9);

   avl_inserir(arvo1,i1);
   avl_inserir(arvo1,i2);
   avl_inserir(arvo1,i3);
   avl_imprime(arvo1);
   printf("a remocao do item %d tem esse resultado: %d \n", item_get_chave(i1), avl_remove(arvo1,i1));
   //printf("num de elem da arvo : %d \n", avl_num_elem(arvo1));
   avl_remove(arvo1,i1);
   printf("a remocao do item %d tem esse resultado: %d \n", item_get_chave(i1), avl_remove(arvo1,i1));
   avl_inserir(arvo1,i4);
   avl_imprime(arvo1);
   int* novo_vetor = avl_para_vetor(arvo1);
   //printf("num de elem da arvo : %d \n", avl_num_elem(arvo1));
   //printf("\n");
   for (int i = 0; i < avl_num_elem(arvo1); i++){
     // printf("%d ", novo_vetor[i]);
   } */