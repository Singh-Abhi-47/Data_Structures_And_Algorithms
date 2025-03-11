#include <stdio.h>
#include <stdlib.h>

int max(int arr[], int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

int main()
{
    system("cls");
    int arr[] = {15, 8, 9, 7, 12, 19, 20, 4, 21, 2, 11, 6, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Maximum element is : %d", max(arr, n));
}