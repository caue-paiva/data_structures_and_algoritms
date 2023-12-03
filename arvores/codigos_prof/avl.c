#include "avl.h"

struct no {
	item_t *info;
	no_t *esq, *dir;
	int fb;
};

struct avl {
	no_t *raiz;
};


avl_t *cria() {
	avl_t *a = (avl_t *)malloc(sizeof(avl_t));
	a->raiz = NULL;
	return a;
}

int esta_vazia(avl_t *A) {
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

void finalizar(avl_t *A) {
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

void imprimir(avl_t *A) {
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

int altura(avl_t *A) {
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

bool busca(avl_t *A, elem chave) {
	return busca_rec(A->raiz, chave);
}

no_t *rotacao_EE(no_t *raiz) {
	no_t *aux;
	aux = raiz->dir;
	raiz->dir = aux->esq;
	aux->esq = raiz;
	return aux;	
}

no_t *rotacao_DD(no_t *raiz) {
	no_t *aux;
	aux = raiz->esq;
	raiz->esq = aux->dir;
	aux->dir = raiz;
	return aux;
}

no_t *rotacao_ED(no_t *raiz) {
	raiz->esq = rotacao_EE(raiz->esq);
	raiz = rotacao_DD(raiz);
	return raiz;
}

no_t *rotacao_DE(no_t *raiz) {
	raiz->dir = rotacao_DD(raiz->dir);
	raiz = rotacao_EE(raiz);
	return raiz;
}

no_t *inserir_rec(no_t *raiz, elem chave, int *flag) {
	if(raiz != NULL) {
		if(get_valor(raiz->info) > chave) {
			raiz->esq = inserir_rec(raiz->esq, chave, flag);
			if(*flag == 1) {
				switch(raiz->fb) {
					case -1:
						raiz->fb = 0;
						*flag = 0;
						break;
					case 0:
						raiz->fb = 1;
						*flag = 1;
						break;
					case 1:
						if(raiz->esq->fb > 0) { //sinais iguais
							raiz = rotacao_DD(raiz);
							raiz->fb = 0;
							raiz->dir->fb = 0;
						} else {
							raiz = rotacao_ED(raiz);
							if(raiz->fb == 0) {
								raiz->esq->fb = 0;
								raiz->dir->fb = 0;
							} else if(raiz->fb == -1) {
								raiz->esq->fb = 1;
								raiz->dir->fb = 0;
								raiz->fb = 0;
							} else { //raiz->fb == 1
								raiz->esq->fb = 0;
								raiz->dir->fb = -1;
								raiz->fb = 0;
							}
						}
						*flag = 0;
				}
			}
		} else if(get_valor(raiz->info) < chave){
			raiz->dir = inserir_rec(raiz->dir, chave, flag);
			if(*flag == 1) {
				switch(raiz->fb) {
					case 1:
						raiz->fb = 0;
						*flag = 0;
						break;
					case 0:
						raiz->fb = -1;
						*flag = 1;
						break;
					case -1:
						if(raiz->dir->fb < 0) { //sinais iguais
							raiz = rotacao_EE(raiz);
							raiz->fb = 0;
							raiz->esq->fb = 0;
						} else {
							raiz = rotacao_DE(raiz);
							if(raiz->fb == 0) {
								raiz->esq->fb = 0;
								raiz->dir->fb = 0;
							} else if(raiz->fb == -1) {
								raiz->esq->fb = 1;
								raiz->dir->fb = 0;
								raiz->fb = 0;
							} else { //raiz->fb == 1
								raiz->esq->fb = 0;
								raiz->dir->fb = -1;
								raiz->fb = 0;
							}
						}
						*flag = 0;
				}
			}
		} else {
			printf("Elemento ja existente!\n");
		}
	} else {
		raiz = (no_t *)malloc(sizeof(no_t));
		raiz->esq = NULL;
		raiz->dir = NULL;
		raiz->fb = 0;
		raiz->info = criar_item(chave);
		*flag = 1;
	}
	
	return raiz;
}

bool inserir(avl_t *A, elem chave) {
	int flag = 1;
	A->raiz = inserir_rec(A->raiz, chave, &flag);
	return true;
}

bool remover_rec(no_t **raiz, elem chave) {
	return false;
}

bool remover(avl_t *A, elem chave) {
	return remover_rec(&(A->raiz), chave);
}