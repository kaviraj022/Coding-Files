#include<stdio.h>
int findPivot(int arr[], int s, int e)
{
    int idx = e;
    int i = s, j = s;
    while(i<e)
    {
        if(arr[i]<arr[idx])
        {
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            j++;
        }
        i++;
    }
    int t = arr[idx];
    arr[idx] = arr[j];
    arr[j] = t;
    return j;
}
void quickSort(int arr[], int s, int e)
{
    if(s<e)
    {
        int m = findPivot(arr,s,e);
        quickSort(arr,s,m-1);
        quickSort(arr,m+1,e);
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
    quickSort(arr, 0, N-1);
    for(int i=0;i<N;i++)
        printf("%d ",arr[i]);
}