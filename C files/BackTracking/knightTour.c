#include<stdio.h>
#include<stdbool.h>
int x[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int y[] = {-1, -2, -2, -1, 1, 2, 2, 1};
bool isSafe(int N, int chessBoard[][N], int r, int c)
{
    if(r<0 || c<0 || r>=N || c>=N)
        return false;
    if(chessBoard[r][c]>0)
        return false;
    return true;
}
void knightTour(int N, int chessBoard[][N], int r, int c, int v)
{
    if(v==(N*N+1))
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                printf("%d ",chessBoard[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    else
    {
        for(int i=0;i<8;i++)
        {
            if(isSafe(N, chessBoard,r+x[i],c+y[i]))
            {
                chessBoard[r+x[i]][c+y[i]] = v;
                knightTour(N,chessBoard,r+x[i],c+y[i],v+1);
                chessBoard[r+x[i]][c+y[i]] = -1;
            }
        }
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    int chessBoard[N][N];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            chessBoard[i][j] = -1;
    chessBoard[0][0] = 1;
    knightTour(N,chessBoard,0,0,2);
}