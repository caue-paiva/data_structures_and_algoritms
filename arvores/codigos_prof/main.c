#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "avl.h"

int main() {
	avl_t *a = cria();

	inserir(a, 8);	
	inserir(a, 6);
	inserir(a, 5);
	inserir(a, 9);
	inserir(a, 17);
	inserir(a, 7);
	
	//inserir(a, 9);
	
	//remover(a, 8);
	
	imprimir(a);
	
	finalizar(a);
	
	return EXIT_SUCCESS;
}