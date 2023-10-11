#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "lista.h"
#include <time.h>

//typedef int F_type;
typedef struct no NO;
typedef struct no NOSKIP;
typedef struct lista_ lista_;
//typedef Letra LETRA;


struct no{
    ITEM* item;
    NO* nivel;
    lista_* lista;
};

struct noskip{
    ITEM* item;
    NOSKIP* prox_niv;
    NOSKIP* prox_dir;
};


struct lista_{
    NO*  fim;
    NO* comeco;
    int tam;
};

struct lista_skip{
    NOSKIP*  fim;
    NOSKIP* comeco;
    int tam;
};

typedef struct lista_ lista_;
typedef struct lista_skip lista_skip;

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
    N1->nivel = NULL;
    return N1;
}

NO* no_criar_skip(ITEM* item){
    NOSKIP* N1 = (NOSKIP*) malloc(sizeof(NOSKIP));
      if (N1 ==NULL){ exit(1);}
    N1->item = item;
    N1->prox_niv = NULL;
    return N1;
}


bool lista_novo_nivel(lista_skip* lista){
      
    NOSKIP* novo_no = no_criar_skips();

    if(lista->tam == 0){
        //printf("primeiro item\n");
        lista->fim = novo_no;
        lista->comeco = novo_no;
    } else{
       // printf("item não primeiro \n");
        lista->fim->prox_niv = novo_no;
        lista->fim = novo_no;
    }
    ++(lista->tam);
    return true;

}

/*bool compara_palavra(char* strBuscada, char* strAtual){



}

int random_fn(){
    return rand() % 2;
}

ITEM* procura_lista(char* str, lista_skip*lista){
      NOSKIP* topo = lista->fim;

      NOSKIP*aux = topo;
      NOSKIP*prox = aux;
    
       do {
          aux = prox; 
          char* str = item_get_chave(aux->item);
          compara_palavra()
          prox = aux->prox_dir;
       }{prox != NULL};


}

void adicionar_conteudo(NOSKIP* noatual, ITEM*item, lista_skip* lista){  //essa função é recursiva e deve ser inicialmente chamada com o inicio da skiplist (primeiro nivel)
       if (noatual == NULL){return;}
    
       NOSKIP*aux = noatual;
       NOSKIP*prox = aux;
      
       do {
          aux = prox; 
          prox = aux->prox_dir;
       }{prox != NULL};

       NOSKIP* novo_no = no_criar_skip(item);
       aux->prox_dir = novo_no;

       if(random_fn()){
            if(noatual->prox_nivel == NULL){
             lista_novo_nivel(lista);
            }
            adicionar_conteudo((noatual->prox_nivel),item, lista)
       } else {
        return;
       }

}


bool lista_inserir( lista_* lista, ITEM* item){ //função de 
    
    NO* novo_no = no_criar(item);

    if(lista->tam == 0){
        //printf("primeiro item\n");
        lista->fim = novo_no;
        lista->comeco = novo_no;
    } else{
       // printf("item não primeiro \n");
        lista->fim->prox_nivel = novo_no;
        lista->fim = novo_no;
    }

    ++(lista->tam);

    return true;

}
*/
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
        aux = aux->prox_nivel;
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
        aux2 = aux->prox_nivel;
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
           // NO* aux_prox_nivel = aux->prox_nivel;
           
            if(aux_atual->prox_nivel != NULL){
             aux_ante->prox_nivel = aux_atual->prox_nivel;
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
              aux_ante->prox_nivel=NULL;
              lista->fim = aux_ante;
              --(lista->tam);
              free(aux_atual);
              return aux_item;
              
            }
              
        }
        aux_ante = aux_atual;
        aux_atual = aux_atual->prox_nivel;
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
        atual = atual->prox_nivel;
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
    NO* prox_nivel1 = atual->prox_nivel;

    do
    {  
      ante = atual;
      atual = prox_nivel1;
      nivel1 = nivel1->nivel;
      atual->nivel = ante;
        
    } while (nivel1 != NULL);
    
    NO* temp_no = (*lista)->fim;
    (*lista)->fim = (*lista)->comeco;
    (*lista)->comeco = temp_no;
    (*lista)->fim->nivel = NULL;
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



