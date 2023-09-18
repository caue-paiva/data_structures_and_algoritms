#include <stdio.h>
#include "item.h"
#include "pilha.h"
#include <stdlib.h>
#include <stdbool.h>

int main(){

    int N_LIN, M_COL;
    scanf("%d %d", &N_LIN, &M_COL);
    int MA[N_LIN][M_COL];

    PILHA *p = pilha_criar();

    for(int i=0;i<N_LIN;i++){
        for(int j =0;j<M_COL;j++){
            scanf("%d", &MA[i][j]);
        }
    }


    ITEM *ITEM_X = item_criar(0);
    ITEM *ITEM_Y = item_criar(0);

    bool achouSaida = false;
    bool devePrintar = true;

    while(MA[item_get_chave(ITEM_X)][item_get_chave(ITEM_Y)] != 2){

        // if (MA[item_get_chave(ITEM_X)][item_get_chave(ITEM_Y)] == 2) {
        //   achouSaida = true;
        //   devePrintar = false;
        //   printf("(%d,%d)\n", item_get_chave(ITEM_X), item_get_chave(ITEM_Y));
        //   break; 
        // }

        if (MA[item_get_chave(ITEM_X)][item_get_chave(ITEM_Y)] == 2) {
         achouSaida = true;
         break; 
        }

       
        if(((item_get_chave(ITEM_X))+1 != N_LIN) && (MA[item_get_chave(ITEM_X)+1][item_get_chave(ITEM_Y)] != 0)){            
                ITEM *TEMPx;
                ITEM *TEMPy;
            
                TEMPx = item_criar(item_get_chave(ITEM_X) + 1);
                TEMPy = item_criar(item_get_chave(ITEM_Y));
            
                pilha_empilhar(p,TEMPx);
                pilha_empilhar(p,TEMPy);
          
        }
            
        
        if((item_get_chave(ITEM_Y)>0) && (MA[item_get_chave(ITEM_X)][item_get_chave(ITEM_Y)-1] != 0)){
                ITEM *TEMPx;
                ITEM *TEMPy;               
                
                TEMPx = item_criar(item_get_chave(ITEM_X));
                TEMPy = item_criar(item_get_chave(ITEM_Y)-1);
                
                pilha_empilhar(p,TEMPx);
                pilha_empilhar(p,TEMPy);
        }


        if((item_get_chave(ITEM_X)>0) && (MA[item_get_chave(ITEM_X)-1][item_get_chave(ITEM_Y)] != 0)){
            ITEM *TEMPx;
            ITEM *TEMPy;
            TEMPx = item_criar(item_get_chave(ITEM_X) - 1);
            TEMPy = item_criar(item_get_chave(ITEM_Y));
            pilha_empilhar(p,TEMPx);
            pilha_empilhar(p,TEMPy);

        }

        if((item_get_chave(ITEM_Y)+1 != M_COL) && (MA[item_get_chave(ITEM_X)][item_get_chave(ITEM_Y)+1] != 0)){
                ITEM *TEMPx, *TEMPy;
                
                TEMPx = item_criar(item_get_chave(ITEM_X));
                
                TEMPy = item_criar(item_get_chave(ITEM_Y)+1);

                
                pilha_empilhar(p,TEMPx);
                pilha_empilhar(p,TEMPy);
               

            }

    
        MA[item_get_chave(ITEM_X)][item_get_chave(ITEM_Y)] = 0;

        
       
       
          if(pilha_vazia(p)){
            printf("Saída não encontrada.");
            devePrintar  = false;
            //printf("(%d, %d)\n", item_get_chave(ITEM_X), item_get_chave(ITEM_Y));
            break;
        }

        
         printf("(%d, %d)\n", item_get_chave(ITEM_X), item_get_chave(ITEM_Y));

      


        ITEM_Y = pilha_desempilhar(p);          
        ITEM_X = pilha_desempilhar(p);

        
        
          
    }   
    if(devePrintar){
        printf("(%d, %d)\n", item_get_chave(ITEM_X), item_get_chave(ITEM_Y));
    }
    

     return 0;
}