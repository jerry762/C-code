#include <stdio.h>
#include <string.h>

/* test cases

===============================================================================
=    accept input(entire string): 6 4 3 5 9 1 10 10 6 3 7 2 9 0 10 9 0 (O)    =
=    not accept input(one by one input): 6 -> enter, 4 -> enter ...    (X)    =
===============================================================================

6 4 3 5 9 1 10 10 6 3 7 2 9 0 10 9 0

8 2 10 9 1 2 7 10 10 6 4 3 5 10 5 5 9

10 10 10 10 10 10 10 10 10 10 10 10

5,5,8,2,6,4,7,3,7,3,9,1,5,5,8,2,9,1,9,1,10

5,0,8,0,6,0,0,7,7,0,0,9,5,0,8,0,0,9,9,0

*/

int game(int *points, int size);

int main()
{
    int maxGames, sum = 0, max, min;
    int roundP[100];

    printf("Please set the maxGames: ");
    scanf("%d", &maxGames);

    for (int i = 0; i < maxGames; i++)
    {
        int points[21];
        int size = 0;

        memset(points, 0, sizeof(points));

        printf("Please input the No. %d's score !\n", i + 1);

        while (scanf("%d", &points[size++]))
        {
            if (getchar() == '\n')
                break;
        }
        roundP[i] = game(points, size);
    }

    max = min = roundP[0];

    for (int i = 0; i < maxGames; i++)
    {
        if (max < roundP[i])
            max = roundP[i];
        if (min > roundP[i])
            min = roundP[i];

        sum += roundP[i];
    }

    printf("\nSum of all games = %d\n", sum);
    printf("Average of the game = %.2f\n", (float)sum / maxGames);
    printf("The maximum score of the games = %d\n", max);
    printf("The minimum score of the games = %d\n\n", min);
}

int game(int *points, int size)
{
    int point = 0;
    int count = 0;
    printf("\n+-----+-----+-----+-----+-----+-----+-----+-----+-----+--------+\n");
    printf("|  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |   10   |\n");
    printf("+-----+-----+-----+-----+-----+-----+-----+-----+-----+--------+\n");

    for (int i = 0; i < 9; i++)
    {
        if (points[count] == 10)
        {
            printf("|%2d|%2s", 10, "  ");
            point += points[count] + points[count + 1] + points[count + 2];
            count++;
        }
        else
        {
            printf("|%2d|%2d", points[count], points[count + 1]);
            if (points[count] + points[count + 1] == 10)
                point += points[count] + points[count + 1] + points[count + 2];
            else
                point += points[count] + points[count + 1];
            count += 2;
        }
    }
    if (size - count == 3)
    {
        printf("|%2d|%2d|%2d|\n", points[count], points[count + 1], points[count + 2]);
        point += points[count] + points[count + 1] + points[count + 2];
    }
    else
    {
        printf("|%2d|%2d|%2s|\n", points[count], points[count + 1], "  ");
        point += points[count] + points[count + 1];
    }
    printf("+-----+-----+-----+-----+-----+-----+-----+-----+-----+--------+\n");

    return point;
}