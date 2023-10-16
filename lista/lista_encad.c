#include <stdlib.h>
#include <stdio.h>
#include "lista_encad.h"
#define N 100
typedef struct no NO;

struct no {
    NO* prox;
    int item;
};

struct lista_ {
   NO* comeco;
   NO* fim;
   int tam;
};

typedef struct lista_ lista;

NO* no_criar(int item){
   NO* no_novo = (NO*) malloc(sizeof(NO));
     if(!no_novo){exit(1);}

   no_novo->item = item;
   no_novo->prox = NULL;
   return no_novo;
}

lista* lista_criar(void){
    lista* lista_nova = (lista*) malloc(sizeof(lista));
        if(!lista_nova){exit(1);}     
    lista_nova->comeco =NULL;
    lista_nova->fim =NULL;
    lista_nova->tam = 0;
    return lista_nova;  
}

int lista_adicionar(lista* lista, int item, enum Position posicao){
 if(!lista){return 0;}
 NO* novo_no = no_criar(item);
 
 if(posicao == FIM){
   if(!lista->comeco){
      lista->comeco = novo_no;
      lista->fim = novo_no;
   }else{
      lista->fim->prox = novo_no;
      lista->fim = novo_no;
   }
 }else{
   if(!lista->comeco){ //lista vazia
      lista->comeco = novo_no;
      lista->fim = novo_no;
   }else{
       novo_no->prox = lista->comeco;
       lista->comeco = novo_no;
   }

 }
   lista->tam++;
}

int lista_procurar(lista* lista, int item){
   if(lista->tam == 0){return 0;}
   NO* atual = lista->comeco;
   
   while(atual){
      if(atual->item == item){
         return 1;
      }
      atual = atual->prox;
   }
   return 0;
}

int lista_remover(lista* lista, int item){
    if(lista->tam==0){return 0;}
    NO* atual = lista->comeco;
    NO* ante=NULL;
    NO* temp;
    int flag;
    
    while(atual){
     temp = atual->prox;
     flag=0;
     if(atual->item==item){
       if(!ante){
         lista->comeco = atual->prox;
         if(lista->tam==1){ //lista vai ser vazia
            lista->fim = NULL;
         }
       }else{
          ante->prox = atual->prox;
          if(!atual->prox){  //remover do fim
            lista->fim = ante;
          }     
       }  
      flag =1;
      lista->tam--;
     }
       if(flag){
         free(atual);
         atual = temp;
       }else{
          ante = atual;
          atual = atual->prox;
       }
    }
    return 1;
}

void lista_printa(lista*lista){
   if(lista->tam == 0){return;}
   NO* aux = lista->comeco;
   do{
     printf("%d ",aux->item);
     aux = aux->prox;
   }while(aux);
   printf("\n");
}

void printa_posicaoes(lista* l1, lista* l2){
     NO* posi = l2->comeco;
     NO* listaNum = l1->comeco;
     int posi_atual=1;
     int posi_printar;
     do{
       if(!posi){break;}
       posi_printar = posi->item;
      // printf("posi printar: %d \n",posi_printar );
       if(posi_printar == posi_atual){
         printf("%d ",listaNum->item);
        // printf(" printou novo posi atual %d posi printar %d ",posi_atual,posi_printar);
         posi = posi->prox;
         
       }
       listaNum = listaNum->prox;
       posi_atual++;
     }while(listaNum);
}

NO* lista_comeco(lista* l1){
   return (l1->comeco);
}

int no_valor(NO* no){
   return (no->item);
}

void no_avanca(NO** no){
   *no = (*no)->prox;
}

lista* intersec(lista* L1, lista* L2){
     if(!(L1 && L2)){exit(1);}
     int conta_merge = 0;
      NO* aux1;
      NO* aux2;
      NO* comecoMaior;
     lista* nova_lista = lista_criar();
     if(L1->tam < L2->tam){
          aux1 = L1->comeco;  //aux 1 é o menor
          aux2 = L2->comeco;
          comecoMaior = L2->comeco;
     }else{
          aux2 = L1->comeco;
          aux1 = L2->comeco;
          comecoMaior = L1->comeco;
     }
   NO* aux3= NULL;
   while(aux1){
   int item_atual = aux1->item;

   while(aux2){
           if(aux1->item == aux2->item){
            NO* novo_no = no_criar(aux1->item);
            if(!aux3){
               nova_lista->comeco = novo_no;
               aux3 = novo_no;
            }else{
               aux3->prox = novo_no;
               aux3 = aux3->prox;
            }
            conta_merge++;
            break;
           }
           aux2 = aux2->prox;
      }
      aux2=comecoMaior;
      aux1 = aux1->prox;
   }
   if(conta_merge >0){
   nova_lista->fim = aux3;
   nova_lista->fim->prox = NULL;
   nova_lista->tam = conta_merge;
   return nova_lista;
   }else {
    printf("não teve iguais entre os 2");
    return NULL;
   }
}

lista* merge2(lista* L1, lista* L2){
     if(!(L1 && L2)){exit(1);}
     int conta_merge = 0;
     NO* aux1;
     NO* aux2;
     NO* comecoMaior;
     int item_atual, item_escolhido;
     lista* nova_lista = lista_criar();
     if(L1->tam < L2->tam){
          aux1 = L1->comeco;  //aux 1 é o menor
          aux2 = L2->comeco;
          comecoMaior = L2->comeco;
     }else{
          aux2 = L1->comeco;
          aux1 = L2->comeco;
          comecoMaior = L1->comeco;
     }
   NO* aux3= NULL;
  // while(aux1 || aux2){
   item_atual = aux1->item;

   while(aux2 && aux1){          
           if(aux1->item < aux2->item){
               item_escolhido = aux1->item; //menor
               NO* novo_no = no_criar(item_escolhido);
               if(!aux3){
                  nova_lista->comeco = novo_no;
                  aux3 = novo_no;
               }else{
                  aux3->prox = novo_no;
                  aux3 = aux3->prox;
               }
               aux1 = aux1->prox;
           }else{
               item_escolhido = aux2->item;
               NO* novo_no = no_criar(item_escolhido);
               if(!aux3){
                  nova_lista->comeco = novo_no;
                  aux3 = novo_no;
               }else{
                  aux3->prox = novo_no;
                  aux3 = aux3->prox;
               } 
               aux2 = aux2->prox;    
           }    
         }
         if(aux1){            
                do
                { item_escolhido = aux1->item;
                  NO* novo_no = no_criar(item_escolhido);
                  if(!aux3){
                     nova_lista->comeco = novo_no;
                     aux3 = novo_no;
                  }else{
                     aux3->prox = novo_no;
                     aux3 = aux3->prox;
                  } 
                  aux1 = aux1->prox;
                } while (aux1);            
         }else{
              do
                { item_escolhido = aux2->item;
                  NO* novo_no = no_criar(item_escolhido);
                   if(!aux3){
                     nova_lista->comeco = novo_no;
                     aux3 = novo_no;
                  }else{
                     aux3->prox = novo_no;
                     aux3 = aux3->prox;
                  } 
                  aux2 = aux2->prox;
                } while (aux2);      
         }
          nova_lista->fim = aux3;
          nova_lista->fim->prox = NULL;
          nova_lista->tam = (L1->tam) + (L2->tam);
          return nova_lista;
}
      
lista* merge(lista* L1, lista* L2){
      if(!(L1->comeco && L2->comeco)){exit(1);}
      NO* aux1 = L1->comeco;
      NO* aux2 =L2->comeco;
      lista* nova_lista = lista_criar();
      NO* aux3= NULL;
      int item1,item2;
      int flag_maior = 0;
      NO* novo_no; 

      while(aux1 || aux2){    
       if(aux1 && aux2){
           printf("ambos existem \n");
           item1 = aux1->item;
           item2 = aux2->item;
           if(item1>item2){
             printf("escolhe o item 1 %d \n",item1);
             novo_no = no_criar(item1);
             aux1= aux1->prox;
            }else {
               printf("escolhe o item 2 %d \n",item2);
              novo_no = no_criar(item2);
             aux2= aux2->prox;
            }

            if(!aux3){
               aux3 = novo_no;
               nova_lista->comeco = aux3;
            }else{
               aux3->prox =novo_no;
               aux3 = aux3->prox;
            }
          }else if(aux1){
             printf("apenas o 1 existe \n");
             item1 = aux1->item;
             novo_no = no_criar(item1);   
             aux3->prox =novo_no;
             aux3 = aux3->prox; 
             aux1= aux1->prox;
          }else{
             printf("apenas o 2 existe \n");
             item2 = aux2->item;
             novo_no = no_criar(item2);    
             aux3->prox =novo_no;
             aux3 = aux3->prox; 
             aux2= aux2->prox;
          }
          
       }

       nova_lista->fim = aux3;
       nova_lista->fim->prox = NULL;
       nova_lista->tam = (L1->tam) + (L2->tam);
       return nova_lista;

      }

int enesimo_elem(lista* L1, int posi){
    NO* aux = L1->comeco;
    int iter=1;
    do{
      if(iter == posi){
         return aux->item;
      }
      aux= aux->prox;
      iter++;
    }while(aux);   
    printf("nao existe essa posicao ");
    return 0;
}

int iguais_recu(lista* L1, lista* L2){
    if((!L1->comeco && L2->comeco) || (L1->comeco && !L2->comeco)){
      return 0;
    }  
    if(!L1->comeco && !L2->comeco){return 1;}

    if(L1->comeco->item != L2->comeco->item){
      return 0;
    }else{
      L1->comeco = L1->comeco->prox;
      L2->comeco  = L2->comeco->prox;
      iguais_recu(L1,L2);
    }
}

void apaga_lista(lista** lista){
   NO* aux = (*lista)->comeco;
   NO* aux2;
   while(aux){
      aux2 = aux->prox;
      free(aux);
      aux = aux2;
   }
   free(*lista);
   *lista = NULL;
}

lista* intercala_listas(lista* L1, lista* L2){
      lista* nova_lista = lista_criar();
      NO* aux1 = L1->comeco;
      NO* aux2 = L2->comeco;
      NO* aux3= NULL;
      //nova_lista->comeco = aux1;
      int flag = 0; 
      while(aux1 || aux2){
         if(!flag && aux1){
            NO* novo = no_criar(aux1->item);
            if(!aux3){
               aux3 = novo;    
               nova_lista->comeco = aux3;
            } else{
               aux3->prox = novo;
               aux3 = aux3->prox;   
            }    
            aux1 = aux1->prox;         
         }
         if(flag && aux2){
            NO* novo2 = no_criar(aux2->item);
            aux3->prox = novo2;        
            aux2 = aux2->prox;
            aux3 = aux3->prox;   
         }
         flag = flag ^ 1;
      }
      aux3->prox = NULL;
      nova_lista->fim = aux3;
      nova_lista-> tam = (L1->tam + L2->tam);
      return nova_lista;
}

int main(){
   //printf("teste");
   lista* L1 = lista_criar();
   lista* L2 = lista_criar();

   lista_adicionar(L1,3,FIM);
   lista_adicionar(L1,5,FIM);
   lista_adicionar(L1,6,FIM);

   lista_adicionar(L2,6,COMECO);
   lista_adicionar(L2,5,COMECO);
   lista_adicionar(L2,3,COMECO);
  
   printf(" %d ", iguais_recu(L1,L2));
   
   //lista_printa(L1);
   //lista_adicionar(L1,2,COMECO);
   //lista_adicionar(L1,2,FIM);
   //lista_printa(L2);
   //lista* L3 = merge2(L1,L2);
   //printf("%p",L3->fim);
   //lista_printa(L3);
   //printa_posicaoes(L1,L2);
   //printf("%d \n",lista_procurar(L1,2));
   //lista_remover(L1,2);
   //printf("%d \n",lista_procurar(L1,2));
   //lista_printa(L1);


}