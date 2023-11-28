#include "abb.h"

#define ERRO_ARV_NULL -1928727
#define ARVO_MENOR_VAL -9878321

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



NO** abb_acha_menor(NO** raiz){
    if(!(raiz) || !(*raiz) )
       return NULL;    
    if(!(*raiz)->esq)
        return raiz;
    else
        return abb_acha_menor( &((*raiz)->esq));
}

NO** abb_acha_maior(NO** raiz){
    if(!(raiz) || !(*raiz) )
       return NULL;    
    if(!(*raiz)->esq)
        return raiz;
    else
        return abb_acha_maior( &((*raiz)->dir));
}

/*
Essa funcao e uma sobra de codigo da AVL, vou deixar aqui caso precise dps

*/
NO* avl_busca_no(NO* no_atual, ITEM* item){ //funcao que busca um no que tenha um certo item
    if(!no_atual)
       return false;  
    int valor_buscado = item_get_chave(item);
    int valor_atual = item_get_chave(no_atual->item);  //pega os valores atuais e buscados 
    
    if(valor_atual == valor_buscado) //achamos o valor que buscamos
       return no_atual;

    if(valor_atual > valor_buscado){
        if(!no_atual->esq)  //se o valor atual for maior que o buscado, vai para esquerda
           return NULL;
        else
           return avl_busca_no(no_atual->esq,item);
    }else{
        if(!no_atual->dir)  //se o valor atual for menor que o buscado, vai para dir
            return NULL;
        else
            return  avl_busca_no(no_atual->dir, item);
    }
}

void abb_imprime_aux(NO* no_atual){
    if(no_atual)
       printf(" %d", item_get_chave(no_atual->item));
    else 
      return;
    abb_imprime_aux(no_atual->dir);
    abb_imprime_aux(no_atual->esq);
}

void abb_imprime(AB* arvo){
    abb_imprime_aux(arvo->raiz);
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

NO* abb_busca_no(NO* no_atual, ITEM* item){
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
           return abb_busca_no(no_atual->esq,item);
    }else{
        if(!no_atual->dir)
            return NULL;
        else
            return  abb_busca_no(no_atual->dir, item);
    }
}
     
NO* abb_busca_pai(NO* raiz, ITEM* procurado){
    if(!raiz ||item_get_chave(raiz->item) == item_get_chave(procurado)) // nesse caso a raiz é o item, não tem pai
       return NULL;
    
    if(item_get_chave(raiz->item) < item_get_chave(procurado)) {
        if(raiz->dir){
            if (item_get_chave(raiz->dir->item) == item_get_chave(procurado)){
                return raiz;
            }else
            return abb_busca_pai(raiz->dir, procurado);
        }else 
          return NULL;
    }

    if(item_get_chave(raiz->item) > item_get_chave(procurado)) {
        if(raiz->esq){
            if (item_get_chave(raiz->esq->item) == item_get_chave(procurado)){
                return raiz;
            }else
            return abb_busca_pai(raiz->esq, procurado);
        }else
          return NULL;
    }
}

bool abb_remove(AB* arvo, ITEM* item){ // mudar a função, usar ponteiro duplo e não precisa achar os pais
      if(!arvo || !arvo->raiz)
            return false;
      NO* no_remover = abb_busca_no(arvo->raiz, item);
      if(!no_remover)
         return false;

      if(no_remover->dir){
            NO** copia_menor = abb_acha_menor(&no_remover->dir);
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
            NO** copia_maior = abb_acha_maior(&no_remover->esq);
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

NO *abb_criar_no(ITEM *item){
    NO *no = (NO*) malloc(sizeof(NO));
        if(!no)
           exit(1);
    no->item = item;
    no->esq = NULL;
    no->dir = NULL;

    return (no);
}

bool abb_inserir_no(NO *raiz, ITEM *item, AB* arvo){
      static int niveis_var;
      if(!raiz)
         return false;

      if(item_get_chave(item) == item_get_chave(raiz->item)){
        niveis_var = 0;
        return false;
      }
       
      if(item_get_chave(item) > item_get_chave(raiz->item)){
         if(!raiz->dir){
            raiz->dir = abb_criar_no(item);
            if(arvo->profundidade < (niveis_var+1))
               arvo->profundidade = (niveis_var+1);
            niveis_var= 0;
            return true;
         }
         else{
           niveis_var++;
           return abb_inserir_no(raiz->dir,item, arvo);
         }
            
       }else{
         if(!raiz->esq){
            raiz->esq = abb_criar_no(item);
            if(arvo->profundidade < (niveis_var+1))
               arvo->profundidade = (niveis_var+1);
            niveis_var = 0;
            return true;
         }
         else{
            niveis_var++;
            return abb_inserir_no(raiz->esq,item, arvo);
         }
            
       }
   
}

AB *abb_criar(void){
    AB *r = (AB*) malloc(sizeof(AB));

    if(r != NULL){
        r->raiz = NULL;
        r->profundidade = -1;
    }

    return (r);
}

bool abb_inserir(AB *T, ITEM *item){
    if(T->raiz == NULL){
        T->profundidade = 1;
        return ((T->raiz = abb_criar_no(item)) != NULL);
    }
    return abb_inserir_no(T->raiz, item, T);
}

void abb_apagar_arvore(AB **T){
    apagar_arvore(&(*T)->raiz);
    free(*T);
    *T = NULL;
}

bool abb_remover(AB *T, int chave){
    if(T != NULL) return (ab_remover_aux(&T->raiz, chave));
    return (false);
}  


