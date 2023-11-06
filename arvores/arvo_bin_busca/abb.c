#include "abb.h"

typedef struct no_ NO;

struct no_{
    ITEM  *item;
    NO *esq;
    NO *dir;
};


struct ab_{
    NO *raiz;
    int profundidade;
};




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


NO* abb_busca_pai(NO* raiz, ITEM* procurado){
    if(!raiz ||item_get_chave(raiz->item) == item_get_chave(procurado)) // nesse caso a raiz é o item, não tem pai
       return NULL;
    
    if(item_get_chave(raiz->item) < item_get_chave(procurado)) {
        if(raiz->dir){
            if (item_get_chave(raiz->dir) == item_get_chave(procurado)){
                return raiz;
            }else
            return abb_busca_pai(raiz->dir, procurado);
        }else 
          return NULL;
    }

    if(item_get_chave(raiz->item) > item_get_chave(procurado)) {
        if(raiz->esq){
            if (item_get_chave(raiz->esq) == item_get_chave(procurado)){
                return raiz;
            }else
            return abb_busca_pai(raiz->esq, procurado);
        }else
          return NULL;
    }
}

bool abb_remove(AB* arvo, NO* no_atual, ITEM* item){ // mudar a função, usar ponteiro duplo e não precisa achar os pais
   NO* no_busca = abb_busca_pai(arvo->raiz,item);

   if(!(no_busca) && item_get_chave(arvo->item)  == item_get_chave(item)){

   }
    
}

bool ab_remover_aux(NO **raiz, int chave){
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

NO *ab_criar_no(ITEM *item){
    NO *no = (NO*) malloc(sizeof(NO));
        if(!no)
           exit(1);
    no->item = item;
    no->esq = NULL;
    no->dir = NULL;

    return (no);
}

bool abb_inserir_no(NO *raiz, ITEM *item, AB* arvo){
      static int niveis;
      if(!raiz)
         return false;

      if(item_get_chave(item) == item_get_chave(raiz->item)){
        niveis = 0;
        return false;
      }
       
      if(item_get_chave(item) > item_get_chave(raiz->item)){
         if(!raiz->dir){
            raiz->dir = ab_criar_no(item);
            if(arvo->niveis < (niveis+1))
               arvo->niveis = (niveis+1);
            niveis = 0;
            return true;
         }
         else{
           niveis++;
           return abb_inserir_no(raiz->dir,item, arvo);
         }
            
       }else{
         if(!raiz->esq){
            raiz->esq = ab_criar_no(item);
            if(arvo->niveis < (niveis+1))
               arvo->niveis = (niveis+1);
            niveis = 0;
            return true;
         }
         else{
            niveis++;
            return abb_inserir_no(raiz->esq,item, arvo);
         }
            
       }
   
}

AB *ab_criar(void){
    AB *r = (AB*) malloc(sizeof(AB));

    if(r != NULL){
        r->raiz = NULL;
        r->profundidade = -1;
    }

    return (r);
}

bool abb_inserir(AB *T, ITEM *item){
    if(T->raiz == NULL){
        T-niveis = 1;
        return ((T->raiz = ab_criar_no(item)) != NULL);
    }
    

    return abb_inserir_no(T->raiz, item, T);
}

void ab_apagar_arvore(AB **T){
    apagar_arvore(&(*T)->raiz);
    free(*T);
    *T = NULL;
}

bool ab_remover(AB *T, int chave){
    if(T != NULL) return (ab_remover_aux(&T->raiz, chave));
    return (false);
}  


