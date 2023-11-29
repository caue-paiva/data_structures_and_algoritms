#ifndef AVL_H
	#define AVL_H
    #include "item.h"
    #define FILHO_ESQ 0
    #define FILHO_DIR 1

    typedef struct avl AVL;   
    typedef struct no_arv NO_ARV;
    /*a struct NO_AVL é declarada na avl, entao a pilha importa ela para guardar esses nós na travessia da AVL
     e o conjunto.h usa TAD relacionados a esses nós e a AVL para suas operacoes*/
   
    AVL *avl_criar(void); 
    bool avl_inserir(AVL* arvo, ITEM* item);
    void avl_apagar_arvore(AVL **T);
    NO_ARV* avl_acha_maior(AVL* arvo);
    NO_ARV* avl_acha_menor(AVL* arvo);
    void avl_imprime(AVL* arvo);
    bool avl_busca_item(AVL* arv, ITEM* item);
    bool avl_remove(AVL*arv, ITEM* item);
    int* avl_para_vetor(AVL*arv);
    int avl_num_elem(AVL* arv);
    ITEM* retorna_item_no_ARV(NO_ARV* no);  // daqui para baixo sao funcoes usadas para o conjunto e outros TADs interagirem com os nos/raiz da AVL
    NO_ARV* avl_pega_raiz(AVL* arv);
    NO_ARV* no_avl_pega_esq(NO_ARV* no);
    NO_ARV* no_avl_pega_dir(NO_ARV* no);
    ITEM* no_avl_pega_item(NO_ARV* no);

    
#endif
