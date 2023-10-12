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

int compara_no_string(NOSKIP* NO, char* str2){ 
     char* str1 = item_get_chave(NO->item);
     return strcmp(str1, str2);  
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

NOSKIP * procura_lista2(char* procurado, int nivel, NOSKIP *no) {
    if(nivel==1){
      if(no->prox_dir==NULL || (compara_no_string(no->prox_dir, procurado) > 0)){
        return NULL;
      }else if(compara_no_string(no->prox_dir, procurado) < 0){  
        return procura_lista2(procurado, nivel, no->prox_dir);
      }else{
        return no->prox_dir;
      }
      
    }// nao encontrado pois estou no nivel mais baixo e o proximo eh nulo ou maior entao nao existe
      
    if(no->prox_dir==NULL || (compara_no_string(no->prox_dir, procurado) > 0)){
      return procura_lista2(procurado, nivel-1, no->prox_baixo);
    }
    else if(compara_no_string(no->prox_dir, procurado) < 0){
      return procura_lista2(procurado, nivel, no->prox_dir);
    }
    else if(compara_no_string(no->prox_dir, procurado) == 0){
       no=no->prox_dir;
      while(no->prox_baixo!=NULL){
        no=no->prox_baixo;
      }
      return no;
    }
}

NOSKIP * muda_def(char* procurado, char* nova_def, int nivel, NOSKIP *no) {
    if(nivel==1){
      if(no->prox_dir==NULL || (compara_no_string(no->prox_dir, procurado) > 0)){
        return NULL;
      }else if(compara_no_string(no->prox_dir, procurado) < 0){  
        return muda_def(procurado,nova_def, nivel, no->prox_dir);
      }else{
          item_set_defini(no->prox_dir->item, nova_def);   
        return no->prox_dir;
      }
      
    }// nao encontrado pois estou no nivel mais baixo e o proximo eh nulo ou maior entao nao existe
      
    if(no->prox_dir==NULL || (compara_no_string(no->prox_dir, procurado) > 0)){
      return muda_def(procurado, nova_def,nivel-1, no->prox_baixo);
     }
     else if(compara_no_string(no->prox_dir, procurado) < 0){
      return muda_def(procurado,nova_def ,nivel, no->prox_dir);
     }
     else if(compara_no_string(no->prox_dir, procurado) == 0){
       no=no->prox_dir;
       item_set_defini(no->item, nova_def);
       while(no->prox_baixo!=NULL){
        no=no->prox_baixo;
        item_set_defini(no->item, nova_def);
      }
      return no;
    }

}

void remove_lista_skip(char* procurado, int nivel, NOSKIP *no) {// nivel é chamada com 4, no começo como NULL
    if(no->prox_dir != NULL){
    if(no->prox_dir->item != NULL){
    if(compara_no_string(no->prox_dir, procurado) == 0){
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
        printf("OPERACAO INVALIDA\n");
        return;
    }

    if(no->prox_dir==NULL){
        remove_lista_skip(procurado, nivel-1, no->prox_baixo);
        return;
    }

    if(no->prox_baixo==NULL ){
       if(compara_no_string(no->prox_dir, procurado) < 0){
        remove_lista_skip(procurado, nivel, no->prox_dir);
        return;
       }
    }

    if(no->prox_baixo==NULL ){
       if(compara_no_string(no->prox_dir, procurado) > 0){
        return;
       }
    }
    
    if(no->prox_dir != NULL){
    if(no->prox_dir-> item != NULL){
    if(compara_no_string(no->prox_dir, procurado) > 0){
        remove_lista_skip(procurado, nivel-1, no->prox_baixo);
        return;
    }
    if(compara_no_string(no->prox_dir, procurado) < 0){
        remove_lista_skip(procurado, nivel, no->prox_dir);
        return;
    }
    }
    }
    
}

int primeiro_char(NOSKIP* NO, char ca){
    ITEM* item = NO->item;
    char* str = item_get_chave(item);
    if (str[0] == ca){ return 1;}
    if (str[0] > ca){
        return 0;  //ficou maior, para de printar
    }else {
       return -1;  //menor, pode continuar
    };
    
}

void busca(char* procurado, int nivel, NOSKIP *no){  /*adicionar um printf na função de busca quebra a função e sua lógica de recursão, então foi criada uma wrapper function de busca*/
    NOSKIP* NO1 = procura_lista2(procurado,nivel,no);
    printf("palavra %s def %s", item_get_chave(NO1->item), item_get_defi(NO1->item));
}

void imprime_todas_palavras(char letra, NOSKIP* no){
 printf("letra %c \n", letra);
  while(no->prox_baixo != NULL){
      no = no->prox_baixo;
  }
  no = no->prox_dir;
 // printf("percorreu ate baixo");
 // printf(" no %p",no);
   NOSKIP* aux = no;
   int flag= 0;
   do{
      if(aux != NULL){
       if(primeiro_char(aux, letra) == 1){
         printf("\n");
         printf("palavra %s def %s", item_get_chave(aux->item), item_get_defi(aux->item));
         flag = 1 ;
       } else if (primeiro_char(aux,letra) == 0){
         if (!flag){
            printf("NAO HA PALAVRAS INICIADAS POR %c \n",letra);
         }
         return;
       }
      }
      aux = aux->prox_dir;
   } while(aux != NULL);

    if (!flag){
      printf("NAO HA PALAVRAS INICIADAS POR %c \n",letra);
   }
}

NOSKIP * insercao(char* inserir,char* defini , int nivel, NOSKIP *no) {
    if( no->prox_dir == NULL && nivel==1){
      NOSKIP *novo = (NOSKIP*) malloc(sizeof(NOSKIP));
      if(novo ==NULL){exit(1);}
     // printf(" nivel atual %d \n",nivel);
      novo->item=item_criar(inserir,defini);
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
    if(  no->prox_dir != NULL &&  no->prox_dir->item != NULL && (compara_no_string(no->prox_dir, inserir) > 0) && nivel==1){
      NOSKIP *novo = (NOSKIP*) malloc(sizeof(NOSKIP));
      if(novo ==NULL){exit(1);}
    //  printf(" nivel atual %d \n",nivel);
      novo->item=item_criar(inserir,defini);
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
        ins = insercao(inserir,defini , nivel-1, no->prox_baixo);
    }
      direction=0;
    }else if( no->prox_dir != NULL &&  no->prox_dir->item != NULL &&  (compara_no_string(no->prox_dir, inserir) > 0)){
      if(no->prox_baixo != NULL) {
        ins = insercao(inserir,defini ,nivel-1, no->prox_baixo);
    }
      direction=0;
    }else if((compara_no_string(no->prox_dir,inserir) < 0)){
        ins=insercao(inserir,defini ,nivel, no->prox_dir);
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
            printf(" { palavra: %s  definicao: %s  }", item_get_chave(N1->item), item_get_defi(N1->item));
        } else {
            printf("HEADER "); 
        }
        N1 = N1->prox_dir;
    }
    printf("\n"); 
}


int main(){
     srand((unsigned int)time(NULL));
     char str1[50]= "elcool";
     char def1[50] = "mel";
     char str2[50] = "eugenio";
     char def2[50] ="o maior de todos";
     char str3[50] = "emania";
     char str4[50]= "gggg";
     char def3[50] =" Supper";
     char newdef[50]= "kkkkkkkk";

     lista_skip* L1 = cria_skip_list();
     int val = 0;
     NOSKIP* NO1 = L1->niveis;
    

    insercao(str2,def2,NIVEIS,L1->niveis);
    insercao(str3,def3,NIVEIS,L1->niveis);
    insercao(str1,def1,NIVEIS,L1->niveis);
    busca(str2,NIVEIS, L1->niveis);

    imprime_todas_palavras('h', L1->niveis);
    printf("\n\n");
    do {
       
         printar_nivel(NO1);
         NO1 = NO1->prox_baixo; 

     } while (NO1 != NULL);


    printf("\n\n\n");


     remove_lista_skip(str4,NIVEIS,L1->niveis);
     muda_def(str2,newdef,NIVEIS,L1->niveis);
     NOSKIP* NO2 = L1->niveis;
     do {
         printar_nivel(NO2);
         NO2 = NO2->prox_baixo; 
     } while (NO2 != NULL);

 

}