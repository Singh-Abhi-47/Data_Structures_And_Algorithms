#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory Allocation failed !");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d\n", value);
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    int value = top->data;
    Node *temp = top;
    top = top->next;
    free(temp);

    return value;
}

int peek()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return top->data;
}

void display()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }
    struct Node *temp = top;
    while (temp != NULL)
    {
        printf("%d => ", temp->data);
        temp = temp->next;
    }
    printf("X\n");
}

int main()
{
    system("cls");

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    printf("Let's peek our stack: %d", peek());
    printf("\n\nLet's pop the top element: %d", pop());

    printf("\n\n The stack looks like this now: ");
    display();

    printf("\n\n");

    return 0;
}