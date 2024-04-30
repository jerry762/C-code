#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 100

int main()
{
    int number[MAX_SIZE] = {0};
    int size = 0;

    srand(time(0));

    printf("input the size of array:");

    scanf("%d", &size);

    for (size_t i = 0; i < size; i++)
        number[i] = rand() % 100;

    for (size_t i = 0; i < size - 1; i++)
    {
        int index = i;

        for (size_t j = i + 1; j < size; j++)
        {
            if (number[index] > number[j])
                index = j;
        }
    }

    // for (size_t i = 0; i < size - 1; i++)
    // {
    //     bool flag = false;

    //     for (size_t j = 0; j < size - i - 1; j++)
    //     {
    //         if (number[j] > number[j + 1])
    //         {
    //             number[j] = number[j] ^ number[j + 1];
    //             number[j + 1] = number[j] ^ number[j + 1];
    //             number[j] = number[j] ^ number[j + 1];

    //             flag = true;
    //         }
    //     }

    //     if (!flag)
    //         break;
    // }

    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", number[i]);
    }

    return 0;
}

