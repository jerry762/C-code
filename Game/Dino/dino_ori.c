#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>

#define HEIGHT 7
#define WIDTH 114
#define SPEED 100 //* 100 == 1 seconds

#define PILLOW_HEIGHT 2

#define SKY_DELAY 9

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
    Player player;

    Pillow p1;
    Pillow p2;
    Pillow p3;
    Pillow p4;
    Pillow p5;

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;
    int step = 0;
    int score = 0;

    char input;

    bool flag = false;

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            if (count1 < PILLOW_HEIGHT && map[j][i] == '@')
            {
                p1.body[count1].y = j;
                p1.body[count1].x = i;
                count1++;
            }
            else if (count2 < PILLOW_HEIGHT && map[j][i] == '@')
            {
                p2.body[count2].y = j;
                p2.body[count2].x = i;
                count2++;
            }
            else if (count3 < PILLOW_HEIGHT && map[j][i] == '@')
            {
                p3.body[count3].y = j;
                p3.body[count3].x = i;
                count3++;
            }
            else if (count4 < PILLOW_HEIGHT && map[j][i] == '@')
            {
                p4.body[count4].y = j;
                p4.body[count4].x = i;
                count4++;
            }
            else if (count5 < PILLOW_HEIGHT && map[j][i] == '@')
            {
                p5.body[count5].y = j;
                p5.body[count5].x = i;
                count5++;
            }
            if (map[j][i] == 'P')
            {
                player.body.y = j;
                player.body.x = i;
            }
        }
    }

    system("cls");

    while (1)
    {
        printf("Your score is %d\n", score);
        for (int i = 0; i < HEIGHT; i++)
        {
            printf("%s\n", map[i]);
        }

        if (map[p1.body[0].y][p1.body[0].x - 1] == '#')
        {
            for (int i = 0; i < PILLOW_HEIGHT; i++)
            {
                map[p1.body[i].y][p1.body[i].x] = ' ';
                p1.body[i].x = WIDTH - 3;
                map[p1.body[i].y][p1.body[i].x] = '@';
            }
        }
        else
        {
            for (int i = 0; i < PILLOW_HEIGHT; i++)
            {
                map[p1.body[i].y][p1.body[i].x] = ' ';
                p1.body[i].x--;
                map[p1.body[i].y][p1.body[i].x] = '@';
            }
        }

        if (map[p2.body[0].y][p2.body[0].x - 1] == '#')
        {
            for (int i = 0; i < PILLOW_HEIGHT; i++)
            {
                map[p2.body[i].y][p2.body[i].x] = ' ';
                p2.body[i].x = WIDTH - 3;
                map[p2.body[i].y][p2.body[i].x] = '@';
            }
        }
        else
        {
            for (int i = 0; i < PILLOW_HEIGHT; i++)
            {
                map[p2.body[i].y][p2.body[i].x] = ' ';
                p2.body[i].x--;
                map[p2.body[i].y][p2.body[i].x] = '@';
            }
        }

        if (map[p3.body[0].y][p3.body[0].x - 1] == '#')
        {
            for (int i = 0; i < PILLOW_HEIGHT; i++)
            {
                map[p3.body[i].y][p3.body[i].x] = ' ';
                p3.body[i].x = WIDTH - 3;
                map[p3.body[i].y][p3.body[i].x] = '@';
            }
        }
        else
        {
            for (int i = 0; i < PILLOW_HEIGHT; i++)
            {
                map[p3.body[i].y][p3.body[i].x] = ' ';
                p3.body[i].x--;
                map[p3.body[i].y][p3.body[i].x] = '@';
            }
        }

        if (map[p4.body[0].y][p4.body[0].x - 1] == '#')
        {
            for (int i = 0; i < PILLOW_HEIGHT; i++)
            {
                map[p4.body[i].y][p4.body[i].x] = ' ';
                p4.body[i].x = WIDTH - 3;
                map[p4.body[i].y][p4.body[i].x] = '@';
            }
        }
        else
        {
            for (int i = 0; i < PILLOW_HEIGHT; i++)
            {
                map[p4.body[i].y][p4.body[i].x] = ' ';
                p4.body[i].x--;
                map[p4.body[i].y][p4.body[i].x] = '@';
            }
        }

        if (map[p5.body[0].y][p5.body[0].x - 1] == '#')
        {
            for (int i = 0; i < PILLOW_HEIGHT; i++)
            {
                map[p5.body[i].y][p5.body[i].x] = ' ';
                p5.body[i].x = WIDTH - 3;
                map[p5.body[i].y][p5.body[i].x] = '@';
            }
        }
        else
        {
            for (int i = 0; i < PILLOW_HEIGHT; i++)
            {
                map[p5.body[i].y][p5.body[i].x] = ' ';
                p5.body[i].x--;
                map[p5.body[i].y][p5.body[i].x] = '@';
            }
        }

        if (kbhit())
        {
            while (kbhit())
                input = getch();

            if (input == 'W' || input == 'w')
            {
                if (step == 0)
                {
                    flag = true;
                    map[player.body.y][player.body.x] = ' ';
                    map[player.body.y - 3][player.body.x] = 'P';
                    player.body.y -= 3;
                }
            }

            if (input == 'S' || input == 's')
            {
                if (step != 0 && step != 6)
                {
                    flag = false;
                    map[player.body.y][player.body.x] = ' ';
                    map[player.body.y + 3][player.body.x] = 'P';
                    player.body.y += 3;
                    step = 0;
                }
            }
        }

        if (flag)
            step++;

        if (step == SKY_DELAY)
        {
            flag = false;
            map[player.body.y][player.body.x] = ' ';
            map[player.body.y + 3][player.body.x] = 'P';
            player.body.y += 3;
            step = 0;
        }

        //* check collision
        if (map[player.body.y][player.body.x] == '@' ||
            map[player.body.y - 1][player.body.x] == '@')
        {
            system("cls");
            printf("Your score is %d !\n", score);
            system("pause");
            break;
        }

        //* count score
        if (step != 0)
        {
            if (map[player.body.y + 2][player.body.x] == '@' ||
                map[player.body.y + 3][player.body.x] == '@')
            {
                score += 10;
            }
        }

        if (score >= 500)
            Sleep(SPEED * 2 / 10);
        else if (score >= 200)
            Sleep(SPEED * 5 / 10);
        else
            Sleep(SPEED * 8 / 10);

        system("cls");
    }

    return 0;
}