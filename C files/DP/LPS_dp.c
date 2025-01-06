#include<stdio.h>
#include<string.h>
#define MAX(A,B) ((A)>(B)?(A):(B))
int LPS(char str[], int s, int e, int n, int dp[][n])
{
    if(s==e)
    {
        dp[s][e] = 1;
        return 1;
    }
    if(s>e)
    {
        dp[s][e] = 0;
        return 0;
    }
    if(str[s]==str[e])
    {
        int a;
        if(dp[s+1][e-1]==-1)
            a = LPS(str,s+1,e-1,n,dp);
        else
            a = dp[s+1][e-1];
        dp[s][e] = a + 2;
        return a+2;
    }
    int a,b;
    if(dp[s][e-1]==-1)
        a = LPS(str,s,e-1,n,dp);
    else
        a = dp[s][e-1];
    if(dp[s+1][e]==-1)
        b = LPS(str,s+1,e,n,dp);
    else
        b = dp[s+1][e];
    dp[s][e] = MAX(a,b);
    return MAX(a,b);
}
int main()
{
    char str[100];
    scanf("%s",str);
    int n = strlen(str);
    int dp[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dp[i][j] = -1;
    int ans = LPS(str,0,n-1,n,dp);
    printf("%d",ans);
}