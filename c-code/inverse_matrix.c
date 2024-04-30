#include <stdio.h>

#define MAX_SIZE 100

void init(double matrix[][MAX_SIZE], double inverse[][MAX_SIZE], int size);
void print(double matrix[][MAX_SIZE], int size);

int main()
{
    int size = 0;
    double matrix[MAX_SIZE][MAX_SIZE] = {0};
    double inverse[MAX_SIZE][MAX_SIZE] = {0};

    printf("input size of the matrix:");

    scanf("%d", &size);

    init(matrix, inverse, size);

    print(matrix, size);

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (i != j)
            {
                double factor = matrix[j][i] / matrix[i][i];

                for (size_t k = 0; k < size; k++)
                {
                    matrix[j][k] = matrix[j][k] - (matrix[i][k] * factor);
                    inverse[j][k] = inverse[j][k] - (inverse[i][k] * factor);
                }
            }
        }
    }

    for (size_t i = 0; i < size; i++)
    {
        double divide = matrix[i][i];

        for (size_t j = 0; j < size; j++)
            inverse[i][j] /= divide;

        matrix[i][i] /= divide;
    }

    printf("\n");

    print(inverse, size);

    return 0;
}

void init(double matrix[][MAX_SIZE], double inverse[][MAX_SIZE], int size)
{
    double value = 0;

    printf("input values of the matrix:");

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            scanf("%lf", &value);
            matrix[i][j] = value;

            if (i == j)
                inverse[i][j] = 1;
        }
    }
}

void print(double matrix[][MAX_SIZE], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            printf("%6.2f", matrix[i][j]);
        }
        printf("\n");
    }
}

/*
    3X3: 2 2 5 -2 1 2 6 3 9

      2.00  2.00  5.00
     -2.00  1.00  2.00
      6.00  3.00  9.00

      0.50 -0.50 -0.17
      5.00 -2.00 -2.33
     -2.00  1.00  1.00
*/

/*
    4X4: 1 1 1 0 0 3 1 2 2 3 1 0 1 0 2 1

       1.00  1.00  1.00  0.00
       0.00  3.00  1.00  2.00
       2.00  3.00  1.00  0.00
       1.00  0.00  2.00  1.00

      -3.00 -0.50  1.50  1.00
       1.00  0.25 -0.25 -0.50
       3.00  0.25 -1.25 -0.50
      -3.00  0.00  1.00  1.00
*/

/*
    5X5: -3 2 6 -4 5 6 4 -2 5 3 -1 2 4 -4 0 2 5 -7 3 -4 -2 5 -3 6 8

     -3.00  2.00  6.00 -4.00  5.00
      6.00  4.00 -2.00  5.00  3.00
     -1.00  2.00  4.00 -4.00  0.00
      2.00  5.00 -7.00  3.00 -4.00
     -2.00  5.00 -3.00  6.00  8.00

      0.42  0.16 -0.48  0.14 -0.25
     -0.21  0.01  0.40 -0.01  0.13
     -0.96 -0.01  1.17 -0.45  0.37
     -1.17 -0.05  1.24 -0.49  0.50
      0.75  0.07 -0.86  0.24 -0.25
*/