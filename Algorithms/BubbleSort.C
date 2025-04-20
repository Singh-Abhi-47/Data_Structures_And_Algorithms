#include <stdio.h>
#include <stdlib.h>

int swap_num = 0;

void bubbleSort(int arr[], int size)
{
    int temp;
    int swapping;

    for (int i = 0; i < (size - 1); i++)
    {
        swapping = 0;
        for (int j = 0; j < (size - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapping = 1;
                swap_num++;
            }
        }
        if (!swapping)
            break;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    system("cls");
    int arr[] = {10, 8, 4, 6, 7, 9, 2, 5, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Array after the Bubble Sort: ");
    printArray(arr, n);
    printf("\nNumber of swappings done throughout the program: %d", swap_num);

    printf("\n\n");
    printf("\n\n");

    return 0;
}