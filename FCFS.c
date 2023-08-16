#include<stdio.h>
#include<stdlib.h>
int main()
{
    int RQ[100],i,initial,THM=0,n;
    printf("Enter the number of requests\n");
    scanf("%d",&n);
    printf("Enter the request sequence\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&RQ[i]);
    }
    printf("enter the initial head moment\n");
    scanf("%d",&initial);
    printf("The sequence of requests are\n");
    for(i=0;i<n;i++)
    {
        printf("%d \t",RQ[i]);
        THM=THM+abs(RQ[i]-initial);
        initial=RQ[i];
    }
    printf("The TOtal Head Movement is %d\n",THM);
    return 0;
}
// Enter the number of requests
// 7 
// Enter the request sequence
// 82 170 43 140 24 16 190 
// enter the initial head moment
// 50 
// The sequence of requests are
// 82      170     43      140     24      16      190    
// The TOtal Head Movement is 642
