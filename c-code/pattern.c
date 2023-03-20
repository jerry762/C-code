#include <stdio.h>

int main()
{
    int h = 0;

    scanf("%d", &h);

    printf("***");

    for (int i = 0; i < h - 1; i++)
        printf(" ");

    printf("***\n");

    for (int i = 1; i < (h + 1) / 2; i++)
    {
        printf("  ");

        for (int j = 0; j < i; j++)
            printf(" ");

        printf("*");

        for (int j = 0; j < (h - 1) - (i * 2); j++)
            printf(" ");

        printf("*\n");
    }

    for (int i = (h - 3) / 2; i > 0; i--)
    {
        printf("  ");

        for (int j = 0; j < i; j++)
            printf(" ");

        printf("*");

        for (int j = 0; j < (h - 1) - (i * 2); j++)
            printf(" ");

        printf("*\n");
    }

    printf("***");

    for (int i = 0; i < h - 1; i++)
        printf(" ");

    printf("***\n");

    return 0;
}