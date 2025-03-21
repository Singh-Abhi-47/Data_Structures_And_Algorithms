#include <stdio.h>
#include <stdlib.h>
#include "PolynomialTemplate.h"

int main()
{
    system("cls");

    b_polly *start = NULL;

    b_Insert(&start, 3, 2, 1);
    b_Insert(&start, -6, 1, 2);
    b_Insert(&start, 4, 1, 1);
    b_Insert(&start, 9, 0, 0);

    b_PrintPoly(start);

    b_FreePoly(start);
}