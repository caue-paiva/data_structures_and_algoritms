#include "Pilha.h"
#include "stdio.h"
#include "stdlib.h"

bool chave_certa(char C1, char C2){
     if (C1 == '(' && C2 == ')'){
       return true;
     } else if (C1 == '[' && C2 == ']'){
      return true;
     } else if (C1 == '{' && C2 == '}'){
      return true;
     } else {
      return false;
     }

}


bool balanceada(char* sequencia){
    PILHA* Pilha1 = pilha_criar();
    int i = 0;
    while (sequencia[i] != '\0') {
          char char_atual = sequencia[i];
         if (char_atual == '(' || char_atual == '[' || char_atual == '{') {
           
            ITEM* novo = item_criar(char_atual);

            if (novo == NULL) {
               return false; 
               }
            if (!pilha_empilhar(Pilha1, novo)){
               return false; 
               }

           } else if (char_atual == ')' || char_atual == ']' || char_atual == '}') {
             if (pilha_vazia(Pilha1)) { 
               return false; 
               }

             char top = item_get_chave(pilha_topo(Pilha1));
            
             if (chave_certa(top, char_atual)) {
               
                ITEM* temp = pilha_desempilhar(Pilha1);
                item_apagar(&temp);  
             } else {
                  return false; 
              }
        }
        i++;
    }
    return pilha_vazia(Pilha1);
}

