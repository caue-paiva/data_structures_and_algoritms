#include "lista.h"



int main(){

int n;

scanf("%d",&n);

LISTA* L1 = lista_criar();
int temp;
for (int i = 0; i < n; i++)
{  
   scanf("%d",&temp);
   ITEM* temp_item = item_criar(temp);
   lista_inserir(L1,temp_item);
}

lista_imprimir(L1);
printf("\n");



}