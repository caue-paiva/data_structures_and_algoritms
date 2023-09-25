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
    NO*  senti;
    NO* comeco;
    int tam;
} lista;

lista* lista_criar(){
    lista* F1 = (lista*) malloc(sizeof(lista));
    if (F1==NULL){exit(1);}
    
    F1->tam = 0;
    
    F1->comeco =NULL;
    F1->senti=NULL;
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
        lista->comeco = novo_no;
        lista->senti = novo_no;
        lista->comeco->ante = lista->senti;
        lista->senti->prox = lista->comeco;
    } else{
       // printf("item não primeiro \n");
        lista->senti->prox = novo_no;
        novo_no->ante = lista->senti;
        lista->senti = novo_no;
        lista->senti->prox = lista->comeco;
        lista->comeco->ante =  lista->senti;

    }
    ++(lista->tam);
    return true;
}

void lista_printar_come(lista* lista){
     if (lista->tam == 0){return;}
     NO* aux;
     aux = lista->comeco;
     //printf("primeiro valor %d \n", aux->item);     
     do {
        F_type item = (aux->item);
        printf("%d \n", item);
       // printf("%d\n", lista->tam);
        aux = aux->prox;

     } while(aux !=lista->comeco);
     
 
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
           
            if(aux->prox != lista->comeco){
              aux->prox->ante = aux_ante;
            } else{
              aux_ante->prox= lista->comeco;
              lista->senti = aux_ante;
              lista->senti->prox = lista->comeco;
            }

            if (aux->ante != lista->senti){
               aux_ante->prox = aux->prox;
            }else{
                aux->prox->ante = lista->senti;
                lista->comeco = aux->prox;
                lista->comeco->ante = lista->senti;
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
     aux = lista->senti;
     bool prim_iter = true;
     //printf("primeiro valor %d \n", aux->item);
    
     do{
        F_type item = (aux->item);
         printf("%d \n", item);
         //printf("%d\n", lista->tam);
         aux = aux->ante;
     }while(aux != lista->senti);
    
}

void lista_apagar(lista**lista){
    if ((*lista)->tam == 0){
        free(*lista);
        *lista = NULL;   
        return;
    
    }
     NO* aux;
     NO* aux2;
     aux = (*lista)->comeco;
     aux2 = aux->prox;
     do{
        free(aux);
        aux = aux2;
        aux2 = aux2->prox;
     }while(aux2 != (*lista)->comeco);
    
     free(*lista);
     *lista = NULL;
}

int main(){

lista* F1 = lista_criar();

lista_adicionar(3,F1);
lista_adicionar(6,F1);
lista_adicionar(7,F1);
lista_adicionar(8,F1);

lista_printar_come(F1);

lista_remover(8, F1);
lista_remover(3, F1);
printf("\n");
lista_printar_fim(F1);


lista_apagar(&F1);

}