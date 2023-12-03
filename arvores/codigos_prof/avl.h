#ifndef _avl_H
#define _avl_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "item.h"

typedef struct no no_t;
typedef struct avl avl_t;

avl_t *cria();
int esta_vazia(avl_t *A);
void finalizar(avl_t *A);
void imprimir(avl_t *A);
int altura(avl_t *A);
bool busca(avl_t *A, elem chave);
bool inserir(avl_t *A, elem chave);
bool remover(avl_t *A, elem chave);

#endif