#include <stdio.h>

int main()
{
    for (int i = 0; i <= 6; i += 3)
    {
        for (int j = 1; j <= 9; j++)
        {
            for (int k = 1; k <= 3; k++)
            {
                printf("%d * %d = %2d\t", i + k, j, (i + k) * j);
            }
            printf("\n");
        }
        printf("\n");
    }
}
