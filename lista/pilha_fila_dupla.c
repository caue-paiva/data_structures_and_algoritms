#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"


typedef int F_type;
typedef struct no NO;
struct no{
    F_type item;
    NO* ante;
    NO* prox;
};


typedef struct{
    NO*  fim;
    NO* comeco;
    int tam;
} lista;

lista* lista_criar(){
    lista* F1 = (lista*) malloc(sizeof(lista));
    if (F1==NULL){exit(1);}
    
    F1->tam = 0;
    F1->fim =NULL;
    F1->comeco =NULL;
    return F1;
}


NO* no_criar(F_type item){
    NO* N1 = (NO*) malloc(sizeof(NO));
    if (N1 ==NULL){ exit(1);}
   
    N1->item = item;
    N1->ante = NULL;
    N1->prox = NULL;
    return N1;
}


bool lista_adicionar(F_type item, lista* lista){
    NO* novo_no = no_criar(item);

    if(lista->tam == 0){
        //printf("primeiro item\n");
        lista->fim = novo_no;
        lista->comeco = novo_no;
    } else{
       // printf("item não primeiro \n");
        lista->fim->prox = novo_no;
        novo_no->ante = lista->fim;
        lista->fim = novo_no;
    }
    ++(lista->tam);
    return true;
}

void lista_printar_come(lista* lista){
     if (lista->tam == 0){return;}
     NO* aux;
     aux = lista->comeco;
     //printf("primeiro valor %d \n", aux->item);
     do{
        F_type item = (aux->item);
        printf("%d \n", item);
       // printf("%d\n", lista->tam);
        aux = aux->prox;
     }while(aux!= NULL);
}

bool lista_remover(F_type item, lista* lista){
    if (lista->tam == 0){return false;}

    NO* aux = lista->comeco;
    for (int i = 0; i < lista->tam; i++){
        F_type aux_item = aux->item;
        //printf("%d\n", aux_item);

        if (aux_item == item){
            //printf("entrou function");
            NO* aux_ante = aux->ante;
            NO* aux_prox = aux->prox;
           
            if(aux->prox != NULL){
              aux->prox->ante = aux_ante;
            } else{
              aux_ante->prox=NULL;
              lista->fim = aux_ante;
            }

            if (aux->ante != NULL){
               aux_ante->prox = aux->prox;
            }else{
                aux->prox->ante = NULL;
                lista->comeco = aux->prox;
            }
              
            free(aux);
            lista->tam--;
            return true;
        }
        aux = aux->prox;
    }
    return false;
}

void lista_printar_fim(lista* lista){
     if (lista->tam == 0){return;}
     NO* aux;
     aux = lista->fim;
     //printf("primeiro valor %d \n", aux->item);
     do{
        F_type item = (aux->item);
        printf("%d \n", item);
       // printf("%d\n", lista->tam);
        aux = aux->ante;
     }while(aux!= NULL);
}

void lista_apagar(lista**lista){
    if ((*lista)->tam == 0){return;}
     NO* aux;
     NO* aux2;
     aux = (*lista)->comeco;
     aux2 = aux->prox;
     free(aux);

     while(aux2){
        aux = aux2;
        aux2 = aux2->prox;
        free(aux);
     }
   //   do{
   //      aux = aux2;
   //      aux2 = aux2->prox;
   //   }while(aux2!= NULL);
    
     free(*lista);
     *lista = NULL;
}

void fp_adiciona(lista* lista, F_type item){
   if(!lista){exit(1);}
   NO* novo_no = no_criar(item);

   if(lista->tam == 0){
      lista->comeco = novo_no;
      lista->fim = novo_no;     
   }

   lista->fim->prox = novo_no;
   novo_no->ante = lista->fim;
   lista->fim = novo_no;
   lista->tam++;
}

F_type pilha_pop(lista* lista){
       NO* final = lista->fim;
       F_type item = final->item;
       lista->fim = lista->fim->ante;
       free(final);
       if(lista->fim)
         lista->fim->prox = NULL;
       lista->tam--;
       return item;
}

F_type fila_pop(lista* lista){
       if(lista->tam == 0){exit(1);}

       NO* come = lista->comeco;
       F_type item = come->item;
       lista->comeco = lista->comeco->prox;
       if(lista->comeco)
          lista->comeco->ante = NULL;
       free(come);
       lista->tam--;
       return item;
}


int main(){

lista* L1 = lista_criar();
lista* L2 = lista_criar();

fp_adiciona(L1,2);
fp_adiciona(L1,3);
fp_adiciona(L1,5);
fp_adiciona(L1,7);

fp_adiciona(L2,2);
fp_adiciona(L2,3);
fp_adiciona(L2,5);
fp_adiciona(L2,7);

for (int i = 0; i < 4; i++)
{
  printf("versao fila %d ",fila_pop(L1));
}
printf("\n\n");
for (int i = 0; i < 4; i++)
{
  printf("versao pilha %d ", pilha_pop(L2));
}

}