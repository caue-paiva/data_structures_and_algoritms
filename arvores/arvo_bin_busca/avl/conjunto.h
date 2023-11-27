#ifndef CONJUNTO_H
  #define CONJUNTO_H
  #include "avl.h"
  
  typedef struct conjun_ conjun;
  bool conjun_remove(conjun* C1, ITEM* item);
  bool conjun_pertence(conjun * C1, ITEM* item);
  conjun* conjun_criar(void);
  bool conjun_add_item(conjun * C1, ITEM* item);
  conjun* conjun_intersec(conjun* C1,  conjun* C2);
  void conjun_imprime(conjun* C1);
  conjun* conjun_uniao(conjun* C1, conjun* C2);
  void conjun_apaga(conjun** C1);
  int conjun_tamanho(conjun* C1);

#endif