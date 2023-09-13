#include <stdio.h>
#include "item.h"
#include "pilha.h"
#include <stdlib.h>
#include <stdbool.h>

int main(){

    int n_linhas, m_colunas;
    scanf("%d %d", &n_linhas, &m_colunas);
    int matriz[n_linhas][m_colunas];

    PILHA *p = pilha_criar();

    for(int i=0;i<n_linhas;i++){
        for(int j =0;j<m_colunas;j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    // Toda vez que eu desempilhar um elemento eu tenho que printá-lo7

    ITEM *itemx = item_criar(0);
    ITEM *itemy = item_criar(0);

    // EMPILHAR X E DEPOIS Y. DESEMPILHAR Y E DEPOIS X


    // Só falta colocar o zero agora

    while(matriz[item_get_chave(itemx)][item_get_chave(itemy)] != 2){
       // printf("Antes dos if");

        // TÁ DANDO PROBLEMA NO IF
        if(((item_get_chave(itemx))+1 != n_linhas) && (matriz[item_get_chave(itemx)+1][item_get_chave(itemy)] != 0)){
            ITEM *tmpx, *tmpy;
            tmpx = item_criar(item_get_chave(itemx) + 1);
            tmpy = item_criar(item_get_chave(itemy));
            pilha_empilhar(p,tmpx);
            pilha_empilhar(p,tmpy);
           // printf("Foi pra baixo");
        }
            
        
        if((item_get_chave(itemy)>0) && (matriz[item_get_chave(itemx)][item_get_chave(itemy)-1] != 0)){
                ITEM *tmpx, *tmpy;
                tmpx = item_criar(item_get_chave(itemx));
                tmpy = item_criar(item_get_chave(itemy)-1);
                pilha_empilhar(p,tmpx);
                pilha_empilhar(p,tmpy);
        }


        if((item_get_chave(itemx)>0) && (matriz[item_get_chave(itemx)-1][item_get_chave(itemy)] != 0)){
            ITEM *tmpx, *tmpy;
            tmpx = item_criar(item_get_chave(itemx) - 1);
            tmpy = item_criar(item_get_chave(itemy));
            pilha_empilhar(p,tmpx);
            pilha_empilhar(p,tmpy);

        }

        if((item_get_chave(itemy)+1 != m_colunas) && (matriz[item_get_chave(itemx)][item_get_chave(itemy)+1] != 0)){
                ITEM *tempx, *tempy;
                
                tempx = item_criar(item_get_chave(itemx));
                
                tempy = item_criar(item_get_chave(itemy)+1);
               
              //  printf("Pilha topo(y): %d\n", item_get_chave(pilha_topo(p)));
                
                pilha_empilhar(p,tempx);
                pilha_empilhar(p,tempy);
               
              //  printf("Pilha topo(y): %d\n", item_get_chave(pilha_topo(p)));

            }

      //  printf("Não empilhou nada");

        matriz[item_get_chave(itemx)][item_get_chave(itemy)] = 0;

        if(pilha_vazia(p)){
            printf("Caminho não encontrado");
            break;
        }

        itemy = pilha_desempilhar(p);   
        
        itemx = pilha_desempilhar(p);

        printf("(%d,%d)\n", item_get_chave(itemx), item_get_chave(itemy));  // (x,y)


      

        for(int i=0;i<n_linhas;i++){
            printf("\n");
        for(int j =0;j<m_colunas;j++){
      //  printf("%d", matriz[i][j]);
        }
    }        
    }   

     return 0;
}