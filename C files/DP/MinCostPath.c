#include<stdio.h>
#include<limits.h>
#define MIN(A,B) ((A)<(B)?(A):(B))
int MCP(int N, int M, int mat[][M], int R, int C, int dp[][M])
{
    if(R==0 && C==0)
    {
        dp[R][C] = mat[R][C];
        return mat[R][C];
    }
    if(R==-1 || C==-1)
        return INT_MAX;
    int a,b;
    if(C-1>=0 && dp[R][C-1]!=-1)
        a = dp[R][C-1];
    else
        a = MCP(N,M,mat,R,C-1,dp);
    if(R-1>=0 && dp[R-1][C]!=-1)
        b = dp[R-1][C];
    else
        b = MCP(N,M,mat,R-1,C,dp);
    dp[R][C] = MIN(a,b) + mat[R][C];
    return dp[R][C];
}
int main()
{
    int N, M;
    scanf("%d %d",&N,&M);
    int mat[N][M],dp[N][M];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            scanf("%d",&mat[i][j]);
            dp[i][j] = -1;
        }
    }
    int ans = MCP(N,M,mat,N-1,M-1,dp);
    printf("%d",ans);
}