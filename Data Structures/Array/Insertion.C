#include <stdio.h>
#include <stdlib.h>

int Insert(int arr[], int k, int ub)
{
    int x;
    if (k > 10)
    {
        printf("overflow");
        return 0;
    }
    for (int i = ub; i >= k; i--)
    {
        arr[i + 1] = arr[i];
    }

    printf("enter your element: ");
    scanf("%d", &x);
    arr[k] = x;
}

int count(int arr[], int n)
{
    int count = 0;

    // Traverse the entire array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    system("cls");
    int arr[10] = {1, 2, 3, 4, 5};

    Insert(arr, 2, 5);

    for (int i = 0; i < count(arr, 10); i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}