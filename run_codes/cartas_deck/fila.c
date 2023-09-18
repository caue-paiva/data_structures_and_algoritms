
#include "fila.h"
#include "item.h"

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

int queue_size(QUEUE* QUE){
    return QUE->total;
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

ITEM* queue_pop(QUEUE*QUE){
       if (queue_empty(QUE)){
         printf(" empty queue, cant pop \n");
        exit(1);
       }else {
         
         ITEM* retu = QUE->list[QUE->start];
         (QUE->start)++;
         (QUE->start) = (QUE->start % N);
         (QUE->total) -- ;
         return retu;
       }
}

ITEM* queue_first(QUEUE* QUE){
    if (queue_empty(QUE)){
         printf(" empty queue, nothing here \n");
         exit(1);
    }
   return  QUE->list[QUE->start];
}

bool queue_push(ITEM* item, QUEUE* QUE){
     if(queue_full(QUE)){
        printf("queue is full \n");
        return false;
     } 
      QUE->list[QUE->end] = item ;
      QUE->end++;
      QUE->end  = (QUE->end % N);
      //printf("new end: %d", QUE->end);
      QUE->total++;
      
      return true;
}

// void queue_stats(QUEUE* QUE){
//    printf("|Queue start %d \n Queue end %d \n Queue total %d \n Queue cur element %d |\n", QUE->start, QUE->end, QUE->total, QUE->list[QUE->start]);
// }

// void queue_graphic(QUEUE*QUE){
//    printf("(");
//    for (int i = 0; i < N; i++)
//    {
//       if( i >= QUE->start && i <= (QUE->end -1)){
//          printf("*");
//       }else {printf(" ");}
//    }
//    printf(")\n");
// }

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
    
    return true;
}

