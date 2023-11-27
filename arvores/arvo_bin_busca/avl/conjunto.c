#include "conjunto.h"

struct conjun_{
    AVL* arvo_elem;
    int num_elem;
};

bool conjun_remove(conjun* C1, ITEM* item){
   if(!C1 || !item)
     return false;
   if(!C1->arvo_elem)  //esse segundo if existe para garantir que a arvo do conjunto n esteja vazia e ele esta abaixo para n dar segfault 
     return false;   //fazer -> em um ponteiro nulo da segfault
   if(avl_remove(C1->arvo_elem, item)){ //n precisa usa a funcao busca conjunto pq a remocao ja busca na arvore
     (C1->num_elem)--;  //chama a funcao remove da AVL, reduz o numero de items do conjunto
     return true;
   }
   return false;
}

bool conjun_pertence(conjun * C1, ITEM* item){
    return avl_busca_item(C1->arvo_elem,item); //busca no conjunto e so uma busca na arvore AVL
}

conjun* conjun_criar(void){
    conjun* novo_conjun = (conjun*) malloc(sizeof(conjun));
         if (!novo_conjun)
           exit(1);
    novo_conjun->num_elem = 0;
    novo_conjun->arvo_elem = avl_criar();
    return novo_conjun;
} 

bool conjun_add_item(conjun * C1, ITEM* item){
    if(!C1)
       return false;
    if(avl_inserir(C1->arvo_elem,item)){
        C1->num_elem++;
        return true;
    }
        return false;
}

conjun* conjun_intersec(conjun* C1,  conjun* C2){
     if (!C1 || !C2)
         printf("quitando programa");
    conjun* novo_conjunto = conjun_criar();
         
    if(!C1->arvo_elem || !C2->arvo_elem || C1->num_elem == 0 || C2->num_elem == 0) //se um dos conjuntos estiver vazio retorna um novo conjunto vazio
        return novo_conjunto;
     
    conjun* maior_conjun;
    conjun* menor_conjun;
    int tam_novo_conjun = 0;
    if(C1->num_elem > C2->num_elem){
        maior_conjun = C1;
        menor_conjun = C2;
    }else{
        maior_conjun = C2;
        menor_conjun = C1;
    }

    int* vetor_menor_conjunto = avl_para_vetor(menor_conjun->arvo_elem);
    if(!vetor_menor_conjunto)
       exit(1);
    ITEM* item_atual;      
  //é mais eficiente loopar no menor conjunto e busca se os seus elementos existem no maior
    for (int i = 0; i < menor_conjun->num_elem ; i++){
        item_atual = item_criar(vetor_menor_conjunto[i]);//achar um jeito de "ITERAR" pela AVL e pegar todos elementos
        if(conjun_pertence(maior_conjun, item_atual)){
           conjun_add_item(novo_conjunto,item_atual);
           tam_novo_conjun++;
        }
               
    }      
    free(vetor_menor_conjunto);
    novo_conjunto->num_elem = tam_novo_conjun;
    return novo_conjunto;
}

void conjun_imprime(conjun* C1){
     if(!C1)
       return;
     avl_imprime(C1->arvo_elem);
}

conjun* conjun_uniao(conjun* C1, conjun* C2){
    if(!C1 || !C2)
       exit(1);

    conjun* novo_conjun =conjun_criar();

    int *vetor1 = avl_para_vetor(C1->arvo_elem);
    int *vetor2 = avl_para_vetor(C2->arvo_elem);
    ITEM* novo_item;
    int novo_num_elem = C1->num_elem;
    for (int i = 0; i < C1->num_elem ; i++){
      novo_item = item_criar(vetor1[i]);
      conjun_add_item(novo_conjun,novo_item);
    }

    for (int i = 0; i < C2->num_elem ; i++){
      novo_item = item_criar(vetor2[i]);
      if(!conjun_pertence(novo_conjun, novo_item)){
        conjun_add_item(novo_conjun,novo_item);
        novo_num_elem++;
      }     
    }
    free(vetor1);
    free(vetor2);
    novo_conjun->num_elem = novo_num_elem;
    return novo_conjun;
}

void conjun_apaga(conjun** C1){
    if(!(*C1)){
      printf("conjunto null");
         return;
    }
    
    avl_apagar_arvore(&((*C1)->arvo_elem));
    printf(" apagou arvo ");
    free(*C1);
    *C1 = NULL;
}

int conjun_tamanho(conjun* C1){
  if(!C1)
    return -1;
  return C1->num_elem;
}