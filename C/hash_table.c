
#include <stdio.h>
#include <stdlib.h>

struct _node {

    char* key;
    char* value;
    struct * _node next;
};

struct _hash_table {
    int size;
    struct _node** table;
};

typedef struct _node Node;
typedef struct _hash_table HashTable;

HashTable* CreateHashTable(int size) {

    HashTable* hash_table = NULL;
    int i;

    if (size < 1)
	return NULL;

    if ((hash_table = (HashTable*)malloc(sizeof(HashTable))) == NULL) {
	return NULL;
    }

    if ((hash_table->table = (Node**)malloc(sizeof((Node*) * size))) == NULL) {
	return NULL;
    }

    for (i = 0; i < size; i++)
	hash_table->table[i] = NULL;

    return hash_table;
}
