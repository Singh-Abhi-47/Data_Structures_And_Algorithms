#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    int arr[4][4];
    int count = 1;

    printf("Start Entering elements it's 4x4 matrix so you'll be entering 10 elements: \n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i < j)
            {
                arr[i][j] = 0;
            }
            else
            {
                printf("%d: ", count);
                scanf("%d", &arr[i][j]);
                count++;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf(" %d\t", arr[i][j]);
        }
        printf("\n");
    }
}
