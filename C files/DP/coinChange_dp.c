#include<stdio.h>
#include<limits.h>
#define MIN(A,B) ((A)<(B)?(A):(B))
int minCoins(int N, int coins[], int sum, int dp[])
{
    if(sum==0)
        return 0;
    if(sum<0)
        return INT_MAX-1;
    int res = sum;
    for(int i=0;i<N;i++)
    {
        int x = coins[i];
        int a;
        if(dp[sum-x] != -1)
            a = dp[sum-x];
        else
            a = minCoins(N, coins, sum-x, dp);
        res = MIN(res, a+1);
    }
    dp[sum] = res;
    return res;
}

int main()
{
    int N, sum;
    scanf("%d %d", &N, &sum);
    int coins[N];
    int dp[sum+1];
    for(int i=0; i<=sum; i++){
        dp[i] = -1;
    }
    for(int i=0; i<N; i++)
        scanf("%d", &coins[i]);
    int ans = minCoins(N, coins, sum, dp);
    printf("%d", ans);
}