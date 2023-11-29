/*
Operacoes testadas ate agora 26/11/2023: 

Criar conjun: um pouco de teste, funciona bem
Add conjun: bastante teste, parece que funciona bem
remover e pertence: um pouco de teste, funciona bem
conjunto uniao: Um pouco de teste, parece funcionar bem
conjunto intersec: testei um pouco, ta funcionando ok dps de eu colocar um check de um deles ser vazio


A melhorar:
1) algoritmo para iterar sobre elementos da arvore (se existir um melhor que transformar em vetor)

2) Algoritmo da uniao entre 2 conjuntos, ver como otimizar ele por si so e a questao acima

3) Apagar arvore ta congelando o terminal do windows, ver isso ai (acontece quando apaga o C2) [DESCOBRI]: isso acontece quando vc coloca o mesmo item and 2 conjuntos e apaga os 2, eu não sei se isso é um erro que deve ser resolvido

Relatorio:
Colocar a prova da nossa solucao da func intersec ser mais eficiente (colcoar grafico do geogebra se puder)
Justificativa do por que usar AVL

Lembrar de verificar se existe memory leak com a valgrind antes de entregar
*/
#include "conjunto.h"


int main(){

 int tam1, tam2, input_val1,input_val2 ,comando, input_pertence;
 ITEM* novo_item1;
 ITEM* primeiro_item;
 //AVL* arvo1 = avl_criar();
 conjun* C1= conjun_criar();

   ITEM* i1 = item_criar(1);
   ITEM* i3 = item_criar(3);
   ITEM* i2 = item_criar(9);
   ITEM* i4 = item_criar(8);
   ITEM* i5 = item_criar(10);
    ITEM* i6 = item_criar(8);
   ITEM* i7 = item_criar(19);
    ITEM* i8 = item_criar(110);
 //  ITEM* i5 = item_criar(9);
   conjun_add_item(C1,i1);
   conjun_add_item(C1,i2);
   conjun_add_item(C1,i3);
   conjun_add_item(C1,i4);
   conjun_add_item(C1,i5);
   conjun_add_item(C1,i6);
   conjun_add_item(C1,i7);
   conjun_add_item(C1,i8); 





  /* avl_inserir(arvo1,i1);
   avl_inserir(arvo1,i2);
   avl_inserir(arvo1,i3);
   avl_inserir(arvo1,i4);
   avl_inserir(arvo1,i5); */

  // avl_inserir(arvo1,i5);


 ITEM* item_do_loop;
 PILHA* pilha = pilha_criar();
 for (int i = 0; i < conjun_tamanho(C1); i++)
 {
  item_do_loop = conjunto_retorna_valores(C1, pilha);
 // printf("ponteiro item: %p ", item_do_loop);
  printf("%d ", item_get_chave(item_do_loop));
 }

printf("\n\n");
  for (int i = 0; i < conjun_tamanho(C1); i++)
 {
  item_do_loop = conjunto_retorna_valores(C1, pilha);
 // printf("ponteiro item: %p ", item_do_loop);
  printf("%d ", item_get_chave(item_do_loop));
 }
 
  
  //avl_apagar_arvore(&arvo1);
  conjun_apaga(&C1);
  pilha_apagar(&pilha);
 
 }

  
 // avl_imprime(arvo1); 

 
 /* for (int i = 0; i < 3; i++) {
    scanf("%d", &input_val1);
   // printf("%d ",input_val1);
    novo_item1 =  item_criar(input_val1);
    if(i==0){
      primeiro_item = novo_item1;
      printf("novo_item ptr %p \n", novo_item1);
    }
    printf("item: %d ", item_get_chave(novo_item1));
    printf(" deu certo %d \n", avl_inserir(C1, novo_item1));
   //printf("erro na insercao do item \n");
 } */
 //avl_imprime(C1);
// printf("item primeiro %p \n", primeiro_item);





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

   /*
   ITEM* i1 = item_criar(2);
   ITEM* i2 = item_criar(4);
   ITEM* i3 = item_criar(6);
   ITEM* i4 = item_criar(8);
   ITEM* i5 = item_criar(9);
   ITEM* i6 = item_criar(8);
   ITEM* i7 = item_criar(9);
   conjun* C1 = conjun_criar();
   conjun* C2 = conjun_criar();
   conjun* C5 = conjun_criar();
   conjun* C6 = conjun_criar();
   conjun_add_item(C1,i1);
   conjun_add_item(C1,i2);
   conjun_add_item(C1,i3);
   conjun_add_item(C1,i4);
   conjun_add_item(C1,i5);
   
   conjun_add_item(C2,i6);
   conjun_add_item(C2,i7);
   
  // printf(" tam do conjun : %d \n", conjun_tamanho(C1));
  // conjun_remove(C1,i1);
  // printf(" tam do conjun : %d \n", conjun_tamanho(C1));
  // conjun_add_item(C1,i1);
 //  conjun_add_item(C1,i1);
  // printf(" tam do conjun : %d \n", conjun_tamanho(C1));

  // printf("pertence %d \n",conjun_pertence(C1,i3));
   // conjun_imprime(C1);
   //printf(" %d \n",conjun_add_item(C1,i3));
 //  printf("remove %d \n",conjun_remove(C6,i3));
    // conjun_imprime(C2);
  // printf("pertence %d \n",conjun_pertence(C6,i3));
  // conjun_add_item(C1,i3);
  // printf("pertence %d \n",conjun_pertence(C1,i3));
     
    conjun* C4 = conjun_intersec(C1,C5);
    conjun* C7 = conjun_intersec(C1,C2);
   // printf(" tam do conjun : %d \n", conjun_tamanho(C4));


   conjun_apaga(&C1);
   conjun_apaga(&C2);
   conjun_apaga(&C4);
   conjun_apaga(&C5);
   conjun_apaga(&C7);

    // conjun_imprime(C3);

*/