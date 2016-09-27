#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "phonebook_hash.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastname[], entry *pHead)
{
    unsigned int hashPos;

    hashPos = hashFunction(stringToInt(lastname));
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

    hashPos = hashFunction(stringToInt(lastName));

    e = (entry *) malloc(sizeof(entry));
    e->pNext = hashTable[hashPos];
    strcpy(e->lastName, lastName);
    e->detail = NULL;
    hashTable[hashPos] = e;

    return e;
}

unsigned int stringToInt(char *key)
{
    int number = 0;
    while (*key)
        number += *key++;
    return number;
}

unsigned int hashFunction(unsigned int key)
{
    return key % MAX_HASH_TABLE_SIZE;
}
