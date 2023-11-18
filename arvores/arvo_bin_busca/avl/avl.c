#include "avl.h"
#define ERRO_ARV_NULL -1928727
#define ARVO_MENOR_VAL -9878321
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

void avl_imprime_aux(NO* no_atual){
    if(no_atual)
       printf("item: %d com altura %d  ", item_get_chave(no_atual->item), no_atual->altura);
    else 
      return;
    avl_imprime_aux(no_atual->dir);
    avl_imprime_aux(no_atual->esq);
}

void avl_imprime(AVL* arvo){
    avl_imprime_aux(arvo->raiz);
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

bool avl_busca_item(NO* no_atual, ITEM* item){
    if(!no_atual)
       return false;
    int valor_buscado = item_get_chave(item);
    int valor_atual = item_get_chave(no_atual->item);
    
    if(valor_atual == valor_buscado)
       return true;

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
    
    NO* novo_no = avl_criar_no(item);
    arvo->raiz = avl_insere_no(arvo->raiz,novo_no);
    return true;
}

AVL *avl_criar(void){
    AVL *arv = (AVL*) malloc(sizeof(AVL));
    if(!arv)
       exit(1);
    arv->raiz = NULL;
    arv->profundidade = -1;
    return (arv);
}

void avl_apagar_arvore(AVL **T){
    apagar_arvore(&(*T)->raiz);
    free(*T);
    *T = NULL;
}



