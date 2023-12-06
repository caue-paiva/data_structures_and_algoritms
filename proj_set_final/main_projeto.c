#include "conjunto.h"

typedef enum {
   PERTENCE =  1,
   UNIAO  = 2,
   INTERSEC = 3,
   REMOVER = 4,
} OPERACOES; //enum para as operacoes



/*
Operacoes testadas ate agora 27/11/2023: 

////
A melhorar:

////
Valgrind/memory leak:

////
Relatorio:
Colocar a prova da nossa solucao da func intersec ser mais eficiente (colcoar grafico do geogebra se puder)
Justificativa do por que usar AVL

*/

int main(){
 
 int tam1, tam2, input_val1,temp;
 OPERACOES OP1;
 ITEM* item_temp_input;
 conjun* C1 = conjun_criar();  //cria os  2 conjuntos bases e pega o input do user de quantos elementos eles vao ter
 conjun* C2 = conjun_criar();
 scanf("%d",&tam1);
 scanf("%d",&tam2);

 for (int i = 0; i < tam1; i++) {
    scanf("%d", &input_val1);
    item_temp_input = item_criar(input_val1); //escaneia o input do usuario e cria um item para inserir
    conjun_add_item(C1, item_temp_input);
 }

 for (int i = 0; i < tam2; i++) {  //mesma funcionalidade de acima porem para o segundo conjunto
    scanf("%d", &input_val1);
    item_temp_input = item_criar(input_val1);
    conjun_add_item(C2, item_temp_input);  
 }

 scanf("%d", &temp);//escaneia comando 
 OP1 = temp;  //usa a variavel enum no switch para ser mais claro
 
 switch (OP1){
   ITEM* temp_item_switch;
   conjun* temp_conjun_switch;  //variaveis que vamos usar na realizacao das operacoes do switch
   int temp_input_switch;

   case PERTENCE:
      scanf("%d", &temp_input_switch);
      temp_item_switch = item_criar(temp_input_switch);  //ver se vale a pena manter como item, talvez sim devido a ficar capaz de ser usado com varios data typess
      if(conjun_pertence(C1,temp_item_switch))
         printf("pertence \n");
      else
         printf("nao pertence \n");
      item_apagar(&temp_item_switch); //apagando o novo item criado para busca apenas 
   break;

   case UNIAO:
      temp_conjun_switch = conjun_criar();
      conjunto_uniao(C1, C2, temp_conjun_switch);    //novo conjunto gerado pela uniao de C1 e C2                     
      conjun_imprime(temp_conjun_switch);
      printf("tam do novo conjunto : %d \n", conjun_tamanho(temp_conjun_switch));
      conjun_apaga(&temp_conjun_switch); //apagando o novo conjunto que ja foi usado para impressao
   break;

   case INTERSEC:
      temp_conjun_switch = conjun_criar();
      conjunto_intersec(C1, C2, temp_conjun_switch); //novo conjunto gerado pela intersec de C1 e C2
      conjun_imprime(temp_conjun_switch);
      printf("tam do novo conjunto : %d \n", conjun_tamanho(temp_conjun_switch));
      conjun_apaga(&temp_conjun_switch); //apagando o novo conjunto que ja foi usado para impressao
   break;

   case REMOVER: //memory leak pequeno ao criar items aqui
     scanf("%d", &temp_input_switch);
     temp_item_switch = item_criar(temp_input_switch); //cria item para fazer a remocao
     if(conjun_remove(C1,temp_item_switch)) //caso o item ja exista, a operacao deleta o item alocado
        printf("removido com sucesso \n"); //ve se a op teve sucesso
     else
        printf("erro na remocao \n");
     conjun_imprime(C1);
   break;

   default:
       printf("comando nao suportado \n");
   break;
}
 
   conjun_apaga(&C1);  //dar free na memoria dos conjuntos bases
   conjun_apaga(&C2);
}