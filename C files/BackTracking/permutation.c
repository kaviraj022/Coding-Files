#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool isSafe(bool visited[], int i)
{
    return !visited[i];
}
void permutation(int N,char str[],char ans[],bool visited[],int ind)
{
    if(ind==N)
        printf("%s\n",ans);
    else
    {
        for(int i=0;i<N;i++)
        {
            if(isSafe(visited,i))
            {
                ans[ind] = str[i];
                visited[i] = true;
                permutation(N,str,ans,visited,ind+1);
                visited[i] = false;
            }
        }
    }
}
int main()
{
    char str[100];
    scanf("%s",str);
    int N = strlen(str);
    char ans[N+1];
    ans[N] = '\0';
    bool visited[N];
    for(int i=0;i<N;i++)
        visited[i] = false;
    permutation(N,str,ans,visited,0);
}