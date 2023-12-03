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
      printf("falha na add \n");
      return false;
    }
    if(avl_inserir(C1->arvo_elem,item)){ //se a insercao for um sucesso retorna true
        C1->num_elem++;
        return true;
    }
    return false;
}

void conjun_imprime(conjun* C1){
     if(!C1)
       return;
     avl_imprime(C1->arvo_elem);  //chama funcao de imprimir arvore
}

void conjun_apaga(conjun** C1){
    if(!(*C1))
      return; 
    avl_apagar_arvore(&((*C1)->arvo_elem)); //apaga a arvore do conjunto
    free(*C1); //libera memoria alocada para o tad conjunto em si
    *C1 = NULL; //ponteiro fica null
}

int conjun_tamanho(conjun* C1){ //retorna o tam/num elementos de um conjunto, se ele nao for null
  if(!C1)
    return -1;
  return C1->num_elem;
}


/* Vamos percorrer pela menor AVL e a cada elemento delas vamos pesquisa se ela existe na maior arvore, se sim vamos add na intersec
entao a complexidade será n*log(N) , onde n < N, desse modo escolher passar pela menor conjunto e buscar no maior é mais eficiente que fazer o contrário
*/

void aux_percorre_intersec(NO_ARV* no_atual, conjun* C2, conjun* novo_conjun, const NO_ARV* no_raiz){  //funcao recursiva auxiliar para a intersecção
    if(!no_atual) //se o no atual for null, retorna
      return;
    ITEM* item_atual = retorna_item_no_ARV(no_atual);  //pega o item atual do C1
    ITEM* novo_item;
    if(conjun_pertence(C2,item_atual)){  //se o item atual do C1 pertencer no C2, ele será add ao conjunto intersecção
       novo_item = item_copiar(item_atual); //copia o item para que C1 e o novo conjunto tenham items diferentes (ponteiros diferentes) com mesmo conteudo
       conjun_add_item(novo_conjun, novo_item);
    }

    aux_percorre_intersec( no_avl_pega_dir(no_atual) ,C2, novo_conjun, no_raiz); //continua percorrendo a arvore para sua direita e esquerda
    aux_percorre_intersec( no_avl_pega_esq(no_atual) ,C2, novo_conjun, no_raiz);
}

void conjunto_intersec(conjun* C1, conjun* C2, conjun* novo_conjun){  //funcao para colocar a intersecção de C1 e C2 em um terceiro conjunto
    if( !C1 || !C2 ){
      printf("conjuntos vazio\n"); //se C1 ou C2 forem nulos, a operacao e cancelada
      return;
    }

    if(!C1->arvo_elem || !C2->arvo_elem || C1->num_elem == 0 || C2->num_elem == 0) //se um dos conjuntos estiver vazio retorna 
          return;
     
    conjun* maior_conjun;
    conjun* menor_conjun;
    if(C1->num_elem > C2->num_elem){ //acha qual é o conjunto com mais elementos, isso é usado na otimizacao da operacao
        maior_conjun = C1;
        menor_conjun = C2;
    }else{
        maior_conjun = C2;  //vendo qual conjunto e maior e qual e menor
        menor_conjun = C1;
    } //vamos percorrer pelo menor conjunto e a cada elemento dele, vamos buscar no maior conjunto se aquele element existe em ambos, se existir ele sera add no conjun intersec
    
    aux_percorre_intersec( avl_pega_raiz(menor_conjun->arvo_elem) , maior_conjun, novo_conjun, avl_pega_raiz(menor_conjun->arvo_elem) ); //chama a funcao auxiliar
}


void aux_percorre_uniao_segundo_conjun(NO_ARV* no_atual, conjun* novo_conjun, const NO_ARV* no_raiz){ //vamos percorrer o segundo conjunto, e caso os elementos dele nao estejam já no novo conjunto, vamos adicionar
    if(!no_atual)
      return;
    ITEM* item_atual = retorna_item_no_ARV(no_atual); //pega o elemento atual
    ITEM* novo_item;
    if(!conjun_pertence(novo_conjun,item_atual)){  //se o elemento atual não estiver no novo conjunto, vamos adicionar ele
       novo_item = item_copiar(item_atual); //copia em um novo item
       conjun_add_item(novo_conjun, novo_item);
    } 

    aux_percorre_uniao_segundo_conjun( no_avl_pega_dir(no_atual) , novo_conjun, no_raiz); //continua a recursao
    aux_percorre_uniao_segundo_conjun( no_avl_pega_esq(no_atual) , novo_conjun, no_raiz);
}

void aux_percorre_uniao_primei_conjun(NO_ARV* no_atual,conjun* novo_conjun){ //vamos percorrer o primeiro conjunto (Maior) e colocar todos os seus elementos no novo conjunto de uniao
    if(!no_atual)
      return;
    ITEM* item_atual = retorna_item_no_ARV(no_atual); //pega o item atual do primeiro conjunto
    ITEM* novo_item = item_copiar(item_atual); // copia o valor num novo item
    conjun_add_item(novo_conjun, novo_item); //add no novo conjunto

    aux_percorre_uniao_primei_conjun( no_avl_pega_dir(no_atual) , novo_conjun); //continua a recursao
    aux_percorre_uniao_primei_conjun( no_avl_pega_esq(no_atual) , novo_conjun);
}

/* Seja N = tam do maior conjunto e n o tamanho do menor conjun entre os 2 da operação de uniao:  como escolhemos o maior conjunto como o primeiro a ser copiado, a uniao vai realizar primeiro N operações (copiar o maior)
depois vamos percorrer o menor n vezes, cada uma realizando uma busca no novo_conjunto ( msm qntd de elementos que o maior) isso fica log(N)

entao a complexidade fica: N + n*log(N) = O(n*log(N)). Escolher copiar os valores do maior primeiro é benéfico, pois:   n*log(N) < N*log(n)  (mais sobre isso no relatorio)
*/
void conjunto_uniao(conjun* C1, conjun* C2, conjun* novo_conjun){ //funcao para colocar a uniao de C1 e C2 em um terceiro conjunto
    if( !C1 || !C2 ){
      printf("conjuntos vazio\n"); //se C1 ou C2 forem nulos, a operacao e cancelada
      return;
    }

    conjun* maior_conjun;
    conjun* menor_conjun;
    if(C1->num_elem > C2->num_elem){ //acha qual é o conjunto com mais elementos, isso é usado na otimizacao da operacao
        maior_conjun = C1;
        menor_conjun = C2;
    }else{
        maior_conjun = C2;  //vendo qual conjunto e maior e qual e menor
        menor_conjun = C1;
    } //vamos percorrer pelo menor conjunto e a cada elemento dele, vamos buscar no maior conjunto se aquele element existe em ambos, se existir ele sera add no conjun intersec
    NO_ARV* raiz_da_menor = avl_pega_raiz(menor_conjun->arvo_elem);
    NO_ARV* raiz_da_maior =  avl_pega_raiz(maior_conjun->arvo_elem);
    aux_percorre_uniao_primei_conjun(raiz_da_maior, novo_conjun ); //chama a funcao para copiar valores do primeiro conjunto
    aux_percorre_uniao_segundo_conjun(raiz_da_menor, novo_conjun, raiz_da_menor);      

}


