#ifndef ABB_H
  #define ABB_H
  
    #include "item.h"
    
    #define FILHO_ESQ 0
    #define FILHO_DIR 1

    typedef struct ab_ AB;

    AB *ab_criar(void); 
    bool abb_inserir(AB *T, ITEM *item);
    bool ab_remover(AB *T, int chave);
    void ab_apagar_arvore(AB **T);
    int maior(AB *T);





#endif