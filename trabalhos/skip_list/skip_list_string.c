#include "skip_list_string.h"


  /* FEITO POR
  Caue Paiva Lira. NUSP: 14675416
  Thales Sena de Queiroz. NUSP: 14608873
*/

typedef struct noskip_ NOSKIP;    //typedef para não ter que escrever struct antes de todos os NOS

struct noskip_{  //Nó da lista, contem o item, e o proximo (direita) e inferior (baixo)
    ITEM* item;
    NOSKIP* prox_baixo;
    NOSKIP* prox_dir;
};


int random_fn(){
    return rand() % 2; //função de random para ver se vai adicionar acima ou não
}

int compara_no_string(NOSKIP* NO, char* str2){  /*essa função compara o conteudo de um nó com a string buscada, ele foi feito para tornar expressoes de  ifs 
                                                 mais claras e menos verbosas nas funções de busca,inserção,alteração */
     char* str1 = item_get_chave(NO->item);
     return strcmp(str1, str2);  
}

NOSKIP* no_criar_skip(ITEM* item){ //cria um nó normal com conteudo
    NOSKIP* N1 = (NOSKIP*) malloc(sizeof(NOSKIP));
    if (N1 ==NULL){ exit(1);}
    N1->item = item;
    N1->prox_dir = NULL;
    N1->prox_baixo = NULL;
    return N1;
}

NOSKIP* no_criar_skip_header(void){ //cria os nós headers (começo de um nível), sem conteúdo
    NOSKIP* N1 = (NOSKIP*) malloc(sizeof(NOSKIP));
    if (N1 ==NULL){ exit(1);}
    N1->item = NULL;
    N1->prox_dir = NULL;
    N1->prox_baixo = NULL;
    return N1;
}

NOSKIP* cria_skip_list(void){  //cria todos os nós headers e faz cada um deles ser ligado verticalmente ao outro
            NOSKIP* no = no_criar_skip_header();
            if (no == NULL){ exit(1);}
               
            NOSKIP* aux = no;
            aux->prox_dir = NULL;
            for (int i = 0; i < NIVEIS-1; i++)
            {   NOSKIP* no1 = no_criar_skip_header();
                if (no1 == NULL){ exit(1);}

                aux->prox_baixo = no1;     
                no1->prox_dir = NULL;
                aux = no1;
            }
            return no;
}


NOSKIP * procura_lista2(char* procurado, int nivel, NOSKIP *no) { //função de procura de um elemento na lista, usa recursão
    if(nivel==1){
      if(no->prox_dir==NULL || (compara_no_string(no->prox_dir, procurado) > 0)){ //ultimo nível e o próximo é nulo ou maior que o buscado, quer dizer que ele não esta na lista
        return NULL;
      }else if(compara_no_string(no->prox_dir, procurado) < 0){  
        return procura_lista2(procurado, nivel, no->prox_dir); //o proximo é menor, vai andar para direita
      }else{
        return no->prox_dir; //achou a palavra, retona ela
      }
      
    }// nao encontrado pois estou no nivel mais baixo e o proximo eh nulo ou maior entao nao existe
      
    if(no->prox_dir==NULL || (compara_no_string(no->prox_dir, procurado) > 0)){  //o proximo é maior ou nulo, então será descido um nível para procurar ele
      return procura_lista2(procurado, nivel-1, no->prox_baixo);
    }
    else if(compara_no_string(no->prox_dir, procurado) < 0){ //o proximo é menor, vai andar para direita
      return procura_lista2(procurado, nivel, no->prox_dir);
    }
    else if(compara_no_string(no->prox_dir, procurado) == 0){  //achou o procurado
       no=no->prox_dir;
      while(no->prox_baixo!=NULL){
        no=no->prox_baixo; //a função vai retornar o item no seu nível mais baixo na lista (nivel 1)
      }
      return no;
    }
}

NOSKIP * muda_def(char* procurado, char* nova_def, int nivel, NOSKIP *no) { //função de mudar definição das palavras
    if(nivel==1){
      if(no->prox_dir==NULL || (compara_no_string(no->prox_dir, procurado) > 0)){  //ultimo nível e o próximo é nulo ou maior que o buscado, quer dizer que ele não esta na lista
        printf("OPERACAO INVALIDA\n");
        return NULL;
      }else if(compara_no_string(no->prox_dir, procurado) < 0){   //o proximo é menor, vai andar para direita
        return muda_def(procurado,nova_def, nivel, no->prox_dir);
      }else{
          item_set_defini(no->prox_dir->item, nova_def);    //achou a palavra, retona ela
        return no->prox_dir;
      }
      
    }// nao encontrado pois estou no nivel mais baixo e o proximo eh nulo ou maior entao nao existe
      
    if(no->prox_dir==NULL || (compara_no_string(no->prox_dir, procurado) > 0)){ //o proximo é maior ou nulo, então será descido um nível para procurar ele
      return muda_def(procurado, nova_def,nivel-1, no->prox_baixo);
     }
     else if(compara_no_string(no->prox_dir, procurado) < 0){ //o proximo é menor, vai andar para direita
      return muda_def(procurado,nova_def ,nivel, no->prox_dir);
     }
     else if(compara_no_string(no->prox_dir, procurado) == 0){  //achou o procurado
       no=no->prox_dir;
       item_set_defini(no->item, nova_def);
       while(no->prox_baixo!=NULL){
        no=no->prox_baixo;
        item_set_defini(no->item, nova_def); //muda a definição do item e das outras versões deles que estão abaixo
      }
      return no;
    }

}


void remove_lista_skip(char* procurado, int nivel, NOSKIP *no) { //remover elementos das lista skip
    if (no == NULL) return;

    if (no->prox_dir && no->prox_dir->item) { //checa se o da direita existe, se existir vé se o conteudo dele não é nulo (so é nulo de for um nó header)
        int compara = compara_no_string(no->prox_dir, procurado);
        if (compara == 0) {  //se for o item que a gnt quer, apaga
            NOSKIP* DELETA = no->prox_dir;
            no->prox_dir = DELETA->prox_dir;
             if (nivel == 1) {
                item_apagar(&DELETA->item);  //So apaga o item no ultimo nível, para não acessar algo null e dar segfault
             }
             free(DELETA);
             remove_lista_skip(procurado, nivel - 1, no->prox_baixo); //desce para apagar o item em todos os níveis
             return; 
         } else if (compara < 0) {  //andar para direita
            remove_lista_skip(procurado, nivel, no->prox_dir);
            return;
         } 
    }

    if (no->prox_baixo) { //se o abaixo existir ele desce
        remove_lista_skip(procurado, nivel - 1, no->prox_baixo);
     } else if (nivel == 1 && (no->prox_dir == NULL || (no->prox_dir && compara_no_string(no->prox_dir, procurado) > 0))) { //ultimo nível, e ou o da direita é nulo ou maior, ai não tem na lista
        printf("OPERACAO INVALIDA\n");
     }
}

int primeiro_char(NOSKIP* NO, char ca){  //compara o primeiro char do conteudo de um nó (palavra) e o char procurado
    ITEM* item = NO->item;
    char* str = item_get_chave(item);
    if (str[0] == ca){ return 1;} //igual
    if (str[0] > ca){
        return 0;  //ficou maior, para de andar
    }else {
       return -1;  //menor, pode continuar
    };
    
}

void busca(char* procurado, int nivel, NOSKIP *no){  /*adicionar um printf na função de busca quebra a função e sua lógica de recursão, então foi criada uma wrapper function de busca*/
    NOSKIP* NO1 = procura_lista2(procurado,nivel,no);
    if(NO1 != NULL){ //se o NO1 for nullo printa invalido, senão printa a palavra
      printf("%s %s\n", item_get_chave(NO1->item), item_get_defi(NO1->item));
    }else {
        printf("OPERACAO INVALIDA\n");
    }
}

void imprime_todas_palavras(char letra, NOSKIP* no){ //imprimir todas palavras que começam com uma letra

  while(no->prox_baixo != NULL){ //desce pro menor nível
      no = no->prox_baixo;
  }
   no = no->prox_dir;  //sai do nó header para um nó normal
   NOSKIP* aux = no;
   int flag= 0; //flag da existencia de palavras com aquele char
   while(aux != NULL){
      
       if(primeiro_char(aux, letra) == 1){ //palavra que começa com o char, printa
         printf("%s %s\n", item_get_chave(aux->item), item_get_defi(aux->item));
         flag = 1 ;
         } else if (primeiro_char(aux,letra) == 0){ // 0 significa que o primeiro char dessa palavra é maior que o char buscado, então não vai mais avançar
         if (!flag){ //se nenhuma palavra foi printada até agora ele printa a msg 
            printf("NAO HA PALAVRAS INICIADAS POR %c \n",letra);
         }
         return;
         }
         aux = aux->prox_dir; //avança direita
    }   

     if (!flag){
       printf("NAO HA PALAVRAS INICIADAS POR %c \n",letra);
     }

}

NOSKIP * insercao(char* inserir,char* defini , int nivel, NOSKIP *no) {  //função de inserir um novo elemento na lista skip
    if( no->prox_dir == NULL && nivel==1){  //chegou no ultimo nível e o próximo é nulo, vai ser forçado a colocar aqui
      NOSKIP *novo = (NOSKIP*) malloc(sizeof(NOSKIP));
      if(novo ==NULL){exit(1);}
      novo->item=item_criar(inserir,defini); //adicionando item
      novo->prox_dir=no->prox_dir;
      novo->prox_baixo=NULL;
      no->prox_dir=novo;
      if(random_fn()){
        return novo; //função aleatoria retornou 1, então a palavra vai ser adicionada no prox nível tambem
      }
      return NULL; //palavra não vai ser add no prox nivel
    }
    if( no->prox_dir != NULL &&  no->prox_dir->item != NULL && (compara_no_string(no->prox_dir, inserir) == 0) ){
          printf("OPERACAO INVALIDA\n");  //caso a palavra seja repetida é uma operação invalida
    }

    if( no->prox_dir != NULL &&  no->prox_dir->item != NULL && (compara_no_string(no->prox_dir, inserir) > 0) && nivel==1){
      NOSKIP *novo = (NOSKIP*) malloc(sizeof(NOSKIP));   //se a proxima for maior, então a nova será inserida aqui
      if(novo ==NULL){exit(1);}
      novo->item=item_criar(inserir,defini);
      novo->prox_dir=no->prox_dir;
      novo->prox_baixo=NULL;
      no->prox_dir=novo;
      if(random_fn()){
        return novo; //função aleatoria 
      }
      return NULL;
    }

    NOSKIP *ins=NULL;  //chamadas recursivas que contam com uma variavel para acompanhar a direção (se a função recursivamenta ta voltando subindo ou indo para esquerda)
    int direction=-1;
    if(no->prox_dir==NULL){
      if(no->prox_baixo != NULL) {
        ins = insercao(inserir,defini , nivel-1, no->prox_baixo);  //prox é nulo e embaixo não é nulo, desce
    }
      direction=0;  //0 É descendo
    }else if( no->prox_dir != NULL &&  no->prox_dir->item != NULL &&  (compara_no_string(no->prox_dir, inserir) > 0)){
      if(no->prox_baixo != NULL) { //desce
        ins = insercao(inserir,defini ,nivel-1, no->prox_baixo);
    }
      direction=0;
    }else if((compara_no_string(no->prox_dir,inserir) < 0)){
        ins=insercao(inserir,defini ,nivel, no->prox_dir);
        direction=1;  //ANDANDO NA DIREITA   
    }

    if(direction==0 && ins!=NULL){
      NOSKIP *novo = (NOSKIP*) malloc(sizeof(NOSKIP));
      novo->item=ins->item;
      novo->prox_dir=no->prox_dir; //adicionando items
      novo->prox_baixo=ins;
      no->prox_dir=novo;
      if(random_fn()){ //função aleatoria
        return novo;
      }
      return NULL;  
    }else if(direction==1 && ins!=NULL){
      return ins;
    }
    return NULL;
}


