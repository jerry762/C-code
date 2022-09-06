#include <stdio.h>

int main (){
char table[3][3]={'\0'};
int p,q=1,n[9]={1,2,3,4,5,6,7,8,9};
printf("start !\nX is A player !\nO is B player !\n\n");
printf("+-+-+-+\n");
for(int i=0;i<3;i++)
    printf("|%c",table[0][i]);
printf("|\n");
printf("+-+-+-+\n");
for(int i=0;i<3;i++)
    printf("|%c",table[1][i]);
printf("|\n");
printf("+-+-+-+\n");
for(int i=0;i<3;i++)
    printf("|%c",table[2][i]);
printf("|\n");
printf("+-+-+-+\n");
while(q)
    {
    if(q%2==1)
        {
        printf("\nplayer A(X)\n");
        printf("input your position you want ?\n");
        scanf("%d",&p);
        if(n[p-1]==0||p<0||p>9)
            {
            printf("input again !\n");
            continue;
            }
        if(p<4)
            {
            table[2][p-1]='X';
            n[p-1]=0;
            }
        if(p>3&&p<7)
            {
            table[1][p-4]='X';
            n[p-1]=0;
            }
        if(p>6&&p<10)
            {
            table[0][p-7]='X';
            n[p-1]=0;
            }
        }
    else
        {
        printf("\nplayer B(O)\n");
        printf("input your position you want ?\n");
        scanf("%d",&p);
        if(n[p-1]==0||p<0||p>9)
            {
            printf("input again !\n");
            continue;
            }
        if(p<4)
            {
            table[2][p-1]='O';
            n[p-1]=0;
            }
        if(p>3&&p<7)
            {
            table[1][p-4]='O';
            n[p-1]=0;
            }
        if(p>6&&p<10)
            {
            table[0][p-7]='O';
            n[p-1]=0;
            }
        }
    printf("+-+-+-+\n");
    for(int i=0;i<3;i++)
        printf("|%c",table[0][i]);
    printf("|\n");
    printf("+-+-+-+\n");
    for(int i=0;i<3;i++)
        printf("|%c",table[1][i]);
    printf("|\n");
    printf("+-+-+-+\n");
    for(int i=0;i<3;i++)
        printf("|%c",table[2][i]);
    printf("|\n");
    printf("+-+-+-+\n");
    if((table[0][0]=='X'&&table[1][1]=='X'&&table[2][2]=='X')||(table[2][0]=='X'&&table[1][1]=='X'&&table[0][2]=='X'))
        {
        printf("A player win !\n");
        return 0;
        }
    if((table[0][0]=='O'&&table[1][1]=='O'&&table[2][2]=='O')||(table[2][0]=='O'&&table[1][1]=='O'&&table[0][2]=='O'))
        {
        printf("B player win !\n");
        return 0;
        }
    for(int i=0;i<3;i++)
        {
        int x1=0,x2=0;
        int o1=0,o2=0;
        for(int j=0;j<3;j++)
            {
            if(table[i][j]=='X')
                x1++;
            if(table[i][j]=='O')
                o1++;
            if(table[j][i]=='X')
                x2++;
            if(table[j][i]=='O')
                o2++;
            }
        if(x1==3||x2==3)
            {
            printf("A player win !\n");
            return 0;
            }
        if(o1==3||o2==3)
            {
            printf("B player win !\n");
            return 0;
            }
        }
    if(q==9)
        {
        printf("no winer !\n");
        return 0;
        }
    q++;
    }
}
