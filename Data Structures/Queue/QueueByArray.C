#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int queue[SIZE];
int front = -1;
int rear = -1;

void Enqueue(int queue[], int *front, int *rear, int value)
{
    if (*front == (*rear + 1) % SIZE)
    {
        printf("Overflow\n");
        return;
    }

    if (*rear == -1 && *front == -1)
    {
        *rear = 0;
        *front = 0;
    }
    else
        *rear = (*rear + 1) % SIZE;

    queue[*rear] = value;
}

void Dequeue(int queue[], int *front, int *rear)
{
    if (*front == -1)
    {
        printf("Underflow\n");
        return;
    }

    int item = queue[*front];

    if (*front == *rear)
    {
        *front = -1;
        *rear = -1;
    }
    else
        *front = (*front + 1) % SIZE;

    printf("Dequeued: %d\n", item);
}

void PrintQueue(int queue[], int front, int rear)
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    int i = front;
    do
    {
        printf("%d ", queue[i]);
        i = (i + 1) % SIZE;
    } while (i != (rear + 1) % SIZE);

    printf("\n");
}

int main()
{
    system("cls");

    Enqueue(queue, &front, &rear, 10);
    Enqueue(queue, &front, &rear, 20);
    Enqueue(queue, &front, &rear, 30);
    Enqueue(queue, &front, &rear, 40);
    Enqueue(queue, &front, &rear, 50);

    PrintQueue(queue, front, rear);

    Dequeue(queue, &front, &rear);
    PrintQueue(queue, front, rear);

    return 0;
}
