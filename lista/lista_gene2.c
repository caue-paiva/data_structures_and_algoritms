#include "stdlib.h"
#include "stdio.h"




enum tipo_lista {
    STR = -1,  //ponteiro para char
    INT = 0,
    LIST = 1,
    VOIDLIST = 2 //a cabeça da lista começa como nada, tem que pular
};


typedef struct bloco {
    union {
      void* atomo;
      struct bloco *sublista;
    } compo;

    enum tipo_lista tipo;
    struct bloco *prox;
} NO;



NO* listagene_criar(){
    NO* novo_no = (NO*) malloc(sizeof(NO));
        if (novo_no== NULL){ exit(1);}

   novo_no ->prox = NULL;
   novo_no->tipo = VOIDLIST;
   novo_no->compo.atomo =NULL;
   novo_no->compo.sublista =NULL;

   return  novo_no;
    
}

NO* No_criar(void* item, enum tipo_lista tipo ){
     NO* novo_no = (NO*) malloc(sizeof(NO));
            if (novo_no ==NULL){ exit(1);}
    
    switch (tipo)
    {
    case INT:
        //novo_no->compo.atomo =  malloc(sizeof(int));
        //if (novo_no->compo.atomo == NULL) { exit(1); }
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

int lista_gen_remover(void*item , enum tipo_lista tipo, NO**list){
  NO* aux = *list;
  if(!aux){return 0;}
  NO* ante =NULL;
  while(aux){
    enum tipo_lista tipagem = aux->tipo;
    switch (tipagem)
    {
    case LIST:
        if((void*) aux->compo.sublista  == (void*) item){
           NO* temp = aux;
           if(!ante){
              *list = (*list)->prox;
           }else{
            ante->prox = aux->prox;
           }                  
           free(temp);
           break;
        }else{ lista_gen_remover(item,tipo,&aux->compo.sublista);}
        break;     
    default:
      if(tipagem == tipo){
        if(aux->compo.atomo == item){
             NO* temp = aux;
          if(!ante){
              *list = (*list)->prox;
           }else{
              ante->prox = aux->prox;
           }   
           free(temp);
         }
         break; 
      }
    } 
    ante = aux;
    aux = aux->prox;
  }

  return 1;
}

int listagene_adicionar(void*  item, enum tipo_lista tipo, NO** list){  //funcao generica que add atomos e sublistas 
    NO* novo_no = No_criar(item,  tipo);
        if (novo_no ==NULL){exit(1);}
    if ((*list)->tipo == VOIDLIST){
        novo_no->tipo = tipo;
        free(*list);
        *list = novo_no;
    } else{    
        NO* aux = *list;
        while(aux->prox != NULL){ aux = aux->prox;}  
        aux->prox = novo_no; 
    }
    //novo_no já é criado com seu prox setado para NULL
    return 1;
  
}

void listagene_print(NO* no){
  //NO* temp = no;
  printf("[");
  while(no != NULL){
    //printf("tipo  atual %d\n ",no->tipo);
    switch (no->tipo)
    {    
        case INT:
           printf("%d ", *((int*)no->compo.atomo));
           break;
        case STR:
           printf("%s ", (char*) no->compo.atomo);
           break; 
        case LIST:
           // printf("[ ");
            listagene_print(no->compo.sublista);
           // printf(" ] ");
         break;  
      case VOIDLIST:
         printf("VAZIO");
         break;         
        default:
            printf("tipo não válido");
            break;
    }
     no = no->prox;
    // printf("completou um loop \n");
  }
   printf("]");
  
}

void lista_gene_vazia(NO*no){   
     NO* aux = no;
     printf("[");
     int flag = 0;
     while(aux){
        switch (aux->tipo)
        {

        case VOIDLIST:
            printf(" vazia ");
            break;    
        case LIST:
            lista_gene_vazia(aux->compo.sublista);
            break;
        default:
            flag =1;
            break;
        }
        aux = aux->prox;
     }
     if (flag){printf(" nao vazia ");}
     printf("]");
}

int main(){
    NO* L1;
    NO* L2;
    NO*L3;
    NO*L4;
    L1 = listagene_criar();
    L2 = listagene_criar();
    L3= listagene_criar();

    int a = 5, b=9, c=6, d=8, h=9, j=10;
    //int b=9, c =6;

    char str[4];
    str[0]= 'a';
    str[1]= 'b';
    str[2]= 'g';

    listagene_adicionar(&a,INT,&L1);
    listagene_adicionar(&b,INT,&L1);
    //listagene_adicionar(&c,INT,L1);


    //listagene_adicionar(&c,INT,&L2);
    //listagene_adicionar(&d, INT, &L2);
    listagene_adicionar(L2,LIST,&L1);
    listagene_adicionar(L3,LIST,&L1);
    listagene_adicionar(&h,INT,&L3);
    listagene_adicionar(&h,INT,&L3);
    listagene_adicionar(str,STR,&L3);
    listagene_adicionar(&j,INT,&L1);
    listagene_print(L1);

    //lista_gen_remover(L2,LIST,&L1);

    printf("\n\n");
    //listagene_print(L1);

    lista_gene_vazia(L1);
}





















