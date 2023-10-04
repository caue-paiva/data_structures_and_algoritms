#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "lista.h"

//typedef int F_type;
typedef struct no NO;

struct no{
    ITEM* item;
    NO* prox;
};



struct lista_{
    NO*  fim;
    NO* comeco;
    int tam;
};

typedef struct lista_ lista_;

 lista_ * lista_criar(void){
     lista_* F1 = (lista_*) malloc(sizeof(lista_));
     if (F1==NULL){exit(1);}
    F1->tam = 0;
    F1->fim =NULL;
    F1->comeco =NULL;
    return F1;
}

bool lista_cheia(lista_ *lista){}

NO* no_criar(ITEM* item){
    NO* N1 = (NO*) malloc(sizeof(NO));
      if (N1 ==NULL){ exit(1);}
    N1->item = item;
    N1->prox = NULL;
    return N1;
}

bool lista_inserir( lista_* lista, ITEM* item){
    
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

void lista_imprimir(lista_* lista){
     if (lista->tam == 0){return;}
     NO* aux;
     aux = lista->comeco;
     //printf("primeiro valor %d \n", aux->item);
     do{
        ITEM* item = (aux->item);
        int chave = item_get_chave(item);
        printf("%d \n", chave);
       // printf("%d\n", lista->tam);
        aux = aux->prox;
     }while(aux!= NULL);

}

bool lista_apagar(lista_ **lista){
    if ((*lista)->tam == 0){
        free(*lista);
        *lista = NULL;
        return true;}
    //printf(" tam : %d \n", (*lista)->tam);
     NO* aux;
     NO* aux2;
     aux = (*lista)->comeco;
     
    do{
        aux2 = aux->prox;
        item_apagar(&(aux->item));
        free(aux);
        aux = aux2;
      }while((aux2) != NULL);  
       
     free(*lista);
     *lista = NULL;
     return true;
}

ITEM* lista_remover(lista_* lista, int chave){
    if (lista->tam == 0){return NULL;}
    
    NO* aux_atual = lista->comeco;
    NO* aux_ante = NULL;

    for (int i = 0; i < lista->tam; i++){
        ITEM* aux_item = aux_atual->item;
        int aux_chave = item_get_chave(aux_item);
        //printf("%d\n", aux_item);

        if (aux_chave == chave){
            //printf("entrou function");
           // NO* aux_ante = aux->ante;
           // NO* aux_prox = aux->prox;
           
            if(aux_atual->prox != NULL){
             aux_ante->prox = aux_atual->prox;
             free(aux_atual);
             --(lista->tam);
             return aux_item;

            } else{
              
              if(aux_ante == NULL){  //caso a lista so tenha um elemento
                lista->comeco == NULL;
                lista->fim = NULL;
                lista->tam = 0;
                free(aux_atual);
                return aux_item;
              }
              aux_ante->prox=NULL;
              lista->fim = aux_ante;
              --(lista->tam);
              free(aux_atual);
              return aux_item;
              
            }
              
        }
        aux_ante = aux_atual;
        aux_atual = aux_atual->prox;
    }
    return NULL;
}

ITEM* lista_busca(lista_* lista, int chave){
    if (lista->tam==0) {return NULL;}
    NO* atual = lista->comeco;
    ITEM* aux_item;
    int aux_chave;
    
    do{ 
        aux_chave = item_get_chave( (aux_item= (atual->item)));
        if (aux_chave == chave){
            return aux_item;
        }
        atual = atual->prox;
    } while (atual != NULL);
    
    return NULL;
 
}

int lista_tamanho(lista_* lista){
    if (lista==NULL){return -329171;}
    return (lista->tam);
}

bool lista_vazia(lista_* lista){
     if (lista==NULL){return NULL;}
     return (lista->tam == 0);
}

bool lista_inverter (lista_ ** lista){
    if ((*lista)->tam <= 1){return false;}
    printf("tam lista : %d \n",(*lista)->tam );
    NO* ante= NULL;
    NO* atual = (*lista)->comeco;
    NO* prox1 = atual->prox;

    do
    {  
      ante = atual;
      atual = prox1;
      prox1 = prox1->prox;
      atual->prox = ante;
        
    } while (prox1 != NULL);
    
    NO* temp_no = (*lista)->fim;
    (*lista)->fim = (*lista)->comeco;
    (*lista)->comeco = temp_no;
    (*lista)->fim->prox = NULL;
    return true;

}

int main(){
ITEM* I1;
ITEM* I2;
ITEM* I3;
ITEM* I4;
lista_* F1 = lista_criar();
I1 = item_criar(3);
I2 = item_criar(5);
I3 = item_criar(7);
//printf("lista VAZIA : %d \n", lista_vazia(F1));
lista_inserir(F1,I1);
lista_inserir(F1,I2);
lista_inserir(F1,I3);

I4 = lista_busca(F1,7);
//printf(" item buscado : %d \n", item_get_chave(I4));

//lista_remover(F1,7);

lista_imprimir(F1);

lista_inverter(&F1);
printf("\n\n");
lista_imprimir(F1);
lista_apagar(&F1);







}



