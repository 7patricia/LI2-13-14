#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "hash_table.h"

int Hash_hash(void*key,int size){
    char *palavra = (char*)key;
    int x,sum;
    for(x=0; palavra[x] != '\0'; x++) {
        sum = sum*2 + palavra[x];
    }
     
    return sum % size;
}

int Hash_compare_keys(char *key1,char *key2) {

    return strcmp(key1, key2) == 0;
}

HashTable Hash_Create(int maxCount) {
    HashTable hs = (HashTable) malloc(sizeof (struct hash_table));
    int x;

    hs->useCount = 0;
    hs->totalCount = maxCount;
    hs->table = (HashElem *) malloc(sizeof (HashElem) * maxCount);


    for (x = 0; x < maxCount; x++) {
        hs->table[x] = NULL;
    }

    return hs;
}

int Hash_IsFull(HashTable hashT) {
    return (((float) hashT->useCount / (float) hashT->totalCount) > 0.8);
}

int Hash_Expand(HashTable hashT) {
    int oldCount = hashT->totalCount;
    int newCount = hashT->totalCount * 2;
    
    int x;
    HashElem *oldTable = hashT->table;
    HashElem aux, aux2;
    hashT->table = (HashElem *) malloc(sizeof (HashElem) * newCount);
    hashT->totalCount = newCount;
    hashT->useCount = 0;

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

    hashT->totalCount = newCount;

    return 0;
}

int Hash_Insert(HashTable hashT, char *data) {
    int hash = Hash_hash(data, hashT->totalCount);

    hashT->useCount += Elem_Insert(hashT, &(hashT->table[hash]), data);
    
    return 0;
}

char *Hash_Search(HashTable hashT, char *key) {
    int hash = Hash_hash(key, hashT->totalCount);
    HashElem aux = hashT->table[hash];
    while (aux != NULL) {
        if (Hash_compare_keys(aux->data, key))
            return aux->data;
        aux = aux->next;
    }

    return NULL;
}

int Elem_Insert(HashTable hashT, HashElem *elem, char *data) {
    int returnVal = 0;

    while ((*elem != NULL) && !Hash_compare_keys((*elem)->data, data)) {
        elem = &((*elem)->next);
    }

    if (*elem == NULL) {
        *elem = (HashElem) malloc(sizeof (struct hash_elem));
        (*elem)->next = NULL;
        returnVal = 1;
    }
    (*elem)->data = data;

    return returnVal;
}
