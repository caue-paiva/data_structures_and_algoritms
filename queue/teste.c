#include "queues1.h"




int main(){

int temp;
char tempc;
QUEUE* Q1 = queue_create();

for (int i = 0; i < 1000; i++)
{
   scanf("%c",&tempc);
   scanf("%d", &temp);
   printf("%c %d", tempc,temp);
   if(tempc == 'a'){
         queue_push(temp,Q1);
   } else if (tempc == 'r'){
      queue_pop(Q1);
   }

   queue_graphic(Q1);
}







}