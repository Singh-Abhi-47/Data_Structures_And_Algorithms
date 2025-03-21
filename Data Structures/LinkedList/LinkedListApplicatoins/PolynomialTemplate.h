#include <stdio.h>
#include <stdlib.h>

typedef struct univariate_polynomial
{
    int coeff;
    int x_pow;
    struct univariate_polynomial *link;
} u_polly;

typedef struct bivariate_polynomial
{
    int coeff;
    int x_pow;
    int y_pow;
    struct bivariate_polynomial *link;
} b_polly;

//---------------------------------------------------------------------

u_polly *u_CreateNode(int coeff, int x_pow)
{
    u_polly *newNode = (u_polly *)malloc(sizeof(u_polly));
    newNode->coeff = coeff;
    newNode->x_pow = x_pow;
    newNode->link = NULL;

    return newNode;
}

b_polly *b_CreateNode(int coeff, int x_pow, int y_pow)
{
    b_polly *newNode = (b_polly *)malloc(sizeof(b_polly));
    newNode->coeff = coeff;
    newNode->x_pow = x_pow;
    newNode->y_pow = y_pow;
    newNode->link = NULL;

    return newNode;
}

//---------------------------------------------------------------------

void u_Insert(u_polly **start, int coeff, int x_pow)
{
    u_polly *newNode = u_CreateNode(coeff, x_pow);
    if (*start == NULL)
    {
        *start = newNode;
        return;
    }
    u_polly *p = *start;
    while (p->link)
    {
        p = p->link;
    }
    p->link = newNode;
}

void b_Insert(b_polly **start, int coeff, int x_pow, int y_pow)
{
    b_polly *newNode = b_CreateNode(coeff, x_pow, y_pow);
    if (*start == NULL)
    {
        *start = newNode;
        return;
    }
    b_polly *p = *start;
    while (p->link)
    {
        p = p->link;
    }
    p->link = newNode;
}

//---------------------------------------------------------------------

void u_PrintPoly(u_polly *start)
{
    u_polly *p = start;
    while (p)
    {
        // Print coefficient and variable
        if (p->coeff > 0 && p != start)
            printf(" + "); // Add '+' only if it's not the first term

        if (p->coeff < 0)
            printf(" - "); // Handle negative numbers separately

        printf("%d", abs(p->coeff)); // Print absolute coefficient

        if (p->x_pow > 0)
            printf("(x^%d)", p->x_pow); // Print variable and exponent

        p = p->link;
    }
    printf("\n");
}

void b_PrintPoly(b_polly *start)
{
    b_polly *p = start;
    while (p)
    {
        // Handle positive coefficients (skip + for first term)
        if (p->coeff > 0 && p != start)
            printf(" + ");
        if (p->coeff < 0)
            printf(" - ");

        printf("%d", abs(p->coeff)); // Print absolute value

        // Print exponents correctly
        if (p->x_pow > 0 && p->y_pow > 0)
            printf("(x^%d)(y^%d)", p->x_pow, p->y_pow);
        else if (p->x_pow > 0)
            printf("(x^%d)", p->x_pow);
        else if (p->y_pow > 0)
            printf("(y^%d)", p->y_pow);

        p = p->link; // Move to next node!
    }
    printf("\n"); // New line at the end
}

//---------------------------------------------------------------------

void u_FreePoly(u_polly *start)
{
    u_polly *p;
    while (start != NULL)
    {
        p = start;
        start = start->link;
        free(p);
    }
}

void b_FreePoly(b_polly *start)
{
    b_polly *p;
    while (start != NULL)
    {
        p = start;
        start = start->link;
        free(p);
    }
}

//---------------------------------------------------------------------