#include <stdio.h>
#include <stdlib.h>

int count(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            count++;
        }
    }
    return count;
}

int deletion(int arr[], int n, int k)
{
    if (n == 0)
    {
        printf("underbound");
        return 0;
    }
    for (int i = k; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }

    return 0;
}

int main()
{
    system("cls");
    int arr[10] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int c = count(arr, n);

    printf("Before deletion array: ");
    for (int i = 0; i < c; i++)
    {
        printf("%d ", arr[i]);
    }

    deletion(arr, n, 2);

    printf("\nAfter deletion array: ");
    for (int i = 0; i < c - 1; i++)
    {
        printf("%d ", arr[i]);
    }
}