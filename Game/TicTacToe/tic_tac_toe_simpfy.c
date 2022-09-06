#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printTable(char table[3][3]);

int main()
{
    char table[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, O_X[2] = {'O', 'X'};
    int jud = 1, position;
    bool numbers[9] = {false};
    printf("A player (O)\nB player (X)\n\n");
    printTable(table);
    while (jud < 10)
    {
        if (jud % 2 == 0)
        {
            printf("A player input position (O):");
        }
        else
        {
            printf("B player input position (X):");
        }
        scanf("%d", &position);
        if (position < 1 || position > 9 || numbers[position - 1] == true)
        {
            printf("input again !\n\n");
            continue;
        }
        if (position >= 1 && position <= 3)
        {
            table[2][position - 1] = O_X[jud % 2];
            numbers[position - 1] = true;
        }
        if (position >= 4 && position <= 6)
        {
            table[1][position - 4] = O_X[jud % 2];
            numbers[position - 1] = true;
        }
        if (position >= 7 && position <= 9)
        {
            table[0][position - 7] = O_X[jud % 2];
            numbers[position - 1] = true;
        }
        system("cls");
        printTable(table);
        if ((table[0][0] == 'X' && table[1][1] == 'X' && table[2][2] == 'X') ||
            (table[2][0] == 'X' && table[1][1] == 'X' && table[0][2] == 'X'))
        {
            printf("B player win !\n");
            system("pause");
            return 0;
        }
        if ((table[0][0] == 'O' && table[1][1] == 'O' && table[2][2] == 'O') ||
            (table[2][0] == 'O' && table[1][1] == 'O' && table[0][2] == 'O'))
        {
            printf("A player win !\n");
            system("pause");
            return 0;
        }
        for (int i = 0; i < 3; i++)
        {
            int x1 = 0, x2 = 0;
            int o1 = 0, o2 = 0;
            for (int j = 0; j < 3; j++)
            {
                if (table[i][j] == 'X')
                    x1++;
                if (table[i][j] == 'O')
                    o1++;
                if (table[j][i] == 'X')
                    x2++;
                if (table[j][i] == 'O')
                    o2++;
            }
            if (x1 == 3 || x2 == 3)
            {
                printf("B player win !\n");
                system("pause");
                return 0;
            }
            if (o1 == 3 || o2 == 3)
            {
                printf("A player win !\n");
                system("pause");
                return 0;
            }
        }
        jud++;
    }
    printf("no winner !\n");
    system("pause");
    return 0;
}
void printTable(char table[3][3])
{
    printf("\t*-*-*-*\n");
    printf("\t|%c|%c|%c|\n", table[0][0], table[0][1], table[0][2]);
    printf("\t*-*-*-*\n");
    printf("\t|%c|%c|%c|\n", table[1][0], table[1][1], table[1][2]);
    printf("\t*-*-*-*\n");
    printf("\t|%c|%c|%c|\n", table[2][0], table[2][1], table[2][2]);
    printf("\t*-*-*-*\n\n");
}
