#include <stdio.h>
#include <stdlib.h>

typedef struct double_node
{
    int data;
    struct double_node *previous;
    struct double_node *next;
} d_node;

d_node *CreateNode(int value)
{
    d_node *newNode = (d_node *)malloc(sizeof(d_node));
    newNode->data = value;
    newNode->previous = NULL;
    newNode->next = NULL;

    return newNode;
}

void InsertAtEnd(d_node **start, int value)
{
    d_node *newNode = CreateNode(value);
    if (*start == NULL)
    {
        *start = newNode;
        return;
    }
    d_node *p = *start;
    while (p->next)
    {
        p = p->next;
    }
    p->next = newNode;
    newNode->previous = p;
}

void InsertAtBeginning(d_node **start, int value)
{
    d_node *newNode = CreateNode(value);
    if (*start == NULL)
    {
        *start = newNode;
        return;
    }

    newNode->next = *start;
    (*start)->previous = newNode;
    *start = newNode;
}

void ForwardPrintList(d_node *start)
{

    d_node *p = start;
    printf("null <==> ");
    while (p)
    {
        printf("%d <==> ", p->data);
        p = p->next;
    }
    printf("null\n");
}

void BackwardPrintList(d_node *start)
{
    d_node *last = start;
    printf("null <==> ");
    if (last == NULL)
        return;

    while (last->next)
        last = last->next;

    while (last)
    {
        printf("%d <==> ", last->data);
        last = last->previous;
    }
    printf("null\n");
}

void FreeList(d_node *start)
{
    d_node *p;
    while (start)
    {
        p = start;
        start = start->next;
        free(p);
    }
}