#include "conjunto.h"

struct conjun_{
    AVL* arvo_elem;  //conjunto é composto por uma AVL, que guarda seus elementos
    int num_elem;  //e uma var int para guardar quantos elementos ele tem, util para algumas operacoes 
};

bool conjun_remove(conjun* C1, ITEM* item){
   if(!C1 || !item)
     return false;
   if(!C1->arvo_elem)  //esse segundo if existe para garantir que a arvo do conjunto n esteja vazia e ele esta abaixo para n dar segfault 
     return false;   //fazer -> em um ponteiro nulo da segfault
   if(avl_remove(C1->arvo_elem, item)){ //n precisa usa a funcao busca conjunto pq a remocao ja busca na arvore
     (C1->num_elem)--;  //chama a funcao remove da AVL, reduz o numero de items do conjunto
     return true;
   }
   return false;
} 

bool conjun_pertence(conjun * C1, ITEM* item){
    return avl_busca_item(C1->arvo_elem,item); //busca no conjunto e so uma busca na arvore AVL
}

conjun* conjun_criar(void){
    conjun* novo_conjun = (conjun*) malloc(sizeof(conjun));
         if (!novo_conjun)  //alloca um conjunto, seta suas variaveis iniciais e retorna
           exit(1);
    novo_conjun->num_elem = 0;
    novo_conjun->arvo_elem = avl_criar(); //cria uma AVL associada a esse conjunto
    return novo_conjun;
} 

bool conjun_add_item(conjun * C1, ITEM* item){ //chama a funcao inserir na AVL
    if(!C1){ 
      return false;
    }
    if(avl_inserir(C1->arvo_elem,item)){ //se a insercao for um sucesso retorna true
        C1->num_elem++;
        return true;
    }
    return false;
}

conjun* conjun_intersec(conjun* C1,  conjun* C2){
    if (!C1 || !C2){
       printf("operecao de intersec invalida \n"); //como nesse caso ums dos conjuntos realmente nao existe (nao somente esta vazio) e uma opera invalida
       exit(1);
    }

    conjun* novo_conjunto = conjun_criar(); //cria novo conjunto para ser retornado
         
    if(!C1->arvo_elem || !C2->arvo_elem || C1->num_elem == 0 || C2->num_elem == 0) //se um dos conjuntos estiver vazio retorna um novo conjunto vazio 
        return novo_conjunto;
     
    conjun* maior_conjun;
    conjun* menor_conjun;
    int tam_novo_conjun = 0;
    if(C1->num_elem > C2->num_elem){ //acha qual é o conjunto com mais elementos, isso é usado na otimizacao da operacao
        maior_conjun = C1;
        menor_conjun = C2;
    }else{
        maior_conjun = C2;
        menor_conjun = C1;
    }

    int* vetor_menor_conjunto = avl_para_vetor(menor_conjun->arvo_elem); //vetor auxiliar para conter os elementos as avl que vao ser usados na opera
    if(!vetor_menor_conjunto){
       printf("operecao de intersec invalida \n"); //checar se o vetor retornado n e null
       exit(1);
    }
    ITEM* item_atual;      
    //é mais eficiente loopar no menor conjunto e buscar se os seus elementos existem no maior
    for (int i = 0; i < menor_conjun->num_elem ; i++){
        item_atual = item_criar(vetor_menor_conjunto[i]);//achar um jeito de "ITERAR" pela AVL e pegar todos elementos
        if(conjun_pertence(maior_conjun, item_atual)){ //se o numero estiver nos 2 conjuntos, ele sera adicionado na intersec deles
           conjun_add_item(novo_conjunto,item_atual);
           tam_novo_conjun++; //guarda o tamanho do novo conjunto
        }else{
          item_apagar(&item_atual); //se a operacao de inserir esse item no novo conjun falhar, apagamos ele
        }
               
    }      
    free(vetor_menor_conjunto); //libera o vetor aux
    novo_conjunto->num_elem = tam_novo_conjun; //coloca o tamanho do novo conjunto
    return novo_conjunto;
}

void conjun_imprime(conjun* C1){
     if(!C1)
       return;
     avl_imprime(C1->arvo_elem);  //chama funcao de imprimir arvore
}

conjun* conjun_uniao(conjun* C1, conjun* C2){
    if(!C1 || !C2)
       exit(1);

    conjun* novo_conjun = conjun_criar(); //aloca uma novo conjunto que vai ser retornado pela opera

    int *vetor1 = avl_para_vetor(C1->arvo_elem); //vetores aux para guardar os valores dos conjuntos e fazer as operacoes
    int *vetor2 = avl_para_vetor(C2->arvo_elem);
    ITEM* novo_item; //item aux para fazer a busca
    int novo_num_elem = C1->num_elem;

    for (int i = 0; i < C1->num_elem ; i++){
      novo_item = item_criar(vetor1[i]);   //coloca todos os items de C1 no novo conjunto
      conjun_add_item(novo_conjun,novo_item);
    }
    free(vetor1); //libera o primeiro vetor, assim nao tem mais doq um vetor alocado ao mesmo tempo 

    for (int i = 0; i < C2->num_elem ; i++){
      novo_item = item_criar(vetor2[i]);
      if(!conjun_pertence(novo_conjun, novo_item)){
          conjun_add_item(novo_conjun,novo_item);  //se os elementos de C2 nao forem repetidos, coloca eles tbm
          novo_num_elem++;
      }else
        item_apagar(&novo_item); //apagar o item criado para busca
    }
    free(vetor2); //libera o segundo vetor
    novo_conjun->num_elem = novo_num_elem; //novo conjun tem um novo num de elementos
    return novo_conjun;
}

void conjun_apaga(conjun** C1){
    if(!(*C1))
      return; 
    avl_apagar_arvore(&((*C1)->arvo_elem)); //apaga a arvore do conjunto
    free(*C1); //libera memoria alocada para o tad conjunto em si
    *C1 = NULL; //ponteiro fica null
}

int conjun_tamanho(conjun* C1){ //retorna o tam/num elementos de um conjunto, se ele n for null
  if(!C1)
    return -1;
  return C1->num_elem;
}

ITEM* aux_conjunto_retorna_valores(PILHA* pilha_atual, NO_ARV* no_raiz){
    static  NO_ARV* no_atual = NULL;
    static bool desce_esquerda = true;
    //static NO_ARV* prox_dir;
    //printf("entrou na func \n");
    

    if(!no_atual){
      no_atual = no_raiz;
    }

    while(desce_esquerda && no_atual){
      //  printf("desce esq e vdd \n");
        pilha_push(pilha_atual, no_atual);
        no_atual =  no_avl_pega_esq(no_atual);
    }

    if(pilha_tam(pilha_atual) > 0){
      // printf("entrou no pilha tam \n");
       NO_ARV* no_retorno = pilha_pop(pilha_atual);
       
       if(no_avl_pega_dir(no_retorno)){
        no_atual =  no_avl_pega_dir(no_retorno);
        desce_esquerda = true;
       // printf("indo direita \n");
       }
       else{
        if(pilha_vazia(pilha_atual)){
         no_atual = NULL;
         desce_esquerda = true;
         return retorna_item_no_ARV(no_retorno);
        }
        //  printf("voltando subindo \n");
          no_atual = pilha_topo(pilha_atual);  
          desce_esquerda = false;
        }
        return retorna_item_no_ARV(no_retorno);
    } 
    no_atual = NULL;
    desce_esquerda = true;
    return NULL;
}


ITEM* conjunto_retorna_valores(conjun* C1, PILHA* pilha){
      if(!C1){ 
        printf("conjunto nulo");
        exit(1);
      }
      return aux_conjunto_retorna_valores(pilha, avl_pega_raiz(C1->arvo_elem));
} 
