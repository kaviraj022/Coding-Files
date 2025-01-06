#include<stdio.h>
#include<limits.h>
#define MIN(A,B) ((A)<(B)?(A):(B))
int minCoins(int N, int coins[], int sum)
{
    if(sum==0)
        return 0;
    if(sum<0)
        return INT_MAX-1;
    int res = sum;
    for(int i=0;i<N;i++)
    {
        int x = coins[i];
        res = MIN(res, minCoins(N,coins,sum-x)+1);
    }
    return res;
}
int main()
{
    int N,sum;
    scanf("%d %d",&N,&sum);
    int coins[N];
    for(int i=0;i<N;i++)
        scanf("%d",&coins[i]);
    int ans = minCoins(N,coins,sum);
    printf("%d",ans);
}