#ifndef QUEUES1_H
   #define QUEUES1_H
#define N 10
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"

typedef int Q_type; 

typedef struct {
   int start;
   int end;
   int total;
   Q_type list[N];
} QUEUE;



QUEUE* queue_create(void);
void queue_free(QUEUE** QUE);
bool queue_empty(QUEUE*QUE);
bool queue_full(QUEUE*QUE);
Q_type queue_pop(QUEUE*QUE);
Q_type queue_first(QUEUE* QUE);
bool queue_push(Q_type item, QUEUE* QUE);
void queue_stats(QUEUE* QUE);
void queue_graphic(QUEUE*QUE);
bool queue_clean(QUEUE* QUE);
bool queue_copy(QUEUE* QUE, QUEUE*QUE2);
QUEUE* stack_create();
bool stack_push(QUEUE*QUE, Q_type item);
Q_type stack_top(QUEUE* QUE);
Q_type stack_pop(QUEUE*QUE);
bool stack_empty(QUEUE*QUE);

#endif