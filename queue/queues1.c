
#include "queues1.h"

QUEUE* queue_create(void){
       QUEUE* new_q = (QUEUE*) malloc(sizeof(QUEUE));
              if(new_q==NULL){exit(1);}
       new_q->start = 0;
       new_q->end = 0;
       new_q->total = 0;
       return new_q;
}

void queue_free(QUEUE** QUE){
     free(*QUE);
     *QUE= NULL;
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

Q_type queue_first(QUEUE* QUE){
    if (queue_empty(QUE)){
         printf(" empty queue, nothing here \n");
         exit(1);
    }
   return  (QUE->list[QUE->start]);
}

bool queue_push(Q_type item, QUEUE* QUE){
     if(queue_full(QUE)){
        printf("queue is full \n");
        return false;
     } 
      QUE->list[QUE->end] = item;
      QUE->end++;
      QUE->end  = (QUE->end % N);
      //printf("new end: %d", QUE->end);
      QUE->total++;
      
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

bool queue_clean(QUEUE* QUE){
  for (int i = 0; i < N; i++){
      QUE->list[i] = 0;
  }
  QUE->total =0;
  QUE->end = 0;
  QUE->start =0;
  return true;
}

bool queue_copy(QUEUE* QUE, QUEUE*QUE2){
     if (queue_empty(QUE) && queue_empty(QUE2)){
      printf("both queues are empty");
      return false;}
     
     
      
   
    QUE->start = 0;
    QUE->end = QUE2->end; 
    QUE->total = QUE2->total; 

      for (int i = 0; i < N; i++){
         QUE->list[i] = QUE2->list[i];
      }
    

  /* if (QUE->end >= QUE->start) {
       
        for (int i = QUE2->start; i <= QUE2->end; ++i) {
            QUE->list[i] = QUE2->list[i];
        }
    } else {
        for (int i = 0; i <= QUE2->end; ++i) {
            QUE->list[i] = QUE2->list[i];
        }
        for (int i = QUE2->start; i < N; ++i) {
            QUE->list[i] = QUE2->list[i];
        }
    } */ 
    
    return true;
}


/*int main(){

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

}*/
