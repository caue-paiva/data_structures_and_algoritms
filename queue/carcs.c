#include "queues1.h"

void shift_cars(QUEUE* QUE){
   if (QUE->start == 0){return;}
   int Posi_to_shift = QUE->start;
   int end = QUE->end;

   for (int i = Posi_to_shift; i <= end; i++){
      QUE->list[i-Posi_to_shift]= QUE->list[i];
   }

   QUE->end = end - Posi_to_shift;
   QUE->start = 0;
}


int main(){

char action;
Q_type plate;
QUEUE* main_que =  queue_create();
QUEUE* aux_que = queue_create();

scanf("%c %d", &action, &plate);

while (action != 'K'){
   //   if(queue_empty(pQUE)){
   //    QUEUE* main_que = pQUE;
   //    QUEUE* aux_que = pQUE2;
   //   } else{
   //     QUEUE* main_que = pQUE2;
   //     QUEUE* aux_que = pQUE;
   //   }
     
     if(action == 'A'){
      if (main_que->start != 0){
         printf("start is %d \n", main_que->start);
         shift_cars(main_que);
      }
      
      queue_push(plate,main_que);
      printf("pushed item %d to queue\n", plate);
      queue_graphic(main_que);
     }
  
     if(action=='D'){
      printf("before departure: ");
      queue_graphic(main_que);
      queue_stats(main_que);
      printf("\n");
      int len = main_que->total;
      for(int i = 0; i < len; i++ ){
          Q_type car_leaving = queue_pop(main_que);
          //printf("car leaving %d \n", car_leaving);
          if(car_leaving == plate){ 
            printf("car leaving has plate %d \n", plate);
            continue;}
          queue_push(car_leaving, aux_que);
      }

      queue_copy(main_que, aux_que);
      //printf("after departure: ");
      //queue_graphic(aux_que);
      queue_clean(aux_que);
      printf("after departure: ");
      queue_graphic(main_que);
      queue_stats(main_que);
      printf("\n");
     }
  // queue_graphic(main_que);
   scanf("%c %d", &action, &plate);
}



}