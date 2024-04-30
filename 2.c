#include <stdio.h>

void swab(int *a, int *b);


int main()
{
    int a = -5;
    int b = 5;

    printf("%d %d\n", a, b);

    swab(&a, &b);

    printf("%d %d", a, b);

    return 0;
}

void swab(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}