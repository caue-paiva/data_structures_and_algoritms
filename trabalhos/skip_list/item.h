#ifndef ITEM_H
	#define ITEM_H
	
	#include <stdlib.h>
	#include <stdio.h>

	typedef struct item_ ITEM;

	ITEM *item_criar(char* palavra, char* defi);
	int item_apagar(ITEM **item);
	void item_imprimir(ITEM *item);
	char* item_get_chave(ITEM *item);
	char* item_get_defi(ITEM *item);
	int item_set_chave(ITEM *item, char* chave);
	int item_set_defini(ITEM *item, char* defi);
	void item_imprimir_defi(ITEM *item);
    int item_apaga_def(ITEM**);
#endif
