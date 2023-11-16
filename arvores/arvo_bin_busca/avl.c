#include "avl.h"

#define ERRO_ARV_NULL -1928727
#define ARVO_MENOR_VAL -9878321

typedef struct no_ NO;

struct no_{
    ITEM  *item;
    NO *esq;
    NO *dir;
    int altura;
};


struct ab_{
    NO *raiz;
    int profundidade;
};



NO** avl_acha_menor(NO** raiz){
    if(!(raiz) || !(*raiz) )
       return NULL;    
    if(!(*raiz)->esq)
        return raiz;
    else
        return avl_acha_menor( &((*raiz)->esq));
}

NO** avl_acha_maior(NO** raiz){
    if(!(raiz) || !(*raiz) )
       return NULL;    
    if(!(*raiz)->esq)
        return raiz;
    else
        return avl_acha_maior( &((*raiz)->dir));
}

void avl_imprime_aux(NO* no_atual){
    if(no_atual)
       printf(" %d", item_get_chave(no_atual->item));
    else 
      return;
    avl_imprime_aux(no_atual->dir);
    avl_imprime_aux(no_atual->esq);
}

void avl_imprime(AB* arvo){
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

bool avl_remove(AB* arvo, ITEM* item){ // mudar a função, usar ponteiro duplo e não precisa achar os pais
      if(!arvo || !arvo->raiz)
            return false;
      NO* no_remover = avl_busca_no(arvo->raiz, item);
      if(!no_remover)
         return false;

      if(no_remover->dir){
            NO** copia_menor = avl_acha_menor(&no_remover->dir);
            item_apagar(&no_remover->item);
            no_remover->item = (*copia_menor)->item;
            if((*copia_menor)->dir){
                NO* filho_dir = (*copia_menor)->dir;
               free((*copia_menor));
               (*copia_menor) = filho_dir;
            }else{
              free(*copia_menor); //dar free no no copia_menor mas não no seu item
              *copia_menor = NULL;
            }
      }else if(no_remover->esq){
            NO** copia_maior = avl_acha_maior(&no_remover->esq);
            item_apagar(&no_remover->item); // item apagar não é o problema
            no_remover->item = (*copia_maior)->item;
            if((*copia_maior)->esq){
               NO* filho_esq = (*copia_maior)->esq;
               free((*copia_maior));
               (*copia_maior) = filho_esq;
            }else{
                free(*copia_maior);
                *copia_maior = NULL; 
            }
      }else if(no_remover == arvo->raiz){
             item_apagar(&no_remover->item); 
             free(no_remover);
             arvo->raiz = NULL; 
      }else{
             item_apagar(&no_remover->item);
             free(no_remover);
             no_remover = NULL;
      }   
      return true;
}
    
bool avl_remover_aux(NO **raiz, int chave){
    NO *p;

    if(*raiz == NULL) return (false);

    if(chave == item_get_chave((*raiz)->item)){
        if((*raiz)->esq == NULL || (*raiz)->dir == NULL){
            p = *raiz;

            if((*raiz)->esq == NULL) *raiz = (*raiz)->dir;
            else *raiz = (*raiz)->esq;

            item_apagar(&p->item);
            p->item = NULL;
            free(p);
            p = NULL;
        }

        else troca_max_esq((*raiz)->esq, (*raiz), (*raiz));

        return (true);
    }
    
    else if(chave < item_get_chave((*raiz)->item)) return ab_remover_aux(&(*raiz)->esq, chave);
    else return ab_remover_aux(&(*raiz)->dir, chave);
}

void apagar_arvore(NO **raiz){
    if(*raiz != NULL){
        apagar_arvore(&(*raiz)->esq);
        apagar_arvore(&(*raiz)->dir);

        item_apagar(&(*raiz)->item);

        free(*raiz);

        *raiz = NULL;
    }
}

NO *avl_criar_no(ITEM *item){
    NO *no = (NO*) malloc(sizeof(NO));
        if(!no)
           exit(1);
    no->item = item;
    no->nivel = 0;
    no->esq = NULL;
    no->dir = NULL;
    return (no);
}

NO* rotacao_dir(NO* desbalan){
    NO* nova_raiz = desbalan->esq;
    desbalan->esq = nova_raiz->dir;
    nova_raiz->dir = desbalan;
    //fazer codigo de calcular altura

    return nova_raiz;
}

bool avl_inserir_no(NO *raiz, ITEM *item, AB* arvo){
      static int niveis_var; //fazer uma conta para setar não nível mas a altura
      if(!raiz)
         return false;

      if(item_get_chave(item) == item_get_chave(raiz->item)){
        niveis_var = 0;
        return false;
      }
       
      if(item_get_chave(item) > item_get_chave(raiz->item)){
         if(!raiz->dir){
            raiz->dir = avl_criar_no(item);
            if(arvo->profundidade < (niveis_var+1))
               arvo->profundidade = (niveis_var+1);
            niveis_var= 0;
            return true;
         }
         else{
           niveis_var++;
           return avl_inserir_no(raiz->dir,item, arvo);
         }
            
       }else{
         if(!raiz->esq){
            raiz->esq = avl_criar_no(item);
            if(arvo->profundidade < (niveis_var+1))
               arvo->profundidade = (niveis_var+1);
            niveis_var = 0;
            return true;
         }
         else{
            niveis_var++;
            return avl_inserir_no(raiz->esq,item, arvo);
         }
            
       }
   
}

AB *avl_criar(void){
    AB *r = (AB*) malloc(sizeof(AB));

    if(r != NULL){
        r->raiz = NULL;
        r->profundidade = -1;
    }

    return (r);
}

bool avl_inserir(AB *T, ITEM *item){
    if(T->raiz == NULL){
        T->profundidade = 1;
        return ((T->raiz = avl_criar_no(item)) != NULL);
    }
    return avl_inserir_no(T->raiz, item, T);
}

void avl_apagar_arvore(AB **T){
    apagar_arvore(&(*T)->raiz);
    free(*T);
    *T = NULL;
}

bool avl_remover(AB *T, int chave){
    if(T != NULL) return (avl_remover_aux(&T->raiz, chave));
    return (false);
}  


