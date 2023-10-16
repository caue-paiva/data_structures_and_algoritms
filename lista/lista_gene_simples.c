#include "stdio.h"
#include "stdlib.h"

typedef struct no NO;

struct no{
  union { 
    int* atomo;
    NO* sublista;
  }compo;

  int tipo; //0 = inteiro, 1 = sublista
  NO*prox;
};

NO* lista_gen_criar(void){
   NO* novo_no = (NO*) malloc(sizeof(NO));
      if(!novo_no){exit(1);}
   novo_no->tipo = 1;
   novo_no->compo.atomo = NULL;
   novo_no->prox = NULL;
   return novo_no;
}

NO* no_criar(int* item){
   NO* novo_no = (NO*) malloc(sizeof(NO));
      if(!novo_no){ exit(1);}
   novo_no->tipo = 0;
   novo_no->compo.atomo = item;
   novo_no->prox =NULL;
   return novo_no;
}

int lista_gen_add(int tipo, void* item, NO* lista){
   if(!lista){return 0;}
   NO* aux = lista;
   if(tipo ==0){
      NO* novo_no = no_criar(item);
      while(aux->prox){aux = aux->prox;}
      aux->prox = novo_no;
      return 1;
   }else if(tipo ==1){
      NO* novo_no = lista_gen_criar();
      novo_no->compo.sublista = item;
      while(aux->prox){aux = aux->prox;}
      aux->prox = novo_no;
      return 1;
   }else{
      return 0;
   }
}

void lista_gen_print(NO* lista){
   if(!lista){return;}

   NO* aux = lista;
   printf("[");
   while(aux){
      if(aux->tipo == 0){
         printf("%d ", *aux->compo.atomo);
      }else{
         lista_gen_print(aux->compo.sublista);
      }
      aux = aux->prox;
   }
   printf("]");
}

int lista_gen_remover(void* item, int tipo, NO* lista){
    if(!lista){return 0;}  
    NO* aux = lista;
    NO* ante = NULL;
    NO* temp;
    while(aux){
      if(item == aux->compo.sublista){
         if(!ante){
               temp  = lista;
               lista = lista->prox;
               free(temp);
         }else{
               temp = aux;
               ante->prox = aux->prox;
               free(temp);
         }
      }else if(aux->tipo == 1){lista_gen_remover(item,tipo,aux->compo.sublista);}
      ante = aux;
      aux = aux->prox;
  }
}

int busca_lista_gene(int item, NO* lista){
  // if(!lista){return 0 ;}
   NO* aux = lista;
   int flag =0;
   while(aux){
      if(aux->tipo == 1){
         if (busca_lista_gene(item, aux->compo.sublista)) return 1;
      }else if (*(aux->compo.atomo) == item){
        // printf(" existe \n");
         return 1;
      }
      aux = aux->prox;
   }
   if(!flag){

      return 0;}
   // printf(" não existe \n");
}

int main(){

   NO* L1 = lista_gen_criar();
   NO* L2 = lista_gen_criar();
   int a,b,c,d;
   a = 4;
   c=5;
   b=0;
   d=4;

 //  lista_gen_add(1,L2,L1);
   lista_gen_add(0,&a,L1);
   lista_gen_add(0,&b,L1);
 
   lista_gen_add(1,L2,L1);
   lista_gen_add(0,&c,L2);
   lista_gen_add(0,&d,L2);
   lista_gen_print(L1);
  // busca_lista_gene(5,L1);
   printf("existe: %d \n",busca_lista_gene(5,L1));
   //lista_gen_add(1,L2,L1);
   lista_gen_print(L2);
}