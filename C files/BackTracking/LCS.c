#include<stdio.h>
#include<string.h>
#define MAX(A,B) ((A)>(B)?(A):(B))
int LCS(char str1[], char str2[], int i, int j,int M,int dp[][M])
{
    if(i<0 || j<0)
        return 0;
    if(str1[i]==str2[j])
    {
        int a;
        if(i-1>=0 && j-1>=0 && dp[i-1][j-1]!=-1)
            a = dp[i-1][j-1];
        else
            a = LCS(str1,str2,i-1,j-1,M,dp);
        dp[i][j] = 1+a;
        return 1 + a;
    }
    int a,b;
    if(j-1>=0 && dp[i][j-1]!=-1)
        a = dp[i][j-1];
    else
        a = LCS(str1,str2,i,j-1,M,dp);
    if(i-1>=0 && dp[i-1][j]!=-1)
        b = dp[i-1][j];
    else
        b = LCS(str1,str2,i-1,j,M,dp);
    dp[i][j] = MAX(a,b);
    return MAX(a,b);
}
int main()
{
    char str1[100],str2[100];
    scanf("%s",str1);
    scanf("%s",str2);
    int N = strlen(str1);
    int M = strlen(str2);
    int dp[N][M];
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            dp[i][j] = -1;
    int ans = LCS(str1,str2,N-1,M-1,M,dp);
    printf("%d",ans);
}