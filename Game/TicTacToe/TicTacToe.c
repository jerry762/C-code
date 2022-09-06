#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void printTable(char table[3][3]);

int main()
{
    char table[3][3], OX[3] = "OX";
    bool pos[3][3] = {false};
    int time = 1, input;

    memset(table, ' ', sizeof(table));

    printf("A player (O)\nB player (X)\n\n");
    printTable(table);

    while (time != 10)
    {
        printf("%c player input position (%c):", (time % 2) ? 'A' : 'B', OX[time % 2]);
        scanf("%d", &input);
        if (input > 9 || input < 1 || pos[(input - 1) / 3][(input - 1) % 3] == true)
        {
            printf("input again !\n");
            continue;
        }

        pos[(input - 1) / 3][(input - 1) % 3] = true;
        table[(input - 1) / 3][(input - 1) % 3] = OX[time % 2];
        system("cls");
        printTable(table);

        if ((table[0][0] == OX[time % 2] &&
             table[1][1] == OX[time % 2] &&
             table[2][2] == OX[time % 2]) ||

            (table[2][0] == OX[time % 2] &&
             table[1][1] == OX[time % 2] &&
             table[0][2] == OX[time % 2]))
        {
            printf("%c player win !\n", (time % 2) ? 'A' : 'B');
            system("pause");
            return 0;
        }

        for (int i = 0; i < 3; i++)
        {
            int row = 0, column = 0;

            for (int j = 0; j < 3; j++)
            {
                if (table[i][j] == OX[time % 2])
                    row++;
                if (table[j][i] == OX[time % 2])
                    column++;
            }
            if (row == 3 || column == 3)
            {
                printf("%c player win !\n", (time % 2) ? 'A' : 'B');
                system("pause");
                return 0;
            }
        }
        time++;
    }
    printf("no winner !\n");
    system("pause");
    return 0;
}

void printTable(char table[3][3])
{
    printf("\t*-*-*-*\n");
    printf("\t|%c|%c|%c|\n", table[2][0], table[2][1], table[2][2]);
    printf("\t*-*-*-*\n");
    printf("\t|%c|%c|%c|\n", table[1][0], table[1][1], table[1][2]);
    printf("\t*-*-*-*\n");
    printf("\t|%c|%c|%c|\n", table[0][0], table[0][1], table[0][2]);
    printf("\t*-*-*-*\n\n");
}