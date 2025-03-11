#include <stdio.h>
#include <stdlib.h>

int LinearSearch(int arr[], int item, int n)
{

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == item)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    system("cls");
    int arr[] = {15, 8, 9, 7, 12, 19, 20, 4, 21, 2, 11, 6, 1, 5};
    int item, n;
    n = sizeof(arr) / sizeof(arr[0]);
    printf("Enter the item you wanna find out: ");
    scanf("%d", &item);

    printf("Found your element at: %d", LinearSearch(arr, item, n));
}