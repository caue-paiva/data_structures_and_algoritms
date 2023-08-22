#include "stdlib.h"
#include "stdio.h"
#include "stdarg.h"
#include "string.h"

int count_digits(int n){
  int count=0;

  while ( n != 0){
    n /= 10;
    count++;
  }

  return count;
}

char * int_to_string( unsigned int n, int digi){
    
    char * int_str = (char*) malloc (sizeof(char)* digi+1);
     if (int_str == NULL)
            exit(1);

    int_str[digi] = '\0';
   
    for (int i = digi-1; i >= 0; i--)
    { 
      int temp = n % 10;
      int_str[i] = temp + '0';
     // printf( "  new char %c", int_str[i]);
       n /= 10;
    }

    return int_str;   
}

void new_print(char*str,...){
   
    va_list args;
     va_start(args, str);
      unsigned int param;

    for (int i = 0; i < strlen(str); i++) {
        if(i!=strlen(str)-1 && str[i]=='%'){
            if(str[i+1]=='u'){
                param = va_arg(args, unsigned int);

                int digits = count_digits(param);

                char * int_str = int_to_string(param, digits);
                
                for (int i = 0; i < digits; i++){
                    putc( int_str[i], stdout);
                 } 
                 i++; 
            }else {putc( str[i], stdout);}
        
         }else{putc( str[i], stdout);}
    
  va_end(args);
}
}


int main(){

char str[]= "teste %u hyuagdsyu  % %u %u  %u  %u bla\n";

new_print("teste %u hyuagdsyu  % %u %u  %u  %u bla\n", 1556251, 1626 , 1726, 125, 1000);

}