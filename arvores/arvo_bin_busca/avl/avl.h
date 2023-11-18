#ifndef AVL_H
	#define AVL_H
    
    #include "item.h"
    
    #define FILHO_ESQ 0
    #define FILHO_DIR 1

    typedef struct avl AVL;
    typedef struct no_H NO;
    AVL *avl_criar(void); 
    bool avl_inserir(AVL* arvo, ITEM* item);
    //bool ab_remover(AVL *T, int chave);
    void avl_apagar_arvore(AVL **T);
    NO* avl_acha_maior(AVL* arvo);
    NO* avl_acha_menor(AVL* arvo);
    void avl_imprime(AVL* arvo);
    bool avl_busca_item(NO* no_atual, ITEM* item);
    
#endif
