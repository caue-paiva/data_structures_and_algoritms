#include "item.h"

struct item_{ 
        int chave;
        /*outros componentes*/
};

typedef struct item_ ITEM;

ITEM *item_criar(int chave){  //aloca um item e retorna ele pro user
          ITEM *item;
          
          item = (ITEM *) malloc(sizeof(ITEM));
              if(!item){
               printf("problemas no item \n");
              }
          if (item != NULL){
             item->chave = chave;
             return(item);
          }
          return(NULL);
}

bool item_apagar(ITEM **item){ //apaga o item
   if (*item != NULL){
      free (*item);
      *item = NULL; /*Boa pratica!*/
      return(true);
   }
   return(false);
}

int item_get_chave(ITEM *item){ //retorna o valor presente no item
    if (item != NULL) {
    //  printf(" item: %p", item);
      return(item->chave);
    }
    printf("saindo do codigo");
    exit(1);
}

bool item_set_chave(ITEM *item, int chave){
  if (item != NULL){  //seta a chave num item
    item->chave = chave;
    return (true);
  }
  return (false);
}

void item_imprimir(ITEM *item){ //imprime o valor de um item
     if (item != NULL)
        printf("\n-->item: %d\n", item->chave);
}