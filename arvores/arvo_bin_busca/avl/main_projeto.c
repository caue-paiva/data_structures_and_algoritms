#include "conjunto.h"

typedef enum {
   PERTENCE =  1,
   UNIAO  = 2,
   INTERSEC = 3,
   REMOVER = 4,
} OPERACOES; //enum para as operacoes

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

3) Apagar arvore ta congelando o terminal do windows, ver isso ai (acontece quando apaga o C2) [RESOLVIDO]: isso acontece quando vc coloca o mesmo item and 2 conjuntos e apaga os 2, eu não sei se isso é um erro que deve ser resolvido

4) [RESOLVIDO] tava tendo um problema na rotacao, ja resolvi

Relatorio:
Colocar a prova da nossa solucao da func intersec ser mais eficiente (colcoar grafico do geogebra se puder)
Justificativa do por que usar AVL

Lembrar de verificar se existe memory leak com a valgrind antes de entregar
*/

int main(){
 
 int tam1, tam2, input_val1;
 OPERACOES OP1;
 conjun* C1 = conjun_criar();
 conjun* C2 = conjun_criar();
 scanf("%d",&tam1);
 scanf("%d",&tam2);

 for (int i = 0; i < tam1; i++) {
    scanf("%d", &input_val1);
    if (!conjun_add_item(C1, item_criar(input_val1)))
        printf("erro na insercao do item \n");
 }

 for (int i = 0; i < tam2; i++) {
    scanf("%d", &input_val1);
    if(!conjun_add_item(C2, item_criar(input_val1)))
       printf("erro na insercao do item \n");
 }

 scanf("%d", &OP1);
 switch (OP1){
   ITEM* novo_item_pertence;
   conjun* temp_conjun_uniao;
   int input_pertence;

   case PERTENCE:
      scanf("%d", &input_pertence);
      novo_item_pertence = item_criar(input_pertence);  //ver se vale a pena manter como item, talvez sim devido a ficar capaz de ser usado com varios data typess
      if(conjun_pertence(C1,novo_item_pertence))
         printf("pertence");
      else
         printf("nao pertence");
      item_apagar(&novo_item_pertence); //apagando o novo item criado para busca apenas 
   break;

   case UNIAO:
      temp_conjun_uniao =  conjun_uniao(C1,C2); //novo conjunto gerado pela uniao de C1 e C2
      conjun_imprime(temp_conjun_uniao);
      conjun_apaga(&temp_conjun_uniao); //apagando o novo conjunto que ja foi usado para impressao
   break;

   default:
       printf("comando nao suportado \n");
   break;
}
 
   conjun_apaga(&C1);  //dar free na memoria dos conjuntos bases
   conjun_apaga(&C2);
}