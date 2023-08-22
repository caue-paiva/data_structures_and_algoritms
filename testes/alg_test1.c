#include "stdlib.h"
#include "stdio.h"
#include "string.h"
int string_equality(char* str1, char* str2);
int sub_str_position(char* str_base, char* sub_str);


int main(){
char string[] = "para_teste_safadeza_para_";
char substr[]= "safadeza";
int result = sub_str_position(string, substr);
printf("%d", result);

}


int sub_str_position(char* str_base, char* sub_str){

int len_sub = strlen(sub_str);
int len_str = strlen(str_base);
char* temp_sub_str;

temp_sub_str = (char*) malloc(sizeof(char)* len_sub);
if (temp_sub_str== NULL){
    printf("failed alloc");
    exit(1);
}
//printf("len sub: %d", len_sub);

for (int i =0 ; i < len_str - len_sub;i++){
     int k =0;
     for (int j=i; j < len_sub+i;j++){
        
        temp_sub_str[k] = str_base[j];
       // printf("k: %d \n", k);
        //printf("j: %d \n", j);
        k++;
     }
     int result = string_equality(temp_sub_str, sub_str);
     if (result==1){
     return i;

     }
}

return -1;


}


int string_equality(char* str1, char* str2){
int len = strlen(str1);

for (int i = 0; i < len; i++)
{ if (str1[i] != str2[i]){
    return 0;
}
    
}

return 1;



}