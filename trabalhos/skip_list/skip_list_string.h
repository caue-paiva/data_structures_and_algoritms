#ifndef SKIP_H
	#define SKIP_H
  
  /* FEITO POR
  Caue Paiva Lira. NUSP: 14675416
  Thales Sena de Queiroz. NUSP: 14608873
*/
  
   #include "item.h"
   #include "stdio.h"
   #include "stdlib.h"
   #include "string.h"
   #include "time.h"
   #define NIVEIS 10 //número de niveis que a skiplist tem

   typedef struct noskip_ NOSKP;

   NOSKP* cria_skip_list(void);
   NOSKP * muda_def(char* procurado, char* nova_def, int nivel, NOSKP *no);
   void remove_lista_skip(char* procurado, int nivel, NOSKP *no);
   void busca(char* procurado, int nivel, NOSKP *no);
   void imprime_todas_palavras(char letra, NOSKP* no);
   NOSKP * insercao(char* inserir,char* defini , int nivel, NOSKP *no);
   void apaga_skip_lista(NOSKP** no);

#endif