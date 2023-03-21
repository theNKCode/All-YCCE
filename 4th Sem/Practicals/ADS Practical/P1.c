#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    char name[20];
    struct Node *next;
};

struct Node *insertathead(struct Node *head, int amt, char n[])
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = amt;
    strcpy(ptr->name, n);
    ptr->next = head;
    return ptr;
}

void linkedlisttraversal(struct Node *head)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p = head;
    printf("----Coffee Shop Bills----\nCoffee Name\tAmount\n");
    while (p->next != NULL)
    {
        printf("%s\t\t%d\n", p->name, p->data);
        p = p->next;
    }
}

void sum(struct Node *head)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p = head;
    int sum = 0;
    while (p->next != NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    printf("%d\n", sum);
}

void max_min(struct Node *head)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p = head;
    int max = INT_MIN;
    int min = INT_MAX;
    while (p->next != NULL)
    {
        if (p->data >= max)
        {
            max = p->data;
        }
        if (p->data <= min)
        {
            min = p->data;
        }
        p = p->next;
    }
    printf("Maximun Amount : %d\t\nMinimum Amount : %d\t\n", max, min);
}

int main()
{
    int ch, amt, i, ch1, coffeech, quantity, size, total;
    char res, coffeename[20], r, resp;
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->next = NULL;

    printf("----Welcome to Coffee Shop----\n");
    printf("\tBill Portal\n");
getmore:
    total = 0;
    do
    {
        printf("\nEnter Coffee :\n\t1.Espresso\n\t2.Cold Coffee\n\t3.Iced Americano\n\t4.Iced Latte\n\t");
        scanf("%d", &coffeech);
        if (coffeech == 1)
            printf("\nEnter Size :\n\t1.Tall \t260\n\t2.Grande \t290\n\t3.Venti\t320\n\t");
        else if (coffeech == 2)
            printf("\nEnter Size :\n\t1.Tall \t255\n\t2.Grande \t280\n\t3.Venti\t300\n\t");
        else if (coffeech == 3)
            printf("\nEnter Size :\n\t1.Tall \t210\n\t2.Grande \t235\n\t3.Venti\t260\n\t");
        else if (coffeech == 4)
            printf("\nEnter Size :\n\t1.Tall \t225\n\t2.Grande \t250\n\t3.Venti\t275\n\t");
        scanf("%d", &size);
        printf("Enter Quantity:\tx");
        scanf("%d", &quantity);
        if (coffeech == 1)
        {
            strcpy(coffeename , "Espresso");
            if (size == 1)
                total = 260 * quantity;
            if (size == 2)
                total = 290 * quantity;
            if (size == 3)
                total = 320 * quantity;
        }
        if (coffeech == 2)
        {
            strcpy(coffeename , "Cold Coffee");
            if (size == 1)
                total = 255 * quantity;
            if (size == 2)
                total = 280 * quantity;
            if (size == 3)
                total = 300 * quantity;
        }
        if (coffeech == 3)
        {
            strcpy(coffeename , "Iced Americano");
            if (size == 1)
                total = 210 * quantity;
            if (size == 2)
                total = 235 * quantity;
            if (size == 3)
                total = 260 * quantity;
        }
        if (coffeech == 4)
        {
            strcpy(coffeename , "Iced Latte");
            if (size == 1)
                total = 225 * quantity;
            if (size == 2)
                total = 250 * quantity;
            if (size == 3)
                total = 275 * quantity;
        }
        printf("\nYour total becomes : %d\n\n", total);
        printf("Do you want to order more coffee :\t");
        scanf("%d", resp);
    } while (resp == 'y');

    head = insertathead(head, total, coffeename);
    printf("\nWant to order another coffee : ");
    scanf("%s", &res);
    if (res == 'y')
        goto getmore;
choice:
    printf("\n1.Print Bills\n2.Sum of all Bills\n3.Print Maximun and Minimum\n\nEnter 1/2/3: ");
    scanf("%d", &ch);
    if (ch == 1)
        linkedlisttraversal(head);
    else if (ch == 2)
        sum(head);
    else if (ch == 3)
        max_min(head);
    else if (ch != 1 || ch != 2 || ch != 3)
    {
        return 0;
    }
    goto choice;
}