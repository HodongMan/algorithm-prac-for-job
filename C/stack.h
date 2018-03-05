#ifndef _STACK_H_
#define _STACL_H_

#include "linked_list.h"

#define TRUE 1
#define FALSE 0


struct _stack {

    struct _node* Tail;
    int count;
};

typedef struct _stack Stack;


Stack* makeStack();

void push(Stack* stack, int data);
int pop(Stack* stack);
static int isEmpty(Stack* stack);


#endif
