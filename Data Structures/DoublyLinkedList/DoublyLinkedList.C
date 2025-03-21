#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedListTemplate.h"

int main()
{
    system("cls");

    d_node *start = NULL;

    InsertAtEnd(&start, 10);
    InsertAtEnd(&start, 20);
    InsertAtEnd(&start, 30);
    InsertAtEnd(&start, 40);
    InsertAtEnd(&start, 50);

    printf("\nForward printing:  ");
    ForwardPrintList(start);

    printf("\nBackward printing: ");
    BackwardPrintList(start);

    FreeList(start);
}