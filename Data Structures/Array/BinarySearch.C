#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int arr[], int item, int lb, int ub)
{
    int l = lb;
    int h = ub;

    int mid = (l + h) / 2;

    while ((item != arr[mid]) && (l <= h))
    {

        if (item > arr[mid])
            l = mid + 1;
        else
            h = mid - 1;

        mid = (l + h) / 2;
    }

    if (item == arr[mid])
        return mid;
    else
        return -1;
}

int main()
{
    system("cls");
    int arr[] = {1, 5, 6, 9, 12, 14, 21, 35, 56, 77, 89, 90, 108};
    int item;
    int n = (sizeof(arr) / sizeof(arr[0]));
    printf("Enter the element you wanna check out: ");
    scanf("%d", &item);

    printf("Found it at: %d", BinarySearch(arr, item, 0, n - 1));
}