#include "item.h"
#include "ab.h"
#define ERRO_ARVO_NULA -191983

int soma_aux(NO* no_atual, AB* T);


int soma(AB* T){
   if(!T)
     return ERRO_ARVO_NULA;  
   return soma_aux(T->raiz,T);
}

int soma_aux(NO* no_atual, AB* T){
   if(!no_atual)
      return 0;
   static int valor;
   int temp_soma;
   if(no_atual->dir){
      valor += soma_aux(no_atual->dir);
   }

   if(no_atual->esq){
      valor += soma_aux(no_atual->esq);
   }

   if(T->raiz == no_atual){
      temp_soma = valor;
      valor = 0;
      return temp_soma;
   }
     
   return item_get_chave(no_atual->item); 
}