#include "avl.h"
#define max(a,b) ((a>b) ? a: b)


struct no_H {
    ITEM  *item;
    NO *esq;
    NO *dir;
    int altura;
};

struct avl{
    NO *raiz;
    int profundidade;
    int num_elem;
};

NO** acha_menor_aux(NO** raiz){
    if(!(raiz) || !(*raiz) )
       return NULL;    
    if(!(*raiz)->esq)
        return raiz;
    else
        return acha_menor_aux(& ((*raiz)->esq));
}

NO* avl_acha_menor(AVL* arvo){
    return *acha_menor_aux( (&(arvo->raiz)) );
}

NO** acha_maior_aux(NO** raiz){
    if(!(raiz) || !(*raiz) )
       return NULL;    
    if(!(*raiz)->esq)
        return raiz;
    else
        return acha_maior_aux( &((*raiz)->dir));
}

NO* avl_acha_maior(AVL* arvo){
    return *acha_maior_aux( (&(arvo->raiz)) );
}

void avl_imprime_aux(NO* no_atual, int profun){
    if(no_atual)
       printf("item: %d com profundidade %d // ", item_get_chave(no_atual->item), profun);
    else 
      return;
    avl_imprime_aux(no_atual->dir, profun+1);
    avl_imprime_aux(no_atual->esq, profun+1);
}

void avl_imprime(AVL* arvo){
    if(arvo->raiz){
      int profundidade = 0;
      avl_imprime_aux(arvo->raiz, profundidade);
    }else
        printf("vazio");
    printf("\n");
}

void troca_max_esq(NO *troca, NO *raiz, NO *ant){
    if(troca->dir != NULL){
        troca_max_esq(troca->dir, raiz, troca);
        return;
    }
    if(raiz == ant) ant->esq = troca->esq;
    else ant->dir = troca->esq;
    raiz->item = troca->item;
    free(troca);
    troca = NULL;
}

NO* avl_busca_no(NO* no_atual, ITEM* item){
    if(!no_atual)
       return false;
    int valor_buscado = item_get_chave(item);
    int valor_atual = item_get_chave(no_atual->item);
    
    if(valor_atual == valor_buscado)
       return no_atual;

    if(valor_atual > valor_buscado){
        if(!no_atual->esq)
           return NULL;
        else
           return avl_busca_no(no_atual->esq,item);
    }else{
        if(!no_atual->dir)
            return NULL;
        else
            return  avl_busca_no(no_atual->dir, item);
    }
}

bool aux_avl_busca(NO* no_atual, ITEM* item){
    if(!no_atual)
       return false;
    int valor_buscado = item_get_chave(item);
    int valor_atual = item_get_chave(no_atual->item);
    
    if(valor_atual == valor_buscado)
       return true;

    if(valor_atual > valor_buscado){
        if(!no_atual->esq)
           return false;
        else
           return avl_busca_no(no_atual->esq,item);
    }else{
        if(!no_atual->dir)
            return false;
        else
            return  avl_busca_no(no_atual->dir, item);
    }
}

bool avl_busca_item(AVL* arv, ITEM* item){
    if(!arv)
      return false;
    return aux_avl_busca(arv->raiz, item);
}
     
NO* avl_busca_pai(NO* raiz, ITEM* procurado){
    if(!raiz ||item_get_chave(raiz->item) == item_get_chave(procurado)) // nesse caso a raiz é o item, não tem pai
       return NULL;
    
    if(item_get_chave(raiz->item) < item_get_chave(procurado)) {
        if(raiz->dir){
            if (item_get_chave(raiz->dir->item) == item_get_chave(procurado)){
                return raiz;
            }else
            return avl_busca_pai(raiz->dir, procurado);
        }else 
          return NULL;
    }

    if(item_get_chave(raiz->item) > item_get_chave(procurado)) {
        if(raiz->esq){
            if (item_get_chave(raiz->esq->item) == item_get_chave(procurado)){
                return raiz;
            }else
            return avl_busca_pai(raiz->esq, procurado);
        }else
          return NULL;
    }
}

void apagar_arvore(NO **raiz){
    if(*raiz){
        apagar_arvore(&((*raiz)->esq));
        apagar_arvore(&((*raiz)->dir));
        item_apagar(&((*raiz)->item));
        free(*raiz);
        *raiz = NULL;
    }
}

NO *avl_criar_no(ITEM *item){
    NO *no = (NO*) malloc(sizeof(NO));
        if(!no)
           exit(1);
    no->item = item;
    no->altura = 0;
    no->esq = NULL;
    no->dir = NULL;
    return (no);
}

int avl_altura_no(NO* no){
    if(!no) 
       return -1;
    else
      return no->altura;
}

NO* rotacao_dir(NO* desbalan){
    NO* nova_raiz = desbalan->esq;
    desbalan->esq = nova_raiz->dir;
    nova_raiz->dir = desbalan;
    desbalan->altura = max(avl_altura_no(desbalan->esq), avl_altura_no(desbalan->dir)) + 1;
    nova_raiz->altura = max(avl_altura_no(nova_raiz->esq), avl_altura_no(nova_raiz->dir)) + 1;
    return nova_raiz;
}

NO* rotacao_esq(NO* desbalan){
    NO* nova_raiz = desbalan->dir;
    desbalan->dir = nova_raiz->esq;
    nova_raiz->esq = desbalan;
    desbalan->altura = max(avl_altura_no(desbalan->esq), avl_altura_no(desbalan->dir)) + 1;
    nova_raiz->altura = max(avl_altura_no(nova_raiz->esq), avl_altura_no(nova_raiz->dir)) + 1;
    return nova_raiz;
}

NO* rotacao_esq_dir(NO* desbalan){
    return rotacao_dir(rotacao_esq(desbalan->esq));
}

NO* rotacao_dir_esq(NO* desbalan){
    return rotacao_esq(rotacao_dir(desbalan->dir));
}

NO* avl_insere_no(NO* raiz, NO* novo_no){
    if(!raiz)
        raiz = novo_no;
    else if(item_get_chave(novo_no->item) < item_get_chave(raiz->item))
          raiz->esq = avl_insere_no(raiz->esq,novo_no);
    else if (item_get_chave(novo_no->item) > item_get_chave(raiz->item))
          raiz->dir =  avl_insere_no(raiz->dir,novo_no);

    raiz->altura = max(avl_altura_no(raiz->esq), avl_altura_no(raiz->dir)) + 1;
    
    if((avl_altura_no(raiz->esq)- avl_altura_no(raiz->dir)) == 2)
        if(item_get_chave(novo_no->item) > item_get_chave(raiz->esq->item))
           raiz = rotacao_esq_dir(raiz);
        else
          raiz = rotacao_dir(raiz);
    if((avl_altura_no(raiz->esq)- avl_altura_no(raiz->dir)) == -2)
        if(item_get_chave(novo_no->item) < item_get_chave(raiz->dir->item))
           raiz = rotacao_dir_esq(raiz);
        else
          raiz = rotacao_esq(raiz);

    return raiz;        
}

bool avl_inserir(AVL* arvo, ITEM* item){
    if(!arvo)
      return false;
    if(avl_busca_item(arvo,item)) 
       return false;
    NO* novo_no = avl_criar_no(item);
    arvo->raiz = avl_insere_no(arvo->raiz,novo_no);
    (arvo->num_elem)++;
    arvo->profundidade = max( avl_altura_no(arvo->raiz->dir), avl_altura_no(arvo->raiz->esq) )+1; //muda a profudidade da arvore
    return true;
}

AVL *avl_criar(void){
    AVL *arv = (AVL*) malloc(sizeof(AVL));
    if(!arv)
       exit(1);
    arv->raiz = NULL;
    arv->profundidade = -1;
    arv->num_elem = 0;
    return (arv);
}

void avl_apagar_arvore(AVL **T){
    apagar_arvore(&(*T)->raiz);
    free(*T);
    *T = NULL;
}

NO* remove_arvo(NO** raiz, ITEM* item){
    if(!(*raiz))  //no é nulo
      return NULL;

    int valor_buscado = item_get_chave(item); //valor que estamos procurando
    if(valor_buscado == item_get_chave((*raiz)->item)){
       if(!(*raiz)->dir || !(*raiz)->esq){ //caso em que ou nao tem filhos ou so tem 1 filho em qualquer lado
        NO* temp_no = *raiz;
        if (!(*raiz)->dir)
            (*raiz) = (*raiz)->esq;
        else if (!(*raiz)->esq)
           (*raiz) = ((*raiz)->dir);
        free(temp_no);
        temp_no = NULL;
       }else 
          troca_max_esq((*raiz)->esq,(*raiz),(*raiz)); //caso em que tem 2 filhos, chama a funcao troca_max_esq
    }else if(valor_buscado > item_get_chave((*raiz)->item)) //se o valor buscado for maior vamos para dir
       (*raiz)->dir = remove_arvo(&(*raiz)->dir, item);
    else
       (*raiz)->esq = remove_arvo(&(*raiz)->esq, item); //se o valor buscado for menor vamos para esq


    if (*raiz){
     (*raiz)->altura = max( avl_altura_no((*raiz)->dir), avl_altura_no((*raiz)->esq ) )+1;  //coloca a nova altura da arvore

        if((avl_altura_no((*raiz)->esq) - avl_altura_no((*raiz)->dir)) == 2)
           if((avl_altura_no((*raiz)->esq->esq) - avl_altura_no((*raiz)->esq->dir)) >= 0 )  //verifica o sinal do filho para ver se precisa de rota dupla
              (*raiz) = rotacao_dir((*raiz));
           else
              (*raiz) = rotacao_esq_dir((*raiz));
             
        if((avl_altura_no((*raiz)->esq)- avl_altura_no((*raiz)->dir)) == -2)  //rotina de rotacao, similar a na insercao
          if( (avl_altura_no((*raiz)->dir->esq) - avl_altura_no((*raiz)->dir->dir)) <= 0 ) 
               (*raiz) = rotacao_esq((*raiz));
           else
               (*raiz) = rotacao_dir_esq((*raiz));
             

    return (*raiz);         //retorna o no modificado dps da remocao e rotacao
    }
}

bool avl_remove(AVL*arv, ITEM* item){
    if(!arv)
      return false;
    if(!avl_busca_item(arv,item))
      return false;
    NO* nova_raiz = remove_arvo(&(arv->raiz),item);
    if(!nova_raiz)
      return false;
    else{
        arv->raiz = nova_raiz;
        (arv->num_elem)--;
        arv->profundidade = max( avl_altura_no(nova_raiz->dir), avl_altura_no(nova_raiz->esq ) )+1; //muda a profudidade da arvore
        return true;
    }
}

int avl_profundidade(AVL* arv){
    if(!arv)
      return -2;
    if(!arv->raiz)
      return -1;
    return ( max(avl_altura_no(arv->raiz->dir), avl_altura_no(arv->raiz->esq)) +1);
}

int avl_num_elem(AVL* arv){
    if(!arv)
      return -1;
    return arv->num_elem;
}

void vetor_avl_aux(int* vetor, NO* no_atual, NO* raiz_da_arvo){ //variavel para a raiz da arvore para comparaca
    if(!no_atual || !raiz_da_arvo)
       return;
    static int index_atual = 0; //essa variavel static mantem conta de qual index do vetor vamos inserir cada elemento
    int elemento_arvore = item_get_chave(no_atual->item);
    vetor[index_atual] = elemento_arvore;
    index_atual++;

    vetor_avl_aux(vetor, no_atual->dir, raiz_da_arvo);
    vetor_avl_aux(vetor, no_atual->esq, raiz_da_arvo);

    if(no_atual == raiz_da_arvo) //se ao voltar das chamadas recursivas estivermos na raiz novamente, setamos o index para zero
        index_atual = 0;
}

int* avl_para_vetor(AVL*arv){ //justificar por que escolher essa forma de iterar na AVL
    if(!arv || ! arv->raiz)
       return NULL;
    int* novo_vetor = (int*) malloc (sizeof(int) * (arv->num_elem));
    if(!novo_vetor)
       return NULL; //essa funcao precisa ser null checada ao ser usada
    vetor_avl_aux(novo_vetor, arv->raiz, arv->raiz);
    return novo_vetor;
}