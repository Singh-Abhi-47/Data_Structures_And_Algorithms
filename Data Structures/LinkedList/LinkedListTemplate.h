#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} Node;

Node *CreateNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->link = NULL;

    return newNode;
}

void InsertAtEnd(Node **start, int value)
{
    Node *newNode = CreateNode(value);
    if (*start == NULL)
    {
        *start = newNode;
        return;
    }
    Node *p = *start;
    while (p->link)
    {
        p = p->link;
    }
    p->link = newNode;
}

void PrintList(Node *start)
{
    Node *p = start;
    while (p)
    {
        printf("%d-->", p->data);
        p = p->link;
    }
    printf("null\n");
}

void FreeList(Node *start)
{
    Node *p;
    while (start != NULL)
    {
        p = start;
        start = start->link;
        free(p);
    }
}