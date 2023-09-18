#ifndef FILA_H
   #define FILA_H
#define N 100

#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "item.h"

typedef int return_type;

typedef struct {
   int start;
   int end;
   int total;
   ITEM* list[N];
} QUEUE;



QUEUE* queue_create(void);
void queue_free(QUEUE** QUE);
bool queue_empty(QUEUE*QUE);
bool queue_full(QUEUE*QUE);
ITEM* queue_pop(QUEUE*QUE);
ITEM*  queue_first(QUEUE* QUE);
bool queue_push(ITEM* item, QUEUE* QUE);
//void queue_stats(QUEUE* QUE);
//void queue_graphic(QUEUE*QUE);
bool queue_clean(QUEUE* QUE);
bool queue_copy(QUEUE* QUE, QUEUE*QUE2);
int queue_size(QUEUE* QUE);

#endif