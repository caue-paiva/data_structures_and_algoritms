#ifndef MATRIZ_H
   #define MATRIZ_H
   #include <stdlib.h>
   #include <stdio.h>
   typedef struct no NO_;
   typedef struct matriz MATRIZ_;

   NO_* no_criar(int item);
   MATRIZ_* matriz_criar(int lins, int cols);
   int insere_valor(int valor, int linha, int coluna, MATRIZ_* MA);
   void imprime_ma(MATRIZ_* MA);





#endif