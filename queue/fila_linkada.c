 #include <stdlib.h>
 #include <stdio.h>
typedef struct no NO;

struct no {
     NO* prox;
     int item;
};

struct fila {
   NO* comeco;
   NO* fim;
   int tam;
};
typedef struct fila FILA;

FILA* fila_criar(void){
     FILA* nova_fila = (FILA*) malloc(sizeof(FILA));
         if (!nova_fila){exit(1);}
     
     nova_fila->comeco =NULL;
     nova_fila->fim = NULL;
     nova_fila->tam =0;

     return nova_fila;
}

NO* no_criar(int item){
   NO* novo_no = (NO*) malloc(sizeof(NO));
      if(!novo_no){exit(1);}
   
   novo_no->item = item;
   novo_no->prox =NULL;
   return novo_no;
}

int fila_push(FILA* fila, int item){
    NO* novo_no = no_criar(item);

    if(!fila->comeco){
      printf("fila vazia \n");
      fila->comeco = novo_no;
      fila->fim = novo_no;
    }else{
      printf("ja tem varios elementos \n");
      fila->fim->prox = novo_no;
      fila->fim = novo_no;
    }
        /*  if(!fila->comeco){
      fila->comeco = novo_no;
      fila->fim = novo_no;
    }else if (!fila->fim->prox){
      fila->fim->prox = novo_no;
    } else {
      fila->fim = fila->fim->prox;
      fila->fim->prox = novo_no;
    }*/

    (fila->tam)++;
    return 1;
}

int fila_vazia(FILA* fila){
   if(!fila->comeco || !fila->fim || fila->tam == 0){return 1;} 
   return 0;
}

int fila_pop(FILA* fila){
   if (fila_vazia(fila)){ exit(1);}
   
   NO* no_removido = fila->comeco;
   int item = no_removido->item;
   fila->comeco = fila->comeco->prox;
   free(no_removido);
   (fila->tam)--;
   return item;
}

int main(){

 FILA* F1 = fila_criar();
 fila_push(F1,3);
 fila_push(F1,4);
 fila_push(F1,5);
 fila_push(F1,6);

 for(int i=0 ; i <4; i++){

   printf("%d ", fila_pop(F1));
 }






 }