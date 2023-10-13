/*NOSKIP * imprime_todas_palavras(char procurado, int nivel, NOSKIP *no) {// nivel é chamada com 4, no começo como NULL
    if(nivel==1){
      // if(no->prox_dir==NULL || item_get_chave(no->prox_dir->item) > procurado){   //(compara_no_string(no->prox_dir, procurado) > 0)
      if(no->prox_dir==NULL || primeiro_char(no->prox_dir, procurado) == 0){
        return NULL;
      }else if(primeiro_char(no->prox_dir, procurado) == -1){  //else if(item_get_chave(no->prox_dir->item) < procurado)
        return imprime_todas_palavras(procurado, nivel, no->prox_dir);
      }else{
        printf("palavra %s def %s", item_get_chave(no->prox_dir->item), item_get_defi(no->prox_dir->item));  //so existe uma palavra com esse charac
        return no->prox_dir;
      }
      
    }// nao encontrado pois estou no nivel mais baixo e o proximo eh nulo ou maior entao nao existe
      
    if(no->prox_dir==NULL || primeiro_char(no->prox_dir, procurado) == 0){
      return imprime_todas_palavras(procurado, nivel-1, no->prox_baixo);
    }
    else if(primeiro_char(no->prox_dir, procurado) == -1){
      return imprime_todas_palavras(procurado, nivel, no->prox_dir);
    }
    else if(primeiro_char(no->prox_dir, procurado) == 1){
       no=no->prox_dir;
      while(no->prox_baixo!=NULL){
        no=no->prox_baixo;
      }
      percorre_linha(no,procurado);
      return no;
    }
}*/

void percorre_linha(NOSKIP*no, char letra){
   NOSKIP* aux = no;
   int flag= 0;
   do{
       if(primeiro_char(aux, letra)){
         printf("\n");
         printf("palavra %s def %s", item_get_chave(aux->item), item_get_defi(aux->item));
         flag = 1 ;
       } else if (primeiro_char(aux,letra) == 0){
         if (!flag){
            printf("NAO HA PALAVRAS INICIADAS POR %c \n",letra);
         }
         return;
       }
     aux = aux->prox_dir;
   } while(aux != NULL);

    if (!flag){
      printf("NAO HA PALAVRAS INICIADAS POR %c \n",letra);
   }
}


/*void remove_lista_skip(char* procurado, int nivel, NOSKIP *no) {
    if(no->prox_dir != NULL){
    if(no->prox_dir->item != NULL){
    if(compara_no_string(no->prox_dir, procurado) == 0){
        NOSKIP* toDelete=no->prox_dir;
        no->prox_dir=no->prox_dir->prox_dir;
        if(nivel==1){
            item_apagar(&toDelete->item);
        }
        free(toDelete);
        if(nivel!=1){
            remove_lista_skip(procurado, nivel-1, no->prox_baixo);
        }
    }
    }
    }
   
    if(no->prox_dir==NULL && no->prox_baixo==NULL){//nao existe o procurado
        //printf("OPERACAO INVALIDA, nao existe o %s \n", procurado);
        return;
    }

    if(no->prox_dir==NULL){
        remove_lista_skip(procurado, nivel-1, no->prox_baixo);
        return;
    }

    if(no->prox_baixo==NULL ){
       if(compara_no_string(no->prox_dir, procurado) < 0){
        remove_lista_skip(procurado, nivel, no->prox_dir);
        return;
       }
    }

    if(no->prox_baixo==NULL ){
       if(compara_no_string(no->prox_dir, procurado) > 0){
        printf("OPERACAO INVALIDA, nao existe o %s \n", procurado);
        return;
       }
    }
    
    if(no->prox_dir != NULL){
    if(no->prox_dir-> item != NULL){
    if(compara_no_string(no->prox_dir, procurado) > 0){
        remove_lista_skip(procurado, nivel-1, no->prox_baixo);
        return;
    }
    if(compara_no_string(no->prox_dir, procurado) < 0){
        remove_lista_skip(procurado, nivel, no->prox_dir);
        return;
    }
    }
    }
    
}*/



/*NOSKIP * insercao(char* inserir,char* defini , int nivel, NOSKIP *no) {
    if( no->prox_dir == NULL && nivel==1){
      NOSKIP *novo = (NOSKIP*) malloc(sizeof(NOSKIP));
      if(novo ==NULL){exit(1);}
     // printf(" nivel atual %d \n",nivel);
      novo->item=item_criar(inserir,defini);
      novo->prox_dir=no->prox_dir;
      novo->prox_baixo=NULL;
      no->prox_dir=novo;
      if(random_fn()){
       // printf("Promoting node with key %d to level %d\n", inserir, nivel);
        return novo;
      }
       // printf("Not promoting node with key %d beyond level %d\n", inserir, nivel);
      return NULL;
    }
    if( no->prox_dir != NULL &&  no->prox_dir->item != NULL && (compara_no_string(no->prox_dir, inserir) > 0) && nivel==1){
      NOSKIP *novo = (NOSKIP*) malloc(sizeof(NOSKIP));
      if(novo ==NULL){exit(1);}
    //  printf(" nivel atual %d \n",nivel);
      novo->item=item_criar(inserir,defini);
      novo->prox_dir=no->prox_dir;
      novo->prox_baixo=NULL;
      no->prox_dir=novo;
      if(random_fn()){
     //   printf("Promoting node with key %d to level %d\n", inserir, nivel);
        return novo;
      }
       // printf("Not promoting node with key %d beyond level %d\n", inserir, nivel);
      return NULL;
    }

    NOSKIP *ins=NULL;
    int direction=-1;
    if(no->prox_dir==NULL){
      if(no->prox_baixo != NULL) {
        ins = insercao(inserir,defini , nivel-1, no->prox_baixo);
    }
      direction=0;
    }else if( no->prox_dir != NULL &&  no->prox_dir->item != NULL &&  (compara_no_string(no->prox_dir, inserir) > 0)){
      if(no->prox_baixo != NULL) {
        ins = insercao(inserir,defini ,nivel-1, no->prox_baixo);
    }
      direction=0;
    }else if((compara_no_string(no->prox_dir,inserir) < 0)){
        ins=insercao(inserir,defini ,nivel, no->prox_dir);
        direction=1;
    }

    if(direction==0 && ins!=NULL){
      NOSKIP *novo = (NOSKIP*) malloc(sizeof(NOSKIP));
     // printf(" nivel atual %d \n",nivel);
      novo->item=ins->item;
      novo->prox_dir=no->prox_dir;
      novo->prox_baixo=ins;
      no->prox_dir=novo;
      if(random_fn()){
        return novo;
      }
      return NULL;  
    }else if(direction==1 && ins!=NULL){
      return ins;
    }
    return NULL;
}*/
void printar_nivel(NOSKIP* no) {
    NOSKIP* N1 = no;
    while (N1 != NULL) {
       
        if(N1->item != NULL) {
            printf("%s  %s ", item_get_chave(N1->item), item_get_defi(N1->item));
        } else {
            printf("HEADER "); 
        }
        N1 = N1->prox_dir;
    }
    printf("\n"); 
}




  /*srand((unsigned int)time(NULL));
     char str1[50]= "elcool";
     char def1[50] = "mel";
     char str2[50] = "eugenio";
     char def2[50] ="o maior de todos";
     char str3[50] = "emania";
     char str4[50]= "gggg";
     char def3[50] =" Supper";
     char newdef[50]= "kkkkkkkk";
    NOSKP* L1 = cria_skip_list();
    insercao(str2,def2,NIVEIS,L1);
    insercao(str3,def3,NIVEIS,L1);
    insercao(str1,def1,NIVEIS,L1);
    busca(str2,NIVEIS, L1);
    imprime_todas_palavras('h', L1);*/


    /*  while(1){
          if (fgets(linha, TAM_MAX_LIN, stdin) == NULL ) {
            break;
        }
         printf("Read line: %s\n", linha);
         comando = strtok(linha," \t\n");
         printf("Comando: %s\n", comando);

       
if (strcmp(comando, "insercao") == 0) {
    palavra = strtok(NULL," ");
    defini = linha + strlen(comando) + strlen(palavra) + 2;
    printf("Calling insercao with %s and %s\n", palavra, defini);
    insercao(palavra, defini, NIVEIS, LISTA);
} else if (strcmp(comando, "remocao") == 0) {
    palavra = strtok(NULL," ");
    printf("Calling remo with %s and \n", palavra);
    remove_lista_skip(palavra, NIVEIS, LISTA);  
 
} else if (strcmp(comando, "busca") == 0) {
    palavra = strtok(NULL," ");
     printf("Calling busca with %s and \n", palavra);
    busca(palavra, NIVEIS, LISTA);
   
} else if (strcmp(comando, "alteracao") == 0) {
    palavra = strtok(NULL," ");
    defini = linha + strlen(comando) + strlen(palavra) + 2;
    printf("Calling muda def with %s and %s \n", palavra, defini);
    muda_def(palavra, defini, NIVEIS, LISTA);
   
} else if (strcmp(comando, "impressao") == 0) {
    sscanf(linha, "%*s %c", &caractere);
    printf("Calling impre with %c and \n", caractere);
    imprime_todas_palavras(caractere, LISTA);
} else {
    printf("comando errado \n");
}

    }
   */


int main(){
     srand((unsigned int)time(NULL));
     char str1[50]= "elcool";
     char def1[50] = "mel";
     char str2[50] = "eugenio";
     char def2[50] ="o maior de todos";
     char str3[50] = "emania";
     char str4[50]= "gggg";
     char def3[50] =" Supper";
     char newdef[50]= "kkkkkkkk";

     lista_skip* L1 = cria_skip_list();
     int val = 0;
     NOSKIP* NO1 = L1->niveis;
    

    insercao(str2,def2,NIVEIS,L1->niveis);
    insercao(str3,def3,NIVEIS,L1->niveis);
    insercao(str1,def1,NIVEIS,L1->niveis);
    busca(str2,NIVEIS, L1->niveis);

    imprime_todas_palavras('h', L1->niveis);
    printf("\n\n");
    do {
       
         printar_nivel(NO1);
         NO1 = NO1->prox_baixo; 

     } while (NO1 != NULL);


    printf("\n\n\n");


     remove_lista_skip(str4,NIVEIS,L1->niveis);
     muda_def(str2,newdef,NIVEIS,L1->niveis);
     NOSKIP* NO2 = L1->niveis;
     do {
         printar_nivel(NO2);
         NO2 = NO2->prox_baixo; 
     } while (NO2 != NULL);

 

}