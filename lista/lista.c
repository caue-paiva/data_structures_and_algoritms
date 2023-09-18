#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"

typedef int F_type;
typedef struct no NO;
struct no{
    F_type item;
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
        lista->fim = novo_no;
    }

    ++(lista->tam);

    return true;

}

void lista_printar(lista* lista){
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

void lista_apagar(lista**lista){
    if ((*lista)->tam == 0){return;}
     NO* aux;
     NO* aux2;
     aux = (*lista)->comeco;
     aux2 = aux->prox;
     do{
        free(aux);
        aux = aux2;
        aux2 = aux2->prox;
     }while(aux2!= NULL);
    
     free(*lista);
     *lista = NULL;
}


int main(){

lista* F1 = lista_criar();

lista_adicionar(3,F1);
lista_adicionar(6,F1);
lista_adicionar(7,F1);
lista_adicionar(8,F1);

lista_printar(F1);

lista_apagar(&F1);







}



