#include <stdlib.h>
#include <stdio.h>
#include "item.h"

struct item_{ 
        char* palavra; //maximo de 50 chars
        char* definicao; //maximo de 140 chars
        /*outros componentes*/
};

ITEM *item_criar (char* palavra, char* defi){
          ITEM *item;
          
          item = (ITEM *) malloc(sizeof(ITEM));
          
          if (item != NULL){
             item->palavra= palavra;
             item->definicao = defi;
             return(item);
          }
          return(NULL);
}

int item_apagar(ITEM **item){
   if (*item != NULL){
      free (*item);
      item = NULL; 
      return(1);
   }
   return(0);
}

char* item_get_chave(ITEM *item){  //retorna a palavra
    if (item != NULL)
      return(item->palavra);
    return NULL;
}

char* item_get_defi(ITEM *item){
    if (item != NULL)
      return(item->definicao);
    exit(1);
}

int item_set_chave(ITEM *item, char* chave){ //seta a palavra
  if (item != NULL){
    item->palavra = chave;
    return (1);
  }
  return (0);
}

int item_set_defini(ITEM *item, char* defi){ //seta a palavra
  if (item != NULL){
    item->definicao = defi;
    return (1);
  }
  return (0);
}

void item_imprimir(ITEM *item){  //imprime palavra
     if (item != NULL)
        printf("\n-->item: %s\n", item->palavra);
}

void item_imprimir_defi(ITEM *item){  //imprime palavra
     if (item != NULL)
        printf("\n-->item: %s\n", item->definicao);
}