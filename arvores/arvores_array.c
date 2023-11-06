#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef struct no NO;
typedef struct arvore ARVO;
typedef int a_elem;

struct no {
    NO* dir;
    NO* esq;
    a_elem item;
};


struct arvore {
    NO* raiz;   
    int num_items;
    int num_niveis;
};

NO* no_criar(a_elem item){
     NO* novo_no = (NO*) malloc(sizeof(NO));
          if(!novo_no)
             exit(1);
     novo_no->item = item;
     novo_no->dir = NULL;
     novo_no->esq = NULL;

     return novo_no;
}

ARVO* arvore_criar(void){
      ARVO* nova_arvo = (ARVO*) malloc (sizeof(ARVO));
            if(!nova_arvo)
               exit(1);
      nova_arvo->num_items = 0;
      nova_arvo->num_niveis = 1;
      NO* novo_no = (NO*) malloc(sizeof(NO));
          if(!novo_no)
             exit(1);
      novo_no->dir = NULL;
      novo_no->esq = NULL;
      nova_arvo->raiz = novo_no;

      return nova_arvo;
}

bool arvore_adicionar_esq(a_elem item, ARVO* arvo, NO* no){
   static int num_niveis;
   if(!arvo)
      return false;

   if(arvo->num_items == 0){
      arvo->raiz->item = item;
      num_niveis = 0;
      (arvo->num_items)++;
      return true;
   }

   if(!no->esq){
      no->esq = no_criar(item);
      if((num_niveis+1) > arvo->num_niveis)  //num_niveis comeca com zero mas o num de niveis de uma arvore comeca com 1
         arvo->num_niveis= num_niveis + 1;
      num_niveis = 0;
      (arvo->num_items)++;
      return true;
   }

   num_niveis++;
   arvore_adicionar_esq(item,arvo,no->esq);
}

bool arvore_adicionar_dir(a_elem item, ARVO* arvo,NO* no){
   static int num_niveis;
   if(!arvo)
      return false;

   if(arvo->num_items == 0){
      arvo->raiz->item = item;
      num_niveis = 0;
      (arvo->num_items)++;
      return true;
   }

   if(!no->dir){
      no->dir = no_criar(item);
      if((num_niveis+1) > arvo->num_niveis)  //num_niveis comeca com zero mas o num de niveis de uma arvore comeca com 1
         arvo->num_niveis = num_niveis + 1;
      num_niveis = 0;
      (arvo->num_items)++;
      return true;
   }

   num_niveis++;
   arvore_adicionar_dir(item,arvo,no->dir);

}

bool arvore_busca(a_elem item, NO* no){
   if(!no)
       return false;
   if(no->item == item)
      return true;

   bool recu_flag = false;
   if(no->dir){
      if(no->dir->item == item)
        return true;
      recu_flag = true;
   }
   if(no->esq){
      if(no->esq->item==item)
        return true;
      if(arvore_busca(item,no->esq))
         return true;  
   }

   if(recu_flag)
      if (arvore_busca(item,no->dir))
         return true; 
         
   return false;

}

void arvore_printa(NO* no){
   if(!no)
     // printf("\n");
      return;

   printf(" %d", no->item);

   arvore_printa(no->dir);
   arvore_printa(no->esq);
}

bool arvore_remover(a_elem item, ARVO* arvo,NO* no){
   if(!no || !arvo)
       return false;

   if(arvo->raiz->item==item){ //caso raiz é o procurado
    //  printf("caso raiz");
      NO* temp = arvo->raiz;
      arvo->raiz = arvo->raiz->esq;
      if(arvo->raiz->esq)
         arvo->raiz->esq->dir = arvo->raiz->dir;
      else
         arvo->raiz->esq = arvo->raiz->dir;
      arvo->raiz->dir = temp->dir;
      free(temp);
      return true;
   }

   /*if(no->item == item){ //o atual é o procurado
      NO* temp = no;
      if(no->esq){
         no = no->esq;
         if(no->esq)
           no->esq->dir = no->dir;
         else
           no->esq = no->dir;
        no->dir = temp->dir;
      }else{
          no = no->dir;
      }
      free(temp);
      return true;
   }     */

   bool recu_flag = false;
   if(no->dir){
      if(no->dir->item == item){  //o da dir é o procurado
          NO* temp = no->dir;
          if(no->dir->esq){
            no->dir = no->dir->esq;
            if(no->dir->esq)
               no->dir->esq->dir = no->dir->dir;
            else
               no->dir->esq = no->dir->dir;
            no->dir->dir = temp->dir;
          }else{
            no->dir = no->dir->dir;
          }
          free(temp);
          return true;
      }
      recu_flag = true;
   }
   if(no->esq){
      if(no->esq->item==item){ //o da esq é o procurado
          //printf("caso esquerda \n");
          NO* temp = no->esq;
         if(no->esq->esq){
            no->esq = no->esq->esq;
            if(no->esq->esq)
               no->esq->esq->dir = no->esq->dir;
            else
               no->esq->esq = no->esq->dir;
            no->esq->dir = temp->dir;      
          }else{
            no->esq = no->esq->dir;
          }
          free(temp);
          return true;
      }
      if(arvore_remover(item,arvo,no->esq))
         return true;  
      }

   if(recu_flag)
      if (arvore_remover(item,arvo,no->dir))
         return true; 
         
   return false;
}

int main(){
   ARVO* A1 = arvore_criar();

   arvore_adicionar_dir(3,A1,A1->raiz);
   arvore_adicionar_esq(4,A1,A1->raiz);
   arvore_printa(A1->raiz);
  // printf("raiz %d \n", A1->raiz->item);
   //printf("\n existe o numero %d : %d", 5, arvore_busca(5,A1->raiz));
  // printf("checando o 4 : %d \n", A1->raiz->esq->item); 4 ta na esquerda
   printf(" \n removeu o %d : %d \n", 4 , arvore_remover(4,A1,A1->raiz));
   arvore_printa(A1->raiz);


}