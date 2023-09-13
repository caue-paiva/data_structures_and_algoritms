#include "stdio.h"
#include "stdlib.h"

void merge1(int V1[], int N1, int V2[], int N2, int V3[], int final1, int final2){
    int flag1=0, flag2=0;
    
    if (N1 == final1&& N2 ==final2){   
        return;    
    }
    
  
    if(N1== final1){flag1=1;}
    if(N2==final2){flag2=1;}
    
    if(flag1){
        V3[N1-1+N2] = V2[N2];
           printf("N2 %d\n", N2);
        N2++;
        
        merge1(V1,N1,V2,N2,V3, final1,final2);
       
       
        return;
     }else if(flag2){
       V3[N1+N2-1] = V1[N1];
       N1++;
         
       merge1(V1,N1, V2,N2,V3, final1,final2);
      
       return;
    }

    if (V1[N1] < V2[N2]){
       V3[N1+N2] = V1[N1];
        printf("N1 %d\n", N1);
       N1++;
      
       merge1(V1,N1, V2,N2,V3, final1,final2);
       
    
    } else{
      V3[N1+N2] = V2[N2];
      N2++;
      merge1(V1,N1,V2,N2,V3, final1,final2);
    }


}


int main(){

int arr1[] = {1,2,3,4};
int arr2[] = {5,6,7};
int arr3[20];

merge1(arr1,0,arr2,0, arr3,4,3);

for (int i = 0; i < 7; i++)
{
    printf("%d \n", arr3[i]);
}







}