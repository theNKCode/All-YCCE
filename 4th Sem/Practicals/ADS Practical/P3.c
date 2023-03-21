#include <stdio.h>
#include <stdlib.h>

#define MAX_LEV 3

typedef struct node
{
    int data;
    struct node *next[MAX_LEV];
} snode;

snode *create(int *list, int n)
{
    snode *sklist, *nnode;
    int i, j;
    printf("Create Linked List:\n");
    sklist = NULL;
    //For creating 0th level of skip list
    for (i = n - 1; i >= 0; i--) 
    {
        nnode = (snode *)malloc(sizeof(snode));
        nnode->data = list[i];
        nnode->next[0] = sklist;
        for (j = 1; j < MAX_LEV; j++)   //For travelling in levels
            nnode->next[j] = NULL;
        sklist = nnode;
    }
    return (sklist);
}

snode *build_skip(snode *sklist)
{
    int i, j;
    snode *nptr, *nnode; //nnode travelling levels
    // For travelling in levels greater than 0.
    for (j = 1; j < MAX_LEV; j++)
    {
        nnode = nptr = sklist;
        for (i = 0; nptr->next[j - 1] != NULL;  i++)
        {
            if (i % MAX_LEV == 0)
            {
                nnode->next[j] = nptr; //nnode next travelling levels also traversing in  that same level as per condition
                nnode = nptr;
            }
            nptr = nptr->next[j - 1]; //nptr is on prev level also traversing in that level at same time
        }
        nnode->next[j] = nptr; // Pointing to NULL
    }
    return sklist;
}

void traverse(snode *sklist)
{
    int i;
    snode *np;
    for (i = MAX_LEV - 1; i >= 0; i--)// ALLocating Levels
    {
        printf("level %d: ", i);
        for (np = sklist; np != NULL; np = np->next[i]) //Travelling in that level
        {
            printf("%d ", np->data);
        }
        printf("\n");
    }
    printf("\n");
}

void search_sklist(snode *sklist, int val)
{
    int count = 0, lvl = MAX_LEV - 1;
    snode *prev = sklist;
    if (sklist == NULL || val < sklist->data)
    {
        printf("%d: is not in the list\tcount:%d\n", val, count);
        return;
    }
    while (lvl >= 0 && sklist != NULL)
    {
        count++;
        printf("%d\tlevel:%d\n", sklist->data, lvl);
        if (sklist->data == val)
        {
            printf("%d: is in the list\tcount:%d\n", val, count);
            return;
        }
        if (sklist->data < val)
        {
            prev = sklist;
            sklist = sklist->next[lvl];
        }
        else
        {
            --lvl;
            sklist = prev->next[lvl];
        }
    }
    printf("%d: is not in the list\tcount:%d\n", val, count);
}

int main()
{
    int list[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(list) / sizeof(list[0]);
    snode *sklist = create(list, n);
    sklist = build_skip(sklist);

    traverse(sklist);

    search_sklist(sklist, 11);
    search_sklist(sklist, 8);

    return 0;
}