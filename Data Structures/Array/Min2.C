#include <stdio.h>
#include <stdlib.h>

int TournamentMin(int arr[], int lb, int ub)
{
    if (lb == ub)
    {
        return arr[lb];
    }

    if (ub == lb + 1)
    {
        return (arr[lb] < arr[ub]) ? arr[lb] : arr[ub];
    }

    int mid = (lb + ub) / 2;
    int minleft = TournamentMin(arr, lb, mid);
    int minright = TournamentMin(arr, mid + 1, ub);

    return (minleft < minright) ? minleft : minright;
}

int main()
{
    system("cls");

    int arr[] = {15, 8, 9, 7, 12, 19, 20, 4, 21, 2, 11, 6, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum element is: %d", TournamentMin(arr, 0, n - 1));

    return 0;
}