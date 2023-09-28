#include "stdlib.h"
#include "stdio.h"




enum tipo_lista {
    STR = -1,  //ponteiro para char
    INT = 0,
    LIST = 1,
    NILL = -1239  //quando não existe tipo
};


typedef struct bloco {
    union {
      void* atomo;
      struct bloco *sublista;
    } compo;

    enum tipo_lista tipo;
    struct bloco *prox;
} NO;


typedef struct {
     NO* comeco;
     NO* fim;
     int tam;
} lista_gene;


lista_gene* listagene_criar(){
    lista_gene* novo_lista = (lista_gene*) malloc(sizeof(lista_gene));
        if (novo_lista== NULL){ exit(1);}

    novo_lista->tam = 0;
    novo_lista ->comeco = NULL;
    novo_lista ->fim = NULL;

    return  novo_lista ;
    
}

NO* No_criar(void* item, enum tipo_lista tipo ){
     NO* novo_no = (NO*) malloc(sizeof(NO));
            if (novo_no ==NULL){ exit(1);}
    switch (tipo)
    {
    case INT:     
        novo_no->compo.atomo = item;
        novo_no->tipo= INT;
        novo_no->prox = NULL;
        break;

    case STR: 
        novo_no->compo.atomo = item;
        novo_no->tipo= STR;
        novo_no->prox = NULL;
        break;

    case LIST:
        novo_no->compo.sublista = item;
        novo_no->tipo= LIST;
        novo_no->prox = NULL;
        break;

    default:
        printf(" tipo nao valido \n");
        return NULL;
        break;
    }

    return novo_no;
}

// NO* sublista_criar(*NO sub_list){
//       NO* novo_no = (NO*) malloc(sizeof(NO));
//             if (novo_no ==NULL){ exit(1);}
//       novo_no->compo
// }

int listagene_adicionar(void*  item, enum tipo_lista tipo, lista_gene* list){  //funcao generica que add atomos e sublistas 
  
    NO* novo_no = No_criar(item,  tipo);
        if (novo_no ==NULL){exit(1);}
    
    if(list->tam == 0){
        list->comeco = novo_no;
        list->fim = novo_no;
        list->tam += 1;
        return 1;
    } else{
        list->fim->prox =  novo_no; //novo_no já é criado com seu prox setado para NULL
        list->fim = novo_no;
        list->tam +=1;
        return 1;
    }
    return 0;
}


void listagene_print(NO* no){
  //NO* temp = no;
  
  while(no != NULL){

    switch (no->tipo)
        {
        case INT:
           printf("%d ", *((int*)no->compo.atomo));
           break;
        case STR:
           printf("%s ", (char*) no->compo.atomo);
           break; 
        case LIST:
              listagene_print(no->compo.sublista);
         break;      
        default:
            printf(" tipo não válido \n");
            break;
        }
     no = no->prox;

  }
  
}

int main(){

lista_gene* L1 = listagene_criar();
int a = 5;
int b=9, c =6;
int* pA = &a;

listagene_adicionar(&a,INT,L1);
listagene_adicionar(&b,INT,L1);
listagene_adicionar(&c,INT,L1);

listagene_print(L1->comeco);




}





















