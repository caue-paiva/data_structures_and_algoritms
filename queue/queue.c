#define QUEUE_SIZE 50
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct{
    int start;
    int end;
    Q_elem arr[QUEUE_SIZE];
    int total;
} queue;

typedef int Q_elem;

void free_queue(queue** que){
     free(&que);
}

queue* create_queue(){
       queue* new_q = (queue*) malloc(sizeof(queue));
              if(new_q==NULL){exit(1);}
        new_q->total = 0;
        new_q->start = 0;
        new_q->end = 0;
        return new_q;
}

bool empty_queue(queue* que){
      assert(que != NULL);
      if (que->total==0){
        return true;
      }
      return false;
}

Q_elem pop_queue(queue* que){
       assert(que != NULL);
       if(empty_queue(que)){
        printf("empty queue, cant pop elements \n");
        return NULL;
       }
       Q_elem item = que->arr[que->start];
       (que->start) = ((que->start)++) % QUEUE_SIZE;
       (que->total)--;
       
       return item;
}

int size_queue(queue* que){
    if (que==NULL){exit(1);}
    return que->total;
}

void push_queue(queue* que, Q_elem item){
       assert(que != NULL);
       if(full_queue(que)){
        printf("full queue, cant add more elements \n");
        return ;
       }

        que->arr[que->end] = item;
       (que->end) = ((que->end)++)%QUEUE_SIZE;
       (que->total)++;

}

bool full_queue(queue* que){
    assert(que != NULL);
    if(que->total== QUEUE_SIZE){
        return true;
    }
    return false;
}