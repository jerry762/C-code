# **井字遊戲 (Tic Tac Toe) <sub> Using C Programming <sub>**

![tic tac toe gif](https://i.imgur.com/yAKw9d6.gif)
    
## **介紹 (Introduction)**


英文遊戲名稱為「TIC TAC TOE」，相傳為古羅馬時代所發明，為一古老的遊戲。直到十九世紀後期，英國才開始出現「圈叉棋」的名稱，並演變成紙筆進行的「井字」遊戲。
    
## **流程圖 (Flow Chart Symbol)**  

|          形狀           |   名稱    | 描述                                                                                                   |
| :---------------------: | :-------: | :----------------------------------------------------------------------------------------------------- |
|   ![Flowline][Link 1]   | 流程符號  | 用來表達過程的次序，用一條線由一個符號連接去到另一個符號。如果不是標準的上至下、左至右圖就會加上箭頭。 |
|   ![Terminal][Link 2]   | 起止符號  | 用來表示程式或子程式的開始與完結。常以一個圓角長方形表示。通常裏面會標上「開始」或「結束」或相關字眼。 |
|   ![Process][Link 3]    |   程式    | 以長方形來代表一系列程式去改變數值、形式、數據的位置。                                                 |
|   ![Decision][Link 4]   | 決策判斷  | 以一個菱形去顯示一個條件進程，用來按情況去決定下一步走向。通常以「是/否」或「真/假」值去決定。         |
| ![Input/Output][Link 5] | 輸入/輸出 | 以平行四邊形來標示數據輸入或輸出的過程，即填入數據或顯示工作結果的步驟。                               |

[Link 1]: https://i.imgur.com/BUAtUih.png "Flowline"
[Link 2]: https://i.imgur.com/edJ7hwa.png "Terminal"
[Link 3]: https://i.imgur.com/icJtknV.png "Process"
[Link 4]: https://i.imgur.com/C3qkqjd.png "Decision"
[Link 5]: https://i.imgur.com/9DzNSGQ.png "Input/Output"

## **流程圖 (flow chart)**

![flow chart](https://i.imgur.com/O3iGHZb.png)

## **設計核心**


- 玩家切換
- 數字鍵代表九宮格之位置
- 檢查位置重複輸入
- 判斷輸贏與平局

## **玩家切換**


每一回合中玩家必須來回切換,假設這一回合是A,下一回合就是B,我這邊是用除二取餘數的概念,1是A,0是B來實現來回切換。

```cpp
char table[3][3], OX[3] = "OX";
int time = 1;
    
while (time < 10)
{
    printf("%c player input position (%c):", (time % 2) ? 'A' : 'B', OX[time % 2]);
        
    system("cls");
    printTable(table);
        
    time++;
}
```

## **數字鍵代表九宮格之位置**


|   Table   | Column 1 | Column 2 | Column 3 |
| :-------: | :------: | :------: | :------: |
| **Row 1** |    7     |    8     |    9     |
| **Row 2** |    4     |    5     |    6     |
| **Row 3** |    1     |    2     |    3     |

7 代表 table[0][0], 8 代表 table[0][1], 9 代表 table[0][2]  
4 代表 table[1][0], 5 代表 table[1][1], 6 代表 table[1][2]  
1 代表 table[2][0], 2 代表 table[2][1], 3 代表 table[2][2]  

再根據該輪給定'O' or 'X' 存入table之中  
***如果輸入的值大於9且小於1,則重新輸入***  

```cpp
while (time != 10)
{
    printf("%c player input position (%c):", (time % 2) ? 'A' : 'B', OX[time % 2]);
    scanf("%d", &input);
    if (input > 9 || input < 1 || pos[(input - 1) / 3][(input - 1) % 3] == true)
    {
        printf("input again !\n");
        continue;
    }

    //pos[(input - 1) / 3][(input - 1) % 3] = true;
    table[(input - 1) / 3][(input - 1) % 3] = OX[time % 2];
    system("cls");
    printTable(table);

    time++;
}
```
    
## **檢查位置重複輸入**


每一回合中,必須檢查是否輸入到已被使用的位置,如果是,則重新輸入位置,如果否,則繼續執行並把該位置設為true,我使用二維布林陣列實現,false代表沒使用,true代表已使用。  
                     
```cpp
while (time != 10)
{
    printf("%c player input position (%c):", (time % 2) ? 'A' : 'B', OX[time % 2]);
    scanf("%d", &input);
    if (pos[(input > 9 || input < 1 || input - 1) / 3][(input - 1) % 3] == true)
    {
        printf("input again !\n");
        continue;
    }

    pos[(input - 1) / 3][(input - 1) % 3] = true;
    //table[(input - 1) / 3][(input - 1) % 3] = OX[time % 2];
    system("cls");
    printTable(table);

    time++;
}                                   
```                                   
                                      
## **判斷輸贏與平局**    


每一回合中需判斷贏家有三種情況,行,列,斜,我們可以用巢狀for解決行和列,另外再寫一個if條件式判斷斜的情況。  
                                      
平局的話只需宣告一個整數變數,把它的值設為1(代表第一局),之後每過一次迴圈(一輪)就加一,直到變數的值等於十時(平局),跳出迴圈。  
          
```cpp
while (time != 10)
{

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
``` 

## **完整程式碼**👇


```cpp
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
```
                                  
                                  
                                  
                                  