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

void insertAtEnd(struct node **start, int value)
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

void PrintList(struct node *start)
{
    struct node *p = start;
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->link;
    }
    printf("NULL\n");
}

void FreeList(struct node *start)
{
    struct node *p;
    while (start != NULL)
    {
        p = start;
        start = start->link;
        free(p);
    }
}

int main()
{
    system("cls");
    struct node *start = NULL;

    insertAtEnd(&start, 10);
    insertAtEnd(&start, 20);
    insertAtEnd(&start, 30);

    printf("Our Linked List is: ");
    PrintList(start);

    FreeList(start);

    return 0;
}
