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
    while(p->next)
    {
        
    }
}