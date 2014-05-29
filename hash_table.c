#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "hash_table.h"

int Hash_hash(char*palavra,int size){
    int x;
    long int sum;
    for(x=0; palavra[x] != '\0'; x++) {
        sum = sum*2 + palavra[x];
    }

    return (int) sum % size;
}

int Hash_compare_keys(char *key1,char *key2) {
    return strcmp(key1, key2) == 0;
}

HashTable Hash_Create(int maxCount) {
    HashTable hs = (HashTable) malloc(sizeof (struct hash_table));
    int x;

    hs->size = 0;
    hs->array_size = maxCount;
    hs->table = (HashElem *) malloc(sizeof (HashElem) * maxCount);


    for (x = 0; x < maxCount; x++) {
        hs->table[x] = NULL;
    }

    return hs;
}

int Hash_IsFull(HashTable hashT) {
    return (((float) hashT->size / (float) hashT->array_size) > 0.8);
}

int Hash_Expand(HashTable hashT) {
    int oldCount = hashT->array_size;
    int newCount = hashT->array_size * 2;
    
    int x;
    HashElem *oldTable = hashT->table;
    HashElem aux, aux2;
    hashT->table = (HashElem *) malloc(sizeof (HashElem) * newCount);
    hashT->array_size = newCount;
    hashT->size = 0;

    for (x = 0; x < newCount; x++) {
        hashT->table[x] = NULL;
    }

    for (x = 0; x < oldCount; x++) {
        aux = oldTable[x];
        while (aux != NULL) {
            Hash_Insert(hashT, aux->data);
            aux2 = aux;
            aux = aux->next;
            free(aux2);
        }
    }
    free(oldTable);

    hashT->array_size = newCount;

    return 0;
}


void Hash_Insert(HashTable hashT, char *data) {
    int hash = Hash_hash(data, hashT->array_size);
    HashElem* elem = &(hashT->table[hash]);

    while ((*elem != NULL) && !Hash_compare_keys((*elem)->data, data)) {
        elem = &((*elem)->next);
    }

    if (*elem == NULL) {
        *elem = (HashElem) malloc(sizeof (struct hash_elem));
        (*elem)->next = NULL;
        hashT->size += 1;
    }
    (*elem)->data = data;
}

char *Hash_Search(HashTable hashT, char *key) {
    int hash = Hash_hash(key, hashT->array_size);
    HashElem aux = hashT->table[hash];
    while (aux != NULL) {
        if (Hash_compare_keys(aux->data, key))
            return aux->data;
        aux = aux->next;
    }

    return NULL;
}
