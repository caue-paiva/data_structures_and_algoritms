#include "avl.h"
#define max(a,b) ((a>b) ? a: b)  //macro para comparacao entre dois valores


struct no_arv {
    ITEM  *item;  //struct do no, contendo um item, nos dir e esq e sua altura
    NO_ARV *esq;
    NO_ARV *dir;
    int altura;
};


struct avl{
    NO_ARV *raiz;
    int profundidade;  //struct avl com a raiz, num de elementos e profundidade
    int num_elem;  //num de elem e uma variavel util para varias operacoes, incluindo as de conjuntos
};

NO_ARV** acha_menor_aux(NO_ARV** raiz){
    if(!(raiz) || !(*raiz) )  //acha o menor valor na arvore ou sub-arvore
       return NULL;    
    if(!(*raiz)->esq)
        return raiz;
    else
        return acha_menor_aux(& ((*raiz)->esq));
}

NO_ARV* avl_acha_menor(AVL* arvo){
    return *acha_menor_aux( (&(arvo->raiz)) );  //wrapper function na acha menor aux, melhor usabilidade
}

NO_ARV** acha_maior_aux(NO_ARV** raiz){ //acha o maior valor na arvore ou sub-arvore
    if(!(raiz) || !(*raiz) )
       return NULL;    
    if(!(*raiz)->esq)
        return raiz;
    else
        return acha_maior_aux( &((*raiz)->dir));
}

NO_ARV* avl_acha_maior(AVL* arvo){   //wrapper function na acha maior aux, melhor usabilidade
    return *acha_maior_aux( (&(arvo->raiz)) );
}

void avl_imprime_aux(NO_ARV* no_atual){
    if(no_atual)
       printf("%d, ", item_get_chave(no_atual->item));
    else 
      return;
    avl_imprime_aux(no_atual->dir);  //funcao auxiliar de imprimir todos os elementos da arvore
    avl_imprime_aux(no_atual->esq);
}

void avl_imprime(AVL* arvo){
    if(arvo->raiz)  // wrapper function da imprime aux para ser usada pelo user (
      avl_imprime_aux(arvo->raiz);
    else
        printf("vazio");
    printf("\n");
}

void troca_max_esq(NO_ARV *troca, NO_ARV *raiz, NO_ARV *ant){
    if(troca->dir != NULL){  //funcao que acha o maior elemento da sub-arvore a esquerda de um no, usada na func de remocao
        troca_max_esq(troca->dir, raiz, troca);
        return;
    }
    if(raiz == ant) ant->esq = troca->esq;
    else ant->dir = troca->esq;
    raiz->item = troca->item;
    free(troca);
    troca = NULL;
}

bool aux_avl_busca(NO_ARV* no_atual, ITEM* item){ //funcao que busca um no que tenha um certo item
    if(!no_atual)
       return false;
    int valor_buscado = item_get_chave(item);
    int valor_atual = item_get_chave(no_atual->item); //pega os valores atuais e buscados
    
    if(valor_atual == valor_buscado) //achamos o valor que buscamos
       return true;

    if(valor_atual > valor_buscado){
        if(!no_atual->esq) //se o valor atual for maior que o buscado, vai para esquerda
           return false;
        else
           return aux_avl_busca(no_atual->esq,item);
    }else{
        if(!no_atual->dir) //se o valor atual for menor que o buscado, vai para dir
            return false;
        else
            return  aux_avl_busca(no_atual->dir, item);
    }
}

bool avl_busca_item(AVL* arv, ITEM* item){ //funcao usada pelo user que chama a funcao aux_busca
    if(!arv)
      return false;
    return aux_avl_busca(arv->raiz, item);
}
     
NO_ARV* avl_busca_pai(NO_ARV* raiz, ITEM* procurado){ //funcao para buscar um pai de um no, nao utilizada nas outras funcoes da AVL, mas implementada para outras funcionalidades futuras
    if(!raiz ||item_get_chave(raiz->item) == item_get_chave(procurado)) // nesse caso a raiz é o item, não tem pai
       return NULL;
    
    if(item_get_chave(raiz->item) < item_get_chave(procurado)) {
        if(raiz->dir){  //se o item procurado for maior, vai para dir
            if (item_get_chave(raiz->dir->item) == item_get_chave(procurado)){
                return raiz;
            }else
            return avl_busca_pai(raiz->dir, procurado);
        }else 
          return NULL;
    }

    if(item_get_chave(raiz->item) > item_get_chave(procurado)) {
        if(raiz->esq){  //se o item procurado for maior, vai para esque
            if (item_get_chave(raiz->esq->item) == item_get_chave(procurado)){
                return raiz;
            }else
            return avl_busca_pai(raiz->esq, procurado);
        }else
          return NULL;
    }
}

void apagar_arvore(NO_ARV **raiz){  //funcao auxiliar de apagar arvore
    if(*raiz){
        apagar_arvore(&((*raiz)->esq)); //chama a funcao recursivamente para todos os nos da arvore
        apagar_arvore(&((*raiz)->dir));
        item_apagar(&((*raiz)->item));
        free(*raiz); //da free e seta aquele ponteiro como NULL
        *raiz = NULL;
    }
}

NO_ARV *avl_criar_no(ITEM *item){
    NO_ARV *no = (NO_ARV*) malloc(sizeof(NO_ARV));
        if(!no)
           exit(1);
    no->item = item;
    no->altura = 0;
    no->esq = NULL;  //cria um no e configura suas variaveis como seus valores iniciais
    no->dir = NULL;
    return (no);
}

int avl_altura_no(NO_ARV* no){
    if(!no) 
       return -1;
    else //funcao que retorna a altura de um no
      return no->altura;
}

NO_ARV* rotacao_dir(NO_ARV* desbalan){
    NO_ARV* nova_raiz = desbalan->esq;
    desbalan->esq = nova_raiz->dir;  //funcao que implementa a rotacao para direita
    nova_raiz->dir = desbalan;
    desbalan->altura = max(avl_altura_no(desbalan->esq), avl_altura_no(desbalan->dir)) + 1; //calcula novas alturas
    nova_raiz->altura = max(avl_altura_no(nova_raiz->esq), avl_altura_no(nova_raiz->dir)) + 1;
    return nova_raiz;
}

NO_ARV* rotacao_esq(NO_ARV* desbalan){
    NO_ARV* nova_raiz = desbalan->dir;
    desbalan->dir = nova_raiz->esq; //funcao que implementa a rotacao para esquerda
    nova_raiz->esq = desbalan;
    desbalan->altura = max(avl_altura_no(desbalan->esq), avl_altura_no(desbalan->dir)) + 1; //calcula novas alturas
    nova_raiz->altura = max(avl_altura_no(nova_raiz->esq), avl_altura_no(nova_raiz->dir)) + 1;
    return nova_raiz;
}

NO_ARV* rotacao_esq_dir(NO_ARV* desbalan){
    desbalan->esq = rotacao_esq(desbalan->esq);  //o filho de desbalanca que vai receber o novo no balanceado
    return rotacao_dir(desbalan);  //aplica a segunda rotacao
}

NO_ARV* rotacao_dir_esq(NO_ARV* desbalan){
    desbalan->dir = rotacao_dir(desbalan->dir);  //o filho de desbalanca que vai receber o novo no balanceado
    return rotacao_esq(desbalan); //aplica a segunda rotacao
}

NO_ARV* avl_insere_no(NO_ARV* raiz, NO_ARV* novo_no){  //funcao auxiliar que insere um nó e aplica rotacoes
    if(!raiz)  //se o no for null, insere ele aqui
        raiz = novo_no;
    else if(item_get_chave(novo_no->item) < item_get_chave(raiz->item))  //percorre a arvore, se for um item maior doq o que vamos inserir, vamos para esquerda
          raiz->esq = avl_insere_no(raiz->esq,novo_no);
    else if (item_get_chave(novo_no->item) > item_get_chave(raiz->item)) //percorre a arvore, se for um item menor doq o que vamos inserir, vamos para direita
          raiz->dir =  avl_insere_no(raiz->dir,novo_no);

    raiz->altura = max(avl_altura_no(raiz->esq), avl_altura_no(raiz->dir)) + 1; //atualiza a altura do no 
    
    if((avl_altura_no(raiz->esq)- avl_altura_no(raiz->dir)) == 2)  //checa se o fator de desbalanceamento é 2 e se for, aplica rotacao
        if(item_get_chave(novo_no->item) > item_get_chave(raiz->esq->item))  //verifica se pprecisa fazer uma rotacao dupla ou nao
           raiz = rotacao_esq_dir(raiz);
        else
          raiz = rotacao_dir(raiz);
    if((avl_altura_no(raiz->esq)- avl_altura_no(raiz->dir)) == -2) //checa se o fator de desbalanceamento é -2  e se for, aplica rotacao
        if(item_get_chave(novo_no->item) < item_get_chave(raiz->dir->item)) //verifica se pprecisa fazer uma rotacao dupla ou nao
           raiz = rotacao_dir_esq(raiz);
        else
          raiz = rotacao_esq(raiz);

    return raiz;        //retorna o no modificado dps da remocao e rotacao
}

bool avl_inserir(AVL* arvo, ITEM* item){
    if(!arvo){
      item_apagar(&item);
      printf("arvore nao existe \n"); //msg de erro avisando que a arv n existe
      return false;
    }
    if(avl_busca_item(arvo,item)){
       item_apagar(&item); //vamos desalocar o item que foi usado para tentar insercao
       printf("esse item ja existe\n");  //msg de erro avisando o user que o elemento ja existe na árvore
       return false;
    } 
    NO_ARV* novo_no = avl_criar_no(item);  //cria um novo no
    arvo->raiz = avl_insere_no(arvo->raiz,novo_no);  //chama a funcao aux de inserir
    (arvo->num_elem)++; //aumenta o numero de elementos na arvore
    arvo->profundidade = max( avl_altura_no(arvo->raiz->dir), avl_altura_no(arvo->raiz->esq) )+1; //muda a profudidade da arvore
    return true;
}

AVL *avl_criar(void){
    AVL *arv = (AVL*) malloc(sizeof(AVL)); //essa funcao cria uma AVL, configura seus parametros iniciais e retorna ela
    if(!arv)
       exit(1);
    arv->raiz = NULL;
    arv->profundidade = -1;
    arv->num_elem = 0;
    return (arv);
}

void avl_apagar_arvore(AVL **T){ //funcao que o usuario tem acesso para apagar um arvore, chama a funcao aux de apagar
    apagar_arvore(&(*T)->raiz);
    free(*T);
    *T = NULL;
}

NO_ARV* remove_arvo(NO_ARV** raiz, ITEM* item){  //funcao auxiliar que remove um item da arvore e aplica rotacoes se precisar
    if(!(*raiz))  //no é nulo
      return NULL;

    int valor_buscado = item_get_chave(item); //valor que estamos procurando
    if(valor_buscado == item_get_chave((*raiz)->item)){
       if(!(*raiz)->dir || !(*raiz)->esq){ //caso em que ou nao tem filhos ou so tem 1 filho em qualquer lado
        NO_ARV* temp_no = *raiz;
        if (!(*raiz)->dir)
            (*raiz) = (*raiz)->esq;
        else if (!(*raiz)->esq)
           (*raiz) = ((*raiz)->dir);
        item_apagar(&temp_no->item);
        free(temp_no);
        temp_no = NULL;
       }else 
          troca_max_esq((*raiz)->esq,(*raiz),(*raiz)); //caso em que tem 2 filhos, chama a funcao troca_max_esq
    }else if(valor_buscado > item_get_chave((*raiz)->item)) //se o valor buscado for maior vamos para dir
       (*raiz)->dir = remove_arvo(&(*raiz)->dir, item);
    else
       (*raiz)->esq = remove_arvo(&(*raiz)->esq, item); //se o valor buscado for menor vamos para esq


    //rotina de rotacao, similar a na insercao
    if (*raiz){
     (*raiz)->altura = max( avl_altura_no((*raiz)->dir), avl_altura_no((*raiz)->esq ) )+1;  //coloca a nova altura da arvore

        if((avl_altura_no((*raiz)->esq) - avl_altura_no((*raiz)->dir)) == 2)  //verifica o fator de balanceamento para ver se precisa de rotacao
           if((avl_altura_no((*raiz)->esq->esq) - avl_altura_no((*raiz)->esq->dir)) >= 0 )  //verifica o sinal do filho para ver se precisa de rota dupla
              (*raiz) = rotacao_dir((*raiz));
           else
              (*raiz) = rotacao_esq_dir((*raiz));
             
        if((avl_altura_no((*raiz)->esq)- avl_altura_no((*raiz)->dir)) == -2)  //verifica o fator de balanceamento
          if( (avl_altura_no((*raiz)->dir->esq) - avl_altura_no((*raiz)->dir->dir)) <= 0 ) 
               (*raiz) = rotacao_esq((*raiz));
           else
               (*raiz) = rotacao_dir_esq((*raiz));
             

    return (*raiz);         //retorna o no modificado dps da remocao e rotacao
    }
}

bool avl_remove(AVL*arv, ITEM* item){  //funcao usada pelo user para remover da avl
    if(!arv)
      return false;
    if(!avl_busca_item(arv,item)){ //se o item nao existe, a operacao e invalida
      item_apagar(&item); //vamos desalocar o item que foi usado para tentar remocao
      printf("esse item nao existe \n");
      return false;
    }  
    NO_ARV* nova_raiz = remove_arvo(&(arv->raiz),item);  //nova raiz é retornada da operacao
    if(!nova_raiz){
      item_apagar(&item); //vamos desalocar o item que foi usado para tentar remocao
      return false;
    }
    else{
        arv->raiz = nova_raiz; //coloca nova raiz
        (arv->num_elem)--; //reduz o numero de elementos da arvore
        arv->profundidade = max( avl_altura_no(nova_raiz->dir), avl_altura_no(nova_raiz->esq ) )+1; //muda a profudidade da arvore
        return true;
    }
}

int avl_profundidade(AVL* arv){
    if(!arv)
      return -2; //se a arvore em si n existe , retorna -2
    if(!arv->raiz)
      return -1; //se o no raiz n existe, retorna -1
    return arv->profundidade;  //retorna prof max  arvore
}

int avl_num_elem(AVL* arv){
    if(!arv)
      return -1;
    return arv->num_elem; //retorna o num de elementos na arvore
}

//essa funcao extrai os conteudos de um AVL e coloca eles num vetor, esse vetor e usado em operacoes, por ser mais facil de ser manipulado e acessar seus elementos
//essa funcao realiza apenas uma iteracao sobre todos os elementos da arvore, sendo O(N), eficiente pois temos que mover interagir com N elementos de qualquer jeito

/*
void vetor_avl_aux(int* vetor, NO_ARV* no_atual, NO_ARV* raiz_da_arvo){ //temos uma variavel para a raiz da arvore para comparacao  e dizer se chegamos no final da volta da recursao
    if(!no_atual || !raiz_da_arvo)
       return;
    static int index_atual = 0; //essa variavel static mantem conta de qual index do vetor vamos inserir cada elemento
    int elemento_arvore = item_get_chave(no_atual->item);
    vetor[index_atual] = elemento_arvore;
    index_atual++; //insere o elemento no index e incrementa ele

    vetor_avl_aux(vetor, no_atual->dir, raiz_da_arvo);
    vetor_avl_aux(vetor, no_atual->esq, raiz_da_arvo);

    if(no_atual == raiz_da_arvo) //se ao voltar das chamadas recursivas estivermos na raiz novamente, setamos o index para zero
        index_atual = 0;
} 

int* avl_para_vetor(AVL*arv){ //funcao disponivel para o usuario para extrair os elementos de uma AVL para um vetor
    if(!arv || ! arv->raiz)
       return NULL;
    int* novo_vetor = (int*) malloc (sizeof(int) * (arv->num_elem)); //aloca um novo vetor de N elementos
    if(!novo_vetor)
       return NULL; //essa funcao precisa ser null checada ao ser usada
    vetor_avl_aux(novo_vetor, arv->raiz, arv->raiz); //copia os elementos para esse novo vetor
    return novo_vetor;
} */




/*devido a necessidade de fazer a pilha importar a avl, e o conjunto importar a pilha, para permitir uma travessia pelos elementos do conjunto implementado com avl mais eficiente, foi necessario criar
varias funcoes que realizam operacoes basicas como pegar os items, e nos da direita/esque, porem isso foi feito de acordo com os principios de TAD, garantind encapsulamento
e interoperabilidade entre varios programas*/


ITEM* retorna_item_no_ARV(NO_ARV* no){  //funcoes necessarias para a pilha interagir com os nos das arvores
    if(!no)
       exit(1);
    return no->item;
}

NO_ARV* avl_pega_raiz(AVL* arv){
    if(!arv)
      exit(1);
    return arv->raiz;
 }
NO_ARV* no_avl_pega_dir(NO_ARV* no){
    return no->dir;
}

NO_ARV* no_avl_pega_esq(NO_ARV* no){  //pega dir e esq nao fazem null check por que um no da direita/esque ser null nao e um erro e é utilizado na logica de outras funcoes
    return no->esq;
 }

ITEM* no_avl_pega_item(NO_ARV* no){
    if(!no)
      exit(1);
    return no->item;
 }

