#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_orig.h"

/* original version */
entry *findName(char lastname[], entry *pHead)
{
    while (pHead) {
        if (strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

int deleteName(char lastname[],entry **pHead)
{
    entry *tmp,*dad;
    if(strcasecmp((*pHead)->lastName,lastname)==0) {
        tmp=*pHead;
        (*pHead)=(*pHead)->pNext;
        free(tmp);
        return 1;
    }
    tmp=(*pHead)->pNext;
    dad=*pHead;
    while (tmp) {
        if (strcasecmp(lastname, tmp->lastName) == 0) {
            dad->pNext=tmp->pNext;
            free(tmp);
            return 1;
        }
        tmp = tmp->pNext;
        dad = dad->pNext;
    }
    return 0;
}

entry *append(char lastName[], entry *e)
{
    /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
}

void show_entry(entry *pHead)
{
    while (pHead) {
        printf("%s", pHead->lastName);
        pHead = pHead->pNext;
    }
}

void show_entrylen(entry *pHead)
{
    int i=0;
    while (pHead) {
        i++;
        pHead = pHead->pNext;
    }
    printf("entry amount:%d",i);
}
