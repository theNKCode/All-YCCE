#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linkedlisttraveral(struct node *head)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp = head;
    printf("Linked List : ");
    while (tmp != NULL)
    {
        printf("%d\t", tmp->data);
        tmp = tmp->next;
    }
    printf("\n\n");
}

int push(struct node *head, int data, int top)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    if (top > 10)
        printf("Your Stack is Full!\nStack Overflow!\n");
    else
        tmp->next = newnode;
    return top;
}

void pop(struct node *head)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    struct node *prev = (struct node *)malloc(sizeof(struct node));
    tmp = head;
    prev = head;
    tmp = tmp->next;
    if (tmp == NULL)
        printf("Your Stack is Empty!\n Stack UnderFlow\n");
    else
    {
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
            prev = prev->next;
        }
        printf("Last Element %d is popped!\n", tmp->data);
        free(tmp);
        prev->next = NULL;
    }
}

int main()
{
    int top = 5, data;
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));
    struct node *fifth = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = NULL;

    printf("Implementing Stack using Linked List\n");

    linkedlisttraveral(head);
    printf("Pushing 11\n");
    top = push(head, 11, top);
    linkedlisttraveral(head);
    printf("Pushing 31\n");
    top = push(head, 31, top);
    linkedlisttraveral(head);
    printf("Popping data\n");
    pop(head);
    linkedlisttraveral(head);
    printf("Popping data\n");
    pop(head);
    linkedlisttraveral(head);
    printf("Popping data\n");
    pop(head);
    linkedlisttraveral(head);
}