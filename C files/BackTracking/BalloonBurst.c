#include<stdio.h>
#include<limits.h>
int maxCoins(int N, int arr[], int l, int r)
{
    if(l>r) return 0;
    int result = INT_MIN;
    for(int ind = l;ind<=r;ind++)
    {
        int ans = arr[ind] * arr[l-1] * arr[r+1];
        int a = maxCoins(N,arr,l,ind-1);
        int b = maxCoins(N,arr,ind+1,r);
        ans = ans + a + b;
        if(ans>result)
            result = ans;
    }
    return result;
}
int main()
{
    int N;
    scanf("%d",&N);
    int arr[N+2];
    arr[0] = arr[N+1] = 1;
    for(int i=1;i<=N;i++)
        scanf("%d",&arr[i]);
    int ans = maxCoins(N+2,arr,1,N);
    printf("%d",ans);
}