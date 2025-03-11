#include <stdio.h>
#include <stdlib.h>

int min(int arr[], int n)
{
    int min = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int main()
{
    system("cls");
    int arr[] = {15, 8, 9, 7, 12, 19, 20, 4, 21, 2, 11, 6, 1, 5};

    int n;
    n = sizeof(arr) / sizeof(arr[0]);
    printf("%d", min(arr, n));

    printf("\n", n);
}