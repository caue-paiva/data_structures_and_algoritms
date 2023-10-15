#include <stdlib.h>
#include <stdio.h>
typedef struct no NO;

enum Position {
   COMECO=1,
   FIM =0
};
typedef struct{
   int id;
   int ano;
   char* nome;
}aluno;

struct no {
    NO* prox;
    aluno* item;
};



typedef struct {
   NO* comeco;
   NO* fim;
   int tam;
} lista;


aluno* cadastra_aluno(char* nome, int ano, int id ){
     aluno* novo_aluno = (aluno*) malloc(sizeof(aluno));
        if(!novo_aluno){exit(1);}
   novo_aluno->id = id;
   novo_aluno->nome = nome;
   novo_aluno->ano = ano;
   return novo_aluno;
}

NO* no_criar(aluno* item){
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

int lista_adicionar(lista* lista, aluno* item, enum Position posicao){
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

int lista_procurar(lista* lista, int id){
   if(lista->tam == 0){return 0;}
   NO* atual = lista->comeco;
   
   while(atual){
      if(atual->item->id == id){
         return 1;
      }
      atual = atual->prox;
   }
   return 0;
}

int lista_remover(lista* lista, int id){
    if(lista->tam==0){return 0;}
    NO* atual = lista->comeco;
    NO* ante=NULL;
    NO* temp;
    int flag;
    
    while(atual){
     temp = atual->prox;
     flag=0;
     if(atual->item->id==id){
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
     printf("aluno: %s  id: %d ",aux->item->nome, aux->item->id);
     aux = aux->prox;
   }while(aux);
   printf("\n");
}

int main(){

lista* L1 = lista_criar();

aluno* A1 = cadastra_aluno("joao",23,120);
aluno* A2 = cadastra_aluno("andre",23,121);
aluno* A3 = cadastra_aluno("feli",23,122);

lista_adicionar(L1,A1,FIM);
lista_adicionar(L1,A2,FIM);
lista_adicionar(L1,A3,COMECO);
//lista_adicionar(L1,2,COMECO);
//lista_adicionar(L1,2,FIM);
lista_printa(L1);

printf("%d \n",lista_procurar(L1,120));
lista_remover(L1,120);
printf("%d \n",lista_procurar(L1,120));
lista_printa(L1);


}