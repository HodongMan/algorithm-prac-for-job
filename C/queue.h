#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "linked_list.h"

#define TRUE 1
#define FALSE 0

typedef struct _queue Queue;

struct _queue {

    Node* Head;
    Node* Tail;
    int count;
};

Queue* makeQueue();
void enqueue(Queue* queue, int value);
int dequeue(Queue* queue);
int peek(Queue* queue);
int isEmpty(Queue* queue);

void freeQueue(Queue* queue);

#endif
