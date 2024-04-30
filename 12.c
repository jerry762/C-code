#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    
    return 0;
}

// 1.
// int count = 0;

// while (str[count] != '\0')
//     count++;

// return count;

// 2.

// for (size_t i = 1; i < 15; i++)
// {
//     for (size_t j = 1; j < 15; j++)
//     {
//         for (size_t k = 1; k < 15; k++)
//         {
//             if (i + j + k == 18)
//             {
//                 printf("%d + %d + %d = %d\n", i, j, k, i + j + k);
//             }
//         }
//     }
// }

// 3.

// int strToDecimal(char *str);

// int main()
// {
//     char a[] = "1000";
//     char b[] = "500";

//     printf("%d", strToDecimal(a) + strToDecimal(b));

//     return 0;
// }

// int strToDecimal(char *str)
// {
//     int count = 0;
//     int size = strlen(str) - 1;

//     for (int i = size; i >= 0; i--)
//     {
//         int digit = str[i] - '0';

//         count += digit * pow(10, size - i);
//     }

//     return count;
// }


// 4.

// int arr[5] = {1, 2, 3, 4, 5};

// int *p = arr;

// *(p++) += 100;
// *(++p) += 100;

// for (size_t i = 0; i < 5; i++)
// {
//     printf("%d ", arr[i]);
// }


// 5.

// int input = 0;

// scanf("%d", &input);

// for (size_t i = 1; i <= input; i++)
// {
//     for (size_t j = 0; j < input - i; j++)
//         printf(" ");

//     for (size_t j = 1; j <= i; j++)
//     {
//         printf("%d", j);
//     }

//     for (int j = i - 1; j > 0; j--)
//         printf("%d", j);

//     printf("\n");
// }