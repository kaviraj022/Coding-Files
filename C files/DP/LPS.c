#include<stdio.h>
#include<string.h>
#define MAX(A,B) ((A)>(B)?(A):(B))
int LPS(char str[], int s, int e)
{
    if(s==e)
        return 1;
    if(s>e)
        return 0;
    if(str[s]==str[e])
        return LPS(str,s+1,e-1)+2;
    return MAX(LPS(str,s,e-1),LPS(str,s+1,e));
}
int main()
{
    char str[100];
    scanf("%s",str);
    int n = strlen(str);
    int ans = LPS(str,0,n-1);
    printf("%d",ans);
}