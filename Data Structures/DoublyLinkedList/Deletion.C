#include "DoublyLinkedListTemplate.h"

int main()
{
    system("cls");

    d_node *start;

    InsertAtEnd(&start, 10);
    InsertAtEnd(&start, 20);
    InsertAtEnd(&start, 30);
    InsertAtEnd(&start, 40);
    InsertAtEnd(&start, 50);
    InsertAtEnd(&start, 60);

    ForwardPrintList(start);

    DeleteNode(&start, 30);

    printf("\n\n");
    ForwardPrintList(start);
    printf("\n");

    FreeList(start);
}