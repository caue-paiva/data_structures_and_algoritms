#include "lista.h"
#include <stdlib.h>
#include <stdio.h>


int main(){

int N;

scanf("%d", &N);
LISTA* L1 =  lista_criar();
for (int i = 0; i < N; i++)
{
  int chave;
  scanf("%d",&chave);
  ITEM* IT1 = item_criar(chave);
  lista_inserir(L1, IT1);
}

lista_inverter(&L1);

lista_imprimir(L1);




}