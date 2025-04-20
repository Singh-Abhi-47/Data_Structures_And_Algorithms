#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1; // starting from the next element of pivot
    int j = high;

    while (i <= j) // when i and j have not crossed
    {
        while ((pivot >= arr[i]) && (high >= i)) // condition for i's iteration
            i++;
        while ((pivot <= arr[j])) // condition for j's iteration
            j--;

        if (i < j) // while i and j have not crossed
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[j], &arr[low]); // when i and j have crossed
    return j;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1); // left array
        quicksort(arr, pi + 1, high);
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

    int arr[] = {2, 6, 7, 5, 3, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, n);

    quicksort(arr, 0, n - 1);

    printf("Sorted Array: ");
    printArray(arr, n);

    return 0;
}