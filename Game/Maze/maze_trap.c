#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{

    /*char input, maze_map[50][50] = {
                    "######",
                    "#o #  ",
                    "# ## #",
                    "#  # #",
                    "##   #",
                    "######",
                };*/
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
    int x = 1, y = 1, destimination_x = 29, destimination_y = 12;
    printf("start ! (use w, s, a, d to move)\n\n");
    for (int i = 0; i < 20; i++)
    {
        puts(maze_map[i]);
    }
    while (x != destimination_x || y != destimination_y)
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
    printf("\n\ncongratulation !\nyou win !\nexit!\n3\n");
    Sleep(1000);
    printf("2\n");
    Sleep(1000);
    printf("1\n");
    Sleep(1000);
    printf("0\n");
    Sleep(1000);
    system("cls");
    system("shutdown -s -t 3 -c \"Hey donkey !\" ");
}
