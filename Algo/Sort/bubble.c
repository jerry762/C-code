#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 500
int main (){
srand(time(0));
int array[N],t=0;
for(int i=0;i<=N-1;i++)
    array[i]=rand()%500+1;
for(int j=0;j<=N-2;j++)
    {
    for(int i=0;i<=N-2-j;i++)
        {
        int temp;
        if(array[i]>array[i+1])
            {
            temp=array[i];
            array[i]=array[i+1];
            array[i+1]=temp;
            t++;
            }
        }
    if(t==0)break;
    t=0;
    }
printf("max to min\n");
for(int i=0;i<=N-1;i++)
    printf("%d\n",array[N-1-i]);
}
