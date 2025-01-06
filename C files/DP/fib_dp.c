#include<stdio.h>
long long fib(long long n, long long dp[])
{
    if(n<=1)
    {
        dp[n] = n;
        return n;
    }
    long long a,b;
    if(dp[n-1]==-1)
        a = fib(n-1,dp);
    else
        a = dp[n-1];
    if(dp[n-2]==-1)
        b = fib(n-2,dp);
    else
        b = dp[n-2];
    dp[n] = a+b;
    return a+b;
}
int main()
{
    long long n;
    scanf("%lld",&n);
    long long dp[n+1];
    for(int i=0;i<=n;i++)
        dp[i] = -1;
    printf("%lld",fib(n,dp));
}