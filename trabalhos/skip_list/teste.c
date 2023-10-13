
#include "skip_list_string.h"







int main(){
srand((unsigned int)time(NULL));
     char str1[50]= "cliche";
     char def1[50] = "acao ou fala previsivel devido ao uso excessivo";
     char str2[50] = "cessionhhh";
     char def2[50] ="pessoa beneficiada com a cessao";
     char str3[50] = "emania";
     char str4[50]= "gggg";
     char def3[50] =" Supper";
     char newdef[50]= "kkkkkkkk";
    NOSKP* L1 = cria_skip_list();

  //  insercao(str2,def2,NIVEIS,L1);
    //insercao(str3,def3,NIVEIS,L1);
    insercao(str1,def1,NIVEIS,L1);
     imprime_todas_palavras('c', L1);
    insercao(str2,def2,NIVEIS,L1);
    imprime_todas_palavras('c', L1);




}