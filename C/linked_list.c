#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

LinkedList* makeLinkedList()
{
    LinkedList* newList;
    if ((newList = (LinkedList*)malloc(sizeof(LinkedList))) == NULL) {
	return NULL;
    }

    newList->Head = NULL;
    newList->Tail = NULL;
    newList->count = 0;

    return newList;
}

Node* makeNode(int value)
{
    Node* newNode;
    if ((newNode = (Node*)malloc(sizeof(Node))) == NULL) {
	return NULL;
    }

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void addNode(LinkedList* list, int data)
{
    Node* node = makeNode(data);

    if (node == NULL || list == NULL) {
	return;
    }

    if (list->Head == NULL) {
	list->Head = node;
    }
    else {
	list->Tail->next = node;
	node->prev = list->Tail;
    }
    list->Tail = node;
    list->count += 1;
    
    node = NULL;
}

void deleteNode(LinkedList* list, int data)
{
    Node* temp = list->Head;

    if (list->count == 0)
	return;

    while (temp->data != data && temp != NULL) {
	temp = temp->next;
    }

    if (temp == NULL)
	return;
    else if (list->count == 1) {
	list->Head = NULL;
	list->Tail = NULL;
    }
    else if (temp == list->Tail) {
	list->Tail->prev->next = NULL;
	list->Tail = list->Tail->prev;
    }
    else {
	if (temp == list->Head) {
	    list->Head = temp->next;
	    temp->next->prev = NULL;
	} else {
	    temp->prev->next = temp->next;
	    temp->next->prev = temp->prev;
	}
    }

    free(temp);
    temp = NULL;
    list->count -= 1;
}



void printNode(LinkedList* list)
{
    Node* tempNode = list->Head;
    
    while(tempNode) {
	printf("%d\n", tempNode->data);
	tempNode = tempNode->next;	
    }
}

void deleteList(LinkedList* list)
{
    Node* tempNode = list->Head;

    while(tempNode != list->Tail){
	tempNode = tempNode->next;
	free(tempNode->prev);
	tempNode->prev = NULL;
    }
    
    free(tempNode->next);
    tempNode->next = NULL;
    free(list);
    list = NULL;
}

int main()
{
    LinkedList* list = makeLinkedList();

    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);
    addNode(list, 4);
    deleteNode(list, 4);
    deleteNode(list, 1);
    printNode(list);

    deleteList(list);
    return 0;
}
