#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
int main()
{
    srand(time(0));
    int num[N], left = 0, right = N - 1, temp;
    for (int i = 0; i < 20; i++)
    {
        num[i] = rand() % 100 + 1;
        printf("num[%d]=%d\n", i, num[i]);
    }
    printf("---------------------------------\n");
    while (left < right)
    {
        for (int i = left; i < right; i++)
        {
            if (num[i] > num[i + 1])
            {
                temp = num[i];
                num[i] = num[i + 1];
                num[i + 1] = temp;
            }
        }
        right--;
        for (int j = right; j > left; j--)
        {
            if (num[j] < num[j - 1])
            {
                temp = num[j];
                num[j] = num[j - 1];
                num[j - 1] = temp;
            }
        }
        left++;
    }
    for (int i = 0; i < N; i++)
        printf("num[%d]=%d\n", i, num[i]);
}
