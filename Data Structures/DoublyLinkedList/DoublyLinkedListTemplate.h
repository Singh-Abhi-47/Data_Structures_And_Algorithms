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

void DeleteNode(d_node **start, int value)
{
    d_node *p = *start;
    if (start == NULL)
    {
        printf("Empty List");
        return;
    }
    if (p->data == value)
    {
        *start = p->next; // Move head to next node
        if (*start)       // If new head is not NULL
            (*start)->previous = NULL;
        free(p); // Free the old head
        return;
    }

    while (p)
    {
        if (p->data == value)
        {
            p->previous->next = p->next;
            p->next->previous = p->previous;
            free(p);
            return;
        }
        p = p->next;
    }

    printf("Element not found!");
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