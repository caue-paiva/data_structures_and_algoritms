#define NIVEIS 5

#include "stdio.h"
#include "stdlib.h"
#include "item.h"

struct noskip_{
    ITEM* item;
    NOSKIP* prox_baixo;
    NOSKIP* prox_dir;
};

struct lista_skip_{
    NOSKIP** niveis;
}

typedef struct noskip_ NOSKIP;

typedef struct lista_skip_ lista_skip;


int random_fn(){
    return rand() % 2;
}


int compara_palavra(char* strBuscada, char* strAtual){
}

void adicionar_conteudo(ITEM*item, lista_skip* lista, int nivel, NOSKIP* abaixo){  //essa função é recursiva e deve ser inicialmente chamada o nivel 0 e o abaixo como null
       if (lista == NULL || nivel >= (NIVEIS-1)){return;}
       
       NOSKIP* novo_no = no_criar_skip(item);

       NOSKIP* aux = lista->niveis[nivel];
       NOSKIP* prox = aux;
       int valor_atual, valor_prox;
     
      if (aux == NULL){
         lista->niveis[nivel] = novo_no;
         novo_no->prox_baixo = abaixo;
      } else{
         do {
              aux = prox; 
              valor_atual = item_get_chave(aux->item);
              prox = aux->prox_dir;
              valor_prox = item_get_chave(prox->item);
          
            } while (prox != NULL || (valor_atual < valor_prox));

            aux->prox_dir = novo_no;
            novo_no->prox_dir = prox;
            novo_no->prox_baixo = abaixo;
           }

       if(random_fn()){
            adicionar_conteudo(item, lista, nivel+1,novo_no);
       } else {
        return;
       }

}

lista_skip* cria_entrada_letra(void){            
            lista_skip* nova_lista = (lista_skip*) malloc(sizeof(lista_skip));
            if (nova_lista ==NULL){ exit(1);}

            noskip** arr_niveis = (noskip**) malloc(sizeof(( noskip*) * NIVEIS));
            if(arr_niveis ==NULL){ exit(1);}

            for (int i = 0; i < NIVEIS; i++)
            {
                arr_niveis[i] = (noskip*) malloc(sizeof(noskip));
            }
            

            nova_lista->niveis = arr_niveis;
            return nova_lista;
}

NOSKIP* no_criar_skip(ITEM* item){
    NOSKIP* N1 = (NOSKIP*) malloc(sizeof(NOSKIP));
    if (N1 ==NULL){ exit(1);}
    N1->item = item;
    N1->prox_dir = NULL;
    N1->prox_baixo = NULL;
    return N1;
}

void imprime_valor(int procurado, lista_skip* lista){

    NOSKIP* novo_no = procura_lista();
    if (novo_no == NULL){printf("valor não achado \n");}

    int valor = item_get_chave(novo_no->item);
    printf(" valor reconhecido %d ", valor);

}

int recursao_abaixo(NOSKIP* NO, int procurado, int nivel){

}

NOSKIP* percorre_nivel(NOSKIP* NO, int procurado, int nivel){
      if (nivel < 0 || NO == NULL){return NULL;}
      
      NOSKIP*aux = NO;
      NOSKIP*prox = aux;
      int item_atual
       do {
          aux = prox;      
           item_atual = item_get_chave(aux->item);

          if (item_atual = procurado){    
            return aux;     
          }
          prox = aux->prox_dir;
       } while (prox != NULL);
         
         if(item_atual > procurado){

         }
       
}

NOSKIP* procura_lista(int procurado, lista_skip*lista, int nivel){ //nivel é chamada com 4
      if (nivel < 0){return NULL;}
      
      NOSKIP* topo = lista->niveis[nivel];
      NOSKIP*aux = topo;
      NOSKIP*prox = aux;
    
       do {
          aux = prox;      
          int item_atual = item_get_chave(aux->item);

          if (item_atual = procurado){    
            return aux;     
          }
          prox = aux->prox_dir;
       } while (prox != NULL);

       if (item_atual > procurado){
           aux = aux->prox_baixo;

       } else {
            procura_lista(procurado,lista, nivel-1);
       }

       

}

int procura_inserir(int elemento, lista_skip* lista, int nivel, NOSKIP*no){
      if (nivel < 0){return NULL;}
      
      if (lista->niveis[nivel] == NULL){
         procura_inserir(procurado,lista,nivel-1,no);
      }

       if (no == NULL){
          NOSKIP* topo = lista->niveis[nivel];
       } else{
          NOSKIP* topo = no;
       }

      NOSKIP*aux = topo;
      NOSKIP*prox = aux;
      int item_atual
    
       do {
          aux = prox;    
          prox = aux->prox_dir;
          if (prox == NULL){
            item_atual = item_get_chave(aux->item);
           
            if (item_atual > procurado){    
                return aux;     
             }

          } else {
             item_atual = item_get_chave(prox->item);
             if (item_atual = procurado){    
                return aux->prox_dir;     
             }
          }
        } while (item_atual < procurado && prox != NULL);
        procura_inserir(procurado,lista, nivel-1, aux->prox_baixo); 
}

NOSKIP* procura_lista2(int procurado, lista_skip*lista, int nivel, NOSKIP* no){ //nivel é chamada com 4, no começo como NULL
      if (nivel < 0){return NULL;}
      
      if (lista->niveis[nivel] == NULL){
         procura_lista2(procurado,lista,nivel-1,no);
      }

       if (no == NULL){
          NOSKIP* topo = lista->niveis[nivel];
       } else{
          NOSKIP* topo = no;
       }

      NOSKIP*aux = topo;
      NOSKIP*prox = aux;
      int item_atual
    
       do {
          aux = prox;    
          prox = aux->prox_dir;
          if (prox == NULL){
            item_atual = item_get_chave(aux->item);
           
            if (item_atual = procurado){    
                return aux;     
             }

          } else {
             item_atual = item_get_chave(prox->item);
             if (item_atual = procurado){    
                return (aux->prox_dir);     
             }
          }
        } while (item_atual < procurado && prox != NULL);
        procura_lista2(procurado,lista, nivel-1, aux->prox_baixo); 
}


NOSKIP* remove_lista(int procurado, lista_skip*lista, int nivel){ //nivel é chamada com 4
      if (nivel < 0){return NULL;}
      
      NOSKIP* topo = lista->niveis[nivel];
      NOSKIP* aux = topo;
      NOSKIP* prox = aux;
      NOSKIP* ante = NULL;
    
      do {
          ante = aux;
          aux = prox;      
          int item_atual = item_get_chave(aux->item);

          if (item_atual = procurado){                
               if (ante == NULL){
                   lista->niveis[nivel] = (aux->prox_dir);
                   item_apagar(aux->item);
                   free(aux);
                   aux == NULL;
               } else{
                 ante->prox_dir = aux->prox_dir;
               }
               break;  //quando da break a gnt tem a certeza que o aux é o item que tem que remover     
          }

          prox = aux->prox_dir;
       } while (prox != NULL);
       procura_lista(procurado,lista, nivel-1);

}