#include "abb.h"

struct no {
	item_t *info;
	no_t *esq, *dir;
};

struct abb {
	no_t *raiz;
};


abb_t *cria() {
	abb_t *a = (abb_t *)malloc(sizeof(abb_t));
	a->raiz = NULL;
	return a;
}

int esta_vazia(abb_t *A) {
	assert(A != NULL);
	return (A->raiz == NULL);
}

void finaliza(no_t *raiz) {
	if(raiz != NULL) {
		finaliza(raiz->esq);
		finaliza(raiz->dir);
		apagar_item(&(raiz->info));
		free(raiz);
	}
}

void finalizar(abb_t *A) {
	finaliza(A->raiz);
	free(A);
}

void imprime(no_t *raiz) {
	if(raiz != NULL) {
		printf("%d(", get_valor(raiz->info));
		imprime(raiz->esq);
		printf(",");
		imprime(raiz->dir);
		printf(")");
	} else {
		printf("_");
	}
}

void imprimir(abb_t *A) {
	imprime(A->raiz);
	printf("\n");
}

int altura_rec(no_t *raiz) {
	if(raiz == NULL) 
		return 0;
	
	int alt_esq = 1 + altura_rec(raiz->esq);
	int alt_dir = 1 + altura_rec(raiz->dir);
	
	if(alt_esq > alt_dir)
		return alt_esq;
	
	return alt_dir;
}

int altura(abb_t *A) {
	return altura_rec(A->raiz);
}

bool busca_rec(no_t *raiz, elem chave) {
	if(raiz == NULL) 
		return false;
	
	if(get_valor(raiz->info) == chave) {
		return true;
	}
	
	if(get_valor(raiz->info) > chave) {
		return busca_rec(raiz->esq, chave);
	}
	
	return busca_rec(raiz->dir, chave);
	
}

bool busca(abb_t *A, elem chave) {
	return busca_rec(A->raiz, chave);
}

bool inserir_rec(no_t **raiz, elem chave) {
	if(*raiz == NULL) {
		(*raiz) = (no_t *)malloc(sizeof(no_t));
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;
		(*raiz)->info = criar_item(chave);
		return true;
	}
	
	if(chave == get_valor((*raiz)->info)) {
		return false;
	}
	
	if(chave < get_valor((*raiz)->info)) {
		return inserir_rec(&(*raiz)->esq, chave);
	} else {
		return inserir_rec(&(*raiz)->dir, chave);
	}
}

bool inserir(abb_t *A, elem chave) {
	return inserir_rec(&(A->raiz), chave);
}

bool remover_rec(no_t **raiz, elem chave) {
	if(*raiz == NULL) {
		return false;
	}
	
	if(chave < get_valor((*raiz)->info)) {
		return remover_rec(&(*raiz)->esq, chave);
	} 
	if(chave > get_valor((*raiz)->info)) {
		return remover_rec(&(*raiz)->dir, chave);
	}
	
	if((*raiz)->esq == NULL && (*raiz)->dir == NULL) { //caso 1
		apagar_item(&(*raiz)->info);
		free(*raiz);
		*raiz = NULL;
		return true;
	}
	
	if((*raiz)->esq == NULL) { //caso 2: no com filho da direita
		no_t *aux;
		aux = *raiz;
		(*raiz) = (*raiz)->dir;
		apagar_item(&aux->info);
		free(aux);
		return true;
	}
	
	if((*raiz)->dir == NULL) { //caso 2: no com filho da esquerda
		no_t *aux;
		aux = *raiz;
		(*raiz) = (*raiz)->esq;
		apagar_item(&aux->info);
		free(aux);
		return true;
	}
	
	//caso 3: no raiz com os dois filhos
	no_t *aux = (*raiz)->esq;
	while(aux->dir != NULL)
		aux = aux->dir;
	
	set_valor((*raiz)->info, get_valor(aux->info));
	
	return remover_rec(&(*raiz)->esq, get_valor(aux->info));
}

bool remover(abb_t *A, elem chave) {
	return remover_rec(&(A->raiz), chave);
}