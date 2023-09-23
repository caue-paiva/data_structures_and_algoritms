#include "lista.h"
int global = 0;

struct lista_ {
    ITEM** lista;
    int Mem_tam;
    int Num_items;
};

bool lista_shift_esque(LISTA*lista, int index){   
     for (int i = index+1; i < lista->Num_items; i++)
     {
         lista->lista[i-1] = lista->lista[i];
     }
     return true;
}

bool lista_shift_dir(LISTA*lista, int index){  
   if(lista->Num_items >= lista->Mem_tam-1) {return false;}

     for (int i = lista->Num_items; i > index; i--)
     {
         lista->lista[i] = lista->lista[i-1];
     }
     return true;
}

LISTA* lista_criar(void){
   LISTA* Lista = (LISTA*) malloc(sizeof(LISTA));
          if(Lista == NULL){exit(1);}

   ITEM** valores = (ITEM**) malloc(sizeof(ITEM*)*TAM_MAX);
           if(valores==NULL){exit(1);}

   Lista->lista = valores;
   Lista->Mem_tam = TAM_MAX;
   Lista->Num_items = 0;

   return Lista;
}

bool lista_inserir(LISTA* lista, ITEM* chave){
    if (lista->Num_items >= lista->Mem_tam){ return false;}

   // printf("iteracao num: %d \n", global);
    global++;
    //printf("num items: %d \n", lista->Num_items);
    if(lista->Num_items == 0){
   // printf("primeira add\n");
    lista->lista[lista->Num_items] = chave;
    lista->Num_items ++;
    return true;
    } else {
     int novo_valor = item_get_chave(chave);
     int lop=0;
     for (int i = 0; i < (lista->Num_items) ; i++)
     {   int antigo_valor = item_get_chave(lista->lista[i]);
         //printf("ant %d novo %d for %d \n", antigo_valor, novo_valor, lop);
         lop++;
         
         if(novo_valor < antigo_valor){
            // printf("shiftado para dir \n");
             lista_shift_dir(lista,i);            
             lista->lista[i] = chave;
            // printf("novo item dps do shift %d , item dps do shift %d \n", item_get_chave(lista->lista[i]) , item_get_chave(lista->lista[i+1]));
             lista->Num_items++;
             return true;
         }
      
     }
      lista->lista[lista->Num_items] = chave;
      lista->Num_items ++;
     // printf("nao precisou shiftar \n");
     
    }
    return true;
}

ITEM* lista_remover(LISTA*lista, int chave){ 
      for (int i = 0; i < lista->Num_items; i++)
      {    int nova_chave = item_get_chave((lista->lista[i]));        
           if ( nova_chave == chave){
                ITEM* item_reque = lista->lista[i];
                lista_shift_esque(lista, i);
                lista->Num_items--;
                return (item_reque);
           }
         
      }    
      return NULL;
}

void lista_apagar(LISTA**lista){
   for (int i = 0; i < (*lista)->Mem_tam; i++){item_apagar(&(*lista)->lista[i]);}
   
   free((*lista)->lista);
   free(*lista);
}


ITEM* lista_busca(LISTA*lista, int chave){ 
      for (int i = 0; i < lista->Num_items; i++)
      {    int nova_chave = item_get_chave((lista->lista[i]));        
           if ( nova_chave == chave){
            ITEM* item_reque = lista->lista[i];
               return (item_reque);
           }
         
      }    
      return NULL;
}

int lista_tamanho(LISTA* lista){
   return lista->Num_items;
}

bool lista_vazia(LISTA* lista){
   return (lista->Num_items == 0);
}

bool lista_cheia(LISTA* lista){
    return (lista->Num_items == lista->Mem_tam);
}

void lista_imprimir(LISTA*lista){
   for (int i = 0; i <lista->Num_items; i++)
   {
      int chave = item_get_chave(lista->lista[i]);
      printf("[%d]; ", chave);
   }
 printf("\n");
}



