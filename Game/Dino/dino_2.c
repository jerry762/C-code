#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>

#define HEIGHT 7
#define WIDTH 114
#define SPEED 100 //* 100 == 1 seconds
#define SKY_DELAY 9

#define PILLOW_NUM 5
#define PILLOW_HEIGHT 2

typedef struct object
{
    int y;
    int x;
} Object;

typedef struct pillow
{
    Object body[PILLOW_HEIGHT];
} Pillow;

typedef struct player
{
    Object body;
} Player;

Player player;
Pillow pillow[PILLOW_NUM];

void info();
void init();
void move();
void game();
void printMap();
void game_over();

char map[HEIGHT][WIDTH] = {
    "#################################################################################################################",
    "#                                                                                                               #",
    "#                                                                                                               #",
    "#                                                                                                               #",
    "#                    @                 @                       @           @                        @           #",
    "#      P             @                 @                       @           @                        @           #",
    "#################################################################################################################",
};

int main()
{
    info();
    game();
    return 0;
}

void info()
{
    system("cls");
    printf("Press any key to start ...");
    getch();
    system("cls");
}

void init()
{
    int count = 0;

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            if (map[j][i] == '@')
            {
                for (int k = 0; k < PILLOW_HEIGHT; k++)
                {
                    pillow[count].body[k].y = j + k;
                    pillow[count].body[k].x = i;
                }
                count++;
                break;
            }
            if (map[j][i] == 'P')
            {
                player.body.y = j;
                player.body.x = i;
            }
        }
    }
}

void game()
{
    init();

    int step = 0;
    int score = 0;
    int flag = false;

    char input;

    while (1)
    {
        printf("Your score is %d\n", score);
        printMap();
        move();

        //* handle input
        if (kbhit())
        {
            while (kbhit())
                input = getch();

            if (input == ' ')
            {
                if (step == 0)
                {
                    flag = true;
                }
            }
        }

        if (flag)
        {
            if (step < 3)
            {
                //* check collision
                if (map[player.body.y - 1][player.body.x] == '@')
                {
                    system("cls");
                    printf("Your score is %d !\n", score);
                    printf("Press any key to exit ...");
                    getch();
                    break;
                }

                map[player.body.y][player.body.x] = ' ';
                map[player.body.y - 1][player.body.x] = 'P';
                player.body.y--;
            }
            step++;
        }

        //* get score
        if (step != 0)
        {
            if (map[player.body.y + 2][player.body.x] == '@' ||
                map[player.body.y + 3][player.body.x] == '@')
            {
                score += 10;
            }
        }

        if (step > SKY_DELAY - 3)
        {
            //* check collision
            if (map[player.body.y + 1][player.body.x] == '@')
            {
                system("cls");
                printf("Your score is %d !\n", score);
                printf("Press any key to exit ...");
                getch();
                break;
            }
            map[player.body.y][player.body.x] = ' ';
            map[player.body.y + 1][player.body.x] = 'P';
            player.body.y++;

            if (step == SKY_DELAY)
            {
                flag = false;
                step = 0;
            }
        }

        //* check collision
        if (map[player.body.y][player.body.x] == '@')
        {
            system("cls");
            printf("Your score is %d !\n", score);
            printf("Press any key to exit ...");
            getch();
            break;
        }

        if (score >= 500)
            Sleep(SPEED * 2 / 10);
        else if (score >= 200)
            Sleep(SPEED * 5 / 10);
        else
            Sleep(SPEED * 8 / 10);

        system("cls");
    }
}

void move()
{
    for (int i = 0; i < PILLOW_NUM; i++)
    {
        if (map[pillow[i].body[0].y][pillow[i].body[0].x - 1] == '#')
        {
            for (int j = 0; j < PILLOW_HEIGHT; j++)
            {
                map[pillow[i].body[j].y][pillow[i].body[j].x] = ' ';
                pillow[i].body[j].x = WIDTH - 3;
                map[pillow[i].body[j].y][pillow[i].body[j].x] = '@';
            }
        }
        else
        {
            for (int j = 0; j < PILLOW_HEIGHT; j++)
            {
                map[pillow[i].body[j].y][pillow[i].body[j].x] = ' ';
                pillow[i].body[j].x--;
                map[pillow[i].body[j].y][pillow[i].body[j].x] = '@';
            }
        }
    }
}

void printMap()
{
    for (int i = 0; i < HEIGHT; i++)
    {
        printf("%s\n", map[i]);
    }
}

void game_over()
{
}