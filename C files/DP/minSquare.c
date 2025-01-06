#include<stdio.h>
#include<math.h>
#define MIN(A,B) ((A)<(B)?(A):(B))
int minSquare(int n,int dp[])
{
    if(n<=3)
        return n;
    if(ceil(sqrt(n)) == floor(sqrt(n)))
        return 1;
    int res = n;
    for(int i=1;i*i<=n;i++)
    {
        int x = i*i;
        int a;
        if(dp[n-x]==-1)
            a = minSquare(n-x,dp);
        else
            a = dp[n-x];
        res = MIN(res, a+1);
    }
    dp[n] = res;
    return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    int dp[n+1];
    for(int i=0;i<=n;i++)
        dp[i] = -1;
    int ans = minSquare(n,dp);
    printf("%d",ans);
}