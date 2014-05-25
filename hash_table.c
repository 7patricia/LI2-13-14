#include <stdlib.h>

#include <stdio.h>

#include "hash_table.h"

HashTable Hash_Create(int maxCount, int (*hashFunction)(void *, int), void *(*getKey)(void *), int (*compareKeys)(void *, void *), int duplicate) {
    HashTable hs = (HashTable) malloc(sizeof (struct hash_table));

    hs->useCount = 0;
    hs->totalCount = maxCount;
    hs->hashFunction = hashFunction;
    hs->getKey = getKey;
    hs->compareKeys = compareKeys;
    hs->duplicate = duplicate;
    hs->table = (HashElem *) malloc(sizeof (HashElem) * maxCount);

    int x;
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
            fflush(stdout);
            aux2 = aux;
            aux = aux->next;
            free(aux2);
        }
    }
    free(oldTable);

    hashT->totalCount = newCount;

    return 0;
}

int Hash_Insert(HashTable hashT, void *data) {
    int hash = hashT->hashFunction(hashT->getKey(data), hashT->totalCount);
    
    hashT->useCount += Elem_Insert(hashT, &(hashT->table[hash]), data);
    
    if (Hash_IsFull(hashT)) {
        Hash_Expand(hashT);
    }
    
    return 0;
}

void *Hash_Remove(HashTable hashT, void *key) {
    HashElem *aux = &(hashT->table[hashT->hashFunction(key, hashT->totalCount)]);
    HashElem toFree;
    void *toReturn = NULL;

    while (*aux != NULL && !hashT->compareKeys(key, hashT->getKey((*aux)->data))) {
        aux = &((*aux)->next);
    }

    if (*aux != NULL) {
        toFree = *aux;
        toReturn = toFree->data;
        *aux = (*aux)->next;
        free(toFree);
    }

    return toReturn;
}

void *Hash_Search(HashTable hashT, void *key) {
    int hash = hashT->hashFunction(key, hashT->totalCount);
    HashElem aux = hashT->table[hash];
    while (aux != NULL) {
        if (hashT->compareKeys(hashT->getKey(aux->data), key))
            return aux->data;
        aux = aux->next;
    }

    return NULL;
}

int Hash_ClearAll(HashTable hashT) {
    HashElem aux, aux2;
    int x;

    for (x = 0; x < hashT->totalCount; x++) {
        aux = hashT->table[x];
        while (aux != NULL) {
            aux2 = aux;
            aux = aux->next;
            free(aux2);
        }
    }
    free(hashT->table);
    free(hashT);

    return 0;
}

int Hash_ApplyToAll(HashTable hashT, int (*function)(void *, void *, void *), void *params) {
    HashElem aux;

    int x;
    for (x = 0; x < hashT->totalCount; x++) {
        aux = hashT->table[x];
        while (aux != NULL) {
            function(aux->data, hashT->getKey(aux->data), params);
            aux = aux->next;
        }
    }

    return 0;
}

int Elem_Insert(HashTable hashT, HashElem *elem, void *data) {
    while ((*elem != NULL) && !hashT->compareKeys(hashT->getKey((*elem)->data), hashT->getKey(data))) {
        elem = &((*elem)->next);
    }

    int returnVal = 0;
    if (*elem == NULL || hashT->duplicate) {
        *elem = (HashElem) malloc(sizeof (struct hash_elem));
        (*elem)->next = NULL;
        returnVal = 1;
    }
    (*elem)->data = data;

    return returnVal;
}
