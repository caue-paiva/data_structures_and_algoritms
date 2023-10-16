#include "queues1.h"




int main(){

int temp;
char tempc;
QUEUE* Q1 = queue_create();
queue_push(2,Q1);
queue_push(3,Q1);

queue_print(&Q1);
queue_stats(Q1);



}