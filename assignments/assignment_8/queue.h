#include <stdio.h>
#include <stdlib.h>
#include "item.h" 

typedef struct c_queue *queue;

// prototipi

queue newQueue(void);

int emptyQueue(queue q);

item dequeue(queue q);

int enqueue(item val, queue q);

queue cloneQueue(queue q);
void print_queue(queue q);
int dimQueue(queue q);
queue catQueue(queue q1, queue q2);