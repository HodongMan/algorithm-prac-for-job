#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

Queue* makeQueue()
{
    Queue* newQueue;
    if ((newQueue = (Queue*)malloc(sizeof(Queue))) == NULL)
	return NULL;

    newQueue->Head = NULL;
    newQueue->Tail = NULL;
    newQueue->count = 0;

    return newQueue;
}

void enqueue(Queue* queue, int value)
{
    Node* newNode = makeNode(value);

    if (isEmpty(queue)) {
	queue->Head = newNode;
	queue->Tail = newNode;
    }
    else {
	queue->Tail->next = newNode;
	queue->Tail = newNode;
    }
    queue->count += 1;
}

int dequeue(Queue* queue)
{
    int delValue;
    Node* delNode;

    if (isEmpty(queue)) 
	return FALSE;

    delNode = queue->Head;
    queue->Head = delNode->next;
    delValue = delNode->data;

    free(delNode);
    queue->count -= 1;

    return delValue;
}

int seek(Queue* queue)
{
    return queue->Head->data;
}

int isEmpty(Queue* queue)
{
    return queue->count == 0;
}

void freeQueue(Queue* queue)
{
    Node* curNode = queue->Head;
    Node* nextNode = queue->Head->next;

    while (curNode != NULL || nextNode != NULL) {
	printf("메모리 해제\n");
	free(curNode);
	curNode = nextNode;
	nextNode = nextNode->next;
    }

    free(queue);
}



/*
int main()
{
    Queue* queue = makeQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));

    return 0;
}

*/
