#include <stdio.h>
#include <stdlib.h>


struct _node {

    int data;
    struct _node* next;
    struct _node* prev;
};

struct _linked_list {

    struct _node* Head;
    struct _node* Tail;
};

typedef struct _node Node;
typedef struct _linked_list LinkedList;

LinkedList* makeLinkedList()
{
    LinkedList* newList;
    if ((newList = (LinkedList*)malloc(sizeof(LinkedList))) == NULL) {
	return NULL;
    }

    newList->Head = NULL;
    newList->Tail = NULL;

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

void addNode(LinkedList* list, Node* node)
{

    if (node == NULL || list == NULL) {
	return;
    }

    if (list->Head == NULL) {
	list->Head = node;
	list->Tail = node;
    }
    else {
	list->Tail->next = node;
	node->prev = list->Tail;
	list->Tail = node;
    }
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
    }
    
    free(tempNode->next);
    free(list);
}

int main()
{
    LinkedList* list = makeLinkedList();
    Node* node1 = makeNode(1);
    Node* node2 = makeNode(2);
    Node* node3 = makeNode(3);

    addNode(list, node1);
    addNode(list, node2);
    addNode(list, node3);
    printNode(list);

    deleteList(list);
    return 0;
}
