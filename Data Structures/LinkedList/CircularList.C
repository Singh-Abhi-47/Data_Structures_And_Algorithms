#include "LinkedListTemplate.h"

void Circular(Node *start)
{
    if (start == NULL)
        return;

    Node *last = start;
    while (last->link != NULL)
    {
        last = last->link;
    }
    last->link = start;
}

void PrintCircular(Node *start)
{
    if (start == NULL)
        return; // Edge case: Empty list

    Node *p = start;
    do
    {
        printf("%d -> ", p->data);
        p = p->link;
    } while (p != start); // Stop when we reach the start node again

    printf("...\n"); // To indicate circular behavior
}

void FreeCircular(Node *start)
{
    if (start == NULL)
        return; // Edge case: Empty list

    Node *p = start;
    Node *temp;

    do
    {
        temp = p;
        p = p->link;
        free(temp);
    } while (p != start); // Stop when we loop back to the start node

    start = NULL; // Set to NULL after freeing
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

    Circular(start);

    printf("\n");

    PrintCircular(start);
    FreeCircular(start);
}