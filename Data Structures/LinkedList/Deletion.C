#include <stdio.h>
#include <stdlib.h>
#include "LinkedListTemplate.h"

void DeletionOfFirstNode(Node **start)
{
    Node *p = *start;
    *start = (*start)->link;
    free(p);
}

void DeletionOfLastNode(Node **start)
{
    Node *p = *start;
    Node *f;
    if (*start == NULL)
    {
        printf("\n!UnderFlow!\n");
        return;
    }
    if ((*start)->link == NULL)
    {
        *start = NULL;
        return;
    }
    while (p->link->link)
    {
        p = p->link;
    }
    f = p->link->link;
    free(f);
    p->link = NULL;
}

void DeleteParticularElement(Node **start, int value)
{
    Node *p = *start;

    if ((*start) == NULL)
    {
        printf("\nUnderflow\n");
        return;
    }

    if (p->data == value)
    {
        *start = p->link;
        free(p);
        return;
    }

    while (p->link)
    {
        if (p->link->data == value)
        {
            Node *f;
            f = p->link;
            p->link = p->link->link;
            free(f);
            return;
        }
        p = p->link;
    }

    printf("\nElement not found!\n");
}

int main()
{
    system("cls");
    Node *start = NULL;

    InsertAtEnd(&start, 10);
    InsertAtEnd(&start, 20);
    InsertAtEnd(&start, 30);
    InsertAtEnd(&start, 40);
    InsertAtEnd(&start, 50);

    printf("Your linked list is: ");
    PrintList(start);

    // DeletionOfFirstNode(&start);
    // printf("\nAfter deleting the first element we have the new list as: \n");
    // PrintList(start);

    // DeletionOfLastNode(&start);
    // printf("\nAfter deleting the last element we have the new list as: \n");
    // PrintList(start);

    DeleteParticularElement(&start, 30);
    printf("\nAfter deleting the 30 element we have the new list as: \n");
    PrintList(start);

    printf("\n");
    FreeList(start);
}
