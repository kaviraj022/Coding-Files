#include<stdio.h>
#include<stdbool.h>
bool isSafe(int row, int col,int N, bool column[], bool ldiagonal[], bool rdiagonal[])
{
    if(column[col]==true)
        return false;
    if(ldiagonal[row+col]==true)
        return false;
    if(rdiagonal[row-col+(N-1)]==true)
        return false;
    return true;
}
void nQueen(int N, char chessBoard[][N], int row, bool column[], bool ldiagonal[], bool rdiagonal[])
{
    if(row==N)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                printf("%c ",chessBoard[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    else
    {
        for(int col=0;col<N;col++)
        {
            if(isSafe(row, col, N, column,ldiagonal,rdiagonal))
            {
                chessBoard[row][col]='Q';
                column[col] = true;
                ldiagonal[row+col] = true;
                rdiagonal[row-col+(N-1)] = true;
                nQueen(N,chessBoard,row+1,column,ldiagonal,rdiagonal);
                chessBoard[row][col]='-';
                column[col] = false;
                ldiagonal[row+col] = false;
                rdiagonal[row-col+(N-1)] = false;
            }
        }
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    char chessBoard[N][N];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            chessBoard[i][j] = '-';
    bool column[N],ldiagonal[2*N-1],rdiagonal[2*N-1];
    for(int i=0;i<N;i++)
        column[i] = false;
    for(int i=0;i<2*N-1;i++)
        ldiagonal[i] = rdiagonal[i] = false;
    nQueen(N,chessBoard,0,column,ldiagonal,rdiagonal);
    
}