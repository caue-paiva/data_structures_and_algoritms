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