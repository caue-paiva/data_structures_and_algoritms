#define NIVEIS 5

#include "stdio.h"
#include "stdlib.h"
#include "item.h"
#include "string.h"
#include "time.h"

typedef struct noskip_ NOSKIP;
typedef struct lista_skip_ lista_skip;

struct noskip_{
    ITEM* item;
    NOSKIP* prox_baixo;
    NOSKIP* prox_dir;
};


struct lista_skip_{
    NOSKIP* niveis;
};


int random_fn(){
    return rand() % 2;
}

int compara_strings(char* str1, char* str2){
    int value =  strcmp(str1, str2);
}

NOSKIP* adiciona_zerado(NOSKIP*debaixo, int nivel){
       if (nivel == NIVEIS){ return NULL;}

}

NOSKIP* no_criar_skip(ITEM* item){
    NOSKIP* N1 = (NOSKIP*) malloc(sizeof(NOSKIP));
    if (N1 ==NULL){ exit(1);}
    N1->item = item;
    N1->prox_dir = NULL;
    N1->prox_baixo = NULL;
    return N1;
}


NOSKIP* no_criar_skip_header(void){
    NOSKIP* N1 = (NOSKIP*) malloc(sizeof(NOSKIP));
    if (N1 ==NULL){ exit(1);}
    N1->item = NULL;
    N1->prox_dir = NULL;
    N1->prox_baixo = NULL;
    return N1;
}

lista_skip* cria_skip_list(void){               
            lista_skip* nova_lista = (lista_skip*) malloc(sizeof(lista_skip));
            if (nova_lista ==NULL){ exit(1);}

            NOSKIP* no = no_criar_skip_header();
            if (no == NULL){ exit(1);}
            nova_lista->niveis = no;
            
            NOSKIP* aux = no;
            aux->prox_dir = NULL;
            for (int i = 0; i < NIVEIS-1; i++)
            {   NOSKIP* no1 = no_criar_skip_header();
                if (no == NULL){ exit(1);}

                aux->prox_baixo = no1;     
                no1->prox_dir = NULL;
                aux = no1;
            }
            return nova_lista;
}

NOSKIP * procura_lista2(int procurado, int nivel, NOSKIP *no) {// nivel é chamada com 4, no começo como NULL
    if(nivel==1){
      if(no->prox_dir==NULL || item_get_chave(no->prox_dir->item)>procurado){
        return NULL;
      }else if(item_get_chave(no->prox_dir->item)<procurado){
        return procura_lista2(procurado, nivel, no->prox_dir);
      }else{
        return no->prox_dir;
      }
      
    }// nao encontrado pois estou no nivel mais baixo e o proximo eh nulo ou maior entao nao existe
      
    if(no->prox_dir==NULL || item_get_chave(no->prox_dir->item)>procurado){
      return procura_lista2(procurado, nivel-1, no->prox_baixo);
    }
    else if(item_get_chave(no->prox_dir->item)<procurado){
      return procura_lista2(procurado, nivel, no->prox_dir);
    }
    else if(item_get_chave(no->prox_dir->item)==procurado){
       no=no->prox_dir;
      while(no->prox_baixo!=NULL){
        no=no->prox_baixo;
      }
      return no;
    }
}

void remove_lista_skip(int procurado, int nivel, NOSKIP *no) {// nivel é chamada com 4, no começo como NULL
    if(no->prox_dir != NULL){
    if(no->prox_dir->item != NULL){
    if(item_get_chave(no->prox_dir->item)==procurado){
        NOSKIP* toDelete=no->prox_dir;
        no->prox_dir=no->prox_dir->prox_dir;
        if(nivel==1){
            item_apagar(&toDelete->item);
        }
        free(toDelete);
        if(nivel!=1){
            remove_lista_skip(procurado, nivel-1, no->prox_baixo);
        }
    }
    }
    }
   
    if(no->prox_dir==NULL && no->prox_baixo==NULL){//nao existe o procurado
        return;
    }

    if(no->prox_dir==NULL){
        remove_lista_skip(procurado, nivel-1, no->prox_baixo);
        return;
    }

    if(no->prox_baixo==NULL ){
       if(item_get_chave(no->prox_dir->item) < procurado){
        remove_lista_skip(procurado, nivel, no->prox_dir);
        return;
       }
    }

    if(no->prox_baixo==NULL ){
       if(item_get_chave(no->prox_dir->item) > procurado){
        return;
       }
    }
    
    if(no->prox_dir != NULL){
    if(no->prox_dir-> item != NULL){
    if(item_get_chave(no->prox_dir->item)>procurado){
        remove_lista_skip(procurado, nivel-1, no->prox_baixo);
        return;
    }
    if(item_get_chave(no->prox_dir->item)<procurado){
        remove_lista_skip(procurado, nivel, no->prox_dir);
        return;
    }
    }
    }
    
}

/*int primeiro_char(NOSKIP* NO, char ca){
    ITEM* item = NO->item;
    char* str = item_get_chave(item);
    if (str[0] == ca){return 1;}
    if (str[0] > ca){
        return 0;
    }else {
     return -2;
    };
    
}*/

/*void imprime_todas_palavras(char procurado, int nivel, NOSKIP *no) {// nivel é chamada com 4, no começo como NULL
   
   if(nivel==1){
      if(no->prox_dir==NULL){
        return NULL;
      } else if(!primeiro_char(no->prox_dir, procurado)){
          NULL;
      }else if(primeiro_char(no->prox_dir, procurado)){
          printf("%c \n", item_get_chave(no->prox_dir->item));
          imprime_todas_palavras(procurado, nivel, no->prox_dir);
      }else{
           printf("%c \n", item_get_chave(no->prox_dir->item));
      }
      
    }// nao encontrado pois estou no nivel mais baixo e o proximo eh nulo ou maior entao nao existe
      
    if(no->prox_dir==NULL){
      procura_lista2(procurado, nivel-1, no->prox_baixo);
    } else if(!primeiro_char(no->prox_dir, procurado)){
      procura_lista2(procurado, nivel-1, no->prox_baixo);
    }
    else if(primeiro_char(no->prox_dir, procurado)){
            printf("%c \n", item_get_chave(no->prox_dir->item));
            procura_lista2(procurado, nivel, no->prox_dir);
    } else {
            procura_lista2(procurado, nivel, no->prox_dir);
    }
  
}*/



NOSKIP * insercao(int inserir, int nivel, NOSKIP *no) {
    if( no->prox_dir == NULL && nivel==1){
      NOSKIP *novo = (NOSKIP*) malloc(sizeof(NOSKIP));
      if(novo ==NULL){exit(1);}
     // printf(" nivel atual %d \n",nivel);
      novo->item=item_criar(inserir);
      novo->prox_dir=no->prox_dir;
      novo->prox_baixo=NULL;
      no->prox_dir=novo;
      if(random_fn()){
       // printf("Promoting node with key %d to level %d\n", inserir, nivel);
        return novo;
      }
       // printf("Not promoting node with key %d beyond level %d\n", inserir, nivel);
      return NULL;
    }
    if(  no->prox_dir != NULL &&  no->prox_dir->item != NULL && item_get_chave(no->prox_dir->item)>inserir && nivel==1){
      NOSKIP *novo = (NOSKIP*) malloc(sizeof(NOSKIP));
      if(novo ==NULL){exit(1);}
    //  printf(" nivel atual %d \n",nivel);
      novo->item=item_criar(inserir);
      novo->prox_dir=no->prox_dir;
      novo->prox_baixo=NULL;
      no->prox_dir=novo;
      if(random_fn()){
     //   printf("Promoting node with key %d to level %d\n", inserir, nivel);
        return novo;
      }
       // printf("Not promoting node with key %d beyond level %d\n", inserir, nivel);
      return NULL;
    }

    NOSKIP *ins=NULL;
    int direction=-1;
    if(no->prox_dir==NULL){
      if(no->prox_baixo != NULL) {
        ins = insercao(inserir, nivel-1, no->prox_baixo);
    }
      direction=0;
    }else if( no->prox_dir != NULL &&  no->prox_dir->item != NULL && item_get_chave(no->prox_dir->item)>inserir){
      if(no->prox_baixo != NULL) {
        ins = insercao(inserir, nivel-1, no->prox_baixo);
    }
      direction=0;
    }else if(item_get_chave(no->prox_dir->item) < inserir){
        ins=insercao(inserir, nivel, no->prox_dir);
        direction=1;
    }

    if(direction==0 && ins!=NULL){
      NOSKIP *novo = (NOSKIP*) malloc(sizeof(NOSKIP));
     // printf(" nivel atual %d \n",nivel);
      novo->item=ins->item;
      novo->prox_dir=no->prox_dir;
      novo->prox_baixo=ins;
      no->prox_dir=novo;
      if(random_fn()){
       // printf("Promoting node with key %d to level %d\n", inserir, nivel);
        return novo;
      }
       // printf("Not promoting node with key %d beyond level %d\n", inserir, nivel);
      return NULL;  
    }else if(direction==1 && ins!=NULL){
      return ins;
    }
    return NULL;
}

void printar_nivel(NOSKIP* no) {
    NOSKIP* N1 = no;
    while (N1 != NULL) {
       
        if(N1->item != NULL) {
            printf("%d ", item_get_chave(N1->item));
        } else {
            printf("HEADER "); 
        }
        N1 = N1->prox_dir;
    }
    printf("\n"); 
}
///funções antigas

int main(){
    srand((unsigned int)time(NULL));
     

     lista_skip* L1 = cria_skip_list();
     int val = 0;
     NOSKIP* NO1 = L1->niveis;

    insercao(5,NIVEIS,L1->niveis);
    insercao(6,NIVEIS,L1->niveis);
    insercao(1,NIVEIS,L1->niveis);
    insercao(2,NIVEIS,L1->niveis);
    insercao(8,NIVEIS,L1->niveis);


      do {
         //printf("%d", val);
         printar_nivel(NO1);
         NO1 = NO1->prox_baixo; 

     } while (NO1 != NULL);

   //NOSKIP* NO3 = procura_lista2(6,NIVEIS,L1->niveis);
  printf("\n\n\n");
  // int val2 = item_get_chave(NO3->item);
  // printf("%d \n", val1);

  remove_lista_skip(5,NIVEIS,L1->niveis);
  remove_lista_skip(1,NIVEIS,L1->niveis);
  remove_lista_skip(8,NIVEIS,L1->niveis);
  remove_lista_skip(2,NIVEIS,L1->niveis);
  
  
  //NOSKIP* NO2 = procura_lista2(6,NIVEIS,L1->niveis);
  //int val1 = item_get_chave(NO2->item);
   //printf("%d \n", val1);
     NOSKIP* NO2 = L1->niveis;
     do {
         //printf("%d", val);
         printar_nivel(NO2);
         NO2 = NO2->prox_baixo; 

     } while (NO2 != NULL);


}