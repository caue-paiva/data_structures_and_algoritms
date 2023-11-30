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
      return(item->chave);
    }
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

ITEM* item_copiar(ITEM* item){ //essa funcao copia o conteudo de um item em outro espaco de memoria, usado para criacao de multiplos conjuntos com elementos independentes
     if(!item){
       printf("item nulo \n");
       exit(1);
     }
      ITEM *item_novo;    
      item_novo = (ITEM *) malloc(sizeof(ITEM));
      if(!item_novo){
         printf("problemas no item \n");
         exit(1);
      }
      if (item_novo != NULL){
             item_novo->chave = item->chave;
             return(item_novo);
      }
      return(NULL);
}

