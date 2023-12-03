#ifndef _ABB_H
#define _ABB_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "item.h"

typedef struct no no_t;
typedef struct abb abb_t;

abb_t *cria();
int esta_vazia(abb_t *A);
void finalizar(abb_t *A);
void imprimir(abb_t *A);
int altura(abb_t *A);
bool busca(abb_t *A, elem chave);
bool inserir(abb_t *A, elem chave);
bool remover(abb_t *A, elem chave);

#endif