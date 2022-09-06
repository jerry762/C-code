#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    char input, maze_map[50][50] = {
                    "##############################",
                    "#o         #   ##   # ### ####",
                    "# ###### # # #    # # ### ####",
                    "# #   ## #   # #### # ###   ##",
                    "#   # ##  ###    #  #  ## ####",
                    "##### #     # ##### ##    ####",
                    "#   # ##### #   #   # # #    #",
                    "# # #    ## # #### ## # # ####",
                    "# # # ##      ##      # # ####",
                    "# # # ####### ## ###### #   ##",
                    "# #   ##   # ## ###### ###   #",
                    "# ###### # #####  #        # #",
                    "#        # #     ##### ### #  ",
                    "# ######## ##### # ### ### # #",
                    "#     # ## ##### ###       ###",
                    "##### # ## #      ######## # #",
                    "#     # ## ## ###        #   #",
                    "# # ###       ###### ####### #",
                    "# #    ### ##      #         #",
                    "##############################",
                };
    int x = 1, y = 1, des_x = 29, des_y = 12;
    printf("start ! (use w, s, a, d to move)\n\n");
    for (int i = 0; i < 20; i++)
    {
        puts(maze_map[i]);
    }
    while (x != des_x || y != des_y)
    {
        input = getch();
        if (input == 'w')
        {
            if (maze_map[y - 1][x] == ' ')
            {
                maze_map[y - 1][x] = 'o';
                maze_map[y][x] = ' ';
                y--;
            }
        }
        if (input == 's')
        {
            if (maze_map[y + 1][x] == ' ')
            {
                maze_map[y + 1][x] = 'o';
                maze_map[y][x] = ' ';
                y++;
            }
        }
        if (input == 'a')
        {
            if (maze_map[y][x - 1] == ' ')
            {
                maze_map[y][x - 1] = 'o';
                maze_map[y][x] = ' ';
                x--;
            }
        }
        if (input == 'd')
        {
            if (maze_map[y][x + 1] == ' ')
            {
                maze_map[y][x + 1] = 'o';
                maze_map[y][x] = ' ';
                x++;
            }
        }
        system("cls");
        for (int i = 0; i < 20; i++)
        {
            puts(maze_map[i]);
        }
    }
    printf("\n\ncongratulation !\nyou win !\nexit!\n");
    system("pause");
    return 0;
}
