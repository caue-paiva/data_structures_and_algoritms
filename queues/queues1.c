#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#define N 20

typedef int Q_type; 

typedef struct {
   int start;
   int end;
   int total;
   Q_type list[N];
} QUEUE;


QUEUE* queue_create(void){
       QUEUE* new_q = (QUEUE*) malloc(sizeof(QUEUE));
              if(new_q==NULL){exit(1);}
       new_q->start = 0;
       new_q->end = 0;
       new_q->total = 0;
       return new_q;
}


bool queue_empty(QUEUE*QUE){
   if (QUE->total == 0){
      return true;
   }else {return false;}
}

bool queue_full(QUEUE*QUE){
   if (QUE->total==N){
      return true;
   }else{ return false; }
}

Q_type queue_pop(QUEUE*QUE){
       if (queue_empty(QUE)){
         printf(" empty queue, cant pop \n");
        exit(1);
       }else {
         Q_type retu = QUE->list[QUE->start];
         (QUE->start)++;
         (QUE->start) = (QUE->start % N);
         (QUE->total) -- ;
         return retu;
       }
}

Q_type queue_top(QUEUE* QUE){
    if (queue_empty(QUE)){
         printf(" empty queue, nothing here \n");
         exit(1);
    }
   return  (QUE->list[QUE->start]);
}

bool queue_push(Q_type item, QUEUE* QUE){
     bool increase_size = true;  //flag to decide wether to increase size , as we wont be increasing size beyond the max capacity of the circular queue
     if(queue_full(QUE)){
        printf(" queue is full, elements added will overwrite previous elements \n");
        increase_size = false;
     } 
      QUE->list[QUE->end] = item;
      QUE->end++;
      QUE->end  = (QUE->end % N);
      printf("new end: %d", QUE->end);
      if(increase_size){QUE->total++;}
      
      return true;
}

void queue_stats(QUEUE* QUE){
   printf("|Queue start %d \n Queue end %d \n Queue total %d \n Queue cur element %d |\n", QUE->start, QUE->end, QUE->total, QUE->list[QUE->start]);
}

void queue_graphic(QUEUE*QUE){
   printf("(");
   for (int i = 0; i < N; i++)
   {
      if( i >= QUE->start && i <= (QUE->end -1)){
         printf("*");
      }else {printf(" ");}
   }
   printf(")\n");
}

int main(){

int plate;
char action;
QUEUE* pQUE = queue_create();

scanf("%c", &action);

while(action != 'K' ){
  
  if (action == 'A'){
   printf("choose the plate\n");
   scanf("%d",&plate);
   printf(" PLATE: %d \n", plate);
   queue_push(plate, pQUE);
   printf("car arriving \n");
   queue_stats(pQUE);
  }

  if (action == 'D'){
   printf("%d", plate);
   int popped = queue_pop(pQUE);
   printf("item popped: %d \n", popped);
   queue_stats(pQUE);
   }
scanf("%c",&action);

}

queue_graphic(pQUE);

}
