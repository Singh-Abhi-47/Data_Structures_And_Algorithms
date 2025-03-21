#include <stdio.h>
#include <stdlib.h>
#include "LinkedListTemplate.h"

int count = 0;
Node *start = NULL;

void AddNode(int value)
{

    InsertAtEnd(&start, value);
    count++;
}

void Traversing()
{
    Node *p = start->link;
    while (p != NULL)
    {
        printf("%d-->", p->data);
        p = p->link;
    }
    printf("null\n");
}

int main()
{
    system("cls");

    AddNode(10);
    AddNode(20);
    AddNode(30);
    AddNode(40);
    AddNode(50);
    AddNode(60);

    InsertAtBeginning(&start, count);

    PrintList(start);

    printf("\n");

    printf("Traversing the header list: ");
    Traversing();
}