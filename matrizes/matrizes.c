
#include "matrizes.h"

typedef struct no NO;
typedef struct matriz MATRIZ;

struct no{
   NO* prox_linha;
   NO* prox_coluna;
   int item, lin,colu;
};

struct matriz{
      NO** linhas;
      NO**colunas;
      int n_lins, n_cols, n_vals;
};


NO* no_criar(int item){
   NO* novo_no = (NO*) malloc(sizeof(NO));
      if(!novo_no){exit(1);}
   novo_no->item = item;
   novo_no->prox_coluna = NULL;
   novo_no->prox_linha =NULL;
   novo_no->lin = -1;
   novo_no->colu = -1;

   return novo_no;
}

MATRIZ* matriz_criar(int lins, int cols){
    MATRIZ* nova_matriz = (MATRIZ*) malloc(sizeof(MATRIZ));
       if(!nova_matriz){exit(1);}

   NO** linhas = (NO**) malloc(sizeof(NO*)* lins);
        if(!linhas){exit(1);}
   for (int i = 0; i < lins; i++)
   {
      linhas[i] = NULL;
   }

   nova_matriz->linhas = linhas;

   NO** col = (NO**) malloc(sizeof(NO*)* cols);
        if(!col){exit(1);}
   
   for (int i = 0; i < cols; i++)
   {
      col[i] = NULL;
   }
        
   nova_matriz->colunas = col;
   nova_matriz->n_cols =cols;
   nova_matriz->n_lins= lins;
   nova_matriz->n_vals = 0;
   return nova_matriz;
}


int insere_valor(int valor, int linha, int coluna, MATRIZ* MA){
   if(!MA){return 0;}
   NO* linha_percorre = MA->linhas[linha];
   NO* colu_percorre = MA->colunas[linha];
   NO* novo_no = no_criar(valor);
   novo_no->lin = linha;
   novo_no->colu = coluna;
   novo_no->item = valor;
   int iters_lin = 0;
   int flagfim1 = 0;
   int flagfim2 = 0;

   if(linha_percorre && coluna != 0){    //insere linha
      while(linha_percorre->prox_coluna){
           if(linha_percorre->prox_coluna->colu == coluna){ //trocar o valor
              if(linha_percorre->prox_coluna->prox_coluna){
                  novo_no->prox_coluna = linha_percorre->prox_coluna->prox_coluna;
                  linha_percorre->prox_coluna = novo_no;
              }else{
                  linha_percorre->prox_coluna = novo_no;
              }       
              flagfim1=1;
           }else if (linha_percorre->prox_coluna->colu > coluna){ //add o no
                  novo_no->prox_coluna = linha_percorre->prox_coluna;
                  linha_percorre->prox_coluna = novo_no;
                  flagfim1=1;
           }
           linha_percorre = linha_percorre->prox_coluna;
      }
      if(!flagfim1){
              linha_percorre->prox_coluna = novo_no;
      }     
   }else{
      if(MA->linhas[linha]){
         novo_no->prox_coluna = MA->linhas[linha];
         MA->linhas[linha] = novo_no; 
      }else{
          MA->linhas[linha] = novo_no;
      }  
   }

   if(colu_percorre && linha != 0){ //insere coluna
      while(colu_percorre->prox_linha){
           if(colu_percorre->prox_linha->lin == linha){
              if(colu_percorre->prox_linha->prox_linha){
                  novo_no->prox_linha = colu_percorre->prox_linha->prox_linha;
                  colu_percorre->prox_linha = novo_no;
              }else{
                  colu_percorre->prox_linha = novo_no;
              }       
              flagfim1=1;
           }else if (colu_percorre->prox_linha->lin > linha){ //add o no
                  novo_no->prox_linha = colu_percorre->prox_linha;
                  colu_percorre->prox_linha = novo_no;
                  flagfim2=1;
           }
           colu_percorre = colu_percorre->prox_linha;
      }
      if(!flagfim2){
              colu_percorre->prox_linha = novo_no;
      }     
   }else{
      if(MA->colunas[linha]){
         novo_no->prox_linha = MA->colunas[linha];
         MA->colunas[linha] = novo_no; 
      }else{
          MA->colunas[linha] = novo_no;
      }
   }

   MA->n_vals++;
   return 1;
}


void imprime_ma(MATRIZ* MA){
     int linhas =MA->n_lins;
     int colunas = MA->n_cols;
     int col_ante,col_atual;
     for (int i = 0; i < linhas; i++)
     { 
        printf("Linha %d ", i);
        NO* aux = MA->linhas[i];

        if(!aux){
         for (int i = 0; i < colunas; i++){
              printf(" 0 ");
         } 
         continue;
        }

        col_atual = aux->colu;       
        for (int i = 0; i < colunas; i++)
        { 
          if(i==col_atual){
             printf(" %d ",aux->item);
             aux = aux->prox_coluna;
             if(aux)
               col_atual = aux->colu;
          }else{
            printf(" 0 ");
          }     
        }    
        printf("\n");         
   }       
}
     
/*int main(){


   MATRIZ* MA1 = matriz_criar(2,2);
   insere_valor(3,0,0,MA1);
  // insere_valor(3,1,1,MA1);
   insere_valor(2,0,1,MA1);
  // insere_valor(2,1,0,MA1);

   imprime_ma(MA1);
}*/