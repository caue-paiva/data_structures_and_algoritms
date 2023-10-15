#include "lista_encad.h"
#include "math.h"

LISTA* cria_numero(int num){ //1234
    LISTA* nova_lista = lista_criar();
       if(!nova_lista){exit(1);}
   // int pote = 10;
    int resto = 0;
    int iter =1;
    int valor_celula;
    int pote;
    while(num > 0){
       valor_celula = num % 10;  
      // printf(" valor cel %d num %d \n", valor_celula, num);
       lista_adicionar(nova_lista, valor_celula, COMECO);
       num /= 10;  
    }


    return nova_lista;
      
}

LISTA* soma(LISTA* L1, LISTA* L2){
   
    LISTA* nova_lista = lista_criar();
       if(!nova_lista){exit(1);}
    int empresta = 0;
    NO_* aux1= lista_comeco(L1);
    NO_* aux2 = lista_comeco(L2);
    int valor_total;

    while(aux1|| aux2){
        valor_total= 0;
        if(aux1){
          valor_total += no_valor(aux1);
        //  printf(" valor do aux 1 %d \n", valor_total);
          no_avanca(&aux1);
        }

        if(aux2){
         valor_total += no_valor(aux2);
        // printf(" valor do aux 2 %d \n", valor_total);
         no_avanca(&aux2);
       //  aux2 =aux2->prox;
        }
       // printf("valor total antes %d \n", valor_total);
        if(empresta){
        //  printf("valor total antes de add %d \n", valor_total);
           valor_total = valor_total + 1;
           //printf("emprestado, valor total agora %d \n", valor_total);
           empresta = 0;
        }
        if(valor_total >= 10){
         empresta = 1;
         valor_total = valor_total - 10;
        }
      //  printf("valor add %d , emprestra %d \n", valor_total, empresta);
        lista_adicionar(nova_lista,valor_total,COMECO);

    }

    if(empresta){
       lista_adicionar(nova_lista,1,COMECO);
    }
    return nova_lista;
}

int main(){

LISTA* N1 = cria_numero(1234);
LISTA* N2 = cria_numero(9876);
lista_printa(N1);
lista_printa(N2);
LISTA* N3 = soma(N1,N2);

lista_printa(N3);

}