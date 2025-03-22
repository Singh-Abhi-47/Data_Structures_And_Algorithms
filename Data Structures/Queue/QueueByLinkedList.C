#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *CreateNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->link = NULL;

    return newNode;
}

void InsertAtEnd(struct node **start, int value)
{
    struct node *newNode = CreateNode(value);
    if (*start == NULL)
    {
        *start = newNode;
        return;
    }
    struct node *p = *start;
    while (p->link != NULL)
    {
        p = p->link;
    }

    p->link = newNode;
}

void InsertAtBeginning(struct node **start, int value)
{
    struct node *newNode = CreateNode(value);

    if (newNode == NULL) // Check if memory allocation failed
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->link = *start; // Point new node to the current first node
    *start = newNode;       // Update start to new node
}

void DeleteFromBeginning(struct node **start)
{
    struct node *p = *start;
    *start = (*start)->link;
    free(p);
}

void PrintingQueue(struct node *start)
{
    struct node *p = start;
    if (p->data == NULL)
    {
        printf("Empty");
        return;
    }
    while (p)
    {
        printf("%d ", p->data);
        p = p->link;
    }
}

void FreeQue(struct node *start)
{
    struct node *p;
    while (start)
    {
        p = start;
        start = start->link;
        free(p);
    }
}

int main()
{
    system("cls");

    struct node *start;

    InsertAtEnd(&start, 10);
    InsertAtEnd(&start, 20);
    InsertAtEnd(&start, 30);
    InsertAtEnd(&start, 40);
    InsertAtEnd(&start, 50);

    // InsertAtBeginning(&start, 10);
    // InsertAtBeginning(&start, 20);
    // InsertAtBeginning(&start, 30);
    // InsertAtBeginning(&start, 40);
    // InsertAtBeginning(&start, 50);

    PrintingQueue(start);

    printf("\nAfter Deletion: ");

    DeleteFromBeginning(&start);

    PrintingQueue(start);

    printf("\n");
}