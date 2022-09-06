#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
int main (){
srand(time(0));
int array[N],min,temp;
for(int i=0;i<=N-1;i++)
    array[i]=rand()%300+1;
for(int i=0;i<=N-2;i++)
    {
    min=i;
    for(int j=i+1;j<=N-1;j++)
        {
        if(array[min]>array[j])
            min=j;
        }
    temp=array[i];
    array[i]=array[min];
    array[min]=temp;
    for(int k=0;k<=N-1;k++)
        printf("%3d ",array[k]);
    printf("\n");
    }
/*printf("max to min\n");
for(int i=0;i<=N-1;i++)
    printf("%d\n",array[N-1-i]);*/
}
