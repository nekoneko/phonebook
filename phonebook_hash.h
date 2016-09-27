#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

#define HASH 1
typedef struct __DETAIL_ENTRY {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} detailEntry;

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    detailEntry *detail;
    /*
        char firstName[16];
        char email[16];
        char phone[10];
        char cell[10];
        char addr1[16];
        char addr2[16];
        char city[16];
        char state[2];
        char zip[5];
    */
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

#define MAX_HASH_TABLE_SIZE 42737

entry *hashTable[MAX_HASH_TABLE_SIZE];

entry *findName(char lastname[], entry *pHead);
entry *append(char lastName[], entry *e);

unsigned int hashFunction(unsigned int);
unsigned int stringToInt(char *key);

#endif
