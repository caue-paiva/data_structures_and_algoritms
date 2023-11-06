#include "item.h"
#include "ab.h"
#define ERRO_ARV_NULL -1928727
#define ARVO_MENOR_VAL -9878321

int maior_aux(NO* no, AB* T);

int maior(AB* T){
   if(!T)
      return ERRO_ARV_NULL;
   return maior_aux(T->raiz, T);
}

int maior_aux(NO* no, AB* T){
   static int maior_val = ARVO_MENOR_VAL;
   int temp_val;

   if(no){
      if((temp_val= item_get_chave(no->item)) > maior_val)
           maior_val = temp_val;
      maior_aux(no->dir,T);
      maior_aux(no->esq,T);
      
      if(T->raiz == no){
         temp_val = maior_val;
         maior_val = ARVO_MENOR_VAL;
         return temp_val;
      } 
   }

   return maior_val; 
}


