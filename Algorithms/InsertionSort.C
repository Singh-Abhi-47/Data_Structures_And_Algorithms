#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int arr[], int size)
{
    for (int j = 1; j < size; j++)
    {
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] >= key)
        {
            arr[i + 1] = arr[i];
            i = i - 1;
            arr[i + 1] = key;
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\n");
}

int main()
{
    system("cls");
    int arr[] = {10, 40, 30, 60, 20, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, size);

    InsertionSort(arr, size);

    printf("Sorted Array: ");
    printArray(arr, size);

    printf("\n\n");

    return 0;
}