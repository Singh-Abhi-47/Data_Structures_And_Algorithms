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

void InserAtEnd(struct node **start, int value)
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
    struct node *newNode = (struct node *)malloc(sizeof(struct node *));
    newNode->data = value;
    newNode->link = *start;
    *start = newNode;
}

void PrintList(struct node *start)
{
    struct node *p = start;
    while (p != NULL)
    {
        printf("%d-->", p->data);
        p = p->link;
    }
    printf("null\n");
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
    printf("Let's make a new linked list: ");
    char choice;
    struct node *start = NULL;

    InsertAtBeginning(&start, 1);
    InsertAtBeginning(&start, 2);
    InsertAtBeginning(&start, 3);

    PrintList(start);

    // do
    // {
    //     printf("\nAdd your element: ");
    //     int value = NULL;
    //     scanf("%d", &value);

    //     InserAtEnd(&start, value);

    //     printf("\nWanna add more elements?(Y/N) ");
    //     scanf(" %c", &choice);
    //     if (choice == 'Y')
    //         system("cls");
    // } while (choice == 'Y');

    // printf("\nPrint your list then?(Y/N)");
    // scanf(" %c", &choice);

    // if (choice == 'Y')
    //     PrintList(start);

    FreeList(start);
}