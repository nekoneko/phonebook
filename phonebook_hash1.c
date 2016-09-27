#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "phonebook_hash1.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastname[], entry *pHead)
{
    unsigned int hashPos;

    hashPos = hash(lastname);
    pHead = hashTable[hashPos];

    while (pHead!=NULL) {
        if (strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    /* allocate memory for the new entry and put lastName */
    unsigned int hashPos;

    hashPos = hash(lastName);

    e = (entry *) malloc(sizeof(entry));
    e->pNext = hashTable[hashPos];
    strcpy(e->lastName, lastName);
    e->detail = NULL;
    hashTable[hashPos] = e;

    return e;
}

unsigned int hash(char *str)
{
    unsigned int hash_value = 0;
    while(*str)
        hash_value = (hash_value << 5) - hash_value + (*str++);
    return (hash_value % MAX_HASH_TABLE_SIZE);
}
