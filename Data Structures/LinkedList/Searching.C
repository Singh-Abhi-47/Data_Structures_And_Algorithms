#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *CreatingNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->link = NULL;

    return newNode;
}

void InsertAtEnd(struct node **start, int value)
{
    struct node *newNode = CreatingNode(value);
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
    while (p->link)
    {
        printf("%d-->", p->data);
        p = p->link;
    }
    printf("null\n");
}

int LinkSearch(struct node *start, int value)
{
    struct node *p = start;
    int count = 1;
    if (p == NULL)
        return count;
    while (p)
    {
        if (p->data == value)
        {
            return count;
        }
        count++;
        p = p->link;
    }

    return -1;
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
    int value;

    printf("Enter your linked list elements, when you are done just enter 0(zero): ");
    int i = 1;
    while (i)
    {
        if (i != 0)
        {
            scanf("%d", &i);
            InsertAtEnd(&start, i);
        }
    }

    printf("\nGood, now let's print your linked list eh.. shall we: \n");
    PrintList(start);

    printf("\nNow let's do the searching thing eh..");

    printf("Enter the element you wanna search: ");
    scanf("%d", &value);

    if (LinkSearch(start, value) != -1)
        printf("Your element is found at position number: %d\n", LinkSearch(start, value));
    else
        printf("Sorry, your element doesn't exist...\n");

    FreeList(start);
}