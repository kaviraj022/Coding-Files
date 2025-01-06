#include<stdio.h>
void merge(int arr[], int s, int m, int e)
{
    int N = m - s + 1;
    int M = e - m;
    int L[N],R[M];
    int a = 0;
    for(int b=s;b<=m;b++)
        L[a++] = arr[b];
    a = 0;
    for(int b=m+1;b<=e;b++)
        R[a++] = arr[b];
    int i=0,j=0,k=s;
    while(i<N && j<M)
    {
        if(L[i] < R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while(i<N)
        arr[k++] = L[i++];
    while(j<M)
        arr[k++] = R[j++];
}
void mergeSort(int arr[], int s, int e)
{
    if(s<e)
    {
        int m = (s+e)/2;
        mergeSort(arr,s,m);
        mergeSort(arr,m+1,e);
        merge(arr,s,m,e);
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
    mergeSort(arr, 0, N-1);
    for(int i=0;i<N;i++)
        printf("%d ",arr[i]);
}