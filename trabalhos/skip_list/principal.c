#include "skip_list_string.h"
#define TAM_MAX_LIN 300


  /* FEITO POR
  Caue Paiva Lira. NUSP: 14675416
  Thales Sena de Queiroz. NUSP: 14608873
*/

char* remove_espaco(const char* str) {  /*essa função remove espaco e formata strings dos comandos para ser enviadas como argumentos para funções, 
não faz parte do TAD skiplist, apenas do input do problema */
      int tam = strlen(str);
    
      char* novo = (char*) malloc(tam + 1); 
      if (novo ==NULL) {
          return NULL; 
      }
      const char* antiga = str; 
      char* str_retorno = novo;  
      while (*antiga) {
          if (*antiga != ' ' && *antiga != '\t' && *antiga != '\n' && *antiga != '\r') {
               *str_retorno++ = *antiga; 
          }     antiga++; 
      }
      *str_retorno = '\0';  
      return novo;
}


int main(){
   srand((unsigned int)time(NULL)); //seeda o random
   char linha[TAM_MAX_LIN];
   char *comando;
   char *palavra;
   char *defini;
   char caractere;
   char* strbackup = (char*) malloc(sizeof(char)*TAM_MAX_LIN); //uma string backup é necessaria pq o strtok faz mudanças inplace da string original
         if(strbackup ==NULL){exit(1);}
      
   NOSKP* LISTA = cria_skip_list(); //cria a lista


   while(1){ //loop de ler os comandos
         
      if (fgets(linha, TAM_MAX_LIN, stdin) == NULL ) { //lé a linha, coloca numa variável e le até achar um EOF
            break;
      }
      strcpy(strbackup,linha); //copia a linha no backup
      comando = strtok(linha," \t\n");  //pega a primeira palavra (comando) até achar um whitespace

       
     if (strcmp(comando, "insercao") == 0) { //strcmp para ver qual o comando a ser executado
         palavra = strtok(NULL," "); //pega a segunda palavra (palavra) até achar um whitespace
         defini = strtok(NULL, "\n"); //pega o resto da string até chegar num \n (definicao)
         char* nova_defini = (char*) malloc(strlen(defini) + 1);  /*é necessario criar novas cópias das strings para que a inserção de uma palavra/defini não muda a outra 
         (oq seria o caso se elas fossem representadas pela msm string)*/
         if(nova_defini == NULL){exit(1);}
         strcpy(nova_defini, defini);
         char* nova_palavra = remove_espaco(palavra);
         if (nova_palavra ==NULL){exit(1);}
         insercao(nova_palavra, nova_defini, NIVEIS, LISTA);

      } else if (strcmp(comando, "remocao") == 0) {
         palavra = strtok(NULL," ");
         char* nova_palavra = remove_espaco(palavra);
         if (nova_palavra ==NULL){exit(1);}
         remove_lista_skip(nova_palavra, NIVEIS, LISTA); 

      } else if (strcmp(comando, "busca") == 0) {
         palavra = strtok(NULL," ");
         char* nova_palavra = remove_espaco(palavra);
         if (nova_palavra ==NULL){exit(1);}
         busca(nova_palavra, NIVEIS, LISTA);

      } else if (strcmp(comando, "alteracao") == 0) {
         palavra = strtok(NULL," ");
         defini = strtok(NULL, "\n");
         char* nova_defini = (char*) malloc(strlen(defini) + 1);
         if(nova_defini == NULL){exit(1);}
         strcpy(nova_defini, defini);
         char* nova_palavra = remove_espaco(palavra);
         if (nova_palavra ==NULL){exit(1);}
         muda_def(nova_palavra, nova_defini, NIVEIS, LISTA);

      } else if (strcmp(comando, "impressao") == 0) {
         caractere = strbackup[10];  //pega o 10 char da string quando o comando impressão é dado, que é a letra que é para pesquisar
         imprime_todas_palavras(caractere, LISTA);
      } else {
         printf("comando errado \n");
      }


   }
   apaga_skip_lista(&LISTA);
} 
   
