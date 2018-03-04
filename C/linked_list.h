#ifndef _LINKED_LIST_H_
#define _LINKED_LSIT_H_

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

LinkedList* makeLinkedList();
Node* makeNode(int value);
void addNode(LinkedList* list, Node* node);
void printNode(LinkedList* list);
void deleteList(LinkedList* list);

#endif
