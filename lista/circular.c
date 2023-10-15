#include <stdlib.h>
#include <stdio.h>
#include "lista_encad.h"
#define N 100
typedef struct no NO;



struct no {
    NO* prox;
    int item;
};

struct lista_ {
   NO* comeco;
   NO* fim;
   int tam;
};
typedef struct lista_ lista;

NO* no_criar(int item){
   NO* no_novo = (NO*) malloc(sizeof(NO));
     if(!no_novo){exit(1);}

   no_novo->item = item;
   no_novo->prox = NULL;
   return no_novo;
}

lista* lista_criar(void){
    lista* lista_nova = (lista*) malloc(sizeof(lista));
        if(!lista_nova){exit(1);}
      
    lista_nova->comeco =NULL;
    lista_nova->fim =NULL;
    lista_nova->tam = 0;

    return lista_nova;
   
}

int lista_adicionar(lista* lista, int item, enum Position posicao){
   if(!lista){return 0;}
   NO* novo_no = no_criar(item);
 
 if(posicao == FIM){
   if(!lista->comeco){
      lista->comeco = novo_no;
      lista->fim = novo_no;
      lista->fim->prox = lista->comeco;
   }else{
      lista->fim->prox = novo_no;
      lista->fim = novo_no;
      lista->fim->prox = lista->comeco;
   }
 }else{
   if(!lista->comeco){ //lista vazia
      lista->comeco = novo_no;
      lista->fim = novo_no;
      lista->fim->prox = lista->comeco;
   }else{
       novo_no->prox = lista->comeco;
       lista->comeco = novo_no;
       lista->fim->prox = lista->comeco;
   }

 }
   lista->tam++;
}

int lista_procurar(lista* lista, int item){
   if(lista->tam == 0){return 0;}
   NO* atual = lista->comeco;
   int flag = 1;
   while(atual != lista->comeco || flag){
      flag = 0;
      if(atual->item == item){
         return 1;
      }
      atual = atual->prox;
   }
   return 0;
}

int lista_remover(lista* lista, int item){
    if(lista->tam==0){return 0;}
    NO* atual = lista->comeco;
    NO* ante=NULL;
    NO* temp;
    int flag;
    int loop_flag = 1;
    while(atual != lista->comeco || loop_flag){
     loop_flag = 0;
     temp = atual->prox;
     flag=0;
     if(atual->item==item){
       if(!ante){
         lista->comeco = atual->prox;
         lista->fim->prox = lista->comeco;
         if(lista->tam==1){ //lista vai ser vazia
            lista->fim = NULL;
         }
       }else{
          ante->prox = atual->prox;
          if(atual->prox == lista->comeco){  //remover do fim
            lista->fim = ante;
            lista->fim->prox = lista->comeco;
          }     
       }  
      flag =1;
      lista->tam--;
     }
       if(flag){
         free(atual);
         atual = temp;
       }else{
          ante = atual;
          atual = atual->prox;
       }
    }
    return 1;

}

void lista_printa(lista*lista){
   if(lista->tam == 0){return;}
   NO* aux = lista->comeco;
   do{
     printf("%d ",aux->item);
     aux = aux->prox;
   }while(aux != lista->comeco);
   printf("\n");
}

void lista_printa_fim(lista*lista){
   if(lista->tam == 0){return;}
   NO* aux = lista->fim;
   do{
     printf("%d ",aux->item);
     aux = aux->prox;
   }while(aux != lista->fim);
   printf("\n");
}



int main(){
lista* L1 = lista_criar();
lista*L2 = lista_criar();

lista_adicionar(L1,3,COMECO);
lista_adicionar(L1,5,COMECO);
lista_adicionar(L1,4,COMECO);
lista_adicionar(L1,7,COMECO);

lista_remover(L1,3);

lista_adicionar(L2,1,COMECO);
lista_adicionar(L2,3,COMECO);

lista_remover(L2,3);

lista_printa_fim(L1);
lista_printa_fim(L2);


}