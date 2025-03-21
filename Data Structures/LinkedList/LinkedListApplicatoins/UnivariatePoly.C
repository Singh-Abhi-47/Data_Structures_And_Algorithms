#include <stdio.h>
#include <stdlib.h>
#include "PolynomialTemplate.h"

int main()
{
    system("cls");

    u_polly *start = NULL;

    u_Insert(&start, 3, 3);
    u_Insert(&start, -6, 2);
    u_Insert(&start, 4, 1);
    u_Insert(&start, 9, 0);

    u_PrintPoly(start);

    u_FreePoly(start);
}