


#include "item.h"
#include "Pilha.h"
#include <stdlib.h>
#include <stdio.h>


//codigo feito para testars pilhas com tamanho modificável
  

struct pilha{
   int top;
   ITEM* itemsV;
};  

//typedef pilha PILHA;


bool pilha_cheia(PILHA* pilha){
    if (pilha->top == TAM-1){
       return true;
    }else {return false;}
}

PILHA* pilha_criar(void){
       PILHA* nova_pilha = (PILHA*) malloc(sizeof(PILHA));
              if(nova_pilha == NULL){exit(1);}
       ITEM* str = (ITEM*) malloc(sizeof(char)*TAM);
             if(str==NULL){exit(1);}
       nova_pilha->itemsV = str;
       nova_pilha->top = -1;
       return nova_pilha;
}

void pilha_apagar(PILHA** pilha){
     free((*pilha)->itemsV);
     free(*pilha);
      *pilha = NULL; 
}

int pilha_tamanho(PILHA* pilha){
   return (pilha->top);
}

bool pilha_vazia(PILHA * pilha){
   if (pilha ->top  < 0){
      return true;
   } else { return false;}
}

ITEM* pilha_desempilhar(PILHA* pilha){
   if (pilha_vazia(pilha)){
      printf( "pilha underflow");
      exit(1);
   } 
   ITEM* result = item_get_chave(&(pilha->itemsV[pilha->top]));
   pilha->top--;
   return result;
}

bool pilha_empilhar (PILHA* pilha, ITEM *item){
   
   if (pilha->top >= (TAM-1)){
   return false;
   }
   pilha->top++;
   pilha->itemsV[pilha->top]->chave = new_item;
   return true;
}


char pilha_topo(PILHA* pilha){
    return (pilha->itemsV[pilha->top]->chave);
}

void pilha_print(PILHA* p){
   for(int i = 0; i <= p->top; i++ ){
      printf("%c\n", p->itemsV[i]->chave);
   }
}