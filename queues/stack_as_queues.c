#include "queues1.h"

QUEUE* stack_create(){
      return queue_create();
}

bool stack_push(QUEUE*QUE, Q_type item){
    if(queue_full(QUE)){exit(1);}
    queue_push(item, QUE);
    return true;
}

Q_type stack_top(QUEUE* QUE){
       if(queue_empty(QUE)){  exit(1); }
       return (QUE->list[QUE->end-1]);
}

Q_type stack_pop(QUEUE*QUE){
     if(queue_empty(QUE)){ exit(1); }
     Q_type item = QUE->list[QUE->end-1];
     QUE->end --;
     QUE->end = QUE->end % N;
     return item;
}

bool stack_empty(QUEUE*QUE){
   return queue_empty(QUE);
}



/*int main(){

QUEUE* pStack = stack_create();



stack_push(pStack,5);
stack_push(pStack,7);
stack_push(pStack,7);


queue_stats(pStack);
printf("\n");
queue_graphic(pStack);
printf("\n");

printf("popped new item: %d \n", stack_pop(pStack));
printf("popped new item: %d \n", stack_pop(pStack));
printf("popped new item: %d \n", stack_pop(pStack));

queue_stats(pStack);
queue_graphic(pStack);



}*/