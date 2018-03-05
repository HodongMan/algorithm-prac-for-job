#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

Stack* makeStack()
{
    Stack* newStack;
    if ((newStack = (Stack*)malloc(sizeof(Stack))) == NULL)
	return NULL;

    newStack->Tail = NULL;
    newStack->count = 0;

    return newStack;
}

void push(Stack* stack, int data)
{
    Node* newNode = makeNode(data);
    
    if (!isEmpty(stack)) {
	stack->Tail->next = newNode;
	newNode->prev = stack->Tail;
    }
    stack->Tail = newNode;
    stack->count += 1;

    newNode = NULL;
}

int pop(Stack* stack)
{
    Node* delNode = stack->Tail;
    int delData = stack->Tail->data;

    if (isEmpty(stack))
	return FALSE;

    stack->Tail = stack->Tail->prev;
    stack->count -= 1;

    free(delNode);
    return delData;
}

static int isEmpty(Stack* stack)
{
    return stack->count == 0;
}


/*
int main()
{
    Stack* stack = makeStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));

    return 0;
}
*/
