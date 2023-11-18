#ifndef ABB_H
  #define ABB_H
  
    #include "item.h"
    
    #define FILHO_ESQ 0
    #define FILHO_DIR 1

    typedef struct ab_ AB;


    bool abb_remove(AB* arvo, ITEM* item);
    AB *abb_criar(void);
    bool abb_inserir(AB *T, ITEM *item);
    void abb_imprime(AB* arvo);


#endif